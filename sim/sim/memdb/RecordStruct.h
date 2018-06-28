#ifndef __RECORD_STRUCT_H__
#define __RECORD_STRUCT_H__

#include "../network/field_describe.h"
#include "../customDataType/customDataType.h"

/////////////////////////////////////////////////////////////////////////
//CWriteableCurrentTime是一个存储[当前时间]的对象，可以写出。
/////////////////////////////////////////////////////////////////////////
class CCurrentTime
{
public:
	//初始化操作，将所有的字段清空
	void init();

	//从文件读入
	//@param	input	读入的文件
	//@return	1表示读入成功，0表示读入失败
	int read(FILE* input);

	//向文件写出
	//@param	output 写出的文件
	//@return	1表时写出成功，0表示写出失败
	int write(FILE* output) const;

	//将内容写到文件中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp = NULL, int index = -1) const;

	//将内容写入文件，突出显示变化的内容
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CCurrentTime *pOriginal) const;

	//将内容写到文件的一行中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp = NULL) const;

	//将内容写到一个字符串中
	//@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

public:
	//当前日期
	CDateType CurrDate;
	//当前时间
	CTimeType CurrTime;
	//当前时间（毫秒）
	CMillisecType CurrMillisec;
	//业务时期
	CDateType ActionDay;
	//原来时间
	CTimeType OldTime;
	//原来时间（毫秒）
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
//CWriteableTerminal是一个存储[终端机]的对象，可以写出。
/////////////////////////////////////////////////////////////////////////
class CTerminal
{
public:
	//初始化操作，将所有的字段清空
	void init(void);

	//从文件读入
	//@param	input	读入的文件
	//@return	1表示读入成功，0表示读入失败
	int read(FILE *input);

	//向文件写出
	//@param	output 写出的文件
	//@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;

	//将内容写到文件中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp = NULL, int index = -1) const;

	//将内容写入文件，突出显示变化的内容
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CTerminal *pOriginal) const;

	//将内容写到文件的一行中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp = NULL) const;

	//将内容写到一个字符串中
	//@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

public:
	//交易日
	CDateType TradingDay;
	//终端机编号
	CTerminalIDType TerminalID;
	//终端机类型
	CTerminalTypeType TerminalType;
	//交易接口类型
	CAppTypeType AppType;
	//终端机当前登录Session
	CSessionIDType SessionID;
	//终端机启动时间
	CTimeType StartTime;
	//终端机更新时间
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
//CWriteableFront是一个存储[前置机]的对象，可以写出。
/////////////////////////////////////////////////////////////////////////
class CFront
{
public:
	///初始化操作，将所有的字段清空
	void init(void);

	//从文件读入
	//@param	input	读入的文件
	//@return	1表示读入成功，0表示读入失败
	int read(FILE *input);

	//向文件写出
	//@param	output 写出的文件
	//@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;

	//将内容写到文件中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp = NULL, int index = -1) const;

	//将内容写入文件，突出显示变化的内容
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CFront *pOriginal) const;

	//将内容写到文件的一行中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp = NULL) const;

	//将内容写到一个字符串中
	//@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;
public:
	//交易日
	CDateType TradingDay;
	//前置编号
	CFrontIDType FrontID;
	//前置Session编号
	CSessionIDType SessionID;
	//前置机启动时间
	CTimeType StartTime;
	//前置机更新时间
	CTimeType UpdateTime;
	//前置运行状态
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
//CWriteableTrader是一个存储[交易员]的对象，可以写出。
/////////////////////////////////////////////////////////////////////////
class CTrader
{
public:
	//初始化操作，将所有的字段清空
	void init(void);

	//从文件读入
	//@param	input	读入的文件
	//@return	1表示读入成功，0表示读入失败
	int read(FILE *input);

	//向文件写出
	//@param	output 写出的文件
	//@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;

	//将内容写到文件中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp = NULL, int index = -1) const;

	//将内容写入文件，突出显示变化的内容
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CTrader *pOriginal) const;

	//将内容写到文件的一行中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp = NULL) const;

	//将内容写到一个字符串中
	//@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

public:
	//交易员代码
	CTraderIDType TraderID;
	//交易接口类型
	CAppTypeType AppType;
	//交易员登录身份
	CTerminalTypeType TerminalType;
	//交易日
	CDateType TradingDay;
	//交易员最大并行数量
	CCounterType MaxParalle;
	//交易接口IP地址
	CIPAddressType ServerIP;
	//会员代码
	CParticipantIDType ParticipantID;
	//经纪会员代码
	CBrokerIDType BrokerID;
	//操作员号
	COperatorIDType OperatorID;
	//用户端产品信息
	CProductInfoType UserProductInfo;
	//接口端产品信息
	CProductInfoType InterfaceProductInfo;
	//协议信息
	CProtocolInfoType ProtocolInfo;
	//Mac地址
	CMacAddressType MacAddress;
	//终端IP地址
	CIPAddressType ClientIPAddress;
	//密码
	CPasswordType Password;
	//是否CA认证
	CIsCaLoginType IsCaLogin;
	//登录身份类型,目前只支持单客户
	CLoginIdentityType Identity;
	//是否强制修改密码
	CIsForcePasswordType IsForcePwd;
	//动态密码
	CPasswordType OneTimePassword;
	//otp认证密码
	COtpPassType OtpPass;
	//CA信息长度，IsCaLogin为'Y'时，本字段有效
	CSizeType CaLen;
	//CA登录时填写,IsCaLogin为'Y'时，本字段有效
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
//CWriteableTraderParalle是一个存储[交易员并行资源]的对象，可以写出。
/////////////////////////////////////////////////////////////////////////
class CTraderParalle
{
public:
	//初始化操作，将所有的字段清空
	void init(void);

	//从文件读入
	//@param	input	读入的文件
	//@return	1表示读入成功，0表示读入失败
	int read(FILE *input);

	//向文件写出
	//@param	output 写出的文件
	//@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;

	//将内容写到文件中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp = NULL, int index = -1) const;

	//将内容写入文件，突出显示变化的内容
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CTraderParalle *pOriginal) const;

	//将内容写到文件的一行中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp = NULL) const;

	//将内容写到一个字符串中
	//@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

public:
	//交易员代码
	CTraderIDType TraderID;
	//交易接口类型
	CAppTypeType AppType;
	//交易员登录身份
	CTerminalTypeType TerminalType;
	//交易员并行数量
	CCounterType Paralled;
	//物理帐号最大并行登录数量
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
//CWriteableTraderLoginLog是一个存储[交易员登录记录]的对象，可以写出。
/////////////////////////////////////////////////////////////////////////
class CTraderLoginLog
{
public:
	//初始化操作，将所有的字段清空
	void init(void);

	//从文件读入
	//@param	input	读入的文件
	//@return	1表示读入成功，0表示读入失败
	int read(FILE *input);

	//向文件写出
	//@param	output 写出的文件
	//@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;

	//将内容写到文件中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp = NULL, int index = -1) const;

	//将内容写入文件，突出显示变化的内容
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CTraderLoginLog *pOriginal) const;

	//将内容写到文件的一行中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp = NULL) const;

	//将内容写到一个字符串中
	//@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

public:
	//用户代码（CTP返回的UserID，易盛返回的是LoginNo）
	CTraderIDType TraderID;
	//交易接口类型
	CAppTypeType AppType;
	//终端机编号
	CTerminalIDType TerminalID;
	//终端机类型
	CTerminalTypeType TerminalType;
	//终端机当前登录Session
	CSessionIDType SessionID;
	//交易员运行时状态
	CTraderRuntypeType TraderRuntype;
	//交易日（CTP返回）
	CDateType TradingDay;
	//交易员当前连接是否活跃
	CBoolType IsActive;
	//实体账户状态更新时间
	CTimeType UpdateTime;
	//登录成功时间（CTP返回）
	CTimeType ExchLoginTime;
	//经纪公司代码（CTP返回）
	CBrokerIDType ExchBrokerID;
	//交易系统名称（CTP返回）
	CSystemNameType ExchSystemName;
	//前置编号（CTP返回）
	CFrontIDType ExchFrontID;
	//会话编号（CTP返回）
	CSessionIDType ExchSessionID;
	//最大报单引用（CTP返回）
	COrderRefType ExchMaxOrderRef;
	//是否CA认证（易盛返回）
	CIsCaLoginType ExchIsCaLogin;
	//是否强制修改密码（易盛返回）
	CIsForcePasswordType ExchIsForcePwd;
	//登录端帐号简称（易盛返回）
	CLoginNameType ExchLoginName;
	//客户预留信息,客户自己识别后台系统（易盛返回）
	CReservedInfoType ExchReservedInfo;
	//上次登录时间（易盛返回）
	CDateTimeType ExchLastLoginDateTime;
	//上次登出时间（易盛返回）
	CDateTimeType ExchLastLogoutDateTime;
	//上次登录ip，兼容ipv6（易盛返回）
	CIpType ExchLastLoginIp;
	//上次登录port（易盛返回）
	CPortType ExchLastLoginPort;
	//上次登录机器信息，主要是Mac地址（易盛返回）
	CMachineInfoType ExchLastLoginMachineInfo;
	//上期所时间（CTP返回）
	CTimeType ExchSHFETime;
	//大商所时间（CTP返回）
	CTimeType ExchDCETime;
	//郑商所时间（CTP返回）
	CTimeType ExchCZCETime;
	//中金所时间（CTP返回）
	CTimeType ExchFFEXTime;
	//系统当前时间(客户端校时，易盛返回）
	CDateTimeType ExchServerDateTime;
	//错误代码
	CErrorIDType ErrorID;
	//错误信息
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
//CWriteableTraderConnect是一个存储[交易员连接状态]的对象，可以写出。
/////////////////////////////////////////////////////////////////////////
class CTraderConnect
{
public:
	//初始化操作，将所有的字段清空
	void init(void);

	//从文件读入
	//@param	input	读入的文件
	//@return	1表示读入成功，0表示读入失败
	int read(FILE *input);

	//向文件写出
	//@param	output 写出的文件
	//@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;

	//将内容写到文件中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp = NULL, int index = -1) const;

	//将内容写入文件，突出显示变化的内容
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CTraderConnect *pOriginal) const;

	//将内容写到文件的一行中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp = NULL) const;

	//将内容写到一个字符串中
	//@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

public:
	//用户代码（CTP返回的UserID，易盛返回的是LoginNo）
	CTraderIDType TraderID;
	//交易接口类型
	CAppTypeType AppType;
	//终端机编号
	CTerminalIDType TerminalID;
	//终端机类型
	CTerminalTypeType TerminalType;
	//终端机当前登录Session
	CSessionIDType SessionID;
	//交易员运行时状态
	CTraderRuntypeType TraderRuntype;
	//交易日（CTP返回）
	CDateType TradingDay;
	//交易员当前连接是否活跃
	CBoolType IsActive;
	//实体账户状态更新时间
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
//CWriteableTraderCertInfo是一个存储[交易员连接]的对象，可以写出。
/////////////////////////////////////////////////////////////////////////
class CTraderCertInfo
{
public:
	//初始化操作，将所有的字段清空
	void init(void);

	//从文件读入
	//@param	input	读入的文件
	//@return	1表示读入成功，0表示读入失败
	int read(FILE *input);

	//向文件写出
	//@param	output 写出的文件
	//@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;

	//将内容写到文件中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp = NULL, int index = -1) const;

	//将内容写入文件，突出显示变化的内容
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CTraderCertInfo *pOriginal) const;

	//将内容写到文件的一行中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp = NULL) const;

	//将内容写到一个字符串中
	//@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

public:
	//交易员代码
	CTraderIDType TraderID;
	//交易接口类型
	CAppTypeType AppType;
	//交易员登录身份
	CTerminalTypeType TerminalType;
	//认证信息
	CCertInfoType CertInfo;
	//API密钥
	CSecretKeyType SecretKey;
	//是否订阅期权
	CBoolType IsOption;
	//客户端产品信息
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
//CWriteableUser是一个存储[用户]的对象，可以写出。
/////////////////////////////////////////////////////////////////////////
class CUser
{
public:
	//初始化操作，将所有的字段清空
	void init(void);

	//从文件读入
	//@param	input	读入的文件
	//@return	1表示读入成功，0表示读入失败
	int read(FILE *input);

	//向文件写出
	//@param	output 写出的文件
	//@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;

	//将内容写到文件中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp = NULL, int index = -1) const;

	//将内容写入文件，突出显示变化的内容
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CUser *pOriginal) const;

	//将内容写到文件的一行中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp = NULL) const;

	//将内容写到一个字符串中
	//@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

public:
	//用户代码
	CUserIDType UserID;
	//用户所在组代码
	CUserGroupIDType UserGroupID;
	//用户名称
	CIndividualNameType UserName;
	//用户类型
	CUserTypeType UserType;
	//密码
	CPasswordType Password;
	//用户状态
	CUserStatusType UserStatus;
	//交易员权限
	CTradeRightType TradeRight;
	//是否活跃
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
//CWriteableUserTrader是一个存储[用户交易员关系表]的对象，可以写出。
/////////////////////////////////////////////////////////////////////////
class CUserTrader
{
public:
	//初始化操作，将所有的字段清空
	void init(void);

	//从文件读入
	//@param	input	读入的文件
	//@return	1表示读入成功，0表示读入失败
	int read(FILE *input);

	//向文件写出
	//@param	output 写出的文件
	//@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;

	//将内容写到文件中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp = NULL, int index = -1) const;

	//将内容写入文件，突出显示变化的内容
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CUserTrader *pOriginal) const;

	//将内容写到文件的一行中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp = NULL) const;

	//将内容写到一个字符串中
	//@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

public:
	//用户代码
	CUserIDType UserID;
	//实体账户代码
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
//CWriteableUserFunctionRight是一个存储[用户权限]的对象，可以写出。
/////////////////////////////////////////////////////////////////////////
class CUserFunctionRight
{
public:
	//初始化操作，将所有的字段清空
	void init(void);

	//从文件读入
	//@param	input	读入的文件
	//@return	1表示读入成功，0表示读入失败
	int read(FILE *input);

	//向文件写出
	//@param	output 写出的文件
	//@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;

	//将内容写到文件中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp = NULL, int index = -1) const;

	//将内容写入文件，突出显示变化的内容
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CUserFunctionRight *pOriginal) const;

	//将内容写到文件的一行中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp = NULL) const;

	//将内容写到一个字符串中
	//@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

public:
	//用户代码
	CUserIDType UserID;
	//功能代码
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
//CWriteableSysInfo是一个存储[系统信息]的对象，可以写出。
/////////////////////////////////////////////////////////////////////////
class CSysInfo
{
public:
	//初始化操作，将所有的字段清空
	void init(void);

	//从文件读入
	//@param	input	读入的文件
	//@return	1表示读入成功，0表示读入失败
	int read(FILE *input);

	//向文件写出
	//@param	output 写出的文件
	//@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;

	//将内容写到文件中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp = nullptr, int index = -1) const;

	//将内容写入文件，突出显示变化的内容
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CSysInfo *pOriginal) const;

	//将内容写到文件的一行中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp = nullptr) const;

	//将内容写到一个字符串中
	//@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

public:
	//认证信息
	CCertInfoType CertInfo;
	//应用程序ID
	CAppIDType AppID;
	//日志位置
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
//CWriteableUserSession是一个存储[交易员在线会话]的对象，可以写出。
/////////////////////////////////////////////////////////////////////////
class CUserSession
{
public:
	//初始化操作，将所有的字段清空
	void init(void);

	//从文件读入
	//@param	input	读入的文件
	//@return	1表示读入成功，0表示读入失败
	int read(FILE *input);

	//向文件写出
	//@param	output 写出的文件
	//@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;

	//将内容写到文件中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp = nullptr, int index = -1) const;

	//将内容写入文件，突出显示变化的内容
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CUserSession *pOriginal) const;

	//将内容写到文件的一行中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp = nullptr) const;

	//将内容写到一个字符串中
	//@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

public:
	//前置编号
	CFrontIDType FrontID;
	//用户代码
	CUserIDType UserID;
	//交易用户类型
	CUserTypeType UserType;
	//会话编号
	CSessionIDType SessionID;
	//系统交易日
	CDateType TradingDay;
	//登录时间
	CTimeType LoginTime;
	//IP地址
	CIPAddressType IPAddress;
	//用户端产品信息
	CFunctionKeyType UserProductInfo;
	//接口端产品信息
	CFunctionKeyType InterfaceProductInfo;
	//协议信息
	CFunctionKeyType ProtocolInfo;
	//系统名称
	CSystemNameType SystemName;
	//最大报单引用
	COrderRefType MaxOrderRef;
	//上期所时间
	CTimeType SHFETime;
	//大商所时间
	CTimeType DCETime;
	//郑商所时间
	CTimeType CZCETime;
	//中金所时间
	CTimeType FFEXTime;
	//Mac地址
	CMacAddressType MacAddress;
	//动态密码
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
//CWriteableMDSession是一个存储[行情订阅者在线会话]的对象，可以写出。
/////////////////////////////////////////////////////////////////////////
class CMDSession
{
public:
	//初始化操作，将所有的字段清空
	void init(void);

	//从文件读入
	//@param	input	读入的文件
	//@return	1表示读入成功，0表示读入失败
	int read(FILE *input);

	//向文件写出
	//@param	output 写出的文件
	//@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;

	//将内容写到文件中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp = NULL, int index = -1) const;

	//将内容写入文件，突出显示变化的内容
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CMDSession *pOriginal) const;

	//将内容写到文件的一行中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp = NULL) const;

	//将内容写到一个字符串中
	//@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

public:
	//前置编号
	CFrontIDType FrontID;
	//用户代码
	CUserIDType UserID;
	//交易用户类型
	CUserTypeType UserType;
	//会话编号
	CSessionIDType SessionID;
	//系统交易日
	CDateType TradingDay;
	//登录时间
	CTimeType LoginTime;
	//IP地址
	CIPAddressType IPAddress;
	//用户端产品信息
	CFunctionKeyType UserProductInfo;
	//接口端产品信息
	CFunctionKeyType InterfaceProductInfo;
	//协议信息
	CFunctionKeyType ProtocolInfo;
	//系统名称
	CSystemNameType SystemName;
	//最大报单引用
	COrderRefType MaxOrderRef;
	//上期所时间
	CTimeType SHFETime;
	//大商所时间
	CTimeType DCETime;
	//郑商所时间
	CTimeType CZCETime;
	//中金所时间
	CTimeType FFEXTime;
	//Mac地址
	CMacAddressType MacAddress;
	//动态密码
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
//CWriteableMaxLocalID是一个存储[最大本地报单号]的对象，可以写出。
/////////////////////////////////////////////////////////////////////////
class CMaxLocalID
{
public:
	//初始化操作，将所有的字段清空
	void init(void);

	//从文件读入
	//@param	input	读入的文件
	//@return	1表示读入成功，0表示读入失败
	int read(FILE *input);

	//向文件写出
	//@param	output 写出的文件
	//@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;

	//将内容写到文件中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp = NULL, int index = -1) const;

	//将内容写入文件，突出显示变化的内容
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CMaxLocalID *pOriginal) const;

	//将内容写到文件的一行中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp = NULL) const;

	//将内容写到一个字符串中
	//@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

public:
	//交易用户代码
	CUserIDType UserID;
	//最大报单本地编号
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
//CWriteableUserSubMarketData是一个存储[行情订阅]的对象，可以写出。
/////////////////////////////////////////////////////////////////////////
class CUserSubMarketData
{
public:
	//初始化操作，将所有的字段清空
	void init(void);

	//从文件读入
	//@param	input	读入的文件
	//@return	1表示读入成功，0表示读入失败
	int read(FILE *input);

	//向文件写出
	//@param	output 写出的文件
	//@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;

	//将内容写到文件中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp = NULL, int index = -1) const;

	//将内容写入文件，突出显示变化的内容
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CUserSubMarketData *pOriginal) const;

	//将内容写到文件的一行中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp = NULL) const;

	//将内容写到一个字符串中
	//@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

public:
	//用户代码
	CUserIDType UserID;
	//前置编号
	CFrontIDType FrontID;
	//会话编号
	CSessionIDType SessionID;
	//合约代码
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
//CWriteableDepthMarketData是一个存储[深度行情]的对象，可以写出。
/////////////////////////////////////////////////////////////////////////
class CDepthMarketData
{
public:
	//初始化操作，将所有的字段清空
	void init(void);

	//从文件读入
	//@param	input	读入的文件
	//@return	1表示读入成功，0表示读入失败
	int read(FILE *input);

	//向文件写出
	//@param	output 写出的文件
	//@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;

	//将内容写到文件中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp = NULL, int index = -1) const;

	//将内容写入文件，突出显示变化的内容
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CDepthMarketData *pOriginal) const;

	//将内容写到文件的一行中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp = NULL) const;

	//将内容写到一个字符串中
	//@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

public:
	//交易日
	CDateType TradingDay;
	//昨结算
	CPriceType PreClearPrice;
	//昨收盘
	CPriceType PreClosePrice;
	//昨持仓量
	CLargeVolumeType PreOpenInterest;
	//昨虚实度
	CRatioType PreDelta;
	//合约最高
	CPriceType HistoryHigh;
	//合约最低
	CPriceType HistoryLow;
	//今开盘
	CPriceType OpenPrice;
	//最高价
	CPriceType HighestPrice;
	//最低价
	CPriceType LowestPrice;
	//今收盘
	CPriceType ClosePrice;
	//涨停板价
	CPriceType UpperLimitPrice;
	//跌停板价
	CPriceType LowerLimitPrice;
	//本次结算价
	CPriceType ClearPrice;
	//今虚实度
	CRatioType CurrDelta;
	//报价精度
	CPrecisionType Precision;
	//最新价
	CPriceType LastPrice;
	//数量
	CVolumeType Volume;
	//成交金额
	CMoneyType Turnover;
	//持仓量
	CLargeVolumeType OpenInterest;
	//涨跌
	CPriceType NetChg;
	//涨跌幅
	CPriceType Markup;
	//振幅
	CRatioType Swing;
	//平均价
	CPriceType AvgPrice;
	//申买价一
	CPriceType BidPrice1;
	//申买量一
	CVolumeType BidVolume1;
	//申卖价一
	CPriceType AskPrice1;
	//申卖量一
	CVolumeType AskVolume1;
	//申买价二
	CPriceType BidPrice2;
	//申买量二
	CVolumeType BidVolume2;
	//申买价三
	CPriceType BidPrice3;
	//申买量三
	CVolumeType BidVolume3;
	//申卖价二
	CPriceType AskPrice2;
	//申卖量二
	CVolumeType AskVolume2;
	//申卖价三
	CPriceType AskPrice3;
	//申卖量三
	CVolumeType AskVolume3;
	//申买价四
	CPriceType BidPrice4;
	//申买量四
	CVolumeType BidVolume4;
	//申买价五
	CPriceType BidPrice5;
	//申买量五
	CVolumeType BidVolume5;
	//申卖价四
	CPriceType AskPrice4;
	//申卖量四
	CVolumeType AskVolume4;
	//申卖价五
	CPriceType AskPrice5;
	//申卖量五
	CVolumeType AskVolume5;
	//申买价六
	CPriceType BidPrice6;
	//申买量六
	CVolumeType BidVolume6;
	//申买价七
	CPriceType BidPrice7;
	//申买量七
	CVolumeType BidVolume7;
	//申买价八
	CPriceType BidPrice8;
	//申买量八
	CVolumeType BidVolume8;
	//申买价九
	CPriceType BidPrice9;
	//申买量九
	CVolumeType BidVolume9;
	//申买价十
	CPriceType BidPrice10;
	//申买量十
	CVolumeType BidVolume10;
	//申卖价六
	CPriceType AskPrice6;
	//申卖量六
	CVolumeType AskVolume6;
	//申卖价七
	CPriceType AskPrice7;
	//申卖量七
	CVolumeType AskVolume7;
	//申卖价八
	CPriceType AskPrice8;
	//申卖量八
	CVolumeType AskVolume8;
	//申卖价九
	CPriceType AskPrice9;
	//申卖量九
	CVolumeType AskVolume9;
	//申卖价十
	CPriceType AskPrice10;
	//申卖量十
	CVolumeType AskVolume10;
	//序号
	CSequenceNoType SequenceNo;
	//市场中文名
	CMarketNameType MarketName;
	//合约代码
	CInstrumentIDType InstrumentID;
	//合约交易状态-1:未知0:开市1:无红利2:竞价3:挂起4:闭市5:开市前6:闭市前7:快市
	CContractStateType InstrumentStatus;
	//最后修改时间
	CTimeType UpdateTime;
	//最后修改毫秒
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
//CWriteableCommodity是一个存储[商品]的对象，可以写出。
/////////////////////////////////////////////////////////////////////////
class CCommodity
{
public:
	//初始化操作，将所有的字段清空
	void init(void);

	//从文件读入
	//@param	input	读入的文件
	//@return	1表示读入成功，0表示读入失败
	int read(FILE *input);

	//向文件写出
	//@param	output 写出的文件
	//@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;

	//将内容写到文件中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp = NULL, int index = -1) const;

	//将内容写入文件，突出显示变化的内容
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CCommodity *pOriginal) const;

	//将内容写到文件的一行中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp = NULL) const;

	//将内容写到一个字符串中
	//@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

public:
	//交易接口类型
	CAppTypeType AppType;
	//交易所代码
	CExchangeIDType ExchangeID;
	//商品
	CCommodityIDType CommodityID;
	//商品类型
	CCommodityTypeType CommodityType;
	//合约在交易所的代码（CTP），在易盛中，指代RelateCommodityNo（依赖合约）
	CInstrumentIDType ExchangeInstID;
	//商品名称
	CCommodityNameType CommodityName;
	//商品属性
	CCommodityAttributeType CommodityAttribute;
	//商品状态
	CCommodityStateType CommodityState;
	//每手乘数
	CProductDotType MultipleValue;
	//最小变动价分子
	CUpperTickType UpperTick;
	//最小变动价分母
	CLowerTickType LowerTick;
	//报价精度
	CPrecisionType Precision;
	//商品使用币种
	CCurrencyIDType CurrencyID;
	//交割方式
	CDeliveryModeType DeliveryMode;
	//交割日偏移
	CDeliveryDaysType DeliveryDays;
	//交割年份
	CYearType DeliveryYear;
	//交割月
	CMonthType DeliveryMonth;
	//市价单最大下单量
	CVolumeType MaxMarketOrderVolume;
	//市价单最小下单量
	CVolumeType MinMarketOrderVolume;
	//限价单最大下单量
	CVolumeType MaxLimitOrderVolume;
	//限价单最小下单量
	CVolumeType MinLimitOrderVolume;
	//保证金计算方式
	CDepositCalculateModeType DepositCalculateMode;
	//最大持仓量
	CVolumeType MaxHoldVol;
	//T+1时间,大于此时间为T+1数据
	CTimeType AddOneTime;
	//组合买卖方向(第一腿)
	CDirectType CmbDirect;
	//平仓方式
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
//CWriteableInstrument是一个存储[合约]的对象，可以写出。
/////////////////////////////////////////////////////////////////////////
class CInstrument
{
public:
	//初始化操作，将所有的字段清空
	void init(void);

	//从文件读入
	//@param	input	读入的文件
	//@return	1表示读入成功，0表示读入失败
	int read(FILE *input);

	//向文件写出
	//@param	output 写出的文件
	//@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;

	//将内容写到文件中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp = NULL, int index = -1) const;

	//将内容写入文件，突出显示变化的内容
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CInstrument *pOriginal) const;

	//将内容写到文件的一行中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp = NULL) const;

	//将内容写到一个字符串中
	//@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

public:
	//交易接口类型
	CAppTypeType AppType;
	//交易所代码
	CExchangeIDType ExchangeID;
	//商品
	CCommodityIDType CommodityID;
	//商品类型
	CCommodityTypeType CommodityType;
	//合约
	CInstrumentIDType InstrumentID;
	//合约名称
	CInstrumentNameType InstrumentName;
	//合约类型
	CContractTypeType InstrumentType;
	//合约状态
	CContractStateType InstrumentState;
	//合约在交易所的代码（CTP），在易盛中，指代RelateCommodityNo（依赖合约）
	CInstrumentIDType ExchangeInstID;
	//合约生命周期状态
	CInstLifePhaseType InstLifePhase;
	//商品名称
	CCommodityNameType CommodityName;
	//商品属性
	CCommodityAttributeType CommodityAttribute;
	//商品交易权限
	CTradeRightType TradeRight;
	//每手乘数
	CProductDotType MultipleValue;
	//最小变动价位
	CPriceType PriceTick;
	//最小变动价分子
	CUpperTickType UpperTick;
	//最小变动价分母
	CLowerTickType LowerTick;
	//商品使用币种
	CCurrencyIDType CurrencyID;
	//报价精度
	CPrecisionType Precision;
	//交割方式
	CDeliveryModeType DeliveryMode;
	//交割日偏移
	CDeliveryDaysType DeliveryDays;
	//交割年份
	CYearType DeliveryYear;
	//交割月
	CMonthType DeliveryMonth;
	//市价单最大下单量
	CVolumeType MaxMarketOrderVolume;
	//市价单最小下单量
	CVolumeType MinMarketOrderVolume;
	//限价单最大下单量
	CVolumeType MaxLimitOrderVolume;
	//限价单最小下单量
	CVolumeType MinLimitOrderVolume;
	//保证金计算方式
	CDepositCalculateModeType DepositCalculateMode;
	//最大持仓量
	CVolumeType MaxHoldVol;
	//T+1时间,大于此时间为T+1数据
	CTimeType AddOneTime;
	//组合买卖方向(第一腿)
	CDirectType CmbDirect;
	//平仓方式
	CCoverModeType CoverMode;
	//创建日
	CDateType CreateDate;
	//上市日
	CDateType OpenDate;
	//到期日
	CDateType ExpiryDate;
	//开始交割日
	CDateType StartDelivDate;
	//结束交割日
	CDateType EndDelivDate;
	//持仓类型
	CPositionTypeType PositionType;
	//持仓日期类型
	CPositionDateTypeType PositionDateType;
	//多头保证金率
	CRatioType LongMarginRatio;
	//空头保证金率
	CRatioType ShortMarginRatio;
	//是否使用大额单边保证金算法
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
//CWriteableOrderAction是一个存储[合约修改]的对象，可以写出。
/////////////////////////////////////////////////////////////////////////
class COrderAction
{
public:
	//初始化操作，将所有的字段清空
	void init(void);

	//从文件读入
	//@param	input	读入的文件
	//@return	1表示读入成功，0表示读入失败
	int read(FILE *input);

	//向文件写出
	//@param	output 写出的文件
	//@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;

	//将内容写到文件中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp = NULL, int index = -1) const;

	//将内容写入文件，突出显示变化的内容
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const COrderAction *pOriginal) const;

	//将内容写到文件的一行中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp = NULL) const;

	//将内容写到一个字符串中
	//@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

public:
	//系统内部排序(字符串)
	COrderInnerIDType OrderInnerID;
	//投资者编号
	CInvestorIDType InvestorID;
	//用户代码
	CUserIDType UserID;
	//操作标志
	CActionFlagType ActionFlag;
	//委托价格
	CPriceType Price;
	//委托数量
	CVolumeType Volume;
	//经纪会员代码
	CBrokerIDType BrokerID;
	//交易所代码
	CExchangeIDType ExchangeID;
	//报单编号
	COrderSysIDType OrderSysID;
	//策略ID号
	CRuleIDType RuleID;
	//报单引用
	COrderRefType OrderRef;
	//合约代码
	CInstrumentIDType InstrumentID;
	//报单操作状态
	COrderActionStatusType OrderActionStatus;
	//状态信息
	CErrorMsgType StatusMsg;
	//操作日期
	CDateType ActionTime;
	//操作时间
	CTimeType ActionDate;
	//物理账号
	CTraderIDType TraderID;
	//报单终端编码
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
//CWriteableExchOrderAction是一个存储[合约修改]的对象，可以写出。
/////////////////////////////////////////////////////////////////////////
class CExchOrderAction
{
public:
	//初始化操作，将所有的字段清空
	void init(void);

	//从文件读入
	//@param	input	读入的文件
	//@return	1表示读入成功，0表示读入失败
	int read(FILE *input);

	//向文件写出
	//@param	output 写出的文件
	//@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;

	//将内容写到文件中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp = NULL, int index = -1) const;

	//将内容写入文件，突出显示变化的内容
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CExchOrderAction *pOriginal) const;

	//将内容写到文件的一行中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp = NULL) const;

	//将内容写到一个字符串中
	//@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

public:
	//系统内部排序(字符串)
	COrderInnerIDType OrderInnerID;
	//投资者编号
	CInvestorIDType InvestorID;
	//用户代码
	CUserIDType UserID;
	//操作标志
	CActionFlagType ActionFlag;
	//委托价格
	CPriceType Price;
	//委托数量
	CVolumeType Volume;
	//经纪会员代码
	CBrokerIDType BrokerID;
	//交易所代码
	CExchangeIDType ExchangeID;
	//报单编号
	COrderSysIDType OrderSysID;
	//策略ID号
	CRuleIDType RuleID;
	//报单引用
	COrderRefType OrderRef;
	//合约代码
	CInstrumentIDType InstrumentID;
	//报单操作状态
	COrderActionStatusType OrderActionStatus;
	//操作日期
	CDateType ActionTime;
	//操作时间
	CTimeType ActionDate;
	//状态信息
	CErrorMsgType StatusMsg;
	//物理账号
	CTraderIDType TraderID;
	//报单终端编码
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
//CWriteableOrder是一个存储[报单]的对象，可以写出。
/////////////////////////////////////////////////////////////////////////
class COrder
{
public:
	//初始化操作，将所有的字段清空
	void init(void);

	//从文件读入
	//@param	input	读入的文件
	//@return	1表示读入成功，0表示读入失败
	int read(FILE *input);

	//向文件写出
	//@param	output 写出的文件
	//@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;

	//将内容写到文件中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp = NULL, int index = -1) const;

	//将内容写入文件，突出显示变化的内容
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const COrder *pOriginal) const;

	//将内容写到文件的一行中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp = NULL) const;

	//将内容写到一个字符串中
	//@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

public:
	//用户代码
	CUserIDType UserID;
	//交易所代码
	CExchangeIDType ExchangeID;
	//商品代码
	CCommodityIDType CommodityID;
	//合约代码
	CInstrumentIDType InstrumentID;
	//报单价格条件
	COrderPriceTypeType OrderPriceType;
	//委托模式
	COrderModeType OrderMode;
	//买入卖出
	CDirectType Direction;
	//开仓平仓
	COffsetType OffsetFlag;
	//投机保值
	CHedgeType HedgeFlag;
	//委托价格
	CPriceType Price;
	//委托数量
	CVolumeType Volume;
	//客户报单信息
	COrderInfoType OrderInfo;
	//经纪会员代码
	CBrokerIDType BrokerID;
	//投资者编号
	CInvestorIDType InvestorID;
	//有效期类型
	CTimeConditionType TimeCondition;
	//交易日
	CDateType TradingDay;
	//系统内部排序(字符串)
	COrderInnerIDType OrderInnerID;
	//报单编号
	COrderSysIDType OrderSysID;
	//成交价格
	CPriceType TradePrice;
	//今成交数量
	CVolumeType VolumeTraded;
	//剩余数量
	CVolumeType VolumeTotal;
	//合约在交易所的代码
	CInstrumentIDType ExchangeInstID;
	//报单提交状态
	COrderSubmitStatusType OrderSubmitStatus;
	//委托状态
	COrderStateType OrderState;
	//报单状态
	COrderStatusType OrderStatus;
	//报单日期
	CDateType InsertDate;
	//委托时间
	CTimeType InsertTime;
	//更新日期
	CDateType UpdateDate;
	//更新时间
	CTimeType UpdateTime;
	//撤销时间
	CTimeType CancelTime;
	//最后一次操作错误信息码
	CErrorIDType ErrorCode;
	//状态信息
	CErrorMsgType StatusMsg;
	//结算编号
	CSettlementIDType SettlementID;
	//报单来源
	COrderSourceType OrderSource;
	//经纪公司报单编号
	CSequenceNoType BrokerOrderSeq;
	//报单引用
	COrderRefType OrderRef;
	//前置编号
	CFrontIDType FrontID;
	//会话编号
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
//CWriteableTrade是一个存储[成交]的对象，可以写出。
/////////////////////////////////////////////////////////////////////////
class CTrade
{
public:
	//初始化操作，将所有的字段清空
	void init(void);

	//从文件读入
	//@param	input	读入的文件
	//@return	1表示读入成功，0表示读入失败
	int read(FILE *input);

	//向文件写出
	//@param	output 写出的文件
	//@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;

	//将内容写到文件中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp = nullptr, int index = -1) const;

	//将内容写入文件，突出显示变化的内容
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CTrade *pOriginal) const;

	//将内容写到文件的一行中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp = nullptr) const;

	//将内容写到一个字符串中
	//@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

public:
	//交易所代码
	CExchangeIDType ExchangeID;
	//交易日
	CDateType TradingDay;
	//成交号
	CTradeIDType TradeID;
	//报单编号
	COrderSysIDType OrderSysID;
	//系统内部排序(字符串)
	COrderInnerIDType OrderInnerID;
	//商品代码
	CCommodityIDType CommodityID;
	//合约代码
	CInstrumentIDType InstrumentID;
	//交易员代码
	CUserIDType UserID;
	//买入卖出
	CDirectType Direction;
	//开仓平仓
	COffsetType OffsetFlag;
	//成交价
	CPriceType TradePrice;
	//成交数量
	CVolumeType VolumeTraded;
	//成交日期
	CDateType TradeDate;
	//成交时间
	CTimeType TradeTime;
	//手续费
	CMoneyType TradeFee;
	//手续费币种
	CCurrencyIDType CurrencyID;
	//手工手续费
	CManualFeeType ManualFee;
	//删除标志
	CDeletedType Deleted;
	//平仓价格
	CPriceType CoverPrice;
	//合约在交易所的代码
	CInstrumentIDType ExchangeInstID;
	//经纪会员代码
	CBrokerIDType BrokerID;
	//投资者代码
	CInvestorIDType InvestorID;
	//报单引用
	COrderRefType OrderRef;
	//投机保值
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
//CWriteableEsfInstPartInfo是一个存储[合约部分信息]的对象，可以写出。
/////////////////////////////////////////////////////////////////////////
class CEsfInstPartInfo
{
public:
	//初始化操作，将所有的字段清空
	void init(void);

	//从文件读入
	//@param	input	读入的文件
	//@return	1表示读入成功，0表示读入失败
	int read(FILE *input);

	//向文件写出
	//@param	output 写出的文件
	//@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;

	//将内容写到文件中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp = NULL, int index = -1) const;

	//将内容写入文件，突出显示变化的内容
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CEsfInstPartInfo *pOriginal) const;

	//将内容写到文件的一行中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp = NULL) const;

	//将内容写到一个字符串中
	//@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

public:
	//交易所名称
	CExchangeNameType ExchangeName;
	//合约代码
	CInstrumentIDType InstrumentID;
	//合约名称
	CInstrumentNameType InstrumentName;
	//报价精度
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
//CWriteableCurrency是一个存储[币种信息]的对象，可以写出。
/////////////////////////////////////////////////////////////////////////
class CCurrency
{
public:
	//初始化操作，将所有的字段清空
	void init(void);

	//从文件读入
	//@param	input	读入的文件
	//@return	1表示读入成功，0表示读入失败
	int read(FILE *input);

	//向文件写出
	//@param	output 写出的文件
	//@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;

	//将内容写到文件中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp = NULL, int index = -1) const;

	//将内容写入文件，突出显示变化的内容
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CCurrency *pOriginal) const;

	//将内容写到文件的一行中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp = NULL) const;

	//将内容写到一个字符串中
	//@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

public:
	//货币编号
	CCurrencyIDType CurrencyID;
	//货币名称
	CCurrencyNameType CurrencyName;
	//是基币
	CIsPrimaryCurrencyType IsPrimary;
	//不是基币
	CIsShareCurrencyType IsShare;
	//汇率(1当前货币换算多少基币)
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
//CWriteableExchUserLogin是一个存储[交易用户登录]的对象，可以写出。
/////////////////////////////////////////////////////////////////////////
class CExchUserLogin
{
public:
	//初始化操作，将所有的字段清空
	void init(void);

	//从文件读入
	//@param	input	读入的文件
	//@return	1表示读入成功，0表示读入失败
	int read(FILE *input);

	//向文件写出
	//@param	output 写出的文件
	//@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;

	//将内容写到文件中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp = NULL, int index = -1) const;

	//将内容写入文件，突出显示变化的内容
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CExchUserLogin *pOriginal) const;

	//将内容写到文件的一行中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp = NULL) const;

	//将内容写到一个字符串中
	//@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

public:
	//经纪公司代码
	CBrokerIDType BrokerID;
	//用户代码
	CUserIDType UserID;
	//登录密码
	CPasswordType Password;
	//系统交易日
	CDateType TradingDay;
	//登录成功时间
	CTimeType LoginTime;
	//最大报单引用
	COrderRefType MaxOrderRef;
	//IP地址
	CIPAddressType IPAddress;
	//用户端产品信息
	CFunctionKeyType UserProductInfo;
	//接口端产品信息
	CFunctionKeyType InterfaceProductInfo;
	//协议信息
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
//CWriteableExchUserLogout是一个存储[交易用户登出]的对象，可以写出。
/////////////////////////////////////////////////////////////////////////
class CExchUserLogout
{
public:
	//初始化操作，将所有的字段清空
	void init(void);

	//从文件读入
	//@param	input	读入的文件
	//@return	1表示读入成功，0表示读入失败
	int read(FILE *input);

	//向文件写出
	//@param	output 写出的文件
	//@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;

	//将内容写到文件中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp = NULL, int index = -1) const;

	//将内容写入文件，突出显示变化的内容
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CExchUserLogout *pOriginal) const;

	//将内容写到文件的一行中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp = NULL) const;

	//将内容写到一个字符串中
	//@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;
public:
	//用户代码
	CUserIDType UserID;
	//经纪公司代码
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
//CWriteableExchMDUserLogin是一个存储[行情用户登录]的对象，可以写出。
/////////////////////////////////////////////////////////////////////////
class CExchMDUserLogin
{
public:
	//初始化操作，将所有的字段清空
	void init(void);

	//从文件读入
	//@param	input	读入的文件
	//@return	1表示读入成功，0表示读入失败
	int read(FILE *input);

	//向文件写出
	//@param	output 写出的文件
	//@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;

	//将内容写到文件中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp = NULL, int index = -1) const;

	//将内容写入文件，突出显示变化的内容
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CExchMDUserLogin *pOriginal) const;

	//将内容写到文件的一行中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp = NULL) const;

	//将内容写到一个字符串中
	//@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

public:
	//经纪公司代码
	CBrokerIDType BrokerID;
	//用户代码
	CUserIDType UserID;
	//登录密码
	CPasswordType Password;
	//系统交易日
	CDateType TradingDay;
	//登录成功时间
	CTimeType LoginTime;
	//最大报单引用
	COrderRefType MaxOrderRef;
	//IP地址
	CIPAddressType IPAddress;
	//用户端产品信息
	CFunctionKeyType UserProductInfo;
	//接口端产品信息
	CFunctionKeyType InterfaceProductInfo;
	//协议信息
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
//CWriteableExchMDUserLogout是一个存储[行情用户登出]的对象，可以写出。
/////////////////////////////////////////////////////////////////////////
class CExchMDUserLogout
{
public:
	//初始化操作，将所有的字段清空
	void init(void);

	//从文件读入
	//@param	input	读入的文件
	//@return	1表示读入成功，0表示读入失败
	int read(FILE *input);

	//向文件写出
	//@param	output 写出的文件
	//@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;

	//将内容写到文件中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp = NULL, int index = -1) const;

	//将内容写入文件，突出显示变化的内容
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CExchMDUserLogout *pOriginal) const;

	//将内容写到文件的一行中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp = NULL) const;

	//将内容写到一个字符串中
	//@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

public:
	//用户代码
	CUserIDType UserID;
	//经纪公司代码
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
//CWriteableExchOrder是一个存储[报单]的对象，可以写出。
/////////////////////////////////////////////////////////////////////////
class CExchOrder
{
public:
	//初始化操作，将所有的字段清空
	void init(void);

	//从文件读入
	//@param	input	读入的文件
	//@return	1表示读入成功，0表示读入失败
	int read(FILE *input);

	//向文件写出
	//@param	output 写出的文件
	//@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;

	//将内容写到文件中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp = NULL, int index = -1) const;

	//将内容写入文件，突出显示变化的内容
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CExchOrder *pOriginal) const;

	//将内容写到文件的一行中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp = NULL) const;

	//将内容写到一个字符串中
	//@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

public:
	//用户代码
	CUserIDType UserID;
	//交易所代码
	CExchangeIDType ExchangeID;
	//商品代码
	CCommodityIDType CommodityID;
	//合约代码
	CInstrumentIDType InstrumentID;
	//报单价格条件
	COrderPriceTypeType OrderPriceType;
	//委托模式
	COrderModeType OrderMode;
	//买入卖出
	CDirectType Direction;
	//开仓平仓
	COffsetType OffsetFlag;
	//投机保值
	CHedgeType HedgeFlag;
	//委托价格
	CPriceType Price;
	//委托数量
	CVolumeType Volume;
	//客户报单信息
	COrderInfoType OrderInfo;
	//经纪会员代码
	CBrokerIDType BrokerID;
	//投资者编号
	CInvestorIDType InvestorID;
	//有效期类型
	CTimeConditionType TimeCondition;
	//交易日
	CDateType TradingDay;
	//系统内部排序(字符串)
	COrderInnerIDType OrderInnerID;
	//报单编号
	COrderSysIDType OrderSysID;
	//成交价格
	CPriceType TradePrice;
	//今成交数量
	CVolumeType VolumeTraded;
	//剩余数量
	CVolumeType VolumeTotal;
	//合约在交易所的代码
	CInstrumentIDType ExchangeInstID;
	//报单提交状态
	COrderSubmitStatusType OrderSubmitStatus;
	//委托状态
	COrderStateType OrderState;
	//报单状态
	COrderStatusType OrderStatus;
	//报单日期
	CDateType InsertDate;
	//委托时间
	CTimeType InsertTime;
	//更新日期
	CDateType UpdateDate;
	//更新时间
	CTimeType UpdateTime;
	//撤销时间
	CTimeType CancelTime;
	//最后一次操作错误信息码
	CErrorIDType ErrorCode;
	//状态信息
	CErrorMsgType StatusMsg;
	//结算编号
	CSettlementIDType SettlementID;
	//报单来源
	COrderSourceType OrderSource;
	//经纪公司报单编号
	CSequenceNoType BrokerOrderSeq;
	//报单引用
	COrderRefType OrderRef;
	//前置编号
	CFrontIDType FrontID;
	//会话编号
	CSessionIDType SessionID;
	//终端机编号
	CTerminalIDType TerminalID;
	//终端机类型
	CTerminalTypeType TerminalType;
	//交易接口类型
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
//CWriteableExchTrade是一个存储[成交]的对象，可以写出。
/////////////////////////////////////////////////////////////////////////
class CExchTrade
{
public:
	//初始化操作，将所有的字段清空
	void init(void);

	//从文件读入
	//@param	input	读入的文件
	//@return	1表示读入成功，0表示读入失败
	int read(FILE *input);

	//向文件写出
	//@param	output 写出的文件
	//@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;

	//将内容写到文件中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp = NULL, int index = -1) const;

	//将内容写入文件，突出显示变化的内容
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CExchTrade *pOriginal) const;

	//将内容写到文件的一行中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp = NULL) const;

	//将内容写到一个字符串中
	//@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

public:
	//交易所代码
	CExchangeIDType ExchangeID;
	//交易日
	CDateType TradingDay;
	//成交号
	CTradeIDType TradeID;
	//报单编号
	COrderSysIDType OrderSysID;
	//系统内部排序(字符串)
	COrderInnerIDType OrderInnerID;
	//商品代码
	CCommodityIDType CommodityID;
	//合约代码
	CInstrumentIDType InstrumentID;
	//交易员代码
	CUserIDType UserID;
	//买入卖出
	CDirectType Direction;
	//开仓平仓
	COffsetType OffsetFlag;
	//成交价
	CPriceType TradePrice;
	//成交数量
	CVolumeType VolumeTraded;
	//成交日期
	CDateType TradeDate;
	//成交时间
	CTimeType TradeTime;
	//手续费
	CMoneyType TradeFee;
	//手续费币种
	CCurrencyIDType CurrencyID;
	//手工手续费
	CManualFeeType ManualFee;
	//删除标志
	CDeletedType Deleted;
	//平仓价格
	CPriceType CoverPrice;
	//合约在交易所的代码
	CInstrumentIDType ExchangeInstID;
	//经纪会员代码
	CBrokerIDType BrokerID;
	//投资者代码
	CInvestorIDType InvestorID;
	//报单引用
	COrderRefType OrderRef;
	//投机保值
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
//CWriteableExchInvestorPosition是一个存储[投资者仓位]的对象，可以写出。
/////////////////////////////////////////////////////////////////////////
class CExchInvestorPosition
{
public:
	//初始化操作，将所有的字段清空
	void init(void);

	//从文件读入
	//@param	input	读入的文件
	//@return	1表示读入成功，0表示读入失败
	int read(FILE *input);

	//向文件写出
	//@param	output 写出的文件
	//@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;

	//将内容写到文件中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp = NULL, int index = -1) const;

	//将内容写入文件，突出显示变化的内容
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CExchInvestorPosition *pOriginal) const;

	//将内容写到文件的一行中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp = NULL) const;

	//将内容写到一个字符串中
	//@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

public:
	//投资者编号
	CInvestorIDType InvestorID;
	//经纪公司代码
	CBrokerIDType BrokerID;
	//交易所代码
	CExchangeIDType ExchangeID;
	//客户代码
	CClientIDType ClientID;
	//合约代码
	CInstrumentIDType InstrumentID;
	//买卖方向
	CDirectionType Direction;
	//投机套保标志
	CHedgeFlagType HedgeFlag;
	//占用保证金
	CUsedMarginType UsedMargin;
	//今持仓量
	CPositionType Position;
	//今日持仓成本
	CPositionCostType PositionCost;
	//昨持仓量
	CYdPositionType YdPosition;
	//昨日持仓成本
	CYdPositionCostType YdPositionCost;
	//冻结的保证金
	CFrozenMarginType FrozenMargin;
	//开仓冻结持仓
	CFrozenPositionType FrozenPosition;
	//平仓冻结持仓
	CFrozenClosingType FrozenClosing;
	//冻结的权利金
	CFrozenPremiumType FrozenPremium;
	//最后一笔成交编号
	CLastTradeIDType LastTradeID;
	//最后一笔本地报单编号
	CLastOrderLocalIDType LastOrderLocalID;
	//币种
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
//CWriteableExchInvestorAccount是一个存储[投资者资金]的对象，可以写出。
/////////////////////////////////////////////////////////////////////////
class CExchInvestorAccount
{
public:
	//初始化操作，将所有的字段清空
	void init(void);

	//从文件读入
	//@param	input	读入的文件
	//@return	1表示读入成功，0表示读入失败
	int read(FILE *input);

	//向文件写出
	//@param	output 写出的文件
	//@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;

	//将内容写到文件中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp = NULL, int index = -1) const;

	//将内容写入文件，突出显示变化的内容
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CExchInvestorAccount *pOriginal) const;

	//将内容写到文件的一行中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp = NULL) const;

	//将内容写到一个字符串中
	//@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

public:
	//经纪公司代码
	CBrokerIDType BrokerID;
	//投资者代码
	CInvestorIDType InvestorID;
	//资金帐号
	CAccountIDType AccountID;
	//上次结算准备金
	CPreBalanceType PreBalance;
	//入金金额
	CDepositType Deposit;
	//出金金额
	CWithdrawType Withdraw;
	//冻结的保证金
	CFrozenMarginType FrozenMargin;
	//冻结手续费
	CFrozenFeeType FrozenFee;
	//冻结权利金
	CFrozenPremiumType FrozenPremium;
	//手续费
	CFeeType Fee;
	//平仓盈亏
	CCloseProfitType CloseProfit;
	//持仓盈亏
	CPositionProfitType PositionProfit;
	//可用资金
	CAvailableType Available;
	//多头冻结的保证金
	CLongFrozenMarginType LongFrozenMargin;
	//空头冻结的保证金
	CShortFrozenMarginType ShortFrozenMargin;
	//多头占用保证金
	CLongMarginType LongMargin;
	//空头占用保证金
	CShortMarginType ShortMargin;
	//当日释放保证金
	CReleaseMarginType ReleaseMargin;
	//动态权益
	CDynamicRightsType DynamicRights;
	//今日出入金
	CTodayInOutType TodayInOut;
	//占用保证金
	CMarginType Margin;
	//期权权利金收支
	CPremiumType Premium;
	//风险度
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
//CWriteableExchDepthMarketData是一个存储[深度行情]的对象，可以写出。
/////////////////////////////////////////////////////////////////////////
class CExchDepthMarketData
{
public:
	//初始化操作，将所有的字段清空
	void init(void);

	//从文件读入
	//@param	input	读入的文件
	//@return	1表示读入成功，0表示读入失败
	int read(FILE *input);

	//向文件写出
	//@param	output 写出的文件
	//@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;

	//将内容写到文件中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp = NULL, int index = -1) const;

	//将内容写入文件，突出显示变化的内容
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CExchDepthMarketData *pOriginal) const;

	//将内容写到文件的一行中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp = NULL) const;

	//将内容写到一个字符串中
	//@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

public:
	//交易日
	CDateType TradingDay;
	//昨结算
	CPriceType PreClearPrice;
	//昨收盘
	CPriceType PreClosePrice;
	//昨持仓量
	CLargeVolumeType PreOpenInterest;
	//昨虚实度
	CRatioType PreDelta;
	//合约最高
	CPriceType HistoryHigh;
	//合约最低
	CPriceType HistoryLow;
	//今开盘
	CPriceType OpenPrice;
	//最高价
	CPriceType HighestPrice;
	//最低价
	CPriceType LowestPrice;
	//今收盘
	CPriceType ClosePrice;
	//涨停板价
	CPriceType UpperLimitPrice;
	//跌停板价
	CPriceType LowerLimitPrice;
	//本次结算价
	CPriceType ClearPrice;
	//今虚实度
	CRatioType CurrDelta;
	//报价精度
	CPrecisionType Precision;
	//最新价
	CPriceType LastPrice;
	//数量
	CVolumeType Volume;
	//成交金额
	CMoneyType Turnover;
	//持仓量
	CLargeVolumeType OpenInterest;
	//涨跌
	CPriceType NetChg;
	//涨跌幅
	CPriceType Markup;
	//振幅
	CRatioType Swing;
	//平均价
	CPriceType AvgPrice;
	//申买价一
	CPriceType BidPrice1;
	//申买量一
	CVolumeType BidVolume1;
	//申卖价一
	CPriceType AskPrice1;
	//申卖量一
	CVolumeType AskVolume1;
	//申买价二
	CPriceType BidPrice2;
	//申买量二
	CVolumeType BidVolume2;
	//申买价三
	CPriceType BidPrice3;
	//申买量三
	CVolumeType BidVolume3;
	//申卖价二
	CPriceType AskPrice2;
	//申卖量二
	CVolumeType AskVolume2;
	//申卖价三
	CPriceType AskPrice3;
	//申卖量三
	CVolumeType AskVolume3;
	//申买价四
	CPriceType BidPrice4;
	//申买量四
	CVolumeType BidVolume4;
	//申买价五
	CPriceType BidPrice5;
	//申买量五
	CVolumeType BidVolume5;
	//申卖价四
	CPriceType AskPrice4;
	//申卖量四
	CVolumeType AskVolume4;
	//申卖价五
	CPriceType AskPrice5;
	//申卖量五
	CVolumeType AskVolume5;
	//申买价六
	CPriceType BidPrice6;
	//申买量六
	CVolumeType BidVolume6;
	//申买价七
	CPriceType BidPrice7;
	//申买量七
	CVolumeType BidVolume7;
	//申买价八
	CPriceType BidPrice8;
	//申买量八
	CVolumeType BidVolume8;
	//申买价九
	CPriceType BidPrice9;
	//申买量九
	CVolumeType BidVolume9;
	//申买价十
	CPriceType BidPrice10;
	//申买量十
	CVolumeType BidVolume10;
	//申卖价六
	CPriceType AskPrice6;
	//申卖量六
	CVolumeType AskVolume6;
	//申卖价七
	CPriceType AskPrice7;
	//申卖量七
	CVolumeType AskVolume7;
	//申卖价八
	CPriceType AskPrice8;
	//申卖量八
	CVolumeType AskVolume8;
	//申卖价九
	CPriceType AskPrice9;
	//申卖量九
	CVolumeType AskVolume9;
	//申卖价十
	CPriceType AskPrice10;
	//申卖量十
	CVolumeType AskVolume10;
	//序号
	CSequenceNoType SequenceNo;
	//市场中文名
	CMarketNameType MarketName;
	//合约代码
	CInstrumentIDType InstrumentID;
	//合约交易状态-1:未知0:开市1:无红利2:竞价3:挂起4:闭市5:开市前6:闭市前7:快市
	CContractStateType InstrumentStatus;
	//最后修改时间
	CTimeType UpdateTime;
	//最后修改毫秒
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
//CWriteableExchDepthMarketHistoryData是一个存储[深度行情历史]的对象，可以写出。
/////////////////////////////////////////////////////////////////////////
class CExchDepthMarketHistoryData
{
public:
	//初始化操作，将所有的字段清空
	void init(void);

	//从文件读入
	//@param	input	读入的文件
	//@return	1表示读入成功，0表示读入失败
	int read(FILE *input);

	//向文件写出
	//@param	output 写出的文件
	//@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;

	//将内容写到文件中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp = NULL, int index = -1) const;

	//将内容写入文件，突出显示变化的内容
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CExchDepthMarketHistoryData *pOriginal) const;

	//将内容写到文件的一行中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp = NULL) const;

	//将内容写到一个字符串中
	//@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

public:
	//交易日
	CDateType TradingDay;
	//昨结算
	CPriceType PreClearPrice;
	//昨收盘
	CPriceType PreClosePrice;
	//昨持仓量
	CLargeVolumeType PreOpenInterest;
	//昨虚实度
	CRatioType PreDelta;
	//合约最高
	CPriceType HistoryHigh;
	//合约最低
	CPriceType HistoryLow;
	//今开盘
	CPriceType OpenPrice;
	//最高价
	CPriceType HighestPrice;
	//最低价
	CPriceType LowestPrice;
	//今收盘
	CPriceType ClosePrice;
	//涨停板价
	CPriceType UpperLimitPrice;
	//跌停板价
	CPriceType LowerLimitPrice;
	//本次结算价
	CPriceType ClearPrice;
	//今虚实度
	CRatioType CurrDelta;
	//报价精度
	CPrecisionType Precision;
	//最新价
	CPriceType LastPrice;
	//数量
	CVolumeType Volume;
	//成交金额
	CMoneyType Turnover;
	//持仓量
	CLargeVolumeType OpenInterest;
	//涨跌
	CPriceType NetChg;
	//涨跌幅
	CPriceType Markup;
	//振幅
	CRatioType Swing;
	//平均价
	CPriceType AvgPrice;
	//申买价一
	CPriceType BidPrice1;
	//申买量一
	CVolumeType BidVolume1;
	//申卖价一
	CPriceType AskPrice1;
	//申卖量一
	CVolumeType AskVolume1;
	//申买价二
	CPriceType BidPrice2;
	//申买量二
	CVolumeType BidVolume2;
	//申买价三
	CPriceType BidPrice3;
	//申买量三
	CVolumeType BidVolume3;
	//申卖价二
	CPriceType AskPrice2;
	//申卖量二
	CVolumeType AskVolume2;
	//申卖价三
	CPriceType AskPrice3;
	//申卖量三
	CVolumeType AskVolume3;
	//申买价四
	CPriceType BidPrice4;
	//申买量四
	CVolumeType BidVolume4;
	//申买价五
	CPriceType BidPrice5;
	//申买量五
	CVolumeType BidVolume5;
	//申卖价四
	CPriceType AskPrice4;
	//申卖量四
	CVolumeType AskVolume4;
	//申卖价五
	CPriceType AskPrice5;
	//申卖量五
	CVolumeType AskVolume5;
	//申买价六
	CPriceType BidPrice6;
	//申买量六
	CVolumeType BidVolume6;
	//申买价七
	CPriceType BidPrice7;
	//申买量七
	CVolumeType BidVolume7;
	//申买价八
	CPriceType BidPrice8;
	//申买量八
	CVolumeType BidVolume8;
	//申买价九
	CPriceType BidPrice9;
	//申买量九
	CVolumeType BidVolume9;
	//申买价十
	CPriceType BidPrice10;
	//申买量十
	CVolumeType BidVolume10;
	//申卖价六
	CPriceType AskPrice6;
	//申卖量六
	CVolumeType AskVolume6;
	//申卖价七
	CPriceType AskPrice7;
	//申卖量七
	CVolumeType AskVolume7;
	//申卖价八
	CPriceType AskPrice8;
	//申卖量八
	CVolumeType AskVolume8;
	//申卖价九
	CPriceType AskPrice9;
	//申卖量九
	CVolumeType AskVolume9;
	//申卖价十
	CPriceType AskPrice10;
	//申卖量十
	CVolumeType AskVolume10;
	//序号
	CSequenceNoType SequenceNo;
	//市场中文名
	CMarketNameType MarketName;
	//合约代码
	CInstrumentIDType InstrumentID;
	//合约交易状态-1:未知0:开市1:无红利2:竞价3:挂起4:闭市5:开市前6:闭市前7:快市
	CContractStateType InstrumentStatus;
	//最后修改时间
	CTimeType UpdateTime;
	//最后修改毫秒
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
//CWriteableExchInstrument是一个存储[合约]的对象，可以写出。
/////////////////////////////////////////////////////////////////////////
class CExchInstrument
{
public:
	//初始化操作，将所有的字段清空
	void init(void);

	//从文件读入
	//@param	input	读入的文件
	//@return	1表示读入成功，0表示读入失败
	int read(FILE *input);

	//向文件写出
	//@param	output 写出的文件
	//@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;

	//将内容写到文件中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp = NULL, int index = -1) const;

	//将内容写入文件，突出显示变化的内容
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CExchInstrument *pOriginal) const;

	//将内容写到文件的一行中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp = NULL) const;

	//将内容写到一个字符串中
	//@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

public:
	//交易接口类型
	CAppTypeType AppType;
	//交易所代码
	CExchangeIDType ExchangeID;
	//商品
	CCommodityIDType CommodityID;
	//商品类型
	CCommodityTypeType CommodityType;
	//合约
	CInstrumentIDType InstrumentID;
	//合约名称
	CInstrumentNameType InstrumentName;
	//合约类型
	CContractTypeType InstrumentType;
	//合约状态
	CContractStateType InstrumentState;
	//合约在交易所的代码（CTP），在易盛中，指代RelateCommodityNo（依赖合约）
	CInstrumentIDType ExchangeInstID;
	//合约生命周期状态
	CInstLifePhaseType InstLifePhase;
	//商品名称
	CCommodityNameType CommodityName;
	//商品属性
	CCommodityAttributeType CommodityAttribute;
	//商品交易权限
	CTradeRightType TradeRight;
	//每手乘数
	CProductDotType MultipleValue;
	//最小变动价位
	CPriceType PriceTick;
	//最小变动价分子
	CUpperTickType UpperTick;
	//最小变动价分母
	CLowerTickType LowerTick;
	//商品使用币种
	CCurrencyIDType CurrencyID;
	//报价精度
	CPrecisionType Precision;
	//交割方式
	CDeliveryModeType DeliveryMode;
	//交割日偏移
	CDeliveryDaysType DeliveryDays;
	//交割年份
	CYearType DeliveryYear;
	//交割月
	CMonthType DeliveryMonth;
	//市价单最大下单量
	CVolumeType MaxMarketOrderVolume;
	//市价单最小下单量
	CVolumeType MinMarketOrderVolume;
	//限价单最大下单量
	CVolumeType MaxLimitOrderVolume;
	//限价单最小下单量
	CVolumeType MinLimitOrderVolume;
	//保证金计算方式
	CDepositCalculateModeType DepositCalculateMode;
	//最大持仓量
	CVolumeType MaxHoldVol;
	//T+1时间,大于此时间为T+1数据
	CTimeType AddOneTime;
	//组合买卖方向(第一腿)
	CDirectType CmbDirect;
	//平仓方式
	CCoverModeType CoverMode;
	//创建日
	CDateType CreateDate;
	//上市日
	CDateType OpenDate;
	//到期日
	CDateType ExpiryDate;
	//开始交割日
	CDateType StartDelivDate;
	//结束交割日
	CDateType EndDelivDate;
	//持仓类型
	CPositionTypeType PositionType;
	//持仓日期类型
	CPositionDateTypeType PositionDateType;
	//多头保证金率
	CRatioType LongMarginRatio;
	//空头保证金率
	CRatioType ShortMarginRatio;
	//是否使用大额单边保证金算法
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
//CWriteableExchInstrumentStatus是一个存储[合约]的对象，可以写出。
/////////////////////////////////////////////////////////////////////////
class CExchInstrumentStatus
{
public:
	//初始化操作，将所有的字段清空
	void init(void);

	//从文件读入
	//@param	input	读入的文件
	//@return	1表示读入成功，0表示读入失败
	int read(FILE *input);

	//向文件写出
	//@param	output 写出的文件
	//@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;

	//将内容写到文件中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp = NULL, int index = -1) const;

	//将内容写入文件，突出显示变化的内容
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CExchInstrumentStatus *pOriginal) const;

	//将内容写到文件的一行中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp = NULL) const;

	//将内容写到一个字符串中
	//@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

public:
	//交易所代码
	CExchangeIDType ExchangeID;
	//合约在交易所的代码
	CInstrumentIDType ExchangeInstID;
	//合约代码
	CInstrumentIDType InstrumentID;
	//合约交易状态
	CInstrumentStatusType InstrumentStatus;
	//交易阶段编号
	CTradingSegmentSNType TradingSegmentSN;
	//进入本状态时间
	CTimeType EnterTime;
	//进入本状态原因
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
//CWriteablePhyAccount是一个存储[物理账号]的对象，可以写出。
/////////////////////////////////////////////////////////////////////////
class CPhyAccount
{
public:
	//初始化操作，将所有的字段清空
	void init(void);

	//从文件读入
	//@param	input	读入的文件
	//@return	1表示读入成功，0表示读入失败
	int read(FILE *input);

	//向文件写出
	//@param	output 写出的文件
	//@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;

	//将内容写到文件中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp = NULL, int index = -1) const;

	//将内容写入文件，突出显示变化的内容
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CPhyAccount *pOriginal) const;

	//将内容写到文件的一行中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp = NULL) const;

	//将内容写到一个字符串中
	//@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

public:
	//经纪公司代码
	CBrokerIDType BrokerID;
	//用户代码
	CUserIDType UserID;
	//密码
	CPasswordType Password;
	//交易前置地址集
	CIPAddrListType TradeFrontAddr;
	//交易Fens地址集
	CIPAddrListType TradeFrontNmSrv;
	//行情前置地址集
	CIPAddrListType MarketFrontAddr;
	//行情Fens地址集
	CIPAddrListType MarketFrontNmSrv;
	//私有流重传方式
	CResumeTypeType PrivateResumeType;
	//公共流重传方式
	CResumeTypeType PublicResumeType;
	//行情续传类型
	CResumeTypeType MarketResumeType;
	//行情主题列表
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
//CWriteableInvestorPosition是一个存储[持仓信息]的对象，可以写出。
/////////////////////////////////////////////////////////////////////////
class CInvestorPosition
{
public:
	//初始化操作，将所有的字段清空
	void init(void);

	//从文件读入
	//@param	input	读入的文件
	//@return	1表示读入成功，0表示读入失败
	int read(FILE *input);

	//向文件写出
	//@param	output 写出的文件
	//@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;

	//将内容写到文件中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp = NULL, int index = -1) const;

	//将内容写入文件，突出显示变化的内容
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CInvestorPosition *pOriginal) const;

	//将内容写到文件的一行中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp = NULL) const;

	//将内容写到一个字符串中
	//@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

public:
	//投资者编号
	CInvestorIDType InvestorID;
	//经纪公司代码
	CBrokerIDType BrokerID;
	//交易所代码
	CExchangeIDType ExchangeID;
	//客户代码
	CClientIDType ClientID;
	//合约代码
	CInstrumentIDType InstrumentID;
	//买卖方向
	CDirectionType Direction;
	//投机套保标志
	CHedgeFlagType HedgeFlag;
	//占用保证金
	CUsedMarginType UsedMargin;
	//今持仓量
	CPositionType Position;
	//今日持仓成本
	CPositionCostType PositionCost;
	//昨持仓量
	CYdPositionType YdPosition;
	//昨日持仓成本
	CYdPositionCostType YdPositionCost;
	//冻结的保证金
	CFrozenMarginType FrozenMargin;
	//开仓冻结持仓
	CFrozenPositionType FrozenPosition;
	//平仓冻结持仓
	CFrozenClosingType FrozenClosing;
	//冻结的权利金
	CFrozenPremiumType FrozenPremium;
	//最后一笔成交编号
	CLastTradeIDType LastTradeID;
	//最后一笔本地报单编号
	CLastOrderLocalIDType LastOrderLocalID;
	//币种
	CCurrencyType Currency;
	//冻结手续费
	CMoneyType FrozenCommission;
	//手续费
	CMoneyType Commission;
	//浮动盈亏
	CPriceType FloatProfit;
	//平仓盈亏
	CPriceType CloseProfit;
	//平仓数量
	CVolumeType CloseVolume;
	//平仓金额
	CMoneyType CloseAmount;
	//多头冻结的保证金
	CLongFrozenMarginType LongFrozenMargin;
	//空头冻结的保证金
	CShortFrozenMarginType ShortFrozenMargin;
	//多头占用保证金
	CLongMarginType LongMargin;
	//空头占用保证金
	CShortMarginType ShortMargin;
	//当日释放保证金
	CReleaseMarginType ReleaseMargin;
	//可用资金
	CAvailableType Available;
	//入金金额
	CDepositType Deposit;
	//出金金额
	CWithdrawType Withdraw;
	//上次结算准备金
	CPreBalanceType PreBalance;
	//动态权益
	CDynamicRightsType DynamicRights;
	//今日出入金
	CTodayInOutType TodayInOut;
	//期权权利金收支
	CPremiumType Premium;
	//风险度
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
//CWriteableRuleInfo是一个存储[策略信息]的对象，可以写出。
/////////////////////////////////////////////////////////////////////////
class CRuleInfo
{
public:
	//初始化操作，将所有的字段清空
	void init(void);

	//从文件读入
	//@param	input	读入的文件
	//@return	1表示读入成功，0表示读入失败
	int read(FILE *input);

	//向文件写出
	//@param	output 写出的文件
	//@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;

	//将内容写到文件中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp = NULL, int index = -1) const;

	//将内容写入文件，突出显示变化的内容
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CRuleInfo *pOriginal) const;

	//将内容写到文件的一行中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp = NULL) const;

	//将内容写到一个字符串中
	//@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

public:
	//策略代码
	CRuleIDType RuleID;
	//策略Dll存储位置
	CRulePathType RulePath;
	//策略的版本
	CRuleVersionType RuleVersion;
	//策略名称
	CRuleNameType RuleName;
	//策略配置文件存储位置
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
//CWriteableExchInvestorFee是一个存储[投资者手续费率]的对象，可以写出。
/////////////////////////////////////////////////////////////////////////
class CExchInvestorFee
{
public:
	//初始化操作，将所有的字段清空
	void init(void);

	//从文件读入
	//@param	input	读入的文件
	//@return	1表示读入成功，0表示读入失败
	int read(FILE *input);

	//向文件写出
	//@param	output 写出的文件
	//@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;

	//将内容写到文件中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp = NULL, int index = -1) const;

	//将内容写入文件，突出显示变化的内容
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CExchInvestorFee *pOriginal) const;

	//将内容写到文件的一行中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp = NULL) const;

	//将内容写到一个字符串中
	//@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

public:
	//经纪公司代码
	CBrokerIDType BrokerID;
	//客户代码
	CClientIDType ClientID;
	//交易所代码
	CExchangeIDType ExchangeID;
	//合约代码
	CInstrumentIDType InstrumentID;
	//品种代码
	CProductIDType ProductID;
	//开仓手续费按比例
	COpenFeeRateType OpenFeeRate;
	//开仓手续费按手数
	COpenFeeAmtType OpenFeeAmt;
	//平仓手续费按比例
	COffsetFeeRateType OffsetFeeRate;
	//平仓手续费按手数
	COffsetFeeAmtType OffsetFeeAmt;
	//平今仓手续费按比例
	COTFeeRateType OTFeeRate;
	//平今仓手续费按手数
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
//CWriteableExchInvestorMargin是一个存储[交易保证金率]的对象，可以写出。
/////////////////////////////////////////////////////////////////////////
class CExchInvestorMargin
{
public:
	//初始化操作，将所有的字段清空
	void init(void);

	//从文件读入
	//@param	input	读入的文件
	//@return	1表示读入成功，0表示读入失败
	int read(FILE *input);

	//向文件写出
	//@param	output 写出的文件
	//@return	1表时写出成功，0表示写出失败
	int write(FILE *output) const;

	//将内容写到文件中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp = NULL, int index = -1) const;

	//将内容写入文件，突出显示变化的内容
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CExchInvestorMargin *pOriginal) const;

	//将内容写到文件的一行中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp = NULL) const;

	//将内容写到一个字符串中
	//@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

public:
	//经纪公司代码
	CBrokerIDType BrokerID;
	//客户代码
	CClientIDType ClientID;
	//交易所代码
	CExchangeIDType ExchangeID;
	//合约代码
	CInstrumentIDType InstrumentID;
	//品种代码
	CProductIDType ProductID;
	//多头占用保证金按比例
	CLongMarginRateType LongMarginRate;
	//多头保证金按手数
	CLongMarginAmtType LongMarginAmt;
	//空头占用保证金按比例
	CShortMarginRateType ShortMarginRate;
	//空头保证金按手数
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