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
public:
	typedef void(*describeFunc)(); /**< ����һ��ָ�뺯������ */

	/**���캯������ִ�д�����ָ�뺯��
	* @param FieldID ��ID
	* @param nStructSize ���С
	* @param pszFieldName ����
	* @param pszComment ��˵��
	* @param func    ָ��һ��������ָ��
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

	/**��ȡ���С
	* @return �������С
	*/
	inline int GetStructSize()
	{
		return m_nStructSize;
	}

	/**��ȡ��ת���ɵ��ֽ�������
	* @return ������ת���ɵ��ֽ�������
	*/
	inline int GetStreamSize()
	{
		return m_nStreamSize;
	}

	/**���Ա����
	* @return �������Ա����
	*/
	inline int GetMemberCount()
	{
		return m_MemberDesc.size();
	}

	/**��ȡ����ÿ����Ա������
	* @param index ��Ա���������ձ��е�λ��
	* @return ���س�Ա����
	*/
	inline TMemberDesc *GetMemberDesc(int index)
	{
		return &m_MemberDesc[index];
	}

	/**��ȡ�������
	* @return �������
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

	/**������ת��Ϊ�ֽ���
	* @param pStruct Ҫת���Ķ���
	* @param pStream ת�������ֽ���
	* @remark �ֽ����еĳ�Ա�����Ǹ�λ��ǰ
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

	/**���ֽ���ת��Ϊ����
	* @param pStruct ת���ĳ�����
	* @param pStream Ҫת�����ֽ���
	* @remark �ֽ����еĳ�Ա���������Ǹ�λ��ǰ
	*/
	void StreamToStruct(char *pStruct, const char *pStream, int nLength)
	{
		for (int i = 0; i<GetMemberCount(); i++) {
			TMemberDesc *p = &m_MemberDesc[i];

			// ��ֹԴ�ֽ���Խ��
			if (p->nStreamOffset + p->nSize > nLength)
			{
				// ���δ�����Ľṹ�ֶ�
				memset(pStruct + p->nStructOffset, 0, m_nStructSize - p->nStructOffset);

				// ����δ�����Ľṹ�ֶ�
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
	int			m_FieldID;			//��ID
	int			m_nStructSize;		//���С
	int			m_nStreamSize;		//��ת�����ֽ�������
	std::string	m_szComment;		//��ע��
	std::string	m_szFieldName;		//�������
	std::vector<TMemberDesc> m_MemberDesc;	//���Ա��������
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