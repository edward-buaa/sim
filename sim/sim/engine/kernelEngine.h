#ifndef __KERNEL_ENGINE_H__
#define __KERNEL_ENGINE_H__

#include <memory>
#include <boost/assign.hpp>
#include <boost/optional.hpp>
#include "../network/ftdEngine.h"
#include "../config/config.h"
#include "../network/ioContextPool.h"

class CKernelEngine final : public CFTDEngine
{
public:
	explicit CKernelEngine(size_t poolSize = 1);
	CKernelEngine(CKernelEngine&) = delete;
	CKernelEngine(CKernelEngine&&) = delete;
	CKernelEngine& operator=(CKernelEngine&) = delete;
	CKernelEngine& operator=(CKernelEngine&&) = delete;
	~CKernelEngine();

	bool loadConfig();	//װ�������ļ�

private:
	bool loadIniFile();		//װ��ini�����ļ�
	bool loadXMLFile();		//װ��xml�����ļ�
	//��������Ƿ����
	std::string checkConfigExist(std::unique_ptr<solo::config::CConfig>& pCfg);

private:
	ioContextPool engine_pool_;
};


#endif
