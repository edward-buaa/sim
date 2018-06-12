#ifndef __SOLO_CONFIG_H__
#define __SOLO_CONFIG_H__

/*
#ifndef�ķ�ʽ�����ں����ֲ��ܳ�ͻ���ⲻ����Ա�֤ͬһ���ļ����ᱻ������Σ�Ҳ�ܱ�֤������ȫ��ͬ�������ļ����ᱻ��С��ͬʱ��������Ȼ��ȱ����������ͬͷ�ļ��ĺ�����С�ġ�ײ���������ܾͻᵼ��ͷ�ļ��������ڣ�������ȴӲ˵�Ҳ���������״��

#pragma once���ɱ������ṩ��֤��ͬһ���ļ����ᱻ������Ρ�ע��������˵�ġ�ͬһ���ļ�����ָ�����ϵ�һ���ļ���������ָ������ͬ�������ļ��������ĺô��ǣ��㲻���ٷѾ���������ˣ���ȻҲ�Ͳ�����ֺ�����ײ������������⡣��Ӧ��ȱ��������ĳ��ͷ�ļ��ж�ݿ��������������ܱ�֤���ǲ����ظ���������Ȼ����Ⱥ�����ײ�����ġ��Ҳ��������������⣬�ظ����������ױ����ֲ�������

���ڣ�2018-6-11
���ܣ���ȡ�����ļ���֧��XML,INI,INFO,JSON��ʽ
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

	///��ȡ�����ļ�
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
	boost::property_tree::iptree m_ptree;	//ʹ�� iptree�����Դ�Сд
};

} }

#endif