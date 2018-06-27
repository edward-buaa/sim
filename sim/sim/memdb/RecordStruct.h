#ifndef __RECORD_STRUCT_H__
#define __RECORD_STRUCT_H__

#include "../network/field_describe.h"
#include "../customDataType/customDataType.h"

/////////////////////////////////////////////////////////////////////////
//CWriteableCurrentTime��һ���洢[��ǰʱ��]�Ķ��󣬿���д����
/////////////////////////////////////////////////////////////////////////
class CCurrentTime
{
public:
	//��ʼ�������������е��ֶ����
	void init();

	//���ļ�����
	//@param	input	������ļ�
	//@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE* input);

	//���ļ�д��
	//@param	output д�����ļ�
	//@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE* output) const;

	//������д���ļ���,����DEBUG
	//@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	//@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp = NULL, int index = -1) const;

	//������д���ļ���ͻ����ʾ�仯������
	//@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	//@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CCurrentTime *pOriginal) const;

	//������д���ļ���һ����,����DEBUG
	//@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp = NULL) const;

	//������д��һ���ַ�����
	//@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

public:
	//��ǰ����
	CDateType CurrDate;
	//��ǰʱ��
	CTimeType CurrTime;
	//��ǰʱ�䣨���룩
	CMillisecType CurrMillisec;
	//ҵ��ʱ��
	CDateType ActionDay;
	//ԭ��ʱ��
	CTimeType OldTime;
	//ԭ��ʱ�䣨���룩
	CMillisecType OldMillisec;

	TYPE_DESCRIPTOR((
		TYPE_DESC(CurrDate)
		,
		TYPE_DESC(CurrTime)
		,
		TYPE_DESC(CurrMillisec)
		,
		TYPE_DESC(ActionDay)
		,
		TYPE_DESC(OldTime)
		,
		TYPE_DESC(OldMillisec)
	));
};

typedef  CCurrentTime CWriteableCurrentTime;
const int REC_ID_CurrentTime = 0x11;

/////////////////////////////////////////////////////////////////////////
//CWriteableTerminal��һ���洢[�ն˻�]�Ķ��󣬿���д����
/////////////////////////////////////////////////////////////////////////
class CTerminal
{
public:
	//��ʼ�������������е��ֶ����
	void init(void);

	//���ļ�����
	//@param	input	������ļ�
	//@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);

	//���ļ�д��
	//@param	output д�����ļ�
	//@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;

	//������д���ļ���,����DEBUG
	//@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	//@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp = NULL, int index = -1) const;

	//������д���ļ���ͻ����ʾ�仯������
	//@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	//@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CTerminal *pOriginal) const;

	//������д���ļ���һ����,����DEBUG
	//@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp = NULL) const;

	//������д��һ���ַ�����
	//@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

public:
	//������
	CDateType TradingDay;
	//�ն˻����
	CTerminalIDType TerminalID;
	//�ն˻�����
	CTerminalTypeType TerminalType;
	//���׽ӿ�����
	CAppTypeType AppType;
	//�ն˻���ǰ��¼Session
	CSessionIDType SessionID;
	//�ն˻�����ʱ��
	CTimeType StartTime;
	//�ն˻�����ʱ��
	CTimeType UpdateTime;

	TYPE_DESCRIPTOR((
		TYPE_DESC(TradingDay)
		,
		TYPE_DESC(TerminalID)
		,
		TYPE_DESC(TerminalType)
		,
		TYPE_DESC(AppType)
		,
		TYPE_DESC(SessionID)
		,
		TYPE_DESC(StartTime)
		,
		TYPE_DESC(UpdateTime)
		));
};

typedef  CTerminal CWriteableTerminal;
const int REC_ID_Terminal = 0x11;


/////////////////////////////////////////////////////////////////////////
//CWriteableFront��һ���洢[ǰ�û�]�Ķ��󣬿���д����
/////////////////////////////////////////////////////////////////////////
class CFront
{
public:
	///��ʼ�������������е��ֶ����
	void init(void);

	//���ļ�����
	//@param	input	������ļ�
	//@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);

	//���ļ�д��
	//@param	output д�����ļ�
	//@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;

	//������д���ļ���,����DEBUG
	//@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	//@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp = NULL, int index = -1) const;

	//������д���ļ���ͻ����ʾ�仯������
	//@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	//@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CFront *pOriginal) const;

	//������д���ļ���һ����,����DEBUG
	//@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp = NULL) const;

	//������д��һ���ַ�����
	//@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;
public:
	//������
	CDateType TradingDay;
	//ǰ�ñ��
	CFrontIDType FrontID;
	//ǰ��Session���
	CSessionIDType SessionID;
	//ǰ�û�����ʱ��
	CTimeType StartTime;
	//ǰ�û�����ʱ��
	CTimeType UpdateTime;
	//ǰ������״̬
	CFrontRunStatusType FrontRunStatus;

	TYPE_DESCRIPTOR((
		TYPE_DESC(TradingDay)
		,
		TYPE_DESC(FrontID)
		,
		TYPE_DESC(SessionID)
		,
		TYPE_DESC(StartTime)
		,
		TYPE_DESC(UpdateTime)
		,
		TYPE_DESC(FrontRunStatus)
		));
};

typedef  CFront CWriteableFront;
const int REC_ID_Front = 0x11;


/////////////////////////////////////////////////////////////////////////
//CWriteableTrader��һ���洢[����Ա]�Ķ��󣬿���д����
/////////////////////////////////////////////////////////////////////////
class CTrader
{
public:
	//��ʼ�������������е��ֶ����
	void init(void);

	//���ļ�����
	//@param	input	������ļ�
	//@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE *input);

	//���ļ�д��
	//@param	output д�����ļ�
	//@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE *output) const;

	//������д���ļ���,����DEBUG
	//@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	//@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp = NULL, int index = -1) const;

	//������д���ļ���ͻ����ʾ�仯������
	//@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	//@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CTrader *pOriginal) const;

	//������д���ļ���һ����,����DEBUG
	//@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp = NULL) const;

	//������д��һ���ַ�����
	//@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

public:
	//����Ա����
	CTraderIDType TraderID;
	//���׽ӿ�����
	CAppTypeType AppType;
	//����Ա��¼���
	CTerminalTypeType TerminalType;
	//������
	CDateType TradingDay;
	//����Ա���������
	CCounterType MaxParalle;
	//���׽ӿ�IP��ַ
	CIPAddressType ServerIP;
	//��Ա����
	CParticipantIDType ParticipantID;
	//���ͻ�Ա����
	CBrokerIDType BrokerID;
	//����Ա��
	COperatorIDType OperatorID;
	//�û��˲�Ʒ��Ϣ
	CProductInfoType UserProductInfo;
	//�ӿڶ˲�Ʒ��Ϣ
	CProductInfoType InterfaceProductInfo;
	//Э����Ϣ
	CProtocolInfoType ProtocolInfo;
	//Mac��ַ
	CMacAddressType MacAddress;
	//�ն�IP��ַ
	CIPAddressType ClientIPAddress;
	//����
	CPasswordType Password;
	//�Ƿ�CA��֤
	CIsCaLoginType IsCaLogin;
	//��¼�������,Ŀǰֻ֧�ֵ��ͻ�
	CLoginIdentityType Identity;
	//�Ƿ�ǿ���޸�����
	CIsForcePasswordType IsForcePwd;
	//��̬����
	CPasswordType OneTimePassword;
	//otp��֤����
	COtpPassType OtpPass;
	//CA��Ϣ���ȣ�IsCaLoginΪ'Y'ʱ�����ֶ���Ч
	CSizeType CaLen;
	//CA��¼ʱ��д,IsCaLoginΪ'Y'ʱ�����ֶ���Ч
	CCaInfoType CaInfo;

	TYPE_DESCRIPTOR((
		TYPE_DESC(TraderID)
		,
		TYPE_DESC(AppType)
		,
		TYPE_DESC(TerminalType)
		,
		TYPE_DESC(TradingDay)
		,
		TYPE_DESC(MaxParalle)
		,
		TYPE_DESC(ServerIP)
		,
		TYPE_DESC(ParticipantID)
		,
		TYPE_DESC(BrokerID)
		,
		TYPE_DESC(OperatorID)
		,
		TYPE_DESC(UserProductInfo)
		,
		TYPE_DESC(InterfaceProductInfo)
		,
		TYPE_DESC(ProtocolInfo)
		,
		TYPE_DESC(MacAddress)
		,
		TYPE_DESC(ClientIPAddress)
		,
		TYPE_DESC(Password)
		,
		TYPE_DESC(IsCaLogin)
		,
		TYPE_DESC(Identity)
		,
		TYPE_DESC(IsForcePwd)
		,
		TYPE_DESC(OneTimePassword)
		,
		TYPE_DESC(OtpPass)
		,
		TYPE_DESC(CaLen)
		,
		TYPE_DESC(CaInfo)
		));
};

typedef  CTrader CWriteableTrader;
const int REC_ID_Trader = 0x11;












#endif