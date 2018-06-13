#ifndef __FTD_ENGINE_H__
#define __FTD_ENGINE_H__

#include "threadBasePool.h"

class CFTDEngine : public CThreadBasePool
{
public:
	explicit CFTDEngine(size_t poolSize);
	CFTDEngine(CFTDEngine&) = delete;
	CFTDEngine(CFTDEngine&&) = delete;
	CFTDEngine& operator=(CFTDEngine&) = delete;
	CFTDEngine& operator=(CFTDEngine&&) = delete;
	~CFTDEngine();

public:
	// ���Դ������е�FTD����
	//virtual void OnRequest(CFTDPackage_ptr msg, int sid);

	//�ͻ�����front��������
	//virtual void OnSessionConnected(weak_srv_t pSession, int sid);

	//�ͻ�����front�Ͽ�
	//virtual void OnSessionDisconnected(int sid, int nReason);
};


#endif
