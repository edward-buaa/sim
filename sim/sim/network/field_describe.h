#ifndef __FIELD_DESCRIBE_H__
#define __FIELD_DESCRIBE_H__

/*
��һ��������еĸ�����Field���������������Ұ�����ı��루FID��
*/

#if defined(_WIN32)
#pragma warning(disable:4996)
#endif

#include <vector>
#include <string>
#include <map>
#include "Endian.h"

//�������ͱ�ʶ��
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

//���Ա���Խṹ
struct TMemberDesc 
{
	MemberType nType;			/**<��Ա����*/
	int nStructOffset;			/**<��Ա�����е�ƫ����*/
	int nStreamOffset;			/**<��Ա���ֽ����е�ƫ����*/
	int nSize;					/**<��Ա����*/
	std::string szName;			/**<��Ա����*/
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