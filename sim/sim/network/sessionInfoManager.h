#ifndef __SESSION_INFO_MANAGER_H__
#define __SESSION_INFO_MANAGER_H__

/*
功能：会话管理类
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

	CSessionIDType		SessionID;			//会话号
	bool				bIsLogin;			//是否已经登录
	CUserIDType			userID;				//会话所属用户代码
	int					nMaxCommFlux;		//没秒钟通讯流量上限
	CUserTypeType		userType;			//用户类型
	int					nDialogFlowSeqNo;	//对话流当前序号
	int					nQueryFlowSeqNo;	//查询流当前序号
	int					nPublicFlowSeqNo;	//公有流当前序号
};

class CSessionInfoManager
{
};


#endif
