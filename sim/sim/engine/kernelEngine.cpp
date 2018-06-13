
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

//װ�������ļ�
bool CKernelEngine::loadConfig()
{
	return true;
}

//װ��ini�����ļ�
bool CKernelEngine::loadIniFile()
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

//װ��xml�����ļ�
bool CKernelEngine::loadXMLFile()
{
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
		return false;
	}

	return true;
}

//��������Ƿ����
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
			s << "�����ļ���ȱ��[" << it << "]��";
			return s.str();
		}
	}

	return "";
}