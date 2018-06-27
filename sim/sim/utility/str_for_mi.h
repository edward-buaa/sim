#ifndef __STR_FOR_MI_H__
#define __STR_FOR_MI_H__

/*
����char []���͵����ݣ�����multi_index��ʹ��
*/

#include <boost/functional/hash.hpp>

struct str_hash
{
	int operator()(const char *b)const
	{
		boost::hash<std::string> hasher;
		return hasher(std::string(b));
	}
};

struct str_equal
{
	bool operator()(const char *p1, const char *p2)const
	{
		return strcmp(p1, p2) == 0;
	}
	bool operator()(const std::string &p1, const std::string &p2) const
	{
		return p1 == p2;
	}
	bool operator()(const std::string &p1, const char *p2) const
	{
		return strcmp(p1.c_str(), p2) == 0;
	}
	bool operator()(const char *p1, const std::string &p2) const
	{
		return strcmp(p1, p2.c_str()) == 0;
	}
};

struct str_less
{
	bool operator()(const char *p1, const char *p2) const
	{
		return strcmp(p1, p2)<0;
	}
	bool operator()(const std::string &p1, const std::string &p2) const
	{
		return p1<p2;
	}
	bool operator()(const std::string &p1, const char *p2) const
	{
		return strcmp(p1.c_str(), p2)<0;
	}
	bool operator()(const char *p1, const std::string &p2) const
	{
		return strcmp(p1, p2.c_str())<0;
	}
};

template<class T>
struct my_less
{
	bool operator()(const char *p1, const char *p2) const
	{
		return strcmp(p1, p2)<0;
	}
	bool operator()(const std::string &p1, const std::string &p2) const
	{
		return p1<p2;
	}
	bool operator()(const std::string &p1, const char *p2) const
	{
		return strcmp(p1.c_str(), p2)<0;
	}
	bool operator()(const char *p1, const std::string &p2) const
	{
		return strcmp(p1, p2.c_str())<0;
	}
	//������ֵ���͵����ݣ�ϵͳ�г����ַ������飬������ֵ���͵�
	//template<class T>
	bool operator()(T _Left, T _Right) const
	{
		return std::less<T>()(_Left, _Right);
	}
};

template<class T>
struct my_greater
{
	bool operator()(const char *p1, const char *p2) const
	{
		return strcmp(p1, p2)>0;
	}
	bool operator()(const std::string &p1, const std::string &p2) const
	{
		return p1>p2;
	}
	bool operator()(const std::string &p1, const char *p2) const
	{
		return strcmp(p1.c_str(), p2)>0;
	}
	bool operator()(const char *p1, const std::string &p2) const
	{
		return strcmp(p1, p2.c_str())>0;
	}
	//������ֵ���͵����ݣ�ϵͳ�г����ַ������飬������ֵ���͵�
	//template<class T>
	bool operator()(T _Left, T _Right) const
	{
		return std::greater<T>()(_Left, _Right);
	}
};

template<class T>
struct my_equal
{
	bool operator()(const char *p1, const char *p2) const
	{
		return strcmp(p1, p2) == 0;
	}
	bool operator()(const std::string &p1, const std::string &p2) const
	{
		return p1 == p2;
	}
	bool operator()(const std::string &p1, const char *p2) const
	{
		return strcmp(p1.c_str(), p2) == 0;
	}
	bool operator()(const char *p1, const std::string &p2) const
	{
		return strcmp(p1, p2.c_str()) == 0;
	}
	//������ֵ���͵����ݣ�ϵͳ�г����ַ������飬������ֵ���͵�
	//template<class T>
	bool operator()(T _Left, T _Right) const
	{
		return std::equal<T>()(_Left, _Right);
	}
};

#endif
