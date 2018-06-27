#ifndef __TABLE_BASE_H__
#define __TABLE_BASE_H__

#include "transaction.h"

/*
默认认为表的行为是：
	1 有变化，就立即生效
	2 如果错误，可以rollback
	3 在变动的同时就进行表的索引的调整；
*/

template<class Tbl, class Rec>
class CInsertCommand : public ITranCommand
{
public:
	explicit CInsertCommand(Tbl* pTable, Rec* pRec)
		: m_pTable{ pTable }, m_pRec{ pRec }
	{

	}

	virtual void undo()
	{
		//xww modify 先注释掉，sim并没有回滚的功能
		//就算是CInsertCommand 是 CTableBase 的友元也不能访问私有的direct_remove
		//m_pTable->direct_remove(m_pRec);
	}

private:
	Tbl* m_pTable;
	Rec* m_pRec;
};

template<class Tbl, class Rec>
class CRemoveCommand : public ITranCommand
{
public:
	explicit CRemoveCommand(Tbl* pTbale, const Rec* pRec)
		: m_pTalbe{ pTbale }, m_pRec{ pRec }
	{

	}

	virtual void undo()
	{
		//xww modify 先注释掉，sim并没有回滚的功能
		//就算是CRemoveCommand 是 CTableBase 的友元也不能访问私有的direct_insert
		//m_pTable->direct_insert(m_pRec);
	}
private:
	Tbl* m_pTable;
	const Rec* m_pRec;
};

template<class Tbl, class Rec>
class CUpateCommand : public ITranCommand
{
public:
	explicit CUpateCommand(Tbl* pTable, const Rec* const pRecOld, const Rec* const pRecNew)
		: m_pTable{ pTable }, m_pRecOld{ pRecOld }, m_pRecNew(pRecNew)
	{

	}

	virtual void undo()
	{
		//xww modify 先注释掉，sim并没有回滚的功能
		//就算是CUpateCommand 是 CTableBase 的友元也不能访问私有的direct_update
		//m_pTable->direct_update(m_pRecNew, m_pRecOld);
	}
private:
	Tbl* m_pTable;
	const Rec* const m_pRecOld;
	const Rec* const m_pRecNew;
};

template<class Rec>
class CTableBase
{
public:
	CTableBase() {}
	virtual ~CTableBase(){}

	typedef CTableBase<Rec> this_type;

	Rec* insert(const Rec* r, CTransaction* pTran)
	{
		Rec* p = direct_insert(r);
		if (pTran)
		{
			ITranCommand* pCommand = new CInsertCommand<this_type, Rec>(this, p);
			pTran->add_action(pCommand);
		}
		return p;
	}

	bool remove(const Rec* r, CTransaction* pTran)
	{
		bool succ = direct_remove(r);
		if (pTran && succ)
		{
			ITranCommand* pCommand = new CRemoveCommand<this_type, Rec>(this, r);
			pTran->add_action(pCommand);
		}
		return succ;
	}

	const Rec* update(const Rec* pOld, const Rec* pNew, CTransaction* pTran)
	{
		/* QQQQQ
		update 需要使用事务型的insert delete来模拟，不然，对于被替换掉的对象，不知道怎么进行删除操作；
		而用了insert delete每次都是全新分配的对象，在事务结束的时候，全部delete就可以了；

		为了优化性能，也可以使用transaction对象来做垃圾回收，在最后释放的时候，同一个指针，仅仅释放一次；
		当然，这就需要update中使用的new obj必须是 对分配的
		*/

		Rec* pInner = direct_update(pOld, pNew);
		if (pInner && pTran)
		{
			ITranCommand* pCommand = new CUpateCommand<this_type, Rec>(this, pOld, pInner);
			pTran->add_action(pCommand);
		}
		return pInner;
	}

	virtual size_t count() = 0;

private:
	virtual Rec* direct_insert(const Rec* r) = 0;
	virtual bool direct_remove(const Rec* r) = 0;

	// 定义为virtual， 一些特殊的表可改写逻辑
	virtual Rec* direct_update(const Rec* pOld, const Rec* pNew)
	{
		Rec* p = nullptr;
		if (direct_remove(pOld))
		{
			p = direct_insert(pNew);
		}
		return p;
	}
};


#endif