#ifndef __IO_CONTEXT_POOL__
#define __IO_CONTEXT_POOL__

/*
一个简单的boost::asio::io_context的pool，
采用每个io_context一个线程的方式，
并且采用静态初始大小，没有一般pool 的低水位，高水位 预分配 动态增加的特性
*/

#include <memory>
#include <boost/asio.hpp>

class ioContextPool final
{
public:
	explicit ioContextPool();
	ioContextPool(ioContextPool&) = delete;
	ioContextPool(ioContextPool&&) = delete;
	ioContextPool& operator=(ioContextPool&) = delete;
	ioContextPool& operator=(ioContextPool&&) = delete;
	~ioContextPool();

	void start();
	void stop();

private:
	void run(bool block);
	void wait();

private:
	//typedef boost::shared_ptr<boost::asio::io_service> io_srv_ptr;
	//typedef boost::shared_ptr<boost::asio::io_service::work> hold_ptr;
	//typedef boost::shared_ptr<boost::thread> thread_ptr;

	using io_contxt_ptr = std::shared_ptr<boost::asio::io_context>;
	//using hold_ptr = std::shared_ptr<boost::asio::io_context::work>;

};

#endif
