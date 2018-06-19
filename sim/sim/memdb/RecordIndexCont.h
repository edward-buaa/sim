#ifndef __RECORD_INDEX_CONT_H__
#define __RECORD_INDEX_CONT_H__


/// --------------  定义 内存分配器 ------------------------------
struct MyPoolTag_CurrentTime { };
typedef boost::singleton_pool<MyPoolTag_CurrentTime, sizeof(CCurrentTime)> MEM_CurrentTime;
typedef boost::fast_pool_allocator<CCurrentTime *, boost::default_user_allocator_new_delete, boost::details::pool::null_mutex> fast_allo_CurrentTime;

typedef boost::shared_ptr<CCurrentTime> CCurrentTimePtr;
typedef multi_index_container<
	CCurrentTimePtr,
	indexed_by<
	sequenced<>
	, ordered_unique< const_mem_fun<CCurrentTimePtr, CCurrentTime *, &CCurrentTimePtr::get> >
	>
	//,fast_allo_CurrentTime>
> Idx_Cont_CurrentTime;


#endif
