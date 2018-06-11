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
	explicit CConfig(const std::string);

	///��ȡ�����ļ�
	std::string loadConfig();

private:
	std::string m_fileName;
	boost::property_tree::iptree m_ptree;	//ʹ�� iptree�����Դ�Сд
};

} }

#endif