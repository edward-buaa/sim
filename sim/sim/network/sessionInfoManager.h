#ifndef __SESSION_INFO_MANAGER_H__
#define __SESSION_INFO_MANAGER_H__

/*
���ܣ��Ự������
*/

#include <cstring>
#include "../customDataType/customDataType.h"

const int MAX_COMM_FLUX = 50;

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
};


#endif
