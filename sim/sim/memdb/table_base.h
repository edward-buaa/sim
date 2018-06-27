#ifndef __TABLE_BASE_H__
#define __TABLE_BASE_H__

#include "transaction.h"

/*
Ĭ����Ϊ�����Ϊ�ǣ�
	1 �б仯����������Ч
	2 ������󣬿���rollback
	3 �ڱ䶯��ͬʱ�ͽ��б�������ĵ�����
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
		//xww modify ��ע�͵���sim��û�лع��Ĺ���
		//������CInsertCommand �� CTableBase ����ԪҲ���ܷ���˽�е�direct_remove
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
		//xww modify ��ע�͵���sim��û�лع��Ĺ���
		//������CRemoveCommand �� CTableBase ����ԪҲ���ܷ���˽�е�direct_insert
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
		//xww modify ��ע�͵���sim��û�лع��Ĺ���
		//������CUpateCommand �� CTableBase ����ԪҲ���ܷ���˽�е�direct_update
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
		update ��Ҫʹ�������͵�insert delete��ģ�⣬��Ȼ�����ڱ��滻���Ķ��󣬲�֪����ô����ɾ��������
		������insert deleteÿ�ζ���ȫ�·���Ķ��������������ʱ��ȫ��delete�Ϳ����ˣ�

		Ϊ���Ż����ܣ�Ҳ����ʹ��transaction���������������գ�������ͷŵ�ʱ��ͬһ��ָ�룬�����ͷ�һ�Σ�
		��Ȼ�������Ҫupdate��ʹ�õ�new obj������ �Է����
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

	// ����Ϊvirtual�� һЩ����ı�ɸ�д�߼�
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