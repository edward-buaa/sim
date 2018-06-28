#ifdef _WIN32
#pragma warning(disable:4996)
#endif

#include "RecordStruct.h"
#include <boost/lexical_cast.hpp>
#include "../utility/compare.h"

//-------------------------------------------------------------
/* 应用业务FieldID 静态成员的初始化 */
REGISTER_FIELD(REC_ID_CurrentTime, CWriteableCurrentTime, "");
REGISTER_FIELD(REC_ID_Terminal, CWriteableTerminal, "");
REGISTER_FIELD(REC_ID_Front, CWriteableFront, "");
REGISTER_FIELD(REC_ID_Trader, CWriteableTrader, "");
REGISTER_FIELD(REC_ID_TraderParalle, CWriteableTraderParalle, "");
REGISTER_FIELD(REC_ID_TraderLoginLog, CWriteableTraderLoginLog, "");
REGISTER_FIELD(REC_ID_TraderConnect, CWriteableTraderConnect, "");
REGISTER_FIELD(REC_ID_TraderCertInfo, CWriteableTraderCertInfo, "");
REGISTER_FIELD(REC_ID_User, CWriteableUser, "");
//--------------------------------------------------------------


/////////////////////////////////////////////////////////////////////////////////////////////
//初始化操作，将所有的字段清空
void CCurrentTime::init()
{
	memset(this, 0, sizeof(CCurrentTime));
}

//从文件读入
int CCurrentTime::read(FILE* input)
{
	if (fread(this, 1, sizeof(CCurrentTime), input) != sizeof(CCurrentTime))
		return 0;
	else
		return 1;
}

//向文件写出
int CCurrentTime::write(FILE* output) const
{
	if (fwrite(this, 1, sizeof(CCurrentTime), output) != sizeof(CCurrentTime))
		return 0;
	else
		return 1;
}

//将内容写到文件中,用于DEBUG
void CCurrentTime::dump(FILE *fp, int index) const
{
	char index_buf[64];
	if (fp == NULL)
	{
		fp = stdout;
	}
	if (index >= 0)
		sprintf(index_buf, "[%d]", index);
	else
		index_buf[0] = '\0';
	fprintf(fp, "\tCCurrentTime%s = {\n", index_buf);
	fprintf(fp, "\t\tCurrDate = %s    [当前日期]\n", boost::lexical_cast<std::string>(CurrDate).c_str());
	fprintf(fp, "\t\tCurrTime = %s    [当前时间]\n", boost::lexical_cast<std::string>(CurrTime).c_str());
	fprintf(fp, "\t\tCurrMillisec = %s    [当前时间（毫秒）]\n", boost::lexical_cast<std::string>(CurrMillisec).c_str());
	fprintf(fp, "\t\tActionDay = %s    [业务日期]\n", boost::lexical_cast<std::string>(ActionDay).c_str());
	fprintf(fp, "\t\tOldTime = %s    [原来时间]\n", boost::lexical_cast<std::string>(OldTime).c_str());
	fprintf(fp, "\t\tOldMillisec = %s    [原来时间（毫秒）]\n", boost::lexical_cast<std::string>(OldMillisec).c_str());
	fprintf(fp, "\t}\n");
}

//将内容写入文件，突出显示变化的内容
void CCurrentTime::dumpDiff(FILE *fp, const CCurrentTime *pOriginal) const
{
	if (fp == NULL)
	{
		fp = stdout;
	}

	fprintf(fp, "\tCCurrentTime = {\n");
	if (compare(CurrDate, pOriginal->CurrDate) != 0)
	{
		fprintf(fp, "\t\tCurrDate = %s -> %s    [当前日期]\n", boost::lexical_cast<std::string>(pOriginal->CurrDate).c_str(), boost::lexical_cast<std::string>(CurrDate).c_str());
	}
	else
	{
		fprintf(fp, "\t\tCurrDate = %s    [当前日期]\n", boost::lexical_cast<std::string>(CurrDate).c_str());
	}

	if (compare(CurrTime, pOriginal->CurrTime) != 0)
	{
		fprintf(fp, "\t\tCurrTime = %s -> %s    [当前时间]\n", boost::lexical_cast<std::string>(pOriginal->CurrTime).c_str(), boost::lexical_cast<std::string>(CurrTime).c_str());
	}
	else
	{
		fprintf(fp, "\t\tCurrTime = %s    [当前时间]\n", boost::lexical_cast<std::string>(CurrTime).c_str());
	}

	if (compare(CurrMillisec, pOriginal->CurrMillisec) != 0)
	{
		fprintf(fp, "\t\tCurrMillisec = %s -> %s    [当前时间（毫秒）]\n", boost::lexical_cast<std::string>(pOriginal->CurrMillisec).c_str(), boost::lexical_cast<std::string>(CurrMillisec).c_str());
	}
	else
	{
		fprintf(fp, "\t\tCurrMillisec = %s    [当前时间（毫秒）]\n", boost::lexical_cast<std::string>(CurrMillisec).c_str());
	}

	if (compare(ActionDay, pOriginal->ActionDay) != 0)
	{
		fprintf(fp, "\t\tActionDay = %s -> %s    [业务日期]\n", boost::lexical_cast<std::string>(pOriginal->ActionDay).c_str(), boost::lexical_cast<std::string>(ActionDay).c_str());
	}
	else
	{
		fprintf(fp, "\t\tActionDay = %s    [业务日期]\n", boost::lexical_cast<std::string>(ActionDay).c_str());
	}

	if (compare(OldTime, pOriginal->OldTime) != 0)
	{
		fprintf(fp, "\t\tOldTime = %s -> %s    [原来时间]\n", boost::lexical_cast<std::string>(pOriginal->OldTime).c_str(), boost::lexical_cast<std::string>(OldTime).c_str());
	}
	else
	{
		fprintf(fp, "\t\tOldTime = %s    [原来时间]\n", boost::lexical_cast<std::string>(OldTime).c_str());
	}

	if (compare(OldMillisec, pOriginal->OldMillisec) != 0)
	{
		fprintf(fp, "\t\tOldMillisec = %s -> %s    [原来时间（毫秒）]\n", boost::lexical_cast<std::string>(pOriginal->OldMillisec).c_str(), boost::lexical_cast<std::string>(OldMillisec).c_str());
	}
	else
	{
		fprintf(fp, "\t\tOldMillisec = %s    [原来时间（毫秒）]\n", boost::lexical_cast<std::string>(OldMillisec).c_str());
	}
	fprintf(fp, "\t}\n");
}

//将内容写到文件的一行中,用于DEBUG
void CCurrentTime::dumpInLine(FILE *fp) const
{
	if (fp == NULL)
	{
		fp = stdout;
	}

	std::stringstream sbuf;
	sbuf << ",CurrDate," << CurrDate;
	sbuf << ",CurrTime," << CurrTime;
	sbuf << ",CurrMillisec," << CurrMillisec;
	sbuf << ",ActionDay," << ActionDay;
	sbuf << ",OldTime," << OldTime;
	sbuf << ",OldMillisec," << OldMillisec;
	fprintf(fp, "%s", sbuf.str().c_str());
}

//将内容写到一个字符串中
void CCurrentTime::dumpString(char *target) const
{
	std::stringstream sbuf;
	sbuf << "CurrDate=" << CurrDate << ",";
	sbuf << "CurrTime=" << CurrTime << ",";
	sbuf << "CurrMillisec=" << CurrMillisec << ",";
	sbuf << "ActionDay=" << ActionDay << ",";
	sbuf << "OldTime=" << OldTime << ",";
	sbuf << "OldMillisec=" << OldMillisec << ",";

	sprintf(target, "%s", sbuf.str().c_str());
}

////////////////////////////////////////////////////////////////////////////////////
void CTerminal::init(void)
{
	memset(this, 0, sizeof(CTerminal));
}

int CTerminal::read(FILE *input)
{
	if (fread(this, 1, sizeof(CTerminal), input) != sizeof(CTerminal))
		return 0;
	else
		return 1;
}

int CTerminal::write(FILE *output) const
{
	if (fwrite(this, 1, sizeof(CTerminal), output) != sizeof(CTerminal))
		return 0;
	else
		return 1;
}

void CTerminal::dump(FILE *fp, int index) const
{
	char index_buf[64];
	if (fp == nullptr)
	{
		fp = stdout;
	}
	if (index >= 0)
		sprintf(index_buf, "[%d]", index);
	else
		index_buf[0] = '\0';
	fprintf(fp, "\tCTerminal%s = {\n", index_buf);
	fprintf(fp, "\t\tTradingDay = %s    [交易日]\n", boost::lexical_cast<std::string>(TradingDay).c_str());
	fprintf(fp, "\t\tTerminalID = %s    [终端机编号]\n", boost::lexical_cast<std::string>(TerminalID).c_str());
	fprintf(fp, "\t\tTerminalType = %s    [终端机类型]\n", boost::lexical_cast<std::string>(TerminalType).c_str());
	fprintf(fp, "\t\tAppType = %s    [交易接口类型]\n", boost::lexical_cast<std::string>(AppType).c_str());
	fprintf(fp, "\t\tSessionID = %s    [终端机当前登录Session]\n", boost::lexical_cast<std::string>(SessionID).c_str());
	fprintf(fp, "\t\tStartTime = %s    [终端机启动时间]\n", boost::lexical_cast<std::string>(StartTime).c_str());
	fprintf(fp, "\t\tUpdateTime = %s    [终端机更新时间]\n", boost::lexical_cast<std::string>(UpdateTime).c_str());
	fprintf(fp, "\t}\n");
}

void CTerminal::dumpDiff(FILE *fp, const CTerminal *pOriginal) const
{
	//char buf[4000],bufOriginal[4000];
	if (fp == nullptr)
	{
		fp = stdout;
	}
	fprintf(fp, "\tCTerminal = {\n");
	if (compare(TradingDay, pOriginal->TradingDay) != 0)
	{
		fprintf(fp, "\t\tTradingDay = %s -> %s    [交易日]\n", boost::lexical_cast<std::string>(pOriginal->TradingDay).c_str(), boost::lexical_cast<std::string>(TradingDay).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTradingDay = %s    [交易日]\n", boost::lexical_cast<std::string>(TradingDay).c_str());
	}
	if (compare(TerminalID, pOriginal->TerminalID) != 0)
	{
		fprintf(fp, "\t\tTerminalID = %s -> %s    [终端机编号]\n", boost::lexical_cast<std::string>(pOriginal->TerminalID).c_str(), boost::lexical_cast<std::string>(TerminalID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTerminalID = %s    [终端机编号]\n", boost::lexical_cast<std::string>(TerminalID).c_str());
	}
	if (compare(TerminalType, pOriginal->TerminalType) != 0)
	{
		fprintf(fp, "\t\tTerminalType = %s -> %s    [终端机类型]\n", boost::lexical_cast<std::string>(pOriginal->TerminalType).c_str(), boost::lexical_cast<std::string>(TerminalType).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTerminalType = %s    [终端机类型]\n", boost::lexical_cast<std::string>(TerminalType).c_str());
	}
	if (compare(AppType, pOriginal->AppType) != 0)
	{
		fprintf(fp, "\t\tAppType = %s -> %s    [交易接口类型]\n", boost::lexical_cast<std::string>(pOriginal->AppType).c_str(), boost::lexical_cast<std::string>(AppType).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAppType = %s    [交易接口类型]\n", boost::lexical_cast<std::string>(AppType).c_str());
	}
	if (compare(SessionID, pOriginal->SessionID) != 0)
	{
		fprintf(fp, "\t\tSessionID = %s -> %s    [终端机当前登录Session]\n", boost::lexical_cast<std::string>(pOriginal->SessionID).c_str(), boost::lexical_cast<std::string>(SessionID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tSessionID = %s    [终端机当前登录Session]\n", boost::lexical_cast<std::string>(SessionID).c_str());
	}
	if (compare(StartTime, pOriginal->StartTime) != 0)
	{
		fprintf(fp, "\t\tStartTime = %s -> %s    [终端机启动时间]\n", boost::lexical_cast<std::string>(pOriginal->StartTime).c_str(), boost::lexical_cast<std::string>(StartTime).c_str());
	}
	else
	{
		fprintf(fp, "\t\tStartTime = %s    [终端机启动时间]\n", boost::lexical_cast<std::string>(StartTime).c_str());
	}
	if (compare(UpdateTime, pOriginal->UpdateTime) != 0)
	{
		fprintf(fp, "\t\tUpdateTime = %s -> %s    [终端机更新时间]\n", boost::lexical_cast<std::string>(pOriginal->UpdateTime).c_str(), boost::lexical_cast<std::string>(UpdateTime).c_str());
	}
	else
	{
		fprintf(fp, "\t\tUpdateTime = %s    [终端机更新时间]\n", boost::lexical_cast<std::string>(UpdateTime).c_str());
	}
	fprintf(fp, "\t}\n");
}

void CTerminal::dumpInLine(FILE *fp) const
{
	if (fp == nullptr)
	{
		fp = stdout;
	}
	std::stringstream sbuf;

	sbuf << ",TradingDay," << TradingDay;
	sbuf << ",TerminalID," << TerminalID;
	sbuf << ",TerminalType," << TerminalType;
	sbuf << ",AppType," << AppType;
	sbuf << ",SessionID," << SessionID;
	sbuf << ",StartTime," << StartTime;
	sbuf << ",UpdateTime," << UpdateTime;
	fprintf(fp, "%s", sbuf.str().c_str());
}

void CTerminal::dumpString(char *target) const
{
	char *p = target;

	std::stringstream sbuf;

	sbuf << "TradingDay=" << TradingDay << ",";
	sbuf << "TerminalID=" << TerminalID << ",";
	sbuf << "TerminalType=" << TerminalType << ",";
	sbuf << "AppType=" << AppType << ",";
	sbuf << "SessionID=" << SessionID << ",";
	sbuf << "StartTime=" << StartTime << ",";
	sbuf << "UpdateTime=" << UpdateTime << ",";

	sprintf(p, "%s", sbuf.str().c_str());
}

/////////////////////////////////////////////////////////////////////////////
void CFront::init(void)
{
	memset(this, 0, sizeof(CFront));
}

int CFront::read(FILE *input)
{
	if (fread(this, 1, sizeof(CFront), input) != sizeof(CFront))
		return 0;
	else
		return 1;
}

int CFront::write(FILE *output) const
{
	if (fwrite(this, 1, sizeof(CFront), output) != sizeof(CFront))
		return 0;
	else
		return 1;
}

void CFront::dump(FILE *fp, int index) const
{
	char index_buf[64];
	if (fp == nullptr)
	{
		fp = stdout;
	}
	if (index >= 0)
		sprintf(index_buf, "[%d]", index);
	else
		index_buf[0] = '\0';
	fprintf(fp, "\tCFront%s = {\n", index_buf);
	fprintf(fp, "\t\tTradingDay = %s    [交易日]\n", boost::lexical_cast<std::string>(TradingDay).c_str());
	fprintf(fp, "\t\tFrontID = %s    [前置编号]\n", boost::lexical_cast<std::string>(FrontID).c_str());
	fprintf(fp, "\t\tSessionID = %s    [前置Session编号]\n", boost::lexical_cast<std::string>(SessionID).c_str());
	fprintf(fp, "\t\tStartTime = %s    [前置机启动时间]\n", boost::lexical_cast<std::string>(StartTime).c_str());
	fprintf(fp, "\t\tUpdateTime = %s    [前置机更新时间]\n", boost::lexical_cast<std::string>(UpdateTime).c_str());
	fprintf(fp, "\t\tFrontRunStatus = %s    [前置运行状态]\n", boost::lexical_cast<std::string>(FrontRunStatus).c_str());
	fprintf(fp, "\t}\n");
}

void CFront::dumpDiff(FILE *fp, const CFront *pOriginal) const
{
	if (fp == nullptr)
	{
		fp = stdout;
	}
	fprintf(fp, "\tCFront = {\n");
	if (compare(TradingDay, pOriginal->TradingDay) != 0)
	{
		fprintf(fp, "\t\tTradingDay = %s -> %s    [交易日]\n", boost::lexical_cast<std::string>(pOriginal->TradingDay).c_str(), boost::lexical_cast<std::string>(TradingDay).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTradingDay = %s    [交易日]\n", boost::lexical_cast<std::string>(TradingDay).c_str());
	}
	if (compare(FrontID, pOriginal->FrontID) != 0)
	{
		fprintf(fp, "\t\tFrontID = %s -> %s    [前置编号]\n", boost::lexical_cast<std::string>(pOriginal->FrontID).c_str(), boost::lexical_cast<std::string>(FrontID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tFrontID = %s    [前置编号]\n", boost::lexical_cast<std::string>(FrontID).c_str());
	}
	if (compare(SessionID, pOriginal->SessionID) != 0)
	{
		fprintf(fp, "\t\tSessionID = %s -> %s    [前置Session编号]\n", boost::lexical_cast<std::string>(pOriginal->SessionID).c_str(), boost::lexical_cast<std::string>(SessionID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tSessionID = %s    [前置Session编号]\n", boost::lexical_cast<std::string>(SessionID).c_str());
	}
	if (compare(StartTime, pOriginal->StartTime) != 0)
	{
		fprintf(fp, "\t\tStartTime = %s -> %s    [前置机启动时间]\n", boost::lexical_cast<std::string>(pOriginal->StartTime).c_str(), boost::lexical_cast<std::string>(StartTime).c_str());
	}
	else
	{
		fprintf(fp, "\t\tStartTime = %s    [前置机启动时间]\n", boost::lexical_cast<std::string>(StartTime).c_str());
	}
	if (compare(UpdateTime, pOriginal->UpdateTime) != 0)
	{
		fprintf(fp, "\t\tUpdateTime = %s -> %s    [前置机更新时间]\n", boost::lexical_cast<std::string>(pOriginal->UpdateTime).c_str(), boost::lexical_cast<std::string>(UpdateTime).c_str());
	}
	else
	{
		fprintf(fp, "\t\tUpdateTime = %s    [前置机更新时间]\n", boost::lexical_cast<std::string>(UpdateTime).c_str());
	}
	if (compare(FrontRunStatus, pOriginal->FrontRunStatus) != 0)
	{
		fprintf(fp, "\t\tFrontRunStatus = %s -> %s    [前置运行状态]\n", boost::lexical_cast<std::string>(pOriginal->FrontRunStatus).c_str(), boost::lexical_cast<std::string>(FrontRunStatus).c_str());
	}
	else
	{
		fprintf(fp, "\t\tFrontRunStatus = %s    [前置运行状态]\n", boost::lexical_cast<std::string>(FrontRunStatus).c_str());
	}
	fprintf(fp, "\t}\n");
}

void CFront::dumpInLine(FILE *fp) const
{
	if (fp == nullptr)
	{
		fp = stdout;
	}
	std::stringstream sbuf;

	sbuf << ",TradingDay," << TradingDay;
	sbuf << ",FrontID," << FrontID;
	sbuf << ",SessionID," << SessionID;
	sbuf << ",StartTime," << StartTime;
	sbuf << ",UpdateTime," << UpdateTime;
	sbuf << ",FrontRunStatus," << FrontRunStatus;
	fprintf(fp, "%s", sbuf.str().c_str());
}

void CFront::dumpString(char *target) const
{
	char *p = target;
	std::stringstream sbuf;
	sbuf << "TradingDay=" << TradingDay << ",";
	sbuf << "FrontID=" << FrontID << ",";
	sbuf << "SessionID=" << SessionID << ",";
	sbuf << "StartTime=" << StartTime << ",";
	sbuf << "UpdateTime=" << UpdateTime << ",";
	sbuf << "FrontRunStatus=" << FrontRunStatus << ",";

	sprintf(p, "%s", sbuf.str().c_str());
}

void CTrader::init(void)
{
	memset(this, 0, sizeof(CTrader));
}

int CTrader::read(FILE *input)
{
	if (fread(this, 1, sizeof(CTrader), input) != sizeof(CTrader))
		return 0;
	else
		return 1;
}

int CTrader::write(FILE *output) const
{
	if (fwrite(this, 1, sizeof(CTrader), output) != sizeof(CTrader))
		return 0;
	else
		return 1;
}

void CTrader::dump(FILE *fp, int index) const
{
	char index_buf[64];
	//char buf[4000];///存放每个成员的字符串值	
	if (fp == nullptr)
	{
		fp = stdout;
	}
	if (index >= 0)
		sprintf(index_buf, "[%d]", index);
	else
		index_buf[0] = '\0';
	fprintf(fp, "\tCTrader%s = {\n", index_buf);
	fprintf(fp, "\t\tTraderID = %s    [交易员代码]\n", boost::lexical_cast<std::string>(TraderID).c_str());
	fprintf(fp, "\t\tAppType = %s    [交易接口类型]\n", boost::lexical_cast<std::string>(AppType).c_str());
	fprintf(fp, "\t\tTerminalType = %s    [交易员登录身份]\n", boost::lexical_cast<std::string>(TerminalType).c_str());
	fprintf(fp, "\t\tTradingDay = %s    [交易日]\n", boost::lexical_cast<std::string>(TradingDay).c_str());
	fprintf(fp, "\t\tMaxParalle = %s    [交易员最大并行数量]\n", boost::lexical_cast<std::string>(MaxParalle).c_str());
	fprintf(fp, "\t\tServerIP = %s    [交易接口IP地址]\n", boost::lexical_cast<std::string>(ServerIP).c_str());
	fprintf(fp, "\t\tParticipantID = %s    [会员代码]\n", boost::lexical_cast<std::string>(ParticipantID).c_str());
	fprintf(fp, "\t\tBrokerID = %s    [经纪会员代码]\n", boost::lexical_cast<std::string>(BrokerID).c_str());
	fprintf(fp, "\t\tOperatorID = %s    [操作员号]\n", boost::lexical_cast<std::string>(OperatorID).c_str());
	fprintf(fp, "\t\tUserProductInfo = %s    [用户端产品信息]\n", boost::lexical_cast<std::string>(UserProductInfo).c_str());
	fprintf(fp, "\t\tInterfaceProductInfo = %s    [接口端产品信息]\n", boost::lexical_cast<std::string>(InterfaceProductInfo).c_str());
	fprintf(fp, "\t\tProtocolInfo = %s    [协议信息]\n", boost::lexical_cast<std::string>(ProtocolInfo).c_str());
	fprintf(fp, "\t\tMacAddress = %s    [Mac地址]\n", boost::lexical_cast<std::string>(MacAddress).c_str());
	fprintf(fp, "\t\tClientIPAddress = %s    [终端IP地址]\n", boost::lexical_cast<std::string>(ClientIPAddress).c_str());
	fprintf(fp, "\t\tPassword = %s    [密码]\n", boost::lexical_cast<std::string>(Password).c_str());
	fprintf(fp, "\t\tIsCaLogin = %s    [是否CA认证]\n", boost::lexical_cast<std::string>(IsCaLogin).c_str());
	fprintf(fp, "\t\tIdentity = %s    [登录身份类型,目前只支持单客户]\n", boost::lexical_cast<std::string>(Identity).c_str());
	fprintf(fp, "\t\tIsForcePwd = %s    [是否强制修改密码]\n", boost::lexical_cast<std::string>(IsForcePwd).c_str());
	fprintf(fp, "\t\tOneTimePassword = %s    [动态密码]\n", boost::lexical_cast<std::string>(OneTimePassword).c_str());
	fprintf(fp, "\t\tOtpPass = %s    [otp认证密码]\n", boost::lexical_cast<std::string>(OtpPass).c_str());
	fprintf(fp, "\t\tCaLen = %s    [CA信息长度，IsCaLogin为'Y'时，本字段有效]\n", boost::lexical_cast<std::string>(CaLen).c_str());
	fprintf(fp, "\t\tCaInfo = %s    [CA登录时填写,IsCaLogin为'Y'时，本字段有效]\n", boost::lexical_cast<std::string>(CaInfo).c_str());
	fprintf(fp, "\t}\n");
}

void CTrader::dumpDiff(FILE *fp, const CTrader *pOriginal) const
{
	if (fp == nullptr)
	{
		fp = stdout;
	}
	fprintf(fp, "\tCTrader = {\n");
	if (compare(TraderID, pOriginal->TraderID) != 0)
	{
		fprintf(fp, "\t\tTraderID = %s -> %s    [交易员代码]\n", boost::lexical_cast<std::string>(pOriginal->TraderID).c_str(), boost::lexical_cast<std::string>(TraderID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTraderID = %s    [交易员代码]\n", boost::lexical_cast<std::string>(TraderID).c_str());
	}
	if (compare(AppType, pOriginal->AppType) != 0)
	{
		fprintf(fp, "\t\tAppType = %s -> %s    [交易接口类型]\n", boost::lexical_cast<std::string>(pOriginal->AppType).c_str(), boost::lexical_cast<std::string>(AppType).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAppType = %s    [交易接口类型]\n", boost::lexical_cast<std::string>(AppType).c_str());
	}
	if (compare(TerminalType, pOriginal->TerminalType) != 0)
	{
		fprintf(fp, "\t\tTerminalType = %s -> %s    [交易员登录身份]\n", boost::lexical_cast<std::string>(pOriginal->TerminalType).c_str(), boost::lexical_cast<std::string>(TerminalType).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTerminalType = %s    [交易员登录身份]\n", boost::lexical_cast<std::string>(TerminalType).c_str());
	}
	if (compare(TradingDay, pOriginal->TradingDay) != 0)
	{
		fprintf(fp, "\t\tTradingDay = %s -> %s    [交易日]\n", boost::lexical_cast<std::string>(pOriginal->TradingDay).c_str(), boost::lexical_cast<std::string>(TradingDay).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTradingDay = %s    [交易日]\n", boost::lexical_cast<std::string>(TradingDay).c_str());
	}
	if (compare(MaxParalle, pOriginal->MaxParalle) != 0)
	{
		fprintf(fp, "\t\tMaxParalle = %s -> %s    [交易员最大并行数量]\n", boost::lexical_cast<std::string>(pOriginal->MaxParalle).c_str(), boost::lexical_cast<std::string>(MaxParalle).c_str());
	}
	else
	{
		fprintf(fp, "\t\tMaxParalle = %s    [交易员最大并行数量]\n", boost::lexical_cast<std::string>(MaxParalle).c_str());
	}
	if (compare(ServerIP, pOriginal->ServerIP) != 0)
	{
		fprintf(fp, "\t\tServerIP = %s -> %s    [交易接口IP地址]\n", boost::lexical_cast<std::string>(pOriginal->ServerIP).c_str(), boost::lexical_cast<std::string>(ServerIP).c_str());
	}
	else
	{
		fprintf(fp, "\t\tServerIP = %s    [交易接口IP地址]\n", boost::lexical_cast<std::string>(ServerIP).c_str());
	}
	if (compare(ParticipantID, pOriginal->ParticipantID) != 0)
	{
		fprintf(fp, "\t\tParticipantID = %s -> %s    [会员代码]\n", boost::lexical_cast<std::string>(pOriginal->ParticipantID).c_str(), boost::lexical_cast<std::string>(ParticipantID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tParticipantID = %s    [会员代码]\n", boost::lexical_cast<std::string>(ParticipantID).c_str());
	}
	if (compare(BrokerID, pOriginal->BrokerID) != 0)
	{
		fprintf(fp, "\t\tBrokerID = %s -> %s    [经纪会员代码]\n", boost::lexical_cast<std::string>(pOriginal->BrokerID).c_str(), boost::lexical_cast<std::string>(BrokerID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBrokerID = %s    [经纪会员代码]\n", boost::lexical_cast<std::string>(BrokerID).c_str());
	}
	if (compare(OperatorID, pOriginal->OperatorID) != 0)
	{
		fprintf(fp, "\t\tOperatorID = %s -> %s    [操作员号]\n", boost::lexical_cast<std::string>(pOriginal->OperatorID).c_str(), boost::lexical_cast<std::string>(OperatorID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tOperatorID = %s    [操作员号]\n", boost::lexical_cast<std::string>(OperatorID).c_str());
	}
	if (compare(UserProductInfo, pOriginal->UserProductInfo) != 0)
	{
		fprintf(fp, "\t\tUserProductInfo = %s -> %s    [用户端产品信息]\n", boost::lexical_cast<std::string>(pOriginal->UserProductInfo).c_str(), boost::lexical_cast<std::string>(UserProductInfo).c_str());
	}
	else
	{
		fprintf(fp, "\t\tUserProductInfo = %s    [用户端产品信息]\n", boost::lexical_cast<std::string>(UserProductInfo).c_str());
	}
	if (compare(InterfaceProductInfo, pOriginal->InterfaceProductInfo) != 0)
	{
		fprintf(fp, "\t\tInterfaceProductInfo = %s -> %s    [接口端产品信息]\n", boost::lexical_cast<std::string>(pOriginal->InterfaceProductInfo).c_str(), boost::lexical_cast<std::string>(InterfaceProductInfo).c_str());
	}
	else
	{
		fprintf(fp, "\t\tInterfaceProductInfo = %s    [接口端产品信息]\n", boost::lexical_cast<std::string>(InterfaceProductInfo).c_str());
	}
	if (compare(ProtocolInfo, pOriginal->ProtocolInfo) != 0)
	{
		fprintf(fp, "\t\tProtocolInfo = %s -> %s    [协议信息]\n", boost::lexical_cast<std::string>(pOriginal->ProtocolInfo).c_str(), boost::lexical_cast<std::string>(ProtocolInfo).c_str());
	}
	else
	{
		fprintf(fp, "\t\tProtocolInfo = %s    [协议信息]\n", boost::lexical_cast<std::string>(ProtocolInfo).c_str());
	}
	if (compare(MacAddress, pOriginal->MacAddress) != 0)
	{
		fprintf(fp, "\t\tMacAddress = %s -> %s    [Mac地址]\n", boost::lexical_cast<std::string>(pOriginal->MacAddress).c_str(), boost::lexical_cast<std::string>(MacAddress).c_str());
	}
	else
	{
		fprintf(fp, "\t\tMacAddress = %s    [Mac地址]\n", boost::lexical_cast<std::string>(MacAddress).c_str());
	}
	if (compare(ClientIPAddress, pOriginal->ClientIPAddress) != 0)
	{
		fprintf(fp, "\t\tClientIPAddress = %s -> %s    [终端IP地址]\n", boost::lexical_cast<std::string>(pOriginal->ClientIPAddress).c_str(), boost::lexical_cast<std::string>(ClientIPAddress).c_str());
	}
	else
	{
		fprintf(fp, "\t\tClientIPAddress = %s    [终端IP地址]\n", boost::lexical_cast<std::string>(ClientIPAddress).c_str());
	}
	if (compare(Password, pOriginal->Password) != 0)
	{
		fprintf(fp, "\t\tPassword = %s -> %s    [密码]\n", boost::lexical_cast<std::string>(pOriginal->Password).c_str(), boost::lexical_cast<std::string>(Password).c_str());
	}
	else
	{
		fprintf(fp, "\t\tPassword = %s    [密码]\n", boost::lexical_cast<std::string>(Password).c_str());
	}
	if (compare(IsCaLogin, pOriginal->IsCaLogin) != 0)
	{
		fprintf(fp, "\t\tIsCaLogin = %s -> %s    [是否CA认证]\n", boost::lexical_cast<std::string>(pOriginal->IsCaLogin).c_str(), boost::lexical_cast<std::string>(IsCaLogin).c_str());
	}
	else
	{
		fprintf(fp, "\t\tIsCaLogin = %s    [是否CA认证]\n", boost::lexical_cast<std::string>(IsCaLogin).c_str());
	}
	if (compare(Identity, pOriginal->Identity) != 0)
	{
		fprintf(fp, "\t\tIdentity = %s -> %s    [登录身份类型,目前只支持单客户]\n", boost::lexical_cast<std::string>(pOriginal->Identity).c_str(), boost::lexical_cast<std::string>(Identity).c_str());
	}
	else
	{
		fprintf(fp, "\t\tIdentity = %s    [登录身份类型,目前只支持单客户]\n", boost::lexical_cast<std::string>(Identity).c_str());
	}
	if (compare(IsForcePwd, pOriginal->IsForcePwd) != 0)
	{
		fprintf(fp, "\t\tIsForcePwd = %s -> %s    [是否强制修改密码]\n", boost::lexical_cast<std::string>(pOriginal->IsForcePwd).c_str(), boost::lexical_cast<std::string>(IsForcePwd).c_str());
	}
	else
	{
		fprintf(fp, "\t\tIsForcePwd = %s    [是否强制修改密码]\n", boost::lexical_cast<std::string>(IsForcePwd).c_str());
	}
	if (compare(OneTimePassword, pOriginal->OneTimePassword) != 0)
	{
		fprintf(fp, "\t\tOneTimePassword = %s -> %s    [动态密码]\n", boost::lexical_cast<std::string>(pOriginal->OneTimePassword).c_str(), boost::lexical_cast<std::string>(OneTimePassword).c_str());
	}
	else
	{
		fprintf(fp, "\t\tOneTimePassword = %s    [动态密码]\n", boost::lexical_cast<std::string>(OneTimePassword).c_str());
	}
	if (compare(OtpPass, pOriginal->OtpPass) != 0)
	{
		fprintf(fp, "\t\tOtpPass = %s -> %s    [otp认证密码]\n", boost::lexical_cast<std::string>(pOriginal->OtpPass).c_str(), boost::lexical_cast<std::string>(OtpPass).c_str());
	}
	else
	{
		fprintf(fp, "\t\tOtpPass = %s    [otp认证密码]\n", boost::lexical_cast<std::string>(OtpPass).c_str());
	}
	if (compare(CaLen, pOriginal->CaLen) != 0)
	{
		fprintf(fp, "\t\tCaLen = %s -> %s    [CA信息长度，IsCaLogin为'Y'时，本字段有效]\n", boost::lexical_cast<std::string>(pOriginal->CaLen).c_str(), boost::lexical_cast<std::string>(CaLen).c_str());
	}
	else
	{
		fprintf(fp, "\t\tCaLen = %s    [CA信息长度，IsCaLogin为'Y'时，本字段有效]\n", boost::lexical_cast<std::string>(CaLen).c_str());
	}
	if (compare(CaInfo, pOriginal->CaInfo) != 0)
	{
		fprintf(fp, "\t\tCaInfo = %s -> %s    [CA登录时填写,IsCaLogin为'Y'时，本字段有效]\n", boost::lexical_cast<std::string>(pOriginal->CaInfo).c_str(), boost::lexical_cast<std::string>(CaInfo).c_str());
	}
	else
	{
		fprintf(fp, "\t\tCaInfo = %s    [CA登录时填写,IsCaLogin为'Y'时，本字段有效]\n", boost::lexical_cast<std::string>(CaInfo).c_str());
	}
	fprintf(fp, "\t}\n");
}

void CTrader::dumpInLine(FILE *fp) const
{
	if (fp == NULL)
	{
		fp = stdout;
	}
	std::stringstream sbuf;

	sbuf << ",TraderID," << TraderID;
	sbuf << ",AppType," << AppType;
	sbuf << ",TerminalType," << TerminalType;
	sbuf << ",TradingDay," << TradingDay;
	sbuf << ",MaxParalle," << MaxParalle;
	sbuf << ",ServerIP," << ServerIP;
	sbuf << ",ParticipantID," << ParticipantID;
	sbuf << ",BrokerID," << BrokerID;
	sbuf << ",OperatorID," << OperatorID;
	sbuf << ",UserProductInfo," << UserProductInfo;
	sbuf << ",InterfaceProductInfo," << InterfaceProductInfo;
	sbuf << ",ProtocolInfo," << ProtocolInfo;
	sbuf << ",MacAddress," << MacAddress;
	sbuf << ",ClientIPAddress," << ClientIPAddress;
	sbuf << ",Password," << Password;
	sbuf << ",IsCaLogin," << IsCaLogin;
	sbuf << ",Identity," << Identity;
	sbuf << ",IsForcePwd," << IsForcePwd;
	sbuf << ",OneTimePassword," << OneTimePassword;
	sbuf << ",OtpPass," << OtpPass;
	sbuf << ",CaLen," << CaLen;
	sbuf << ",CaInfo," << CaInfo;
	fprintf(fp, "%s", sbuf.str().c_str());
}

void CTrader::dumpString(char *target) const
{
	char *p = target;

	std::stringstream sbuf;

	sbuf << "TraderID=" << TraderID << ",";
	sbuf << "AppType=" << AppType << ",";
	sbuf << "TerminalType=" << TerminalType << ",";
	sbuf << "TradingDay=" << TradingDay << ",";
	sbuf << "MaxParalle=" << MaxParalle << ",";
	sbuf << "ServerIP=" << ServerIP << ",";
	sbuf << "ParticipantID=" << ParticipantID << ",";
	sbuf << "BrokerID=" << BrokerID << ",";
	sbuf << "OperatorID=" << OperatorID << ",";
	sbuf << "UserProductInfo=" << UserProductInfo << ",";
	sbuf << "InterfaceProductInfo=" << InterfaceProductInfo << ",";
	sbuf << "ProtocolInfo=" << ProtocolInfo << ",";
	sbuf << "MacAddress=" << MacAddress << ",";
	sbuf << "ClientIPAddress=" << ClientIPAddress << ",";
	sbuf << "Password=" << Password << ",";
	sbuf << "IsCaLogin=" << IsCaLogin << ",";
	sbuf << "Identity=" << Identity << ",";
	sbuf << "IsForcePwd=" << IsForcePwd << ",";
	sbuf << "OneTimePassword=" << OneTimePassword << ",";
	sbuf << "OtpPass=" << OtpPass << ",";
	sbuf << "CaLen=" << CaLen << ",";
	sbuf << "CaInfo=" << CaInfo << ",";

	sprintf(p, "%s", sbuf.str().c_str());
}

void CTraderParalle::init(void)
{
	memset(this, 0, sizeof(CTraderParalle));
}

int CTraderParalle::read(FILE *input)
{
	if (fread(this, 1, sizeof(CTraderParalle), input) != sizeof(CTraderParalle))
		return 0;
	else
		return 1;
}

int CTraderParalle::write(FILE *output) const
{
	if (fwrite(this, 1, sizeof(CTraderParalle), output) != sizeof(CTraderParalle))
		return 0;
	else
		return 1;
}

void CTraderParalle::dump(FILE *fp, int index) const
{
	char index_buf[64];
	if (fp == nullptr)
	{
		fp = stdout;
	}
	if (index >= 0)
		sprintf(index_buf, "[%d]", index);
	else
		index_buf[0] = '\0';
	fprintf(fp, "\tCTraderParalle%s = {\n", index_buf);
	fprintf(fp, "\t\tTraderID = %s    [交易员代码]\n", boost::lexical_cast<std::string>(TraderID).c_str());
	fprintf(fp, "\t\tAppType = %s    [交易接口类型]\n", boost::lexical_cast<std::string>(AppType).c_str());
	fprintf(fp, "\t\tTerminalType = %s    [交易员登录身份]\n", boost::lexical_cast<std::string>(TerminalType).c_str());
	fprintf(fp, "\t\tParalled = %s    [交易员并行数量]\n", boost::lexical_cast<std::string>(Paralled).c_str());
	fprintf(fp, "\t\tMaxParalle = %s    [物理帐号最大并行登录数量]\n", boost::lexical_cast<std::string>(MaxParalle).c_str());
	fprintf(fp, "\t}\n");
}

void CTraderParalle::dumpDiff(FILE *fp, const CTraderParalle *pOriginal) const
{
	if (fp == nullptr)
	{
		fp = stdout;
	}
	fprintf(fp, "\tCTraderParalle = {\n");
	if (compare(TraderID, pOriginal->TraderID) != 0)
	{
		fprintf(fp, "\t\tTraderID = %s -> %s    [交易员代码]\n", boost::lexical_cast<std::string>(pOriginal->TraderID).c_str(), boost::lexical_cast<std::string>(TraderID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTraderID = %s    [交易员代码]\n", boost::lexical_cast<std::string>(TraderID).c_str());
	}
	if (compare(AppType, pOriginal->AppType) != 0)
	{
		fprintf(fp, "\t\tAppType = %s -> %s    [交易接口类型]\n", boost::lexical_cast<std::string>(pOriginal->AppType).c_str(), boost::lexical_cast<std::string>(AppType).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAppType = %s    [交易接口类型]\n", boost::lexical_cast<std::string>(AppType).c_str());
	}
	if (compare(TerminalType, pOriginal->TerminalType) != 0)
	{
		fprintf(fp, "\t\tTerminalType = %s -> %s    [交易员登录身份]\n", boost::lexical_cast<std::string>(pOriginal->TerminalType).c_str(), boost::lexical_cast<std::string>(TerminalType).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTerminalType = %s    [交易员登录身份]\n", boost::lexical_cast<std::string>(TerminalType).c_str());
	}
	if (compare(Paralled, pOriginal->Paralled) != 0)
	{
		fprintf(fp, "\t\tParalled = %s -> %s    [交易员并行数量]\n", boost::lexical_cast<std::string>(pOriginal->Paralled).c_str(), boost::lexical_cast<std::string>(Paralled).c_str());
	}
	else
	{
		fprintf(fp, "\t\tParalled = %s    [交易员并行数量]\n", boost::lexical_cast<std::string>(Paralled).c_str());
	}
	if (compare(MaxParalle, pOriginal->MaxParalle) != 0)
	{
		fprintf(fp, "\t\tMaxParalle = %s -> %s    [物理帐号最大并行登录数量]\n", boost::lexical_cast<std::string>(pOriginal->MaxParalle).c_str(), boost::lexical_cast<std::string>(MaxParalle).c_str());
	}
	else
	{
		fprintf(fp, "\t\tMaxParalle = %s    [物理帐号最大并行登录数量]\n", boost::lexical_cast<std::string>(MaxParalle).c_str());
	}
	fprintf(fp, "\t}\n");
}

void CTraderParalle::dumpInLine(FILE *fp) const
{
	if (fp == nullptr)
	{
		fp = stdout;
	}
	std::stringstream sbuf;

	sbuf << ",TraderID," << TraderID;
	sbuf << ",AppType," << AppType;
	sbuf << ",TerminalType," << TerminalType;
	sbuf << ",Paralled," << Paralled;
	sbuf << ",MaxParalle," << MaxParalle;
	fprintf(fp, "%s", sbuf.str().c_str());
}

void CTraderParalle::dumpString(char *target) const
{
	char *p = target;
	std::stringstream sbuf;
	sbuf << "TraderID=" << TraderID << ",";
	sbuf << "AppType=" << AppType << ",";
	sbuf << "TerminalType=" << TerminalType << ",";
	sbuf << "Paralled=" << Paralled << ",";
	sbuf << "MaxParalle=" << MaxParalle << ",";

	sprintf(p, "%s", sbuf.str().c_str());
}

void CTraderLoginLog::init(void)
{
	memset(this, 0, sizeof(CTraderLoginLog));
}

int CTraderLoginLog::read(FILE *input)
{
	if (fread(this, 1, sizeof(CTraderLoginLog), input) != sizeof(CTraderLoginLog))
		return 0;
	else
		return 1;
}

int CTraderLoginLog::write(FILE *output) const
{
	if (fwrite(this, 1, sizeof(CTraderLoginLog), output) != sizeof(CTraderLoginLog))
		return 0;
	else
		return 1;
}

void CTraderLoginLog::dump(FILE *fp, int index) const
{
	char index_buf[64];
	if (fp == nullptr)
	{
		fp = stdout;
	}
	if (index >= 0)
		sprintf(index_buf, "[%d]", index);
	else
		index_buf[0] = '\0';
	fprintf(fp, "\tCTraderLoginLog%s = {\n", index_buf);
	fprintf(fp, "\t\tTraderID = %s    [用户代码（CTP返回的UserID，易盛返回的是LoginNo）]\n", boost::lexical_cast<std::string>(TraderID).c_str());
	fprintf(fp, "\t\tAppType = %s    [交易接口类型]\n", boost::lexical_cast<std::string>(AppType).c_str());
	fprintf(fp, "\t\tTerminalID = %s    [终端机编号]\n", boost::lexical_cast<std::string>(TerminalID).c_str());
	fprintf(fp, "\t\tTerminalType = %s    [终端机类型]\n", boost::lexical_cast<std::string>(TerminalType).c_str());
	fprintf(fp, "\t\tSessionID = %s    [终端机当前登录Session]\n", boost::lexical_cast<std::string>(SessionID).c_str());
	fprintf(fp, "\t\tTraderRuntype = %s    [交易员运行时状态]\n", boost::lexical_cast<std::string>(TraderRuntype).c_str());
	fprintf(fp, "\t\tTradingDay = %s    [交易日（CTP返回）]\n", boost::lexical_cast<std::string>(TradingDay).c_str());
	fprintf(fp, "\t\tIsActive = %s    [交易员当前连接是否活跃]\n", boost::lexical_cast<std::string>(IsActive).c_str());
	fprintf(fp, "\t\tUpdateTime = %s    [实体账户状态更新时间]\n", boost::lexical_cast<std::string>(UpdateTime).c_str());
	fprintf(fp, "\t\tExchLoginTime = %s    [登录成功时间（CTP返回）]\n", boost::lexical_cast<std::string>(ExchLoginTime).c_str());
	fprintf(fp, "\t\tExchBrokerID = %s    [经纪公司代码（CTP返回）]\n", boost::lexical_cast<std::string>(ExchBrokerID).c_str());
	fprintf(fp, "\t\tExchSystemName = %s    [交易系统名称（CTP返回）]\n", boost::lexical_cast<std::string>(ExchSystemName).c_str());
	fprintf(fp, "\t\tExchFrontID = %s    [前置编号（CTP返回）]\n", boost::lexical_cast<std::string>(ExchFrontID).c_str());
	fprintf(fp, "\t\tExchSessionID = %s    [会话编号（CTP返回）]\n", boost::lexical_cast<std::string>(ExchSessionID).c_str());
	fprintf(fp, "\t\tExchMaxOrderRef = %s    [最大报单引用（CTP返回）]\n", boost::lexical_cast<std::string>(ExchMaxOrderRef).c_str());
	fprintf(fp, "\t\tExchIsCaLogin = %s    [是否CA认证（易盛返回）]\n", boost::lexical_cast<std::string>(ExchIsCaLogin).c_str());
	fprintf(fp, "\t\tExchIsForcePwd = %s    [是否强制修改密码（易盛返回）]\n", boost::lexical_cast<std::string>(ExchIsForcePwd).c_str());
	fprintf(fp, "\t\tExchLoginName = %s    [登录端帐号简称（易盛返回）]\n", boost::lexical_cast<std::string>(ExchLoginName).c_str());
	fprintf(fp, "\t\tExchReservedInfo = %s    [客户预留信息,客户自己识别后台系统（易盛返回）]\n", boost::lexical_cast<std::string>(ExchReservedInfo).c_str());
	fprintf(fp, "\t\tExchLastLoginDateTime = %s    [上次登录时间（易盛返回）]\n", boost::lexical_cast<std::string>(ExchLastLoginDateTime).c_str());
	fprintf(fp, "\t\tExchLastLogoutDateTime = %s    [上次登出时间（易盛返回）]\n", boost::lexical_cast<std::string>(ExchLastLogoutDateTime).c_str());
	fprintf(fp, "\t\tExchLastLoginIp = %s    [上次登录ip，兼容ipv6（易盛返回）]\n", boost::lexical_cast<std::string>(ExchLastLoginIp).c_str());
	fprintf(fp, "\t\tExchLastLoginPort = %s    [上次登录port（易盛返回）]\n", boost::lexical_cast<std::string>(ExchLastLoginPort).c_str());
	fprintf(fp, "\t\tExchLastLoginMachineInfo = %s    [上次登录机器信息，主要是Mac地址（易盛返回）]\n", boost::lexical_cast<std::string>(ExchLastLoginMachineInfo).c_str());
	fprintf(fp, "\t\tExchSHFETime = %s    [上期所时间（CTP返回）]\n", boost::lexical_cast<std::string>(ExchSHFETime).c_str());
	fprintf(fp, "\t\tExchDCETime = %s    [大商所时间（CTP返回）]\n", boost::lexical_cast<std::string>(ExchDCETime).c_str());
	fprintf(fp, "\t\tExchCZCETime = %s    [郑商所时间（CTP返回）]\n", boost::lexical_cast<std::string>(ExchCZCETime).c_str());
	fprintf(fp, "\t\tExchFFEXTime = %s    [中金所时间（CTP返回）]\n", boost::lexical_cast<std::string>(ExchFFEXTime).c_str());
	fprintf(fp, "\t\tExchServerDateTime = %s    [系统当前时间(客户端校时，易盛返回）]\n", boost::lexical_cast<std::string>(ExchServerDateTime).c_str());
	fprintf(fp, "\t\tErrorID = %s    [错误代码]\n", boost::lexical_cast<std::string>(ErrorID).c_str());
	fprintf(fp, "\t\tErrorMsg = %s    [错误信息]\n", boost::lexical_cast<std::string>(ErrorMsg).c_str());
	fprintf(fp, "\t}\n");
}

void CTraderLoginLog::dumpDiff(FILE *fp, const CTraderLoginLog *pOriginal) const
{
	if (fp == nullptr)
	{
		fp = stdout;
	}
	fprintf(fp, "\tCTraderLoginLog = {\n");
	if (compare(TraderID, pOriginal->TraderID) != 0)
	{
		fprintf(fp, "\t\tTraderID = %s -> %s    [用户代码（CTP返回的UserID，易盛返回的是LoginNo）]\n", boost::lexical_cast<std::string>(pOriginal->TraderID).c_str(), boost::lexical_cast<std::string>(TraderID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTraderID = %s    [用户代码（CTP返回的UserID，易盛返回的是LoginNo）]\n", boost::lexical_cast<std::string>(TraderID).c_str());
	}
	if (compare(AppType, pOriginal->AppType) != 0)
	{
		fprintf(fp, "\t\tAppType = %s -> %s    [交易接口类型]\n", boost::lexical_cast<std::string>(pOriginal->AppType).c_str(), boost::lexical_cast<std::string>(AppType).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAppType = %s    [交易接口类型]\n", boost::lexical_cast<std::string>(AppType).c_str());
	}
	if (compare(TerminalID, pOriginal->TerminalID) != 0)
	{
		fprintf(fp, "\t\tTerminalID = %s -> %s    [终端机编号]\n", boost::lexical_cast<std::string>(pOriginal->TerminalID).c_str(), boost::lexical_cast<std::string>(TerminalID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTerminalID = %s    [终端机编号]\n", boost::lexical_cast<std::string>(TerminalID).c_str());
	}
	if (compare(TerminalType, pOriginal->TerminalType) != 0)
	{
		fprintf(fp, "\t\tTerminalType = %s -> %s    [终端机类型]\n", boost::lexical_cast<std::string>(pOriginal->TerminalType).c_str(), boost::lexical_cast<std::string>(TerminalType).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTerminalType = %s    [终端机类型]\n", boost::lexical_cast<std::string>(TerminalType).c_str());
	}
	if (compare(SessionID, pOriginal->SessionID) != 0)
	{
		fprintf(fp, "\t\tSessionID = %s -> %s    [终端机当前登录Session]\n", boost::lexical_cast<std::string>(pOriginal->SessionID).c_str(), boost::lexical_cast<std::string>(SessionID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tSessionID = %s    [终端机当前登录Session]\n", boost::lexical_cast<std::string>(SessionID).c_str());
	}
	if (compare(TraderRuntype, pOriginal->TraderRuntype) != 0)
	{
		fprintf(fp, "\t\tTraderRuntype = %s -> %s    [交易员运行时状态]\n", boost::lexical_cast<std::string>(pOriginal->TraderRuntype).c_str(), boost::lexical_cast<std::string>(TraderRuntype).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTraderRuntype = %s    [交易员运行时状态]\n", boost::lexical_cast<std::string>(TraderRuntype).c_str());
	}
	if (compare(TradingDay, pOriginal->TradingDay) != 0)
	{
		fprintf(fp, "\t\tTradingDay = %s -> %s    [交易日（CTP返回）]\n", boost::lexical_cast<std::string>(pOriginal->TradingDay).c_str(), boost::lexical_cast<std::string>(TradingDay).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTradingDay = %s    [交易日（CTP返回）]\n", boost::lexical_cast<std::string>(TradingDay).c_str());
	}
	if (compare(IsActive, pOriginal->IsActive) != 0)
	{
		fprintf(fp, "\t\tIsActive = %s -> %s    [交易员当前连接是否活跃]\n", boost::lexical_cast<std::string>(pOriginal->IsActive).c_str(), boost::lexical_cast<std::string>(IsActive).c_str());
	}
	else
	{
		fprintf(fp, "\t\tIsActive = %s    [交易员当前连接是否活跃]\n", boost::lexical_cast<std::string>(IsActive).c_str());
	}
	if (compare(UpdateTime, pOriginal->UpdateTime) != 0)
	{
		fprintf(fp, "\t\tUpdateTime = %s -> %s    [实体账户状态更新时间]\n", boost::lexical_cast<std::string>(pOriginal->UpdateTime).c_str(), boost::lexical_cast<std::string>(UpdateTime).c_str());
	}
	else
	{
		fprintf(fp, "\t\tUpdateTime = %s    [实体账户状态更新时间]\n", boost::lexical_cast<std::string>(UpdateTime).c_str());
	}
	if (compare(ExchLoginTime, pOriginal->ExchLoginTime) != 0)
	{
		fprintf(fp, "\t\tExchLoginTime = %s -> %s    [登录成功时间（CTP返回）]\n", boost::lexical_cast<std::string>(pOriginal->ExchLoginTime).c_str(), boost::lexical_cast<std::string>(ExchLoginTime).c_str());
	}
	else
	{
		fprintf(fp, "\t\tExchLoginTime = %s    [登录成功时间（CTP返回）]\n", boost::lexical_cast<std::string>(ExchLoginTime).c_str());
	}
	if (compare(ExchBrokerID, pOriginal->ExchBrokerID) != 0)
	{
		fprintf(fp, "\t\tExchBrokerID = %s -> %s    [经纪公司代码（CTP返回）]\n", boost::lexical_cast<std::string>(pOriginal->ExchBrokerID).c_str(), boost::lexical_cast<std::string>(ExchBrokerID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tExchBrokerID = %s    [经纪公司代码（CTP返回）]\n", boost::lexical_cast<std::string>(ExchBrokerID).c_str());
	}
	if (compare(ExchSystemName, pOriginal->ExchSystemName) != 0)
	{
		fprintf(fp, "\t\tExchSystemName = %s -> %s    [交易系统名称（CTP返回）]\n", boost::lexical_cast<std::string>(pOriginal->ExchSystemName).c_str(), boost::lexical_cast<std::string>(ExchSystemName).c_str());
	}
	else
	{
		fprintf(fp, "\t\tExchSystemName = %s    [交易系统名称（CTP返回）]\n", boost::lexical_cast<std::string>(ExchSystemName).c_str());
	}
	if (compare(ExchFrontID, pOriginal->ExchFrontID) != 0)
	{
		fprintf(fp, "\t\tExchFrontID = %s -> %s    [前置编号（CTP返回）]\n", boost::lexical_cast<std::string>(pOriginal->ExchFrontID).c_str(), boost::lexical_cast<std::string>(ExchFrontID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tExchFrontID = %s    [前置编号（CTP返回）]\n", boost::lexical_cast<std::string>(ExchFrontID).c_str());
	}
	if (compare(ExchSessionID, pOriginal->ExchSessionID) != 0)
	{
		fprintf(fp, "\t\tExchSessionID = %s -> %s    [会话编号（CTP返回）]\n", boost::lexical_cast<std::string>(pOriginal->ExchSessionID).c_str(), boost::lexical_cast<std::string>(ExchSessionID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tExchSessionID = %s    [会话编号（CTP返回）]\n", boost::lexical_cast<std::string>(ExchSessionID).c_str());
	}
	if (compare(ExchMaxOrderRef, pOriginal->ExchMaxOrderRef) != 0)
	{
		fprintf(fp, "\t\tExchMaxOrderRef = %s -> %s    [最大报单引用（CTP返回）]\n", boost::lexical_cast<std::string>(pOriginal->ExchMaxOrderRef).c_str(), boost::lexical_cast<std::string>(ExchMaxOrderRef).c_str());
	}
	else
	{
		fprintf(fp, "\t\tExchMaxOrderRef = %s    [最大报单引用（CTP返回）]\n", boost::lexical_cast<std::string>(ExchMaxOrderRef).c_str());
	}
	if (compare(ExchIsCaLogin, pOriginal->ExchIsCaLogin) != 0)
	{
		fprintf(fp, "\t\tExchIsCaLogin = %s -> %s    [是否CA认证（易盛返回）]\n", boost::lexical_cast<std::string>(pOriginal->ExchIsCaLogin).c_str(), boost::lexical_cast<std::string>(ExchIsCaLogin).c_str());
	}
	else
	{
		fprintf(fp, "\t\tExchIsCaLogin = %s    [是否CA认证（易盛返回）]\n", boost::lexical_cast<std::string>(ExchIsCaLogin).c_str());
	}
	if (compare(ExchIsForcePwd, pOriginal->ExchIsForcePwd) != 0)
	{
		fprintf(fp, "\t\tExchIsForcePwd = %s -> %s    [是否强制修改密码（易盛返回）]\n", boost::lexical_cast<std::string>(pOriginal->ExchIsForcePwd).c_str(), boost::lexical_cast<std::string>(ExchIsForcePwd).c_str());
	}
	else
	{
		fprintf(fp, "\t\tExchIsForcePwd = %s    [是否强制修改密码（易盛返回）]\n", boost::lexical_cast<std::string>(ExchIsForcePwd).c_str());
	}
	if (compare(ExchLoginName, pOriginal->ExchLoginName) != 0)
	{
		fprintf(fp, "\t\tExchLoginName = %s -> %s    [登录端帐号简称（易盛返回）]\n", boost::lexical_cast<std::string>(pOriginal->ExchLoginName).c_str(), boost::lexical_cast<std::string>(ExchLoginName).c_str());
	}
	else
	{
		fprintf(fp, "\t\tExchLoginName = %s    [登录端帐号简称（易盛返回）]\n", boost::lexical_cast<std::string>(ExchLoginName).c_str());
	}
	if (compare(ExchReservedInfo, pOriginal->ExchReservedInfo) != 0)
	{
		fprintf(fp, "\t\tExchReservedInfo = %s -> %s    [客户预留信息,客户自己识别后台系统（易盛返回）]\n", boost::lexical_cast<std::string>(pOriginal->ExchReservedInfo).c_str(), boost::lexical_cast<std::string>(ExchReservedInfo).c_str());
	}
	else
	{
		fprintf(fp, "\t\tExchReservedInfo = %s    [客户预留信息,客户自己识别后台系统（易盛返回）]\n", boost::lexical_cast<std::string>(ExchReservedInfo).c_str());
	}
	if (compare(ExchLastLoginDateTime, pOriginal->ExchLastLoginDateTime) != 0)
	{
		fprintf(fp, "\t\tExchLastLoginDateTime = %s -> %s    [上次登录时间（易盛返回）]\n", boost::lexical_cast<std::string>(pOriginal->ExchLastLoginDateTime).c_str(), boost::lexical_cast<std::string>(ExchLastLoginDateTime).c_str());
	}
	else
	{
		fprintf(fp, "\t\tExchLastLoginDateTime = %s    [上次登录时间（易盛返回）]\n", boost::lexical_cast<std::string>(ExchLastLoginDateTime).c_str());
	}
	if (compare(ExchLastLogoutDateTime, pOriginal->ExchLastLogoutDateTime) != 0)
	{
		fprintf(fp, "\t\tExchLastLogoutDateTime = %s -> %s    [上次登出时间（易盛返回）]\n", boost::lexical_cast<std::string>(pOriginal->ExchLastLogoutDateTime).c_str(), boost::lexical_cast<std::string>(ExchLastLogoutDateTime).c_str());
	}
	else
	{
		fprintf(fp, "\t\tExchLastLogoutDateTime = %s    [上次登出时间（易盛返回）]\n", boost::lexical_cast<std::string>(ExchLastLogoutDateTime).c_str());
	}
	if (compare(ExchLastLoginIp, pOriginal->ExchLastLoginIp) != 0)
	{
		fprintf(fp, "\t\tExchLastLoginIp = %s -> %s    [上次登录ip，兼容ipv6（易盛返回）]\n", boost::lexical_cast<std::string>(pOriginal->ExchLastLoginIp).c_str(), boost::lexical_cast<std::string>(ExchLastLoginIp).c_str());
	}
	else
	{
		fprintf(fp, "\t\tExchLastLoginIp = %s    [上次登录ip，兼容ipv6（易盛返回）]\n", boost::lexical_cast<std::string>(ExchLastLoginIp).c_str());
	}
	if (compare(ExchLastLoginPort, pOriginal->ExchLastLoginPort) != 0)
	{
		fprintf(fp, "\t\tExchLastLoginPort = %s -> %s    [上次登录port（易盛返回）]\n", boost::lexical_cast<std::string>(pOriginal->ExchLastLoginPort).c_str(), boost::lexical_cast<std::string>(ExchLastLoginPort).c_str());
	}
	else
	{
		fprintf(fp, "\t\tExchLastLoginPort = %s    [上次登录port（易盛返回）]\n", boost::lexical_cast<std::string>(ExchLastLoginPort).c_str());
	}
	if (compare(ExchLastLoginMachineInfo, pOriginal->ExchLastLoginMachineInfo) != 0)
	{
		fprintf(fp, "\t\tExchLastLoginMachineInfo = %s -> %s    [上次登录机器信息，主要是Mac地址（易盛返回）]\n", boost::lexical_cast<std::string>(pOriginal->ExchLastLoginMachineInfo).c_str(), boost::lexical_cast<std::string>(ExchLastLoginMachineInfo).c_str());
	}
	else
	{
		fprintf(fp, "\t\tExchLastLoginMachineInfo = %s    [上次登录机器信息，主要是Mac地址（易盛返回）]\n", boost::lexical_cast<std::string>(ExchLastLoginMachineInfo).c_str());
	}
	if (compare(ExchSHFETime, pOriginal->ExchSHFETime) != 0)
	{
		fprintf(fp, "\t\tExchSHFETime = %s -> %s    [上期所时间（CTP返回）]\n", boost::lexical_cast<std::string>(pOriginal->ExchSHFETime).c_str(), boost::lexical_cast<std::string>(ExchSHFETime).c_str());
	}
	else
	{
		fprintf(fp, "\t\tExchSHFETime = %s    [上期所时间（CTP返回）]\n", boost::lexical_cast<std::string>(ExchSHFETime).c_str());
	}
	if (compare(ExchDCETime, pOriginal->ExchDCETime) != 0)
	{
		fprintf(fp, "\t\tExchDCETime = %s -> %s    [大商所时间（CTP返回）]\n", boost::lexical_cast<std::string>(pOriginal->ExchDCETime).c_str(), boost::lexical_cast<std::string>(ExchDCETime).c_str());
	}
	else
	{
		fprintf(fp, "\t\tExchDCETime = %s    [大商所时间（CTP返回）]\n", boost::lexical_cast<std::string>(ExchDCETime).c_str());
	}
	if (compare(ExchCZCETime, pOriginal->ExchCZCETime) != 0)
	{
		fprintf(fp, "\t\tExchCZCETime = %s -> %s    [郑商所时间（CTP返回）]\n", boost::lexical_cast<std::string>(pOriginal->ExchCZCETime).c_str(), boost::lexical_cast<std::string>(ExchCZCETime).c_str());
	}
	else
	{
		fprintf(fp, "\t\tExchCZCETime = %s    [郑商所时间（CTP返回）]\n", boost::lexical_cast<std::string>(ExchCZCETime).c_str());
	}
	if (compare(ExchFFEXTime, pOriginal->ExchFFEXTime) != 0)
	{
		fprintf(fp, "\t\tExchFFEXTime = %s -> %s    [中金所时间（CTP返回）]\n", boost::lexical_cast<std::string>(pOriginal->ExchFFEXTime).c_str(), boost::lexical_cast<std::string>(ExchFFEXTime).c_str());
	}
	else
	{
		fprintf(fp, "\t\tExchFFEXTime = %s    [中金所时间（CTP返回）]\n", boost::lexical_cast<std::string>(ExchFFEXTime).c_str());
	}
	if (compare(ExchServerDateTime, pOriginal->ExchServerDateTime) != 0)
	{
		fprintf(fp, "\t\tExchServerDateTime = %s -> %s    [系统当前时间(客户端校时，易盛返回）]\n", boost::lexical_cast<std::string>(pOriginal->ExchServerDateTime).c_str(), boost::lexical_cast<std::string>(ExchServerDateTime).c_str());
	}
	else
	{
		fprintf(fp, "\t\tExchServerDateTime = %s    [系统当前时间(客户端校时，易盛返回）]\n", boost::lexical_cast<std::string>(ExchServerDateTime).c_str());
	}
	if (compare(ErrorID, pOriginal->ErrorID) != 0)
	{
		fprintf(fp, "\t\tErrorID = %s -> %s    [错误代码]\n", boost::lexical_cast<std::string>(pOriginal->ErrorID).c_str(), boost::lexical_cast<std::string>(ErrorID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tErrorID = %s    [错误代码]\n", boost::lexical_cast<std::string>(ErrorID).c_str());
	}
	if (compare(ErrorMsg, pOriginal->ErrorMsg) != 0)
	{
		fprintf(fp, "\t\tErrorMsg = %s -> %s    [错误信息]\n", boost::lexical_cast<std::string>(pOriginal->ErrorMsg).c_str(), boost::lexical_cast<std::string>(ErrorMsg).c_str());
	}
	else
	{
		fprintf(fp, "\t\tErrorMsg = %s    [错误信息]\n", boost::lexical_cast<std::string>(ErrorMsg).c_str());
	}
	fprintf(fp, "\t}\n");
}

void CTraderLoginLog::dumpInLine(FILE *fp) const
{
	if (fp == nullptr)
	{
		fp = stdout;
	}
	std::stringstream sbuf;

	sbuf << ",TraderID," << TraderID;
	sbuf << ",AppType," << AppType;
	sbuf << ",TerminalID," << TerminalID;
	sbuf << ",TerminalType," << TerminalType;
	sbuf << ",SessionID," << SessionID;
	sbuf << ",TraderRuntype," << TraderRuntype;
	sbuf << ",TradingDay," << TradingDay;
	sbuf << ",IsActive," << IsActive;
	sbuf << ",UpdateTime," << UpdateTime;
	sbuf << ",ExchLoginTime," << ExchLoginTime;
	sbuf << ",ExchBrokerID," << ExchBrokerID;
	sbuf << ",ExchSystemName," << ExchSystemName;
	sbuf << ",ExchFrontID," << ExchFrontID;
	sbuf << ",ExchSessionID," << ExchSessionID;
	sbuf << ",ExchMaxOrderRef," << ExchMaxOrderRef;
	sbuf << ",ExchIsCaLogin," << ExchIsCaLogin;
	sbuf << ",ExchIsForcePwd," << ExchIsForcePwd;
	sbuf << ",ExchLoginName," << ExchLoginName;
	sbuf << ",ExchReservedInfo," << ExchReservedInfo;
	sbuf << ",ExchLastLoginDateTime," << ExchLastLoginDateTime;
	sbuf << ",ExchLastLogoutDateTime," << ExchLastLogoutDateTime;
	sbuf << ",ExchLastLoginIp," << ExchLastLoginIp;
	sbuf << ",ExchLastLoginPort," << ExchLastLoginPort;
	sbuf << ",ExchLastLoginMachineInfo," << ExchLastLoginMachineInfo;
	sbuf << ",ExchSHFETime," << ExchSHFETime;
	sbuf << ",ExchDCETime," << ExchDCETime;
	sbuf << ",ExchCZCETime," << ExchCZCETime;
	sbuf << ",ExchFFEXTime," << ExchFFEXTime;
	sbuf << ",ExchServerDateTime," << ExchServerDateTime;
	sbuf << ",ErrorID," << ErrorID;
	sbuf << ",ErrorMsg," << ErrorMsg;
	fprintf(fp, "%s", sbuf.str().c_str());
}

void CTraderLoginLog::dumpString(char *target) const
{
	char *p = target;
	std::stringstream sbuf;

	sbuf << "TraderID=" << TraderID << ",";
	sbuf << "AppType=" << AppType << ",";
	sbuf << "TerminalID=" << TerminalID << ",";
	sbuf << "TerminalType=" << TerminalType << ",";
	sbuf << "SessionID=" << SessionID << ",";
	sbuf << "TraderRuntype=" << TraderRuntype << ",";
	sbuf << "TradingDay=" << TradingDay << ",";
	sbuf << "IsActive=" << IsActive << ",";
	sbuf << "UpdateTime=" << UpdateTime << ",";
	sbuf << "ExchLoginTime=" << ExchLoginTime << ",";
	sbuf << "ExchBrokerID=" << ExchBrokerID << ",";
	sbuf << "ExchSystemName=" << ExchSystemName << ",";
	sbuf << "ExchFrontID=" << ExchFrontID << ",";
	sbuf << "ExchSessionID=" << ExchSessionID << ",";
	sbuf << "ExchMaxOrderRef=" << ExchMaxOrderRef << ",";
	sbuf << "ExchIsCaLogin=" << ExchIsCaLogin << ",";
	sbuf << "ExchIsForcePwd=" << ExchIsForcePwd << ",";
	sbuf << "ExchLoginName=" << ExchLoginName << ",";
	sbuf << "ExchReservedInfo=" << ExchReservedInfo << ",";
	sbuf << "ExchLastLoginDateTime=" << ExchLastLoginDateTime << ",";
	sbuf << "ExchLastLogoutDateTime=" << ExchLastLogoutDateTime << ",";
	sbuf << "ExchLastLoginIp=" << ExchLastLoginIp << ",";
	sbuf << "ExchLastLoginPort=" << ExchLastLoginPort << ",";
	sbuf << "ExchLastLoginMachineInfo=" << ExchLastLoginMachineInfo << ",";
	sbuf << "ExchSHFETime=" << ExchSHFETime << ",";
	sbuf << "ExchDCETime=" << ExchDCETime << ",";
	sbuf << "ExchCZCETime=" << ExchCZCETime << ",";
	sbuf << "ExchFFEXTime=" << ExchFFEXTime << ",";
	sbuf << "ExchServerDateTime=" << ExchServerDateTime << ",";
	sbuf << "ErrorID=" << ErrorID << ",";
	sbuf << "ErrorMsg=" << ErrorMsg << ",";

	sprintf(p, "%s", sbuf.str().c_str());
}

void CTraderConnect::init(void)
{
	memset(this, 0, sizeof(CTraderConnect));
}

int CTraderConnect::read(FILE *input)
{
	if (fread(this, 1, sizeof(CTraderConnect), input) != sizeof(CTraderConnect))
		return 0;
	else
		return 1;
}

int CTraderConnect::write(FILE *output) const
{
	if (fwrite(this, 1, sizeof(CTraderConnect), output) != sizeof(CTraderConnect))
		return 0;
	else
		return 1;
}

void CTraderConnect::dump(FILE *fp, int index) const
{
	char index_buf[64];
	if (fp == nullptr)
	{
		fp = stdout;
	}
	if (index >= 0)
		sprintf(index_buf, "[%d]", index);
	else
		index_buf[0] = '\0';
	fprintf(fp, "\tCTraderConnect%s = {\n", index_buf);
	fprintf(fp, "\t\tTraderID = %s    [用户代码（CTP返回的UserID，易盛返回的是LoginNo）]\n", boost::lexical_cast<std::string>(TraderID).c_str());
	fprintf(fp, "\t\tAppType = %s    [交易接口类型]\n", boost::lexical_cast<std::string>(AppType).c_str());
	fprintf(fp, "\t\tTerminalID = %s    [终端机编号]\n", boost::lexical_cast<std::string>(TerminalID).c_str());
	fprintf(fp, "\t\tTerminalType = %s    [终端机类型]\n", boost::lexical_cast<std::string>(TerminalType).c_str());
	fprintf(fp, "\t\tSessionID = %s    [终端机当前登录Session]\n", boost::lexical_cast<std::string>(SessionID).c_str());
	fprintf(fp, "\t\tTraderRuntype = %s    [交易员运行时状态]\n", boost::lexical_cast<std::string>(TraderRuntype).c_str());
	fprintf(fp, "\t\tTradingDay = %s    [交易日（CTP返回）]\n", boost::lexical_cast<std::string>(TradingDay).c_str());
	fprintf(fp, "\t\tIsActive = %s    [交易员当前连接是否活跃]\n", boost::lexical_cast<std::string>(IsActive).c_str());
	fprintf(fp, "\t\tUpdateTime = %s    [实体账户状态更新时间]\n", boost::lexical_cast<std::string>(UpdateTime).c_str());
	fprintf(fp, "\t}\n");
}

void CTraderConnect::dumpDiff(FILE *fp, const CTraderConnect *pOriginal) const
{
	if (fp == nullptr)
	{
		fp = stdout;
	}
	fprintf(fp, "\tCTraderConnect = {\n");
	if (compare(TraderID, pOriginal->TraderID) != 0)
	{
		fprintf(fp, "\t\tTraderID = %s -> %s    [用户代码（CTP返回的UserID，易盛返回的是LoginNo）]\n", boost::lexical_cast<std::string>(pOriginal->TraderID).c_str(), boost::lexical_cast<std::string>(TraderID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTraderID = %s    [用户代码（CTP返回的UserID，易盛返回的是LoginNo）]\n", boost::lexical_cast<std::string>(TraderID).c_str());
	}
	if (compare(AppType, pOriginal->AppType) != 0)
	{
		fprintf(fp, "\t\tAppType = %s -> %s    [交易接口类型]\n", boost::lexical_cast<std::string>(pOriginal->AppType).c_str(), boost::lexical_cast<std::string>(AppType).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAppType = %s    [交易接口类型]\n", boost::lexical_cast<std::string>(AppType).c_str());
	}
	if (compare(TerminalID, pOriginal->TerminalID) != 0)
	{
		fprintf(fp, "\t\tTerminalID = %s -> %s    [终端机编号]\n", boost::lexical_cast<std::string>(pOriginal->TerminalID).c_str(), boost::lexical_cast<std::string>(TerminalID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTerminalID = %s    [终端机编号]\n", boost::lexical_cast<std::string>(TerminalID).c_str());
	}
	if (compare(TerminalType, pOriginal->TerminalType) != 0)
	{
		fprintf(fp, "\t\tTerminalType = %s -> %s    [终端机类型]\n", boost::lexical_cast<std::string>(pOriginal->TerminalType).c_str(), boost::lexical_cast<std::string>(TerminalType).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTerminalType = %s    [终端机类型]\n", boost::lexical_cast<std::string>(TerminalType).c_str());
	}
	if (compare(SessionID, pOriginal->SessionID) != 0)
	{
		fprintf(fp, "\t\tSessionID = %s -> %s    [终端机当前登录Session]\n", boost::lexical_cast<std::string>(pOriginal->SessionID).c_str(), boost::lexical_cast<std::string>(SessionID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tSessionID = %s    [终端机当前登录Session]\n", boost::lexical_cast<std::string>(SessionID).c_str());
	}
	if (compare(TraderRuntype, pOriginal->TraderRuntype) != 0)
	{
		fprintf(fp, "\t\tTraderRuntype = %s -> %s    [交易员运行时状态]\n", boost::lexical_cast<std::string>(pOriginal->TraderRuntype).c_str(), boost::lexical_cast<std::string>(TraderRuntype).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTraderRuntype = %s    [交易员运行时状态]\n", boost::lexical_cast<std::string>(TraderRuntype).c_str());
	}
	if (compare(TradingDay, pOriginal->TradingDay) != 0)
	{
		fprintf(fp, "\t\tTradingDay = %s -> %s    [交易日（CTP返回）]\n", boost::lexical_cast<std::string>(pOriginal->TradingDay).c_str(), boost::lexical_cast<std::string>(TradingDay).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTradingDay = %s    [交易日（CTP返回）]\n", boost::lexical_cast<std::string>(TradingDay).c_str());
	}
	if (compare(IsActive, pOriginal->IsActive) != 0)
	{
		fprintf(fp, "\t\tIsActive = %s -> %s    [交易员当前连接是否活跃]\n", boost::lexical_cast<std::string>(pOriginal->IsActive).c_str(), boost::lexical_cast<std::string>(IsActive).c_str());
	}
	else
	{
		fprintf(fp, "\t\tIsActive = %s    [交易员当前连接是否活跃]\n", boost::lexical_cast<std::string>(IsActive).c_str());
	}
	if (compare(UpdateTime, pOriginal->UpdateTime) != 0)
	{
		fprintf(fp, "\t\tUpdateTime = %s -> %s    [实体账户状态更新时间]\n", boost::lexical_cast<std::string>(pOriginal->UpdateTime).c_str(), boost::lexical_cast<std::string>(UpdateTime).c_str());
	}
	else
	{
		fprintf(fp, "\t\tUpdateTime = %s    [实体账户状态更新时间]\n", boost::lexical_cast<std::string>(UpdateTime).c_str());
	}
	fprintf(fp, "\t}\n");
}

void CTraderConnect::dumpInLine(FILE *fp) const
{
	if (fp == nullptr)
	{
		fp = stdout;
	}
	std::stringstream sbuf;

	sbuf << ",TraderID," << TraderID;
	sbuf << ",AppType," << AppType;
	sbuf << ",TerminalID," << TerminalID;
	sbuf << ",TerminalType," << TerminalType;
	sbuf << ",SessionID," << SessionID;
	sbuf << ",TraderRuntype," << TraderRuntype;
	sbuf << ",TradingDay," << TradingDay;
	sbuf << ",IsActive," << IsActive;
	sbuf << ",UpdateTime," << UpdateTime;
	fprintf(fp, "%s", sbuf.str().c_str());
}

void CTraderConnect::dumpString(char *target) const
{
	char *p = target;
	std::stringstream sbuf;

	sbuf << "TraderID=" << TraderID << ",";
	sbuf << "AppType=" << AppType << ",";
	sbuf << "TerminalID=" << TerminalID << ",";
	sbuf << "TerminalType=" << TerminalType << ",";
	sbuf << "SessionID=" << SessionID << ",";
	sbuf << "TraderRuntype=" << TraderRuntype << ",";
	sbuf << "TradingDay=" << TradingDay << ",";
	sbuf << "IsActive=" << IsActive << ",";
	sbuf << "UpdateTime=" << UpdateTime << ",";

	sprintf(p, "%s", sbuf.str().c_str());
}

void CTraderCertInfo::init(void)
{
	memset(this, 0, sizeof(CTraderCertInfo));
}

int CTraderCertInfo::read(FILE *input)
{
	if (fread(this, 1, sizeof(CTraderCertInfo), input) != sizeof(CTraderCertInfo))
		return 0;
	else
		return 1;
}

int CTraderCertInfo::write(FILE *output) const
{
	if (fwrite(this, 1, sizeof(CTraderCertInfo), output) != sizeof(CTraderCertInfo))
		return 0;
	else
		return 1;
}

void CTraderCertInfo::dump(FILE *fp, int index) const
{
	char index_buf[64];
	if (fp == nullptr)
	{
		fp = stdout;
	}
	if (index >= 0)
		sprintf(index_buf, "[%d]", index);
	else
		index_buf[0] = '\0';
	fprintf(fp, "\tCTraderCertInfo%s = {\n", index_buf);
	fprintf(fp, "\t\tTraderID = %s    [交易员代码]\n", boost::lexical_cast<std::string>(TraderID).c_str());
	fprintf(fp, "\t\tAppType = %s    [交易接口类型]\n", boost::lexical_cast<std::string>(AppType).c_str());
	fprintf(fp, "\t\tTerminalType = %s    [交易员登录身份]\n", boost::lexical_cast<std::string>(TerminalType).c_str());
	fprintf(fp, "\t\tCertInfo = %s    [认证信息]\n", boost::lexical_cast<std::string>(CertInfo).c_str());
	fprintf(fp, "\t\tSecretKey = %s    [API密钥]\n", boost::lexical_cast<std::string>(SecretKey).c_str());
	fprintf(fp, "\t\tIsOption = %s    [是否订阅期权]\n", boost::lexical_cast<std::string>(IsOption).c_str());
	fprintf(fp, "\t\tAppID = %s    [客户端产品信息]\n", boost::lexical_cast<std::string>(AppID).c_str());
	fprintf(fp, "\t}\n");
}

void CTraderCertInfo::dumpDiff(FILE *fp, const CTraderCertInfo *pOriginal) const
{
	if (fp == nullptr)
	{
		fp = stdout;
	}
	fprintf(fp, "\tCTraderCertInfo = {\n");
	if (compare(TraderID, pOriginal->TraderID) != 0)
	{
		fprintf(fp, "\t\tTraderID = %s -> %s    [交易员代码]\n", boost::lexical_cast<std::string>(pOriginal->TraderID).c_str(), boost::lexical_cast<std::string>(TraderID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTraderID = %s    [交易员代码]\n", boost::lexical_cast<std::string>(TraderID).c_str());
	}
	if (compare(AppType, pOriginal->AppType) != 0)
	{
		fprintf(fp, "\t\tAppType = %s -> %s    [交易接口类型]\n", boost::lexical_cast<std::string>(pOriginal->AppType).c_str(), boost::lexical_cast<std::string>(AppType).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAppType = %s    [交易接口类型]\n", boost::lexical_cast<std::string>(AppType).c_str());
	}
	if (compare(TerminalType, pOriginal->TerminalType) != 0)
	{
		fprintf(fp, "\t\tTerminalType = %s -> %s    [交易员登录身份]\n", boost::lexical_cast<std::string>(pOriginal->TerminalType).c_str(), boost::lexical_cast<std::string>(TerminalType).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTerminalType = %s    [交易员登录身份]\n", boost::lexical_cast<std::string>(TerminalType).c_str());
	}
	if (compare(CertInfo, pOriginal->CertInfo) != 0)
	{
		fprintf(fp, "\t\tCertInfo = %s -> %s    [认证信息]\n", boost::lexical_cast<std::string>(pOriginal->CertInfo).c_str(), boost::lexical_cast<std::string>(CertInfo).c_str());
	}
	else
	{
		fprintf(fp, "\t\tCertInfo = %s    [认证信息]\n", boost::lexical_cast<std::string>(CertInfo).c_str());
	}
	if (compare(SecretKey, pOriginal->SecretKey) != 0)
	{
		fprintf(fp, "\t\tSecretKey = %s -> %s    [API密钥]\n", boost::lexical_cast<std::string>(pOriginal->SecretKey).c_str(), boost::lexical_cast<std::string>(SecretKey).c_str());
	}
	else
	{
		fprintf(fp, "\t\tSecretKey = %s    [API密钥]\n", boost::lexical_cast<std::string>(SecretKey).c_str());
	}
	if (compare(IsOption, pOriginal->IsOption) != 0)
	{
		fprintf(fp, "\t\tIsOption = %s -> %s    [是否订阅期权]\n", boost::lexical_cast<std::string>(pOriginal->IsOption).c_str(), boost::lexical_cast<std::string>(IsOption).c_str());
	}
	else
	{
		fprintf(fp, "\t\tIsOption = %s    [是否订阅期权]\n", boost::lexical_cast<std::string>(IsOption).c_str());
	}
	if (compare(AppID, pOriginal->AppID) != 0)
	{
		fprintf(fp, "\t\tAppID = %s -> %s    [客户端产品信息]\n", boost::lexical_cast<std::string>(pOriginal->AppID).c_str(), boost::lexical_cast<std::string>(AppID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAppID = %s    [客户端产品信息]\n", boost::lexical_cast<std::string>(AppID).c_str());
	}
	fprintf(fp, "\t}\n");
}

void CTraderCertInfo::dumpInLine(FILE *fp) const
{
	if (fp == nullptr)
	{
		fp = stdout;
	}
	std::stringstream sbuf;

	sbuf << ",TraderID," << TraderID;
	sbuf << ",AppType," << AppType;
	sbuf << ",TerminalType," << TerminalType;
	sbuf << ",CertInfo," << CertInfo;
	sbuf << ",SecretKey," << SecretKey;
	sbuf << ",IsOption," << IsOption;
	sbuf << ",AppID," << AppID;
	fprintf(fp, "%s", sbuf.str().c_str());
}

void CTraderCertInfo::dumpString(char *target) const
{
	char *p = target;
	std::stringstream sbuf;

	sbuf << "TraderID=" << TraderID << ",";
	sbuf << "AppType=" << AppType << ",";
	sbuf << "TerminalType=" << TerminalType << ",";
	sbuf << "CertInfo=" << CertInfo << ",";
	sbuf << "SecretKey=" << SecretKey << ",";
	sbuf << "IsOption=" << IsOption << ",";
	sbuf << "AppID=" << AppID << ",";

	sprintf(p, "%s", sbuf.str().c_str());
}

void CUser::init(void)
{
	memset(this, 0, sizeof(CUser));
}

int CUser::read(FILE *input)
{
	if (fread(this, 1, sizeof(CUser), input) != sizeof(CUser))
		return 0;
	else
		return 1;
}

int CUser::write(FILE *output) const
{
	if (fwrite(this, 1, sizeof(CUser), output) != sizeof(CUser))
		return 0;
	else
		return 1;
}

void CUser::dump(FILE *fp, int index) const
{
	char index_buf[64];
	if (fp == nullptr)
	{
		fp = stdout;
	}
	if (index >= 0)
		sprintf(index_buf, "[%d]", index);
	else
		index_buf[0] = '\0';
	fprintf(fp, "\tCUser%s = {\n", index_buf);
	fprintf(fp, "\t\tUserID = %s    [用户代码]\n", boost::lexical_cast<std::string>(UserID).c_str());
	fprintf(fp, "\t\tUserGroupID = %s    [用户所在组代码]\n", boost::lexical_cast<std::string>(UserGroupID).c_str());
	fprintf(fp, "\t\tUserName = %s    [用户名称]\n", boost::lexical_cast<std::string>(UserName).c_str());
	fprintf(fp, "\t\tUserType = %s    [用户类型]\n", boost::lexical_cast<std::string>(UserType).c_str());
	fprintf(fp, "\t\tPassword = %s    [密码]\n", boost::lexical_cast<std::string>(Password).c_str());
	fprintf(fp, "\t\tUserStatus = %s    [用户状态]\n", boost::lexical_cast<std::string>(UserStatus).c_str());
	fprintf(fp, "\t\tTradeRight = %s    [交易员权限]\n", boost::lexical_cast<std::string>(TradeRight).c_str());
	fprintf(fp, "\t\tIsActive = %s    [是否活跃]\n", boost::lexical_cast<std::string>(IsActive).c_str());
	fprintf(fp, "\t}\n");
}

void CUser::dumpDiff(FILE *fp, const CUser *pOriginal) const
{
	if (fp == NULL)
	{
		fp = stdout;
	}
	fprintf(fp, "\tCUser = {\n");
	if (compare(UserID, pOriginal->UserID) != 0)
	{
		fprintf(fp, "\t\tUserID = %s -> %s    [用户代码]\n", boost::lexical_cast<std::string>(pOriginal->UserID).c_str(), boost::lexical_cast<std::string>(UserID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tUserID = %s    [用户代码]\n", boost::lexical_cast<std::string>(UserID).c_str());
	}
	if (compare(UserGroupID, pOriginal->UserGroupID) != 0)
	{
		fprintf(fp, "\t\tUserGroupID = %s -> %s    [用户所在组代码]\n", boost::lexical_cast<std::string>(pOriginal->UserGroupID).c_str(), boost::lexical_cast<std::string>(UserGroupID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tUserGroupID = %s    [用户所在组代码]\n", boost::lexical_cast<std::string>(UserGroupID).c_str());
	}
	if (compare(UserName, pOriginal->UserName) != 0)
	{
		fprintf(fp, "\t\tUserName = %s -> %s    [用户名称]\n", boost::lexical_cast<std::string>(pOriginal->UserName).c_str(), boost::lexical_cast<std::string>(UserName).c_str());
	}
	else
	{
		fprintf(fp, "\t\tUserName = %s    [用户名称]\n", boost::lexical_cast<std::string>(UserName).c_str());
	}
	if (compare(UserType, pOriginal->UserType) != 0)
	{
		fprintf(fp, "\t\tUserType = %s -> %s    [用户类型]\n", boost::lexical_cast<std::string>(pOriginal->UserType).c_str(), boost::lexical_cast<std::string>(UserType).c_str());
	}
	else
	{
		fprintf(fp, "\t\tUserType = %s    [用户类型]\n", boost::lexical_cast<std::string>(UserType).c_str());
	}
	if (compare(Password, pOriginal->Password) != 0)
	{
		fprintf(fp, "\t\tPassword = %s -> %s    [密码]\n", boost::lexical_cast<std::string>(pOriginal->Password).c_str(), boost::lexical_cast<std::string>(Password).c_str());
	}
	else
	{
		fprintf(fp, "\t\tPassword = %s    [密码]\n", boost::lexical_cast<std::string>(Password).c_str());
	}
	if (compare(UserStatus, pOriginal->UserStatus) != 0)
	{
		fprintf(fp, "\t\tUserStatus = %s -> %s    [用户状态]\n", boost::lexical_cast<std::string>(pOriginal->UserStatus).c_str(), boost::lexical_cast<std::string>(UserStatus).c_str());
	}
	else
	{
		fprintf(fp, "\t\tUserStatus = %s    [用户状态]\n", boost::lexical_cast<std::string>(UserStatus).c_str());
	}
	if (compare(TradeRight, pOriginal->TradeRight) != 0)
	{
		fprintf(fp, "\t\tTradeRight = %s -> %s    [交易员权限]\n", boost::lexical_cast<std::string>(pOriginal->TradeRight).c_str(), boost::lexical_cast<std::string>(TradeRight).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTradeRight = %s    [交易员权限]\n", boost::lexical_cast<std::string>(TradeRight).c_str());
	}
	if (compare(IsActive, pOriginal->IsActive) != 0)
	{
		fprintf(fp, "\t\tIsActive = %s -> %s    [是否活跃]\n", boost::lexical_cast<std::string>(pOriginal->IsActive).c_str(), boost::lexical_cast<std::string>(IsActive).c_str());
	}
	else
	{
		fprintf(fp, "\t\tIsActive = %s    [是否活跃]\n", boost::lexical_cast<std::string>(IsActive).c_str());
	}
	fprintf(fp, "\t}\n");
}

void CUser::dumpInLine(FILE *fp) const
{
	if (fp == nullptr)
	{
		fp = stdout;
	}
	std::stringstream sbuf;

	sbuf << ",UserID," << UserID;
	sbuf << ",UserGroupID," << UserGroupID;
	sbuf << ",UserName," << UserName;
	sbuf << ",UserType," << UserType;
	sbuf << ",Password," << Password;
	sbuf << ",UserStatus," << UserStatus;
	sbuf << ",TradeRight," << TradeRight;
	sbuf << ",IsActive," << IsActive;
	fprintf(fp, "%s", sbuf.str().c_str());
}

void CUser::dumpString(char *target) const
{
	char *p = target;
	std::stringstream sbuf;

	sbuf << "UserID=" << UserID << ",";
	sbuf << "UserGroupID=" << UserGroupID << ",";
	sbuf << "UserName=" << UserName << ",";
	sbuf << "UserType=" << UserType << ",";
	sbuf << "Password=" << Password << ",";
	sbuf << "UserStatus=" << UserStatus << ",";
	sbuf << "TradeRight=" << TradeRight << ",";
	sbuf << "IsActive=" << IsActive << ",";

	sprintf(p, "%s", sbuf.str().c_str());
}