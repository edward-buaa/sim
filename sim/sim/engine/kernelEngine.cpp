
#include <iostream>
#include "kernelEngine.h"

const char* INI_FILE_NAME = "matchkernel.ini";
const char* XML_FILE_NAME = "matchkernel.xml";

CKernelEngine::CKernelEngine(size_t poolSize)
	:CFTDEngine{ poolSize }
{

}

CKernelEngine::~CKernelEngine()
{

}

//装载配置文件
bool CKernelEngine::loadConfig()
{
	return true;
}

//装载ini配置文件
bool CKernelEngine::loadIniFile()
{
	//--------------装载ini文件--------------------
	std::unique_ptr<solo::config::CConfig> pCfg;
	try
	{
		pCfg = std::make_unique<solo::config::CConfig>(INI_FILE_NAME);
		pCfg->loadConfig();
		std::string msg = checkConfigExist(pCfg);
		if (!msg.empty())
		{
			std::cerr << "配置项错误：" << msg << std::endl;
			return false;
		}
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return false;
	}

	return true;
}

//装载xml配置文件
bool CKernelEngine::loadXMLFile()
{
	//--------------------装载xml文件------------------
	std::unique_ptr<solo::config::CConfig> pXML;
	try
	{
		pXML = std::make_unique<solo::config::CConfig>(XML_FILE_NAME);
		pXML->loadConfig();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return false;
	}

	return true;
}

//检查配置是否存在
std::string CKernelEngine::checkConfigExist(std::unique_ptr<solo::config::CConfig>& pCfg)
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
			s << "配置文件中缺少[" << it << "]项";
			return s.str();
		}
	}

	return "";
}