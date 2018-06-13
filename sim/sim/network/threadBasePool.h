#ifndef __THREAD_BASE_POOL_H__
#define __THREAD_BASE_POOL_H__

#include "../network/ioContextPool.h"

class CThreadBasePool
{
public:
	explicit CThreadBasePool(ioContextPool& pool)
		: work_pool_{ pool }
	{
		io_context_ = &(pool.getIoContext());
	}

	boost::asio::io_context& getIoContext() const
	{
		return *io_context_;
	}

	ioContextPool& getPool()
	{
		return work_pool_;
	}

private:
	boost::asio::io_context* io_context_;
	ioContextPool& work_pool_;
};

#endif