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












#endif