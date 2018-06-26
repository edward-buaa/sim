
#include "config.h"
#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/ini_parser.hpp>
#include <boost/property_tree/info_parser.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/regex.h>
//#include <boost/optional.hpp>

config::CConfig::CConfig(const std::string fileName)
	: m_fileName{fileName}
{

}

config::CConfig::~CConfig()
{

}

///读取配置文件
void config::CConfig::loadConfig()
{
	using boost::property_tree::ini_parser::ini_parser_error;
	using boost::property_tree::xml_parser::xml_parser_error;
	using boost::property_tree::info_parser::info_parser_error;
	using boost::property_tree::json_parser::json_parser_error;
	using namespace boost::property_tree;

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

	//找到文件类型
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

	//读取文件
	switch (type)
	{
	case 0:	//xml
		try
		{
			xml_parser::read_xml(m_fileName, m_ptree);
		}
		catch (xml_parser_error& e)
		{
			std::stringstream s;
			s << e.message() << " ";
			s << e.line() << " in file [";
			s << e.filename() ;
			s << "]";
			throw std::runtime_error(s.str().c_str());
		}
		break;
	case 1:	//ini
		try
		{
			ini_parser::read_ini(m_fileName, m_ptree);
		}
		catch (ini_parser_error& e)
		{
			std::stringstream s;
			s << e.message() << " ";
			s << e.line() << " in file [";
			s << e.filename();
			s << "]";
			throw std::runtime_error(s.str().c_str());
		}
		break;
	case 2:		//info
		try
		{
			info_parser::read_info(m_fileName, m_ptree);
		}
		catch (info_parser_error& e)
		{
			std::stringstream s;
			s << e.message() << " ";
			s << e.line() << " in file [";
			s << e.filename();
			s << "]";
			throw std::runtime_error(s.str().c_str());
		}
		break;
	case 3:
		try
		{
			json_parser::read_json(m_fileName, m_ptree);
		}
		catch (json_parser_error& e)
		{
			std::stringstream s;
			s << e.message() << " ";
			s << e.line() << " in file [";
			s << e.filename();
			s << "]";
			throw std::runtime_error(s.str().c_str());
		}
		break;
	default:
		throw std::runtime_error("Can't support file type! Only [xml ini info json]");
	}
}