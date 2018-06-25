#ifndef __RECORD_INDEX_CONT_H__
#define __RECORD_INDEX_CONT_H__

#include "RecordStruct.h"
#include <boost/pool/pool.hpp>
#include <boost/pool/object_pool.hpp>
#include <boost/pool/pool_alloc.hpp>
#include <boost/multi_index_container.hpp>
#include <boost/multi_index/identity.hpp>
#include <boost/multi_index/sequenced_index.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/composite_key.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/multi_index/mem_fun.hpp>
#include <boost/multi_index/indexed_by.hpp>
#include <boost/smart_ptr/shared_ptr.hpp>

using boost::multi_index_container;
using namespace boost::multi_index;

/// --------------  定义 内存分配器 ------------------------------
struct MyPoolTag_CurrentTime { };
typedef boost::singleton_pool<MyPoolTag_CurrentTime, sizeof(CCurrentTime)> MEM_CurrentTime;
typedef boost::fast_pool_allocator<CCurrentTime*, boost::default_user_allocator_new_delete, 
			boost::details::pool::null_mutex> fast_allo_CurrentTime;

typedef boost::shared_ptr<CCurrentTime> CCurrentTimePtr;
typedef multi_index_container<
	CCurrentTimePtr,
	indexed_by<
	sequenced<>
	, ordered_unique< const_mem_fun<CCurrentTimePtr, CCurrentTime *, &CCurrentTimePtr::get> >
	>
> Idx_Cont_CurrentTime;


#endif
