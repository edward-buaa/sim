#ifndef __IO_CONTEXT_POOL__
#define __IO_CONTEXT_POOL__

/*
һ���򵥵�boost::asio::io_context��pool��
����ÿ��io_contextһ���̵߳ķ�ʽ��
���Ҳ��þ�̬��ʼ��С��û��һ��pool �ĵ�ˮλ����ˮλ Ԥ���� ��̬���ӵ�����
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
