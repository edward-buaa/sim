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
#include "../utility/str_for_multi_index.h"

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

public:
	bool IsSessionLogin(DWORD sid)
	{
		TSessionInfo *pFind = GetSessionInfo(sid);
		if (pFind == nullptr)
			return false;

		return pFind->bIsLogin;
	}

	void SetSessionInfo(TSessionInfo& info)
	{
		SessionInfo_List_.insert(info);
		TSessionInfo* p = GetSessionInfo(info.SessionID);
	}

	TSessionInfo* GetSessionInfo(DWORD sessionID)
	{
		sessioninfo_list_type::iterator it = SessionInfo_List_.find(sessionID);
		return (it != SessionInfo_List_.end()) ? const_cast<TSessionInfo*>(&(*it)) : 0;
	}

	void ClearSessionInfo(DWORD SessionID)
	{
		SessionInfo_List_.erase(SessionID);
	}

	sessioninfo_list_type& GetSessionInfoTable()
	{
		return SessionInfo_List_;
	}

	CSessionIDType GetSessionID(const CUserIDType UserID)
	{
		typedef sessioninfo_list_type::nth_index<1>::type IndexType;
		IndexType& index = SessionInfo_List_.get<1>();
		IndexType::iterator it = index.find(boost::make_tuple(UserID));
		if (it != index.end())
		{
			return it->SessionID;
		}
		else
		{
			printf("warning: no find session infos with userid=[%s]\n", UserID);
			for (it = index.begin(); it != index.end(); ++it)
			{
				printf("session paras:sessid=[%d] userid=[%s]\n", it->SessionID, it->userID);
				if (strcmp(it->userID, UserID) == 0)
				{
					return it->SessionID;
				}
			}
		}

		return 0;
	}

private:
	//��¼�û������session����Ϣ
	sessioninfo_list_type SessionInfo_List_;
};



#endif
