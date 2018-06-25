#ifndef __COMPARE_H_
#define __COMPARE_H_

#include <cstring>
#include "type_dec.h"

//字符串比较函数
//@param	s1	字符串1
//@param	s2	字符串2
//@return	1表示大于，0表示等于，-1表示小于
inline int compare(const char *s1, const char *s2)
{
	int result = strcmp(s1, s2);
	if (result>0)
		return 1;
	else if (result<0)
		return -1;
	return 0;
}

//字符串比较函数
//@param	s1	字符串1
//@param	s2	字符串2
//@return	1表示大于，0表示等于，-1表示小于
inline int compare(const std::string &s1, const std::string &s2)
{
	if (s1 < s2) return -1;
	if (s2 < s1) return 1;
	return 0;
}

//整数比较函数
//@param	v1	整数1
//@param	v2	整数2
//@return	1表示大于，0表示等于，-1表示小于
inline int compare(const int v1, const int v2)
{
	if (v1>v2)
		return 1;
	if (v1<v2)
		return -1;
	return 0;
}

//整数比较函数
//@param	v1	整数1
//@param	v2	整数2
//@return	1表示大于，0表示等于，-1表示小于
inline int compare(const unsigned int v1, const unsigned int v2)
{
	if (v1>v2)
		return 1;
	if (v1<v2)
		return -1;
	return 0;
}

//浮点数比较函数
//@param	v1	浮点数1
//@param	v2	浮点数2
//@return	1表示大于，0表示等于，-1表示小于
inline int compare(const double v1, const double v2)
{
	if (v1>v2 + SMALL_DOUBLE)
		return 1;
	if (v1<v2 - SMALL_DOUBLE)
		return -1;
	return 0;
}

//QWord比较函数
//@param	v1	QWord1
//@param	v2	QWord2
//@return	1表示大于，0表示等于，-1表示小于
inline int compare(const LONGLONG v1, const LONGLONG v2)
{
	if (v1>v2)
		return 1;
	if (v1<v2)
		return -1;
	return 0;
}


#endif
