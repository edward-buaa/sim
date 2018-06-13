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
	// 用以处理所有的FTD请求
	//virtual void OnRequest(CFTDPackage_ptr msg, int sid);

	//客户端与front建立连接
	//virtual void OnSessionConnected(weak_srv_t pSession, int sid);

	//客户端与front断开
	//virtual void OnSessionDisconnected(int sid, int nReason);
};


#endif
