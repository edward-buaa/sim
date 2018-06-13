#ifndef __THREAD_BASE_POOL_H__
#define __THREAD_BASE_POOL_H__

#include <memory>
#include "../network/ioContextPool.h"

class CThreadBasePool
{
public:
	explicit CThreadBasePool(size_t poolSize)
	{
		work_pool_.reset(new ioContextPool(poolSize));
		io_context_ = &(work_pool_->getIoContext());
	}

protected:
	boost::asio::io_context* io_context_;
	std::unique_ptr<ioContextPool> work_pool_;
};

#endif