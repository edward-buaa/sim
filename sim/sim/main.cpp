
#include <iostream>
#include <memory>
#include <boost/assign.hpp>
#include <boost/optional.hpp>
#include "config/config.h"
#include "network/ioContextPool.h"

const char* INI_FILE_NAME = "matchkernel.ini";
const char* XML_FILE_NAME = "matchkernel.xml";

std::string checkConfigExist(std::unique_ptr<solo::config::CConfig>& pCfg);

int main()
{
	//--------------װ��ini�ļ�--------------------
	std::unique_ptr<solo::config::CConfig> pCfg;
	try
	{
		pCfg = std::make_unique<solo::config::CConfig>(INI_FILE_NAME);
		pCfg->loadConfig();
		std::string msg = checkConfigExist(pCfg);
		if (!msg.empty())
		{
			std::cerr << "���������" << msg << std::endl;
			return -1;
		}
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return -1;
	}

	//--------------------װ��xml�ļ�------------------
	std::unique_ptr<solo::config::CConfig> pXML;
	try
	{
		pXML = std::make_unique<solo::config::CConfig>(XML_FILE_NAME);
		pXML->loadConfig();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return -1;
	}

	//--------------------����ϵͳ-------------------
	ioContextPool engine_pool(1);

	return 0;
}

//��������Ƿ����
std::string checkConfigExist(std::unique_ptr<solo::config::CConfig>& pCfg)
{
	std::vector<std::string> vec;
	vec = boost::assign::list_of<std::string>
		("MatchDllPath")
		("MD_SRC_Address")
		("MD_SRC_User")
		("MD_SRC_Password")
		("TkernelAddress")
		("SimAddress").to_container(vec);

	for (auto it : vec)
	{
		boost::optional<std::string> rp = pCfg->get<std::string>(it);
		if (!rp)
		{
			std::stringstream s;
			s << "�����ļ���ȱ��[" << it << "]��";
			return s.str();
		}
	}

	return "";
}