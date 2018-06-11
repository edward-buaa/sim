
#include "config.h"
#include <boost/regex.h>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/ini_parser.hpp>
#include <boost/property_tree/info_parser.hpp>
#include <boost/property_tree/json_parser.hpp>

solo::config::CConfig::CConfig(const std::string)
{

}

///��ȡ�����ļ�
void solo::config::CConfig::loadConfig()
{
	using boost::property_tree::ini_parser::ini_parser_error;
	using boost::property_tree::xml_parser::xml_parser_error;
	using boost::property_tree::info_parser::info_parser_error;
	using boost::property_tree::json_parser::json_parser_error;

	std::string expr[] =
	{
#if defined(_WIN32)// || defined(_WIN64)
		".+\\.XML",
		".+\\.INI",
		".+\\.INFO",
		".+\\.JSON",
#else
		".+/.XML",
		".+/.INI",
		".+/.INFO",
		".+/.JSON"
#endif
	};

	//�ҵ��ļ�����
	size_t type = -1;
	for (size_t i = 0; i < sizeof(expr) / sizeof(std::string); ++i)
	{
		boost::RegEx re(expr[i], true);
		if (re.Match(m_fileName))
		{
			type = i;
			break;
		}
	}

	//��ȡ�ļ�
	switch (type)
	{
	case 0:
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	default:
		break;
	}
}