
#ifndef __CONFIG_MANAGER_H__
#define __CONFIG_MANAGER_H__

#include "config.h"
#include <memory>

/*
配置管理类
*/

class configMgr
{
public:
	configMgr();
	~configMgr();
	configMgr(configMgr&) = delete;
	configMgr(configMgr&&) = delete;
	configMgr& operator=(configMgr&) = delete;
	configMgr& operator=(configMgr&&) = delete;

	//加载配置文件
	bool loadConfig();

private:
	const std::unique_ptr<config::CConfig> m_pIniCfg;
	const std::unique_ptr<config::CConfig> m_pXMLCfg;
};

#endif
