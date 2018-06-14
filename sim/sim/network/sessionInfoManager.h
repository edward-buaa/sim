#ifndef __SESSION_INFO_MANAGER_H__
#define __SESSION_INFO_MANAGER_H__

/*
���ܣ��Ự������
*/

#include <cstring>
#include <boost/multi_index/indexed_by.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/multi_index_container.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/composite_key.hpp>
#include "../customDataType/customDataType.h"

const int MAX_COMM_FLUX = 50;
using namespace boost::multi_index;

struct TSessionInfo
{
	TSessionInfo()
	{
		memset(this, 0, sizeof(TSessionInfo));
		bIsLogin = false;
		nMaxCommFlux = MAX_COMM_FLUX;
	}

	TSessionInfo(CSessionIDType sid)
	{
		memset(this, 0, sizeof(TSessionInfo));
		bIsLogin = false;
		nMaxCommFlux = MAX_COMM_FLUX;
		SessionID = sid;
	}

	CSessionIDType		SessionID;			//�Ự��
	bool				bIsLogin;			//�Ƿ��Ѿ���¼
	CUserIDType			userID;				//�Ự�����û�����
	int					nMaxCommFlux;		//û����ͨѶ��������
	CUserTypeType		userType;			//�û�����
	int					nDialogFlowSeqNo;	//�Ի�����ǰ���
	int					nQueryFlowSeqNo;	//��ѯ����ǰ���
	int					nPublicFlowSeqNo;	//��������ǰ���
};

class CSessionInfoManager
{
public:
	typedef boost::multi_index_container <
		TSessionInfo,
		indexed_by<
			ordered_unique<
				member<TSessionInfo, const CSessionIDType, &TSessionInfo::SessionID>
			>,
			ordered_non_unique<
				composite_key<
					TSessionInfo, member<TSessionInfo, const CUserIDType, &TSessionInfo::userID>
				>,
				composite_key_compare<
					my_less<CUserIDType>
				>
			>
		>
	> sessioninfo_list_type;
};


#endif
