
#ifndef __CONFIG_MANAGER_H__
#define __CONFIG_MANAGER_H__

#include "config.h"
#include <memory>

/*
���ù�����
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

	//���������ļ�
	bool loadConfig();

private:
	const std::unique_ptr<config::CConfig> m_pIniCfg;
	const std::unique_ptr<config::CConfig> m_pXMLCfg;
};

#endif
