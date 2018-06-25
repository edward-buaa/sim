#ifndef __FIELD_DESCRIBE_H__
#define __FIELD_DESCRIBE_H__

/*
对一个网络包中的各个域（Field）进行描述，并且包含域的编码（FID）
*/

#if defined(_WIN32)
#pragma warning(disable:4996)
#endif

#include <vector>
#include <string>
#include <map>
#include "Endian.h"

//数据类型标识符
enum MemberType {
	FT_CHAR,
	FT_UCHAR,
	FT_SHORT,
	//FT_USHORT,
	FT_INT,
	//FT_UINT,
	//FT_LONG,
	//FT_ULONG,
	FT_LONGLONG,
	//FT_ULONGLONG,
	FT_FLOAT,
	FT_DOUBLE,
	//FT_STRING,
	FT_BYTE = FT_CHAR,
	FT_WORD = FT_SHORT,
	FT_DWORD = FT_INT,
	FT_LONG = FT_LONGLONG,
	FT_REAL4 = FT_FLOAT,
	FT_REAL8 = FT_DOUBLE,
	FT_STRING,
};

//类成员属性结构
struct TMemberDesc 
{
	MemberType nType;			/**<成员类型*/
	int nStructOffset;			/**<成员在类中的偏移量*/
	int nStreamOffset;			/**<成员在字节流中的偏移量*/
	int nSize;					/**<成员长度*/
	std::string szName;			/**<成员名称*/
};

template<class Type>
struct CParamType {
	static const MemberType TypeID = solo::FT_STRING;
};
template<>
struct CParamType<char> {
	static const MemberType TypeID = FT_BYTE;
};
template<>
struct CParamType<short int> {
	static const MemberType TypeID = FT_WORD;
};
template<>
struct CParamType<int> {
	static const MemberType TypeID = FT_DWORD;
};
template<>
struct CParamType<float> {
	static const MemberType TypeID = FT_REAL4;
};
template<>
struct CParamType<double> {
	static const MemberType TypeID = FT_REAL8;
};
template<>
struct CParamType<long long> {
	static const MemberType TypeID = FT_LONGLONG;
};


class FieldDescribe
{

};

#endif