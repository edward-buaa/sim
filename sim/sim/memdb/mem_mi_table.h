#ifndef __MEM_MI_TABLE_H__
#define __MEM_MI_TABLE_H__

#include <boost/smart_ptr/shared_ptr.hpp>
#include "table_base.h"

template<class Rec, class CONT>
class CMemMITable : public CTableBase<Rec>
{
public:
	explicit CMemMITable() {}
	virtual ~CMemMITable() {}

	virtual Rec* direct_insert(const Rec* r)
	{
		boost::shared_ptr<Rec> p(new Rec());
		*p = *r;
		std::pair<Rec_Cont::iterator, bool> pr = m_recordList.push_back(p);
		return (pr.second) ? p.get() : 0;
	}

	virtual bool direct_remove(const Rec* pR)
	{
		typename nth_idx<1>::type& idx = get_idx<1>();

		Rec* pp = (Rec*)pR;
		typename nth_idx<1>::type::iterator it = idx.find(pp);
		if (it != idx.end())
		{
			idx.erase(it);
			return true;
		}

		return false;
	}

	virtual size_t count()
	{
		return m_recordList.size();
	}

	CONT& get_cont()
	{
		return m_recordList;
	}

private:
	typedef CONT Rec_Cont;
	Rec_Cont m_recordList;

public:

	//QQQQ需要测试
	//获取索引的定义类型
	template<int idx>
	struct nth_idx
	{
		typedef typename Rec_Cont::template nth_index<idx>::type type;
	};

	template<class tag>
	struct tag_idx
	{
		typedef typename Rec_Cont::template index<tag>::type type;
	};

	//获取具体容器的索引对象
	template<int I>
	typename nth_idx<I>::type& get_idx()
	{
		return m_recordList.get<I>();
	}

	template<class T>
	typename tag_idx<T>::type& get_idx()
	{
		return m_recordList.get<T>();
	}
};


#endif