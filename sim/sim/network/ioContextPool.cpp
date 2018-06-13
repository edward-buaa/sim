

#include "ioContextPool.h"

ioContextPool::ioContextPool(size_t poolSize)
{
	if (poolSize == 0)
	{
		poolSize = std::thread::hardware_concurrency();
	}

	for (size_t i = 0; i < poolSize; ++i)
	{
		io_contxt_ptr io(new boost::asio::io_context);
		io_srvs_.push_back(io);
		work_ptr work(new work_t(boost::asio::make_work_guard(*io)));
		works_.push_back(work);
	}
}

ioContextPool::~ioContextPool()
{
	stop();
}

void ioContextPool::start()
{
	run();
}

void ioContextPool::run()
{
	if (!threads_.empty())
		return;

	for (size_t i = 0; i < io_srvs_.size(); ++i)
	{
		thread_ptr t(new std::thread(std::bind(&boost::asio::io_context::run, io_srvs_[i])));
		threads_.push_back(t);
	}
}

void ioContextPool::stop()
{
	if (works_.empty())
		return;

	std::lock_guard<std::mutex> lk(mutex_);
	for (size_t i = 0; i < works_.size(); ++i)
	{
		works_[i].reset();
	}
	works_.clear();

	//析构works的时候，会自动处理io_srv
	for (size_t k = 0; k < io_srvs_.size(); ++k)
	{
		io_srvs_[k]->stop();
	}
	io_srvs_.clear();
}

boost::asio::io_context& ioContextPool::getIoContext()
{
	boost::asio::io_context& io = *io_srvs_[next_idx_];
	std::lock_guard<std::mutex> lk(mutex_);
	++next_idx_;
	if (next_idx_ == io_srvs_.size())
	{
		next_idx_ = 0;
	}

	return io;
}