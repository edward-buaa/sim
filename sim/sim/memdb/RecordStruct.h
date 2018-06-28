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

/////////////////////////////////////////////////////////////////////////
//CWriteableTraderParalle��һ���洢[����Ա������Դ]�Ķ��󣬿���д����
/////////////////////////////////////////////////////////////////////////
class CTraderParalle
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
	void dumpDiff(FILE *fp, const CTraderParalle *pOriginal) const;

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
	//����Ա��������
	CCounterType Paralled;
	//�����ʺ�����е�¼����
	CCounterType MaxParalle;

	TYPE_DESCRIPTOR((
		TYPE_DESC(TraderID)
		,
		TYPE_DESC(AppType)
		,
		TYPE_DESC(TerminalType)
		,
		TYPE_DESC(Paralled)
		,
		TYPE_DESC(MaxParalle)
		));
};

typedef  CTraderParalle CWriteableTraderParalle;
const int REC_ID_TraderParalle = 0x11;

/////////////////////////////////////////////////////////////////////////
//CWriteableTraderLoginLog��һ���洢[����Ա��¼��¼]�Ķ��󣬿���д����
/////////////////////////////////////////////////////////////////////////
class CTraderLoginLog
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
	void dumpDiff(FILE *fp, const CTraderLoginLog *pOriginal) const;

	//������д���ļ���һ����,����DEBUG
	//@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp = NULL) const;

	//������д��һ���ַ�����
	//@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

public:
	//�û����루CTP���ص�UserID����ʢ���ص���LoginNo��
	CTraderIDType TraderID;
	//���׽ӿ�����
	CAppTypeType AppType;
	//�ն˻����
	CTerminalIDType TerminalID;
	//�ն˻�����
	CTerminalTypeType TerminalType;
	//�ն˻���ǰ��¼Session
	CSessionIDType SessionID;
	//����Ա����ʱ״̬
	CTraderRuntypeType TraderRuntype;
	//�����գ�CTP���أ�
	CDateType TradingDay;
	//����Ա��ǰ�����Ƿ��Ծ
	CBoolType IsActive;
	//ʵ���˻�״̬����ʱ��
	CTimeType UpdateTime;
	//��¼�ɹ�ʱ�䣨CTP���أ�
	CTimeType ExchLoginTime;
	//���͹�˾���루CTP���أ�
	CBrokerIDType ExchBrokerID;
	//����ϵͳ���ƣ�CTP���أ�
	CSystemNameType ExchSystemName;
	//ǰ�ñ�ţ�CTP���أ�
	CFrontIDType ExchFrontID;
	//�Ự��ţ�CTP���أ�
	CSessionIDType ExchSessionID;
	//��󱨵����ã�CTP���أ�
	COrderRefType ExchMaxOrderRef;
	//�Ƿ�CA��֤����ʢ���أ�
	CIsCaLoginType ExchIsCaLogin;
	//�Ƿ�ǿ���޸����루��ʢ���أ�
	CIsForcePasswordType ExchIsForcePwd;
	//��¼���ʺż�ƣ���ʢ���أ�
	CLoginNameType ExchLoginName;
	//�ͻ�Ԥ����Ϣ,�ͻ��Լ�ʶ���̨ϵͳ����ʢ���أ�
	CReservedInfoType ExchReservedInfo;
	//�ϴε�¼ʱ�䣨��ʢ���أ�
	CDateTimeType ExchLastLoginDateTime;
	//�ϴεǳ�ʱ�䣨��ʢ���أ�
	CDateTimeType ExchLastLogoutDateTime;
	//�ϴε�¼ip������ipv6����ʢ���أ�
	CIpType ExchLastLoginIp;
	//�ϴε�¼port����ʢ���أ�
	CPortType ExchLastLoginPort;
	//�ϴε�¼������Ϣ����Ҫ��Mac��ַ����ʢ���أ�
	CMachineInfoType ExchLastLoginMachineInfo;
	//������ʱ�䣨CTP���أ�
	CTimeType ExchSHFETime;
	//������ʱ�䣨CTP���أ�
	CTimeType ExchDCETime;
	//֣����ʱ�䣨CTP���أ�
	CTimeType ExchCZCETime;
	//�н���ʱ�䣨CTP���أ�
	CTimeType ExchFFEXTime;
	//ϵͳ��ǰʱ��(�ͻ���Уʱ����ʢ���أ�
	CDateTimeType ExchServerDateTime;
	//�������
	CErrorIDType ErrorID;
	//������Ϣ
	CErrorMsgType ErrorMsg;

	TYPE_DESCRIPTOR((
		TYPE_DESC(TraderID)
		,
		TYPE_DESC(AppType)
		,
		TYPE_DESC(TerminalID)
		,
		TYPE_DESC(TerminalType)
		,
		TYPE_DESC(SessionID)
		,
		TYPE_DESC(TraderRuntype)
		,
		TYPE_DESC(TradingDay)
		,
		TYPE_DESC(IsActive)
		,
		TYPE_DESC(UpdateTime)
		,
		TYPE_DESC(ExchLoginTime)
		,
		TYPE_DESC(ExchBrokerID)
		,
		TYPE_DESC(ExchSystemName)
		,
		TYPE_DESC(ExchFrontID)
		,
		TYPE_DESC(ExchSessionID)
		,
		TYPE_DESC(ExchMaxOrderRef)
		,
		TYPE_DESC(ExchIsCaLogin)
		,
		TYPE_DESC(ExchIsForcePwd)
		,
		TYPE_DESC(ExchLoginName)
		,
		TYPE_DESC(ExchReservedInfo)
		,
		TYPE_DESC(ExchLastLoginDateTime)
		,
		TYPE_DESC(ExchLastLogoutDateTime)
		,
		TYPE_DESC(ExchLastLoginIp)
		,
		TYPE_DESC(ExchLastLoginPort)
		,
		TYPE_DESC(ExchLastLoginMachineInfo)
		,
		TYPE_DESC(ExchSHFETime)
		,
		TYPE_DESC(ExchDCETime)
		,
		TYPE_DESC(ExchCZCETime)
		,
		TYPE_DESC(ExchFFEXTime)
		,
		TYPE_DESC(ExchServerDateTime)
		,
		TYPE_DESC(ErrorID)
		,
		TYPE_DESC(ErrorMsg)
		));
};

typedef  CTraderLoginLog CWriteableTraderLoginLog;
const int REC_ID_TraderLoginLog = 0x11;

/////////////////////////////////////////////////////////////////////////
//CWriteableTraderConnect��һ���洢[����Ա����״̬]�Ķ��󣬿���д����
/////////////////////////////////////////////////////////////////////////
class CTraderConnect
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
	void dumpDiff(FILE *fp, const CTraderConnect *pOriginal) const;

	//������д���ļ���һ����,����DEBUG
	//@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp = NULL) const;

	//������д��һ���ַ�����
	//@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

public:
	//�û����루CTP���ص�UserID����ʢ���ص���LoginNo��
	CTraderIDType TraderID;
	//���׽ӿ�����
	CAppTypeType AppType;
	//�ն˻����
	CTerminalIDType TerminalID;
	//�ն˻�����
	CTerminalTypeType TerminalType;
	//�ն˻���ǰ��¼Session
	CSessionIDType SessionID;
	//����Ա����ʱ״̬
	CTraderRuntypeType TraderRuntype;
	//�����գ�CTP���أ�
	CDateType TradingDay;
	//����Ա��ǰ�����Ƿ��Ծ
	CBoolType IsActive;
	//ʵ���˻�״̬����ʱ��
	CTimeType UpdateTime;

	TYPE_DESCRIPTOR((
		TYPE_DESC(TraderID)
		,
		TYPE_DESC(AppType)
		,
		TYPE_DESC(TerminalID)
		,
		TYPE_DESC(TerminalType)
		,
		TYPE_DESC(SessionID)
		,
		TYPE_DESC(TraderRuntype)
		,
		TYPE_DESC(TradingDay)
		,
		TYPE_DESC(IsActive)
		,
		TYPE_DESC(UpdateTime)
		));
};

typedef  CTraderConnect CWriteableTraderConnect;
const int REC_ID_TraderConnect = 0x11;

/////////////////////////////////////////////////////////////////////////
//CWriteableTraderCertInfo��һ���洢[����Ա����]�Ķ��󣬿���д����
/////////////////////////////////////////////////////////////////////////
class CTraderCertInfo
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
	void dumpDiff(FILE *fp, const CTraderCertInfo *pOriginal) const;

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
	//��֤��Ϣ
	CCertInfoType CertInfo;
	//API��Կ
	CSecretKeyType SecretKey;
	//�Ƿ�����Ȩ
	CBoolType IsOption;
	//�ͻ��˲�Ʒ��Ϣ
	CAppIDType AppID;

	TYPE_DESCRIPTOR((
		TYPE_DESC(TraderID)
		,
		TYPE_DESC(AppType)
		,
		TYPE_DESC(TerminalType)
		,
		TYPE_DESC(CertInfo)
		,
		TYPE_DESC(SecretKey)
		,
		TYPE_DESC(IsOption)
		,
		TYPE_DESC(AppID)
		));
};

typedef  CTraderCertInfo CWriteableTraderCertInfo;
const int REC_ID_TraderCertInfo = 0x11;


/////////////////////////////////////////////////////////////////////////
//CWriteableUser��һ���洢[�û�]�Ķ��󣬿���д����
/////////////////////////////////////////////////////////////////////////
class CUser
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
	void dumpDiff(FILE *fp, const CUser *pOriginal) const;

	//������д���ļ���һ����,����DEBUG
	//@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp = NULL) const;

	//������д��һ���ַ�����
	//@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

public:
	//�û�����
	CUserIDType UserID;
	//�û����������
	CUserGroupIDType UserGroupID;
	//�û�����
	CIndividualNameType UserName;
	//�û�����
	CUserTypeType UserType;
	//����
	CPasswordType Password;
	//�û�״̬
	CUserStatusType UserStatus;
	//����ԱȨ��
	CTradeRightType TradeRight;
	//�Ƿ��Ծ
	CBoolType IsActive;

	TYPE_DESCRIPTOR((
		TYPE_DESC(UserID)
		,
		TYPE_DESC(UserGroupID)
		,
		TYPE_DESC(UserName)
		,
		TYPE_DESC(UserType)
		,
		TYPE_DESC(Password)
		,
		TYPE_DESC(UserStatus)
		,
		TYPE_DESC(TradeRight)
		,
		TYPE_DESC(IsActive)
		));
};

typedef  CUser CWriteableUser;
const int REC_ID_User = 0x11;







#endif