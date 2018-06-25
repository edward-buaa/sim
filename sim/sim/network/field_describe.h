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
public:
	typedef void(*describeFunc)(); /**< 定义一个指针函数类型 */

	/**构造函数，并执行传进的指针函数
	* @param FieldID 域ID
	* @param nStructSize 域大小
	* @param pszFieldName 域名
	* @param pszComment 域说明
	* @param func    指向一个函数的指针
	*/
	FieldDescribe(int FieldID, int nStructSize, const char *pszFieldName,
		const char *pszComment, describeFunc func)
	{
		m_FieldID = FieldID;
		m_szFieldName = pszFieldName;
		m_szComment = pszComment;
		m_nStructSize = nStructSize;
		m_nStreamSize = 0;

		func();
	}

	~FieldDescribe() {};

	/**获取域大小
	* @return 返回域大小
	*/
	inline int GetStructSize()
	{
		return m_nStructSize;
	}

	/**获取类转换成的字节流长度
	* @return 返回类转换成的字节流长度
	*/
	inline int GetStreamSize()
	{
		return m_nStreamSize;
	}

	/**类成员个数
	* @return 返回类成员个数
	*/
	inline int GetMemberCount()
	{
		return m_MemberDesc.size();
	}

	/**获取域中每个成员的描述
	* @param index 成员在描述对照表中的位置
	* @return 返回成员描述
	*/
	inline TMemberDesc *GetMemberDesc(int index)
	{
		return &m_MemberDesc[index];
	}

	/**获取域的名称
	* @return 域的名称
	*/
	inline const char *GetFieldName()
	{
		return m_szFieldName.c_str();
	}

	template<class DataType>
	void SetupMember(DataType &, int offset, char *name, int length)
	{
		typedef CParamType<DataType> type;
		SetupMember_(type::TypeID, offset, name, length);
	}

	/**将对象转换为字节流
	* @param pStruct 要转换的对象
	* @param pStream 转换出的字节流
	* @remark 字节流中的成员变量是高位在前
	*/
	void StructToStream(char *pStream, char *pStruct)
	{
		for (int i = 0; i<GetMemberCount(); i++)
		{
			TMemberDesc *p = &m_MemberDesc[i];
			switch (p->nType)
			{
			case FT_CHAR:
			case FT_STRING:
				memcpy(pStream + p->nStreamOffset, pStruct + p->nStructOffset, p->nSize);
				break;
			default: // short int long double
#ifdef _BIG_ENDIAN_
				endian::ChangeEndianCopy(pStream + p->nStreamOffset, 
					pStruct + p->nStructOffset, p->nSize);
#else
				memcpy(pStream + p->nStreamOffset, pStruct + p->nStructOffset, p->nSize);
#endif
			}
		}
	}

	/**将字节流转换为对象
	* @param pStruct 转换的出对象
	* @param pStream 要转换的字节流
	* @remark 字节流中的成员变量必须是高位在前
	*/
	void StreamToStruct(char *pStruct, const char *pStream, int nLength)
	{
		for (int i = 0; i<GetMemberCount(); i++) {
			TMemberDesc *p = &m_MemberDesc[i];

			// 防止源字节流越界
			if (p->nStreamOffset + p->nSize > nLength)
			{
				// 清空未解析的结构字段
				memset(pStruct + p->nStructOffset, 0, m_nStructSize - p->nStructOffset);

				// 跳过未解析的结构字段
				break;
			}

			switch (p->nType)
			{
			case FT_CHAR:
			case FT_STRING:
				memcpy(pStruct + p->nStructOffset, pStream + p->nStreamOffset, p->nSize);
				break;
			default: // short int long double
#ifdef _BIG_ENDIAN_
				solo::endian::ChangeEndianCopy(pStruct + p->nStructOffset, pStream + p->nStreamOffset, p->nSize);
#else
				memcpy(pStruct + p->nStructOffset, pStream + p->nStreamOffset, p->nSize);
#endif
			}
		}
	}

private:
	int			m_FieldID;			//域ID
	int			m_nStructSize;		//域大小
	int			m_nStreamSize;		//域转换成字节流长度
	std::string	m_szComment;		//域注释
	std::string	m_szFieldName;		//域的名称
	std::vector<TMemberDesc> m_MemberDesc;	//域成员属性数组
};


#define TYPE_DESCRIPTOR(members) void DescribeMembers() { members; } \
									static FieldDescribe field_desc_

#define TYPE_DESC(member) field_desc_.SetupMember( \
			member,(char *)&member-(char *)this,#member,sizeof(member))

#define REGISTER_FIELD(fid,field, comment)  \
		static void DescribeMemberOf_##fid() \
		{ ((field *)NULL)->DescribeMembers(); } \
		FieldDescribe field::field_desc_( \
		fid,sizeof(field),#field,comment,&DescribeMemberOf_##fid)

#endif