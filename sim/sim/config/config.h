#ifndef __SOLO_CONFIG_H__
#define __SOLO_CONFIG_H__

/*
#ifndef的方式依赖于宏名字不能冲突，这不光可以保证同一个文件不会被包含多次，也能保证内容完全相同的两个文件不会被不小心同时包含。当然，缺点就是如果不同头文件的宏名不小心“撞车”，可能就会导致头文件明明存在，编译器却硬说找不到声明的状况

#pragma once则由编译器提供保证：同一个文件不会被包含多次。注意这里所说的“同一个文件”是指物理上的一个文件，而不是指内容相同的两个文件。带来的好处是，你不必再费劲想个宏名了，当然也就不会出现宏名碰撞引发的奇怪问题。对应的缺点就是如果某个头文件有多份拷贝，本方法不能保证他们不被重复包含。当然，相比宏名碰撞引发的“找不到声明”的问题，重复包含更容易被发现并修正。

日期：2018-6-11
功能：读取配置文件，支持XML,INI,INFO,JSON格式
*/

#include <string>
#include <boost/property_tree/ptree.hpp>

namespace solo { namespace config {

class CConfig
{
public:
	explicit CConfig(const std::string fileName);
	CConfig(CConfig&) = delete;
	CConfig(CConfig&&) = delete;
	CConfig& operator=(CConfig&) = delete;
	CConfig& operator=(CConfig&&) = delete;
	~CConfig();

	///读取配置文件
	void loadConfig();

	template<class Ret>
	boost::optional<Ret> get(const std::string& path)
	{
		return m_ptree.get_optional<Ret>(path);
	}

	template<class Ret>
	boost::optional<Ret> get(const std::string& path, const Ret default_value)
	{
		return m_ptree.get_optional<Ret>(path, default_value);
	}

	int getInt(const std::string& key)
	{
		return m_ptree.get<int>(key);
	}

	int getInt(const std::string& key, int default_value)
	{
		return m_ptree.get<int>(key, default_value);
	}

	double getDouble(const std::string& key)
	{
		return m_ptree.get<double>(key);
	}

	double getDouble(const std::string& key, double default_value)
	{
		return m_ptree.get<double>(key, default_value);
	}

	std::string getString(const std::string& key)
	{
		return m_ptree.get<std::string>(key);
	}

	std::string getString(const std::string& key, std::string default_value)
	{
		return m_ptree.get<std::string>(key, default_value);
	}

	std::string getFileName() const
	{
		return m_fileName;
	}

	boost::property_tree::iptree& getPTree()
	{
		return m_ptree;
	}

private:
	std::string m_fileName;
	boost::property_tree::iptree m_ptree;	//使用 iptree，忽略大小写
};

} }

#endif