

#include "ftdEngine.h"

CFTDEngine::CFTDEngine(size_t poolSize)
	:CThreadBasePool{ poolSize }
{

}

CFTDEngine::~CFTDEngine()
{

}

// 用以处理所有的FTD请求
//void CFTDEngine::OnRequest(CFTDPackage_ptr msg, int sid)
//{
//
//}
//
//客户端与front建立连接
//void CFTDEngine::OnSessionConnected(weak_srv_t pSession, int sid)
//{
//
//}

//客户端与front断开
//void CFTDEngine::OnSessionDisconnected(int sid, int nReason)
//{
//
//}