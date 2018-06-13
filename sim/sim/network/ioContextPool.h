#ifndef __IO_CONTEXT_POOL__
#define __IO_CONTEXT_POOL__

/*
һ���򵥵�boost::asio::io_context��pool��
����ÿ��io_contextһ���̵߳ķ�ʽ��
���Ҳ��þ�̬��ʼ��С��û��һ��pool �ĵ�ˮλ����ˮλ Ԥ���� ��̬���ӵ�����
*/

#include <memory>
#include <thread>
#include <mutex>
#include <boost/asio.hpp>

class ioContextPool final
{
public:
	explicit ioContextPool(size_t poolSize = 0);
	ioContextPool(ioContextPool&) = delete;
	ioContextPool(ioContextPool&&) = delete;
	ioContextPool& operator=(ioContextPool&) = delete;
	ioContextPool& operator=(ioContextPool&&) = delete;
	~ioContextPool();

	void start();
	void stop();
	void run();
	boost::asio::io_context& getIoContext();

private:
	using io_contxt_ptr = std::shared_ptr<boost::asio::io_context>;
	using work_t = boost::asio::executor_work_guard<boost::asio::io_context::executor_type>;
	using work_ptr = std::shared_ptr<work_t>;
	using thread_ptr = std::shared_ptr<std::thread>;

	std::vector<io_contxt_ptr> io_srvs_;
	std::vector<work_ptr> works_;
	std::vector<thread_ptr> threads_;
	std::mutex mutex_;
	std::size_t next_idx_ = 0;	//next io_context used for a connection
};

#endif
