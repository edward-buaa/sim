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

/////////////////////////////////////////////////////////////////////////
//CWriteableUserTrader��һ���洢[�û�����Ա��ϵ��]�Ķ��󣬿���д����
/////////////////////////////////////////////////////////////////////////
class CUserTrader
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
	void dumpDiff(FILE *fp, const CUserTrader *pOriginal) const;

	//������д���ļ���һ����,����DEBUG
	//@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp = NULL) const;

	//������д��һ���ַ�����
	//@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

public:
	//�û�����
	CUserIDType UserID;
	//ʵ���˻�����
	CTraderIDType TraderID;

	TYPE_DESCRIPTOR((
		TYPE_DESC(UserID)
		,
		TYPE_DESC(TraderID)
		));
};

typedef  CUserTrader CWriteableUserTrader;
const int REC_ID_UserTrader = 0x11;

/////////////////////////////////////////////////////////////////////////
//CWriteableUserFunctionRight��һ���洢[�û�Ȩ��]�Ķ��󣬿���д����
/////////////////////////////////////////////////////////////////////////
class CUserFunctionRight
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
	void dumpDiff(FILE *fp, const CUserFunctionRight *pOriginal) const;

	//������д���ļ���һ����,����DEBUG
	//@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp = NULL) const;

	//������д��һ���ַ�����
	//@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

public:
	//�û�����
	CUserIDType UserID;
	//���ܴ���
	CFunctionCodeType FunctionCode;

	TYPE_DESCRIPTOR((
		TYPE_DESC(UserID)
		,
		TYPE_DESC(FunctionCode)
	));
};

typedef  CUserFunctionRight CWriteableUserFunctionRight;
const int REC_ID_UserFunctionRight = 0x11;

/////////////////////////////////////////////////////////////////////////
//CWriteableSysInfo��һ���洢[ϵͳ��Ϣ]�Ķ��󣬿���д����
/////////////////////////////////////////////////////////////////////////
class CSysInfo
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
	void dump(FILE *fp = nullptr, int index = -1) const;

	//������д���ļ���ͻ����ʾ�仯������
	//@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	//@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CSysInfo *pOriginal) const;

	//������д���ļ���һ����,����DEBUG
	//@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp = nullptr) const;

	//������д��һ���ַ�����
	//@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

public:
	//��֤��Ϣ
	CCertInfoType CertInfo;
	//Ӧ�ó���ID
	CAppIDType AppID;
	//��־λ��
	CLogPathType LogPath;

	TYPE_DESCRIPTOR((
		TYPE_DESC(CertInfo)
		,
		TYPE_DESC(AppID)
		,
		TYPE_DESC(LogPath)
	));
};

typedef  CSysInfo CWriteableSysInfo;
const int REC_ID_SysInfo = 0x11;

/////////////////////////////////////////////////////////////////////////
//CWriteableUserSession��һ���洢[����Ա���߻Ự]�Ķ��󣬿���д����
/////////////////////////////////////////////////////////////////////////
class CUserSession
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
	void dump(FILE *fp = nullptr, int index = -1) const;

	//������д���ļ���ͻ����ʾ�仯������
	//@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	//@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CUserSession *pOriginal) const;

	//������д���ļ���һ����,����DEBUG
	//@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp = nullptr) const;

	//������д��һ���ַ�����
	//@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

public:
	//ǰ�ñ��
	CFrontIDType FrontID;
	//�û�����
	CUserIDType UserID;
	//�����û�����
	CUserTypeType UserType;
	//�Ự���
	CSessionIDType SessionID;
	//ϵͳ������
	CDateType TradingDay;
	//��¼ʱ��
	CTimeType LoginTime;
	//IP��ַ
	CIPAddressType IPAddress;
	//�û��˲�Ʒ��Ϣ
	CFunctionKeyType UserProductInfo;
	//�ӿڶ˲�Ʒ��Ϣ
	CFunctionKeyType InterfaceProductInfo;
	//Э����Ϣ
	CFunctionKeyType ProtocolInfo;
	//ϵͳ����
	CSystemNameType SystemName;
	//��󱨵�����
	COrderRefType MaxOrderRef;
	//������ʱ��
	CTimeType SHFETime;
	//������ʱ��
	CTimeType DCETime;
	//֣����ʱ��
	CTimeType CZCETime;
	//�н���ʱ��
	CTimeType FFEXTime;
	//Mac��ַ
	CMacAddressType MacAddress;
	//��̬����
	CPasswordType OneTimePassword;

	TYPE_DESCRIPTOR((
		TYPE_DESC(FrontID)
		,
		TYPE_DESC(UserID)
		,
		TYPE_DESC(UserType)
		,
		TYPE_DESC(SessionID)
		,
		TYPE_DESC(TradingDay)
		,
		TYPE_DESC(LoginTime)
		,
		TYPE_DESC(IPAddress)
		,
		TYPE_DESC(UserProductInfo)
		,
		TYPE_DESC(InterfaceProductInfo)
		,
		TYPE_DESC(ProtocolInfo)
		,
		TYPE_DESC(SystemName)
		,
		TYPE_DESC(MaxOrderRef)
		,
		TYPE_DESC(SHFETime)
		,
		TYPE_DESC(DCETime)
		,
		TYPE_DESC(CZCETime)
		,
		TYPE_DESC(FFEXTime)
		,
		TYPE_DESC(MacAddress)
		,
		TYPE_DESC(OneTimePassword)
		));
};

typedef  CUserSession CWriteableUserSession;
const int REC_ID_UserSession = 0x11;

/////////////////////////////////////////////////////////////////////////
//CWriteableMDSession��һ���洢[���鶩�������߻Ự]�Ķ��󣬿���д����
/////////////////////////////////////////////////////////////////////////
class CMDSession
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
	void dumpDiff(FILE *fp, const CMDSession *pOriginal) const;

	//������д���ļ���һ����,����DEBUG
	//@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp = NULL) const;

	//������д��һ���ַ�����
	//@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

public:
	//ǰ�ñ��
	CFrontIDType FrontID;
	//�û�����
	CUserIDType UserID;
	//�����û�����
	CUserTypeType UserType;
	//�Ự���
	CSessionIDType SessionID;
	//ϵͳ������
	CDateType TradingDay;
	//��¼ʱ��
	CTimeType LoginTime;
	//IP��ַ
	CIPAddressType IPAddress;
	//�û��˲�Ʒ��Ϣ
	CFunctionKeyType UserProductInfo;
	//�ӿڶ˲�Ʒ��Ϣ
	CFunctionKeyType InterfaceProductInfo;
	//Э����Ϣ
	CFunctionKeyType ProtocolInfo;
	//ϵͳ����
	CSystemNameType SystemName;
	//��󱨵�����
	COrderRefType MaxOrderRef;
	//������ʱ��
	CTimeType SHFETime;
	//������ʱ��
	CTimeType DCETime;
	//֣����ʱ��
	CTimeType CZCETime;
	//�н���ʱ��
	CTimeType FFEXTime;
	//Mac��ַ
	CMacAddressType MacAddress;
	//��̬����
	CPasswordType OneTimePassword;

	TYPE_DESCRIPTOR((
		TYPE_DESC(FrontID)
		,
		TYPE_DESC(UserID)
		,
		TYPE_DESC(UserType)
		,
		TYPE_DESC(SessionID)
		,
		TYPE_DESC(TradingDay)
		,
		TYPE_DESC(LoginTime)
		,
		TYPE_DESC(IPAddress)
		,
		TYPE_DESC(UserProductInfo)
		,
		TYPE_DESC(InterfaceProductInfo)
		,
		TYPE_DESC(ProtocolInfo)
		,
		TYPE_DESC(SystemName)
		,
		TYPE_DESC(MaxOrderRef)
		,
		TYPE_DESC(SHFETime)
		,
		TYPE_DESC(DCETime)
		,
		TYPE_DESC(CZCETime)
		,
		TYPE_DESC(FFEXTime)
		,
		TYPE_DESC(MacAddress)
		,
		TYPE_DESC(OneTimePassword)
		));
};

typedef  CMDSession CWriteableMDSession;
const int REC_ID_MDSession = 0x11;


/////////////////////////////////////////////////////////////////////////
//CWriteableMaxLocalID��һ���洢[��󱾵ر�����]�Ķ��󣬿���д����
/////////////////////////////////////////////////////////////////////////
class CMaxLocalID
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
	void dumpDiff(FILE *fp, const CMaxLocalID *pOriginal) const;

	//������д���ļ���һ����,����DEBUG
	//@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp = NULL) const;

	//������д��һ���ַ�����
	//@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

public:
	//�����û�����
	CUserIDType UserID;
	//��󱨵����ر��
	COrderRefType MaxOrderLocalID;

	TYPE_DESCRIPTOR((
		TYPE_DESC(UserID)
		,
		TYPE_DESC(MaxOrderLocalID)
	));
};

typedef  CMaxLocalID CWriteableMaxLocalID;
const int REC_ID_MaxLocalID = 0x11;

/////////////////////////////////////////////////////////////////////////
//CWriteableUserSubMarketData��һ���洢[���鶩��]�Ķ��󣬿���д����
/////////////////////////////////////////////////////////////////////////
class CUserSubMarketData
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
	void dumpDiff(FILE *fp, const CUserSubMarketData *pOriginal) const;

	//������д���ļ���һ����,����DEBUG
	//@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp = NULL) const;

	//������д��һ���ַ�����
	//@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

public:
	//�û�����
	CUserIDType UserID;
	//ǰ�ñ��
	CFrontIDType FrontID;
	//�Ự���
	CSessionIDType SessionID;
	//��Լ����
	CInstrumentIDType InstrumentID;

	TYPE_DESCRIPTOR((
		TYPE_DESC(UserID)
		,
		TYPE_DESC(FrontID)
		,
		TYPE_DESC(SessionID)
		,
		TYPE_DESC(InstrumentID)
	));
};

typedef  CUserSubMarketData CWriteableUserSubMarketData;
const int REC_ID_UserSubMarketData = 0x11;

/////////////////////////////////////////////////////////////////////////
//CWriteableDepthMarketData��һ���洢[�������]�Ķ��󣬿���д����
/////////////////////////////////////////////////////////////////////////
class CDepthMarketData
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
	void dumpDiff(FILE *fp, const CDepthMarketData *pOriginal) const;

	//������д���ļ���һ����,����DEBUG
	//@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp = NULL) const;

	//������д��һ���ַ�����
	//@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

public:
	//������
	CDateType TradingDay;
	//�����
	CPriceType PreClearPrice;
	//������
	CPriceType PreClosePrice;
	//��ֲ���
	CLargeVolumeType PreOpenInterest;
	//����ʵ��
	CRatioType PreDelta;
	//��Լ���
	CPriceType HistoryHigh;
	//��Լ���
	CPriceType HistoryLow;
	//����
	CPriceType OpenPrice;
	//��߼�
	CPriceType HighestPrice;
	//��ͼ�
	CPriceType LowestPrice;
	//������
	CPriceType ClosePrice;
	//��ͣ���
	CPriceType UpperLimitPrice;
	//��ͣ���
	CPriceType LowerLimitPrice;
	//���ν����
	CPriceType ClearPrice;
	//����ʵ��
	CRatioType CurrDelta;
	//���۾���
	CPrecisionType Precision;
	//���¼�
	CPriceType LastPrice;
	//����
	CVolumeType Volume;
	//�ɽ����
	CMoneyType Turnover;
	//�ֲ���
	CLargeVolumeType OpenInterest;
	//�ǵ�
	CPriceType NetChg;
	//�ǵ���
	CPriceType Markup;
	//���
	CRatioType Swing;
	//ƽ����
	CPriceType AvgPrice;
	//�����һ
	CPriceType BidPrice1;
	//������һ
	CVolumeType BidVolume1;
	//������һ
	CPriceType AskPrice1;
	//������һ
	CVolumeType AskVolume1;
	//����۶�
	CPriceType BidPrice2;
	//��������
	CVolumeType BidVolume2;
	//�������
	CPriceType BidPrice3;
	//��������
	CVolumeType BidVolume3;
	//�����۶�
	CPriceType AskPrice2;
	//��������
	CVolumeType AskVolume2;
	//��������
	CPriceType AskPrice3;
	//��������
	CVolumeType AskVolume3;
	//�������
	CPriceType BidPrice4;
	//��������
	CVolumeType BidVolume4;
	//�������
	CPriceType BidPrice5;
	//��������
	CVolumeType BidVolume5;
	//��������
	CPriceType AskPrice4;
	//��������
	CVolumeType AskVolume4;
	//��������
	CPriceType AskPrice5;
	//��������
	CVolumeType AskVolume5;
	//�������
	CPriceType BidPrice6;
	//��������
	CVolumeType BidVolume6;
	//�������
	CPriceType BidPrice7;
	//��������
	CVolumeType BidVolume7;
	//����۰�
	CPriceType BidPrice8;
	//��������
	CVolumeType BidVolume8;
	//����۾�
	CPriceType BidPrice9;
	//��������
	CVolumeType BidVolume9;
	//�����ʮ
	CPriceType BidPrice10;
	//������ʮ
	CVolumeType BidVolume10;
	//��������
	CPriceType AskPrice6;
	//��������
	CVolumeType AskVolume6;
	//��������
	CPriceType AskPrice7;
	//��������
	CVolumeType AskVolume7;
	//�����۰�
	CPriceType AskPrice8;
	//��������
	CVolumeType AskVolume8;
	//�����۾�
	CPriceType AskPrice9;
	//��������
	CVolumeType AskVolume9;
	//������ʮ
	CPriceType AskPrice10;
	//������ʮ
	CVolumeType AskVolume10;
	//���
	CSequenceNoType SequenceNo;
	//�г�������
	CMarketNameType MarketName;
	//��Լ����
	CInstrumentIDType InstrumentID;
	//��Լ����״̬-1:δ֪0:����1:�޺���2:����3:����4:����5:����ǰ6:����ǰ7:����
	CContractStateType InstrumentStatus;
	//����޸�ʱ��
	CTimeType UpdateTime;
	//����޸ĺ���
	CMillisecType UpdateMillisec;

	TYPE_DESCRIPTOR((
		TYPE_DESC(TradingDay)
		,
		TYPE_DESC(PreClearPrice)
		,
		TYPE_DESC(PreClosePrice)
		,
		TYPE_DESC(PreOpenInterest)
		,
		TYPE_DESC(PreDelta)
		,
		TYPE_DESC(HistoryHigh)
		,
		TYPE_DESC(HistoryLow)
		,
		TYPE_DESC(OpenPrice)
		,
		TYPE_DESC(HighestPrice)
		,
		TYPE_DESC(LowestPrice)
		,
		TYPE_DESC(ClosePrice)
		,
		TYPE_DESC(UpperLimitPrice)
		,
		TYPE_DESC(LowerLimitPrice)
		,
		TYPE_DESC(ClearPrice)
		,
		TYPE_DESC(CurrDelta)
		,
		TYPE_DESC(Precision)
		,
		TYPE_DESC(LastPrice)
		,
		TYPE_DESC(Volume)
		,
		TYPE_DESC(Turnover)
		,
		TYPE_DESC(OpenInterest)
		,
		TYPE_DESC(NetChg)
		,
		TYPE_DESC(Markup)
		,
		TYPE_DESC(Swing)
		,
		TYPE_DESC(AvgPrice)
		,
		TYPE_DESC(BidPrice1)
		,
		TYPE_DESC(BidVolume1)
		,
		TYPE_DESC(AskPrice1)
		,
		TYPE_DESC(AskVolume1)
		,
		TYPE_DESC(BidPrice2)
		,
		TYPE_DESC(BidVolume2)
		,
		TYPE_DESC(BidPrice3)
		,
		TYPE_DESC(BidVolume3)
		,
		TYPE_DESC(AskPrice2)
		,
		TYPE_DESC(AskVolume2)
		,
		TYPE_DESC(AskPrice3)
		,
		TYPE_DESC(AskVolume3)
		,
		TYPE_DESC(BidPrice4)
		,
		TYPE_DESC(BidVolume4)
		,
		TYPE_DESC(BidPrice5)
		,
		TYPE_DESC(BidVolume5)
		,
		TYPE_DESC(AskPrice4)
		,
		TYPE_DESC(AskVolume4)
		,
		TYPE_DESC(AskPrice5)
		,
		TYPE_DESC(AskVolume5)
		,
		TYPE_DESC(BidPrice6)
		,
		TYPE_DESC(BidVolume6)
		,
		TYPE_DESC(BidPrice7)
		,
		TYPE_DESC(BidVolume7)
		,
		TYPE_DESC(BidPrice8)
		,
		TYPE_DESC(BidVolume8)
		,
		TYPE_DESC(BidPrice9)
		,
		TYPE_DESC(BidVolume9)
		,
		TYPE_DESC(BidPrice10)
		,
		TYPE_DESC(BidVolume10)
		,
		TYPE_DESC(AskPrice6)
		,
		TYPE_DESC(AskVolume6)
		,
		TYPE_DESC(AskPrice7)
		,
		TYPE_DESC(AskVolume7)
		,
		TYPE_DESC(AskPrice8)
		,
		TYPE_DESC(AskVolume8)
		,
		TYPE_DESC(AskPrice9)
		,
		TYPE_DESC(AskVolume9)
		,
		TYPE_DESC(AskPrice10)
		,
		TYPE_DESC(AskVolume10)
		,
		TYPE_DESC(SequenceNo)
		,
		TYPE_DESC(MarketName)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(InstrumentStatus)
		,
		TYPE_DESC(UpdateTime)
		,
		TYPE_DESC(UpdateMillisec)
		));
};

typedef  CDepthMarketData CWriteableDepthMarketData;
const int REC_ID_DepthMarketData = 0x11;

/////////////////////////////////////////////////////////////////////////
//CWriteableCommodity��һ���洢[��Ʒ]�Ķ��󣬿���д����
/////////////////////////////////////////////////////////////////////////
class CCommodity
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
	void dumpDiff(FILE *fp, const CCommodity *pOriginal) const;

	//������д���ļ���һ����,����DEBUG
	//@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp = NULL) const;

	//������д��һ���ַ�����
	//@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

public:
	//���׽ӿ�����
	CAppTypeType AppType;
	//����������
	CExchangeIDType ExchangeID;
	//��Ʒ
	CCommodityIDType CommodityID;
	//��Ʒ����
	CCommodityTypeType CommodityType;
	//��Լ�ڽ������Ĵ��루CTP��������ʢ�У�ָ��RelateCommodityNo��������Լ��
	CInstrumentIDType ExchangeInstID;
	//��Ʒ����
	CCommodityNameType CommodityName;
	//��Ʒ����
	CCommodityAttributeType CommodityAttribute;
	//��Ʒ״̬
	CCommodityStateType CommodityState;
	//ÿ�ֳ���
	CProductDotType MultipleValue;
	//��С�䶯�۷���
	CUpperTickType UpperTick;
	//��С�䶯�۷�ĸ
	CLowerTickType LowerTick;
	//���۾���
	CPrecisionType Precision;
	//��Ʒʹ�ñ���
	CCurrencyIDType CurrencyID;
	//���ʽ
	CDeliveryModeType DeliveryMode;
	//������ƫ��
	CDeliveryDaysType DeliveryDays;
	//�������
	CYearType DeliveryYear;
	//������
	CMonthType DeliveryMonth;
	//�м۵�����µ���
	CVolumeType MaxMarketOrderVolume;
	//�м۵���С�µ���
	CVolumeType MinMarketOrderVolume;
	//�޼۵�����µ���
	CVolumeType MaxLimitOrderVolume;
	//�޼۵���С�µ���
	CVolumeType MinLimitOrderVolume;
	//��֤����㷽ʽ
	CDepositCalculateModeType DepositCalculateMode;
	//���ֲ���
	CVolumeType MaxHoldVol;
	//T+1ʱ��,���ڴ�ʱ��ΪT+1����
	CTimeType AddOneTime;
	//�����������(��һ��)
	CDirectType CmbDirect;
	//ƽ�ַ�ʽ
	CCoverModeType CoverMode;

	TYPE_DESCRIPTOR((
		TYPE_DESC(AppType)
		,
		TYPE_DESC(ExchangeID)
		,
		TYPE_DESC(CommodityID)
		,
		TYPE_DESC(CommodityType)
		,
		TYPE_DESC(ExchangeInstID)
		,
		TYPE_DESC(CommodityName)
		,
		TYPE_DESC(CommodityAttribute)
		,
		TYPE_DESC(CommodityState)
		,
		TYPE_DESC(MultipleValue)
		,
		TYPE_DESC(UpperTick)
		,
		TYPE_DESC(LowerTick)
		,
		TYPE_DESC(Precision)
		,
		TYPE_DESC(CurrencyID)
		,
		TYPE_DESC(DeliveryMode)
		,
		TYPE_DESC(DeliveryDays)
		,
		TYPE_DESC(DeliveryYear)
		,
		TYPE_DESC(DeliveryMonth)
		,
		TYPE_DESC(MaxMarketOrderVolume)
		,
		TYPE_DESC(MinMarketOrderVolume)
		,
		TYPE_DESC(MaxLimitOrderVolume)
		,
		TYPE_DESC(MinLimitOrderVolume)
		,
		TYPE_DESC(DepositCalculateMode)
		,
		TYPE_DESC(MaxHoldVol)
		,
		TYPE_DESC(AddOneTime)
		,
		TYPE_DESC(CmbDirect)
		,
		TYPE_DESC(CoverMode)
	));
};

typedef  CCommodity CWriteableCommodity;
const int REC_ID_Commodity = 0x11;

/////////////////////////////////////////////////////////////////////////
//CWriteableInstrument��һ���洢[��Լ]�Ķ��󣬿���д����
/////////////////////////////////////////////////////////////////////////
class CInstrument
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
	void dumpDiff(FILE *fp, const CInstrument *pOriginal) const;

	//������д���ļ���һ����,����DEBUG
	//@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp = NULL) const;

	//������д��һ���ַ�����
	//@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

public:
	//���׽ӿ�����
	CAppTypeType AppType;
	//����������
	CExchangeIDType ExchangeID;
	//��Ʒ
	CCommodityIDType CommodityID;
	//��Ʒ����
	CCommodityTypeType CommodityType;
	//��Լ
	CInstrumentIDType InstrumentID;
	//��Լ����
	CInstrumentNameType InstrumentName;
	//��Լ����
	CContractTypeType InstrumentType;
	//��Լ״̬
	CContractStateType InstrumentState;
	//��Լ�ڽ������Ĵ��루CTP��������ʢ�У�ָ��RelateCommodityNo��������Լ��
	CInstrumentIDType ExchangeInstID;
	//��Լ��������״̬
	CInstLifePhaseType InstLifePhase;
	//��Ʒ����
	CCommodityNameType CommodityName;
	//��Ʒ����
	CCommodityAttributeType CommodityAttribute;
	//��Ʒ����Ȩ��
	CTradeRightType TradeRight;
	//ÿ�ֳ���
	CProductDotType MultipleValue;
	//��С�䶯��λ
	CPriceType PriceTick;
	//��С�䶯�۷���
	CUpperTickType UpperTick;
	//��С�䶯�۷�ĸ
	CLowerTickType LowerTick;
	//��Ʒʹ�ñ���
	CCurrencyIDType CurrencyID;
	//���۾���
	CPrecisionType Precision;
	//���ʽ
	CDeliveryModeType DeliveryMode;
	//������ƫ��
	CDeliveryDaysType DeliveryDays;
	//�������
	CYearType DeliveryYear;
	//������
	CMonthType DeliveryMonth;
	//�м۵�����µ���
	CVolumeType MaxMarketOrderVolume;
	//�м۵���С�µ���
	CVolumeType MinMarketOrderVolume;
	//�޼۵�����µ���
	CVolumeType MaxLimitOrderVolume;
	//�޼۵���С�µ���
	CVolumeType MinLimitOrderVolume;
	//��֤����㷽ʽ
	CDepositCalculateModeType DepositCalculateMode;
	//���ֲ���
	CVolumeType MaxHoldVol;
	//T+1ʱ��,���ڴ�ʱ��ΪT+1����
	CTimeType AddOneTime;
	//�����������(��һ��)
	CDirectType CmbDirect;
	//ƽ�ַ�ʽ
	CCoverModeType CoverMode;
	//������
	CDateType CreateDate;
	//������
	CDateType OpenDate;
	//������
	CDateType ExpiryDate;
	//��ʼ������
	CDateType StartDelivDate;
	//����������
	CDateType EndDelivDate;
	//�ֲ�����
	CPositionTypeType PositionType;
	//�ֲ���������
	CPositionDateTypeType PositionDateType;
	//��ͷ��֤����
	CRatioType LongMarginRatio;
	//��ͷ��֤����
	CRatioType ShortMarginRatio;
	//�Ƿ�ʹ�ô��߱�֤���㷨
	CMaxMarginSideAlgorithmType MaxMarginSideAlgorithm;

	TYPE_DESCRIPTOR((
		TYPE_DESC(AppType)
		,
		TYPE_DESC(ExchangeID)
		,
		TYPE_DESC(CommodityID)
		,
		TYPE_DESC(CommodityType)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(InstrumentName)
		,
		TYPE_DESC(InstrumentType)
		,
		TYPE_DESC(InstrumentState)
		,
		TYPE_DESC(ExchangeInstID)
		,
		TYPE_DESC(InstLifePhase)
		,
		TYPE_DESC(CommodityName)
		,
		TYPE_DESC(CommodityAttribute)
		,
		TYPE_DESC(TradeRight)
		,
		TYPE_DESC(MultipleValue)
		,
		TYPE_DESC(PriceTick)
		,
		TYPE_DESC(UpperTick)
		,
		TYPE_DESC(LowerTick)
		,
		TYPE_DESC(CurrencyID)
		,
		TYPE_DESC(Precision)
		,
		TYPE_DESC(DeliveryMode)
		,
		TYPE_DESC(DeliveryDays)
		,
		TYPE_DESC(DeliveryYear)
		,
		TYPE_DESC(DeliveryMonth)
		,
		TYPE_DESC(MaxMarketOrderVolume)
		,
		TYPE_DESC(MinMarketOrderVolume)
		,
		TYPE_DESC(MaxLimitOrderVolume)
		,
		TYPE_DESC(MinLimitOrderVolume)
		,
		TYPE_DESC(DepositCalculateMode)
		,
		TYPE_DESC(MaxHoldVol)
		,
		TYPE_DESC(AddOneTime)
		,
		TYPE_DESC(CmbDirect)
		,
		TYPE_DESC(CoverMode)
		,
		TYPE_DESC(CreateDate)
		,
		TYPE_DESC(OpenDate)
		,
		TYPE_DESC(ExpiryDate)
		,
		TYPE_DESC(StartDelivDate)
		,
		TYPE_DESC(EndDelivDate)
		,
		TYPE_DESC(PositionType)
		,
		TYPE_DESC(PositionDateType)
		,
		TYPE_DESC(LongMarginRatio)
		,
		TYPE_DESC(ShortMarginRatio)
		,
		TYPE_DESC(MaxMarginSideAlgorithm)
	));
};

typedef  CInstrument CWriteableInstrument;
const int REC_ID_Instrument = 0x11;

/////////////////////////////////////////////////////////////////////////
//CWriteableOrderAction��һ���洢[��Լ�޸�]�Ķ��󣬿���д����
/////////////////////////////////////////////////////////////////////////
class COrderAction
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
	void dumpDiff(FILE *fp, const COrderAction *pOriginal) const;

	//������д���ļ���һ����,����DEBUG
	//@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp = NULL) const;

	//������д��һ���ַ�����
	//@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

public:
	//ϵͳ�ڲ�����(�ַ���)
	COrderInnerIDType OrderInnerID;
	//Ͷ���߱��
	CInvestorIDType InvestorID;
	//�û�����
	CUserIDType UserID;
	//������־
	CActionFlagType ActionFlag;
	//ί�м۸�
	CPriceType Price;
	//ί������
	CVolumeType Volume;
	//���ͻ�Ա����
	CBrokerIDType BrokerID;
	//����������
	CExchangeIDType ExchangeID;
	//�������
	COrderSysIDType OrderSysID;
	//����ID��
	CRuleIDType RuleID;
	//��������
	COrderRefType OrderRef;
	//��Լ����
	CInstrumentIDType InstrumentID;
	//��������״̬
	COrderActionStatusType OrderActionStatus;
	//״̬��Ϣ
	CErrorMsgType StatusMsg;
	//��������
	CDateType ActionTime;
	//����ʱ��
	CTimeType ActionDate;
	//�����˺�
	CTraderIDType TraderID;
	//�����ն˱���
	CTerminalIDType TerminalID;

	TYPE_DESCRIPTOR((
		TYPE_DESC(OrderInnerID)
		,
		TYPE_DESC(InvestorID)
		,
		TYPE_DESC(UserID)
		,
		TYPE_DESC(ActionFlag)
		,
		TYPE_DESC(Price)
		,
		TYPE_DESC(Volume)
		,
		TYPE_DESC(BrokerID)
		,
		TYPE_DESC(ExchangeID)
		,
		TYPE_DESC(OrderSysID)
		,
		TYPE_DESC(RuleID)
		,
		TYPE_DESC(OrderRef)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(OrderActionStatus)
		,
		TYPE_DESC(StatusMsg)
		,
		TYPE_DESC(ActionTime)
		,
		TYPE_DESC(ActionDate)
		,
		TYPE_DESC(TraderID)
		,
		TYPE_DESC(TerminalID)
	));
};

typedef  COrderAction CWriteableOrderAction;
const int REC_ID_OrderAction = 0x11;

/////////////////////////////////////////////////////////////////////////
//CWriteableExchOrderAction��һ���洢[��Լ�޸�]�Ķ��󣬿���д����
/////////////////////////////////////////////////////////////////////////
class CExchOrderAction
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
	void dumpDiff(FILE *fp, const CExchOrderAction *pOriginal) const;

	//������д���ļ���һ����,����DEBUG
	//@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp = NULL) const;

	//������д��һ���ַ�����
	//@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

public:
	//ϵͳ�ڲ�����(�ַ���)
	COrderInnerIDType OrderInnerID;
	//Ͷ���߱��
	CInvestorIDType InvestorID;
	//�û�����
	CUserIDType UserID;
	//������־
	CActionFlagType ActionFlag;
	//ί�м۸�
	CPriceType Price;
	//ί������
	CVolumeType Volume;
	//���ͻ�Ա����
	CBrokerIDType BrokerID;
	//����������
	CExchangeIDType ExchangeID;
	//�������
	COrderSysIDType OrderSysID;
	//����ID��
	CRuleIDType RuleID;
	//��������
	COrderRefType OrderRef;
	//��Լ����
	CInstrumentIDType InstrumentID;
	//��������״̬
	COrderActionStatusType OrderActionStatus;
	//��������
	CDateType ActionTime;
	//����ʱ��
	CTimeType ActionDate;
	//״̬��Ϣ
	CErrorMsgType StatusMsg;
	//�����˺�
	CTraderIDType TraderID;
	//�����ն˱���
	CTerminalIDType TerminalID;

	TYPE_DESCRIPTOR((
		TYPE_DESC(OrderInnerID)
		,
		TYPE_DESC(InvestorID)
		,
		TYPE_DESC(UserID)
		,
		TYPE_DESC(ActionFlag)
		,
		TYPE_DESC(Price)
		,
		TYPE_DESC(Volume)
		,
		TYPE_DESC(BrokerID)
		,
		TYPE_DESC(ExchangeID)
		,
		TYPE_DESC(OrderSysID)
		,
		TYPE_DESC(RuleID)
		,
		TYPE_DESC(OrderRef)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(OrderActionStatus)
		,
		TYPE_DESC(ActionTime)
		,
		TYPE_DESC(ActionDate)
		,
		TYPE_DESC(StatusMsg)
		,
		TYPE_DESC(TraderID)
		,
		TYPE_DESC(TerminalID)
	));
};

typedef  CExchOrderAction CWriteableExchOrderAction;
const int REC_ID_ExchOrderAction = 0x11;

/////////////////////////////////////////////////////////////////////////
//CWriteableOrder��һ���洢[����]�Ķ��󣬿���д����
/////////////////////////////////////////////////////////////////////////
class COrder
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
	void dumpDiff(FILE *fp, const COrder *pOriginal) const;

	//������д���ļ���һ����,����DEBUG
	//@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp = NULL) const;

	//������д��һ���ַ�����
	//@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

public:
	//�û�����
	CUserIDType UserID;
	//����������
	CExchangeIDType ExchangeID;
	//��Ʒ����
	CCommodityIDType CommodityID;
	//��Լ����
	CInstrumentIDType InstrumentID;
	//�����۸�����
	COrderPriceTypeType OrderPriceType;
	//ί��ģʽ
	COrderModeType OrderMode;
	//��������
	CDirectType Direction;
	//����ƽ��
	COffsetType OffsetFlag;
	//Ͷ����ֵ
	CHedgeType HedgeFlag;
	//ί�м۸�
	CPriceType Price;
	//ί������
	CVolumeType Volume;
	//�ͻ�������Ϣ
	COrderInfoType OrderInfo;
	//���ͻ�Ա����
	CBrokerIDType BrokerID;
	//Ͷ���߱��
	CInvestorIDType InvestorID;
	//��Ч������
	CTimeConditionType TimeCondition;
	//������
	CDateType TradingDay;
	//ϵͳ�ڲ�����(�ַ���)
	COrderInnerIDType OrderInnerID;
	//�������
	COrderSysIDType OrderSysID;
	//�ɽ��۸�
	CPriceType TradePrice;
	//��ɽ�����
	CVolumeType VolumeTraded;
	//ʣ������
	CVolumeType VolumeTotal;
	//��Լ�ڽ������Ĵ���
	CInstrumentIDType ExchangeInstID;
	//�����ύ״̬
	COrderSubmitStatusType OrderSubmitStatus;
	//ί��״̬
	COrderStateType OrderState;
	//����״̬
	COrderStatusType OrderStatus;
	//��������
	CDateType InsertDate;
	//ί��ʱ��
	CTimeType InsertTime;
	//��������
	CDateType UpdateDate;
	//����ʱ��
	CTimeType UpdateTime;
	//����ʱ��
	CTimeType CancelTime;
	//���һ�β���������Ϣ��
	CErrorIDType ErrorCode;
	//״̬��Ϣ
	CErrorMsgType StatusMsg;
	//������
	CSettlementIDType SettlementID;
	//������Դ
	COrderSourceType OrderSource;
	//���͹�˾�������
	CSequenceNoType BrokerOrderSeq;
	//��������
	COrderRefType OrderRef;
	//ǰ�ñ��
	CFrontIDType FrontID;
	//�Ự���
	CSessionIDType SessionID;

	TYPE_DESCRIPTOR((
		TYPE_DESC(UserID)
		,
		TYPE_DESC(ExchangeID)
		,
		TYPE_DESC(CommodityID)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(OrderPriceType)
		,
		TYPE_DESC(OrderMode)
		,
		TYPE_DESC(Direction)
		,
		TYPE_DESC(OffsetFlag)
		,
		TYPE_DESC(HedgeFlag)
		,
		TYPE_DESC(Price)
		,
		TYPE_DESC(Volume)
		,
		TYPE_DESC(OrderInfo)
		,
		TYPE_DESC(BrokerID)
		,
		TYPE_DESC(InvestorID)
		,
		TYPE_DESC(TimeCondition)
		,
		TYPE_DESC(TradingDay)
		,
		TYPE_DESC(OrderInnerID)
		,
		TYPE_DESC(OrderSysID)
		,
		TYPE_DESC(TradePrice)
		,
		TYPE_DESC(VolumeTraded)
		,
		TYPE_DESC(VolumeTotal)
		,
		TYPE_DESC(ExchangeInstID)
		,
		TYPE_DESC(OrderSubmitStatus)
		,
		TYPE_DESC(OrderState)
		,
		TYPE_DESC(OrderStatus)
		,
		TYPE_DESC(InsertDate)
		,
		TYPE_DESC(InsertTime)
		,
		TYPE_DESC(UpdateDate)
		,
		TYPE_DESC(UpdateTime)
		,
		TYPE_DESC(CancelTime)
		,
		TYPE_DESC(ErrorCode)
		,
		TYPE_DESC(StatusMsg)
		,
		TYPE_DESC(SettlementID)
		,
		TYPE_DESC(OrderSource)
		,
		TYPE_DESC(BrokerOrderSeq)
		,
		TYPE_DESC(OrderRef)
		,
		TYPE_DESC(FrontID)
		,
		TYPE_DESC(SessionID)
	));
};

typedef  COrder CWriteableOrder;
const int REC_ID_Order = 0x11;

/////////////////////////////////////////////////////////////////////////
//CWriteableTrade��һ���洢[�ɽ�]�Ķ��󣬿���д����
/////////////////////////////////////////////////////////////////////////
class CTrade
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
	void dump(FILE *fp = nullptr, int index = -1) const;

	//������д���ļ���ͻ����ʾ�仯������
	//@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	//@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CTrade *pOriginal) const;

	//������д���ļ���һ����,����DEBUG
	//@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp = nullptr) const;

	//������д��һ���ַ�����
	//@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

public:
	//����������
	CExchangeIDType ExchangeID;
	//������
	CDateType TradingDay;
	//�ɽ���
	CTradeIDType TradeID;
	//�������
	COrderSysIDType OrderSysID;
	//ϵͳ�ڲ�����(�ַ���)
	COrderInnerIDType OrderInnerID;
	//��Ʒ����
	CCommodityIDType CommodityID;
	//��Լ����
	CInstrumentIDType InstrumentID;
	//����Ա����
	CUserIDType UserID;
	//��������
	CDirectType Direction;
	//����ƽ��
	COffsetType OffsetFlag;
	//�ɽ���
	CPriceType TradePrice;
	//�ɽ�����
	CVolumeType VolumeTraded;
	//�ɽ�����
	CDateType TradeDate;
	//�ɽ�ʱ��
	CTimeType TradeTime;
	//������
	CMoneyType TradeFee;
	//�����ѱ���
	CCurrencyIDType CurrencyID;
	//�ֹ�������
	CManualFeeType ManualFee;
	//ɾ����־
	CDeletedType Deleted;
	//ƽ�ּ۸�
	CPriceType CoverPrice;
	//��Լ�ڽ������Ĵ���
	CInstrumentIDType ExchangeInstID;
	//���ͻ�Ա����
	CBrokerIDType BrokerID;
	//Ͷ���ߴ���
	CInvestorIDType InvestorID;
	//��������
	COrderRefType OrderRef;
	//Ͷ����ֵ
	CHedgeType HedgeFlag;

	TYPE_DESCRIPTOR((
		TYPE_DESC(ExchangeID)
		,
		TYPE_DESC(TradingDay)
		,
		TYPE_DESC(TradeID)
		,
		TYPE_DESC(OrderSysID)
		,
		TYPE_DESC(OrderInnerID)
		,
		TYPE_DESC(CommodityID)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(UserID)
		,
		TYPE_DESC(Direction)
		,
		TYPE_DESC(OffsetFlag)
		,
		TYPE_DESC(TradePrice)
		,
		TYPE_DESC(VolumeTraded)
		,
		TYPE_DESC(TradeDate)
		,
		TYPE_DESC(TradeTime)
		,
		TYPE_DESC(TradeFee)
		,
		TYPE_DESC(CurrencyID)
		,
		TYPE_DESC(ManualFee)
		,
		TYPE_DESC(Deleted)
		,
		TYPE_DESC(CoverPrice)
		,
		TYPE_DESC(ExchangeInstID)
		,
		TYPE_DESC(BrokerID)
		,
		TYPE_DESC(InvestorID)
		,
		TYPE_DESC(OrderRef)
		,
		TYPE_DESC(HedgeFlag)
	));
};

typedef  CTrade CWriteableTrade;
const int REC_ID_Trade = 0x11;

/////////////////////////////////////////////////////////////////////////
//CWriteableEsfInstPartInfo��һ���洢[��Լ������Ϣ]�Ķ��󣬿���д����
/////////////////////////////////////////////////////////////////////////
class CEsfInstPartInfo
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
	void dumpDiff(FILE *fp, const CEsfInstPartInfo *pOriginal) const;

	//������д���ļ���һ����,����DEBUG
	//@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp = NULL) const;

	//������д��һ���ַ�����
	//@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

public:
	//����������
	CExchangeNameType ExchangeName;
	//��Լ����
	CInstrumentIDType InstrumentID;
	//��Լ����
	CInstrumentNameType InstrumentName;
	//���۾���
	CPrecisionType Precision;

	TYPE_DESCRIPTOR((
		TYPE_DESC(ExchangeName)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(InstrumentName)
		,
		TYPE_DESC(Precision)
	));
};

typedef  CEsfInstPartInfo CWriteableEsfInstPartInfo;
const int REC_ID_EsfInstPartInfo = 0x11;

/////////////////////////////////////////////////////////////////////////
//CWriteableCurrency��һ���洢[������Ϣ]�Ķ��󣬿���д����
/////////////////////////////////////////////////////////////////////////
class CCurrency
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
	void dumpDiff(FILE *fp, const CCurrency *pOriginal) const;

	//������д���ļ���һ����,����DEBUG
	//@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp = NULL) const;

	//������д��һ���ַ�����
	//@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

public:
	//���ұ��
	CCurrencyIDType CurrencyID;
	//��������
	CCurrencyNameType CurrencyName;
	//�ǻ���
	CIsPrimaryCurrencyType IsPrimary;
	//���ǻ���
	CIsShareCurrencyType IsShare;
	//����(1��ǰ���һ�����ٻ���)
	CExchangeRateType ExchangeRate;

	TYPE_DESCRIPTOR((
		TYPE_DESC(CurrencyID)
		,
		TYPE_DESC(CurrencyName)
		,
		TYPE_DESC(IsPrimary)
		,
		TYPE_DESC(IsShare)
		,
		TYPE_DESC(ExchangeRate)
	));
};

typedef  CCurrency CWriteableCurrency;
const int REC_ID_Currency = 0x11;

/////////////////////////////////////////////////////////////////////////
//CWriteableExchUserLogin��һ���洢[�����û���¼]�Ķ��󣬿���д����
/////////////////////////////////////////////////////////////////////////
class CExchUserLogin
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
	void dumpDiff(FILE *fp, const CExchUserLogin *pOriginal) const;

	//������д���ļ���һ����,����DEBUG
	//@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp = NULL) const;

	//������д��һ���ַ�����
	//@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

public:
	//���͹�˾����
	CBrokerIDType BrokerID;
	//�û�����
	CUserIDType UserID;
	//��¼����
	CPasswordType Password;
	//ϵͳ������
	CDateType TradingDay;
	//��¼�ɹ�ʱ��
	CTimeType LoginTime;
	//��󱨵�����
	COrderRefType MaxOrderRef;
	//IP��ַ
	CIPAddressType IPAddress;
	//�û��˲�Ʒ��Ϣ
	CFunctionKeyType UserProductInfo;
	//�ӿڶ˲�Ʒ��Ϣ
	CFunctionKeyType InterfaceProductInfo;
	//Э����Ϣ
	CFunctionKeyType ProtocolInfo;

	TYPE_DESCRIPTOR((
		TYPE_DESC(BrokerID)
		,
		TYPE_DESC(UserID)
		,
		TYPE_DESC(Password)
		,
		TYPE_DESC(TradingDay)
		,
		TYPE_DESC(LoginTime)
		,
		TYPE_DESC(MaxOrderRef)
		,
		TYPE_DESC(IPAddress)
		,
		TYPE_DESC(UserProductInfo)
		,
		TYPE_DESC(InterfaceProductInfo)
		,
		TYPE_DESC(ProtocolInfo)
	));
};

typedef  CExchUserLogin CWriteableExchUserLogin;
const int REC_ID_ExchUserLogin = 0x11;

/////////////////////////////////////////////////////////////////////////
//CWriteableExchUserLogout��һ���洢[�����û��ǳ�]�Ķ��󣬿���д����
/////////////////////////////////////////////////////////////////////////
class CExchUserLogout
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
	void dumpDiff(FILE *fp, const CExchUserLogout *pOriginal) const;

	//������д���ļ���һ����,����DEBUG
	//@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp = NULL) const;

	//������д��һ���ַ�����
	//@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;
public:
	//�û�����
	CUserIDType UserID;
	//���͹�˾����
	CBrokerIDType BrokerID;

	TYPE_DESCRIPTOR((
		TYPE_DESC(UserID)
		,
		TYPE_DESC(BrokerID)
	));
};

typedef  CExchUserLogout CWriteableExchUserLogout;
const int REC_ID_ExchUserLogout = 0x11;

/////////////////////////////////////////////////////////////////////////
//CWriteableExchMDUserLogin��һ���洢[�����û���¼]�Ķ��󣬿���д����
/////////////////////////////////////////////////////////////////////////
class CExchMDUserLogin
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
	void dumpDiff(FILE *fp, const CExchMDUserLogin *pOriginal) const;

	//������д���ļ���һ����,����DEBUG
	//@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp = NULL) const;

	//������д��һ���ַ�����
	//@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

public:
	//���͹�˾����
	CBrokerIDType BrokerID;
	//�û�����
	CUserIDType UserID;
	//��¼����
	CPasswordType Password;
	//ϵͳ������
	CDateType TradingDay;
	//��¼�ɹ�ʱ��
	CTimeType LoginTime;
	//��󱨵�����
	COrderRefType MaxOrderRef;
	//IP��ַ
	CIPAddressType IPAddress;
	//�û��˲�Ʒ��Ϣ
	CFunctionKeyType UserProductInfo;
	//�ӿڶ˲�Ʒ��Ϣ
	CFunctionKeyType InterfaceProductInfo;
	//Э����Ϣ
	CFunctionKeyType ProtocolInfo;

	TYPE_DESCRIPTOR((
		TYPE_DESC(BrokerID)
		,
		TYPE_DESC(UserID)
		,
		TYPE_DESC(Password)
		,
		TYPE_DESC(TradingDay)
		,
		TYPE_DESC(LoginTime)
		,
		TYPE_DESC(MaxOrderRef)
		,
		TYPE_DESC(IPAddress)
		,
		TYPE_DESC(UserProductInfo)
		,
		TYPE_DESC(InterfaceProductInfo)
		,
		TYPE_DESC(ProtocolInfo)
	));
};

typedef  CExchMDUserLogin CWriteableExchMDUserLogin;
const int REC_ID_ExchMDUserLogin = 0x11;

/////////////////////////////////////////////////////////////////////////
//CWriteableExchMDUserLogout��һ���洢[�����û��ǳ�]�Ķ��󣬿���д����
/////////////////////////////////////////////////////////////////////////
class CExchMDUserLogout
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
	void dumpDiff(FILE *fp, const CExchMDUserLogout *pOriginal) const;

	//������д���ļ���һ����,����DEBUG
	//@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp = NULL) const;

	//������д��һ���ַ�����
	//@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

public:
	//�û�����
	CUserIDType UserID;
	//���͹�˾����
	CBrokerIDType BrokerID;

	TYPE_DESCRIPTOR((
		TYPE_DESC(UserID)
		,
		TYPE_DESC(BrokerID)
	));
};

typedef  CExchMDUserLogout CWriteableExchMDUserLogout;
const int REC_ID_ExchMDUserLogout = 0x11;

/////////////////////////////////////////////////////////////////////////
//CWriteableExchOrder��һ���洢[����]�Ķ��󣬿���д����
/////////////////////////////////////////////////////////////////////////
class CExchOrder
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
	void dumpDiff(FILE *fp, const CExchOrder *pOriginal) const;

	//������д���ļ���һ����,����DEBUG
	//@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp = NULL) const;

	//������д��һ���ַ�����
	//@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

public:
	//�û�����
	CUserIDType UserID;
	//����������
	CExchangeIDType ExchangeID;
	//��Ʒ����
	CCommodityIDType CommodityID;
	//��Լ����
	CInstrumentIDType InstrumentID;
	//�����۸�����
	COrderPriceTypeType OrderPriceType;
	//ί��ģʽ
	COrderModeType OrderMode;
	//��������
	CDirectType Direction;
	//����ƽ��
	COffsetType OffsetFlag;
	//Ͷ����ֵ
	CHedgeType HedgeFlag;
	//ί�м۸�
	CPriceType Price;
	//ί������
	CVolumeType Volume;
	//�ͻ�������Ϣ
	COrderInfoType OrderInfo;
	//���ͻ�Ա����
	CBrokerIDType BrokerID;
	//Ͷ���߱��
	CInvestorIDType InvestorID;
	//��Ч������
	CTimeConditionType TimeCondition;
	//������
	CDateType TradingDay;
	//ϵͳ�ڲ�����(�ַ���)
	COrderInnerIDType OrderInnerID;
	//�������
	COrderSysIDType OrderSysID;
	//�ɽ��۸�
	CPriceType TradePrice;
	//��ɽ�����
	CVolumeType VolumeTraded;
	//ʣ������
	CVolumeType VolumeTotal;
	//��Լ�ڽ������Ĵ���
	CInstrumentIDType ExchangeInstID;
	//�����ύ״̬
	COrderSubmitStatusType OrderSubmitStatus;
	//ί��״̬
	COrderStateType OrderState;
	//����״̬
	COrderStatusType OrderStatus;
	//��������
	CDateType InsertDate;
	//ί��ʱ��
	CTimeType InsertTime;
	//��������
	CDateType UpdateDate;
	//����ʱ��
	CTimeType UpdateTime;
	//����ʱ��
	CTimeType CancelTime;
	//���һ�β���������Ϣ��
	CErrorIDType ErrorCode;
	//״̬��Ϣ
	CErrorMsgType StatusMsg;
	//������
	CSettlementIDType SettlementID;
	//������Դ
	COrderSourceType OrderSource;
	//���͹�˾�������
	CSequenceNoType BrokerOrderSeq;
	//��������
	COrderRefType OrderRef;
	//ǰ�ñ��
	CFrontIDType FrontID;
	//�Ự���
	CSessionIDType SessionID;
	//�ն˻����
	CTerminalIDType TerminalID;
	//�ն˻�����
	CTerminalTypeType TerminalType;
	//���׽ӿ�����
	CAppTypeType AppType;

	TYPE_DESCRIPTOR((
		TYPE_DESC(UserID)
		,
		TYPE_DESC(ExchangeID)
		,
		TYPE_DESC(CommodityID)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(OrderPriceType)
		,
		TYPE_DESC(OrderMode)
		,
		TYPE_DESC(Direction)
		,
		TYPE_DESC(OffsetFlag)
		,
		TYPE_DESC(HedgeFlag)
		,
		TYPE_DESC(Price)
		,
		TYPE_DESC(Volume)
		,
		TYPE_DESC(OrderInfo)
		,
		TYPE_DESC(BrokerID)
		,
		TYPE_DESC(InvestorID)
		,
		TYPE_DESC(TimeCondition)
		,
		TYPE_DESC(TradingDay)
		,
		TYPE_DESC(OrderInnerID)
		,
		TYPE_DESC(OrderSysID)
		,
		TYPE_DESC(TradePrice)
		,
		TYPE_DESC(VolumeTraded)
		,
		TYPE_DESC(VolumeTotal)
		,
		TYPE_DESC(ExchangeInstID)
		,
		TYPE_DESC(OrderSubmitStatus)
		,
		TYPE_DESC(OrderState)
		,
		TYPE_DESC(OrderStatus)
		,
		TYPE_DESC(InsertDate)
		,
		TYPE_DESC(InsertTime)
		,
		TYPE_DESC(UpdateDate)
		,
		TYPE_DESC(UpdateTime)
		,
		TYPE_DESC(CancelTime)
		,
		TYPE_DESC(ErrorCode)
		,
		TYPE_DESC(StatusMsg)
		,
		TYPE_DESC(SettlementID)
		,
		TYPE_DESC(OrderSource)
		,
		TYPE_DESC(BrokerOrderSeq)
		,
		TYPE_DESC(OrderRef)
		,
		TYPE_DESC(FrontID)
		,
		TYPE_DESC(SessionID)
		,
		TYPE_DESC(TerminalID)
		,
		TYPE_DESC(TerminalType)
		,
		TYPE_DESC(AppType)
	));
};

typedef  CExchOrder CWriteableExchOrder;
const int REC_ID_ExchOrder = 0x11;

/////////////////////////////////////////////////////////////////////////
//CWriteableExchTrade��һ���洢[�ɽ�]�Ķ��󣬿���д����
/////////////////////////////////////////////////////////////////////////
class CExchTrade
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
	void dumpDiff(FILE *fp, const CExchTrade *pOriginal) const;

	//������д���ļ���һ����,����DEBUG
	//@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp = NULL) const;

	//������д��һ���ַ�����
	//@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

public:
	//����������
	CExchangeIDType ExchangeID;
	//������
	CDateType TradingDay;
	//�ɽ���
	CTradeIDType TradeID;
	//�������
	COrderSysIDType OrderSysID;
	//ϵͳ�ڲ�����(�ַ���)
	COrderInnerIDType OrderInnerID;
	//��Ʒ����
	CCommodityIDType CommodityID;
	//��Լ����
	CInstrumentIDType InstrumentID;
	//����Ա����
	CUserIDType UserID;
	//��������
	CDirectType Direction;
	//����ƽ��
	COffsetType OffsetFlag;
	//�ɽ���
	CPriceType TradePrice;
	//�ɽ�����
	CVolumeType VolumeTraded;
	//�ɽ�����
	CDateType TradeDate;
	//�ɽ�ʱ��
	CTimeType TradeTime;
	//������
	CMoneyType TradeFee;
	//�����ѱ���
	CCurrencyIDType CurrencyID;
	//�ֹ�������
	CManualFeeType ManualFee;
	//ɾ����־
	CDeletedType Deleted;
	//ƽ�ּ۸�
	CPriceType CoverPrice;
	//��Լ�ڽ������Ĵ���
	CInstrumentIDType ExchangeInstID;
	//���ͻ�Ա����
	CBrokerIDType BrokerID;
	//Ͷ���ߴ���
	CInvestorIDType InvestorID;
	//��������
	COrderRefType OrderRef;
	//Ͷ����ֵ
	CHedgeType HedgeFlag;

	TYPE_DESCRIPTOR((
		TYPE_DESC(ExchangeID)
		,
		TYPE_DESC(TradingDay)
		,
		TYPE_DESC(TradeID)
		,
		TYPE_DESC(OrderSysID)
		,
		TYPE_DESC(OrderInnerID)
		,
		TYPE_DESC(CommodityID)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(UserID)
		,
		TYPE_DESC(Direction)
		,
		TYPE_DESC(OffsetFlag)
		,
		TYPE_DESC(TradePrice)
		,
		TYPE_DESC(VolumeTraded)
		,
		TYPE_DESC(TradeDate)
		,
		TYPE_DESC(TradeTime)
		,
		TYPE_DESC(TradeFee)
		,
		TYPE_DESC(CurrencyID)
		,
		TYPE_DESC(ManualFee)
		,
		TYPE_DESC(Deleted)
		,
		TYPE_DESC(CoverPrice)
		,
		TYPE_DESC(ExchangeInstID)
		,
		TYPE_DESC(BrokerID)
		,
		TYPE_DESC(InvestorID)
		,
		TYPE_DESC(OrderRef)
		,
		TYPE_DESC(HedgeFlag)
	));
};

typedef  CExchTrade CWriteableExchTrade;
const int REC_ID_ExchTrade = 0x11;

/////////////////////////////////////////////////////////////////////////
//CWriteableExchInvestorPosition��һ���洢[Ͷ���߲�λ]�Ķ��󣬿���д����
/////////////////////////////////////////////////////////////////////////
class CExchInvestorPosition
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
	void dumpDiff(FILE *fp, const CExchInvestorPosition *pOriginal) const;

	//������д���ļ���һ����,����DEBUG
	//@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp = NULL) const;

	//������д��һ���ַ�����
	//@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

public:
	//Ͷ���߱��
	CInvestorIDType InvestorID;
	//���͹�˾����
	CBrokerIDType BrokerID;
	//����������
	CExchangeIDType ExchangeID;
	//�ͻ�����
	CClientIDType ClientID;
	//��Լ����
	CInstrumentIDType InstrumentID;
	//��������
	CDirectionType Direction;
	//Ͷ���ױ���־
	CHedgeFlagType HedgeFlag;
	//ռ�ñ�֤��
	CUsedMarginType UsedMargin;
	//��ֲ���
	CPositionType Position;
	//���ճֲֳɱ�
	CPositionCostType PositionCost;
	//��ֲ���
	CYdPositionType YdPosition;
	//���ճֲֳɱ�
	CYdPositionCostType YdPositionCost;
	//����ı�֤��
	CFrozenMarginType FrozenMargin;
	//���ֶ���ֲ�
	CFrozenPositionType FrozenPosition;
	//ƽ�ֶ���ֲ�
	CFrozenClosingType FrozenClosing;
	//�����Ȩ����
	CFrozenPremiumType FrozenPremium;
	//���һ�ʳɽ����
	CLastTradeIDType LastTradeID;
	//���һ�ʱ��ر������
	CLastOrderLocalIDType LastOrderLocalID;
	//����
	CCurrencyType Currency;

	TYPE_DESCRIPTOR((
		TYPE_DESC(InvestorID)
		,
		TYPE_DESC(BrokerID)
		,
		TYPE_DESC(ExchangeID)
		,
		TYPE_DESC(ClientID)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(Direction)
		,
		TYPE_DESC(HedgeFlag)
		,
		TYPE_DESC(UsedMargin)
		,
		TYPE_DESC(Position)
		,
		TYPE_DESC(PositionCost)
		,
		TYPE_DESC(YdPosition)
		,
		TYPE_DESC(YdPositionCost)
		,
		TYPE_DESC(FrozenMargin)
		,
		TYPE_DESC(FrozenPosition)
		,
		TYPE_DESC(FrozenClosing)
		,
		TYPE_DESC(FrozenPremium)
		,
		TYPE_DESC(LastTradeID)
		,
		TYPE_DESC(LastOrderLocalID)
		,
		TYPE_DESC(Currency)
	));
};

typedef  CExchInvestorPosition CWriteableExchInvestorPosition;
const int REC_ID_ExchInvestorPosition = 0x11;

/////////////////////////////////////////////////////////////////////////
//CWriteableExchInvestorAccount��һ���洢[Ͷ�����ʽ�]�Ķ��󣬿���д����
/////////////////////////////////////////////////////////////////////////
class CExchInvestorAccount
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
	void dumpDiff(FILE *fp, const CExchInvestorAccount *pOriginal) const;

	//������д���ļ���һ����,����DEBUG
	//@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp = NULL) const;

	//������д��һ���ַ�����
	//@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

public:
	//���͹�˾����
	CBrokerIDType BrokerID;
	//Ͷ���ߴ���
	CInvestorIDType InvestorID;
	//�ʽ��ʺ�
	CAccountIDType AccountID;
	//�ϴν���׼����
	CPreBalanceType PreBalance;
	//�����
	CDepositType Deposit;
	//������
	CWithdrawType Withdraw;
	//����ı�֤��
	CFrozenMarginType FrozenMargin;
	//����������
	CFrozenFeeType FrozenFee;
	//����Ȩ����
	CFrozenPremiumType FrozenPremium;
	//������
	CFeeType Fee;
	//ƽ��ӯ��
	CCloseProfitType CloseProfit;
	//�ֲ�ӯ��
	CPositionProfitType PositionProfit;
	//�����ʽ�
	CAvailableType Available;
	//��ͷ����ı�֤��
	CLongFrozenMarginType LongFrozenMargin;
	//��ͷ����ı�֤��
	CShortFrozenMarginType ShortFrozenMargin;
	//��ͷռ�ñ�֤��
	CLongMarginType LongMargin;
	//��ͷռ�ñ�֤��
	CShortMarginType ShortMargin;
	//�����ͷű�֤��
	CReleaseMarginType ReleaseMargin;
	//��̬Ȩ��
	CDynamicRightsType DynamicRights;
	//���ճ����
	CTodayInOutType TodayInOut;
	//ռ�ñ�֤��
	CMarginType Margin;
	//��ȨȨ������֧
	CPremiumType Premium;
	//���ն�
	CRiskType Risk;

	TYPE_DESCRIPTOR((
		TYPE_DESC(BrokerID)
		,
		TYPE_DESC(InvestorID)
		,
		TYPE_DESC(AccountID)
		,
		TYPE_DESC(PreBalance)
		,
		TYPE_DESC(Deposit)
		,
		TYPE_DESC(Withdraw)
		,
		TYPE_DESC(FrozenMargin)
		,
		TYPE_DESC(FrozenFee)
		,
		TYPE_DESC(FrozenPremium)
		,
		TYPE_DESC(Fee)
		,
		TYPE_DESC(CloseProfit)
		,
		TYPE_DESC(PositionProfit)
		,
		TYPE_DESC(Available)
		,
		TYPE_DESC(LongFrozenMargin)
		,
		TYPE_DESC(ShortFrozenMargin)
		,
		TYPE_DESC(LongMargin)
		,
		TYPE_DESC(ShortMargin)
		,
		TYPE_DESC(ReleaseMargin)
		,
		TYPE_DESC(DynamicRights)
		,
		TYPE_DESC(TodayInOut)
		,
		TYPE_DESC(Margin)
		,
		TYPE_DESC(Premium)
		,
		TYPE_DESC(Risk)
	));
};

typedef  CExchInvestorAccount CWriteableExchInvestorAccount;
const int REC_ID_ExchInvestorAccount = 0x11;

/////////////////////////////////////////////////////////////////////////
//CWriteableExchDepthMarketData��һ���洢[�������]�Ķ��󣬿���д����
/////////////////////////////////////////////////////////////////////////
class CExchDepthMarketData
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
	void dumpDiff(FILE *fp, const CExchDepthMarketData *pOriginal) const;

	//������д���ļ���һ����,����DEBUG
	//@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp = NULL) const;

	//������д��һ���ַ�����
	//@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

public:
	//������
	CDateType TradingDay;
	//�����
	CPriceType PreClearPrice;
	//������
	CPriceType PreClosePrice;
	//��ֲ���
	CLargeVolumeType PreOpenInterest;
	//����ʵ��
	CRatioType PreDelta;
	//��Լ���
	CPriceType HistoryHigh;
	//��Լ���
	CPriceType HistoryLow;
	//����
	CPriceType OpenPrice;
	//��߼�
	CPriceType HighestPrice;
	//��ͼ�
	CPriceType LowestPrice;
	//������
	CPriceType ClosePrice;
	//��ͣ���
	CPriceType UpperLimitPrice;
	//��ͣ���
	CPriceType LowerLimitPrice;
	//���ν����
	CPriceType ClearPrice;
	//����ʵ��
	CRatioType CurrDelta;
	//���۾���
	CPrecisionType Precision;
	//���¼�
	CPriceType LastPrice;
	//����
	CVolumeType Volume;
	//�ɽ����
	CMoneyType Turnover;
	//�ֲ���
	CLargeVolumeType OpenInterest;
	//�ǵ�
	CPriceType NetChg;
	//�ǵ���
	CPriceType Markup;
	//���
	CRatioType Swing;
	//ƽ����
	CPriceType AvgPrice;
	//�����һ
	CPriceType BidPrice1;
	//������һ
	CVolumeType BidVolume1;
	//������һ
	CPriceType AskPrice1;
	//������һ
	CVolumeType AskVolume1;
	//����۶�
	CPriceType BidPrice2;
	//��������
	CVolumeType BidVolume2;
	//�������
	CPriceType BidPrice3;
	//��������
	CVolumeType BidVolume3;
	//�����۶�
	CPriceType AskPrice2;
	//��������
	CVolumeType AskVolume2;
	//��������
	CPriceType AskPrice3;
	//��������
	CVolumeType AskVolume3;
	//�������
	CPriceType BidPrice4;
	//��������
	CVolumeType BidVolume4;
	//�������
	CPriceType BidPrice5;
	//��������
	CVolumeType BidVolume5;
	//��������
	CPriceType AskPrice4;
	//��������
	CVolumeType AskVolume4;
	//��������
	CPriceType AskPrice5;
	//��������
	CVolumeType AskVolume5;
	//�������
	CPriceType BidPrice6;
	//��������
	CVolumeType BidVolume6;
	//�������
	CPriceType BidPrice7;
	//��������
	CVolumeType BidVolume7;
	//����۰�
	CPriceType BidPrice8;
	//��������
	CVolumeType BidVolume8;
	//����۾�
	CPriceType BidPrice9;
	//��������
	CVolumeType BidVolume9;
	//�����ʮ
	CPriceType BidPrice10;
	//������ʮ
	CVolumeType BidVolume10;
	//��������
	CPriceType AskPrice6;
	//��������
	CVolumeType AskVolume6;
	//��������
	CPriceType AskPrice7;
	//��������
	CVolumeType AskVolume7;
	//�����۰�
	CPriceType AskPrice8;
	//��������
	CVolumeType AskVolume8;
	//�����۾�
	CPriceType AskPrice9;
	//��������
	CVolumeType AskVolume9;
	//������ʮ
	CPriceType AskPrice10;
	//������ʮ
	CVolumeType AskVolume10;
	//���
	CSequenceNoType SequenceNo;
	//�г�������
	CMarketNameType MarketName;
	//��Լ����
	CInstrumentIDType InstrumentID;
	//��Լ����״̬-1:δ֪0:����1:�޺���2:����3:����4:����5:����ǰ6:����ǰ7:����
	CContractStateType InstrumentStatus;
	//����޸�ʱ��
	CTimeType UpdateTime;
	//����޸ĺ���
	CMillisecType UpdateMillisec;

	TYPE_DESCRIPTOR((
		TYPE_DESC(TradingDay)
		,
		TYPE_DESC(PreClearPrice)
		,
		TYPE_DESC(PreClosePrice)
		,
		TYPE_DESC(PreOpenInterest)
		,
		TYPE_DESC(PreDelta)
		,
		TYPE_DESC(HistoryHigh)
		,
		TYPE_DESC(HistoryLow)
		,
		TYPE_DESC(OpenPrice)
		,
		TYPE_DESC(HighestPrice)
		,
		TYPE_DESC(LowestPrice)
		,
		TYPE_DESC(ClosePrice)
		,
		TYPE_DESC(UpperLimitPrice)
		,
		TYPE_DESC(LowerLimitPrice)
		,
		TYPE_DESC(ClearPrice)
		,
		TYPE_DESC(CurrDelta)
		,
		TYPE_DESC(Precision)
		,
		TYPE_DESC(LastPrice)
		,
		TYPE_DESC(Volume)
		,
		TYPE_DESC(Turnover)
		,
		TYPE_DESC(OpenInterest)
		,
		TYPE_DESC(NetChg)
		,
		TYPE_DESC(Markup)
		,
		TYPE_DESC(Swing)
		,
		TYPE_DESC(AvgPrice)
		,
		TYPE_DESC(BidPrice1)
		,
		TYPE_DESC(BidVolume1)
		,
		TYPE_DESC(AskPrice1)
		,
		TYPE_DESC(AskVolume1)
		,
		TYPE_DESC(BidPrice2)
		,
		TYPE_DESC(BidVolume2)
		,
		TYPE_DESC(BidPrice3)
		,
		TYPE_DESC(BidVolume3)
		,
		TYPE_DESC(AskPrice2)
		,
		TYPE_DESC(AskVolume2)
		,
		TYPE_DESC(AskPrice3)
		,
		TYPE_DESC(AskVolume3)
		,
		TYPE_DESC(BidPrice4)
		,
		TYPE_DESC(BidVolume4)
		,
		TYPE_DESC(BidPrice5)
		,
		TYPE_DESC(BidVolume5)
		,
		TYPE_DESC(AskPrice4)
		,
		TYPE_DESC(AskVolume4)
		,
		TYPE_DESC(AskPrice5)
		,
		TYPE_DESC(AskVolume5)
		,
		TYPE_DESC(BidPrice6)
		,
		TYPE_DESC(BidVolume6)
		,
		TYPE_DESC(BidPrice7)
		,
		TYPE_DESC(BidVolume7)
		,
		TYPE_DESC(BidPrice8)
		,
		TYPE_DESC(BidVolume8)
		,
		TYPE_DESC(BidPrice9)
		,
		TYPE_DESC(BidVolume9)
		,
		TYPE_DESC(BidPrice10)
		,
		TYPE_DESC(BidVolume10)
		,
		TYPE_DESC(AskPrice6)
		,
		TYPE_DESC(AskVolume6)
		,
		TYPE_DESC(AskPrice7)
		,
		TYPE_DESC(AskVolume7)
		,
		TYPE_DESC(AskPrice8)
		,
		TYPE_DESC(AskVolume8)
		,
		TYPE_DESC(AskPrice9)
		,
		TYPE_DESC(AskVolume9)
		,
		TYPE_DESC(AskPrice10)
		,
		TYPE_DESC(AskVolume10)
		,
		TYPE_DESC(SequenceNo)
		,
		TYPE_DESC(MarketName)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(InstrumentStatus)
		,
		TYPE_DESC(UpdateTime)
		,
		TYPE_DESC(UpdateMillisec)
	));
};

typedef  CExchDepthMarketData CWriteableExchDepthMarketData;
const int REC_ID_ExchDepthMarketData = 0x11;

/////////////////////////////////////////////////////////////////////////
//CWriteableExchDepthMarketHistoryData��һ���洢[���������ʷ]�Ķ��󣬿���д����
/////////////////////////////////////////////////////////////////////////
class CExchDepthMarketHistoryData
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
	void dumpDiff(FILE *fp, const CExchDepthMarketHistoryData *pOriginal) const;

	//������д���ļ���һ����,����DEBUG
	//@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp = NULL) const;

	//������д��һ���ַ�����
	//@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

public:
	//������
	CDateType TradingDay;
	//�����
	CPriceType PreClearPrice;
	//������
	CPriceType PreClosePrice;
	//��ֲ���
	CLargeVolumeType PreOpenInterest;
	//����ʵ��
	CRatioType PreDelta;
	//��Լ���
	CPriceType HistoryHigh;
	//��Լ���
	CPriceType HistoryLow;
	//����
	CPriceType OpenPrice;
	//��߼�
	CPriceType HighestPrice;
	//��ͼ�
	CPriceType LowestPrice;
	//������
	CPriceType ClosePrice;
	//��ͣ���
	CPriceType UpperLimitPrice;
	//��ͣ���
	CPriceType LowerLimitPrice;
	//���ν����
	CPriceType ClearPrice;
	//����ʵ��
	CRatioType CurrDelta;
	//���۾���
	CPrecisionType Precision;
	//���¼�
	CPriceType LastPrice;
	//����
	CVolumeType Volume;
	//�ɽ����
	CMoneyType Turnover;
	//�ֲ���
	CLargeVolumeType OpenInterest;
	//�ǵ�
	CPriceType NetChg;
	//�ǵ���
	CPriceType Markup;
	//���
	CRatioType Swing;
	//ƽ����
	CPriceType AvgPrice;
	//�����һ
	CPriceType BidPrice1;
	//������һ
	CVolumeType BidVolume1;
	//������һ
	CPriceType AskPrice1;
	//������һ
	CVolumeType AskVolume1;
	//����۶�
	CPriceType BidPrice2;
	//��������
	CVolumeType BidVolume2;
	//�������
	CPriceType BidPrice3;
	//��������
	CVolumeType BidVolume3;
	//�����۶�
	CPriceType AskPrice2;
	//��������
	CVolumeType AskVolume2;
	//��������
	CPriceType AskPrice3;
	//��������
	CVolumeType AskVolume3;
	//�������
	CPriceType BidPrice4;
	//��������
	CVolumeType BidVolume4;
	//�������
	CPriceType BidPrice5;
	//��������
	CVolumeType BidVolume5;
	//��������
	CPriceType AskPrice4;
	//��������
	CVolumeType AskVolume4;
	//��������
	CPriceType AskPrice5;
	//��������
	CVolumeType AskVolume5;
	//�������
	CPriceType BidPrice6;
	//��������
	CVolumeType BidVolume6;
	//�������
	CPriceType BidPrice7;
	//��������
	CVolumeType BidVolume7;
	//����۰�
	CPriceType BidPrice8;
	//��������
	CVolumeType BidVolume8;
	//����۾�
	CPriceType BidPrice9;
	//��������
	CVolumeType BidVolume9;
	//�����ʮ
	CPriceType BidPrice10;
	//������ʮ
	CVolumeType BidVolume10;
	//��������
	CPriceType AskPrice6;
	//��������
	CVolumeType AskVolume6;
	//��������
	CPriceType AskPrice7;
	//��������
	CVolumeType AskVolume7;
	//�����۰�
	CPriceType AskPrice8;
	//��������
	CVolumeType AskVolume8;
	//�����۾�
	CPriceType AskPrice9;
	//��������
	CVolumeType AskVolume9;
	//������ʮ
	CPriceType AskPrice10;
	//������ʮ
	CVolumeType AskVolume10;
	//���
	CSequenceNoType SequenceNo;
	//�г�������
	CMarketNameType MarketName;
	//��Լ����
	CInstrumentIDType InstrumentID;
	//��Լ����״̬-1:δ֪0:����1:�޺���2:����3:����4:����5:����ǰ6:����ǰ7:����
	CContractStateType InstrumentStatus;
	//����޸�ʱ��
	CTimeType UpdateTime;
	//����޸ĺ���
	CMillisecType UpdateMillisec;

	TYPE_DESCRIPTOR((
		TYPE_DESC(TradingDay)
		,
		TYPE_DESC(PreClearPrice)
		,
		TYPE_DESC(PreClosePrice)
		,
		TYPE_DESC(PreOpenInterest)
		,
		TYPE_DESC(PreDelta)
		,
		TYPE_DESC(HistoryHigh)
		,
		TYPE_DESC(HistoryLow)
		,
		TYPE_DESC(OpenPrice)
		,
		TYPE_DESC(HighestPrice)
		,
		TYPE_DESC(LowestPrice)
		,
		TYPE_DESC(ClosePrice)
		,
		TYPE_DESC(UpperLimitPrice)
		,
		TYPE_DESC(LowerLimitPrice)
		,
		TYPE_DESC(ClearPrice)
		,
		TYPE_DESC(CurrDelta)
		,
		TYPE_DESC(Precision)
		,
		TYPE_DESC(LastPrice)
		,
		TYPE_DESC(Volume)
		,
		TYPE_DESC(Turnover)
		,
		TYPE_DESC(OpenInterest)
		,
		TYPE_DESC(NetChg)
		,
		TYPE_DESC(Markup)
		,
		TYPE_DESC(Swing)
		,
		TYPE_DESC(AvgPrice)
		,
		TYPE_DESC(BidPrice1)
		,
		TYPE_DESC(BidVolume1)
		,
		TYPE_DESC(AskPrice1)
		,
		TYPE_DESC(AskVolume1)
		,
		TYPE_DESC(BidPrice2)
		,
		TYPE_DESC(BidVolume2)
		,
		TYPE_DESC(BidPrice3)
		,
		TYPE_DESC(BidVolume3)
		,
		TYPE_DESC(AskPrice2)
		,
		TYPE_DESC(AskVolume2)
		,
		TYPE_DESC(AskPrice3)
		,
		TYPE_DESC(AskVolume3)
		,
		TYPE_DESC(BidPrice4)
		,
		TYPE_DESC(BidVolume4)
		,
		TYPE_DESC(BidPrice5)
		,
		TYPE_DESC(BidVolume5)
		,
		TYPE_DESC(AskPrice4)
		,
		TYPE_DESC(AskVolume4)
		,
		TYPE_DESC(AskPrice5)
		,
		TYPE_DESC(AskVolume5)
		,
		TYPE_DESC(BidPrice6)
		,
		TYPE_DESC(BidVolume6)
		,
		TYPE_DESC(BidPrice7)
		,
		TYPE_DESC(BidVolume7)
		,
		TYPE_DESC(BidPrice8)
		,
		TYPE_DESC(BidVolume8)
		,
		TYPE_DESC(BidPrice9)
		,
		TYPE_DESC(BidVolume9)
		,
		TYPE_DESC(BidPrice10)
		,
		TYPE_DESC(BidVolume10)
		,
		TYPE_DESC(AskPrice6)
		,
		TYPE_DESC(AskVolume6)
		,
		TYPE_DESC(AskPrice7)
		,
		TYPE_DESC(AskVolume7)
		,
		TYPE_DESC(AskPrice8)
		,
		TYPE_DESC(AskVolume8)
		,
		TYPE_DESC(AskPrice9)
		,
		TYPE_DESC(AskVolume9)
		,
		TYPE_DESC(AskPrice10)
		,
		TYPE_DESC(AskVolume10)
		,
		TYPE_DESC(SequenceNo)
		,
		TYPE_DESC(MarketName)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(InstrumentStatus)
		,
		TYPE_DESC(UpdateTime)
		,
		TYPE_DESC(UpdateMillisec)
	));
};

typedef  CExchDepthMarketHistoryData CWriteableExchDepthMarketHistoryData;
const int REC_ID_ExchDepthMarketHistoryData = 0x11;

/////////////////////////////////////////////////////////////////////////
//CWriteableExchInstrument��һ���洢[��Լ]�Ķ��󣬿���д����
/////////////////////////////////////////////////////////////////////////
class CExchInstrument
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
	void dumpDiff(FILE *fp, const CExchInstrument *pOriginal) const;

	//������д���ļ���һ����,����DEBUG
	//@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp = NULL) const;

	//������д��һ���ַ�����
	//@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

public:
	//���׽ӿ�����
	CAppTypeType AppType;
	//����������
	CExchangeIDType ExchangeID;
	//��Ʒ
	CCommodityIDType CommodityID;
	//��Ʒ����
	CCommodityTypeType CommodityType;
	//��Լ
	CInstrumentIDType InstrumentID;
	//��Լ����
	CInstrumentNameType InstrumentName;
	//��Լ����
	CContractTypeType InstrumentType;
	//��Լ״̬
	CContractStateType InstrumentState;
	//��Լ�ڽ������Ĵ��루CTP��������ʢ�У�ָ��RelateCommodityNo��������Լ��
	CInstrumentIDType ExchangeInstID;
	//��Լ��������״̬
	CInstLifePhaseType InstLifePhase;
	//��Ʒ����
	CCommodityNameType CommodityName;
	//��Ʒ����
	CCommodityAttributeType CommodityAttribute;
	//��Ʒ����Ȩ��
	CTradeRightType TradeRight;
	//ÿ�ֳ���
	CProductDotType MultipleValue;
	//��С�䶯��λ
	CPriceType PriceTick;
	//��С�䶯�۷���
	CUpperTickType UpperTick;
	//��С�䶯�۷�ĸ
	CLowerTickType LowerTick;
	//��Ʒʹ�ñ���
	CCurrencyIDType CurrencyID;
	//���۾���
	CPrecisionType Precision;
	//���ʽ
	CDeliveryModeType DeliveryMode;
	//������ƫ��
	CDeliveryDaysType DeliveryDays;
	//�������
	CYearType DeliveryYear;
	//������
	CMonthType DeliveryMonth;
	//�м۵�����µ���
	CVolumeType MaxMarketOrderVolume;
	//�м۵���С�µ���
	CVolumeType MinMarketOrderVolume;
	//�޼۵�����µ���
	CVolumeType MaxLimitOrderVolume;
	//�޼۵���С�µ���
	CVolumeType MinLimitOrderVolume;
	//��֤����㷽ʽ
	CDepositCalculateModeType DepositCalculateMode;
	//���ֲ���
	CVolumeType MaxHoldVol;
	//T+1ʱ��,���ڴ�ʱ��ΪT+1����
	CTimeType AddOneTime;
	//�����������(��һ��)
	CDirectType CmbDirect;
	//ƽ�ַ�ʽ
	CCoverModeType CoverMode;
	//������
	CDateType CreateDate;
	//������
	CDateType OpenDate;
	//������
	CDateType ExpiryDate;
	//��ʼ������
	CDateType StartDelivDate;
	//����������
	CDateType EndDelivDate;
	//�ֲ�����
	CPositionTypeType PositionType;
	//�ֲ���������
	CPositionDateTypeType PositionDateType;
	//��ͷ��֤����
	CRatioType LongMarginRatio;
	//��ͷ��֤����
	CRatioType ShortMarginRatio;
	//�Ƿ�ʹ�ô��߱�֤���㷨
	CMaxMarginSideAlgorithmType MaxMarginSideAlgorithm;

	TYPE_DESCRIPTOR((
		TYPE_DESC(AppType)
		,
		TYPE_DESC(ExchangeID)
		,
		TYPE_DESC(CommodityID)
		,
		TYPE_DESC(CommodityType)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(InstrumentName)
		,
		TYPE_DESC(InstrumentType)
		,
		TYPE_DESC(InstrumentState)
		,
		TYPE_DESC(ExchangeInstID)
		,
		TYPE_DESC(InstLifePhase)
		,
		TYPE_DESC(CommodityName)
		,
		TYPE_DESC(CommodityAttribute)
		,
		TYPE_DESC(TradeRight)
		,
		TYPE_DESC(MultipleValue)
		,
		TYPE_DESC(PriceTick)
		,
		TYPE_DESC(UpperTick)
		,
		TYPE_DESC(LowerTick)
		,
		TYPE_DESC(CurrencyID)
		,
		TYPE_DESC(Precision)
		,
		TYPE_DESC(DeliveryMode)
		,
		TYPE_DESC(DeliveryDays)
		,
		TYPE_DESC(DeliveryYear)
		,
		TYPE_DESC(DeliveryMonth)
		,
		TYPE_DESC(MaxMarketOrderVolume)
		,
		TYPE_DESC(MinMarketOrderVolume)
		,
		TYPE_DESC(MaxLimitOrderVolume)
		,
		TYPE_DESC(MinLimitOrderVolume)
		,
		TYPE_DESC(DepositCalculateMode)
		,
		TYPE_DESC(MaxHoldVol)
		,
		TYPE_DESC(AddOneTime)
		,
		TYPE_DESC(CmbDirect)
		,
		TYPE_DESC(CoverMode)
		,
		TYPE_DESC(CreateDate)
		,
		TYPE_DESC(OpenDate)
		,
		TYPE_DESC(ExpiryDate)
		,
		TYPE_DESC(StartDelivDate)
		,
		TYPE_DESC(EndDelivDate)
		,
		TYPE_DESC(PositionType)
		,
		TYPE_DESC(PositionDateType)
		,
		TYPE_DESC(LongMarginRatio)
		,
		TYPE_DESC(ShortMarginRatio)
		,
		TYPE_DESC(MaxMarginSideAlgorithm)
	));
};

typedef  CExchInstrument CWriteableExchInstrument;
const int REC_ID_ExchInstrument = 0x11;

/////////////////////////////////////////////////////////////////////////
//CWriteableExchInstrumentStatus��һ���洢[��Լ]�Ķ��󣬿���д����
/////////////////////////////////////////////////////////////////////////
class CExchInstrumentStatus
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
	void dumpDiff(FILE *fp, const CExchInstrumentStatus *pOriginal) const;

	//������д���ļ���һ����,����DEBUG
	//@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp = NULL) const;

	//������д��һ���ַ�����
	//@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

public:
	//����������
	CExchangeIDType ExchangeID;
	//��Լ�ڽ������Ĵ���
	CInstrumentIDType ExchangeInstID;
	//��Լ����
	CInstrumentIDType InstrumentID;
	//��Լ����״̬
	CInstrumentStatusType InstrumentStatus;
	//���׽׶α��
	CTradingSegmentSNType TradingSegmentSN;
	//���뱾״̬ʱ��
	CTimeType EnterTime;
	//���뱾״̬ԭ��
	CInstStatusEnterReasonType EnterReason;

	TYPE_DESCRIPTOR((
		TYPE_DESC(ExchangeID)
		,
		TYPE_DESC(ExchangeInstID)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(InstrumentStatus)
		,
		TYPE_DESC(TradingSegmentSN)
		,
		TYPE_DESC(EnterTime)
		,
		TYPE_DESC(EnterReason)
	));
};

typedef  CExchInstrumentStatus CWriteableExchInstrumentStatus;
const int REC_ID_ExchInstrumentStatus = 0x11;

/////////////////////////////////////////////////////////////////////////
//CWriteablePhyAccount��һ���洢[�����˺�]�Ķ��󣬿���д����
/////////////////////////////////////////////////////////////////////////
class CPhyAccount
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
	void dumpDiff(FILE *fp, const CPhyAccount *pOriginal) const;

	//������д���ļ���һ����,����DEBUG
	//@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp = NULL) const;

	//������д��һ���ַ�����
	//@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

public:
	//���͹�˾����
	CBrokerIDType BrokerID;
	//�û�����
	CUserIDType UserID;
	//����
	CPasswordType Password;
	//����ǰ�õ�ַ��
	CIPAddrListType TradeFrontAddr;
	//����Fens��ַ��
	CIPAddrListType TradeFrontNmSrv;
	//����ǰ�õ�ַ��
	CIPAddrListType MarketFrontAddr;
	//����Fens��ַ��
	CIPAddrListType MarketFrontNmSrv;
	//˽�����ش���ʽ
	CResumeTypeType PrivateResumeType;
	//�������ش���ʽ
	CResumeTypeType PublicResumeType;
	//������������
	CResumeTypeType MarketResumeType;
	//���������б�
	CTopicListType MarketTopic;

	TYPE_DESCRIPTOR((
		TYPE_DESC(BrokerID)
		,
		TYPE_DESC(UserID)
		,
		TYPE_DESC(Password)
		,
		TYPE_DESC(TradeFrontAddr)
		,
		TYPE_DESC(TradeFrontNmSrv)
		,
		TYPE_DESC(MarketFrontAddr)
		,
		TYPE_DESC(MarketFrontNmSrv)
		,
		TYPE_DESC(PrivateResumeType)
		,
		TYPE_DESC(PublicResumeType)
		,
		TYPE_DESC(MarketResumeType)
		,
		TYPE_DESC(MarketTopic)
	));
};

typedef  CPhyAccount CWriteablePhyAccount;
const int REC_ID_PhyAccount = 0x11;

/////////////////////////////////////////////////////////////////////////
//CWriteableInvestorPosition��һ���洢[�ֲ���Ϣ]�Ķ��󣬿���д����
/////////////////////////////////////////////////////////////////////////
class CInvestorPosition
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
	void dumpDiff(FILE *fp, const CInvestorPosition *pOriginal) const;

	//������д���ļ���һ����,����DEBUG
	//@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp = NULL) const;

	//������д��һ���ַ�����
	//@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

public:
	//Ͷ���߱��
	CInvestorIDType InvestorID;
	//���͹�˾����
	CBrokerIDType BrokerID;
	//����������
	CExchangeIDType ExchangeID;
	//�ͻ�����
	CClientIDType ClientID;
	//��Լ����
	CInstrumentIDType InstrumentID;
	//��������
	CDirectionType Direction;
	//Ͷ���ױ���־
	CHedgeFlagType HedgeFlag;
	//ռ�ñ�֤��
	CUsedMarginType UsedMargin;
	//��ֲ���
	CPositionType Position;
	//���ճֲֳɱ�
	CPositionCostType PositionCost;
	//��ֲ���
	CYdPositionType YdPosition;
	//���ճֲֳɱ�
	CYdPositionCostType YdPositionCost;
	//����ı�֤��
	CFrozenMarginType FrozenMargin;
	//���ֶ���ֲ�
	CFrozenPositionType FrozenPosition;
	//ƽ�ֶ���ֲ�
	CFrozenClosingType FrozenClosing;
	//�����Ȩ����
	CFrozenPremiumType FrozenPremium;
	//���һ�ʳɽ����
	CLastTradeIDType LastTradeID;
	//���һ�ʱ��ر������
	CLastOrderLocalIDType LastOrderLocalID;
	//����
	CCurrencyType Currency;
	//����������
	CMoneyType FrozenCommission;
	//������
	CMoneyType Commission;
	//����ӯ��
	CPriceType FloatProfit;
	//ƽ��ӯ��
	CPriceType CloseProfit;
	//ƽ������
	CVolumeType CloseVolume;
	//ƽ�ֽ��
	CMoneyType CloseAmount;
	//��ͷ����ı�֤��
	CLongFrozenMarginType LongFrozenMargin;
	//��ͷ����ı�֤��
	CShortFrozenMarginType ShortFrozenMargin;
	//��ͷռ�ñ�֤��
	CLongMarginType LongMargin;
	//��ͷռ�ñ�֤��
	CShortMarginType ShortMargin;
	//�����ͷű�֤��
	CReleaseMarginType ReleaseMargin;
	//�����ʽ�
	CAvailableType Available;
	//�����
	CDepositType Deposit;
	//������
	CWithdrawType Withdraw;
	//�ϴν���׼����
	CPreBalanceType PreBalance;
	//��̬Ȩ��
	CDynamicRightsType DynamicRights;
	//���ճ����
	CTodayInOutType TodayInOut;
	//��ȨȨ������֧
	CPremiumType Premium;
	//���ն�
	CRiskType Risk;

	TYPE_DESCRIPTOR((
		TYPE_DESC(InvestorID)
		,
		TYPE_DESC(BrokerID)
		,
		TYPE_DESC(ExchangeID)
		,
		TYPE_DESC(ClientID)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(Direction)
		,
		TYPE_DESC(HedgeFlag)
		,
		TYPE_DESC(UsedMargin)
		,
		TYPE_DESC(Position)
		,
		TYPE_DESC(PositionCost)
		,
		TYPE_DESC(YdPosition)
		,
		TYPE_DESC(YdPositionCost)
		,
		TYPE_DESC(FrozenMargin)
		,
		TYPE_DESC(FrozenPosition)
		,
		TYPE_DESC(FrozenClosing)
		,
		TYPE_DESC(FrozenPremium)
		,
		TYPE_DESC(LastTradeID)
		,
		TYPE_DESC(LastOrderLocalID)
		,
		TYPE_DESC(Currency)
		,
		TYPE_DESC(FrozenCommission)
		,
		TYPE_DESC(Commission)
		,
		TYPE_DESC(FloatProfit)
		,
		TYPE_DESC(CloseProfit)
		,
		TYPE_DESC(CloseVolume)
		,
		TYPE_DESC(CloseAmount)
		,
		TYPE_DESC(LongFrozenMargin)
		,
		TYPE_DESC(ShortFrozenMargin)
		,
		TYPE_DESC(LongMargin)
		,
		TYPE_DESC(ShortMargin)
		,
		TYPE_DESC(ReleaseMargin)
		,
		TYPE_DESC(Available)
		,
		TYPE_DESC(Deposit)
		,
		TYPE_DESC(Withdraw)
		,
		TYPE_DESC(PreBalance)
		,
		TYPE_DESC(DynamicRights)
		,
		TYPE_DESC(TodayInOut)
		,
		TYPE_DESC(Premium)
		,
		TYPE_DESC(Risk)
	));
};

typedef  CInvestorPosition CWriteableInvestorPosition;
const int REC_ID_InvestorPosition = 0x11;

/////////////////////////////////////////////////////////////////////////
//CWriteableRuleInfo��һ���洢[������Ϣ]�Ķ��󣬿���д����
/////////////////////////////////////////////////////////////////////////
class CRuleInfo
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
	void dumpDiff(FILE *fp, const CRuleInfo *pOriginal) const;

	//������д���ļ���һ����,����DEBUG
	//@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp = NULL) const;

	//������д��һ���ַ�����
	//@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

public:
	//���Դ���
	CRuleIDType RuleID;
	//����Dll�洢λ��
	CRulePathType RulePath;
	//���Եİ汾
	CRuleVersionType RuleVersion;
	//��������
	CRuleNameType RuleName;
	//���������ļ��洢λ��
	CRulePathType ConfigPath;

	TYPE_DESCRIPTOR((
		TYPE_DESC(RuleID)
		,
		TYPE_DESC(RulePath)
		,
		TYPE_DESC(RuleVersion)
		,
		TYPE_DESC(RuleName)
		,
		TYPE_DESC(ConfigPath)
	));
};

typedef  CRuleInfo CWriteableRuleInfo;
const int REC_ID_RuleInfo = 0x11;

/////////////////////////////////////////////////////////////////////////
//CWriteableExchInvestorFee��һ���洢[Ͷ������������]�Ķ��󣬿���д����
/////////////////////////////////////////////////////////////////////////
class CExchInvestorFee
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
	void dumpDiff(FILE *fp, const CExchInvestorFee *pOriginal) const;

	//������д���ļ���һ����,����DEBUG
	//@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp = NULL) const;

	//������д��һ���ַ�����
	//@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

public:
	//���͹�˾����
	CBrokerIDType BrokerID;
	//�ͻ�����
	CClientIDType ClientID;
	//����������
	CExchangeIDType ExchangeID;
	//��Լ����
	CInstrumentIDType InstrumentID;
	//Ʒ�ִ���
	CProductIDType ProductID;
	//���������Ѱ�����
	COpenFeeRateType OpenFeeRate;
	//���������Ѱ�����
	COpenFeeAmtType OpenFeeAmt;
	//ƽ�������Ѱ�����
	COffsetFeeRateType OffsetFeeRate;
	//ƽ�������Ѱ�����
	COffsetFeeAmtType OffsetFeeAmt;
	//ƽ��������Ѱ�����
	COTFeeRateType OTFeeRate;
	//ƽ��������Ѱ�����
	COTFeeAmtType OTFeeAmt;

	TYPE_DESCRIPTOR((
		TYPE_DESC(BrokerID)
		,
		TYPE_DESC(ClientID)
		,
		TYPE_DESC(ExchangeID)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(ProductID)
		,
		TYPE_DESC(OpenFeeRate)
		,
		TYPE_DESC(OpenFeeAmt)
		,
		TYPE_DESC(OffsetFeeRate)
		,
		TYPE_DESC(OffsetFeeAmt)
		,
		TYPE_DESC(OTFeeRate)
		,
		TYPE_DESC(OTFeeAmt)
	));
};

typedef  CExchInvestorFee CWriteableExchInvestorFee;
const int REC_ID_ExchInvestorFee = 0x11;

/////////////////////////////////////////////////////////////////////////
//CWriteableExchInvestorMargin��һ���洢[���ױ�֤����]�Ķ��󣬿���д����
/////////////////////////////////////////////////////////////////////////
class CExchInvestorMargin
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
	void dumpDiff(FILE *fp, const CExchInvestorMargin *pOriginal) const;

	//������д���ļ���һ����,����DEBUG
	//@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp = NULL) const;

	//������д��һ���ַ�����
	//@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

public:
	//���͹�˾����
	CBrokerIDType BrokerID;
	//�ͻ�����
	CClientIDType ClientID;
	//����������
	CExchangeIDType ExchangeID;
	//��Լ����
	CInstrumentIDType InstrumentID;
	//Ʒ�ִ���
	CProductIDType ProductID;
	//��ͷռ�ñ�֤�𰴱���
	CLongMarginRateType LongMarginRate;
	//��ͷ��֤������
	CLongMarginAmtType LongMarginAmt;
	//��ͷռ�ñ�֤�𰴱���
	CShortMarginRateType ShortMarginRate;
	//��ͷ��֤������
	CShortMarginAmtType ShortMarginAmt;

	TYPE_DESCRIPTOR((
		TYPE_DESC(BrokerID)
		,
		TYPE_DESC(ClientID)
		,
		TYPE_DESC(ExchangeID)
		,
		TYPE_DESC(InstrumentID)
		,
		TYPE_DESC(ProductID)
		,
		TYPE_DESC(LongMarginRate)
		,
		TYPE_DESC(LongMarginAmt)
		,
		TYPE_DESC(ShortMarginRate)
		,
		TYPE_DESC(ShortMarginAmt)
	));
};

typedef  CExchInvestorMargin CWriteableExchInvestorMargin;
const int REC_ID_ExchInvestorMargin = 0x11;







#endif