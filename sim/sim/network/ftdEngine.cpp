

#include "ftdEngine.h"

CFTDEngine::CFTDEngine(size_t poolSize)
	:CThreadBasePool{ poolSize }
{

}

CFTDEngine::~CFTDEngine()
{

}

// ���Դ������е�FTD����
//void CFTDEngine::OnRequest(CFTDPackage_ptr msg, int sid)
//{
//
//}
//
//�ͻ�����front��������
//void CFTDEngine::OnSessionConnected(weak_srv_t pSession, int sid)
//{
//
//}

//�ͻ�����front�Ͽ�
//void CFTDEngine::OnSessionDisconnected(int sid, int nReason)
//{
//
//}