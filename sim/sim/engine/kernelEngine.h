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

	bool initEngine();		//初始化引擎
	

private:
	bool loadConfig();		//装载配置文件
	bool loadIniFile();		//装载ini配置文件
	bool loadXMLFile();		//装载xml配置文件
	//检查配置是否存在
	std::string checkConfigExist(std::unique_ptr<config::CConfig>& pCfg);

private:
	ioContextPool engine_pool_;
};


#endif
