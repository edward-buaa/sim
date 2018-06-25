#ifndef __COMPARE_H_
#define __COMPARE_H_

#include <cstring>
#include "type_dec.h"

//�ַ����ȽϺ���
//@param	s1	�ַ���1
//@param	s2	�ַ���2
//@return	1��ʾ���ڣ�0��ʾ���ڣ�-1��ʾС��
inline int compare(const char *s1, const char *s2)
{
	int result = strcmp(s1, s2);
	if (result>0)
		return 1;
	else if (result<0)
		return -1;
	return 0;
}

//�ַ����ȽϺ���
//@param	s1	�ַ���1
//@param	s2	�ַ���2
//@return	1��ʾ���ڣ�0��ʾ���ڣ�-1��ʾС��
inline int compare(const std::string &s1, const std::string &s2)
{
	if (s1 < s2) return -1;
	if (s2 < s1) return 1;
	return 0;
}

//�����ȽϺ���
//@param	v1	����1
//@param	v2	����2
//@return	1��ʾ���ڣ�0��ʾ���ڣ�-1��ʾС��
inline int compare(const int v1, const int v2)
{
	if (v1>v2)
		return 1;
	if (v1<v2)
		return -1;
	return 0;
}

//�����ȽϺ���
//@param	v1	����1
//@param	v2	����2
//@return	1��ʾ���ڣ�0��ʾ���ڣ�-1��ʾС��
inline int compare(const unsigned int v1, const unsigned int v2)
{
	if (v1>v2)
		return 1;
	if (v1<v2)
		return -1;
	return 0;
}

//�������ȽϺ���
//@param	v1	������1
//@param	v2	������2
//@return	1��ʾ���ڣ�0��ʾ���ڣ�-1��ʾС��
inline int compare(const double v1, const double v2)
{
	if (v1>v2 + SMALL_DOUBLE)
		return 1;
	if (v1<v2 - SMALL_DOUBLE)
		return -1;
	return 0;
}

//QWord�ȽϺ���
//@param	v1	QWord1
//@param	v2	QWord2
//@return	1��ʾ���ڣ�0��ʾ���ڣ�-1��ʾС��
inline int compare(const LONGLONG v1, const LONGLONG v2)
{
	if (v1>v2)
		return 1;
	if (v1<v2)
		return -1;
	return 0;
}


#endif
