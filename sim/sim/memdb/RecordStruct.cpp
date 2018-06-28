#ifdef _WIN32
#pragma warning(disable:4996)
#endif

#include "RecordStruct.h"
#include <boost/lexical_cast.hpp>
#include "../utility/compare.h"

//-------------------------------------------------------------
/* Ӧ��ҵ��FieldID ��̬��Ա�ĳ�ʼ�� */
REGISTER_FIELD(REC_ID_CurrentTime, CWriteableCurrentTime, "");
REGISTER_FIELD(REC_ID_Terminal, CWriteableTerminal, "");
REGISTER_FIELD(REC_ID_Front, CWriteableFront, "");
REGISTER_FIELD(REC_ID_Trader, CWriteableTrader, "");
REGISTER_FIELD(REC_ID_TraderParalle, CWriteableTraderParalle, "");
REGISTER_FIELD(REC_ID_TraderLoginLog, CWriteableTraderLoginLog, "");
REGISTER_FIELD(REC_ID_TraderConnect, CWriteableTraderConnect, "");
REGISTER_FIELD(REC_ID_TraderCertInfo, CWriteableTraderCertInfo, "");
REGISTER_FIELD(REC_ID_User, CWriteableUser, "");
REGISTER_FIELD(REC_ID_UserTrader, CWriteableUserTrader, "");
REGISTER_FIELD(REC_ID_UserFunctionRight, CWriteableUserFunctionRight, "");
REGISTER_FIELD(REC_ID_SysInfo, CWriteableSysInfo, "");
REGISTER_FIELD(REC_ID_UserSession, CWriteableUserSession, "");
REGISTER_FIELD(REC_ID_MDSession, CWriteableMDSession, "");
REGISTER_FIELD(REC_ID_MaxLocalID, CWriteableMaxLocalID, "");
REGISTER_FIELD(REC_ID_UserSubMarketData, CWriteableUserSubMarketData, "");
REGISTER_FIELD(REC_ID_DepthMarketData, CWriteableDepthMarketData, "");
REGISTER_FIELD(REC_ID_Commodity, CWriteableCommodity, "");
REGISTER_FIELD(REC_ID_Instrument, CWriteableInstrument, "");
REGISTER_FIELD(REC_ID_OrderAction, CWriteableOrderAction, "");
REGISTER_FIELD(REC_ID_ExchOrderAction, CWriteableExchOrderAction, "");
REGISTER_FIELD(REC_ID_Order, CWriteableOrder, "");
REGISTER_FIELD(REC_ID_Trade, CWriteableTrade, "");
REGISTER_FIELD(REC_ID_EsfInstPartInfo, CWriteableEsfInstPartInfo, "");
REGISTER_FIELD(REC_ID_Currency, CWriteableCurrency, "");
REGISTER_FIELD(REC_ID_ExchUserLogin, CWriteableExchUserLogin, "");
REGISTER_FIELD(REC_ID_ExchUserLogout, CWriteableExchUserLogout, "");
REGISTER_FIELD(REC_ID_ExchMDUserLogin, CWriteableExchMDUserLogin, "");
REGISTER_FIELD(REC_ID_ExchMDUserLogout, CWriteableExchMDUserLogout, "");
REGISTER_FIELD(REC_ID_ExchOrder, CWriteableExchOrder, "");
REGISTER_FIELD(REC_ID_ExchTrade, CWriteableExchTrade, "");
REGISTER_FIELD(REC_ID_ExchInvestorPosition, CWriteableExchInvestorPosition, "");
REGISTER_FIELD(REC_ID_ExchInvestorAccount, CWriteableExchInvestorAccount, "");
REGISTER_FIELD(REC_ID_ExchDepthMarketData, CWriteableExchDepthMarketData, "");
REGISTER_FIELD(REC_ID_ExchDepthMarketHistoryData, CWriteableExchDepthMarketHistoryData, "");
REGISTER_FIELD(REC_ID_ExchInstrument, CWriteableExchInstrument, "");
REGISTER_FIELD(REC_ID_ExchInstrumentStatus, CWriteableExchInstrumentStatus, "");
REGISTER_FIELD(REC_ID_PhyAccount, CWriteablePhyAccount, "");
REGISTER_FIELD(REC_ID_InvestorPosition, CWriteableInvestorPosition, "");
REGISTER_FIELD(REC_ID_RuleInfo, CWriteableRuleInfo, "");
REGISTER_FIELD(REC_ID_ExchInvestorFee, CWriteableExchInvestorFee, "");
REGISTER_FIELD(REC_ID_ExchInvestorMargin, CWriteableExchInvestorMargin, "");
//--------------------------------------------------------------


/////////////////////////////////////////////////////////////////////////////////////////////
//��ʼ�������������е��ֶ����
void CCurrentTime::init()
{
	memset(this, 0, sizeof(CCurrentTime));
}

//���ļ�����
int CCurrentTime::read(FILE* input)
{
	if (fread(this, 1, sizeof(CCurrentTime), input) != sizeof(CCurrentTime))
		return 0;
	else
		return 1;
}

//���ļ�д��
int CCurrentTime::write(FILE* output) const
{
	if (fwrite(this, 1, sizeof(CCurrentTime), output) != sizeof(CCurrentTime))
		return 0;
	else
		return 1;
}

//������д���ļ���,����DEBUG
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
	fprintf(fp, "\t\tCurrDate = %s    [��ǰ����]\n", boost::lexical_cast<std::string>(CurrDate).c_str());
	fprintf(fp, "\t\tCurrTime = %s    [��ǰʱ��]\n", boost::lexical_cast<std::string>(CurrTime).c_str());
	fprintf(fp, "\t\tCurrMillisec = %s    [��ǰʱ�䣨���룩]\n", boost::lexical_cast<std::string>(CurrMillisec).c_str());
	fprintf(fp, "\t\tActionDay = %s    [ҵ������]\n", boost::lexical_cast<std::string>(ActionDay).c_str());
	fprintf(fp, "\t\tOldTime = %s    [ԭ��ʱ��]\n", boost::lexical_cast<std::string>(OldTime).c_str());
	fprintf(fp, "\t\tOldMillisec = %s    [ԭ��ʱ�䣨���룩]\n", boost::lexical_cast<std::string>(OldMillisec).c_str());
	fprintf(fp, "\t}\n");
}

//������д���ļ���ͻ����ʾ�仯������
void CCurrentTime::dumpDiff(FILE *fp, const CCurrentTime *pOriginal) const
{
	if (fp == NULL)
	{
		fp = stdout;
	}

	fprintf(fp, "\tCCurrentTime = {\n");
	if (compare(CurrDate, pOriginal->CurrDate) != 0)
	{
		fprintf(fp, "\t\tCurrDate = %s -> %s    [��ǰ����]\n", boost::lexical_cast<std::string>(pOriginal->CurrDate).c_str(), boost::lexical_cast<std::string>(CurrDate).c_str());
	}
	else
	{
		fprintf(fp, "\t\tCurrDate = %s    [��ǰ����]\n", boost::lexical_cast<std::string>(CurrDate).c_str());
	}

	if (compare(CurrTime, pOriginal->CurrTime) != 0)
	{
		fprintf(fp, "\t\tCurrTime = %s -> %s    [��ǰʱ��]\n", boost::lexical_cast<std::string>(pOriginal->CurrTime).c_str(), boost::lexical_cast<std::string>(CurrTime).c_str());
	}
	else
	{
		fprintf(fp, "\t\tCurrTime = %s    [��ǰʱ��]\n", boost::lexical_cast<std::string>(CurrTime).c_str());
	}

	if (compare(CurrMillisec, pOriginal->CurrMillisec) != 0)
	{
		fprintf(fp, "\t\tCurrMillisec = %s -> %s    [��ǰʱ�䣨���룩]\n", boost::lexical_cast<std::string>(pOriginal->CurrMillisec).c_str(), boost::lexical_cast<std::string>(CurrMillisec).c_str());
	}
	else
	{
		fprintf(fp, "\t\tCurrMillisec = %s    [��ǰʱ�䣨���룩]\n", boost::lexical_cast<std::string>(CurrMillisec).c_str());
	}

	if (compare(ActionDay, pOriginal->ActionDay) != 0)
	{
		fprintf(fp, "\t\tActionDay = %s -> %s    [ҵ������]\n", boost::lexical_cast<std::string>(pOriginal->ActionDay).c_str(), boost::lexical_cast<std::string>(ActionDay).c_str());
	}
	else
	{
		fprintf(fp, "\t\tActionDay = %s    [ҵ������]\n", boost::lexical_cast<std::string>(ActionDay).c_str());
	}

	if (compare(OldTime, pOriginal->OldTime) != 0)
	{
		fprintf(fp, "\t\tOldTime = %s -> %s    [ԭ��ʱ��]\n", boost::lexical_cast<std::string>(pOriginal->OldTime).c_str(), boost::lexical_cast<std::string>(OldTime).c_str());
	}
	else
	{
		fprintf(fp, "\t\tOldTime = %s    [ԭ��ʱ��]\n", boost::lexical_cast<std::string>(OldTime).c_str());
	}

	if (compare(OldMillisec, pOriginal->OldMillisec) != 0)
	{
		fprintf(fp, "\t\tOldMillisec = %s -> %s    [ԭ��ʱ�䣨���룩]\n", boost::lexical_cast<std::string>(pOriginal->OldMillisec).c_str(), boost::lexical_cast<std::string>(OldMillisec).c_str());
	}
	else
	{
		fprintf(fp, "\t\tOldMillisec = %s    [ԭ��ʱ�䣨���룩]\n", boost::lexical_cast<std::string>(OldMillisec).c_str());
	}
	fprintf(fp, "\t}\n");
}

//������д���ļ���һ����,����DEBUG
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

//������д��һ���ַ�����
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
	fprintf(fp, "\t\tTradingDay = %s    [������]\n", boost::lexical_cast<std::string>(TradingDay).c_str());
	fprintf(fp, "\t\tTerminalID = %s    [�ն˻����]\n", boost::lexical_cast<std::string>(TerminalID).c_str());
	fprintf(fp, "\t\tTerminalType = %s    [�ն˻�����]\n", boost::lexical_cast<std::string>(TerminalType).c_str());
	fprintf(fp, "\t\tAppType = %s    [���׽ӿ�����]\n", boost::lexical_cast<std::string>(AppType).c_str());
	fprintf(fp, "\t\tSessionID = %s    [�ն˻���ǰ��¼Session]\n", boost::lexical_cast<std::string>(SessionID).c_str());
	fprintf(fp, "\t\tStartTime = %s    [�ն˻�����ʱ��]\n", boost::lexical_cast<std::string>(StartTime).c_str());
	fprintf(fp, "\t\tUpdateTime = %s    [�ն˻�����ʱ��]\n", boost::lexical_cast<std::string>(UpdateTime).c_str());
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
		fprintf(fp, "\t\tTradingDay = %s -> %s    [������]\n", boost::lexical_cast<std::string>(pOriginal->TradingDay).c_str(), boost::lexical_cast<std::string>(TradingDay).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTradingDay = %s    [������]\n", boost::lexical_cast<std::string>(TradingDay).c_str());
	}
	if (compare(TerminalID, pOriginal->TerminalID) != 0)
	{
		fprintf(fp, "\t\tTerminalID = %s -> %s    [�ն˻����]\n", boost::lexical_cast<std::string>(pOriginal->TerminalID).c_str(), boost::lexical_cast<std::string>(TerminalID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTerminalID = %s    [�ն˻����]\n", boost::lexical_cast<std::string>(TerminalID).c_str());
	}
	if (compare(TerminalType, pOriginal->TerminalType) != 0)
	{
		fprintf(fp, "\t\tTerminalType = %s -> %s    [�ն˻�����]\n", boost::lexical_cast<std::string>(pOriginal->TerminalType).c_str(), boost::lexical_cast<std::string>(TerminalType).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTerminalType = %s    [�ն˻�����]\n", boost::lexical_cast<std::string>(TerminalType).c_str());
	}
	if (compare(AppType, pOriginal->AppType) != 0)
	{
		fprintf(fp, "\t\tAppType = %s -> %s    [���׽ӿ�����]\n", boost::lexical_cast<std::string>(pOriginal->AppType).c_str(), boost::lexical_cast<std::string>(AppType).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAppType = %s    [���׽ӿ�����]\n", boost::lexical_cast<std::string>(AppType).c_str());
	}
	if (compare(SessionID, pOriginal->SessionID) != 0)
	{
		fprintf(fp, "\t\tSessionID = %s -> %s    [�ն˻���ǰ��¼Session]\n", boost::lexical_cast<std::string>(pOriginal->SessionID).c_str(), boost::lexical_cast<std::string>(SessionID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tSessionID = %s    [�ն˻���ǰ��¼Session]\n", boost::lexical_cast<std::string>(SessionID).c_str());
	}
	if (compare(StartTime, pOriginal->StartTime) != 0)
	{
		fprintf(fp, "\t\tStartTime = %s -> %s    [�ն˻�����ʱ��]\n", boost::lexical_cast<std::string>(pOriginal->StartTime).c_str(), boost::lexical_cast<std::string>(StartTime).c_str());
	}
	else
	{
		fprintf(fp, "\t\tStartTime = %s    [�ն˻�����ʱ��]\n", boost::lexical_cast<std::string>(StartTime).c_str());
	}
	if (compare(UpdateTime, pOriginal->UpdateTime) != 0)
	{
		fprintf(fp, "\t\tUpdateTime = %s -> %s    [�ն˻�����ʱ��]\n", boost::lexical_cast<std::string>(pOriginal->UpdateTime).c_str(), boost::lexical_cast<std::string>(UpdateTime).c_str());
	}
	else
	{
		fprintf(fp, "\t\tUpdateTime = %s    [�ն˻�����ʱ��]\n", boost::lexical_cast<std::string>(UpdateTime).c_str());
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
	fprintf(fp, "\t\tTradingDay = %s    [������]\n", boost::lexical_cast<std::string>(TradingDay).c_str());
	fprintf(fp, "\t\tFrontID = %s    [ǰ�ñ��]\n", boost::lexical_cast<std::string>(FrontID).c_str());
	fprintf(fp, "\t\tSessionID = %s    [ǰ��Session���]\n", boost::lexical_cast<std::string>(SessionID).c_str());
	fprintf(fp, "\t\tStartTime = %s    [ǰ�û�����ʱ��]\n", boost::lexical_cast<std::string>(StartTime).c_str());
	fprintf(fp, "\t\tUpdateTime = %s    [ǰ�û�����ʱ��]\n", boost::lexical_cast<std::string>(UpdateTime).c_str());
	fprintf(fp, "\t\tFrontRunStatus = %s    [ǰ������״̬]\n", boost::lexical_cast<std::string>(FrontRunStatus).c_str());
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
		fprintf(fp, "\t\tTradingDay = %s -> %s    [������]\n", boost::lexical_cast<std::string>(pOriginal->TradingDay).c_str(), boost::lexical_cast<std::string>(TradingDay).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTradingDay = %s    [������]\n", boost::lexical_cast<std::string>(TradingDay).c_str());
	}
	if (compare(FrontID, pOriginal->FrontID) != 0)
	{
		fprintf(fp, "\t\tFrontID = %s -> %s    [ǰ�ñ��]\n", boost::lexical_cast<std::string>(pOriginal->FrontID).c_str(), boost::lexical_cast<std::string>(FrontID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tFrontID = %s    [ǰ�ñ��]\n", boost::lexical_cast<std::string>(FrontID).c_str());
	}
	if (compare(SessionID, pOriginal->SessionID) != 0)
	{
		fprintf(fp, "\t\tSessionID = %s -> %s    [ǰ��Session���]\n", boost::lexical_cast<std::string>(pOriginal->SessionID).c_str(), boost::lexical_cast<std::string>(SessionID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tSessionID = %s    [ǰ��Session���]\n", boost::lexical_cast<std::string>(SessionID).c_str());
	}
	if (compare(StartTime, pOriginal->StartTime) != 0)
	{
		fprintf(fp, "\t\tStartTime = %s -> %s    [ǰ�û�����ʱ��]\n", boost::lexical_cast<std::string>(pOriginal->StartTime).c_str(), boost::lexical_cast<std::string>(StartTime).c_str());
	}
	else
	{
		fprintf(fp, "\t\tStartTime = %s    [ǰ�û�����ʱ��]\n", boost::lexical_cast<std::string>(StartTime).c_str());
	}
	if (compare(UpdateTime, pOriginal->UpdateTime) != 0)
	{
		fprintf(fp, "\t\tUpdateTime = %s -> %s    [ǰ�û�����ʱ��]\n", boost::lexical_cast<std::string>(pOriginal->UpdateTime).c_str(), boost::lexical_cast<std::string>(UpdateTime).c_str());
	}
	else
	{
		fprintf(fp, "\t\tUpdateTime = %s    [ǰ�û�����ʱ��]\n", boost::lexical_cast<std::string>(UpdateTime).c_str());
	}
	if (compare(FrontRunStatus, pOriginal->FrontRunStatus) != 0)
	{
		fprintf(fp, "\t\tFrontRunStatus = %s -> %s    [ǰ������״̬]\n", boost::lexical_cast<std::string>(pOriginal->FrontRunStatus).c_str(), boost::lexical_cast<std::string>(FrontRunStatus).c_str());
	}
	else
	{
		fprintf(fp, "\t\tFrontRunStatus = %s    [ǰ������״̬]\n", boost::lexical_cast<std::string>(FrontRunStatus).c_str());
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
	//char buf[4000];///���ÿ����Ա���ַ���ֵ	
	if (fp == nullptr)
	{
		fp = stdout;
	}
	if (index >= 0)
		sprintf(index_buf, "[%d]", index);
	else
		index_buf[0] = '\0';
	fprintf(fp, "\tCTrader%s = {\n", index_buf);
	fprintf(fp, "\t\tTraderID = %s    [����Ա����]\n", boost::lexical_cast<std::string>(TraderID).c_str());
	fprintf(fp, "\t\tAppType = %s    [���׽ӿ�����]\n", boost::lexical_cast<std::string>(AppType).c_str());
	fprintf(fp, "\t\tTerminalType = %s    [����Ա��¼���]\n", boost::lexical_cast<std::string>(TerminalType).c_str());
	fprintf(fp, "\t\tTradingDay = %s    [������]\n", boost::lexical_cast<std::string>(TradingDay).c_str());
	fprintf(fp, "\t\tMaxParalle = %s    [����Ա���������]\n", boost::lexical_cast<std::string>(MaxParalle).c_str());
	fprintf(fp, "\t\tServerIP = %s    [���׽ӿ�IP��ַ]\n", boost::lexical_cast<std::string>(ServerIP).c_str());
	fprintf(fp, "\t\tParticipantID = %s    [��Ա����]\n", boost::lexical_cast<std::string>(ParticipantID).c_str());
	fprintf(fp, "\t\tBrokerID = %s    [���ͻ�Ա����]\n", boost::lexical_cast<std::string>(BrokerID).c_str());
	fprintf(fp, "\t\tOperatorID = %s    [����Ա��]\n", boost::lexical_cast<std::string>(OperatorID).c_str());
	fprintf(fp, "\t\tUserProductInfo = %s    [�û��˲�Ʒ��Ϣ]\n", boost::lexical_cast<std::string>(UserProductInfo).c_str());
	fprintf(fp, "\t\tInterfaceProductInfo = %s    [�ӿڶ˲�Ʒ��Ϣ]\n", boost::lexical_cast<std::string>(InterfaceProductInfo).c_str());
	fprintf(fp, "\t\tProtocolInfo = %s    [Э����Ϣ]\n", boost::lexical_cast<std::string>(ProtocolInfo).c_str());
	fprintf(fp, "\t\tMacAddress = %s    [Mac��ַ]\n", boost::lexical_cast<std::string>(MacAddress).c_str());
	fprintf(fp, "\t\tClientIPAddress = %s    [�ն�IP��ַ]\n", boost::lexical_cast<std::string>(ClientIPAddress).c_str());
	fprintf(fp, "\t\tPassword = %s    [����]\n", boost::lexical_cast<std::string>(Password).c_str());
	fprintf(fp, "\t\tIsCaLogin = %s    [�Ƿ�CA��֤]\n", boost::lexical_cast<std::string>(IsCaLogin).c_str());
	fprintf(fp, "\t\tIdentity = %s    [��¼�������,Ŀǰֻ֧�ֵ��ͻ�]\n", boost::lexical_cast<std::string>(Identity).c_str());
	fprintf(fp, "\t\tIsForcePwd = %s    [�Ƿ�ǿ���޸�����]\n", boost::lexical_cast<std::string>(IsForcePwd).c_str());
	fprintf(fp, "\t\tOneTimePassword = %s    [��̬����]\n", boost::lexical_cast<std::string>(OneTimePassword).c_str());
	fprintf(fp, "\t\tOtpPass = %s    [otp��֤����]\n", boost::lexical_cast<std::string>(OtpPass).c_str());
	fprintf(fp, "\t\tCaLen = %s    [CA��Ϣ���ȣ�IsCaLoginΪ'Y'ʱ�����ֶ���Ч]\n", boost::lexical_cast<std::string>(CaLen).c_str());
	fprintf(fp, "\t\tCaInfo = %s    [CA��¼ʱ��д,IsCaLoginΪ'Y'ʱ�����ֶ���Ч]\n", boost::lexical_cast<std::string>(CaInfo).c_str());
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
		fprintf(fp, "\t\tTraderID = %s -> %s    [����Ա����]\n", boost::lexical_cast<std::string>(pOriginal->TraderID).c_str(), boost::lexical_cast<std::string>(TraderID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTraderID = %s    [����Ա����]\n", boost::lexical_cast<std::string>(TraderID).c_str());
	}
	if (compare(AppType, pOriginal->AppType) != 0)
	{
		fprintf(fp, "\t\tAppType = %s -> %s    [���׽ӿ�����]\n", boost::lexical_cast<std::string>(pOriginal->AppType).c_str(), boost::lexical_cast<std::string>(AppType).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAppType = %s    [���׽ӿ�����]\n", boost::lexical_cast<std::string>(AppType).c_str());
	}
	if (compare(TerminalType, pOriginal->TerminalType) != 0)
	{
		fprintf(fp, "\t\tTerminalType = %s -> %s    [����Ա��¼���]\n", boost::lexical_cast<std::string>(pOriginal->TerminalType).c_str(), boost::lexical_cast<std::string>(TerminalType).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTerminalType = %s    [����Ա��¼���]\n", boost::lexical_cast<std::string>(TerminalType).c_str());
	}
	if (compare(TradingDay, pOriginal->TradingDay) != 0)
	{
		fprintf(fp, "\t\tTradingDay = %s -> %s    [������]\n", boost::lexical_cast<std::string>(pOriginal->TradingDay).c_str(), boost::lexical_cast<std::string>(TradingDay).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTradingDay = %s    [������]\n", boost::lexical_cast<std::string>(TradingDay).c_str());
	}
	if (compare(MaxParalle, pOriginal->MaxParalle) != 0)
	{
		fprintf(fp, "\t\tMaxParalle = %s -> %s    [����Ա���������]\n", boost::lexical_cast<std::string>(pOriginal->MaxParalle).c_str(), boost::lexical_cast<std::string>(MaxParalle).c_str());
	}
	else
	{
		fprintf(fp, "\t\tMaxParalle = %s    [����Ա���������]\n", boost::lexical_cast<std::string>(MaxParalle).c_str());
	}
	if (compare(ServerIP, pOriginal->ServerIP) != 0)
	{
		fprintf(fp, "\t\tServerIP = %s -> %s    [���׽ӿ�IP��ַ]\n", boost::lexical_cast<std::string>(pOriginal->ServerIP).c_str(), boost::lexical_cast<std::string>(ServerIP).c_str());
	}
	else
	{
		fprintf(fp, "\t\tServerIP = %s    [���׽ӿ�IP��ַ]\n", boost::lexical_cast<std::string>(ServerIP).c_str());
	}
	if (compare(ParticipantID, pOriginal->ParticipantID) != 0)
	{
		fprintf(fp, "\t\tParticipantID = %s -> %s    [��Ա����]\n", boost::lexical_cast<std::string>(pOriginal->ParticipantID).c_str(), boost::lexical_cast<std::string>(ParticipantID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tParticipantID = %s    [��Ա����]\n", boost::lexical_cast<std::string>(ParticipantID).c_str());
	}
	if (compare(BrokerID, pOriginal->BrokerID) != 0)
	{
		fprintf(fp, "\t\tBrokerID = %s -> %s    [���ͻ�Ա����]\n", boost::lexical_cast<std::string>(pOriginal->BrokerID).c_str(), boost::lexical_cast<std::string>(BrokerID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBrokerID = %s    [���ͻ�Ա����]\n", boost::lexical_cast<std::string>(BrokerID).c_str());
	}
	if (compare(OperatorID, pOriginal->OperatorID) != 0)
	{
		fprintf(fp, "\t\tOperatorID = %s -> %s    [����Ա��]\n", boost::lexical_cast<std::string>(pOriginal->OperatorID).c_str(), boost::lexical_cast<std::string>(OperatorID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tOperatorID = %s    [����Ա��]\n", boost::lexical_cast<std::string>(OperatorID).c_str());
	}
	if (compare(UserProductInfo, pOriginal->UserProductInfo) != 0)
	{
		fprintf(fp, "\t\tUserProductInfo = %s -> %s    [�û��˲�Ʒ��Ϣ]\n", boost::lexical_cast<std::string>(pOriginal->UserProductInfo).c_str(), boost::lexical_cast<std::string>(UserProductInfo).c_str());
	}
	else
	{
		fprintf(fp, "\t\tUserProductInfo = %s    [�û��˲�Ʒ��Ϣ]\n", boost::lexical_cast<std::string>(UserProductInfo).c_str());
	}
	if (compare(InterfaceProductInfo, pOriginal->InterfaceProductInfo) != 0)
	{
		fprintf(fp, "\t\tInterfaceProductInfo = %s -> %s    [�ӿڶ˲�Ʒ��Ϣ]\n", boost::lexical_cast<std::string>(pOriginal->InterfaceProductInfo).c_str(), boost::lexical_cast<std::string>(InterfaceProductInfo).c_str());
	}
	else
	{
		fprintf(fp, "\t\tInterfaceProductInfo = %s    [�ӿڶ˲�Ʒ��Ϣ]\n", boost::lexical_cast<std::string>(InterfaceProductInfo).c_str());
	}
	if (compare(ProtocolInfo, pOriginal->ProtocolInfo) != 0)
	{
		fprintf(fp, "\t\tProtocolInfo = %s -> %s    [Э����Ϣ]\n", boost::lexical_cast<std::string>(pOriginal->ProtocolInfo).c_str(), boost::lexical_cast<std::string>(ProtocolInfo).c_str());
	}
	else
	{
		fprintf(fp, "\t\tProtocolInfo = %s    [Э����Ϣ]\n", boost::lexical_cast<std::string>(ProtocolInfo).c_str());
	}
	if (compare(MacAddress, pOriginal->MacAddress) != 0)
	{
		fprintf(fp, "\t\tMacAddress = %s -> %s    [Mac��ַ]\n", boost::lexical_cast<std::string>(pOriginal->MacAddress).c_str(), boost::lexical_cast<std::string>(MacAddress).c_str());
	}
	else
	{
		fprintf(fp, "\t\tMacAddress = %s    [Mac��ַ]\n", boost::lexical_cast<std::string>(MacAddress).c_str());
	}
	if (compare(ClientIPAddress, pOriginal->ClientIPAddress) != 0)
	{
		fprintf(fp, "\t\tClientIPAddress = %s -> %s    [�ն�IP��ַ]\n", boost::lexical_cast<std::string>(pOriginal->ClientIPAddress).c_str(), boost::lexical_cast<std::string>(ClientIPAddress).c_str());
	}
	else
	{
		fprintf(fp, "\t\tClientIPAddress = %s    [�ն�IP��ַ]\n", boost::lexical_cast<std::string>(ClientIPAddress).c_str());
	}
	if (compare(Password, pOriginal->Password) != 0)
	{
		fprintf(fp, "\t\tPassword = %s -> %s    [����]\n", boost::lexical_cast<std::string>(pOriginal->Password).c_str(), boost::lexical_cast<std::string>(Password).c_str());
	}
	else
	{
		fprintf(fp, "\t\tPassword = %s    [����]\n", boost::lexical_cast<std::string>(Password).c_str());
	}
	if (compare(IsCaLogin, pOriginal->IsCaLogin) != 0)
	{
		fprintf(fp, "\t\tIsCaLogin = %s -> %s    [�Ƿ�CA��֤]\n", boost::lexical_cast<std::string>(pOriginal->IsCaLogin).c_str(), boost::lexical_cast<std::string>(IsCaLogin).c_str());
	}
	else
	{
		fprintf(fp, "\t\tIsCaLogin = %s    [�Ƿ�CA��֤]\n", boost::lexical_cast<std::string>(IsCaLogin).c_str());
	}
	if (compare(Identity, pOriginal->Identity) != 0)
	{
		fprintf(fp, "\t\tIdentity = %s -> %s    [��¼�������,Ŀǰֻ֧�ֵ��ͻ�]\n", boost::lexical_cast<std::string>(pOriginal->Identity).c_str(), boost::lexical_cast<std::string>(Identity).c_str());
	}
	else
	{
		fprintf(fp, "\t\tIdentity = %s    [��¼�������,Ŀǰֻ֧�ֵ��ͻ�]\n", boost::lexical_cast<std::string>(Identity).c_str());
	}
	if (compare(IsForcePwd, pOriginal->IsForcePwd) != 0)
	{
		fprintf(fp, "\t\tIsForcePwd = %s -> %s    [�Ƿ�ǿ���޸�����]\n", boost::lexical_cast<std::string>(pOriginal->IsForcePwd).c_str(), boost::lexical_cast<std::string>(IsForcePwd).c_str());
	}
	else
	{
		fprintf(fp, "\t\tIsForcePwd = %s    [�Ƿ�ǿ���޸�����]\n", boost::lexical_cast<std::string>(IsForcePwd).c_str());
	}
	if (compare(OneTimePassword, pOriginal->OneTimePassword) != 0)
	{
		fprintf(fp, "\t\tOneTimePassword = %s -> %s    [��̬����]\n", boost::lexical_cast<std::string>(pOriginal->OneTimePassword).c_str(), boost::lexical_cast<std::string>(OneTimePassword).c_str());
	}
	else
	{
		fprintf(fp, "\t\tOneTimePassword = %s    [��̬����]\n", boost::lexical_cast<std::string>(OneTimePassword).c_str());
	}
	if (compare(OtpPass, pOriginal->OtpPass) != 0)
	{
		fprintf(fp, "\t\tOtpPass = %s -> %s    [otp��֤����]\n", boost::lexical_cast<std::string>(pOriginal->OtpPass).c_str(), boost::lexical_cast<std::string>(OtpPass).c_str());
	}
	else
	{
		fprintf(fp, "\t\tOtpPass = %s    [otp��֤����]\n", boost::lexical_cast<std::string>(OtpPass).c_str());
	}
	if (compare(CaLen, pOriginal->CaLen) != 0)
	{
		fprintf(fp, "\t\tCaLen = %s -> %s    [CA��Ϣ���ȣ�IsCaLoginΪ'Y'ʱ�����ֶ���Ч]\n", boost::lexical_cast<std::string>(pOriginal->CaLen).c_str(), boost::lexical_cast<std::string>(CaLen).c_str());
	}
	else
	{
		fprintf(fp, "\t\tCaLen = %s    [CA��Ϣ���ȣ�IsCaLoginΪ'Y'ʱ�����ֶ���Ч]\n", boost::lexical_cast<std::string>(CaLen).c_str());
	}
	if (compare(CaInfo, pOriginal->CaInfo) != 0)
	{
		fprintf(fp, "\t\tCaInfo = %s -> %s    [CA��¼ʱ��д,IsCaLoginΪ'Y'ʱ�����ֶ���Ч]\n", boost::lexical_cast<std::string>(pOriginal->CaInfo).c_str(), boost::lexical_cast<std::string>(CaInfo).c_str());
	}
	else
	{
		fprintf(fp, "\t\tCaInfo = %s    [CA��¼ʱ��д,IsCaLoginΪ'Y'ʱ�����ֶ���Ч]\n", boost::lexical_cast<std::string>(CaInfo).c_str());
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
	fprintf(fp, "\t\tTraderID = %s    [����Ա����]\n", boost::lexical_cast<std::string>(TraderID).c_str());
	fprintf(fp, "\t\tAppType = %s    [���׽ӿ�����]\n", boost::lexical_cast<std::string>(AppType).c_str());
	fprintf(fp, "\t\tTerminalType = %s    [����Ա��¼���]\n", boost::lexical_cast<std::string>(TerminalType).c_str());
	fprintf(fp, "\t\tParalled = %s    [����Ա��������]\n", boost::lexical_cast<std::string>(Paralled).c_str());
	fprintf(fp, "\t\tMaxParalle = %s    [�����ʺ�����е�¼����]\n", boost::lexical_cast<std::string>(MaxParalle).c_str());
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
		fprintf(fp, "\t\tTraderID = %s -> %s    [����Ա����]\n", boost::lexical_cast<std::string>(pOriginal->TraderID).c_str(), boost::lexical_cast<std::string>(TraderID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTraderID = %s    [����Ա����]\n", boost::lexical_cast<std::string>(TraderID).c_str());
	}
	if (compare(AppType, pOriginal->AppType) != 0)
	{
		fprintf(fp, "\t\tAppType = %s -> %s    [���׽ӿ�����]\n", boost::lexical_cast<std::string>(pOriginal->AppType).c_str(), boost::lexical_cast<std::string>(AppType).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAppType = %s    [���׽ӿ�����]\n", boost::lexical_cast<std::string>(AppType).c_str());
	}
	if (compare(TerminalType, pOriginal->TerminalType) != 0)
	{
		fprintf(fp, "\t\tTerminalType = %s -> %s    [����Ա��¼���]\n", boost::lexical_cast<std::string>(pOriginal->TerminalType).c_str(), boost::lexical_cast<std::string>(TerminalType).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTerminalType = %s    [����Ա��¼���]\n", boost::lexical_cast<std::string>(TerminalType).c_str());
	}
	if (compare(Paralled, pOriginal->Paralled) != 0)
	{
		fprintf(fp, "\t\tParalled = %s -> %s    [����Ա��������]\n", boost::lexical_cast<std::string>(pOriginal->Paralled).c_str(), boost::lexical_cast<std::string>(Paralled).c_str());
	}
	else
	{
		fprintf(fp, "\t\tParalled = %s    [����Ա��������]\n", boost::lexical_cast<std::string>(Paralled).c_str());
	}
	if (compare(MaxParalle, pOriginal->MaxParalle) != 0)
	{
		fprintf(fp, "\t\tMaxParalle = %s -> %s    [�����ʺ�����е�¼����]\n", boost::lexical_cast<std::string>(pOriginal->MaxParalle).c_str(), boost::lexical_cast<std::string>(MaxParalle).c_str());
	}
	else
	{
		fprintf(fp, "\t\tMaxParalle = %s    [�����ʺ�����е�¼����]\n", boost::lexical_cast<std::string>(MaxParalle).c_str());
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
	fprintf(fp, "\t\tTraderID = %s    [�û����루CTP���ص�UserID����ʢ���ص���LoginNo��]\n", boost::lexical_cast<std::string>(TraderID).c_str());
	fprintf(fp, "\t\tAppType = %s    [���׽ӿ�����]\n", boost::lexical_cast<std::string>(AppType).c_str());
	fprintf(fp, "\t\tTerminalID = %s    [�ն˻����]\n", boost::lexical_cast<std::string>(TerminalID).c_str());
	fprintf(fp, "\t\tTerminalType = %s    [�ն˻�����]\n", boost::lexical_cast<std::string>(TerminalType).c_str());
	fprintf(fp, "\t\tSessionID = %s    [�ն˻���ǰ��¼Session]\n", boost::lexical_cast<std::string>(SessionID).c_str());
	fprintf(fp, "\t\tTraderRuntype = %s    [����Ա����ʱ״̬]\n", boost::lexical_cast<std::string>(TraderRuntype).c_str());
	fprintf(fp, "\t\tTradingDay = %s    [�����գ�CTP���أ�]\n", boost::lexical_cast<std::string>(TradingDay).c_str());
	fprintf(fp, "\t\tIsActive = %s    [����Ա��ǰ�����Ƿ��Ծ]\n", boost::lexical_cast<std::string>(IsActive).c_str());
	fprintf(fp, "\t\tUpdateTime = %s    [ʵ���˻�״̬����ʱ��]\n", boost::lexical_cast<std::string>(UpdateTime).c_str());
	fprintf(fp, "\t\tExchLoginTime = %s    [��¼�ɹ�ʱ�䣨CTP���أ�]\n", boost::lexical_cast<std::string>(ExchLoginTime).c_str());
	fprintf(fp, "\t\tExchBrokerID = %s    [���͹�˾���루CTP���أ�]\n", boost::lexical_cast<std::string>(ExchBrokerID).c_str());
	fprintf(fp, "\t\tExchSystemName = %s    [����ϵͳ���ƣ�CTP���أ�]\n", boost::lexical_cast<std::string>(ExchSystemName).c_str());
	fprintf(fp, "\t\tExchFrontID = %s    [ǰ�ñ�ţ�CTP���أ�]\n", boost::lexical_cast<std::string>(ExchFrontID).c_str());
	fprintf(fp, "\t\tExchSessionID = %s    [�Ự��ţ�CTP���أ�]\n", boost::lexical_cast<std::string>(ExchSessionID).c_str());
	fprintf(fp, "\t\tExchMaxOrderRef = %s    [��󱨵����ã�CTP���أ�]\n", boost::lexical_cast<std::string>(ExchMaxOrderRef).c_str());
	fprintf(fp, "\t\tExchIsCaLogin = %s    [�Ƿ�CA��֤����ʢ���أ�]\n", boost::lexical_cast<std::string>(ExchIsCaLogin).c_str());
	fprintf(fp, "\t\tExchIsForcePwd = %s    [�Ƿ�ǿ���޸����루��ʢ���أ�]\n", boost::lexical_cast<std::string>(ExchIsForcePwd).c_str());
	fprintf(fp, "\t\tExchLoginName = %s    [��¼���ʺż�ƣ���ʢ���أ�]\n", boost::lexical_cast<std::string>(ExchLoginName).c_str());
	fprintf(fp, "\t\tExchReservedInfo = %s    [�ͻ�Ԥ����Ϣ,�ͻ��Լ�ʶ���̨ϵͳ����ʢ���أ�]\n", boost::lexical_cast<std::string>(ExchReservedInfo).c_str());
	fprintf(fp, "\t\tExchLastLoginDateTime = %s    [�ϴε�¼ʱ�䣨��ʢ���أ�]\n", boost::lexical_cast<std::string>(ExchLastLoginDateTime).c_str());
	fprintf(fp, "\t\tExchLastLogoutDateTime = %s    [�ϴεǳ�ʱ�䣨��ʢ���أ�]\n", boost::lexical_cast<std::string>(ExchLastLogoutDateTime).c_str());
	fprintf(fp, "\t\tExchLastLoginIp = %s    [�ϴε�¼ip������ipv6����ʢ���أ�]\n", boost::lexical_cast<std::string>(ExchLastLoginIp).c_str());
	fprintf(fp, "\t\tExchLastLoginPort = %s    [�ϴε�¼port����ʢ���أ�]\n", boost::lexical_cast<std::string>(ExchLastLoginPort).c_str());
	fprintf(fp, "\t\tExchLastLoginMachineInfo = %s    [�ϴε�¼������Ϣ����Ҫ��Mac��ַ����ʢ���أ�]\n", boost::lexical_cast<std::string>(ExchLastLoginMachineInfo).c_str());
	fprintf(fp, "\t\tExchSHFETime = %s    [������ʱ�䣨CTP���أ�]\n", boost::lexical_cast<std::string>(ExchSHFETime).c_str());
	fprintf(fp, "\t\tExchDCETime = %s    [������ʱ�䣨CTP���أ�]\n", boost::lexical_cast<std::string>(ExchDCETime).c_str());
	fprintf(fp, "\t\tExchCZCETime = %s    [֣����ʱ�䣨CTP���أ�]\n", boost::lexical_cast<std::string>(ExchCZCETime).c_str());
	fprintf(fp, "\t\tExchFFEXTime = %s    [�н���ʱ�䣨CTP���أ�]\n", boost::lexical_cast<std::string>(ExchFFEXTime).c_str());
	fprintf(fp, "\t\tExchServerDateTime = %s    [ϵͳ��ǰʱ��(�ͻ���Уʱ����ʢ���أ�]\n", boost::lexical_cast<std::string>(ExchServerDateTime).c_str());
	fprintf(fp, "\t\tErrorID = %s    [�������]\n", boost::lexical_cast<std::string>(ErrorID).c_str());
	fprintf(fp, "\t\tErrorMsg = %s    [������Ϣ]\n", boost::lexical_cast<std::string>(ErrorMsg).c_str());
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
		fprintf(fp, "\t\tTraderID = %s -> %s    [�û����루CTP���ص�UserID����ʢ���ص���LoginNo��]\n", boost::lexical_cast<std::string>(pOriginal->TraderID).c_str(), boost::lexical_cast<std::string>(TraderID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTraderID = %s    [�û����루CTP���ص�UserID����ʢ���ص���LoginNo��]\n", boost::lexical_cast<std::string>(TraderID).c_str());
	}
	if (compare(AppType, pOriginal->AppType) != 0)
	{
		fprintf(fp, "\t\tAppType = %s -> %s    [���׽ӿ�����]\n", boost::lexical_cast<std::string>(pOriginal->AppType).c_str(), boost::lexical_cast<std::string>(AppType).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAppType = %s    [���׽ӿ�����]\n", boost::lexical_cast<std::string>(AppType).c_str());
	}
	if (compare(TerminalID, pOriginal->TerminalID) != 0)
	{
		fprintf(fp, "\t\tTerminalID = %s -> %s    [�ն˻����]\n", boost::lexical_cast<std::string>(pOriginal->TerminalID).c_str(), boost::lexical_cast<std::string>(TerminalID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTerminalID = %s    [�ն˻����]\n", boost::lexical_cast<std::string>(TerminalID).c_str());
	}
	if (compare(TerminalType, pOriginal->TerminalType) != 0)
	{
		fprintf(fp, "\t\tTerminalType = %s -> %s    [�ն˻�����]\n", boost::lexical_cast<std::string>(pOriginal->TerminalType).c_str(), boost::lexical_cast<std::string>(TerminalType).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTerminalType = %s    [�ն˻�����]\n", boost::lexical_cast<std::string>(TerminalType).c_str());
	}
	if (compare(SessionID, pOriginal->SessionID) != 0)
	{
		fprintf(fp, "\t\tSessionID = %s -> %s    [�ն˻���ǰ��¼Session]\n", boost::lexical_cast<std::string>(pOriginal->SessionID).c_str(), boost::lexical_cast<std::string>(SessionID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tSessionID = %s    [�ն˻���ǰ��¼Session]\n", boost::lexical_cast<std::string>(SessionID).c_str());
	}
	if (compare(TraderRuntype, pOriginal->TraderRuntype) != 0)
	{
		fprintf(fp, "\t\tTraderRuntype = %s -> %s    [����Ա����ʱ״̬]\n", boost::lexical_cast<std::string>(pOriginal->TraderRuntype).c_str(), boost::lexical_cast<std::string>(TraderRuntype).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTraderRuntype = %s    [����Ա����ʱ״̬]\n", boost::lexical_cast<std::string>(TraderRuntype).c_str());
	}
	if (compare(TradingDay, pOriginal->TradingDay) != 0)
	{
		fprintf(fp, "\t\tTradingDay = %s -> %s    [�����գ�CTP���أ�]\n", boost::lexical_cast<std::string>(pOriginal->TradingDay).c_str(), boost::lexical_cast<std::string>(TradingDay).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTradingDay = %s    [�����գ�CTP���أ�]\n", boost::lexical_cast<std::string>(TradingDay).c_str());
	}
	if (compare(IsActive, pOriginal->IsActive) != 0)
	{
		fprintf(fp, "\t\tIsActive = %s -> %s    [����Ա��ǰ�����Ƿ��Ծ]\n", boost::lexical_cast<std::string>(pOriginal->IsActive).c_str(), boost::lexical_cast<std::string>(IsActive).c_str());
	}
	else
	{
		fprintf(fp, "\t\tIsActive = %s    [����Ա��ǰ�����Ƿ��Ծ]\n", boost::lexical_cast<std::string>(IsActive).c_str());
	}
	if (compare(UpdateTime, pOriginal->UpdateTime) != 0)
	{
		fprintf(fp, "\t\tUpdateTime = %s -> %s    [ʵ���˻�״̬����ʱ��]\n", boost::lexical_cast<std::string>(pOriginal->UpdateTime).c_str(), boost::lexical_cast<std::string>(UpdateTime).c_str());
	}
	else
	{
		fprintf(fp, "\t\tUpdateTime = %s    [ʵ���˻�״̬����ʱ��]\n", boost::lexical_cast<std::string>(UpdateTime).c_str());
	}
	if (compare(ExchLoginTime, pOriginal->ExchLoginTime) != 0)
	{
		fprintf(fp, "\t\tExchLoginTime = %s -> %s    [��¼�ɹ�ʱ�䣨CTP���أ�]\n", boost::lexical_cast<std::string>(pOriginal->ExchLoginTime).c_str(), boost::lexical_cast<std::string>(ExchLoginTime).c_str());
	}
	else
	{
		fprintf(fp, "\t\tExchLoginTime = %s    [��¼�ɹ�ʱ�䣨CTP���أ�]\n", boost::lexical_cast<std::string>(ExchLoginTime).c_str());
	}
	if (compare(ExchBrokerID, pOriginal->ExchBrokerID) != 0)
	{
		fprintf(fp, "\t\tExchBrokerID = %s -> %s    [���͹�˾���루CTP���أ�]\n", boost::lexical_cast<std::string>(pOriginal->ExchBrokerID).c_str(), boost::lexical_cast<std::string>(ExchBrokerID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tExchBrokerID = %s    [���͹�˾���루CTP���أ�]\n", boost::lexical_cast<std::string>(ExchBrokerID).c_str());
	}
	if (compare(ExchSystemName, pOriginal->ExchSystemName) != 0)
	{
		fprintf(fp, "\t\tExchSystemName = %s -> %s    [����ϵͳ���ƣ�CTP���أ�]\n", boost::lexical_cast<std::string>(pOriginal->ExchSystemName).c_str(), boost::lexical_cast<std::string>(ExchSystemName).c_str());
	}
	else
	{
		fprintf(fp, "\t\tExchSystemName = %s    [����ϵͳ���ƣ�CTP���أ�]\n", boost::lexical_cast<std::string>(ExchSystemName).c_str());
	}
	if (compare(ExchFrontID, pOriginal->ExchFrontID) != 0)
	{
		fprintf(fp, "\t\tExchFrontID = %s -> %s    [ǰ�ñ�ţ�CTP���أ�]\n", boost::lexical_cast<std::string>(pOriginal->ExchFrontID).c_str(), boost::lexical_cast<std::string>(ExchFrontID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tExchFrontID = %s    [ǰ�ñ�ţ�CTP���أ�]\n", boost::lexical_cast<std::string>(ExchFrontID).c_str());
	}
	if (compare(ExchSessionID, pOriginal->ExchSessionID) != 0)
	{
		fprintf(fp, "\t\tExchSessionID = %s -> %s    [�Ự��ţ�CTP���أ�]\n", boost::lexical_cast<std::string>(pOriginal->ExchSessionID).c_str(), boost::lexical_cast<std::string>(ExchSessionID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tExchSessionID = %s    [�Ự��ţ�CTP���أ�]\n", boost::lexical_cast<std::string>(ExchSessionID).c_str());
	}
	if (compare(ExchMaxOrderRef, pOriginal->ExchMaxOrderRef) != 0)
	{
		fprintf(fp, "\t\tExchMaxOrderRef = %s -> %s    [��󱨵����ã�CTP���أ�]\n", boost::lexical_cast<std::string>(pOriginal->ExchMaxOrderRef).c_str(), boost::lexical_cast<std::string>(ExchMaxOrderRef).c_str());
	}
	else
	{
		fprintf(fp, "\t\tExchMaxOrderRef = %s    [��󱨵����ã�CTP���أ�]\n", boost::lexical_cast<std::string>(ExchMaxOrderRef).c_str());
	}
	if (compare(ExchIsCaLogin, pOriginal->ExchIsCaLogin) != 0)
	{
		fprintf(fp, "\t\tExchIsCaLogin = %s -> %s    [�Ƿ�CA��֤����ʢ���أ�]\n", boost::lexical_cast<std::string>(pOriginal->ExchIsCaLogin).c_str(), boost::lexical_cast<std::string>(ExchIsCaLogin).c_str());
	}
	else
	{
		fprintf(fp, "\t\tExchIsCaLogin = %s    [�Ƿ�CA��֤����ʢ���أ�]\n", boost::lexical_cast<std::string>(ExchIsCaLogin).c_str());
	}
	if (compare(ExchIsForcePwd, pOriginal->ExchIsForcePwd) != 0)
	{
		fprintf(fp, "\t\tExchIsForcePwd = %s -> %s    [�Ƿ�ǿ���޸����루��ʢ���أ�]\n", boost::lexical_cast<std::string>(pOriginal->ExchIsForcePwd).c_str(), boost::lexical_cast<std::string>(ExchIsForcePwd).c_str());
	}
	else
	{
		fprintf(fp, "\t\tExchIsForcePwd = %s    [�Ƿ�ǿ���޸����루��ʢ���أ�]\n", boost::lexical_cast<std::string>(ExchIsForcePwd).c_str());
	}
	if (compare(ExchLoginName, pOriginal->ExchLoginName) != 0)
	{
		fprintf(fp, "\t\tExchLoginName = %s -> %s    [��¼���ʺż�ƣ���ʢ���أ�]\n", boost::lexical_cast<std::string>(pOriginal->ExchLoginName).c_str(), boost::lexical_cast<std::string>(ExchLoginName).c_str());
	}
	else
	{
		fprintf(fp, "\t\tExchLoginName = %s    [��¼���ʺż�ƣ���ʢ���أ�]\n", boost::lexical_cast<std::string>(ExchLoginName).c_str());
	}
	if (compare(ExchReservedInfo, pOriginal->ExchReservedInfo) != 0)
	{
		fprintf(fp, "\t\tExchReservedInfo = %s -> %s    [�ͻ�Ԥ����Ϣ,�ͻ��Լ�ʶ���̨ϵͳ����ʢ���أ�]\n", boost::lexical_cast<std::string>(pOriginal->ExchReservedInfo).c_str(), boost::lexical_cast<std::string>(ExchReservedInfo).c_str());
	}
	else
	{
		fprintf(fp, "\t\tExchReservedInfo = %s    [�ͻ�Ԥ����Ϣ,�ͻ��Լ�ʶ���̨ϵͳ����ʢ���أ�]\n", boost::lexical_cast<std::string>(ExchReservedInfo).c_str());
	}
	if (compare(ExchLastLoginDateTime, pOriginal->ExchLastLoginDateTime) != 0)
	{
		fprintf(fp, "\t\tExchLastLoginDateTime = %s -> %s    [�ϴε�¼ʱ�䣨��ʢ���أ�]\n", boost::lexical_cast<std::string>(pOriginal->ExchLastLoginDateTime).c_str(), boost::lexical_cast<std::string>(ExchLastLoginDateTime).c_str());
	}
	else
	{
		fprintf(fp, "\t\tExchLastLoginDateTime = %s    [�ϴε�¼ʱ�䣨��ʢ���أ�]\n", boost::lexical_cast<std::string>(ExchLastLoginDateTime).c_str());
	}
	if (compare(ExchLastLogoutDateTime, pOriginal->ExchLastLogoutDateTime) != 0)
	{
		fprintf(fp, "\t\tExchLastLogoutDateTime = %s -> %s    [�ϴεǳ�ʱ�䣨��ʢ���أ�]\n", boost::lexical_cast<std::string>(pOriginal->ExchLastLogoutDateTime).c_str(), boost::lexical_cast<std::string>(ExchLastLogoutDateTime).c_str());
	}
	else
	{
		fprintf(fp, "\t\tExchLastLogoutDateTime = %s    [�ϴεǳ�ʱ�䣨��ʢ���أ�]\n", boost::lexical_cast<std::string>(ExchLastLogoutDateTime).c_str());
	}
	if (compare(ExchLastLoginIp, pOriginal->ExchLastLoginIp) != 0)
	{
		fprintf(fp, "\t\tExchLastLoginIp = %s -> %s    [�ϴε�¼ip������ipv6����ʢ���أ�]\n", boost::lexical_cast<std::string>(pOriginal->ExchLastLoginIp).c_str(), boost::lexical_cast<std::string>(ExchLastLoginIp).c_str());
	}
	else
	{
		fprintf(fp, "\t\tExchLastLoginIp = %s    [�ϴε�¼ip������ipv6����ʢ���أ�]\n", boost::lexical_cast<std::string>(ExchLastLoginIp).c_str());
	}
	if (compare(ExchLastLoginPort, pOriginal->ExchLastLoginPort) != 0)
	{
		fprintf(fp, "\t\tExchLastLoginPort = %s -> %s    [�ϴε�¼port����ʢ���أ�]\n", boost::lexical_cast<std::string>(pOriginal->ExchLastLoginPort).c_str(), boost::lexical_cast<std::string>(ExchLastLoginPort).c_str());
	}
	else
	{
		fprintf(fp, "\t\tExchLastLoginPort = %s    [�ϴε�¼port����ʢ���أ�]\n", boost::lexical_cast<std::string>(ExchLastLoginPort).c_str());
	}
	if (compare(ExchLastLoginMachineInfo, pOriginal->ExchLastLoginMachineInfo) != 0)
	{
		fprintf(fp, "\t\tExchLastLoginMachineInfo = %s -> %s    [�ϴε�¼������Ϣ����Ҫ��Mac��ַ����ʢ���أ�]\n", boost::lexical_cast<std::string>(pOriginal->ExchLastLoginMachineInfo).c_str(), boost::lexical_cast<std::string>(ExchLastLoginMachineInfo).c_str());
	}
	else
	{
		fprintf(fp, "\t\tExchLastLoginMachineInfo = %s    [�ϴε�¼������Ϣ����Ҫ��Mac��ַ����ʢ���أ�]\n", boost::lexical_cast<std::string>(ExchLastLoginMachineInfo).c_str());
	}
	if (compare(ExchSHFETime, pOriginal->ExchSHFETime) != 0)
	{
		fprintf(fp, "\t\tExchSHFETime = %s -> %s    [������ʱ�䣨CTP���أ�]\n", boost::lexical_cast<std::string>(pOriginal->ExchSHFETime).c_str(), boost::lexical_cast<std::string>(ExchSHFETime).c_str());
	}
	else
	{
		fprintf(fp, "\t\tExchSHFETime = %s    [������ʱ�䣨CTP���أ�]\n", boost::lexical_cast<std::string>(ExchSHFETime).c_str());
	}
	if (compare(ExchDCETime, pOriginal->ExchDCETime) != 0)
	{
		fprintf(fp, "\t\tExchDCETime = %s -> %s    [������ʱ�䣨CTP���أ�]\n", boost::lexical_cast<std::string>(pOriginal->ExchDCETime).c_str(), boost::lexical_cast<std::string>(ExchDCETime).c_str());
	}
	else
	{
		fprintf(fp, "\t\tExchDCETime = %s    [������ʱ�䣨CTP���أ�]\n", boost::lexical_cast<std::string>(ExchDCETime).c_str());
	}
	if (compare(ExchCZCETime, pOriginal->ExchCZCETime) != 0)
	{
		fprintf(fp, "\t\tExchCZCETime = %s -> %s    [֣����ʱ�䣨CTP���أ�]\n", boost::lexical_cast<std::string>(pOriginal->ExchCZCETime).c_str(), boost::lexical_cast<std::string>(ExchCZCETime).c_str());
	}
	else
	{
		fprintf(fp, "\t\tExchCZCETime = %s    [֣����ʱ�䣨CTP���أ�]\n", boost::lexical_cast<std::string>(ExchCZCETime).c_str());
	}
	if (compare(ExchFFEXTime, pOriginal->ExchFFEXTime) != 0)
	{
		fprintf(fp, "\t\tExchFFEXTime = %s -> %s    [�н���ʱ�䣨CTP���أ�]\n", boost::lexical_cast<std::string>(pOriginal->ExchFFEXTime).c_str(), boost::lexical_cast<std::string>(ExchFFEXTime).c_str());
	}
	else
	{
		fprintf(fp, "\t\tExchFFEXTime = %s    [�н���ʱ�䣨CTP���أ�]\n", boost::lexical_cast<std::string>(ExchFFEXTime).c_str());
	}
	if (compare(ExchServerDateTime, pOriginal->ExchServerDateTime) != 0)
	{
		fprintf(fp, "\t\tExchServerDateTime = %s -> %s    [ϵͳ��ǰʱ��(�ͻ���Уʱ����ʢ���أ�]\n", boost::lexical_cast<std::string>(pOriginal->ExchServerDateTime).c_str(), boost::lexical_cast<std::string>(ExchServerDateTime).c_str());
	}
	else
	{
		fprintf(fp, "\t\tExchServerDateTime = %s    [ϵͳ��ǰʱ��(�ͻ���Уʱ����ʢ���أ�]\n", boost::lexical_cast<std::string>(ExchServerDateTime).c_str());
	}
	if (compare(ErrorID, pOriginal->ErrorID) != 0)
	{
		fprintf(fp, "\t\tErrorID = %s -> %s    [�������]\n", boost::lexical_cast<std::string>(pOriginal->ErrorID).c_str(), boost::lexical_cast<std::string>(ErrorID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tErrorID = %s    [�������]\n", boost::lexical_cast<std::string>(ErrorID).c_str());
	}
	if (compare(ErrorMsg, pOriginal->ErrorMsg) != 0)
	{
		fprintf(fp, "\t\tErrorMsg = %s -> %s    [������Ϣ]\n", boost::lexical_cast<std::string>(pOriginal->ErrorMsg).c_str(), boost::lexical_cast<std::string>(ErrorMsg).c_str());
	}
	else
	{
		fprintf(fp, "\t\tErrorMsg = %s    [������Ϣ]\n", boost::lexical_cast<std::string>(ErrorMsg).c_str());
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
	fprintf(fp, "\t\tTraderID = %s    [�û����루CTP���ص�UserID����ʢ���ص���LoginNo��]\n", boost::lexical_cast<std::string>(TraderID).c_str());
	fprintf(fp, "\t\tAppType = %s    [���׽ӿ�����]\n", boost::lexical_cast<std::string>(AppType).c_str());
	fprintf(fp, "\t\tTerminalID = %s    [�ն˻����]\n", boost::lexical_cast<std::string>(TerminalID).c_str());
	fprintf(fp, "\t\tTerminalType = %s    [�ն˻�����]\n", boost::lexical_cast<std::string>(TerminalType).c_str());
	fprintf(fp, "\t\tSessionID = %s    [�ն˻���ǰ��¼Session]\n", boost::lexical_cast<std::string>(SessionID).c_str());
	fprintf(fp, "\t\tTraderRuntype = %s    [����Ա����ʱ״̬]\n", boost::lexical_cast<std::string>(TraderRuntype).c_str());
	fprintf(fp, "\t\tTradingDay = %s    [�����գ�CTP���أ�]\n", boost::lexical_cast<std::string>(TradingDay).c_str());
	fprintf(fp, "\t\tIsActive = %s    [����Ա��ǰ�����Ƿ��Ծ]\n", boost::lexical_cast<std::string>(IsActive).c_str());
	fprintf(fp, "\t\tUpdateTime = %s    [ʵ���˻�״̬����ʱ��]\n", boost::lexical_cast<std::string>(UpdateTime).c_str());
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
		fprintf(fp, "\t\tTraderID = %s -> %s    [�û����루CTP���ص�UserID����ʢ���ص���LoginNo��]\n", boost::lexical_cast<std::string>(pOriginal->TraderID).c_str(), boost::lexical_cast<std::string>(TraderID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTraderID = %s    [�û����루CTP���ص�UserID����ʢ���ص���LoginNo��]\n", boost::lexical_cast<std::string>(TraderID).c_str());
	}
	if (compare(AppType, pOriginal->AppType) != 0)
	{
		fprintf(fp, "\t\tAppType = %s -> %s    [���׽ӿ�����]\n", boost::lexical_cast<std::string>(pOriginal->AppType).c_str(), boost::lexical_cast<std::string>(AppType).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAppType = %s    [���׽ӿ�����]\n", boost::lexical_cast<std::string>(AppType).c_str());
	}
	if (compare(TerminalID, pOriginal->TerminalID) != 0)
	{
		fprintf(fp, "\t\tTerminalID = %s -> %s    [�ն˻����]\n", boost::lexical_cast<std::string>(pOriginal->TerminalID).c_str(), boost::lexical_cast<std::string>(TerminalID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTerminalID = %s    [�ն˻����]\n", boost::lexical_cast<std::string>(TerminalID).c_str());
	}
	if (compare(TerminalType, pOriginal->TerminalType) != 0)
	{
		fprintf(fp, "\t\tTerminalType = %s -> %s    [�ն˻�����]\n", boost::lexical_cast<std::string>(pOriginal->TerminalType).c_str(), boost::lexical_cast<std::string>(TerminalType).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTerminalType = %s    [�ն˻�����]\n", boost::lexical_cast<std::string>(TerminalType).c_str());
	}
	if (compare(SessionID, pOriginal->SessionID) != 0)
	{
		fprintf(fp, "\t\tSessionID = %s -> %s    [�ն˻���ǰ��¼Session]\n", boost::lexical_cast<std::string>(pOriginal->SessionID).c_str(), boost::lexical_cast<std::string>(SessionID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tSessionID = %s    [�ն˻���ǰ��¼Session]\n", boost::lexical_cast<std::string>(SessionID).c_str());
	}
	if (compare(TraderRuntype, pOriginal->TraderRuntype) != 0)
	{
		fprintf(fp, "\t\tTraderRuntype = %s -> %s    [����Ա����ʱ״̬]\n", boost::lexical_cast<std::string>(pOriginal->TraderRuntype).c_str(), boost::lexical_cast<std::string>(TraderRuntype).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTraderRuntype = %s    [����Ա����ʱ״̬]\n", boost::lexical_cast<std::string>(TraderRuntype).c_str());
	}
	if (compare(TradingDay, pOriginal->TradingDay) != 0)
	{
		fprintf(fp, "\t\tTradingDay = %s -> %s    [�����գ�CTP���أ�]\n", boost::lexical_cast<std::string>(pOriginal->TradingDay).c_str(), boost::lexical_cast<std::string>(TradingDay).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTradingDay = %s    [�����գ�CTP���أ�]\n", boost::lexical_cast<std::string>(TradingDay).c_str());
	}
	if (compare(IsActive, pOriginal->IsActive) != 0)
	{
		fprintf(fp, "\t\tIsActive = %s -> %s    [����Ա��ǰ�����Ƿ��Ծ]\n", boost::lexical_cast<std::string>(pOriginal->IsActive).c_str(), boost::lexical_cast<std::string>(IsActive).c_str());
	}
	else
	{
		fprintf(fp, "\t\tIsActive = %s    [����Ա��ǰ�����Ƿ��Ծ]\n", boost::lexical_cast<std::string>(IsActive).c_str());
	}
	if (compare(UpdateTime, pOriginal->UpdateTime) != 0)
	{
		fprintf(fp, "\t\tUpdateTime = %s -> %s    [ʵ���˻�״̬����ʱ��]\n", boost::lexical_cast<std::string>(pOriginal->UpdateTime).c_str(), boost::lexical_cast<std::string>(UpdateTime).c_str());
	}
	else
	{
		fprintf(fp, "\t\tUpdateTime = %s    [ʵ���˻�״̬����ʱ��]\n", boost::lexical_cast<std::string>(UpdateTime).c_str());
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
	fprintf(fp, "\t\tTraderID = %s    [����Ա����]\n", boost::lexical_cast<std::string>(TraderID).c_str());
	fprintf(fp, "\t\tAppType = %s    [���׽ӿ�����]\n", boost::lexical_cast<std::string>(AppType).c_str());
	fprintf(fp, "\t\tTerminalType = %s    [����Ա��¼���]\n", boost::lexical_cast<std::string>(TerminalType).c_str());
	fprintf(fp, "\t\tCertInfo = %s    [��֤��Ϣ]\n", boost::lexical_cast<std::string>(CertInfo).c_str());
	fprintf(fp, "\t\tSecretKey = %s    [API��Կ]\n", boost::lexical_cast<std::string>(SecretKey).c_str());
	fprintf(fp, "\t\tIsOption = %s    [�Ƿ�����Ȩ]\n", boost::lexical_cast<std::string>(IsOption).c_str());
	fprintf(fp, "\t\tAppID = %s    [�ͻ��˲�Ʒ��Ϣ]\n", boost::lexical_cast<std::string>(AppID).c_str());
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
		fprintf(fp, "\t\tTraderID = %s -> %s    [����Ա����]\n", boost::lexical_cast<std::string>(pOriginal->TraderID).c_str(), boost::lexical_cast<std::string>(TraderID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTraderID = %s    [����Ա����]\n", boost::lexical_cast<std::string>(TraderID).c_str());
	}
	if (compare(AppType, pOriginal->AppType) != 0)
	{
		fprintf(fp, "\t\tAppType = %s -> %s    [���׽ӿ�����]\n", boost::lexical_cast<std::string>(pOriginal->AppType).c_str(), boost::lexical_cast<std::string>(AppType).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAppType = %s    [���׽ӿ�����]\n", boost::lexical_cast<std::string>(AppType).c_str());
	}
	if (compare(TerminalType, pOriginal->TerminalType) != 0)
	{
		fprintf(fp, "\t\tTerminalType = %s -> %s    [����Ա��¼���]\n", boost::lexical_cast<std::string>(pOriginal->TerminalType).c_str(), boost::lexical_cast<std::string>(TerminalType).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTerminalType = %s    [����Ա��¼���]\n", boost::lexical_cast<std::string>(TerminalType).c_str());
	}
	if (compare(CertInfo, pOriginal->CertInfo) != 0)
	{
		fprintf(fp, "\t\tCertInfo = %s -> %s    [��֤��Ϣ]\n", boost::lexical_cast<std::string>(pOriginal->CertInfo).c_str(), boost::lexical_cast<std::string>(CertInfo).c_str());
	}
	else
	{
		fprintf(fp, "\t\tCertInfo = %s    [��֤��Ϣ]\n", boost::lexical_cast<std::string>(CertInfo).c_str());
	}
	if (compare(SecretKey, pOriginal->SecretKey) != 0)
	{
		fprintf(fp, "\t\tSecretKey = %s -> %s    [API��Կ]\n", boost::lexical_cast<std::string>(pOriginal->SecretKey).c_str(), boost::lexical_cast<std::string>(SecretKey).c_str());
	}
	else
	{
		fprintf(fp, "\t\tSecretKey = %s    [API��Կ]\n", boost::lexical_cast<std::string>(SecretKey).c_str());
	}
	if (compare(IsOption, pOriginal->IsOption) != 0)
	{
		fprintf(fp, "\t\tIsOption = %s -> %s    [�Ƿ�����Ȩ]\n", boost::lexical_cast<std::string>(pOriginal->IsOption).c_str(), boost::lexical_cast<std::string>(IsOption).c_str());
	}
	else
	{
		fprintf(fp, "\t\tIsOption = %s    [�Ƿ�����Ȩ]\n", boost::lexical_cast<std::string>(IsOption).c_str());
	}
	if (compare(AppID, pOriginal->AppID) != 0)
	{
		fprintf(fp, "\t\tAppID = %s -> %s    [�ͻ��˲�Ʒ��Ϣ]\n", boost::lexical_cast<std::string>(pOriginal->AppID).c_str(), boost::lexical_cast<std::string>(AppID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAppID = %s    [�ͻ��˲�Ʒ��Ϣ]\n", boost::lexical_cast<std::string>(AppID).c_str());
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
	fprintf(fp, "\t\tUserID = %s    [�û�����]\n", boost::lexical_cast<std::string>(UserID).c_str());
	fprintf(fp, "\t\tUserGroupID = %s    [�û����������]\n", boost::lexical_cast<std::string>(UserGroupID).c_str());
	fprintf(fp, "\t\tUserName = %s    [�û�����]\n", boost::lexical_cast<std::string>(UserName).c_str());
	fprintf(fp, "\t\tUserType = %s    [�û�����]\n", boost::lexical_cast<std::string>(UserType).c_str());
	fprintf(fp, "\t\tPassword = %s    [����]\n", boost::lexical_cast<std::string>(Password).c_str());
	fprintf(fp, "\t\tUserStatus = %s    [�û�״̬]\n", boost::lexical_cast<std::string>(UserStatus).c_str());
	fprintf(fp, "\t\tTradeRight = %s    [����ԱȨ��]\n", boost::lexical_cast<std::string>(TradeRight).c_str());
	fprintf(fp, "\t\tIsActive = %s    [�Ƿ��Ծ]\n", boost::lexical_cast<std::string>(IsActive).c_str());
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
		fprintf(fp, "\t\tUserID = %s -> %s    [�û�����]\n", boost::lexical_cast<std::string>(pOriginal->UserID).c_str(), boost::lexical_cast<std::string>(UserID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tUserID = %s    [�û�����]\n", boost::lexical_cast<std::string>(UserID).c_str());
	}
	if (compare(UserGroupID, pOriginal->UserGroupID) != 0)
	{
		fprintf(fp, "\t\tUserGroupID = %s -> %s    [�û����������]\n", boost::lexical_cast<std::string>(pOriginal->UserGroupID).c_str(), boost::lexical_cast<std::string>(UserGroupID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tUserGroupID = %s    [�û����������]\n", boost::lexical_cast<std::string>(UserGroupID).c_str());
	}
	if (compare(UserName, pOriginal->UserName) != 0)
	{
		fprintf(fp, "\t\tUserName = %s -> %s    [�û�����]\n", boost::lexical_cast<std::string>(pOriginal->UserName).c_str(), boost::lexical_cast<std::string>(UserName).c_str());
	}
	else
	{
		fprintf(fp, "\t\tUserName = %s    [�û�����]\n", boost::lexical_cast<std::string>(UserName).c_str());
	}
	if (compare(UserType, pOriginal->UserType) != 0)
	{
		fprintf(fp, "\t\tUserType = %s -> %s    [�û�����]\n", boost::lexical_cast<std::string>(pOriginal->UserType).c_str(), boost::lexical_cast<std::string>(UserType).c_str());
	}
	else
	{
		fprintf(fp, "\t\tUserType = %s    [�û�����]\n", boost::lexical_cast<std::string>(UserType).c_str());
	}
	if (compare(Password, pOriginal->Password) != 0)
	{
		fprintf(fp, "\t\tPassword = %s -> %s    [����]\n", boost::lexical_cast<std::string>(pOriginal->Password).c_str(), boost::lexical_cast<std::string>(Password).c_str());
	}
	else
	{
		fprintf(fp, "\t\tPassword = %s    [����]\n", boost::lexical_cast<std::string>(Password).c_str());
	}
	if (compare(UserStatus, pOriginal->UserStatus) != 0)
	{
		fprintf(fp, "\t\tUserStatus = %s -> %s    [�û�״̬]\n", boost::lexical_cast<std::string>(pOriginal->UserStatus).c_str(), boost::lexical_cast<std::string>(UserStatus).c_str());
	}
	else
	{
		fprintf(fp, "\t\tUserStatus = %s    [�û�״̬]\n", boost::lexical_cast<std::string>(UserStatus).c_str());
	}
	if (compare(TradeRight, pOriginal->TradeRight) != 0)
	{
		fprintf(fp, "\t\tTradeRight = %s -> %s    [����ԱȨ��]\n", boost::lexical_cast<std::string>(pOriginal->TradeRight).c_str(), boost::lexical_cast<std::string>(TradeRight).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTradeRight = %s    [����ԱȨ��]\n", boost::lexical_cast<std::string>(TradeRight).c_str());
	}
	if (compare(IsActive, pOriginal->IsActive) != 0)
	{
		fprintf(fp, "\t\tIsActive = %s -> %s    [�Ƿ��Ծ]\n", boost::lexical_cast<std::string>(pOriginal->IsActive).c_str(), boost::lexical_cast<std::string>(IsActive).c_str());
	}
	else
	{
		fprintf(fp, "\t\tIsActive = %s    [�Ƿ��Ծ]\n", boost::lexical_cast<std::string>(IsActive).c_str());
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

void CUserTrader::init(void)
{
	memset(this, 0, sizeof(CUserTrader));
}

int CUserTrader::read(FILE *input)
{
	if (fread(this, 1, sizeof(CUserTrader), input) != sizeof(CUserTrader))
		return 0;
	else
		return 1;
}

int CUserTrader::write(FILE *output) const
{
	if (fwrite(this, 1, sizeof(CUserTrader), output) != sizeof(CUserTrader))
		return 0;
	else
		return 1;
}

void CUserTrader::dump(FILE *fp, int index) const
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
	fprintf(fp, "\tCUserTrader%s = {\n", index_buf);
	fprintf(fp, "\t\tUserID = %s    [�û�����]\n", boost::lexical_cast<std::string>(UserID).c_str());
	fprintf(fp, "\t\tTraderID = %s    [ʵ���˻�����]\n", boost::lexical_cast<std::string>(TraderID).c_str());
	fprintf(fp, "\t}\n");
}

void CUserTrader::dumpDiff(FILE *fp, const CUserTrader *pOriginal) const
{
	if (fp == nullptr)
	{
		fp = stdout;
	}
	fprintf(fp, "\tCUserTrader = {\n");
	if (compare(UserID, pOriginal->UserID) != 0)
	{
		fprintf(fp, "\t\tUserID = %s -> %s    [�û�����]\n", boost::lexical_cast<std::string>(pOriginal->UserID).c_str(), boost::lexical_cast<std::string>(UserID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tUserID = %s    [�û�����]\n", boost::lexical_cast<std::string>(UserID).c_str());
	}
	if (compare(TraderID, pOriginal->TraderID) != 0)
	{
		fprintf(fp, "\t\tTraderID = %s -> %s    [ʵ���˻�����]\n", boost::lexical_cast<std::string>(pOriginal->TraderID).c_str(), boost::lexical_cast<std::string>(TraderID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTraderID = %s    [ʵ���˻�����]\n", boost::lexical_cast<std::string>(TraderID).c_str());
	}
	fprintf(fp, "\t}\n");
}

void CUserTrader::dumpInLine(FILE *fp) const
{
	if (fp == nullptr)
	{
		fp = stdout;
	}
	std::stringstream sbuf;

	sbuf << ",UserID," << UserID;
	sbuf << ",TraderID," << TraderID;
	fprintf(fp, "%s", sbuf.str().c_str());
}

void CUserTrader::dumpString(char *target) const
{
	char *p = target;
	std::stringstream sbuf;

	sbuf << "UserID=" << UserID << ",";
	sbuf << "TraderID=" << TraderID << ",";
	sprintf(p, "%s", sbuf.str().c_str());
}

void CUserFunctionRight::init(void)
{
	memset(this, 0, sizeof(CUserFunctionRight));
}

int CUserFunctionRight::read(FILE *input)
{
	if (fread(this, 1, sizeof(CUserFunctionRight), input) != sizeof(CUserFunctionRight))
		return 0;
	else
		return 1;
}

int CUserFunctionRight::write(FILE *output) const
{
	if (fwrite(this, 1, sizeof(CUserFunctionRight), output) != sizeof(CUserFunctionRight))
		return 0;
	else
		return 1;
}

void CUserFunctionRight::dump(FILE *fp, int index) const
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
	fprintf(fp, "\tCUserFunctionRight%s = {\n", index_buf);
	fprintf(fp, "\t\tUserID = %s    [�û�����]\n", boost::lexical_cast<std::string>(UserID).c_str());
	fprintf(fp, "\t\tFunctionCode = %s    [���ܴ���]\n", boost::lexical_cast<std::string>(FunctionCode).c_str());
	fprintf(fp, "\t}\n");
}

void CUserFunctionRight::dumpDiff(FILE *fp, const CUserFunctionRight *pOriginal) const
{
	if (fp == nullptr)
	{
		fp = stdout;
	}
	fprintf(fp, "\tCUserFunctionRight = {\n");
	if (compare(UserID, pOriginal->UserID) != 0)
	{
		fprintf(fp, "\t\tUserID = %s -> %s    [�û�����]\n", boost::lexical_cast<std::string>(pOriginal->UserID).c_str(), boost::lexical_cast<std::string>(UserID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tUserID = %s    [�û�����]\n", boost::lexical_cast<std::string>(UserID).c_str());
	}
	if (compare(FunctionCode, pOriginal->FunctionCode) != 0)
	{
		fprintf(fp, "\t\tFunctionCode = %s -> %s    [���ܴ���]\n", boost::lexical_cast<std::string>(pOriginal->FunctionCode).c_str(), boost::lexical_cast<std::string>(FunctionCode).c_str());
	}
	else
	{
		fprintf(fp, "\t\tFunctionCode = %s    [���ܴ���]\n", boost::lexical_cast<std::string>(FunctionCode).c_str());
	}
	fprintf(fp, "\t}\n");
}

void CUserFunctionRight::dumpInLine(FILE *fp) const
{
	if (fp == nullptr)
	{
		fp = stdout;
	}
	std::stringstream sbuf;

	sbuf << ",UserID," << UserID;
	sbuf << ",FunctionCode," << FunctionCode;
	fprintf(fp, "%s", sbuf.str().c_str());
}

void CUserFunctionRight::dumpString(char *target) const
{
	char *p = target;
	std::stringstream sbuf;

	sbuf << "UserID=" << UserID << ",";
	sbuf << "FunctionCode=" << FunctionCode << ",";

	sprintf(p, "%s", sbuf.str().c_str());
}

void CSysInfo::init(void)
{
	memset(this, 0, sizeof(CSysInfo));
}

int CSysInfo::read(FILE *input)
{
	if (fread(this, 1, sizeof(CSysInfo), input) != sizeof(CSysInfo))
		return 0;
	else
		return 1;
}

int CSysInfo::write(FILE *output) const
{
	if (fwrite(this, 1, sizeof(CSysInfo), output) != sizeof(CSysInfo))
		return 0;
	else
		return 1;
}

void CSysInfo::dump(FILE *fp, int index) const
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
	fprintf(fp, "\tCSysInfo%s = {\n", index_buf);
	fprintf(fp, "\t\tCertInfo = %s    [��֤��Ϣ]\n", boost::lexical_cast<std::string>(CertInfo).c_str());
	fprintf(fp, "\t\tAppID = %s    [Ӧ�ó���ID]\n", boost::lexical_cast<std::string>(AppID).c_str());
	fprintf(fp, "\t\tLogPath = %s    [��־λ��]\n", boost::lexical_cast<std::string>(LogPath).c_str());
	fprintf(fp, "\t}\n");
}

void CSysInfo::dumpDiff(FILE *fp, const CSysInfo *pOriginal) const
{
	if (fp == nullptr)
	{
		fp = stdout;
	}
	fprintf(fp, "\tCSysInfo = {\n");
	if (compare(CertInfo, pOriginal->CertInfo) != 0)
	{
		fprintf(fp, "\t\tCertInfo = %s -> %s    [��֤��Ϣ]\n", boost::lexical_cast<std::string>(pOriginal->CertInfo).c_str(), boost::lexical_cast<std::string>(CertInfo).c_str());
	}
	else
	{
		fprintf(fp, "\t\tCertInfo = %s    [��֤��Ϣ]\n", boost::lexical_cast<std::string>(CertInfo).c_str());
	}
	if (compare(AppID, pOriginal->AppID) != 0)
	{
		fprintf(fp, "\t\tAppID = %s -> %s    [Ӧ�ó���ID]\n", boost::lexical_cast<std::string>(pOriginal->AppID).c_str(), boost::lexical_cast<std::string>(AppID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAppID = %s    [Ӧ�ó���ID]\n", boost::lexical_cast<std::string>(AppID).c_str());
	}
	if (compare(LogPath, pOriginal->LogPath) != 0)
	{
		fprintf(fp, "\t\tLogPath = %s -> %s    [��־λ��]\n", boost::lexical_cast<std::string>(pOriginal->LogPath).c_str(), boost::lexical_cast<std::string>(LogPath).c_str());
	}
	else
	{
		fprintf(fp, "\t\tLogPath = %s    [��־λ��]\n", boost::lexical_cast<std::string>(LogPath).c_str());
	}
	fprintf(fp, "\t}\n");
}

void CSysInfo::dumpInLine(FILE *fp) const
{
	if (fp == nullptr)
	{
		fp = stdout;
	}
	std::stringstream sbuf;

	sbuf << ",CertInfo," << CertInfo;
	sbuf << ",AppID," << AppID;
	sbuf << ",LogPath," << LogPath;
	fprintf(fp, "%s", sbuf.str().c_str());
}

void CSysInfo::dumpString(char *target) const
{
	char *p = target;

	std::stringstream sbuf;

	sbuf << "CertInfo=" << CertInfo << ",";
	sbuf << "AppID=" << AppID << ",";
	sbuf << "LogPath=" << LogPath << ",";

	sprintf(p, "%s", sbuf.str().c_str());
}

void CUserSession::init(void)
{
	memset(this, 0, sizeof(CUserSession));
}

int CUserSession::read(FILE *input)
{
	if (fread(this, 1, sizeof(CUserSession), input) != sizeof(CUserSession))
		return 0;
	else
		return 1;
}

int CUserSession::write(FILE *output) const
{
	if (fwrite(this, 1, sizeof(CUserSession), output) != sizeof(CUserSession))
		return 0;
	else
		return 1;
}

void CUserSession::dump(FILE *fp, int index) const
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
	fprintf(fp, "\tCUserSession%s = {\n", index_buf);
	fprintf(fp, "\t\tFrontID = %s    [ǰ�ñ��]\n", boost::lexical_cast<std::string>(FrontID).c_str());
	fprintf(fp, "\t\tUserID = %s    [�û�����]\n", boost::lexical_cast<std::string>(UserID).c_str());
	fprintf(fp, "\t\tUserType = %s    [�����û�����]\n", boost::lexical_cast<std::string>(UserType).c_str());
	fprintf(fp, "\t\tSessionID = %s    [�Ự���]\n", boost::lexical_cast<std::string>(SessionID).c_str());
	fprintf(fp, "\t\tTradingDay = %s    [ϵͳ������]\n", boost::lexical_cast<std::string>(TradingDay).c_str());
	fprintf(fp, "\t\tLoginTime = %s    [��¼ʱ��]\n", boost::lexical_cast<std::string>(LoginTime).c_str());
	fprintf(fp, "\t\tIPAddress = %s    [IP��ַ]\n", boost::lexical_cast<std::string>(IPAddress).c_str());
	fprintf(fp, "\t\tUserProductInfo = %s    [�û��˲�Ʒ��Ϣ]\n", boost::lexical_cast<std::string>(UserProductInfo).c_str());
	fprintf(fp, "\t\tInterfaceProductInfo = %s    [�ӿڶ˲�Ʒ��Ϣ]\n", boost::lexical_cast<std::string>(InterfaceProductInfo).c_str());
	fprintf(fp, "\t\tProtocolInfo = %s    [Э����Ϣ]\n", boost::lexical_cast<std::string>(ProtocolInfo).c_str());
	fprintf(fp, "\t\tSystemName = %s    [ϵͳ����]\n", boost::lexical_cast<std::string>(SystemName).c_str());
	fprintf(fp, "\t\tMaxOrderRef = %s    [��󱨵�����]\n", boost::lexical_cast<std::string>(MaxOrderRef).c_str());
	fprintf(fp, "\t\tSHFETime = %s    [������ʱ��]\n", boost::lexical_cast<std::string>(SHFETime).c_str());
	fprintf(fp, "\t\tDCETime = %s    [������ʱ��]\n", boost::lexical_cast<std::string>(DCETime).c_str());
	fprintf(fp, "\t\tCZCETime = %s    [֣����ʱ��]\n", boost::lexical_cast<std::string>(CZCETime).c_str());
	fprintf(fp, "\t\tFFEXTime = %s    [�н���ʱ��]\n", boost::lexical_cast<std::string>(FFEXTime).c_str());
	fprintf(fp, "\t\tMacAddress = %s    [Mac��ַ]\n", boost::lexical_cast<std::string>(MacAddress).c_str());
	fprintf(fp, "\t\tOneTimePassword = %s    [��̬����]\n", boost::lexical_cast<std::string>(OneTimePassword).c_str());
	fprintf(fp, "\t}\n");
}

void CUserSession::dumpDiff(FILE *fp, const CUserSession *pOriginal) const
{
	if (fp == nullptr)
	{
		fp = stdout;
	}
	fprintf(fp, "\tCUserSession = {\n");
	if (compare(FrontID, pOriginal->FrontID) != 0)
	{
		fprintf(fp, "\t\tFrontID = %s -> %s    [ǰ�ñ��]\n", boost::lexical_cast<std::string>(pOriginal->FrontID).c_str(), boost::lexical_cast<std::string>(FrontID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tFrontID = %s    [ǰ�ñ��]\n", boost::lexical_cast<std::string>(FrontID).c_str());
	}
	if (compare(UserID, pOriginal->UserID) != 0)
	{
		fprintf(fp, "\t\tUserID = %s -> %s    [�û�����]\n", boost::lexical_cast<std::string>(pOriginal->UserID).c_str(), boost::lexical_cast<std::string>(UserID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tUserID = %s    [�û�����]\n", boost::lexical_cast<std::string>(UserID).c_str());
	}
	if (compare(UserType, pOriginal->UserType) != 0)
	{
		fprintf(fp, "\t\tUserType = %s -> %s    [�����û�����]\n", boost::lexical_cast<std::string>(pOriginal->UserType).c_str(), boost::lexical_cast<std::string>(UserType).c_str());
	}
	else
	{
		fprintf(fp, "\t\tUserType = %s    [�����û�����]\n", boost::lexical_cast<std::string>(UserType).c_str());
	}
	if (compare(SessionID, pOriginal->SessionID) != 0)
	{
		fprintf(fp, "\t\tSessionID = %s -> %s    [�Ự���]\n", boost::lexical_cast<std::string>(pOriginal->SessionID).c_str(), boost::lexical_cast<std::string>(SessionID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tSessionID = %s    [�Ự���]\n", boost::lexical_cast<std::string>(SessionID).c_str());
	}
	if (compare(TradingDay, pOriginal->TradingDay) != 0)
	{
		fprintf(fp, "\t\tTradingDay = %s -> %s    [ϵͳ������]\n", boost::lexical_cast<std::string>(pOriginal->TradingDay).c_str(), boost::lexical_cast<std::string>(TradingDay).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTradingDay = %s    [ϵͳ������]\n", boost::lexical_cast<std::string>(TradingDay).c_str());
	}
	if (compare(LoginTime, pOriginal->LoginTime) != 0)
	{
		fprintf(fp, "\t\tLoginTime = %s -> %s    [��¼ʱ��]\n", boost::lexical_cast<std::string>(pOriginal->LoginTime).c_str(), boost::lexical_cast<std::string>(LoginTime).c_str());
	}
	else
	{
		fprintf(fp, "\t\tLoginTime = %s    [��¼ʱ��]\n", boost::lexical_cast<std::string>(LoginTime).c_str());
	}
	if (compare(IPAddress, pOriginal->IPAddress) != 0)
	{
		fprintf(fp, "\t\tIPAddress = %s -> %s    [IP��ַ]\n", boost::lexical_cast<std::string>(pOriginal->IPAddress).c_str(), boost::lexical_cast<std::string>(IPAddress).c_str());
	}
	else
	{
		fprintf(fp, "\t\tIPAddress = %s    [IP��ַ]\n", boost::lexical_cast<std::string>(IPAddress).c_str());
	}
	if (compare(UserProductInfo, pOriginal->UserProductInfo) != 0)
	{
		fprintf(fp, "\t\tUserProductInfo = %s -> %s    [�û��˲�Ʒ��Ϣ]\n", boost::lexical_cast<std::string>(pOriginal->UserProductInfo).c_str(), boost::lexical_cast<std::string>(UserProductInfo).c_str());
	}
	else
	{
		fprintf(fp, "\t\tUserProductInfo = %s    [�û��˲�Ʒ��Ϣ]\n", boost::lexical_cast<std::string>(UserProductInfo).c_str());
	}
	if (compare(InterfaceProductInfo, pOriginal->InterfaceProductInfo) != 0)
	{
		fprintf(fp, "\t\tInterfaceProductInfo = %s -> %s    [�ӿڶ˲�Ʒ��Ϣ]\n", boost::lexical_cast<std::string>(pOriginal->InterfaceProductInfo).c_str(), boost::lexical_cast<std::string>(InterfaceProductInfo).c_str());
	}
	else
	{
		fprintf(fp, "\t\tInterfaceProductInfo = %s    [�ӿڶ˲�Ʒ��Ϣ]\n", boost::lexical_cast<std::string>(InterfaceProductInfo).c_str());
	}
	if (compare(ProtocolInfo, pOriginal->ProtocolInfo) != 0)
	{
		fprintf(fp, "\t\tProtocolInfo = %s -> %s    [Э����Ϣ]\n", boost::lexical_cast<std::string>(pOriginal->ProtocolInfo).c_str(), boost::lexical_cast<std::string>(ProtocolInfo).c_str());
	}
	else
	{
		fprintf(fp, "\t\tProtocolInfo = %s    [Э����Ϣ]\n", boost::lexical_cast<std::string>(ProtocolInfo).c_str());
	}
	if (compare(SystemName, pOriginal->SystemName) != 0)
	{
		fprintf(fp, "\t\tSystemName = %s -> %s    [ϵͳ����]\n", boost::lexical_cast<std::string>(pOriginal->SystemName).c_str(), boost::lexical_cast<std::string>(SystemName).c_str());
	}
	else
	{
		fprintf(fp, "\t\tSystemName = %s    [ϵͳ����]\n", boost::lexical_cast<std::string>(SystemName).c_str());
	}
	if (compare(MaxOrderRef, pOriginal->MaxOrderRef) != 0)
	{
		fprintf(fp, "\t\tMaxOrderRef = %s -> %s    [��󱨵�����]\n", boost::lexical_cast<std::string>(pOriginal->MaxOrderRef).c_str(), boost::lexical_cast<std::string>(MaxOrderRef).c_str());
	}
	else
	{
		fprintf(fp, "\t\tMaxOrderRef = %s    [��󱨵�����]\n", boost::lexical_cast<std::string>(MaxOrderRef).c_str());
	}
	if (compare(SHFETime, pOriginal->SHFETime) != 0)
	{
		fprintf(fp, "\t\tSHFETime = %s -> %s    [������ʱ��]\n", boost::lexical_cast<std::string>(pOriginal->SHFETime).c_str(), boost::lexical_cast<std::string>(SHFETime).c_str());
	}
	else
	{
		fprintf(fp, "\t\tSHFETime = %s    [������ʱ��]\n", boost::lexical_cast<std::string>(SHFETime).c_str());
	}
	if (compare(DCETime, pOriginal->DCETime) != 0)
	{
		fprintf(fp, "\t\tDCETime = %s -> %s    [������ʱ��]\n", boost::lexical_cast<std::string>(pOriginal->DCETime).c_str(), boost::lexical_cast<std::string>(DCETime).c_str());
	}
	else
	{
		fprintf(fp, "\t\tDCETime = %s    [������ʱ��]\n", boost::lexical_cast<std::string>(DCETime).c_str());
	}
	if (compare(CZCETime, pOriginal->CZCETime) != 0)
	{
		fprintf(fp, "\t\tCZCETime = %s -> %s    [֣����ʱ��]\n", boost::lexical_cast<std::string>(pOriginal->CZCETime).c_str(), boost::lexical_cast<std::string>(CZCETime).c_str());
	}
	else
	{
		fprintf(fp, "\t\tCZCETime = %s    [֣����ʱ��]\n", boost::lexical_cast<std::string>(CZCETime).c_str());
	}
	if (compare(FFEXTime, pOriginal->FFEXTime) != 0)
	{
		fprintf(fp, "\t\tFFEXTime = %s -> %s    [�н���ʱ��]\n", boost::lexical_cast<std::string>(pOriginal->FFEXTime).c_str(), boost::lexical_cast<std::string>(FFEXTime).c_str());
	}
	else
	{
		fprintf(fp, "\t\tFFEXTime = %s    [�н���ʱ��]\n", boost::lexical_cast<std::string>(FFEXTime).c_str());
	}
	if (compare(MacAddress, pOriginal->MacAddress) != 0)
	{
		fprintf(fp, "\t\tMacAddress = %s -> %s    [Mac��ַ]\n", boost::lexical_cast<std::string>(pOriginal->MacAddress).c_str(), boost::lexical_cast<std::string>(MacAddress).c_str());
	}
	else
	{
		fprintf(fp, "\t\tMacAddress = %s    [Mac��ַ]\n", boost::lexical_cast<std::string>(MacAddress).c_str());
	}
	if (compare(OneTimePassword, pOriginal->OneTimePassword) != 0)
	{
		fprintf(fp, "\t\tOneTimePassword = %s -> %s    [��̬����]\n", boost::lexical_cast<std::string>(pOriginal->OneTimePassword).c_str(), boost::lexical_cast<std::string>(OneTimePassword).c_str());
	}
	else
	{
		fprintf(fp, "\t\tOneTimePassword = %s    [��̬����]\n", boost::lexical_cast<std::string>(OneTimePassword).c_str());
	}
	fprintf(fp, "\t}\n");
}

void CUserSession::dumpInLine(FILE *fp) const
{
	if (fp == nullptr)
	{
		fp = stdout;
	}
	std::stringstream sbuf;

	sbuf << ",FrontID," << FrontID;
	sbuf << ",UserID," << UserID;
	sbuf << ",UserType," << UserType;
	sbuf << ",SessionID," << SessionID;
	sbuf << ",TradingDay," << TradingDay;
	sbuf << ",LoginTime," << LoginTime;
	sbuf << ",IPAddress," << IPAddress;
	sbuf << ",UserProductInfo," << UserProductInfo;
	sbuf << ",InterfaceProductInfo," << InterfaceProductInfo;
	sbuf << ",ProtocolInfo," << ProtocolInfo;
	sbuf << ",SystemName," << SystemName;
	sbuf << ",MaxOrderRef," << MaxOrderRef;
	sbuf << ",SHFETime," << SHFETime;
	sbuf << ",DCETime," << DCETime;
	sbuf << ",CZCETime," << CZCETime;
	sbuf << ",FFEXTime," << FFEXTime;
	sbuf << ",MacAddress," << MacAddress;
	sbuf << ",OneTimePassword," << OneTimePassword;
	fprintf(fp, "%s", sbuf.str().c_str());
}

void CUserSession::dumpString(char *target) const
{
	char *p = target;
	std::stringstream sbuf;

	sbuf << "FrontID=" << FrontID << ",";
	sbuf << "UserID=" << UserID << ",";
	sbuf << "UserType=" << UserType << ",";
	sbuf << "SessionID=" << SessionID << ",";
	sbuf << "TradingDay=" << TradingDay << ",";
	sbuf << "LoginTime=" << LoginTime << ",";
	sbuf << "IPAddress=" << IPAddress << ",";
	sbuf << "UserProductInfo=" << UserProductInfo << ",";
	sbuf << "InterfaceProductInfo=" << InterfaceProductInfo << ",";
	sbuf << "ProtocolInfo=" << ProtocolInfo << ",";
	sbuf << "SystemName=" << SystemName << ",";
	sbuf << "MaxOrderRef=" << MaxOrderRef << ",";
	sbuf << "SHFETime=" << SHFETime << ",";
	sbuf << "DCETime=" << DCETime << ",";
	sbuf << "CZCETime=" << CZCETime << ",";
	sbuf << "FFEXTime=" << FFEXTime << ",";
	sbuf << "MacAddress=" << MacAddress << ",";
	sbuf << "OneTimePassword=" << OneTimePassword << ",";

	sprintf(p, "%s", sbuf.str().c_str());
}

void CMDSession::init(void)
{
	memset(this, 0, sizeof(CMDSession));
}

int CMDSession::read(FILE *input)
{
	if (fread(this, 1, sizeof(CMDSession), input) != sizeof(CMDSession))
		return 0;
	else
		return 1;
}

int CMDSession::write(FILE *output) const
{
	if (fwrite(this, 1, sizeof(CMDSession), output) != sizeof(CMDSession))
		return 0;
	else
		return 1;
}

void CMDSession::dump(FILE *fp, int index) const
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
	fprintf(fp, "\tCMDSession%s = {\n", index_buf);
	fprintf(fp, "\t\tFrontID = %s    [ǰ�ñ��]\n", boost::lexical_cast<std::string>(FrontID).c_str());
	fprintf(fp, "\t\tUserID = %s    [�û�����]\n", boost::lexical_cast<std::string>(UserID).c_str());
	fprintf(fp, "\t\tUserType = %s    [�����û�����]\n", boost::lexical_cast<std::string>(UserType).c_str());
	fprintf(fp, "\t\tSessionID = %s    [�Ự���]\n", boost::lexical_cast<std::string>(SessionID).c_str());
	fprintf(fp, "\t\tTradingDay = %s    [ϵͳ������]\n", boost::lexical_cast<std::string>(TradingDay).c_str());
	fprintf(fp, "\t\tLoginTime = %s    [��¼ʱ��]\n", boost::lexical_cast<std::string>(LoginTime).c_str());
	fprintf(fp, "\t\tIPAddress = %s    [IP��ַ]\n", boost::lexical_cast<std::string>(IPAddress).c_str());
	fprintf(fp, "\t\tUserProductInfo = %s    [�û��˲�Ʒ��Ϣ]\n", boost::lexical_cast<std::string>(UserProductInfo).c_str());
	fprintf(fp, "\t\tInterfaceProductInfo = %s    [�ӿڶ˲�Ʒ��Ϣ]\n", boost::lexical_cast<std::string>(InterfaceProductInfo).c_str());
	fprintf(fp, "\t\tProtocolInfo = %s    [Э����Ϣ]\n", boost::lexical_cast<std::string>(ProtocolInfo).c_str());
	fprintf(fp, "\t\tSystemName = %s    [ϵͳ����]\n", boost::lexical_cast<std::string>(SystemName).c_str());
	fprintf(fp, "\t\tMaxOrderRef = %s    [��󱨵�����]\n", boost::lexical_cast<std::string>(MaxOrderRef).c_str());
	fprintf(fp, "\t\tSHFETime = %s    [������ʱ��]\n", boost::lexical_cast<std::string>(SHFETime).c_str());
	fprintf(fp, "\t\tDCETime = %s    [������ʱ��]\n", boost::lexical_cast<std::string>(DCETime).c_str());
	fprintf(fp, "\t\tCZCETime = %s    [֣����ʱ��]\n", boost::lexical_cast<std::string>(CZCETime).c_str());
	fprintf(fp, "\t\tFFEXTime = %s    [�н���ʱ��]\n", boost::lexical_cast<std::string>(FFEXTime).c_str());
	fprintf(fp, "\t\tMacAddress = %s    [Mac��ַ]\n", boost::lexical_cast<std::string>(MacAddress).c_str());
	fprintf(fp, "\t\tOneTimePassword = %s    [��̬����]\n", boost::lexical_cast<std::string>(OneTimePassword).c_str());
	fprintf(fp, "\t}\n");
}

void CMDSession::dumpDiff(FILE *fp, const CMDSession *pOriginal) const
{
	if (fp == NULL)
	{
		fp = stdout;
	}
	fprintf(fp, "\tCMDSession = {\n");
	if (compare(FrontID, pOriginal->FrontID) != 0)
	{
		fprintf(fp, "\t\tFrontID = %s -> %s    [ǰ�ñ��]\n", boost::lexical_cast<std::string>(pOriginal->FrontID).c_str(), boost::lexical_cast<std::string>(FrontID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tFrontID = %s    [ǰ�ñ��]\n", boost::lexical_cast<std::string>(FrontID).c_str());
	}
	if (compare(UserID, pOriginal->UserID) != 0)
	{
		fprintf(fp, "\t\tUserID = %s -> %s    [�û�����]\n", boost::lexical_cast<std::string>(pOriginal->UserID).c_str(), boost::lexical_cast<std::string>(UserID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tUserID = %s    [�û�����]\n", boost::lexical_cast<std::string>(UserID).c_str());
	}
	if (compare(UserType, pOriginal->UserType) != 0)
	{
		fprintf(fp, "\t\tUserType = %s -> %s    [�����û�����]\n", boost::lexical_cast<std::string>(pOriginal->UserType).c_str(), boost::lexical_cast<std::string>(UserType).c_str());
	}
	else
	{
		fprintf(fp, "\t\tUserType = %s    [�����û�����]\n", boost::lexical_cast<std::string>(UserType).c_str());
	}
	if (compare(SessionID, pOriginal->SessionID) != 0)
	{
		fprintf(fp, "\t\tSessionID = %s -> %s    [�Ự���]\n", boost::lexical_cast<std::string>(pOriginal->SessionID).c_str(), boost::lexical_cast<std::string>(SessionID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tSessionID = %s    [�Ự���]\n", boost::lexical_cast<std::string>(SessionID).c_str());
	}
	if (compare(TradingDay, pOriginal->TradingDay) != 0)
	{
		fprintf(fp, "\t\tTradingDay = %s -> %s    [ϵͳ������]\n", boost::lexical_cast<std::string>(pOriginal->TradingDay).c_str(), boost::lexical_cast<std::string>(TradingDay).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTradingDay = %s    [ϵͳ������]\n", boost::lexical_cast<std::string>(TradingDay).c_str());
	}
	if (compare(LoginTime, pOriginal->LoginTime) != 0)
	{
		fprintf(fp, "\t\tLoginTime = %s -> %s    [��¼ʱ��]\n", boost::lexical_cast<std::string>(pOriginal->LoginTime).c_str(), boost::lexical_cast<std::string>(LoginTime).c_str());
	}
	else
	{
		fprintf(fp, "\t\tLoginTime = %s    [��¼ʱ��]\n", boost::lexical_cast<std::string>(LoginTime).c_str());
	}
	if (compare(IPAddress, pOriginal->IPAddress) != 0)
	{
		fprintf(fp, "\t\tIPAddress = %s -> %s    [IP��ַ]\n", boost::lexical_cast<std::string>(pOriginal->IPAddress).c_str(), boost::lexical_cast<std::string>(IPAddress).c_str());
	}
	else
	{
		fprintf(fp, "\t\tIPAddress = %s    [IP��ַ]\n", boost::lexical_cast<std::string>(IPAddress).c_str());
	}
	if (compare(UserProductInfo, pOriginal->UserProductInfo) != 0)
	{
		fprintf(fp, "\t\tUserProductInfo = %s -> %s    [�û��˲�Ʒ��Ϣ]\n", boost::lexical_cast<std::string>(pOriginal->UserProductInfo).c_str(), boost::lexical_cast<std::string>(UserProductInfo).c_str());
	}
	else
	{
		fprintf(fp, "\t\tUserProductInfo = %s    [�û��˲�Ʒ��Ϣ]\n", boost::lexical_cast<std::string>(UserProductInfo).c_str());
	}
	if (compare(InterfaceProductInfo, pOriginal->InterfaceProductInfo) != 0)
	{
		fprintf(fp, "\t\tInterfaceProductInfo = %s -> %s    [�ӿڶ˲�Ʒ��Ϣ]\n", boost::lexical_cast<std::string>(pOriginal->InterfaceProductInfo).c_str(), boost::lexical_cast<std::string>(InterfaceProductInfo).c_str());
	}
	else
	{
		fprintf(fp, "\t\tInterfaceProductInfo = %s    [�ӿڶ˲�Ʒ��Ϣ]\n", boost::lexical_cast<std::string>(InterfaceProductInfo).c_str());
	}
	if (compare(ProtocolInfo, pOriginal->ProtocolInfo) != 0)
	{
		fprintf(fp, "\t\tProtocolInfo = %s -> %s    [Э����Ϣ]\n", boost::lexical_cast<std::string>(pOriginal->ProtocolInfo).c_str(), boost::lexical_cast<std::string>(ProtocolInfo).c_str());
	}
	else
	{
		fprintf(fp, "\t\tProtocolInfo = %s    [Э����Ϣ]\n", boost::lexical_cast<std::string>(ProtocolInfo).c_str());
	}
	if (compare(SystemName, pOriginal->SystemName) != 0)
	{
		fprintf(fp, "\t\tSystemName = %s -> %s    [ϵͳ����]\n", boost::lexical_cast<std::string>(pOriginal->SystemName).c_str(), boost::lexical_cast<std::string>(SystemName).c_str());
	}
	else
	{
		fprintf(fp, "\t\tSystemName = %s    [ϵͳ����]\n", boost::lexical_cast<std::string>(SystemName).c_str());
	}
	if (compare(MaxOrderRef, pOriginal->MaxOrderRef) != 0)
	{
		fprintf(fp, "\t\tMaxOrderRef = %s -> %s    [��󱨵�����]\n", boost::lexical_cast<std::string>(pOriginal->MaxOrderRef).c_str(), boost::lexical_cast<std::string>(MaxOrderRef).c_str());
	}
	else
	{
		fprintf(fp, "\t\tMaxOrderRef = %s    [��󱨵�����]\n", boost::lexical_cast<std::string>(MaxOrderRef).c_str());
	}
	if (compare(SHFETime, pOriginal->SHFETime) != 0)
	{
		fprintf(fp, "\t\tSHFETime = %s -> %s    [������ʱ��]\n", boost::lexical_cast<std::string>(pOriginal->SHFETime).c_str(), boost::lexical_cast<std::string>(SHFETime).c_str());
	}
	else
	{
		fprintf(fp, "\t\tSHFETime = %s    [������ʱ��]\n", boost::lexical_cast<std::string>(SHFETime).c_str());
	}
	if (compare(DCETime, pOriginal->DCETime) != 0)
	{
		fprintf(fp, "\t\tDCETime = %s -> %s    [������ʱ��]\n", boost::lexical_cast<std::string>(pOriginal->DCETime).c_str(), boost::lexical_cast<std::string>(DCETime).c_str());
	}
	else
	{
		fprintf(fp, "\t\tDCETime = %s    [������ʱ��]\n", boost::lexical_cast<std::string>(DCETime).c_str());
	}
	if (compare(CZCETime, pOriginal->CZCETime) != 0)
	{
		fprintf(fp, "\t\tCZCETime = %s -> %s    [֣����ʱ��]\n", boost::lexical_cast<std::string>(pOriginal->CZCETime).c_str(), boost::lexical_cast<std::string>(CZCETime).c_str());
	}
	else
	{
		fprintf(fp, "\t\tCZCETime = %s    [֣����ʱ��]\n", boost::lexical_cast<std::string>(CZCETime).c_str());
	}
	if (compare(FFEXTime, pOriginal->FFEXTime) != 0)
	{
		fprintf(fp, "\t\tFFEXTime = %s -> %s    [�н���ʱ��]\n", boost::lexical_cast<std::string>(pOriginal->FFEXTime).c_str(), boost::lexical_cast<std::string>(FFEXTime).c_str());
	}
	else
	{
		fprintf(fp, "\t\tFFEXTime = %s    [�н���ʱ��]\n", boost::lexical_cast<std::string>(FFEXTime).c_str());
	}
	if (compare(MacAddress, pOriginal->MacAddress) != 0)
	{
		fprintf(fp, "\t\tMacAddress = %s -> %s    [Mac��ַ]\n", boost::lexical_cast<std::string>(pOriginal->MacAddress).c_str(), boost::lexical_cast<std::string>(MacAddress).c_str());
	}
	else
	{
		fprintf(fp, "\t\tMacAddress = %s    [Mac��ַ]\n", boost::lexical_cast<std::string>(MacAddress).c_str());
	}
	if (compare(OneTimePassword, pOriginal->OneTimePassword) != 0)
	{
		fprintf(fp, "\t\tOneTimePassword = %s -> %s    [��̬����]\n", boost::lexical_cast<std::string>(pOriginal->OneTimePassword).c_str(), boost::lexical_cast<std::string>(OneTimePassword).c_str());
	}
	else
	{
		fprintf(fp, "\t\tOneTimePassword = %s    [��̬����]\n", boost::lexical_cast<std::string>(OneTimePassword).c_str());
	}
	fprintf(fp, "\t}\n");
}

void CMDSession::dumpInLine(FILE *fp) const
{
	if (fp == nullptr)
	{
		fp = stdout;
	}
	std::stringstream sbuf;

	sbuf << ",FrontID," << FrontID;
	sbuf << ",UserID," << UserID;
	sbuf << ",UserType," << UserType;
	sbuf << ",SessionID," << SessionID;
	sbuf << ",TradingDay," << TradingDay;
	sbuf << ",LoginTime," << LoginTime;
	sbuf << ",IPAddress," << IPAddress;
	sbuf << ",UserProductInfo," << UserProductInfo;
	sbuf << ",InterfaceProductInfo," << InterfaceProductInfo;
	sbuf << ",ProtocolInfo," << ProtocolInfo;
	sbuf << ",SystemName," << SystemName;
	sbuf << ",MaxOrderRef," << MaxOrderRef;
	sbuf << ",SHFETime," << SHFETime;
	sbuf << ",DCETime," << DCETime;
	sbuf << ",CZCETime," << CZCETime;
	sbuf << ",FFEXTime," << FFEXTime;
	sbuf << ",MacAddress," << MacAddress;
	sbuf << ",OneTimePassword," << OneTimePassword;
	fprintf(fp, "%s", sbuf.str().c_str());
}

void CMDSession::dumpString(char *target) const
{
	char *p = target;
	std::stringstream sbuf;

	sbuf << "FrontID=" << FrontID << ",";
	sbuf << "UserID=" << UserID << ",";
	sbuf << "UserType=" << UserType << ",";
	sbuf << "SessionID=" << SessionID << ",";
	sbuf << "TradingDay=" << TradingDay << ",";
	sbuf << "LoginTime=" << LoginTime << ",";
	sbuf << "IPAddress=" << IPAddress << ",";
	sbuf << "UserProductInfo=" << UserProductInfo << ",";
	sbuf << "InterfaceProductInfo=" << InterfaceProductInfo << ",";
	sbuf << "ProtocolInfo=" << ProtocolInfo << ",";
	sbuf << "SystemName=" << SystemName << ",";
	sbuf << "MaxOrderRef=" << MaxOrderRef << ",";
	sbuf << "SHFETime=" << SHFETime << ",";
	sbuf << "DCETime=" << DCETime << ",";
	sbuf << "CZCETime=" << CZCETime << ",";
	sbuf << "FFEXTime=" << FFEXTime << ",";
	sbuf << "MacAddress=" << MacAddress << ",";
	sbuf << "OneTimePassword=" << OneTimePassword << ",";

	sprintf(p, "%s", sbuf.str().c_str());
}

void CMaxLocalID::init(void)
{
	memset(this, 0, sizeof(CMaxLocalID));
}

int CMaxLocalID::read(FILE *input)
{
	if (fread(this, 1, sizeof(CMaxLocalID), input) != sizeof(CMaxLocalID))
		return 0;
	else
		return 1;
}

int CMaxLocalID::write(FILE *output) const
{
	if (fwrite(this, 1, sizeof(CMaxLocalID), output) != sizeof(CMaxLocalID))
		return 0;
	else
		return 1;
}

void CMaxLocalID::dump(FILE *fp, int index) const
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
	fprintf(fp, "\tCMaxLocalID%s = {\n", index_buf);
	fprintf(fp, "\t\tUserID = %s    [�����û�����]\n", boost::lexical_cast<std::string>(UserID).c_str());
	fprintf(fp, "\t\tMaxOrderLocalID = %s    [��󱨵����ر��]\n", boost::lexical_cast<std::string>(MaxOrderLocalID).c_str());
	fprintf(fp, "\t}\n");
}

void CMaxLocalID::dumpDiff(FILE *fp, const CMaxLocalID *pOriginal) const
{
	if (fp == nullptr)
	{
		fp = stdout;
	}
	fprintf(fp, "\tCMaxLocalID = {\n");
	if (compare(UserID, pOriginal->UserID) != 0)
	{
		fprintf(fp, "\t\tUserID = %s -> %s    [�����û�����]\n", boost::lexical_cast<std::string>(pOriginal->UserID).c_str(), boost::lexical_cast<std::string>(UserID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tUserID = %s    [�����û�����]\n", boost::lexical_cast<std::string>(UserID).c_str());
	}
	if (compare(MaxOrderLocalID, pOriginal->MaxOrderLocalID) != 0)
	{
		fprintf(fp, "\t\tMaxOrderLocalID = %s -> %s    [��󱨵����ر��]\n", boost::lexical_cast<std::string>(pOriginal->MaxOrderLocalID).c_str(), boost::lexical_cast<std::string>(MaxOrderLocalID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tMaxOrderLocalID = %s    [��󱨵����ر��]\n", boost::lexical_cast<std::string>(MaxOrderLocalID).c_str());
	}
	fprintf(fp, "\t}\n");
}

void CMaxLocalID::dumpInLine(FILE *fp) const
{
	if (fp == nullptr)
	{
		fp = stdout;
	}
	std::stringstream sbuf;

	sbuf << ",UserID," << UserID;
	sbuf << ",MaxOrderLocalID," << MaxOrderLocalID;
	fprintf(fp, "%s", sbuf.str().c_str());
}

void CMaxLocalID::dumpString(char *target) const
{
	char *p = target;
	std::stringstream sbuf;

	sbuf << "UserID=" << UserID << ",";
	sbuf << "MaxOrderLocalID=" << MaxOrderLocalID << ",";

	sprintf(p, "%s", sbuf.str().c_str());
}

void CUserSubMarketData::init(void)
{
	memset(this, 0, sizeof(CUserSubMarketData));
}

int CUserSubMarketData::read(FILE *input)
{
	if (fread(this, 1, sizeof(CUserSubMarketData), input) != sizeof(CUserSubMarketData))
		return 0;
	else
		return 1;
}

int CUserSubMarketData::write(FILE *output) const
{
	if (fwrite(this, 1, sizeof(CUserSubMarketData), output) != sizeof(CUserSubMarketData))
		return 0;
	else
		return 1;
}

void CUserSubMarketData::dump(FILE *fp, int index) const
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

	fprintf(fp, "\tCUserSubMarketData%s = {\n", index_buf);
	fprintf(fp, "\t\tUserID = %s    [�û�����]\n", boost::lexical_cast<std::string>(UserID).c_str());
	fprintf(fp, "\t\tFrontID = %s    [ǰ�ñ��]\n", boost::lexical_cast<std::string>(FrontID).c_str());
	fprintf(fp, "\t\tSessionID = %s    [�Ự���]\n", boost::lexical_cast<std::string>(SessionID).c_str());
	fprintf(fp, "\t\tInstrumentID = %s    [��Լ����]\n", boost::lexical_cast<std::string>(InstrumentID).c_str());
	fprintf(fp, "\t}\n");
}

void CUserSubMarketData::dumpDiff(FILE *fp, const CUserSubMarketData *pOriginal) const
{
	if (fp == nullptr)
	{
		fp = stdout;
	}
	fprintf(fp, "\tCUserSubMarketData = {\n");
	if (compare(UserID, pOriginal->UserID) != 0)
	{
		fprintf(fp, "\t\tUserID = %s -> %s    [�û�����]\n", boost::lexical_cast<std::string>(pOriginal->UserID).c_str(), boost::lexical_cast<std::string>(UserID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tUserID = %s    [�û�����]\n", boost::lexical_cast<std::string>(UserID).c_str());
	}
	if (compare(FrontID, pOriginal->FrontID) != 0)
	{
		fprintf(fp, "\t\tFrontID = %s -> %s    [ǰ�ñ��]\n", boost::lexical_cast<std::string>(pOriginal->FrontID).c_str(), boost::lexical_cast<std::string>(FrontID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tFrontID = %s    [ǰ�ñ��]\n", boost::lexical_cast<std::string>(FrontID).c_str());
	}
	if (compare(SessionID, pOriginal->SessionID) != 0)
	{
		fprintf(fp, "\t\tSessionID = %s -> %s    [�Ự���]\n", boost::lexical_cast<std::string>(pOriginal->SessionID).c_str(), boost::lexical_cast<std::string>(SessionID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tSessionID = %s    [�Ự���]\n", boost::lexical_cast<std::string>(SessionID).c_str());
	}
	if (compare(InstrumentID, pOriginal->InstrumentID) != 0)
	{
		fprintf(fp, "\t\tInstrumentID = %s -> %s    [��Լ����]\n", boost::lexical_cast<std::string>(pOriginal->InstrumentID).c_str(), boost::lexical_cast<std::string>(InstrumentID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tInstrumentID = %s    [��Լ����]\n", boost::lexical_cast<std::string>(InstrumentID).c_str());
	}
	fprintf(fp, "\t}\n");
}

void CUserSubMarketData::dumpInLine(FILE *fp) const
{
	if (fp == nullptr)
	{
		fp = stdout;
	}
	std::stringstream sbuf;

	sbuf << ",UserID," << UserID;
	sbuf << ",FrontID," << FrontID;
	sbuf << ",SessionID," << SessionID;
	sbuf << ",InstrumentID," << InstrumentID;
	fprintf(fp, "%s", sbuf.str().c_str());
}

void CUserSubMarketData::dumpString(char *target) const
{
	char *p = target;
	std::stringstream sbuf;
	sbuf << "UserID=" << UserID << ",";
	sbuf << "FrontID=" << FrontID << ",";
	sbuf << "SessionID=" << SessionID << ",";
	sbuf << "InstrumentID=" << InstrumentID << ",";

	sprintf(p, "%s", sbuf.str().c_str());
}

void CDepthMarketData::init(void)
{
	memset(this, 0, sizeof(CDepthMarketData));
}

int CDepthMarketData::read(FILE *input)
{
	if (fread(this, 1, sizeof(CDepthMarketData), input) != sizeof(CDepthMarketData))
		return 0;
	else
		return 1;
}

int CDepthMarketData::write(FILE *output) const
{
	if (fwrite(this, 1, sizeof(CDepthMarketData), output) != sizeof(CDepthMarketData))
		return 0;
	else
		return 1;
}

void CDepthMarketData::dump(FILE *fp, int index) const
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
	fprintf(fp, "\tCDepthMarketData%s = {\n", index_buf);
	fprintf(fp, "\t\tTradingDay = %s    [������]\n", boost::lexical_cast<std::string>(TradingDay).c_str());
	fprintf(fp, "\t\tPreClearPrice = %s    [�����]\n", boost::lexical_cast<std::string>(PreClearPrice).c_str());
	fprintf(fp, "\t\tPreClosePrice = %s    [������]\n", boost::lexical_cast<std::string>(PreClosePrice).c_str());
	fprintf(fp, "\t\tPreOpenInterest = %s    [��ֲ���]\n", boost::lexical_cast<std::string>(PreOpenInterest).c_str());
	fprintf(fp, "\t\tPreDelta = %s    [����ʵ��]\n", boost::lexical_cast<std::string>(PreDelta).c_str());
	fprintf(fp, "\t\tHistoryHigh = %s    [��Լ���]\n", boost::lexical_cast<std::string>(HistoryHigh).c_str());
	fprintf(fp, "\t\tHistoryLow = %s    [��Լ���]\n", boost::lexical_cast<std::string>(HistoryLow).c_str());
	fprintf(fp, "\t\tOpenPrice = %s    [����]\n", boost::lexical_cast<std::string>(OpenPrice).c_str());
	fprintf(fp, "\t\tHighestPrice = %s    [��߼�]\n", boost::lexical_cast<std::string>(HighestPrice).c_str());
	fprintf(fp, "\t\tLowestPrice = %s    [��ͼ�]\n", boost::lexical_cast<std::string>(LowestPrice).c_str());
	fprintf(fp, "\t\tClosePrice = %s    [������]\n", boost::lexical_cast<std::string>(ClosePrice).c_str());
	fprintf(fp, "\t\tUpperLimitPrice = %s    [��ͣ���]\n", boost::lexical_cast<std::string>(UpperLimitPrice).c_str());
	fprintf(fp, "\t\tLowerLimitPrice = %s    [��ͣ���]\n", boost::lexical_cast<std::string>(LowerLimitPrice).c_str());
	fprintf(fp, "\t\tClearPrice = %s    [���ν����]\n", boost::lexical_cast<std::string>(ClearPrice).c_str());
	fprintf(fp, "\t\tCurrDelta = %s    [����ʵ��]\n", boost::lexical_cast<std::string>(CurrDelta).c_str());
	fprintf(fp, "\t\tPrecision = %s    [���۾���]\n", boost::lexical_cast<std::string>(Precision).c_str());
	fprintf(fp, "\t\tLastPrice = %s    [���¼�]\n", boost::lexical_cast<std::string>(LastPrice).c_str());
	fprintf(fp, "\t\tVolume = %s    [����]\n", boost::lexical_cast<std::string>(Volume).c_str());
	fprintf(fp, "\t\tTurnover = %s    [�ɽ����]\n", boost::lexical_cast<std::string>(Turnover).c_str());
	fprintf(fp, "\t\tOpenInterest = %s    [�ֲ���]\n", boost::lexical_cast<std::string>(OpenInterest).c_str());
	fprintf(fp, "\t\tNetChg = %s    [�ǵ�]\n", boost::lexical_cast<std::string>(NetChg).c_str());
	fprintf(fp, "\t\tMarkup = %s    [�ǵ���]\n", boost::lexical_cast<std::string>(Markup).c_str());
	fprintf(fp, "\t\tSwing = %s    [���]\n", boost::lexical_cast<std::string>(Swing).c_str());
	fprintf(fp, "\t\tAvgPrice = %s    [ƽ����]\n", boost::lexical_cast<std::string>(AvgPrice).c_str());
	fprintf(fp, "\t\tBidPrice1 = %s    [�����һ]\n", boost::lexical_cast<std::string>(BidPrice1).c_str());
	fprintf(fp, "\t\tBidVolume1 = %s    [������һ]\n", boost::lexical_cast<std::string>(BidVolume1).c_str());
	fprintf(fp, "\t\tAskPrice1 = %s    [������һ]\n", boost::lexical_cast<std::string>(AskPrice1).c_str());
	fprintf(fp, "\t\tAskVolume1 = %s    [������һ]\n", boost::lexical_cast<std::string>(AskVolume1).c_str());
	fprintf(fp, "\t\tBidPrice2 = %s    [����۶�]\n", boost::lexical_cast<std::string>(BidPrice2).c_str());
	fprintf(fp, "\t\tBidVolume2 = %s    [��������]\n", boost::lexical_cast<std::string>(BidVolume2).c_str());
	fprintf(fp, "\t\tBidPrice3 = %s    [�������]\n", boost::lexical_cast<std::string>(BidPrice3).c_str());
	fprintf(fp, "\t\tBidVolume3 = %s    [��������]\n", boost::lexical_cast<std::string>(BidVolume3).c_str());
	fprintf(fp, "\t\tAskPrice2 = %s    [�����۶�]\n", boost::lexical_cast<std::string>(AskPrice2).c_str());
	fprintf(fp, "\t\tAskVolume2 = %s    [��������]\n", boost::lexical_cast<std::string>(AskVolume2).c_str());
	fprintf(fp, "\t\tAskPrice3 = %s    [��������]\n", boost::lexical_cast<std::string>(AskPrice3).c_str());
	fprintf(fp, "\t\tAskVolume3 = %s    [��������]\n", boost::lexical_cast<std::string>(AskVolume3).c_str());
	fprintf(fp, "\t\tBidPrice4 = %s    [�������]\n", boost::lexical_cast<std::string>(BidPrice4).c_str());
	fprintf(fp, "\t\tBidVolume4 = %s    [��������]\n", boost::lexical_cast<std::string>(BidVolume4).c_str());
	fprintf(fp, "\t\tBidPrice5 = %s    [�������]\n", boost::lexical_cast<std::string>(BidPrice5).c_str());
	fprintf(fp, "\t\tBidVolume5 = %s    [��������]\n", boost::lexical_cast<std::string>(BidVolume5).c_str());
	fprintf(fp, "\t\tAskPrice4 = %s    [��������]\n", boost::lexical_cast<std::string>(AskPrice4).c_str());
	fprintf(fp, "\t\tAskVolume4 = %s    [��������]\n", boost::lexical_cast<std::string>(AskVolume4).c_str());
	fprintf(fp, "\t\tAskPrice5 = %s    [��������]\n", boost::lexical_cast<std::string>(AskPrice5).c_str());
	fprintf(fp, "\t\tAskVolume5 = %s    [��������]\n", boost::lexical_cast<std::string>(AskVolume5).c_str());
	fprintf(fp, "\t\tBidPrice6 = %s    [�������]\n", boost::lexical_cast<std::string>(BidPrice6).c_str());
	fprintf(fp, "\t\tBidVolume6 = %s    [��������]\n", boost::lexical_cast<std::string>(BidVolume6).c_str());
	fprintf(fp, "\t\tBidPrice7 = %s    [�������]\n", boost::lexical_cast<std::string>(BidPrice7).c_str());
	fprintf(fp, "\t\tBidVolume7 = %s    [��������]\n", boost::lexical_cast<std::string>(BidVolume7).c_str());
	fprintf(fp, "\t\tBidPrice8 = %s    [����۰�]\n", boost::lexical_cast<std::string>(BidPrice8).c_str());
	fprintf(fp, "\t\tBidVolume8 = %s    [��������]\n", boost::lexical_cast<std::string>(BidVolume8).c_str());
	fprintf(fp, "\t\tBidPrice9 = %s    [����۾�]\n", boost::lexical_cast<std::string>(BidPrice9).c_str());
	fprintf(fp, "\t\tBidVolume9 = %s    [��������]\n", boost::lexical_cast<std::string>(BidVolume9).c_str());
	fprintf(fp, "\t\tBidPrice10 = %s    [�����ʮ]\n", boost::lexical_cast<std::string>(BidPrice10).c_str());
	fprintf(fp, "\t\tBidVolume10 = %s    [������ʮ]\n", boost::lexical_cast<std::string>(BidVolume10).c_str());
	fprintf(fp, "\t\tAskPrice6 = %s    [��������]\n", boost::lexical_cast<std::string>(AskPrice6).c_str());
	fprintf(fp, "\t\tAskVolume6 = %s    [��������]\n", boost::lexical_cast<std::string>(AskVolume6).c_str());
	fprintf(fp, "\t\tAskPrice7 = %s    [��������]\n", boost::lexical_cast<std::string>(AskPrice7).c_str());
	fprintf(fp, "\t\tAskVolume7 = %s    [��������]\n", boost::lexical_cast<std::string>(AskVolume7).c_str());
	fprintf(fp, "\t\tAskPrice8 = %s    [�����۰�]\n", boost::lexical_cast<std::string>(AskPrice8).c_str());
	fprintf(fp, "\t\tAskVolume8 = %s    [��������]\n", boost::lexical_cast<std::string>(AskVolume8).c_str());
	fprintf(fp, "\t\tAskPrice9 = %s    [�����۾�]\n", boost::lexical_cast<std::string>(AskPrice9).c_str());
	fprintf(fp, "\t\tAskVolume9 = %s    [��������]\n", boost::lexical_cast<std::string>(AskVolume9).c_str());
	fprintf(fp, "\t\tAskPrice10 = %s    [������ʮ]\n", boost::lexical_cast<std::string>(AskPrice10).c_str());
	fprintf(fp, "\t\tAskVolume10 = %s    [������ʮ]\n", boost::lexical_cast<std::string>(AskVolume10).c_str());
	fprintf(fp, "\t\tSequenceNo = %s    [���]\n", boost::lexical_cast<std::string>(SequenceNo).c_str());
	fprintf(fp, "\t\tMarketName = %s    [�г�������]\n", boost::lexical_cast<std::string>(MarketName).c_str());
	fprintf(fp, "\t\tInstrumentID = %s    [��Լ����]\n", boost::lexical_cast<std::string>(InstrumentID).c_str());
	fprintf(fp, "\t\tInstrumentStatus = %s    [��Լ����״̬-1:δ֪0:����1:�޺���2:����3:����4:����5:����ǰ6:����ǰ7:����]\n", boost::lexical_cast<std::string>(InstrumentStatus).c_str());
	fprintf(fp, "\t\tUpdateTime = %s    [����޸�ʱ��]\n", boost::lexical_cast<std::string>(UpdateTime).c_str());
	fprintf(fp, "\t\tUpdateMillisec = %s    [����޸ĺ���]\n", boost::lexical_cast<std::string>(UpdateMillisec).c_str());
	fprintf(fp, "\t}\n");
}

void CDepthMarketData::dumpDiff(FILE *fp, const CDepthMarketData *pOriginal) const
{
	if (fp == nullptr)
	{
		fp = stdout;
	}
	fprintf(fp, "\tCDepthMarketData = {\n");
	if (compare(TradingDay, pOriginal->TradingDay) != 0)
	{
		fprintf(fp, "\t\tTradingDay = %s -> %s    [������]\n", boost::lexical_cast<std::string>(pOriginal->TradingDay).c_str(), boost::lexical_cast<std::string>(TradingDay).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTradingDay = %s    [������]\n", boost::lexical_cast<std::string>(TradingDay).c_str());
	}
	if (compare(PreClearPrice, pOriginal->PreClearPrice) != 0)
	{
		fprintf(fp, "\t\tPreClearPrice = %s -> %s    [�����]\n", boost::lexical_cast<std::string>(pOriginal->PreClearPrice).c_str(), boost::lexical_cast<std::string>(PreClearPrice).c_str());
	}
	else
	{
		fprintf(fp, "\t\tPreClearPrice = %s    [�����]\n", boost::lexical_cast<std::string>(PreClearPrice).c_str());
	}
	if (compare(PreClosePrice, pOriginal->PreClosePrice) != 0)
	{
		fprintf(fp, "\t\tPreClosePrice = %s -> %s    [������]\n", boost::lexical_cast<std::string>(pOriginal->PreClosePrice).c_str(), boost::lexical_cast<std::string>(PreClosePrice).c_str());
	}
	else
	{
		fprintf(fp, "\t\tPreClosePrice = %s    [������]\n", boost::lexical_cast<std::string>(PreClosePrice).c_str());
	}
	if (compare(PreOpenInterest, pOriginal->PreOpenInterest) != 0)
	{
		fprintf(fp, "\t\tPreOpenInterest = %s -> %s    [��ֲ���]\n", boost::lexical_cast<std::string>(pOriginal->PreOpenInterest).c_str(), boost::lexical_cast<std::string>(PreOpenInterest).c_str());
	}
	else
	{
		fprintf(fp, "\t\tPreOpenInterest = %s    [��ֲ���]\n", boost::lexical_cast<std::string>(PreOpenInterest).c_str());
	}
	if (compare(PreDelta, pOriginal->PreDelta) != 0)
	{
		fprintf(fp, "\t\tPreDelta = %s -> %s    [����ʵ��]\n", boost::lexical_cast<std::string>(pOriginal->PreDelta).c_str(), boost::lexical_cast<std::string>(PreDelta).c_str());
	}
	else
	{
		fprintf(fp, "\t\tPreDelta = %s    [����ʵ��]\n", boost::lexical_cast<std::string>(PreDelta).c_str());
	}
	if (compare(HistoryHigh, pOriginal->HistoryHigh) != 0)
	{
		fprintf(fp, "\t\tHistoryHigh = %s -> %s    [��Լ���]\n", boost::lexical_cast<std::string>(pOriginal->HistoryHigh).c_str(), boost::lexical_cast<std::string>(HistoryHigh).c_str());
	}
	else
	{
		fprintf(fp, "\t\tHistoryHigh = %s    [��Լ���]\n", boost::lexical_cast<std::string>(HistoryHigh).c_str());
	}
	if (compare(HistoryLow, pOriginal->HistoryLow) != 0)
	{
		fprintf(fp, "\t\tHistoryLow = %s -> %s    [��Լ���]\n", boost::lexical_cast<std::string>(pOriginal->HistoryLow).c_str(), boost::lexical_cast<std::string>(HistoryLow).c_str());
	}
	else
	{
		fprintf(fp, "\t\tHistoryLow = %s    [��Լ���]\n", boost::lexical_cast<std::string>(HistoryLow).c_str());
	}
	if (compare(OpenPrice, pOriginal->OpenPrice) != 0)
	{
		fprintf(fp, "\t\tOpenPrice = %s -> %s    [����]\n", boost::lexical_cast<std::string>(pOriginal->OpenPrice).c_str(), boost::lexical_cast<std::string>(OpenPrice).c_str());
	}
	else
	{
		fprintf(fp, "\t\tOpenPrice = %s    [����]\n", boost::lexical_cast<std::string>(OpenPrice).c_str());
	}
	if (compare(HighestPrice, pOriginal->HighestPrice) != 0)
	{
		fprintf(fp, "\t\tHighestPrice = %s -> %s    [��߼�]\n", boost::lexical_cast<std::string>(pOriginal->HighestPrice).c_str(), boost::lexical_cast<std::string>(HighestPrice).c_str());
	}
	else
	{
		fprintf(fp, "\t\tHighestPrice = %s    [��߼�]\n", boost::lexical_cast<std::string>(HighestPrice).c_str());
	}
	if (compare(LowestPrice, pOriginal->LowestPrice) != 0)
	{
		fprintf(fp, "\t\tLowestPrice = %s -> %s    [��ͼ�]\n", boost::lexical_cast<std::string>(pOriginal->LowestPrice).c_str(), boost::lexical_cast<std::string>(LowestPrice).c_str());
	}
	else
	{
		fprintf(fp, "\t\tLowestPrice = %s    [��ͼ�]\n", boost::lexical_cast<std::string>(LowestPrice).c_str());
	}
	if (compare(ClosePrice, pOriginal->ClosePrice) != 0)
	{
		fprintf(fp, "\t\tClosePrice = %s -> %s    [������]\n", boost::lexical_cast<std::string>(pOriginal->ClosePrice).c_str(), boost::lexical_cast<std::string>(ClosePrice).c_str());
	}
	else
	{
		fprintf(fp, "\t\tClosePrice = %s    [������]\n", boost::lexical_cast<std::string>(ClosePrice).c_str());
	}
	if (compare(UpperLimitPrice, pOriginal->UpperLimitPrice) != 0)
	{
		fprintf(fp, "\t\tUpperLimitPrice = %s -> %s    [��ͣ���]\n", boost::lexical_cast<std::string>(pOriginal->UpperLimitPrice).c_str(), boost::lexical_cast<std::string>(UpperLimitPrice).c_str());
	}
	else
	{
		fprintf(fp, "\t\tUpperLimitPrice = %s    [��ͣ���]\n", boost::lexical_cast<std::string>(UpperLimitPrice).c_str());
	}
	if (compare(LowerLimitPrice, pOriginal->LowerLimitPrice) != 0)
	{
		fprintf(fp, "\t\tLowerLimitPrice = %s -> %s    [��ͣ���]\n", boost::lexical_cast<std::string>(pOriginal->LowerLimitPrice).c_str(), boost::lexical_cast<std::string>(LowerLimitPrice).c_str());
	}
	else
	{
		fprintf(fp, "\t\tLowerLimitPrice = %s    [��ͣ���]\n", boost::lexical_cast<std::string>(LowerLimitPrice).c_str());
	}
	if (compare(ClearPrice, pOriginal->ClearPrice) != 0)
	{
		fprintf(fp, "\t\tClearPrice = %s -> %s    [���ν����]\n", boost::lexical_cast<std::string>(pOriginal->ClearPrice).c_str(), boost::lexical_cast<std::string>(ClearPrice).c_str());
	}
	else
	{
		fprintf(fp, "\t\tClearPrice = %s    [���ν����]\n", boost::lexical_cast<std::string>(ClearPrice).c_str());
	}
	if (compare(CurrDelta, pOriginal->CurrDelta) != 0)
	{
		fprintf(fp, "\t\tCurrDelta = %s -> %s    [����ʵ��]\n", boost::lexical_cast<std::string>(pOriginal->CurrDelta).c_str(), boost::lexical_cast<std::string>(CurrDelta).c_str());
	}
	else
	{
		fprintf(fp, "\t\tCurrDelta = %s    [����ʵ��]\n", boost::lexical_cast<std::string>(CurrDelta).c_str());
	}
	if (compare(Precision, pOriginal->Precision) != 0)
	{
		fprintf(fp, "\t\tPrecision = %s -> %s    [���۾���]\n", boost::lexical_cast<std::string>(pOriginal->Precision).c_str(), boost::lexical_cast<std::string>(Precision).c_str());
	}
	else
	{
		fprintf(fp, "\t\tPrecision = %s    [���۾���]\n", boost::lexical_cast<std::string>(Precision).c_str());
	}
	if (compare(LastPrice, pOriginal->LastPrice) != 0)
	{
		fprintf(fp, "\t\tLastPrice = %s -> %s    [���¼�]\n", boost::lexical_cast<std::string>(pOriginal->LastPrice).c_str(), boost::lexical_cast<std::string>(LastPrice).c_str());
	}
	else
	{
		fprintf(fp, "\t\tLastPrice = %s    [���¼�]\n", boost::lexical_cast<std::string>(LastPrice).c_str());
	}
	if (compare(Volume, pOriginal->Volume) != 0)
	{
		fprintf(fp, "\t\tVolume = %s -> %s    [����]\n", boost::lexical_cast<std::string>(pOriginal->Volume).c_str(), boost::lexical_cast<std::string>(Volume).c_str());
	}
	else
	{
		fprintf(fp, "\t\tVolume = %s    [����]\n", boost::lexical_cast<std::string>(Volume).c_str());
	}
	if (compare(Turnover, pOriginal->Turnover) != 0)
	{
		fprintf(fp, "\t\tTurnover = %s -> %s    [�ɽ����]\n", boost::lexical_cast<std::string>(pOriginal->Turnover).c_str(), boost::lexical_cast<std::string>(Turnover).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTurnover = %s    [�ɽ����]\n", boost::lexical_cast<std::string>(Turnover).c_str());
	}
	if (compare(OpenInterest, pOriginal->OpenInterest) != 0)
	{
		fprintf(fp, "\t\tOpenInterest = %s -> %s    [�ֲ���]\n", boost::lexical_cast<std::string>(pOriginal->OpenInterest).c_str(), boost::lexical_cast<std::string>(OpenInterest).c_str());
	}
	else
	{
		fprintf(fp, "\t\tOpenInterest = %s    [�ֲ���]\n", boost::lexical_cast<std::string>(OpenInterest).c_str());
	}
	if (compare(NetChg, pOriginal->NetChg) != 0)
	{
		fprintf(fp, "\t\tNetChg = %s -> %s    [�ǵ�]\n", boost::lexical_cast<std::string>(pOriginal->NetChg).c_str(), boost::lexical_cast<std::string>(NetChg).c_str());
	}
	else
	{
		fprintf(fp, "\t\tNetChg = %s    [�ǵ�]\n", boost::lexical_cast<std::string>(NetChg).c_str());
	}
	if (compare(Markup, pOriginal->Markup) != 0)
	{
		fprintf(fp, "\t\tMarkup = %s -> %s    [�ǵ���]\n", boost::lexical_cast<std::string>(pOriginal->Markup).c_str(), boost::lexical_cast<std::string>(Markup).c_str());
	}
	else
	{
		fprintf(fp, "\t\tMarkup = %s    [�ǵ���]\n", boost::lexical_cast<std::string>(Markup).c_str());
	}
	if (compare(Swing, pOriginal->Swing) != 0)
	{
		fprintf(fp, "\t\tSwing = %s -> %s    [���]\n", boost::lexical_cast<std::string>(pOriginal->Swing).c_str(), boost::lexical_cast<std::string>(Swing).c_str());
	}
	else
	{
		fprintf(fp, "\t\tSwing = %s    [���]\n", boost::lexical_cast<std::string>(Swing).c_str());
	}
	if (compare(AvgPrice, pOriginal->AvgPrice) != 0)
	{
		fprintf(fp, "\t\tAvgPrice = %s -> %s    [ƽ����]\n", boost::lexical_cast<std::string>(pOriginal->AvgPrice).c_str(), boost::lexical_cast<std::string>(AvgPrice).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAvgPrice = %s    [ƽ����]\n", boost::lexical_cast<std::string>(AvgPrice).c_str());
	}
	if (compare(BidPrice1, pOriginal->BidPrice1) != 0)
	{
		fprintf(fp, "\t\tBidPrice1 = %s -> %s    [�����һ]\n", boost::lexical_cast<std::string>(pOriginal->BidPrice1).c_str(), boost::lexical_cast<std::string>(BidPrice1).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBidPrice1 = %s    [�����һ]\n", boost::lexical_cast<std::string>(BidPrice1).c_str());
	}
	if (compare(BidVolume1, pOriginal->BidVolume1) != 0)
	{
		fprintf(fp, "\t\tBidVolume1 = %s -> %s    [������һ]\n", boost::lexical_cast<std::string>(pOriginal->BidVolume1).c_str(), boost::lexical_cast<std::string>(BidVolume1).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBidVolume1 = %s    [������һ]\n", boost::lexical_cast<std::string>(BidVolume1).c_str());
	}
	if (compare(AskPrice1, pOriginal->AskPrice1) != 0)
	{
		fprintf(fp, "\t\tAskPrice1 = %s -> %s    [������һ]\n", boost::lexical_cast<std::string>(pOriginal->AskPrice1).c_str(), boost::lexical_cast<std::string>(AskPrice1).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAskPrice1 = %s    [������һ]\n", boost::lexical_cast<std::string>(AskPrice1).c_str());
	}
	if (compare(AskVolume1, pOriginal->AskVolume1) != 0)
	{
		fprintf(fp, "\t\tAskVolume1 = %s -> %s    [������һ]\n", boost::lexical_cast<std::string>(pOriginal->AskVolume1).c_str(), boost::lexical_cast<std::string>(AskVolume1).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAskVolume1 = %s    [������һ]\n", boost::lexical_cast<std::string>(AskVolume1).c_str());
	}
	if (compare(BidPrice2, pOriginal->BidPrice2) != 0)
	{
		fprintf(fp, "\t\tBidPrice2 = %s -> %s    [����۶�]\n", boost::lexical_cast<std::string>(pOriginal->BidPrice2).c_str(), boost::lexical_cast<std::string>(BidPrice2).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBidPrice2 = %s    [����۶�]\n", boost::lexical_cast<std::string>(BidPrice2).c_str());
	}
	if (compare(BidVolume2, pOriginal->BidVolume2) != 0)
	{
		fprintf(fp, "\t\tBidVolume2 = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->BidVolume2).c_str(), boost::lexical_cast<std::string>(BidVolume2).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBidVolume2 = %s    [��������]\n", boost::lexical_cast<std::string>(BidVolume2).c_str());
	}
	if (compare(BidPrice3, pOriginal->BidPrice3) != 0)
	{
		fprintf(fp, "\t\tBidPrice3 = %s -> %s    [�������]\n", boost::lexical_cast<std::string>(pOriginal->BidPrice3).c_str(), boost::lexical_cast<std::string>(BidPrice3).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBidPrice3 = %s    [�������]\n", boost::lexical_cast<std::string>(BidPrice3).c_str());
	}
	if (compare(BidVolume3, pOriginal->BidVolume3) != 0)
	{
		fprintf(fp, "\t\tBidVolume3 = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->BidVolume3).c_str(), boost::lexical_cast<std::string>(BidVolume3).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBidVolume3 = %s    [��������]\n", boost::lexical_cast<std::string>(BidVolume3).c_str());
	}
	if (compare(AskPrice2, pOriginal->AskPrice2) != 0)
	{
		fprintf(fp, "\t\tAskPrice2 = %s -> %s    [�����۶�]\n", boost::lexical_cast<std::string>(pOriginal->AskPrice2).c_str(), boost::lexical_cast<std::string>(AskPrice2).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAskPrice2 = %s    [�����۶�]\n", boost::lexical_cast<std::string>(AskPrice2).c_str());
	}
	if (compare(AskVolume2, pOriginal->AskVolume2) != 0)
	{
		fprintf(fp, "\t\tAskVolume2 = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->AskVolume2).c_str(), boost::lexical_cast<std::string>(AskVolume2).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAskVolume2 = %s    [��������]\n", boost::lexical_cast<std::string>(AskVolume2).c_str());
	}
	if (compare(AskPrice3, pOriginal->AskPrice3) != 0)
	{
		fprintf(fp, "\t\tAskPrice3 = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->AskPrice3).c_str(), boost::lexical_cast<std::string>(AskPrice3).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAskPrice3 = %s    [��������]\n", boost::lexical_cast<std::string>(AskPrice3).c_str());
	}
	if (compare(AskVolume3, pOriginal->AskVolume3) != 0)
	{
		fprintf(fp, "\t\tAskVolume3 = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->AskVolume3).c_str(), boost::lexical_cast<std::string>(AskVolume3).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAskVolume3 = %s    [��������]\n", boost::lexical_cast<std::string>(AskVolume3).c_str());
	}
	if (compare(BidPrice4, pOriginal->BidPrice4) != 0)
	{
		fprintf(fp, "\t\tBidPrice4 = %s -> %s    [�������]\n", boost::lexical_cast<std::string>(pOriginal->BidPrice4).c_str(), boost::lexical_cast<std::string>(BidPrice4).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBidPrice4 = %s    [�������]\n", boost::lexical_cast<std::string>(BidPrice4).c_str());
	}
	if (compare(BidVolume4, pOriginal->BidVolume4) != 0)
	{
		fprintf(fp, "\t\tBidVolume4 = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->BidVolume4).c_str(), boost::lexical_cast<std::string>(BidVolume4).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBidVolume4 = %s    [��������]\n", boost::lexical_cast<std::string>(BidVolume4).c_str());
	}
	if (compare(BidPrice5, pOriginal->BidPrice5) != 0)
	{
		fprintf(fp, "\t\tBidPrice5 = %s -> %s    [�������]\n", boost::lexical_cast<std::string>(pOriginal->BidPrice5).c_str(), boost::lexical_cast<std::string>(BidPrice5).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBidPrice5 = %s    [�������]\n", boost::lexical_cast<std::string>(BidPrice5).c_str());
	}
	if (compare(BidVolume5, pOriginal->BidVolume5) != 0)
	{
		fprintf(fp, "\t\tBidVolume5 = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->BidVolume5).c_str(), boost::lexical_cast<std::string>(BidVolume5).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBidVolume5 = %s    [��������]\n", boost::lexical_cast<std::string>(BidVolume5).c_str());
	}
	if (compare(AskPrice4, pOriginal->AskPrice4) != 0)
	{
		fprintf(fp, "\t\tAskPrice4 = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->AskPrice4).c_str(), boost::lexical_cast<std::string>(AskPrice4).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAskPrice4 = %s    [��������]\n", boost::lexical_cast<std::string>(AskPrice4).c_str());
	}
	if (compare(AskVolume4, pOriginal->AskVolume4) != 0)
	{
		fprintf(fp, "\t\tAskVolume4 = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->AskVolume4).c_str(), boost::lexical_cast<std::string>(AskVolume4).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAskVolume4 = %s    [��������]\n", boost::lexical_cast<std::string>(AskVolume4).c_str());
	}
	if (compare(AskPrice5, pOriginal->AskPrice5) != 0)
	{
		fprintf(fp, "\t\tAskPrice5 = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->AskPrice5).c_str(), boost::lexical_cast<std::string>(AskPrice5).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAskPrice5 = %s    [��������]\n", boost::lexical_cast<std::string>(AskPrice5).c_str());
	}
	if (compare(AskVolume5, pOriginal->AskVolume5) != 0)
	{
		fprintf(fp, "\t\tAskVolume5 = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->AskVolume5).c_str(), boost::lexical_cast<std::string>(AskVolume5).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAskVolume5 = %s    [��������]\n", boost::lexical_cast<std::string>(AskVolume5).c_str());
	}
	if (compare(BidPrice6, pOriginal->BidPrice6) != 0)
	{
		fprintf(fp, "\t\tBidPrice6 = %s -> %s    [�������]\n", boost::lexical_cast<std::string>(pOriginal->BidPrice6).c_str(), boost::lexical_cast<std::string>(BidPrice6).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBidPrice6 = %s    [�������]\n", boost::lexical_cast<std::string>(BidPrice6).c_str());
	}
	if (compare(BidVolume6, pOriginal->BidVolume6) != 0)
	{
		fprintf(fp, "\t\tBidVolume6 = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->BidVolume6).c_str(), boost::lexical_cast<std::string>(BidVolume6).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBidVolume6 = %s    [��������]\n", boost::lexical_cast<std::string>(BidVolume6).c_str());
	}
	if (compare(BidPrice7, pOriginal->BidPrice7) != 0)
	{
		fprintf(fp, "\t\tBidPrice7 = %s -> %s    [�������]\n", boost::lexical_cast<std::string>(pOriginal->BidPrice7).c_str(), boost::lexical_cast<std::string>(BidPrice7).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBidPrice7 = %s    [�������]\n", boost::lexical_cast<std::string>(BidPrice7).c_str());
	}
	if (compare(BidVolume7, pOriginal->BidVolume7) != 0)
	{
		fprintf(fp, "\t\tBidVolume7 = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->BidVolume7).c_str(), boost::lexical_cast<std::string>(BidVolume7).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBidVolume7 = %s    [��������]\n", boost::lexical_cast<std::string>(BidVolume7).c_str());
	}
	if (compare(BidPrice8, pOriginal->BidPrice8) != 0)
	{
		fprintf(fp, "\t\tBidPrice8 = %s -> %s    [����۰�]\n", boost::lexical_cast<std::string>(pOriginal->BidPrice8).c_str(), boost::lexical_cast<std::string>(BidPrice8).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBidPrice8 = %s    [����۰�]\n", boost::lexical_cast<std::string>(BidPrice8).c_str());
	}
	if (compare(BidVolume8, pOriginal->BidVolume8) != 0)
	{
		fprintf(fp, "\t\tBidVolume8 = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->BidVolume8).c_str(), boost::lexical_cast<std::string>(BidVolume8).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBidVolume8 = %s    [��������]\n", boost::lexical_cast<std::string>(BidVolume8).c_str());
	}
	if (compare(BidPrice9, pOriginal->BidPrice9) != 0)
	{
		fprintf(fp, "\t\tBidPrice9 = %s -> %s    [����۾�]\n", boost::lexical_cast<std::string>(pOriginal->BidPrice9).c_str(), boost::lexical_cast<std::string>(BidPrice9).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBidPrice9 = %s    [����۾�]\n", boost::lexical_cast<std::string>(BidPrice9).c_str());
	}
	if (compare(BidVolume9, pOriginal->BidVolume9) != 0)
	{
		fprintf(fp, "\t\tBidVolume9 = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->BidVolume9).c_str(), boost::lexical_cast<std::string>(BidVolume9).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBidVolume9 = %s    [��������]\n", boost::lexical_cast<std::string>(BidVolume9).c_str());
	}
	if (compare(BidPrice10, pOriginal->BidPrice10) != 0)
	{
		fprintf(fp, "\t\tBidPrice10 = %s -> %s    [�����ʮ]\n", boost::lexical_cast<std::string>(pOriginal->BidPrice10).c_str(), boost::lexical_cast<std::string>(BidPrice10).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBidPrice10 = %s    [�����ʮ]\n", boost::lexical_cast<std::string>(BidPrice10).c_str());
	}
	if (compare(BidVolume10, pOriginal->BidVolume10) != 0)
	{
		fprintf(fp, "\t\tBidVolume10 = %s -> %s    [������ʮ]\n", boost::lexical_cast<std::string>(pOriginal->BidVolume10).c_str(), boost::lexical_cast<std::string>(BidVolume10).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBidVolume10 = %s    [������ʮ]\n", boost::lexical_cast<std::string>(BidVolume10).c_str());
	}
	if (compare(AskPrice6, pOriginal->AskPrice6) != 0)
	{
		fprintf(fp, "\t\tAskPrice6 = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->AskPrice6).c_str(), boost::lexical_cast<std::string>(AskPrice6).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAskPrice6 = %s    [��������]\n", boost::lexical_cast<std::string>(AskPrice6).c_str());
	}
	if (compare(AskVolume6, pOriginal->AskVolume6) != 0)
	{
		fprintf(fp, "\t\tAskVolume6 = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->AskVolume6).c_str(), boost::lexical_cast<std::string>(AskVolume6).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAskVolume6 = %s    [��������]\n", boost::lexical_cast<std::string>(AskVolume6).c_str());
	}
	if (compare(AskPrice7, pOriginal->AskPrice7) != 0)
	{
		fprintf(fp, "\t\tAskPrice7 = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->AskPrice7).c_str(), boost::lexical_cast<std::string>(AskPrice7).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAskPrice7 = %s    [��������]\n", boost::lexical_cast<std::string>(AskPrice7).c_str());
	}
	if (compare(AskVolume7, pOriginal->AskVolume7) != 0)
	{
		fprintf(fp, "\t\tAskVolume7 = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->AskVolume7).c_str(), boost::lexical_cast<std::string>(AskVolume7).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAskVolume7 = %s    [��������]\n", boost::lexical_cast<std::string>(AskVolume7).c_str());
	}
	if (compare(AskPrice8, pOriginal->AskPrice8) != 0)
	{
		fprintf(fp, "\t\tAskPrice8 = %s -> %s    [�����۰�]\n", boost::lexical_cast<std::string>(pOriginal->AskPrice8).c_str(), boost::lexical_cast<std::string>(AskPrice8).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAskPrice8 = %s    [�����۰�]\n", boost::lexical_cast<std::string>(AskPrice8).c_str());
	}
	if (compare(AskVolume8, pOriginal->AskVolume8) != 0)
	{
		fprintf(fp, "\t\tAskVolume8 = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->AskVolume8).c_str(), boost::lexical_cast<std::string>(AskVolume8).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAskVolume8 = %s    [��������]\n", boost::lexical_cast<std::string>(AskVolume8).c_str());
	}
	if (compare(AskPrice9, pOriginal->AskPrice9) != 0)
	{
		fprintf(fp, "\t\tAskPrice9 = %s -> %s    [�����۾�]\n", boost::lexical_cast<std::string>(pOriginal->AskPrice9).c_str(), boost::lexical_cast<std::string>(AskPrice9).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAskPrice9 = %s    [�����۾�]\n", boost::lexical_cast<std::string>(AskPrice9).c_str());
	}
	if (compare(AskVolume9, pOriginal->AskVolume9) != 0)
	{
		fprintf(fp, "\t\tAskVolume9 = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->AskVolume9).c_str(), boost::lexical_cast<std::string>(AskVolume9).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAskVolume9 = %s    [��������]\n", boost::lexical_cast<std::string>(AskVolume9).c_str());
	}
	if (compare(AskPrice10, pOriginal->AskPrice10) != 0)
	{
		fprintf(fp, "\t\tAskPrice10 = %s -> %s    [������ʮ]\n", boost::lexical_cast<std::string>(pOriginal->AskPrice10).c_str(), boost::lexical_cast<std::string>(AskPrice10).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAskPrice10 = %s    [������ʮ]\n", boost::lexical_cast<std::string>(AskPrice10).c_str());
	}
	if (compare(AskVolume10, pOriginal->AskVolume10) != 0)
	{
		fprintf(fp, "\t\tAskVolume10 = %s -> %s    [������ʮ]\n", boost::lexical_cast<std::string>(pOriginal->AskVolume10).c_str(), boost::lexical_cast<std::string>(AskVolume10).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAskVolume10 = %s    [������ʮ]\n", boost::lexical_cast<std::string>(AskVolume10).c_str());
	}
	if (compare(SequenceNo, pOriginal->SequenceNo) != 0)
	{
		fprintf(fp, "\t\tSequenceNo = %s -> %s    [���]\n", boost::lexical_cast<std::string>(pOriginal->SequenceNo).c_str(), boost::lexical_cast<std::string>(SequenceNo).c_str());
	}
	else
	{
		fprintf(fp, "\t\tSequenceNo = %s    [���]\n", boost::lexical_cast<std::string>(SequenceNo).c_str());
	}
	if (compare(MarketName, pOriginal->MarketName) != 0)
	{
		fprintf(fp, "\t\tMarketName = %s -> %s    [�г�������]\n", boost::lexical_cast<std::string>(pOriginal->MarketName).c_str(), boost::lexical_cast<std::string>(MarketName).c_str());
	}
	else
	{
		fprintf(fp, "\t\tMarketName = %s    [�г�������]\n", boost::lexical_cast<std::string>(MarketName).c_str());
	}
	if (compare(InstrumentID, pOriginal->InstrumentID) != 0)
	{
		fprintf(fp, "\t\tInstrumentID = %s -> %s    [��Լ����]\n", boost::lexical_cast<std::string>(pOriginal->InstrumentID).c_str(), boost::lexical_cast<std::string>(InstrumentID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tInstrumentID = %s    [��Լ����]\n", boost::lexical_cast<std::string>(InstrumentID).c_str());
	}
	if (compare(InstrumentStatus, pOriginal->InstrumentStatus) != 0)
	{
		fprintf(fp, "\t\tInstrumentStatus = %s -> %s    [��Լ����״̬-1:δ֪0:����1:�޺���2:����3:����4:����5:����ǰ6:����ǰ7:����]\n", boost::lexical_cast<std::string>(pOriginal->InstrumentStatus).c_str(), boost::lexical_cast<std::string>(InstrumentStatus).c_str());
	}
	else
	{
		fprintf(fp, "\t\tInstrumentStatus = %s    [��Լ����״̬-1:δ֪0:����1:�޺���2:����3:����4:����5:����ǰ6:����ǰ7:����]\n", boost::lexical_cast<std::string>(InstrumentStatus).c_str());
	}
	if (compare(UpdateTime, pOriginal->UpdateTime) != 0)
	{
		fprintf(fp, "\t\tUpdateTime = %s -> %s    [����޸�ʱ��]\n", boost::lexical_cast<std::string>(pOriginal->UpdateTime).c_str(), boost::lexical_cast<std::string>(UpdateTime).c_str());
	}
	else
	{
		fprintf(fp, "\t\tUpdateTime = %s    [����޸�ʱ��]\n", boost::lexical_cast<std::string>(UpdateTime).c_str());
	}
	if (compare(UpdateMillisec, pOriginal->UpdateMillisec) != 0)
	{
		fprintf(fp, "\t\tUpdateMillisec = %s -> %s    [����޸ĺ���]\n", boost::lexical_cast<std::string>(pOriginal->UpdateMillisec).c_str(), boost::lexical_cast<std::string>(UpdateMillisec).c_str());
	}
	else
	{
		fprintf(fp, "\t\tUpdateMillisec = %s    [����޸ĺ���]\n", boost::lexical_cast<std::string>(UpdateMillisec).c_str());
	}
	fprintf(fp, "\t}\n");
}

void CDepthMarketData::dumpInLine(FILE *fp) const
{
	if (fp == nullptr)
	{
		fp = stdout;
	}
	std::stringstream sbuf;

	sbuf << ",TradingDay," << TradingDay;
	sbuf << ",PreClearPrice," << PreClearPrice;
	sbuf << ",PreClosePrice," << PreClosePrice;
	sbuf << ",PreOpenInterest," << PreOpenInterest;
	sbuf << ",PreDelta," << PreDelta;
	sbuf << ",HistoryHigh," << HistoryHigh;
	sbuf << ",HistoryLow," << HistoryLow;
	sbuf << ",OpenPrice," << OpenPrice;
	sbuf << ",HighestPrice," << HighestPrice;
	sbuf << ",LowestPrice," << LowestPrice;
	sbuf << ",ClosePrice," << ClosePrice;
	sbuf << ",UpperLimitPrice," << UpperLimitPrice;
	sbuf << ",LowerLimitPrice," << LowerLimitPrice;
	sbuf << ",ClearPrice," << ClearPrice;
	sbuf << ",CurrDelta," << CurrDelta;
	sbuf << ",Precision," << Precision;
	sbuf << ",LastPrice," << LastPrice;
	sbuf << ",Volume," << Volume;
	sbuf << ",Turnover," << Turnover;
	sbuf << ",OpenInterest," << OpenInterest;
	sbuf << ",NetChg," << NetChg;
	sbuf << ",Markup," << Markup;
	sbuf << ",Swing," << Swing;
	sbuf << ",AvgPrice," << AvgPrice;
	sbuf << ",BidPrice1," << BidPrice1;
	sbuf << ",BidVolume1," << BidVolume1;
	sbuf << ",AskPrice1," << AskPrice1;
	sbuf << ",AskVolume1," << AskVolume1;
	sbuf << ",BidPrice2," << BidPrice2;
	sbuf << ",BidVolume2," << BidVolume2;
	sbuf << ",BidPrice3," << BidPrice3;
	sbuf << ",BidVolume3," << BidVolume3;
	sbuf << ",AskPrice2," << AskPrice2;
	sbuf << ",AskVolume2," << AskVolume2;
	sbuf << ",AskPrice3," << AskPrice3;
	sbuf << ",AskVolume3," << AskVolume3;
	sbuf << ",BidPrice4," << BidPrice4;
	sbuf << ",BidVolume4," << BidVolume4;
	sbuf << ",BidPrice5," << BidPrice5;
	sbuf << ",BidVolume5," << BidVolume5;
	sbuf << ",AskPrice4," << AskPrice4;
	sbuf << ",AskVolume4," << AskVolume4;
	sbuf << ",AskPrice5," << AskPrice5;
	sbuf << ",AskVolume5," << AskVolume5;
	sbuf << ",BidPrice6," << BidPrice6;
	sbuf << ",BidVolume6," << BidVolume6;
	sbuf << ",BidPrice7," << BidPrice7;
	sbuf << ",BidVolume7," << BidVolume7;
	sbuf << ",BidPrice8," << BidPrice8;
	sbuf << ",BidVolume8," << BidVolume8;
	sbuf << ",BidPrice9," << BidPrice9;
	sbuf << ",BidVolume9," << BidVolume9;
	sbuf << ",BidPrice10," << BidPrice10;
	sbuf << ",BidVolume10," << BidVolume10;
	sbuf << ",AskPrice6," << AskPrice6;
	sbuf << ",AskVolume6," << AskVolume6;
	sbuf << ",AskPrice7," << AskPrice7;
	sbuf << ",AskVolume7," << AskVolume7;
	sbuf << ",AskPrice8," << AskPrice8;
	sbuf << ",AskVolume8," << AskVolume8;
	sbuf << ",AskPrice9," << AskPrice9;
	sbuf << ",AskVolume9," << AskVolume9;
	sbuf << ",AskPrice10," << AskPrice10;
	sbuf << ",AskVolume10," << AskVolume10;
	sbuf << ",SequenceNo," << SequenceNo;
	sbuf << ",MarketName," << MarketName;
	sbuf << ",InstrumentID," << InstrumentID;
	sbuf << ",InstrumentStatus," << InstrumentStatus;
	sbuf << ",UpdateTime," << UpdateTime;
	sbuf << ",UpdateMillisec," << UpdateMillisec;
	fprintf(fp, "%s", sbuf.str().c_str());
}

void CDepthMarketData::dumpString(char *target) const
{
	char *p = target;

	std::stringstream sbuf;

	sbuf << "TradingDay=" << TradingDay << ",";
	sbuf << "PreClearPrice=" << PreClearPrice << ",";
	sbuf << "PreClosePrice=" << PreClosePrice << ",";
	sbuf << "PreOpenInterest=" << PreOpenInterest << ",";
	sbuf << "PreDelta=" << PreDelta << ",";
	sbuf << "HistoryHigh=" << HistoryHigh << ",";
	sbuf << "HistoryLow=" << HistoryLow << ",";
	sbuf << "OpenPrice=" << OpenPrice << ",";
	sbuf << "HighestPrice=" << HighestPrice << ",";
	sbuf << "LowestPrice=" << LowestPrice << ",";
	sbuf << "ClosePrice=" << ClosePrice << ",";
	sbuf << "UpperLimitPrice=" << UpperLimitPrice << ",";
	sbuf << "LowerLimitPrice=" << LowerLimitPrice << ",";
	sbuf << "ClearPrice=" << ClearPrice << ",";
	sbuf << "CurrDelta=" << CurrDelta << ",";
	sbuf << "Precision=" << Precision << ",";
	sbuf << "LastPrice=" << LastPrice << ",";
	sbuf << "Volume=" << Volume << ",";
	sbuf << "Turnover=" << Turnover << ",";
	sbuf << "OpenInterest=" << OpenInterest << ",";
	sbuf << "NetChg=" << NetChg << ",";
	sbuf << "Markup=" << Markup << ",";
	sbuf << "Swing=" << Swing << ",";
	sbuf << "AvgPrice=" << AvgPrice << ",";
	sbuf << "BidPrice1=" << BidPrice1 << ",";
	sbuf << "BidVolume1=" << BidVolume1 << ",";
	sbuf << "AskPrice1=" << AskPrice1 << ",";
	sbuf << "AskVolume1=" << AskVolume1 << ",";
	sbuf << "BidPrice2=" << BidPrice2 << ",";
	sbuf << "BidVolume2=" << BidVolume2 << ",";
	sbuf << "BidPrice3=" << BidPrice3 << ",";
	sbuf << "BidVolume3=" << BidVolume3 << ",";
	sbuf << "AskPrice2=" << AskPrice2 << ",";
	sbuf << "AskVolume2=" << AskVolume2 << ",";
	sbuf << "AskPrice3=" << AskPrice3 << ",";
	sbuf << "AskVolume3=" << AskVolume3 << ",";
	sbuf << "BidPrice4=" << BidPrice4 << ",";
	sbuf << "BidVolume4=" << BidVolume4 << ",";
	sbuf << "BidPrice5=" << BidPrice5 << ",";
	sbuf << "BidVolume5=" << BidVolume5 << ",";
	sbuf << "AskPrice4=" << AskPrice4 << ",";
	sbuf << "AskVolume4=" << AskVolume4 << ",";
	sbuf << "AskPrice5=" << AskPrice5 << ",";
	sbuf << "AskVolume5=" << AskVolume5 << ",";
	sbuf << "BidPrice6=" << BidPrice6 << ",";
	sbuf << "BidVolume6=" << BidVolume6 << ",";
	sbuf << "BidPrice7=" << BidPrice7 << ",";
	sbuf << "BidVolume7=" << BidVolume7 << ",";
	sbuf << "BidPrice8=" << BidPrice8 << ",";
	sbuf << "BidVolume8=" << BidVolume8 << ",";
	sbuf << "BidPrice9=" << BidPrice9 << ",";
	sbuf << "BidVolume9=" << BidVolume9 << ",";
	sbuf << "BidPrice10=" << BidPrice10 << ",";
	sbuf << "BidVolume10=" << BidVolume10 << ",";
	sbuf << "AskPrice6=" << AskPrice6 << ",";
	sbuf << "AskVolume6=" << AskVolume6 << ",";
	sbuf << "AskPrice7=" << AskPrice7 << ",";
	sbuf << "AskVolume7=" << AskVolume7 << ",";
	sbuf << "AskPrice8=" << AskPrice8 << ",";
	sbuf << "AskVolume8=" << AskVolume8 << ",";
	sbuf << "AskPrice9=" << AskPrice9 << ",";
	sbuf << "AskVolume9=" << AskVolume9 << ",";
	sbuf << "AskPrice10=" << AskPrice10 << ",";
	sbuf << "AskVolume10=" << AskVolume10 << ",";
	sbuf << "SequenceNo=" << SequenceNo << ",";
	sbuf << "MarketName=" << MarketName << ",";
	sbuf << "InstrumentID=" << InstrumentID << ",";
	sbuf << "InstrumentStatus=" << InstrumentStatus << ",";
	sbuf << "UpdateTime=" << UpdateTime << ",";
	sbuf << "UpdateMillisec=" << UpdateMillisec << ",";

	sprintf(p, "%s", sbuf.str().c_str());
}

void CCommodity::init(void)
{
	memset(this, 0, sizeof(CCommodity));
}

int CCommodity::read(FILE *input)
{
	if (fread(this, 1, sizeof(CCommodity), input) != sizeof(CCommodity))
		return 0;
	else
		return 1;
}

int CCommodity::write(FILE *output) const
{
	if (fwrite(this, 1, sizeof(CCommodity), output) != sizeof(CCommodity))
		return 0;
	else
		return 1;
}

void CCommodity::dump(FILE *fp, int index) const
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
	fprintf(fp, "\tCCommodity%s = {\n", index_buf);
	fprintf(fp, "\t\tAppType = %s    [���׽ӿ�����]\n", boost::lexical_cast<std::string>(AppType).c_str());
	fprintf(fp, "\t\tExchangeID = %s    [����������]\n", boost::lexical_cast<std::string>(ExchangeID).c_str());
	fprintf(fp, "\t\tCommodityID = %s    [��Ʒ]\n", boost::lexical_cast<std::string>(CommodityID).c_str());
	fprintf(fp, "\t\tCommodityType = %s    [��Ʒ����]\n", boost::lexical_cast<std::string>(CommodityType).c_str());
	fprintf(fp, "\t\tExchangeInstID = %s    [��Լ�ڽ������Ĵ��루CTP��������ʢ�У�ָ��RelateCommodityNo��������Լ��]\n", boost::lexical_cast<std::string>(ExchangeInstID).c_str());
	fprintf(fp, "\t\tCommodityName = %s    [��Ʒ����]\n", boost::lexical_cast<std::string>(CommodityName).c_str());
	fprintf(fp, "\t\tCommodityAttribute = %s    [��Ʒ����]\n", boost::lexical_cast<std::string>(CommodityAttribute).c_str());
	fprintf(fp, "\t\tCommodityState = %s    [��Ʒ״̬]\n", boost::lexical_cast<std::string>(CommodityState).c_str());
	fprintf(fp, "\t\tMultipleValue = %s    [ÿ�ֳ���]\n", boost::lexical_cast<std::string>(MultipleValue).c_str());
	fprintf(fp, "\t\tUpperTick = %s    [��С�䶯�۷���]\n", boost::lexical_cast<std::string>(UpperTick).c_str());
	fprintf(fp, "\t\tLowerTick = %s    [��С�䶯�۷�ĸ]\n", boost::lexical_cast<std::string>(LowerTick).c_str());
	fprintf(fp, "\t\tPrecision = %s    [���۾���]\n", boost::lexical_cast<std::string>(Precision).c_str());
	fprintf(fp, "\t\tCurrencyID = %s    [��Ʒʹ�ñ���]\n", boost::lexical_cast<std::string>(CurrencyID).c_str());
	fprintf(fp, "\t\tDeliveryMode = %s    [���ʽ]\n", boost::lexical_cast<std::string>(DeliveryMode).c_str());
	fprintf(fp, "\t\tDeliveryDays = %s    [������ƫ��]\n", boost::lexical_cast<std::string>(DeliveryDays).c_str());
	fprintf(fp, "\t\tDeliveryYear = %s    [�������]\n", boost::lexical_cast<std::string>(DeliveryYear).c_str());
	fprintf(fp, "\t\tDeliveryMonth = %s    [������]\n", boost::lexical_cast<std::string>(DeliveryMonth).c_str());
	fprintf(fp, "\t\tMaxMarketOrderVolume = %s    [�м۵�����µ���]\n", boost::lexical_cast<std::string>(MaxMarketOrderVolume).c_str());
	fprintf(fp, "\t\tMinMarketOrderVolume = %s    [�м۵���С�µ���]\n", boost::lexical_cast<std::string>(MinMarketOrderVolume).c_str());
	fprintf(fp, "\t\tMaxLimitOrderVolume = %s    [�޼۵�����µ���]\n", boost::lexical_cast<std::string>(MaxLimitOrderVolume).c_str());
	fprintf(fp, "\t\tMinLimitOrderVolume = %s    [�޼۵���С�µ���]\n", boost::lexical_cast<std::string>(MinLimitOrderVolume).c_str());
	fprintf(fp, "\t\tDepositCalculateMode = %s    [��֤����㷽ʽ]\n", boost::lexical_cast<std::string>(DepositCalculateMode).c_str());
	fprintf(fp, "\t\tMaxHoldVol = %s    [���ֲ���]\n", boost::lexical_cast<std::string>(MaxHoldVol).c_str());
	fprintf(fp, "\t\tAddOneTime = %s    [T+1ʱ��,���ڴ�ʱ��ΪT+1����]\n", boost::lexical_cast<std::string>(AddOneTime).c_str());
	fprintf(fp, "\t\tCmbDirect = %s    [�����������(��һ��)]\n", boost::lexical_cast<std::string>(CmbDirect).c_str());
	fprintf(fp, "\t\tCoverMode = %s    [ƽ�ַ�ʽ]\n", boost::lexical_cast<std::string>(CoverMode).c_str());
	fprintf(fp, "\t}\n");
}

void CCommodity::dumpDiff(FILE *fp, const CCommodity *pOriginal) const
{
	if (fp == nullptr)
	{
		fp = stdout;
	}
	fprintf(fp, "\tCCommodity = {\n");
	if (compare(AppType, pOriginal->AppType) != 0)
	{
		fprintf(fp, "\t\tAppType = %s -> %s    [���׽ӿ�����]\n", boost::lexical_cast<std::string>(pOriginal->AppType).c_str(), boost::lexical_cast<std::string>(AppType).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAppType = %s    [���׽ӿ�����]\n", boost::lexical_cast<std::string>(AppType).c_str());
	}
	if (compare(ExchangeID, pOriginal->ExchangeID) != 0)
	{
		fprintf(fp, "\t\tExchangeID = %s -> %s    [����������]\n", boost::lexical_cast<std::string>(pOriginal->ExchangeID).c_str(), boost::lexical_cast<std::string>(ExchangeID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tExchangeID = %s    [����������]\n", boost::lexical_cast<std::string>(ExchangeID).c_str());
	}
	if (compare(CommodityID, pOriginal->CommodityID) != 0)
	{
		fprintf(fp, "\t\tCommodityID = %s -> %s    [��Ʒ]\n", boost::lexical_cast<std::string>(pOriginal->CommodityID).c_str(), boost::lexical_cast<std::string>(CommodityID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tCommodityID = %s    [��Ʒ]\n", boost::lexical_cast<std::string>(CommodityID).c_str());
	}
	if (compare(CommodityType, pOriginal->CommodityType) != 0)
	{
		fprintf(fp, "\t\tCommodityType = %s -> %s    [��Ʒ����]\n", boost::lexical_cast<std::string>(pOriginal->CommodityType).c_str(), boost::lexical_cast<std::string>(CommodityType).c_str());
	}
	else
	{
		fprintf(fp, "\t\tCommodityType = %s    [��Ʒ����]\n", boost::lexical_cast<std::string>(CommodityType).c_str());
	}
	if (compare(ExchangeInstID, pOriginal->ExchangeInstID) != 0)
	{
		fprintf(fp, "\t\tExchangeInstID = %s -> %s    [��Լ�ڽ������Ĵ��루CTP��������ʢ�У�ָ��RelateCommodityNo��������Լ��]\n", boost::lexical_cast<std::string>(pOriginal->ExchangeInstID).c_str(), boost::lexical_cast<std::string>(ExchangeInstID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tExchangeInstID = %s    [��Լ�ڽ������Ĵ��루CTP��������ʢ�У�ָ��RelateCommodityNo��������Լ��]\n", boost::lexical_cast<std::string>(ExchangeInstID).c_str());
	}
	if (compare(CommodityName, pOriginal->CommodityName) != 0)
	{
		fprintf(fp, "\t\tCommodityName = %s -> %s    [��Ʒ����]\n", boost::lexical_cast<std::string>(pOriginal->CommodityName).c_str(), boost::lexical_cast<std::string>(CommodityName).c_str());
	}
	else
	{
		fprintf(fp, "\t\tCommodityName = %s    [��Ʒ����]\n", boost::lexical_cast<std::string>(CommodityName).c_str());
	}
	if (compare(CommodityAttribute, pOriginal->CommodityAttribute) != 0)
	{
		fprintf(fp, "\t\tCommodityAttribute = %s -> %s    [��Ʒ����]\n", boost::lexical_cast<std::string>(pOriginal->CommodityAttribute).c_str(), boost::lexical_cast<std::string>(CommodityAttribute).c_str());
	}
	else
	{
		fprintf(fp, "\t\tCommodityAttribute = %s    [��Ʒ����]\n", boost::lexical_cast<std::string>(CommodityAttribute).c_str());
	}
	if (compare(CommodityState, pOriginal->CommodityState) != 0)
	{
		fprintf(fp, "\t\tCommodityState = %s -> %s    [��Ʒ״̬]\n", boost::lexical_cast<std::string>(pOriginal->CommodityState).c_str(), boost::lexical_cast<std::string>(CommodityState).c_str());
	}
	else
	{
		fprintf(fp, "\t\tCommodityState = %s    [��Ʒ״̬]\n", boost::lexical_cast<std::string>(CommodityState).c_str());
	}
	if (compare(MultipleValue, pOriginal->MultipleValue) != 0)
	{
		fprintf(fp, "\t\tMultipleValue = %s -> %s    [ÿ�ֳ���]\n", boost::lexical_cast<std::string>(pOriginal->MultipleValue).c_str(), boost::lexical_cast<std::string>(MultipleValue).c_str());
	}
	else
	{
		fprintf(fp, "\t\tMultipleValue = %s    [ÿ�ֳ���]\n", boost::lexical_cast<std::string>(MultipleValue).c_str());
	}
	if (compare(UpperTick, pOriginal->UpperTick) != 0)
	{
		fprintf(fp, "\t\tUpperTick = %s -> %s    [��С�䶯�۷���]\n", boost::lexical_cast<std::string>(pOriginal->UpperTick).c_str(), boost::lexical_cast<std::string>(UpperTick).c_str());
	}
	else
	{
		fprintf(fp, "\t\tUpperTick = %s    [��С�䶯�۷���]\n", boost::lexical_cast<std::string>(UpperTick).c_str());
	}
	if (compare(LowerTick, pOriginal->LowerTick) != 0)
	{
		fprintf(fp, "\t\tLowerTick = %s -> %s    [��С�䶯�۷�ĸ]\n", boost::lexical_cast<std::string>(pOriginal->LowerTick).c_str(), boost::lexical_cast<std::string>(LowerTick).c_str());
	}
	else
	{
		fprintf(fp, "\t\tLowerTick = %s    [��С�䶯�۷�ĸ]\n", boost::lexical_cast<std::string>(LowerTick).c_str());
	}
	if (compare(Precision, pOriginal->Precision) != 0)
	{
		fprintf(fp, "\t\tPrecision = %s -> %s    [���۾���]\n", boost::lexical_cast<std::string>(pOriginal->Precision).c_str(), boost::lexical_cast<std::string>(Precision).c_str());
	}
	else
	{
		fprintf(fp, "\t\tPrecision = %s    [���۾���]\n", boost::lexical_cast<std::string>(Precision).c_str());
	}
	if (compare(CurrencyID, pOriginal->CurrencyID) != 0)
	{
		fprintf(fp, "\t\tCurrencyID = %s -> %s    [��Ʒʹ�ñ���]\n", boost::lexical_cast<std::string>(pOriginal->CurrencyID).c_str(), boost::lexical_cast<std::string>(CurrencyID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tCurrencyID = %s    [��Ʒʹ�ñ���]\n", boost::lexical_cast<std::string>(CurrencyID).c_str());
	}
	if (compare(DeliveryMode, pOriginal->DeliveryMode) != 0)
	{
		fprintf(fp, "\t\tDeliveryMode = %s -> %s    [���ʽ]\n", boost::lexical_cast<std::string>(pOriginal->DeliveryMode).c_str(), boost::lexical_cast<std::string>(DeliveryMode).c_str());
	}
	else
	{
		fprintf(fp, "\t\tDeliveryMode = %s    [���ʽ]\n", boost::lexical_cast<std::string>(DeliveryMode).c_str());
	}
	if (compare(DeliveryDays, pOriginal->DeliveryDays) != 0)
	{
		fprintf(fp, "\t\tDeliveryDays = %s -> %s    [������ƫ��]\n", boost::lexical_cast<std::string>(pOriginal->DeliveryDays).c_str(), boost::lexical_cast<std::string>(DeliveryDays).c_str());
	}
	else
	{
		fprintf(fp, "\t\tDeliveryDays = %s    [������ƫ��]\n", boost::lexical_cast<std::string>(DeliveryDays).c_str());
	}
	if (compare(DeliveryYear, pOriginal->DeliveryYear) != 0)
	{
		fprintf(fp, "\t\tDeliveryYear = %s -> %s    [�������]\n", boost::lexical_cast<std::string>(pOriginal->DeliveryYear).c_str(), boost::lexical_cast<std::string>(DeliveryYear).c_str());
	}
	else
	{
		fprintf(fp, "\t\tDeliveryYear = %s    [�������]\n", boost::lexical_cast<std::string>(DeliveryYear).c_str());
	}
	if (compare(DeliveryMonth, pOriginal->DeliveryMonth) != 0)
	{
		fprintf(fp, "\t\tDeliveryMonth = %s -> %s    [������]\n", boost::lexical_cast<std::string>(pOriginal->DeliveryMonth).c_str(), boost::lexical_cast<std::string>(DeliveryMonth).c_str());
	}
	else
	{
		fprintf(fp, "\t\tDeliveryMonth = %s    [������]\n", boost::lexical_cast<std::string>(DeliveryMonth).c_str());
	}
	if (compare(MaxMarketOrderVolume, pOriginal->MaxMarketOrderVolume) != 0)
	{
		fprintf(fp, "\t\tMaxMarketOrderVolume = %s -> %s    [�м۵�����µ���]\n", boost::lexical_cast<std::string>(pOriginal->MaxMarketOrderVolume).c_str(), boost::lexical_cast<std::string>(MaxMarketOrderVolume).c_str());
	}
	else
	{
		fprintf(fp, "\t\tMaxMarketOrderVolume = %s    [�м۵�����µ���]\n", boost::lexical_cast<std::string>(MaxMarketOrderVolume).c_str());
	}
	if (compare(MinMarketOrderVolume, pOriginal->MinMarketOrderVolume) != 0)
	{
		fprintf(fp, "\t\tMinMarketOrderVolume = %s -> %s    [�м۵���С�µ���]\n", boost::lexical_cast<std::string>(pOriginal->MinMarketOrderVolume).c_str(), boost::lexical_cast<std::string>(MinMarketOrderVolume).c_str());
	}
	else
	{
		fprintf(fp, "\t\tMinMarketOrderVolume = %s    [�м۵���С�µ���]\n", boost::lexical_cast<std::string>(MinMarketOrderVolume).c_str());
	}
	if (compare(MaxLimitOrderVolume, pOriginal->MaxLimitOrderVolume) != 0)
	{
		fprintf(fp, "\t\tMaxLimitOrderVolume = %s -> %s    [�޼۵�����µ���]\n", boost::lexical_cast<std::string>(pOriginal->MaxLimitOrderVolume).c_str(), boost::lexical_cast<std::string>(MaxLimitOrderVolume).c_str());
	}
	else
	{
		fprintf(fp, "\t\tMaxLimitOrderVolume = %s    [�޼۵�����µ���]\n", boost::lexical_cast<std::string>(MaxLimitOrderVolume).c_str());
	}
	if (compare(MinLimitOrderVolume, pOriginal->MinLimitOrderVolume) != 0)
	{
		fprintf(fp, "\t\tMinLimitOrderVolume = %s -> %s    [�޼۵���С�µ���]\n", boost::lexical_cast<std::string>(pOriginal->MinLimitOrderVolume).c_str(), boost::lexical_cast<std::string>(MinLimitOrderVolume).c_str());
	}
	else
	{
		fprintf(fp, "\t\tMinLimitOrderVolume = %s    [�޼۵���С�µ���]\n", boost::lexical_cast<std::string>(MinLimitOrderVolume).c_str());
	}
	if (compare(DepositCalculateMode, pOriginal->DepositCalculateMode) != 0)
	{
		fprintf(fp, "\t\tDepositCalculateMode = %s -> %s    [��֤����㷽ʽ]\n", boost::lexical_cast<std::string>(pOriginal->DepositCalculateMode).c_str(), boost::lexical_cast<std::string>(DepositCalculateMode).c_str());
	}
	else
	{
		fprintf(fp, "\t\tDepositCalculateMode = %s    [��֤����㷽ʽ]\n", boost::lexical_cast<std::string>(DepositCalculateMode).c_str());
	}
	if (compare(MaxHoldVol, pOriginal->MaxHoldVol) != 0)
	{
		fprintf(fp, "\t\tMaxHoldVol = %s -> %s    [���ֲ���]\n", boost::lexical_cast<std::string>(pOriginal->MaxHoldVol).c_str(), boost::lexical_cast<std::string>(MaxHoldVol).c_str());
	}
	else
	{
		fprintf(fp, "\t\tMaxHoldVol = %s    [���ֲ���]\n", boost::lexical_cast<std::string>(MaxHoldVol).c_str());
	}
	if (compare(AddOneTime, pOriginal->AddOneTime) != 0)
	{
		fprintf(fp, "\t\tAddOneTime = %s -> %s    [T+1ʱ��,���ڴ�ʱ��ΪT+1����]\n", boost::lexical_cast<std::string>(pOriginal->AddOneTime).c_str(), boost::lexical_cast<std::string>(AddOneTime).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAddOneTime = %s    [T+1ʱ��,���ڴ�ʱ��ΪT+1����]\n", boost::lexical_cast<std::string>(AddOneTime).c_str());
	}
	if (compare(CmbDirect, pOriginal->CmbDirect) != 0)
	{
		fprintf(fp, "\t\tCmbDirect = %s -> %s    [�����������(��һ��)]\n", boost::lexical_cast<std::string>(pOriginal->CmbDirect).c_str(), boost::lexical_cast<std::string>(CmbDirect).c_str());
	}
	else
	{
		fprintf(fp, "\t\tCmbDirect = %s    [�����������(��һ��)]\n", boost::lexical_cast<std::string>(CmbDirect).c_str());
	}
	if (compare(CoverMode, pOriginal->CoverMode) != 0)
	{
		fprintf(fp, "\t\tCoverMode = %s -> %s    [ƽ�ַ�ʽ]\n", boost::lexical_cast<std::string>(pOriginal->CoverMode).c_str(), boost::lexical_cast<std::string>(CoverMode).c_str());
	}
	else
	{
		fprintf(fp, "\t\tCoverMode = %s    [ƽ�ַ�ʽ]\n", boost::lexical_cast<std::string>(CoverMode).c_str());
	}
	fprintf(fp, "\t}\n");
}

void CCommodity::dumpInLine(FILE *fp) const
{
	if (fp == nullptr)
	{
		fp = stdout;
	}
	std::stringstream sbuf;

	sbuf << ",AppType," << AppType;
	sbuf << ",ExchangeID," << ExchangeID;
	sbuf << ",CommodityID," << CommodityID;
	sbuf << ",CommodityType," << CommodityType;
	sbuf << ",ExchangeInstID," << ExchangeInstID;
	sbuf << ",CommodityName," << CommodityName;
	sbuf << ",CommodityAttribute," << CommodityAttribute;
	sbuf << ",CommodityState," << CommodityState;
	sbuf << ",MultipleValue," << MultipleValue;
	sbuf << ",UpperTick," << UpperTick;
	sbuf << ",LowerTick," << LowerTick;
	sbuf << ",Precision," << Precision;
	sbuf << ",CurrencyID," << CurrencyID;
	sbuf << ",DeliveryMode," << DeliveryMode;
	sbuf << ",DeliveryDays," << DeliveryDays;
	sbuf << ",DeliveryYear," << DeliveryYear;
	sbuf << ",DeliveryMonth," << DeliveryMonth;
	sbuf << ",MaxMarketOrderVolume," << MaxMarketOrderVolume;
	sbuf << ",MinMarketOrderVolume," << MinMarketOrderVolume;
	sbuf << ",MaxLimitOrderVolume," << MaxLimitOrderVolume;
	sbuf << ",MinLimitOrderVolume," << MinLimitOrderVolume;
	sbuf << ",DepositCalculateMode," << DepositCalculateMode;
	sbuf << ",MaxHoldVol," << MaxHoldVol;
	sbuf << ",AddOneTime," << AddOneTime;
	sbuf << ",CmbDirect," << CmbDirect;
	sbuf << ",CoverMode," << CoverMode;
	fprintf(fp, "%s", sbuf.str().c_str());
}

void CCommodity::dumpString(char *target) const
{
	char *p = target;
	std::stringstream sbuf;

	sbuf << "AppType=" << AppType << ",";
	sbuf << "ExchangeID=" << ExchangeID << ",";
	sbuf << "CommodityID=" << CommodityID << ",";
	sbuf << "CommodityType=" << CommodityType << ",";
	sbuf << "ExchangeInstID=" << ExchangeInstID << ",";
	sbuf << "CommodityName=" << CommodityName << ",";
	sbuf << "CommodityAttribute=" << CommodityAttribute << ",";
	sbuf << "CommodityState=" << CommodityState << ",";
	sbuf << "MultipleValue=" << MultipleValue << ",";
	sbuf << "UpperTick=" << UpperTick << ",";
	sbuf << "LowerTick=" << LowerTick << ",";
	sbuf << "Precision=" << Precision << ",";
	sbuf << "CurrencyID=" << CurrencyID << ",";
	sbuf << "DeliveryMode=" << DeliveryMode << ",";
	sbuf << "DeliveryDays=" << DeliveryDays << ",";
	sbuf << "DeliveryYear=" << DeliveryYear << ",";
	sbuf << "DeliveryMonth=" << DeliveryMonth << ",";
	sbuf << "MaxMarketOrderVolume=" << MaxMarketOrderVolume << ",";
	sbuf << "MinMarketOrderVolume=" << MinMarketOrderVolume << ",";
	sbuf << "MaxLimitOrderVolume=" << MaxLimitOrderVolume << ",";
	sbuf << "MinLimitOrderVolume=" << MinLimitOrderVolume << ",";
	sbuf << "DepositCalculateMode=" << DepositCalculateMode << ",";
	sbuf << "MaxHoldVol=" << MaxHoldVol << ",";
	sbuf << "AddOneTime=" << AddOneTime << ",";
	sbuf << "CmbDirect=" << CmbDirect << ",";
	sbuf << "CoverMode=" << CoverMode << ",";

	sprintf(p, "%s", sbuf.str().c_str());
}

void CInstrument::init(void)
{
	memset(this, 0, sizeof(CInstrument));
}

int CInstrument::read(FILE *input)
{
	if (fread(this, 1, sizeof(CInstrument), input) != sizeof(CInstrument))
		return 0;
	else
		return 1;
}

int CInstrument::write(FILE *output) const
{
	if (fwrite(this, 1, sizeof(CInstrument), output) != sizeof(CInstrument))
		return 0;
	else
		return 1;
}

void CInstrument::dump(FILE *fp, int index) const
{
	char index_buf[64];
	//char buf[4000];///���ÿ����Ա���ַ���ֵ	
	if (fp == NULL)
	{
		fp = stdout;
	}
	if (index >= 0)
		sprintf(index_buf, "[%d]", index);
	else
		index_buf[0] = '\0';
	fprintf(fp, "\tCInstrument%s = {\n", index_buf);
	fprintf(fp, "\t\tAppType = %s    [���׽ӿ�����]\n", boost::lexical_cast<std::string>(AppType).c_str());
	fprintf(fp, "\t\tExchangeID = %s    [����������]\n", boost::lexical_cast<std::string>(ExchangeID).c_str());
	fprintf(fp, "\t\tCommodityID = %s    [��Ʒ]\n", boost::lexical_cast<std::string>(CommodityID).c_str());
	fprintf(fp, "\t\tCommodityType = %s    [��Ʒ����]\n", boost::lexical_cast<std::string>(CommodityType).c_str());
	fprintf(fp, "\t\tInstrumentID = %s    [��Լ]\n", boost::lexical_cast<std::string>(InstrumentID).c_str());
	fprintf(fp, "\t\tInstrumentName = %s    [��Լ����]\n", boost::lexical_cast<std::string>(InstrumentName).c_str());
	fprintf(fp, "\t\tInstrumentType = %s    [��Լ����]\n", boost::lexical_cast<std::string>(InstrumentType).c_str());
	fprintf(fp, "\t\tInstrumentState = %s    [��Լ״̬]\n", boost::lexical_cast<std::string>(InstrumentState).c_str());
	fprintf(fp, "\t\tExchangeInstID = %s    [��Լ�ڽ������Ĵ��루CTP��������ʢ�У�ָ��RelateCommodityNo��������Լ��]\n", boost::lexical_cast<std::string>(ExchangeInstID).c_str());
	fprintf(fp, "\t\tInstLifePhase = %s    [��Լ��������״̬]\n", boost::lexical_cast<std::string>(InstLifePhase).c_str());
	fprintf(fp, "\t\tCommodityName = %s    [��Ʒ����]\n", boost::lexical_cast<std::string>(CommodityName).c_str());
	fprintf(fp, "\t\tCommodityAttribute = %s    [��Ʒ����]\n", boost::lexical_cast<std::string>(CommodityAttribute).c_str());
	fprintf(fp, "\t\tTradeRight = %s    [��Ʒ����Ȩ��]\n", boost::lexical_cast<std::string>(TradeRight).c_str());
	fprintf(fp, "\t\tMultipleValue = %s    [ÿ�ֳ���]\n", boost::lexical_cast<std::string>(MultipleValue).c_str());
	fprintf(fp, "\t\tPriceTick = %s    [��С�䶯��λ]\n", boost::lexical_cast<std::string>(PriceTick).c_str());
	fprintf(fp, "\t\tUpperTick = %s    [��С�䶯�۷���]\n", boost::lexical_cast<std::string>(UpperTick).c_str());
	fprintf(fp, "\t\tLowerTick = %s    [��С�䶯�۷�ĸ]\n", boost::lexical_cast<std::string>(LowerTick).c_str());
	fprintf(fp, "\t\tCurrencyID = %s    [��Ʒʹ�ñ���]\n", boost::lexical_cast<std::string>(CurrencyID).c_str());
	fprintf(fp, "\t\tPrecision = %s    [���۾���]\n", boost::lexical_cast<std::string>(Precision).c_str());
	fprintf(fp, "\t\tDeliveryMode = %s    [���ʽ]\n", boost::lexical_cast<std::string>(DeliveryMode).c_str());
	fprintf(fp, "\t\tDeliveryDays = %s    [������ƫ��]\n", boost::lexical_cast<std::string>(DeliveryDays).c_str());
	fprintf(fp, "\t\tDeliveryYear = %s    [�������]\n", boost::lexical_cast<std::string>(DeliveryYear).c_str());
	fprintf(fp, "\t\tDeliveryMonth = %s    [������]\n", boost::lexical_cast<std::string>(DeliveryMonth).c_str());
	fprintf(fp, "\t\tMaxMarketOrderVolume = %s    [�м۵�����µ���]\n", boost::lexical_cast<std::string>(MaxMarketOrderVolume).c_str());
	fprintf(fp, "\t\tMinMarketOrderVolume = %s    [�м۵���С�µ���]\n", boost::lexical_cast<std::string>(MinMarketOrderVolume).c_str());
	fprintf(fp, "\t\tMaxLimitOrderVolume = %s    [�޼۵�����µ���]\n", boost::lexical_cast<std::string>(MaxLimitOrderVolume).c_str());
	fprintf(fp, "\t\tMinLimitOrderVolume = %s    [�޼۵���С�µ���]\n", boost::lexical_cast<std::string>(MinLimitOrderVolume).c_str());
	fprintf(fp, "\t\tDepositCalculateMode = %s    [��֤����㷽ʽ]\n", boost::lexical_cast<std::string>(DepositCalculateMode).c_str());
	fprintf(fp, "\t\tMaxHoldVol = %s    [���ֲ���]\n", boost::lexical_cast<std::string>(MaxHoldVol).c_str());
	fprintf(fp, "\t\tAddOneTime = %s    [T+1ʱ��,���ڴ�ʱ��ΪT+1����]\n", boost::lexical_cast<std::string>(AddOneTime).c_str());
	fprintf(fp, "\t\tCmbDirect = %s    [�����������(��һ��)]\n", boost::lexical_cast<std::string>(CmbDirect).c_str());
	fprintf(fp, "\t\tCoverMode = %s    [ƽ�ַ�ʽ]\n", boost::lexical_cast<std::string>(CoverMode).c_str());
	fprintf(fp, "\t\tCreateDate = %s    [������]\n", boost::lexical_cast<std::string>(CreateDate).c_str());
	fprintf(fp, "\t\tOpenDate = %s    [������]\n", boost::lexical_cast<std::string>(OpenDate).c_str());
	fprintf(fp, "\t\tExpiryDate = %s    [������]\n", boost::lexical_cast<std::string>(ExpiryDate).c_str());
	fprintf(fp, "\t\tStartDelivDate = %s    [��ʼ������]\n", boost::lexical_cast<std::string>(StartDelivDate).c_str());
	fprintf(fp, "\t\tEndDelivDate = %s    [����������]\n", boost::lexical_cast<std::string>(EndDelivDate).c_str());
	fprintf(fp, "\t\tPositionType = %s    [�ֲ�����]\n", boost::lexical_cast<std::string>(PositionType).c_str());
	fprintf(fp, "\t\tPositionDateType = %s    [�ֲ���������]\n", boost::lexical_cast<std::string>(PositionDateType).c_str());
	fprintf(fp, "\t\tLongMarginRatio = %s    [��ͷ��֤����]\n", boost::lexical_cast<std::string>(LongMarginRatio).c_str());
	fprintf(fp, "\t\tShortMarginRatio = %s    [��ͷ��֤����]\n", boost::lexical_cast<std::string>(ShortMarginRatio).c_str());
	fprintf(fp, "\t\tMaxMarginSideAlgorithm = %s    [�Ƿ�ʹ�ô��߱�֤���㷨]\n", boost::lexical_cast<std::string>(MaxMarginSideAlgorithm).c_str());
	fprintf(fp, "\t}\n");
}

void CInstrument::dumpDiff(FILE *fp, const CInstrument *pOriginal) const
{
	//char buf[4000],bufOriginal[4000];
	if (fp == NULL)
	{
		fp = stdout;
	}
	fprintf(fp, "\tCInstrument = {\n");
	if (compare(AppType, pOriginal->AppType) != 0)
	{
		fprintf(fp, "\t\tAppType = %s -> %s    [���׽ӿ�����]\n", boost::lexical_cast<std::string>(pOriginal->AppType).c_str(), boost::lexical_cast<std::string>(AppType).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAppType = %s    [���׽ӿ�����]\n", boost::lexical_cast<std::string>(AppType).c_str());
	}
	if (compare(ExchangeID, pOriginal->ExchangeID) != 0)
	{
		fprintf(fp, "\t\tExchangeID = %s -> %s    [����������]\n", boost::lexical_cast<std::string>(pOriginal->ExchangeID).c_str(), boost::lexical_cast<std::string>(ExchangeID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tExchangeID = %s    [����������]\n", boost::lexical_cast<std::string>(ExchangeID).c_str());
	}
	if (compare(CommodityID, pOriginal->CommodityID) != 0)
	{
		fprintf(fp, "\t\tCommodityID = %s -> %s    [��Ʒ]\n", boost::lexical_cast<std::string>(pOriginal->CommodityID).c_str(), boost::lexical_cast<std::string>(CommodityID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tCommodityID = %s    [��Ʒ]\n", boost::lexical_cast<std::string>(CommodityID).c_str());
	}
	if (compare(CommodityType, pOriginal->CommodityType) != 0)
	{
		fprintf(fp, "\t\tCommodityType = %s -> %s    [��Ʒ����]\n", boost::lexical_cast<std::string>(pOriginal->CommodityType).c_str(), boost::lexical_cast<std::string>(CommodityType).c_str());
	}
	else
	{
		fprintf(fp, "\t\tCommodityType = %s    [��Ʒ����]\n", boost::lexical_cast<std::string>(CommodityType).c_str());
	}
	if (compare(InstrumentID, pOriginal->InstrumentID) != 0)
	{
		fprintf(fp, "\t\tInstrumentID = %s -> %s    [��Լ]\n", boost::lexical_cast<std::string>(pOriginal->InstrumentID).c_str(), boost::lexical_cast<std::string>(InstrumentID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tInstrumentID = %s    [��Լ]\n", boost::lexical_cast<std::string>(InstrumentID).c_str());
	}
	if (compare(InstrumentName, pOriginal->InstrumentName) != 0)
	{
		fprintf(fp, "\t\tInstrumentName = %s -> %s    [��Լ����]\n", boost::lexical_cast<std::string>(pOriginal->InstrumentName).c_str(), boost::lexical_cast<std::string>(InstrumentName).c_str());
	}
	else
	{
		fprintf(fp, "\t\tInstrumentName = %s    [��Լ����]\n", boost::lexical_cast<std::string>(InstrumentName).c_str());
	}
	if (compare(InstrumentType, pOriginal->InstrumentType) != 0)
	{
		fprintf(fp, "\t\tInstrumentType = %s -> %s    [��Լ����]\n", boost::lexical_cast<std::string>(pOriginal->InstrumentType).c_str(), boost::lexical_cast<std::string>(InstrumentType).c_str());
	}
	else
	{
		fprintf(fp, "\t\tInstrumentType = %s    [��Լ����]\n", boost::lexical_cast<std::string>(InstrumentType).c_str());
	}
	if (compare(InstrumentState, pOriginal->InstrumentState) != 0)
	{
		fprintf(fp, "\t\tInstrumentState = %s -> %s    [��Լ״̬]\n", boost::lexical_cast<std::string>(pOriginal->InstrumentState).c_str(), boost::lexical_cast<std::string>(InstrumentState).c_str());
	}
	else
	{
		fprintf(fp, "\t\tInstrumentState = %s    [��Լ״̬]\n", boost::lexical_cast<std::string>(InstrumentState).c_str());
	}
	if (compare(ExchangeInstID, pOriginal->ExchangeInstID) != 0)
	{
		fprintf(fp, "\t\tExchangeInstID = %s -> %s    [��Լ�ڽ������Ĵ��루CTP��������ʢ�У�ָ��RelateCommodityNo��������Լ��]\n", boost::lexical_cast<std::string>(pOriginal->ExchangeInstID).c_str(), boost::lexical_cast<std::string>(ExchangeInstID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tExchangeInstID = %s    [��Լ�ڽ������Ĵ��루CTP��������ʢ�У�ָ��RelateCommodityNo��������Լ��]\n", boost::lexical_cast<std::string>(ExchangeInstID).c_str());
	}
	if (compare(InstLifePhase, pOriginal->InstLifePhase) != 0)
	{
		fprintf(fp, "\t\tInstLifePhase = %s -> %s    [��Լ��������״̬]\n", boost::lexical_cast<std::string>(pOriginal->InstLifePhase).c_str(), boost::lexical_cast<std::string>(InstLifePhase).c_str());
	}
	else
	{
		fprintf(fp, "\t\tInstLifePhase = %s    [��Լ��������״̬]\n", boost::lexical_cast<std::string>(InstLifePhase).c_str());
	}
	if (compare(CommodityName, pOriginal->CommodityName) != 0)
	{
		fprintf(fp, "\t\tCommodityName = %s -> %s    [��Ʒ����]\n", boost::lexical_cast<std::string>(pOriginal->CommodityName).c_str(), boost::lexical_cast<std::string>(CommodityName).c_str());
	}
	else
	{
		fprintf(fp, "\t\tCommodityName = %s    [��Ʒ����]\n", boost::lexical_cast<std::string>(CommodityName).c_str());
	}
	if (compare(CommodityAttribute, pOriginal->CommodityAttribute) != 0)
	{
		fprintf(fp, "\t\tCommodityAttribute = %s -> %s    [��Ʒ����]\n", boost::lexical_cast<std::string>(pOriginal->CommodityAttribute).c_str(), boost::lexical_cast<std::string>(CommodityAttribute).c_str());
	}
	else
	{
		fprintf(fp, "\t\tCommodityAttribute = %s    [��Ʒ����]\n", boost::lexical_cast<std::string>(CommodityAttribute).c_str());
	}
	if (compare(TradeRight, pOriginal->TradeRight) != 0)
	{
		fprintf(fp, "\t\tTradeRight = %s -> %s    [��Ʒ����Ȩ��]\n", boost::lexical_cast<std::string>(pOriginal->TradeRight).c_str(), boost::lexical_cast<std::string>(TradeRight).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTradeRight = %s    [��Ʒ����Ȩ��]\n", boost::lexical_cast<std::string>(TradeRight).c_str());
	}
	if (compare(MultipleValue, pOriginal->MultipleValue) != 0)
	{
		fprintf(fp, "\t\tMultipleValue = %s -> %s    [ÿ�ֳ���]\n", boost::lexical_cast<std::string>(pOriginal->MultipleValue).c_str(), boost::lexical_cast<std::string>(MultipleValue).c_str());
	}
	else
	{
		fprintf(fp, "\t\tMultipleValue = %s    [ÿ�ֳ���]\n", boost::lexical_cast<std::string>(MultipleValue).c_str());
	}
	if (compare(PriceTick, pOriginal->PriceTick) != 0)
	{
		fprintf(fp, "\t\tPriceTick = %s -> %s    [��С�䶯��λ]\n", boost::lexical_cast<std::string>(pOriginal->PriceTick).c_str(), boost::lexical_cast<std::string>(PriceTick).c_str());
	}
	else
	{
		fprintf(fp, "\t\tPriceTick = %s    [��С�䶯��λ]\n", boost::lexical_cast<std::string>(PriceTick).c_str());
	}
	if (compare(UpperTick, pOriginal->UpperTick) != 0)
	{
		fprintf(fp, "\t\tUpperTick = %s -> %s    [��С�䶯�۷���]\n", boost::lexical_cast<std::string>(pOriginal->UpperTick).c_str(), boost::lexical_cast<std::string>(UpperTick).c_str());
	}
	else
	{
		fprintf(fp, "\t\tUpperTick = %s    [��С�䶯�۷���]\n", boost::lexical_cast<std::string>(UpperTick).c_str());
	}
	if (compare(LowerTick, pOriginal->LowerTick) != 0)
	{
		fprintf(fp, "\t\tLowerTick = %s -> %s    [��С�䶯�۷�ĸ]\n", boost::lexical_cast<std::string>(pOriginal->LowerTick).c_str(), boost::lexical_cast<std::string>(LowerTick).c_str());
	}
	else
	{
		fprintf(fp, "\t\tLowerTick = %s    [��С�䶯�۷�ĸ]\n", boost::lexical_cast<std::string>(LowerTick).c_str());
	}
	if (compare(CurrencyID, pOriginal->CurrencyID) != 0)
	{
		fprintf(fp, "\t\tCurrencyID = %s -> %s    [��Ʒʹ�ñ���]\n", boost::lexical_cast<std::string>(pOriginal->CurrencyID).c_str(), boost::lexical_cast<std::string>(CurrencyID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tCurrencyID = %s    [��Ʒʹ�ñ���]\n", boost::lexical_cast<std::string>(CurrencyID).c_str());
	}
	if (compare(Precision, pOriginal->Precision) != 0)
	{
		fprintf(fp, "\t\tPrecision = %s -> %s    [���۾���]\n", boost::lexical_cast<std::string>(pOriginal->Precision).c_str(), boost::lexical_cast<std::string>(Precision).c_str());
	}
	else
	{
		fprintf(fp, "\t\tPrecision = %s    [���۾���]\n", boost::lexical_cast<std::string>(Precision).c_str());
	}
	if (compare(DeliveryMode, pOriginal->DeliveryMode) != 0)
	{
		fprintf(fp, "\t\tDeliveryMode = %s -> %s    [���ʽ]\n", boost::lexical_cast<std::string>(pOriginal->DeliveryMode).c_str(), boost::lexical_cast<std::string>(DeliveryMode).c_str());
	}
	else
	{
		fprintf(fp, "\t\tDeliveryMode = %s    [���ʽ]\n", boost::lexical_cast<std::string>(DeliveryMode).c_str());
	}
	if (compare(DeliveryDays, pOriginal->DeliveryDays) != 0)
	{
		fprintf(fp, "\t\tDeliveryDays = %s -> %s    [������ƫ��]\n", boost::lexical_cast<std::string>(pOriginal->DeliveryDays).c_str(), boost::lexical_cast<std::string>(DeliveryDays).c_str());
	}
	else
	{
		fprintf(fp, "\t\tDeliveryDays = %s    [������ƫ��]\n", boost::lexical_cast<std::string>(DeliveryDays).c_str());
	}
	if (compare(DeliveryYear, pOriginal->DeliveryYear) != 0)
	{
		fprintf(fp, "\t\tDeliveryYear = %s -> %s    [�������]\n", boost::lexical_cast<std::string>(pOriginal->DeliveryYear).c_str(), boost::lexical_cast<std::string>(DeliveryYear).c_str());
	}
	else
	{
		fprintf(fp, "\t\tDeliveryYear = %s    [�������]\n", boost::lexical_cast<std::string>(DeliveryYear).c_str());
	}
	if (compare(DeliveryMonth, pOriginal->DeliveryMonth) != 0)
	{
		fprintf(fp, "\t\tDeliveryMonth = %s -> %s    [������]\n", boost::lexical_cast<std::string>(pOriginal->DeliveryMonth).c_str(), boost::lexical_cast<std::string>(DeliveryMonth).c_str());
	}
	else
	{
		fprintf(fp, "\t\tDeliveryMonth = %s    [������]\n", boost::lexical_cast<std::string>(DeliveryMonth).c_str());
	}
	if (compare(MaxMarketOrderVolume, pOriginal->MaxMarketOrderVolume) != 0)
	{
		fprintf(fp, "\t\tMaxMarketOrderVolume = %s -> %s    [�м۵�����µ���]\n", boost::lexical_cast<std::string>(pOriginal->MaxMarketOrderVolume).c_str(), boost::lexical_cast<std::string>(MaxMarketOrderVolume).c_str());
	}
	else
	{
		fprintf(fp, "\t\tMaxMarketOrderVolume = %s    [�м۵�����µ���]\n", boost::lexical_cast<std::string>(MaxMarketOrderVolume).c_str());
	}
	if (compare(MinMarketOrderVolume, pOriginal->MinMarketOrderVolume) != 0)
	{
		fprintf(fp, "\t\tMinMarketOrderVolume = %s -> %s    [�м۵���С�µ���]\n", boost::lexical_cast<std::string>(pOriginal->MinMarketOrderVolume).c_str(), boost::lexical_cast<std::string>(MinMarketOrderVolume).c_str());
	}
	else
	{
		fprintf(fp, "\t\tMinMarketOrderVolume = %s    [�м۵���С�µ���]\n", boost::lexical_cast<std::string>(MinMarketOrderVolume).c_str());
	}
	if (compare(MaxLimitOrderVolume, pOriginal->MaxLimitOrderVolume) != 0)
	{
		fprintf(fp, "\t\tMaxLimitOrderVolume = %s -> %s    [�޼۵�����µ���]\n", boost::lexical_cast<std::string>(pOriginal->MaxLimitOrderVolume).c_str(), boost::lexical_cast<std::string>(MaxLimitOrderVolume).c_str());
	}
	else
	{
		fprintf(fp, "\t\tMaxLimitOrderVolume = %s    [�޼۵�����µ���]\n", boost::lexical_cast<std::string>(MaxLimitOrderVolume).c_str());
	}
	if (compare(MinLimitOrderVolume, pOriginal->MinLimitOrderVolume) != 0)
	{
		fprintf(fp, "\t\tMinLimitOrderVolume = %s -> %s    [�޼۵���С�µ���]\n", boost::lexical_cast<std::string>(pOriginal->MinLimitOrderVolume).c_str(), boost::lexical_cast<std::string>(MinLimitOrderVolume).c_str());
	}
	else
	{
		fprintf(fp, "\t\tMinLimitOrderVolume = %s    [�޼۵���С�µ���]\n", boost::lexical_cast<std::string>(MinLimitOrderVolume).c_str());
	}
	if (compare(DepositCalculateMode, pOriginal->DepositCalculateMode) != 0)
	{
		fprintf(fp, "\t\tDepositCalculateMode = %s -> %s    [��֤����㷽ʽ]\n", boost::lexical_cast<std::string>(pOriginal->DepositCalculateMode).c_str(), boost::lexical_cast<std::string>(DepositCalculateMode).c_str());
	}
	else
	{
		fprintf(fp, "\t\tDepositCalculateMode = %s    [��֤����㷽ʽ]\n", boost::lexical_cast<std::string>(DepositCalculateMode).c_str());
	}
	if (compare(MaxHoldVol, pOriginal->MaxHoldVol) != 0)
	{
		fprintf(fp, "\t\tMaxHoldVol = %s -> %s    [���ֲ���]\n", boost::lexical_cast<std::string>(pOriginal->MaxHoldVol).c_str(), boost::lexical_cast<std::string>(MaxHoldVol).c_str());
	}
	else
	{
		fprintf(fp, "\t\tMaxHoldVol = %s    [���ֲ���]\n", boost::lexical_cast<std::string>(MaxHoldVol).c_str());
	}
	if (compare(AddOneTime, pOriginal->AddOneTime) != 0)
	{
		fprintf(fp, "\t\tAddOneTime = %s -> %s    [T+1ʱ��,���ڴ�ʱ��ΪT+1����]\n", boost::lexical_cast<std::string>(pOriginal->AddOneTime).c_str(), boost::lexical_cast<std::string>(AddOneTime).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAddOneTime = %s    [T+1ʱ��,���ڴ�ʱ��ΪT+1����]\n", boost::lexical_cast<std::string>(AddOneTime).c_str());
	}
	if (compare(CmbDirect, pOriginal->CmbDirect) != 0)
	{
		fprintf(fp, "\t\tCmbDirect = %s -> %s    [�����������(��һ��)]\n", boost::lexical_cast<std::string>(pOriginal->CmbDirect).c_str(), boost::lexical_cast<std::string>(CmbDirect).c_str());
	}
	else
	{
		fprintf(fp, "\t\tCmbDirect = %s    [�����������(��һ��)]\n", boost::lexical_cast<std::string>(CmbDirect).c_str());
	}
	if (compare(CoverMode, pOriginal->CoverMode) != 0)
	{
		fprintf(fp, "\t\tCoverMode = %s -> %s    [ƽ�ַ�ʽ]\n", boost::lexical_cast<std::string>(pOriginal->CoverMode).c_str(), boost::lexical_cast<std::string>(CoverMode).c_str());
	}
	else
	{
		fprintf(fp, "\t\tCoverMode = %s    [ƽ�ַ�ʽ]\n", boost::lexical_cast<std::string>(CoverMode).c_str());
	}
	if (compare(CreateDate, pOriginal->CreateDate) != 0)
	{
		fprintf(fp, "\t\tCreateDate = %s -> %s    [������]\n", boost::lexical_cast<std::string>(pOriginal->CreateDate).c_str(), boost::lexical_cast<std::string>(CreateDate).c_str());
	}
	else
	{
		fprintf(fp, "\t\tCreateDate = %s    [������]\n", boost::lexical_cast<std::string>(CreateDate).c_str());
	}
	if (compare(OpenDate, pOriginal->OpenDate) != 0)
	{
		fprintf(fp, "\t\tOpenDate = %s -> %s    [������]\n", boost::lexical_cast<std::string>(pOriginal->OpenDate).c_str(), boost::lexical_cast<std::string>(OpenDate).c_str());
	}
	else
	{
		fprintf(fp, "\t\tOpenDate = %s    [������]\n", boost::lexical_cast<std::string>(OpenDate).c_str());
	}
	if (compare(ExpiryDate, pOriginal->ExpiryDate) != 0)
	{
		fprintf(fp, "\t\tExpiryDate = %s -> %s    [������]\n", boost::lexical_cast<std::string>(pOriginal->ExpiryDate).c_str(), boost::lexical_cast<std::string>(ExpiryDate).c_str());
	}
	else
	{
		fprintf(fp, "\t\tExpiryDate = %s    [������]\n", boost::lexical_cast<std::string>(ExpiryDate).c_str());
	}
	if (compare(StartDelivDate, pOriginal->StartDelivDate) != 0)
	{
		fprintf(fp, "\t\tStartDelivDate = %s -> %s    [��ʼ������]\n", boost::lexical_cast<std::string>(pOriginal->StartDelivDate).c_str(), boost::lexical_cast<std::string>(StartDelivDate).c_str());
	}
	else
	{
		fprintf(fp, "\t\tStartDelivDate = %s    [��ʼ������]\n", boost::lexical_cast<std::string>(StartDelivDate).c_str());
	}
	if (compare(EndDelivDate, pOriginal->EndDelivDate) != 0)
	{
		fprintf(fp, "\t\tEndDelivDate = %s -> %s    [����������]\n", boost::lexical_cast<std::string>(pOriginal->EndDelivDate).c_str(), boost::lexical_cast<std::string>(EndDelivDate).c_str());
	}
	else
	{
		fprintf(fp, "\t\tEndDelivDate = %s    [����������]\n", boost::lexical_cast<std::string>(EndDelivDate).c_str());
	}
	if (compare(PositionType, pOriginal->PositionType) != 0)
	{
		fprintf(fp, "\t\tPositionType = %s -> %s    [�ֲ�����]\n", boost::lexical_cast<std::string>(pOriginal->PositionType).c_str(), boost::lexical_cast<std::string>(PositionType).c_str());
	}
	else
	{
		fprintf(fp, "\t\tPositionType = %s    [�ֲ�����]\n", boost::lexical_cast<std::string>(PositionType).c_str());
	}
	if (compare(PositionDateType, pOriginal->PositionDateType) != 0)
	{
		fprintf(fp, "\t\tPositionDateType = %s -> %s    [�ֲ���������]\n", boost::lexical_cast<std::string>(pOriginal->PositionDateType).c_str(), boost::lexical_cast<std::string>(PositionDateType).c_str());
	}
	else
	{
		fprintf(fp, "\t\tPositionDateType = %s    [�ֲ���������]\n", boost::lexical_cast<std::string>(PositionDateType).c_str());
	}
	if (compare(LongMarginRatio, pOriginal->LongMarginRatio) != 0)
	{
		fprintf(fp, "\t\tLongMarginRatio = %s -> %s    [��ͷ��֤����]\n", boost::lexical_cast<std::string>(pOriginal->LongMarginRatio).c_str(), boost::lexical_cast<std::string>(LongMarginRatio).c_str());
	}
	else
	{
		fprintf(fp, "\t\tLongMarginRatio = %s    [��ͷ��֤����]\n", boost::lexical_cast<std::string>(LongMarginRatio).c_str());
	}
	if (compare(ShortMarginRatio, pOriginal->ShortMarginRatio) != 0)
	{
		fprintf(fp, "\t\tShortMarginRatio = %s -> %s    [��ͷ��֤����]\n", boost::lexical_cast<std::string>(pOriginal->ShortMarginRatio).c_str(), boost::lexical_cast<std::string>(ShortMarginRatio).c_str());
	}
	else
	{
		fprintf(fp, "\t\tShortMarginRatio = %s    [��ͷ��֤����]\n", boost::lexical_cast<std::string>(ShortMarginRatio).c_str());
	}
	if (compare(MaxMarginSideAlgorithm, pOriginal->MaxMarginSideAlgorithm) != 0)
	{
		fprintf(fp, "\t\tMaxMarginSideAlgorithm = %s -> %s    [�Ƿ�ʹ�ô��߱�֤���㷨]\n", boost::lexical_cast<std::string>(pOriginal->MaxMarginSideAlgorithm).c_str(), boost::lexical_cast<std::string>(MaxMarginSideAlgorithm).c_str());
	}
	else
	{
		fprintf(fp, "\t\tMaxMarginSideAlgorithm = %s    [�Ƿ�ʹ�ô��߱�֤���㷨]\n", boost::lexical_cast<std::string>(MaxMarginSideAlgorithm).c_str());
	}
	fprintf(fp, "\t}\n");
}

void CInstrument::dumpInLine(FILE *fp) const
{
	if (fp == NULL)
	{
		fp = stdout;
	}
	std::stringstream sbuf;

	sbuf << ",AppType," << AppType;
	sbuf << ",ExchangeID," << ExchangeID;
	sbuf << ",CommodityID," << CommodityID;
	sbuf << ",CommodityType," << CommodityType;
	sbuf << ",InstrumentID," << InstrumentID;
	sbuf << ",InstrumentName," << InstrumentName;
	sbuf << ",InstrumentType," << InstrumentType;
	sbuf << ",InstrumentState," << InstrumentState;
	sbuf << ",ExchangeInstID," << ExchangeInstID;
	sbuf << ",InstLifePhase," << InstLifePhase;
	sbuf << ",CommodityName," << CommodityName;
	sbuf << ",CommodityAttribute," << CommodityAttribute;
	sbuf << ",TradeRight," << TradeRight;
	sbuf << ",MultipleValue," << MultipleValue;
	sbuf << ",PriceTick," << PriceTick;
	sbuf << ",UpperTick," << UpperTick;
	sbuf << ",LowerTick," << LowerTick;
	sbuf << ",CurrencyID," << CurrencyID;
	sbuf << ",Precision," << Precision;
	sbuf << ",DeliveryMode," << DeliveryMode;
	sbuf << ",DeliveryDays," << DeliveryDays;
	sbuf << ",DeliveryYear," << DeliveryYear;
	sbuf << ",DeliveryMonth," << DeliveryMonth;
	sbuf << ",MaxMarketOrderVolume," << MaxMarketOrderVolume;
	sbuf << ",MinMarketOrderVolume," << MinMarketOrderVolume;
	sbuf << ",MaxLimitOrderVolume," << MaxLimitOrderVolume;
	sbuf << ",MinLimitOrderVolume," << MinLimitOrderVolume;
	sbuf << ",DepositCalculateMode," << DepositCalculateMode;
	sbuf << ",MaxHoldVol," << MaxHoldVol;
	sbuf << ",AddOneTime," << AddOneTime;
	sbuf << ",CmbDirect," << CmbDirect;
	sbuf << ",CoverMode," << CoverMode;
	sbuf << ",CreateDate," << CreateDate;
	sbuf << ",OpenDate," << OpenDate;
	sbuf << ",ExpiryDate," << ExpiryDate;
	sbuf << ",StartDelivDate," << StartDelivDate;
	sbuf << ",EndDelivDate," << EndDelivDate;
	sbuf << ",PositionType," << PositionType;
	sbuf << ",PositionDateType," << PositionDateType;
	sbuf << ",LongMarginRatio," << LongMarginRatio;
	sbuf << ",ShortMarginRatio," << ShortMarginRatio;
	sbuf << ",MaxMarginSideAlgorithm," << MaxMarginSideAlgorithm;
	fprintf(fp, "%s", sbuf.str().c_str());
}

void CInstrument::dumpString(char *target) const
{
	char *p = target;

	std::stringstream sbuf;

	sbuf << "AppType=" << AppType << ",";
	sbuf << "ExchangeID=" << ExchangeID << ",";
	sbuf << "CommodityID=" << CommodityID << ",";
	sbuf << "CommodityType=" << CommodityType << ",";
	sbuf << "InstrumentID=" << InstrumentID << ",";
	sbuf << "InstrumentName=" << InstrumentName << ",";
	sbuf << "InstrumentType=" << InstrumentType << ",";
	sbuf << "InstrumentState=" << InstrumentState << ",";
	sbuf << "ExchangeInstID=" << ExchangeInstID << ",";
	sbuf << "InstLifePhase=" << InstLifePhase << ",";
	sbuf << "CommodityName=" << CommodityName << ",";
	sbuf << "CommodityAttribute=" << CommodityAttribute << ",";
	sbuf << "TradeRight=" << TradeRight << ",";
	sbuf << "MultipleValue=" << MultipleValue << ",";
	sbuf << "PriceTick=" << PriceTick << ",";
	sbuf << "UpperTick=" << UpperTick << ",";
	sbuf << "LowerTick=" << LowerTick << ",";
	sbuf << "CurrencyID=" << CurrencyID << ",";
	sbuf << "Precision=" << Precision << ",";
	sbuf << "DeliveryMode=" << DeliveryMode << ",";
	sbuf << "DeliveryDays=" << DeliveryDays << ",";
	sbuf << "DeliveryYear=" << DeliveryYear << ",";
	sbuf << "DeliveryMonth=" << DeliveryMonth << ",";
	sbuf << "MaxMarketOrderVolume=" << MaxMarketOrderVolume << ",";
	sbuf << "MinMarketOrderVolume=" << MinMarketOrderVolume << ",";
	sbuf << "MaxLimitOrderVolume=" << MaxLimitOrderVolume << ",";
	sbuf << "MinLimitOrderVolume=" << MinLimitOrderVolume << ",";
	sbuf << "DepositCalculateMode=" << DepositCalculateMode << ",";
	sbuf << "MaxHoldVol=" << MaxHoldVol << ",";
	sbuf << "AddOneTime=" << AddOneTime << ",";
	sbuf << "CmbDirect=" << CmbDirect << ",";
	sbuf << "CoverMode=" << CoverMode << ",";
	sbuf << "CreateDate=" << CreateDate << ",";
	sbuf << "OpenDate=" << OpenDate << ",";
	sbuf << "ExpiryDate=" << ExpiryDate << ",";
	sbuf << "StartDelivDate=" << StartDelivDate << ",";
	sbuf << "EndDelivDate=" << EndDelivDate << ",";
	sbuf << "PositionType=" << PositionType << ",";
	sbuf << "PositionDateType=" << PositionDateType << ",";
	sbuf << "LongMarginRatio=" << LongMarginRatio << ",";
	sbuf << "ShortMarginRatio=" << ShortMarginRatio << ",";
	sbuf << "MaxMarginSideAlgorithm=" << MaxMarginSideAlgorithm << ",";

	sprintf(p, "%s", sbuf.str().c_str());
}

void COrderAction::init(void)
{
	memset(this, 0, sizeof(COrderAction));
}

int COrderAction::read(FILE *input)
{
	if (fread(this, 1, sizeof(COrderAction), input) != sizeof(COrderAction))
		return 0;
	else
		return 1;
}

int COrderAction::write(FILE *output) const
{
	if (fwrite(this, 1, sizeof(COrderAction), output) != sizeof(COrderAction))
		return 0;
	else
		return 1;
}

void COrderAction::dump(FILE *fp, int index) const
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
	fprintf(fp, "\tCOrderAction%s = {\n", index_buf);
	fprintf(fp, "\t\tOrderInnerID = %s    [ϵͳ�ڲ�����(�ַ���)]\n", boost::lexical_cast<std::string>(OrderInnerID).c_str());
	fprintf(fp, "\t\tInvestorID = %s    [Ͷ���߱��]\n", boost::lexical_cast<std::string>(InvestorID).c_str());
	fprintf(fp, "\t\tUserID = %s    [�û�����]\n", boost::lexical_cast<std::string>(UserID).c_str());
	fprintf(fp, "\t\tActionFlag = %s    [������־]\n", boost::lexical_cast<std::string>(ActionFlag).c_str());
	fprintf(fp, "\t\tPrice = %s    [ί�м۸�]\n", boost::lexical_cast<std::string>(Price).c_str());
	fprintf(fp, "\t\tVolume = %s    [ί������]\n", boost::lexical_cast<std::string>(Volume).c_str());
	fprintf(fp, "\t\tBrokerID = %s    [���ͻ�Ա����]\n", boost::lexical_cast<std::string>(BrokerID).c_str());
	fprintf(fp, "\t\tExchangeID = %s    [����������]\n", boost::lexical_cast<std::string>(ExchangeID).c_str());
	fprintf(fp, "\t\tOrderSysID = %s    [�������]\n", boost::lexical_cast<std::string>(OrderSysID).c_str());
	fprintf(fp, "\t\tRuleID = %s    [����ID��]\n", boost::lexical_cast<std::string>(RuleID).c_str());
	fprintf(fp, "\t\tOrderRef = %s    [��������]\n", boost::lexical_cast<std::string>(OrderRef).c_str());
	fprintf(fp, "\t\tInstrumentID = %s    [��Լ����]\n", boost::lexical_cast<std::string>(InstrumentID).c_str());
	fprintf(fp, "\t\tOrderActionStatus = %s    [��������״̬]\n", boost::lexical_cast<std::string>(OrderActionStatus).c_str());
	fprintf(fp, "\t\tStatusMsg = %s    [״̬��Ϣ]\n", boost::lexical_cast<std::string>(StatusMsg).c_str());
	fprintf(fp, "\t\tActionTime = %s    [��������]\n", boost::lexical_cast<std::string>(ActionTime).c_str());
	fprintf(fp, "\t\tActionDate = %s    [����ʱ��]\n", boost::lexical_cast<std::string>(ActionDate).c_str());
	fprintf(fp, "\t\tTraderID = %s    [�����˺�]\n", boost::lexical_cast<std::string>(TraderID).c_str());
	fprintf(fp, "\t\tTerminalID = %s    [�����ն˱���]\n", boost::lexical_cast<std::string>(TerminalID).c_str());
	fprintf(fp, "\t}\n");
}

void COrderAction::dumpDiff(FILE *fp, const COrderAction *pOriginal) const
{
	if (fp == nullptr)
	{
		fp = stdout;
	}
	fprintf(fp, "\tCOrderAction = {\n");
	if (compare(OrderInnerID, pOriginal->OrderInnerID) != 0)
	{
		fprintf(fp, "\t\tOrderInnerID = %s -> %s    [ϵͳ�ڲ�����(�ַ���)]\n", boost::lexical_cast<std::string>(pOriginal->OrderInnerID).c_str(), boost::lexical_cast<std::string>(OrderInnerID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tOrderInnerID = %s    [ϵͳ�ڲ�����(�ַ���)]\n", boost::lexical_cast<std::string>(OrderInnerID).c_str());
	}
	if (compare(InvestorID, pOriginal->InvestorID) != 0)
	{
		fprintf(fp, "\t\tInvestorID = %s -> %s    [Ͷ���߱��]\n", boost::lexical_cast<std::string>(pOriginal->InvestorID).c_str(), boost::lexical_cast<std::string>(InvestorID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tInvestorID = %s    [Ͷ���߱��]\n", boost::lexical_cast<std::string>(InvestorID).c_str());
	}
	if (compare(UserID, pOriginal->UserID) != 0)
	{
		fprintf(fp, "\t\tUserID = %s -> %s    [�û�����]\n", boost::lexical_cast<std::string>(pOriginal->UserID).c_str(), boost::lexical_cast<std::string>(UserID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tUserID = %s    [�û�����]\n", boost::lexical_cast<std::string>(UserID).c_str());
	}
	if (compare(ActionFlag, pOriginal->ActionFlag) != 0)
	{
		fprintf(fp, "\t\tActionFlag = %s -> %s    [������־]\n", boost::lexical_cast<std::string>(pOriginal->ActionFlag).c_str(), boost::lexical_cast<std::string>(ActionFlag).c_str());
	}
	else
	{
		fprintf(fp, "\t\tActionFlag = %s    [������־]\n", boost::lexical_cast<std::string>(ActionFlag).c_str());
	}
	if (compare(Price, pOriginal->Price) != 0)
	{
		fprintf(fp, "\t\tPrice = %s -> %s    [ί�м۸�]\n", boost::lexical_cast<std::string>(pOriginal->Price).c_str(), boost::lexical_cast<std::string>(Price).c_str());
	}
	else
	{
		fprintf(fp, "\t\tPrice = %s    [ί�м۸�]\n", boost::lexical_cast<std::string>(Price).c_str());
	}
	if (compare(Volume, pOriginal->Volume) != 0)
	{
		fprintf(fp, "\t\tVolume = %s -> %s    [ί������]\n", boost::lexical_cast<std::string>(pOriginal->Volume).c_str(), boost::lexical_cast<std::string>(Volume).c_str());
	}
	else
	{
		fprintf(fp, "\t\tVolume = %s    [ί������]\n", boost::lexical_cast<std::string>(Volume).c_str());
	}
	if (compare(BrokerID, pOriginal->BrokerID) != 0)
	{
		fprintf(fp, "\t\tBrokerID = %s -> %s    [���ͻ�Ա����]\n", boost::lexical_cast<std::string>(pOriginal->BrokerID).c_str(), boost::lexical_cast<std::string>(BrokerID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBrokerID = %s    [���ͻ�Ա����]\n", boost::lexical_cast<std::string>(BrokerID).c_str());
	}
	if (compare(ExchangeID, pOriginal->ExchangeID) != 0)
	{
		fprintf(fp, "\t\tExchangeID = %s -> %s    [����������]\n", boost::lexical_cast<std::string>(pOriginal->ExchangeID).c_str(), boost::lexical_cast<std::string>(ExchangeID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tExchangeID = %s    [����������]\n", boost::lexical_cast<std::string>(ExchangeID).c_str());
	}
	if (compare(OrderSysID, pOriginal->OrderSysID) != 0)
	{
		fprintf(fp, "\t\tOrderSysID = %s -> %s    [�������]\n", boost::lexical_cast<std::string>(pOriginal->OrderSysID).c_str(), boost::lexical_cast<std::string>(OrderSysID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tOrderSysID = %s    [�������]\n", boost::lexical_cast<std::string>(OrderSysID).c_str());
	}
	if (compare(RuleID, pOriginal->RuleID) != 0)
	{
		fprintf(fp, "\t\tRuleID = %s -> %s    [����ID��]\n", boost::lexical_cast<std::string>(pOriginal->RuleID).c_str(), boost::lexical_cast<std::string>(RuleID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tRuleID = %s    [����ID��]\n", boost::lexical_cast<std::string>(RuleID).c_str());
	}
	if (compare(OrderRef, pOriginal->OrderRef) != 0)
	{
		fprintf(fp, "\t\tOrderRef = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->OrderRef).c_str(), boost::lexical_cast<std::string>(OrderRef).c_str());
	}
	else
	{
		fprintf(fp, "\t\tOrderRef = %s    [��������]\n", boost::lexical_cast<std::string>(OrderRef).c_str());
	}
	if (compare(InstrumentID, pOriginal->InstrumentID) != 0)
	{
		fprintf(fp, "\t\tInstrumentID = %s -> %s    [��Լ����]\n", boost::lexical_cast<std::string>(pOriginal->InstrumentID).c_str(), boost::lexical_cast<std::string>(InstrumentID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tInstrumentID = %s    [��Լ����]\n", boost::lexical_cast<std::string>(InstrumentID).c_str());
	}
	if (compare(OrderActionStatus, pOriginal->OrderActionStatus) != 0)
	{
		fprintf(fp, "\t\tOrderActionStatus = %s -> %s    [��������״̬]\n", boost::lexical_cast<std::string>(pOriginal->OrderActionStatus).c_str(), boost::lexical_cast<std::string>(OrderActionStatus).c_str());
	}
	else
	{
		fprintf(fp, "\t\tOrderActionStatus = %s    [��������״̬]\n", boost::lexical_cast<std::string>(OrderActionStatus).c_str());
	}
	if (compare(StatusMsg, pOriginal->StatusMsg) != 0)
	{
		fprintf(fp, "\t\tStatusMsg = %s -> %s    [״̬��Ϣ]\n", boost::lexical_cast<std::string>(pOriginal->StatusMsg).c_str(), boost::lexical_cast<std::string>(StatusMsg).c_str());
	}
	else
	{
		fprintf(fp, "\t\tStatusMsg = %s    [״̬��Ϣ]\n", boost::lexical_cast<std::string>(StatusMsg).c_str());
	}
	if (compare(ActionTime, pOriginal->ActionTime) != 0)
	{
		fprintf(fp, "\t\tActionTime = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->ActionTime).c_str(), boost::lexical_cast<std::string>(ActionTime).c_str());
	}
	else
	{
		fprintf(fp, "\t\tActionTime = %s    [��������]\n", boost::lexical_cast<std::string>(ActionTime).c_str());
	}
	if (compare(ActionDate, pOriginal->ActionDate) != 0)
	{
		fprintf(fp, "\t\tActionDate = %s -> %s    [����ʱ��]\n", boost::lexical_cast<std::string>(pOriginal->ActionDate).c_str(), boost::lexical_cast<std::string>(ActionDate).c_str());
	}
	else
	{
		fprintf(fp, "\t\tActionDate = %s    [����ʱ��]\n", boost::lexical_cast<std::string>(ActionDate).c_str());
	}
	if (compare(TraderID, pOriginal->TraderID) != 0)
	{
		fprintf(fp, "\t\tTraderID = %s -> %s    [�����˺�]\n", boost::lexical_cast<std::string>(pOriginal->TraderID).c_str(), boost::lexical_cast<std::string>(TraderID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTraderID = %s    [�����˺�]\n", boost::lexical_cast<std::string>(TraderID).c_str());
	}
	if (compare(TerminalID, pOriginal->TerminalID) != 0)
	{
		fprintf(fp, "\t\tTerminalID = %s -> %s    [�����ն˱���]\n", boost::lexical_cast<std::string>(pOriginal->TerminalID).c_str(), boost::lexical_cast<std::string>(TerminalID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTerminalID = %s    [�����ն˱���]\n", boost::lexical_cast<std::string>(TerminalID).c_str());
	}
	fprintf(fp, "\t}\n");
}

void COrderAction::dumpInLine(FILE *fp) const
{
	if (fp == nullptr)
	{
		fp = stdout;
	}
	std::stringstream sbuf;

	sbuf << ",OrderInnerID," << OrderInnerID;
	sbuf << ",InvestorID," << InvestorID;
	sbuf << ",UserID," << UserID;
	sbuf << ",ActionFlag," << ActionFlag;
	sbuf << ",Price," << Price;
	sbuf << ",Volume," << Volume;
	sbuf << ",BrokerID," << BrokerID;
	sbuf << ",ExchangeID," << ExchangeID;
	sbuf << ",OrderSysID," << OrderSysID;
	sbuf << ",RuleID," << RuleID;
	sbuf << ",OrderRef," << OrderRef;
	sbuf << ",InstrumentID," << InstrumentID;
	sbuf << ",OrderActionStatus," << OrderActionStatus;
	sbuf << ",StatusMsg," << StatusMsg;
	sbuf << ",ActionTime," << ActionTime;
	sbuf << ",ActionDate," << ActionDate;
	sbuf << ",TraderID," << TraderID;
	sbuf << ",TerminalID," << TerminalID;
	fprintf(fp, "%s", sbuf.str().c_str());
}

void COrderAction::dumpString(char *target) const
{
	char *p = target;
	std::stringstream sbuf;

	sbuf << "OrderInnerID=" << OrderInnerID << ",";
	sbuf << "InvestorID=" << InvestorID << ",";
	sbuf << "UserID=" << UserID << ",";
	sbuf << "ActionFlag=" << ActionFlag << ",";
	sbuf << "Price=" << Price << ",";
	sbuf << "Volume=" << Volume << ",";
	sbuf << "BrokerID=" << BrokerID << ",";
	sbuf << "ExchangeID=" << ExchangeID << ",";
	sbuf << "OrderSysID=" << OrderSysID << ",";
	sbuf << "RuleID=" << RuleID << ",";
	sbuf << "OrderRef=" << OrderRef << ",";
	sbuf << "InstrumentID=" << InstrumentID << ",";
	sbuf << "OrderActionStatus=" << OrderActionStatus << ",";
	sbuf << "StatusMsg=" << StatusMsg << ",";
	sbuf << "ActionTime=" << ActionTime << ",";
	sbuf << "ActionDate=" << ActionDate << ",";
	sbuf << "TraderID=" << TraderID << ",";
	sbuf << "TerminalID=" << TerminalID << ",";

	sprintf(p, "%s", sbuf.str().c_str());
}

void CExchOrderAction::init(void)
{
	memset(this, 0, sizeof(CExchOrderAction));
}

int CExchOrderAction::read(FILE *input)
{
	if (fread(this, 1, sizeof(CExchOrderAction), input) != sizeof(CExchOrderAction))
		return 0;
	else
		return 1;
}

int CExchOrderAction::write(FILE *output) const
{
	if (fwrite(this, 1, sizeof(CExchOrderAction), output) != sizeof(CExchOrderAction))
		return 0;
	else
		return 1;
}

void CExchOrderAction::dump(FILE *fp, int index) const
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

	fprintf(fp, "\tCExchOrderAction%s = {\n", index_buf);
	fprintf(fp, "\t\tOrderInnerID = %s    [ϵͳ�ڲ�����(�ַ���)]\n", boost::lexical_cast<std::string>(OrderInnerID).c_str());
	fprintf(fp, "\t\tInvestorID = %s    [Ͷ���߱��]\n", boost::lexical_cast<std::string>(InvestorID).c_str());
	fprintf(fp, "\t\tUserID = %s    [�û�����]\n", boost::lexical_cast<std::string>(UserID).c_str());
	fprintf(fp, "\t\tActionFlag = %s    [������־]\n", boost::lexical_cast<std::string>(ActionFlag).c_str());
	fprintf(fp, "\t\tPrice = %s    [ί�м۸�]\n", boost::lexical_cast<std::string>(Price).c_str());
	fprintf(fp, "\t\tVolume = %s    [ί������]\n", boost::lexical_cast<std::string>(Volume).c_str());
	fprintf(fp, "\t\tBrokerID = %s    [���ͻ�Ա����]\n", boost::lexical_cast<std::string>(BrokerID).c_str());
	fprintf(fp, "\t\tExchangeID = %s    [����������]\n", boost::lexical_cast<std::string>(ExchangeID).c_str());
	fprintf(fp, "\t\tOrderSysID = %s    [�������]\n", boost::lexical_cast<std::string>(OrderSysID).c_str());
	fprintf(fp, "\t\tRuleID = %s    [����ID��]\n", boost::lexical_cast<std::string>(RuleID).c_str());
	fprintf(fp, "\t\tOrderRef = %s    [��������]\n", boost::lexical_cast<std::string>(OrderRef).c_str());
	fprintf(fp, "\t\tInstrumentID = %s    [��Լ����]\n", boost::lexical_cast<std::string>(InstrumentID).c_str());
	fprintf(fp, "\t\tOrderActionStatus = %s    [��������״̬]\n", boost::lexical_cast<std::string>(OrderActionStatus).c_str());
	fprintf(fp, "\t\tActionTime = %s    [��������]\n", boost::lexical_cast<std::string>(ActionTime).c_str());
	fprintf(fp, "\t\tActionDate = %s    [����ʱ��]\n", boost::lexical_cast<std::string>(ActionDate).c_str());
	fprintf(fp, "\t\tStatusMsg = %s    [״̬��Ϣ]\n", boost::lexical_cast<std::string>(StatusMsg).c_str());
	fprintf(fp, "\t\tTraderID = %s    [�����˺�]\n", boost::lexical_cast<std::string>(TraderID).c_str());
	fprintf(fp, "\t\tTerminalID = %s    [�����ն˱���]\n", boost::lexical_cast<std::string>(TerminalID).c_str());
	fprintf(fp, "\t}\n");
}

void CExchOrderAction::dumpDiff(FILE *fp, const CExchOrderAction *pOriginal) const
{
	if (fp == nullptr)
	{
		fp = stdout;
	}
	fprintf(fp, "\tCExchOrderAction = {\n");
	if (compare(OrderInnerID, pOriginal->OrderInnerID) != 0)
	{
		fprintf(fp, "\t\tOrderInnerID = %s -> %s    [ϵͳ�ڲ�����(�ַ���)]\n", boost::lexical_cast<std::string>(pOriginal->OrderInnerID).c_str(), boost::lexical_cast<std::string>(OrderInnerID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tOrderInnerID = %s    [ϵͳ�ڲ�����(�ַ���)]\n", boost::lexical_cast<std::string>(OrderInnerID).c_str());
	}
	if (compare(InvestorID, pOriginal->InvestorID) != 0)
	{
		fprintf(fp, "\t\tInvestorID = %s -> %s    [Ͷ���߱��]\n", boost::lexical_cast<std::string>(pOriginal->InvestorID).c_str(), boost::lexical_cast<std::string>(InvestorID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tInvestorID = %s    [Ͷ���߱��]\n", boost::lexical_cast<std::string>(InvestorID).c_str());
	}
	if (compare(UserID, pOriginal->UserID) != 0)
	{
		fprintf(fp, "\t\tUserID = %s -> %s    [�û�����]\n", boost::lexical_cast<std::string>(pOriginal->UserID).c_str(), boost::lexical_cast<std::string>(UserID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tUserID = %s    [�û�����]\n", boost::lexical_cast<std::string>(UserID).c_str());
	}
	if (compare(ActionFlag, pOriginal->ActionFlag) != 0)
	{
		fprintf(fp, "\t\tActionFlag = %s -> %s    [������־]\n", boost::lexical_cast<std::string>(pOriginal->ActionFlag).c_str(), boost::lexical_cast<std::string>(ActionFlag).c_str());
	}
	else
	{
		fprintf(fp, "\t\tActionFlag = %s    [������־]\n", boost::lexical_cast<std::string>(ActionFlag).c_str());
	}
	if (compare(Price, pOriginal->Price) != 0)
	{
		fprintf(fp, "\t\tPrice = %s -> %s    [ί�м۸�]\n", boost::lexical_cast<std::string>(pOriginal->Price).c_str(), boost::lexical_cast<std::string>(Price).c_str());
	}
	else
	{
		fprintf(fp, "\t\tPrice = %s    [ί�м۸�]\n", boost::lexical_cast<std::string>(Price).c_str());
	}
	if (compare(Volume, pOriginal->Volume) != 0)
	{
		fprintf(fp, "\t\tVolume = %s -> %s    [ί������]\n", boost::lexical_cast<std::string>(pOriginal->Volume).c_str(), boost::lexical_cast<std::string>(Volume).c_str());
	}
	else
	{
		fprintf(fp, "\t\tVolume = %s    [ί������]\n", boost::lexical_cast<std::string>(Volume).c_str());
	}
	if (compare(BrokerID, pOriginal->BrokerID) != 0)
	{
		fprintf(fp, "\t\tBrokerID = %s -> %s    [���ͻ�Ա����]\n", boost::lexical_cast<std::string>(pOriginal->BrokerID).c_str(), boost::lexical_cast<std::string>(BrokerID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBrokerID = %s    [���ͻ�Ա����]\n", boost::lexical_cast<std::string>(BrokerID).c_str());
	}
	if (compare(ExchangeID, pOriginal->ExchangeID) != 0)
	{
		fprintf(fp, "\t\tExchangeID = %s -> %s    [����������]\n", boost::lexical_cast<std::string>(pOriginal->ExchangeID).c_str(), boost::lexical_cast<std::string>(ExchangeID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tExchangeID = %s    [����������]\n", boost::lexical_cast<std::string>(ExchangeID).c_str());
	}
	if (compare(OrderSysID, pOriginal->OrderSysID) != 0)
	{
		fprintf(fp, "\t\tOrderSysID = %s -> %s    [�������]\n", boost::lexical_cast<std::string>(pOriginal->OrderSysID).c_str(), boost::lexical_cast<std::string>(OrderSysID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tOrderSysID = %s    [�������]\n", boost::lexical_cast<std::string>(OrderSysID).c_str());
	}
	if (compare(RuleID, pOriginal->RuleID) != 0)
	{
		fprintf(fp, "\t\tRuleID = %s -> %s    [����ID��]\n", boost::lexical_cast<std::string>(pOriginal->RuleID).c_str(), boost::lexical_cast<std::string>(RuleID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tRuleID = %s    [����ID��]\n", boost::lexical_cast<std::string>(RuleID).c_str());
	}
	if (compare(OrderRef, pOriginal->OrderRef) != 0)
	{
		fprintf(fp, "\t\tOrderRef = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->OrderRef).c_str(), boost::lexical_cast<std::string>(OrderRef).c_str());
	}
	else
	{
		fprintf(fp, "\t\tOrderRef = %s    [��������]\n", boost::lexical_cast<std::string>(OrderRef).c_str());
	}
	if (compare(InstrumentID, pOriginal->InstrumentID) != 0)
	{
		fprintf(fp, "\t\tInstrumentID = %s -> %s    [��Լ����]\n", boost::lexical_cast<std::string>(pOriginal->InstrumentID).c_str(), boost::lexical_cast<std::string>(InstrumentID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tInstrumentID = %s    [��Լ����]\n", boost::lexical_cast<std::string>(InstrumentID).c_str());
	}
	if (compare(OrderActionStatus, pOriginal->OrderActionStatus) != 0)
	{
		fprintf(fp, "\t\tOrderActionStatus = %s -> %s    [��������״̬]\n", boost::lexical_cast<std::string>(pOriginal->OrderActionStatus).c_str(), boost::lexical_cast<std::string>(OrderActionStatus).c_str());
	}
	else
	{
		fprintf(fp, "\t\tOrderActionStatus = %s    [��������״̬]\n", boost::lexical_cast<std::string>(OrderActionStatus).c_str());
	}
	if (compare(ActionTime, pOriginal->ActionTime) != 0)
	{
		fprintf(fp, "\t\tActionTime = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->ActionTime).c_str(), boost::lexical_cast<std::string>(ActionTime).c_str());
	}
	else
	{
		fprintf(fp, "\t\tActionTime = %s    [��������]\n", boost::lexical_cast<std::string>(ActionTime).c_str());
	}
	if (compare(ActionDate, pOriginal->ActionDate) != 0)
	{
		fprintf(fp, "\t\tActionDate = %s -> %s    [����ʱ��]\n", boost::lexical_cast<std::string>(pOriginal->ActionDate).c_str(), boost::lexical_cast<std::string>(ActionDate).c_str());
	}
	else
	{
		fprintf(fp, "\t\tActionDate = %s    [����ʱ��]\n", boost::lexical_cast<std::string>(ActionDate).c_str());
	}
	if (compare(StatusMsg, pOriginal->StatusMsg) != 0)
	{
		fprintf(fp, "\t\tStatusMsg = %s -> %s    [״̬��Ϣ]\n", boost::lexical_cast<std::string>(pOriginal->StatusMsg).c_str(), boost::lexical_cast<std::string>(StatusMsg).c_str());
	}
	else
	{
		fprintf(fp, "\t\tStatusMsg = %s    [״̬��Ϣ]\n", boost::lexical_cast<std::string>(StatusMsg).c_str());
	}
	if (compare(TraderID, pOriginal->TraderID) != 0)
	{
		fprintf(fp, "\t\tTraderID = %s -> %s    [�����˺�]\n", boost::lexical_cast<std::string>(pOriginal->TraderID).c_str(), boost::lexical_cast<std::string>(TraderID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTraderID = %s    [�����˺�]\n", boost::lexical_cast<std::string>(TraderID).c_str());
	}
	if (compare(TerminalID, pOriginal->TerminalID) != 0)
	{
		fprintf(fp, "\t\tTerminalID = %s -> %s    [�����ն˱���]\n", boost::lexical_cast<std::string>(pOriginal->TerminalID).c_str(), boost::lexical_cast<std::string>(TerminalID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTerminalID = %s    [�����ն˱���]\n", boost::lexical_cast<std::string>(TerminalID).c_str());
	}
	fprintf(fp, "\t}\n");
}

void CExchOrderAction::dumpInLine(FILE *fp) const
{
	if (fp == nullptr)
	{
		fp = stdout;
	}
	std::stringstream sbuf;

	sbuf << ",OrderInnerID," << OrderInnerID;
	sbuf << ",InvestorID," << InvestorID;
	sbuf << ",UserID," << UserID;
	sbuf << ",ActionFlag," << ActionFlag;
	sbuf << ",Price," << Price;
	sbuf << ",Volume," << Volume;
	sbuf << ",BrokerID," << BrokerID;
	sbuf << ",ExchangeID," << ExchangeID;
	sbuf << ",OrderSysID," << OrderSysID;
	sbuf << ",RuleID," << RuleID;
	sbuf << ",OrderRef," << OrderRef;
	sbuf << ",InstrumentID," << InstrumentID;
	sbuf << ",OrderActionStatus," << OrderActionStatus;
	sbuf << ",ActionTime," << ActionTime;
	sbuf << ",ActionDate," << ActionDate;
	sbuf << ",StatusMsg," << StatusMsg;
	sbuf << ",TraderID," << TraderID;
	sbuf << ",TerminalID," << TerminalID;
	fprintf(fp, "%s", sbuf.str().c_str());
}

void CExchOrderAction::dumpString(char *target) const
{
	char *p = target;
	std::stringstream sbuf;

	sbuf << "OrderInnerID=" << OrderInnerID << ",";
	sbuf << "InvestorID=" << InvestorID << ",";
	sbuf << "UserID=" << UserID << ",";
	sbuf << "ActionFlag=" << ActionFlag << ",";
	sbuf << "Price=" << Price << ",";
	sbuf << "Volume=" << Volume << ",";
	sbuf << "BrokerID=" << BrokerID << ",";
	sbuf << "ExchangeID=" << ExchangeID << ",";
	sbuf << "OrderSysID=" << OrderSysID << ",";
	sbuf << "RuleID=" << RuleID << ",";
	sbuf << "OrderRef=" << OrderRef << ",";
	sbuf << "InstrumentID=" << InstrumentID << ",";
	sbuf << "OrderActionStatus=" << OrderActionStatus << ",";
	sbuf << "ActionTime=" << ActionTime << ",";
	sbuf << "ActionDate=" << ActionDate << ",";
	sbuf << "StatusMsg=" << StatusMsg << ",";
	sbuf << "TraderID=" << TraderID << ",";
	sbuf << "TerminalID=" << TerminalID << ",";

	sprintf(p, "%s", sbuf.str().c_str());
}

void COrder::init(void)
{
	memset(this, 0, sizeof(COrder));
}

int COrder::read(FILE *input)
{
	if (fread(this, 1, sizeof(COrder), input) != sizeof(COrder))
		return 0;
	else
		return 1;
}

int COrder::write(FILE *output) const
{
	if (fwrite(this, 1, sizeof(COrder), output) != sizeof(COrder))
		return 0;
	else
		return 1;
}

void COrder::dump(FILE *fp, int index) const
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

	fprintf(fp, "\tCOrder%s = {\n", index_buf);
	fprintf(fp, "\t\tUserID = %s    [�û�����]\n", boost::lexical_cast<std::string>(UserID).c_str());
	fprintf(fp, "\t\tExchangeID = %s    [����������]\n", boost::lexical_cast<std::string>(ExchangeID).c_str());
	fprintf(fp, "\t\tCommodityID = %s    [��Ʒ����]\n", boost::lexical_cast<std::string>(CommodityID).c_str());
	fprintf(fp, "\t\tInstrumentID = %s    [��Լ����]\n", boost::lexical_cast<std::string>(InstrumentID).c_str());
	fprintf(fp, "\t\tOrderPriceType = %s    [�����۸�����]\n", boost::lexical_cast<std::string>(OrderPriceType).c_str());
	fprintf(fp, "\t\tOrderMode = %s    [ί��ģʽ]\n", boost::lexical_cast<std::string>(OrderMode).c_str());
	fprintf(fp, "\t\tDirection = %s    [��������]\n", boost::lexical_cast<std::string>(Direction).c_str());
	fprintf(fp, "\t\tOffsetFlag = %s    [����ƽ��]\n", boost::lexical_cast<std::string>(OffsetFlag).c_str());
	fprintf(fp, "\t\tHedgeFlag = %s    [Ͷ����ֵ]\n", boost::lexical_cast<std::string>(HedgeFlag).c_str());
	fprintf(fp, "\t\tPrice = %s    [ί�м۸�]\n", boost::lexical_cast<std::string>(Price).c_str());
	fprintf(fp, "\t\tVolume = %s    [ί������]\n", boost::lexical_cast<std::string>(Volume).c_str());
	fprintf(fp, "\t\tOrderInfo = %s    [�ͻ�������Ϣ]\n", boost::lexical_cast<std::string>(OrderInfo).c_str());
	fprintf(fp, "\t\tBrokerID = %s    [���ͻ�Ա����]\n", boost::lexical_cast<std::string>(BrokerID).c_str());
	fprintf(fp, "\t\tInvestorID = %s    [Ͷ���߱��]\n", boost::lexical_cast<std::string>(InvestorID).c_str());
	fprintf(fp, "\t\tTimeCondition = %s    [��Ч������]\n", boost::lexical_cast<std::string>(TimeCondition).c_str());
	fprintf(fp, "\t\tTradingDay = %s    [������]\n", boost::lexical_cast<std::string>(TradingDay).c_str());
	fprintf(fp, "\t\tOrderInnerID = %s    [ϵͳ�ڲ�����(�ַ���)]\n", boost::lexical_cast<std::string>(OrderInnerID).c_str());
	fprintf(fp, "\t\tOrderSysID = %s    [�������]\n", boost::lexical_cast<std::string>(OrderSysID).c_str());
	fprintf(fp, "\t\tTradePrice = %s    [�ɽ��۸�]\n", boost::lexical_cast<std::string>(TradePrice).c_str());
	fprintf(fp, "\t\tVolumeTraded = %s    [��ɽ�����]\n", boost::lexical_cast<std::string>(VolumeTraded).c_str());
	fprintf(fp, "\t\tVolumeTotal = %s    [ʣ������]\n", boost::lexical_cast<std::string>(VolumeTotal).c_str());
	fprintf(fp, "\t\tExchangeInstID = %s    [��Լ�ڽ������Ĵ���]\n", boost::lexical_cast<std::string>(ExchangeInstID).c_str());
	fprintf(fp, "\t\tOrderSubmitStatus = %s    [�����ύ״̬]\n", boost::lexical_cast<std::string>(OrderSubmitStatus).c_str());
	fprintf(fp, "\t\tOrderState = %s    [ί��״̬]\n", boost::lexical_cast<std::string>(OrderState).c_str());
	fprintf(fp, "\t\tOrderStatus = %s    [����״̬]\n", boost::lexical_cast<std::string>(OrderStatus).c_str());
	fprintf(fp, "\t\tInsertDate = %s    [��������]\n", boost::lexical_cast<std::string>(InsertDate).c_str());
	fprintf(fp, "\t\tInsertTime = %s    [ί��ʱ��]\n", boost::lexical_cast<std::string>(InsertTime).c_str());
	fprintf(fp, "\t\tUpdateDate = %s    [��������]\n", boost::lexical_cast<std::string>(UpdateDate).c_str());
	fprintf(fp, "\t\tUpdateTime = %s    [����ʱ��]\n", boost::lexical_cast<std::string>(UpdateTime).c_str());
	fprintf(fp, "\t\tCancelTime = %s    [����ʱ��]\n", boost::lexical_cast<std::string>(CancelTime).c_str());
	fprintf(fp, "\t\tErrorCode = %s    [���һ�β���������Ϣ��]\n", boost::lexical_cast<std::string>(ErrorCode).c_str());
	fprintf(fp, "\t\tStatusMsg = %s    [״̬��Ϣ]\n", boost::lexical_cast<std::string>(StatusMsg).c_str());
	fprintf(fp, "\t\tSettlementID = %s    [������]\n", boost::lexical_cast<std::string>(SettlementID).c_str());
	fprintf(fp, "\t\tOrderSource = %s    [������Դ]\n", boost::lexical_cast<std::string>(OrderSource).c_str());
	fprintf(fp, "\t\tBrokerOrderSeq = %s    [���͹�˾�������]\n", boost::lexical_cast<std::string>(BrokerOrderSeq).c_str());
	fprintf(fp, "\t\tOrderRef = %s    [��������]\n", boost::lexical_cast<std::string>(OrderRef).c_str());
	fprintf(fp, "\t\tFrontID = %s    [ǰ�ñ��]\n", boost::lexical_cast<std::string>(FrontID).c_str());
	fprintf(fp, "\t\tSessionID = %s    [�Ự���]\n", boost::lexical_cast<std::string>(SessionID).c_str());
	fprintf(fp, "\t}\n");
}

void COrder::dumpDiff(FILE *fp, const COrder *pOriginal) const
{
	if (fp == nullptr)
	{
		fp = stdout;
	}
	fprintf(fp, "\tCOrder = {\n");
	if (compare(UserID, pOriginal->UserID) != 0)
	{
		fprintf(fp, "\t\tUserID = %s -> %s    [�û�����]\n", boost::lexical_cast<std::string>(pOriginal->UserID).c_str(), boost::lexical_cast<std::string>(UserID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tUserID = %s    [�û�����]\n", boost::lexical_cast<std::string>(UserID).c_str());
	}
	if (compare(ExchangeID, pOriginal->ExchangeID) != 0)
	{
		fprintf(fp, "\t\tExchangeID = %s -> %s    [����������]\n", boost::lexical_cast<std::string>(pOriginal->ExchangeID).c_str(), boost::lexical_cast<std::string>(ExchangeID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tExchangeID = %s    [����������]\n", boost::lexical_cast<std::string>(ExchangeID).c_str());
	}
	if (compare(CommodityID, pOriginal->CommodityID) != 0)
	{
		fprintf(fp, "\t\tCommodityID = %s -> %s    [��Ʒ����]\n", boost::lexical_cast<std::string>(pOriginal->CommodityID).c_str(), boost::lexical_cast<std::string>(CommodityID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tCommodityID = %s    [��Ʒ����]\n", boost::lexical_cast<std::string>(CommodityID).c_str());
	}
	if (compare(InstrumentID, pOriginal->InstrumentID) != 0)
	{
		fprintf(fp, "\t\tInstrumentID = %s -> %s    [��Լ����]\n", boost::lexical_cast<std::string>(pOriginal->InstrumentID).c_str(), boost::lexical_cast<std::string>(InstrumentID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tInstrumentID = %s    [��Լ����]\n", boost::lexical_cast<std::string>(InstrumentID).c_str());
	}
	if (compare(OrderPriceType, pOriginal->OrderPriceType) != 0)
	{
		fprintf(fp, "\t\tOrderPriceType = %s -> %s    [�����۸�����]\n", boost::lexical_cast<std::string>(pOriginal->OrderPriceType).c_str(), boost::lexical_cast<std::string>(OrderPriceType).c_str());
	}
	else
	{
		fprintf(fp, "\t\tOrderPriceType = %s    [�����۸�����]\n", boost::lexical_cast<std::string>(OrderPriceType).c_str());
	}
	if (compare(OrderMode, pOriginal->OrderMode) != 0)
	{
		fprintf(fp, "\t\tOrderMode = %s -> %s    [ί��ģʽ]\n", boost::lexical_cast<std::string>(pOriginal->OrderMode).c_str(), boost::lexical_cast<std::string>(OrderMode).c_str());
	}
	else
	{
		fprintf(fp, "\t\tOrderMode = %s    [ί��ģʽ]\n", boost::lexical_cast<std::string>(OrderMode).c_str());
	}
	if (compare(Direction, pOriginal->Direction) != 0)
	{
		fprintf(fp, "\t\tDirection = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->Direction).c_str(), boost::lexical_cast<std::string>(Direction).c_str());
	}
	else
	{
		fprintf(fp, "\t\tDirection = %s    [��������]\n", boost::lexical_cast<std::string>(Direction).c_str());
	}
	if (compare(OffsetFlag, pOriginal->OffsetFlag) != 0)
	{
		fprintf(fp, "\t\tOffsetFlag = %s -> %s    [����ƽ��]\n", boost::lexical_cast<std::string>(pOriginal->OffsetFlag).c_str(), boost::lexical_cast<std::string>(OffsetFlag).c_str());
	}
	else
	{
		fprintf(fp, "\t\tOffsetFlag = %s    [����ƽ��]\n", boost::lexical_cast<std::string>(OffsetFlag).c_str());
	}
	if (compare(HedgeFlag, pOriginal->HedgeFlag) != 0)
	{
		fprintf(fp, "\t\tHedgeFlag = %s -> %s    [Ͷ����ֵ]\n", boost::lexical_cast<std::string>(pOriginal->HedgeFlag).c_str(), boost::lexical_cast<std::string>(HedgeFlag).c_str());
	}
	else
	{
		fprintf(fp, "\t\tHedgeFlag = %s    [Ͷ����ֵ]\n", boost::lexical_cast<std::string>(HedgeFlag).c_str());
	}
	if (compare(Price, pOriginal->Price) != 0)
	{
		fprintf(fp, "\t\tPrice = %s -> %s    [ί�м۸�]\n", boost::lexical_cast<std::string>(pOriginal->Price).c_str(), boost::lexical_cast<std::string>(Price).c_str());
	}
	else
	{
		fprintf(fp, "\t\tPrice = %s    [ί�м۸�]\n", boost::lexical_cast<std::string>(Price).c_str());
	}
	if (compare(Volume, pOriginal->Volume) != 0)
	{
		fprintf(fp, "\t\tVolume = %s -> %s    [ί������]\n", boost::lexical_cast<std::string>(pOriginal->Volume).c_str(), boost::lexical_cast<std::string>(Volume).c_str());
	}
	else
	{
		fprintf(fp, "\t\tVolume = %s    [ί������]\n", boost::lexical_cast<std::string>(Volume).c_str());
	}
	if (compare(OrderInfo, pOriginal->OrderInfo) != 0)
	{
		fprintf(fp, "\t\tOrderInfo = %s -> %s    [�ͻ�������Ϣ]\n", boost::lexical_cast<std::string>(pOriginal->OrderInfo).c_str(), boost::lexical_cast<std::string>(OrderInfo).c_str());
	}
	else
	{
		fprintf(fp, "\t\tOrderInfo = %s    [�ͻ�������Ϣ]\n", boost::lexical_cast<std::string>(OrderInfo).c_str());
	}
	if (compare(BrokerID, pOriginal->BrokerID) != 0)
	{
		fprintf(fp, "\t\tBrokerID = %s -> %s    [���ͻ�Ա����]\n", boost::lexical_cast<std::string>(pOriginal->BrokerID).c_str(), boost::lexical_cast<std::string>(BrokerID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBrokerID = %s    [���ͻ�Ա����]\n", boost::lexical_cast<std::string>(BrokerID).c_str());
	}
	if (compare(InvestorID, pOriginal->InvestorID) != 0)
	{
		fprintf(fp, "\t\tInvestorID = %s -> %s    [Ͷ���߱��]\n", boost::lexical_cast<std::string>(pOriginal->InvestorID).c_str(), boost::lexical_cast<std::string>(InvestorID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tInvestorID = %s    [Ͷ���߱��]\n", boost::lexical_cast<std::string>(InvestorID).c_str());
	}
	if (compare(TimeCondition, pOriginal->TimeCondition) != 0)
	{
		fprintf(fp, "\t\tTimeCondition = %s -> %s    [��Ч������]\n", boost::lexical_cast<std::string>(pOriginal->TimeCondition).c_str(), boost::lexical_cast<std::string>(TimeCondition).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTimeCondition = %s    [��Ч������]\n", boost::lexical_cast<std::string>(TimeCondition).c_str());
	}
	if (compare(TradingDay, pOriginal->TradingDay) != 0)
	{
		fprintf(fp, "\t\tTradingDay = %s -> %s    [������]\n", boost::lexical_cast<std::string>(pOriginal->TradingDay).c_str(), boost::lexical_cast<std::string>(TradingDay).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTradingDay = %s    [������]\n", boost::lexical_cast<std::string>(TradingDay).c_str());
	}
	if (compare(OrderInnerID, pOriginal->OrderInnerID) != 0)
	{
		fprintf(fp, "\t\tOrderInnerID = %s -> %s    [ϵͳ�ڲ�����(�ַ���)]\n", boost::lexical_cast<std::string>(pOriginal->OrderInnerID).c_str(), boost::lexical_cast<std::string>(OrderInnerID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tOrderInnerID = %s    [ϵͳ�ڲ�����(�ַ���)]\n", boost::lexical_cast<std::string>(OrderInnerID).c_str());
	}
	if (compare(OrderSysID, pOriginal->OrderSysID) != 0)
	{
		fprintf(fp, "\t\tOrderSysID = %s -> %s    [�������]\n", boost::lexical_cast<std::string>(pOriginal->OrderSysID).c_str(), boost::lexical_cast<std::string>(OrderSysID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tOrderSysID = %s    [�������]\n", boost::lexical_cast<std::string>(OrderSysID).c_str());
	}
	if (compare(TradePrice, pOriginal->TradePrice) != 0)
	{
		fprintf(fp, "\t\tTradePrice = %s -> %s    [�ɽ��۸�]\n", boost::lexical_cast<std::string>(pOriginal->TradePrice).c_str(), boost::lexical_cast<std::string>(TradePrice).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTradePrice = %s    [�ɽ��۸�]\n", boost::lexical_cast<std::string>(TradePrice).c_str());
	}
	if (compare(VolumeTraded, pOriginal->VolumeTraded) != 0)
	{
		fprintf(fp, "\t\tVolumeTraded = %s -> %s    [��ɽ�����]\n", boost::lexical_cast<std::string>(pOriginal->VolumeTraded).c_str(), boost::lexical_cast<std::string>(VolumeTraded).c_str());
	}
	else
	{
		fprintf(fp, "\t\tVolumeTraded = %s    [��ɽ�����]\n", boost::lexical_cast<std::string>(VolumeTraded).c_str());
	}
	if (compare(VolumeTotal, pOriginal->VolumeTotal) != 0)
	{
		fprintf(fp, "\t\tVolumeTotal = %s -> %s    [ʣ������]\n", boost::lexical_cast<std::string>(pOriginal->VolumeTotal).c_str(), boost::lexical_cast<std::string>(VolumeTotal).c_str());
	}
	else
	{
		fprintf(fp, "\t\tVolumeTotal = %s    [ʣ������]\n", boost::lexical_cast<std::string>(VolumeTotal).c_str());
	}
	if (compare(ExchangeInstID, pOriginal->ExchangeInstID) != 0)
	{
		fprintf(fp, "\t\tExchangeInstID = %s -> %s    [��Լ�ڽ������Ĵ���]\n", boost::lexical_cast<std::string>(pOriginal->ExchangeInstID).c_str(), boost::lexical_cast<std::string>(ExchangeInstID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tExchangeInstID = %s    [��Լ�ڽ������Ĵ���]\n", boost::lexical_cast<std::string>(ExchangeInstID).c_str());
	}
	if (compare(OrderSubmitStatus, pOriginal->OrderSubmitStatus) != 0)
	{
		fprintf(fp, "\t\tOrderSubmitStatus = %s -> %s    [�����ύ״̬]\n", boost::lexical_cast<std::string>(pOriginal->OrderSubmitStatus).c_str(), boost::lexical_cast<std::string>(OrderSubmitStatus).c_str());
	}
	else
	{
		fprintf(fp, "\t\tOrderSubmitStatus = %s    [�����ύ״̬]\n", boost::lexical_cast<std::string>(OrderSubmitStatus).c_str());
	}
	if (compare(OrderState, pOriginal->OrderState) != 0)
	{
		fprintf(fp, "\t\tOrderState = %s -> %s    [ί��״̬]\n", boost::lexical_cast<std::string>(pOriginal->OrderState).c_str(), boost::lexical_cast<std::string>(OrderState).c_str());
	}
	else
	{
		fprintf(fp, "\t\tOrderState = %s    [ί��״̬]\n", boost::lexical_cast<std::string>(OrderState).c_str());
	}
	if (compare(OrderStatus, pOriginal->OrderStatus) != 0)
	{
		fprintf(fp, "\t\tOrderStatus = %s -> %s    [����״̬]\n", boost::lexical_cast<std::string>(pOriginal->OrderStatus).c_str(), boost::lexical_cast<std::string>(OrderStatus).c_str());
	}
	else
	{
		fprintf(fp, "\t\tOrderStatus = %s    [����״̬]\n", boost::lexical_cast<std::string>(OrderStatus).c_str());
	}
	if (compare(InsertDate, pOriginal->InsertDate) != 0)
	{
		fprintf(fp, "\t\tInsertDate = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->InsertDate).c_str(), boost::lexical_cast<std::string>(InsertDate).c_str());
	}
	else
	{
		fprintf(fp, "\t\tInsertDate = %s    [��������]\n", boost::lexical_cast<std::string>(InsertDate).c_str());
	}
	if (compare(InsertTime, pOriginal->InsertTime) != 0)
	{
		fprintf(fp, "\t\tInsertTime = %s -> %s    [ί��ʱ��]\n", boost::lexical_cast<std::string>(pOriginal->InsertTime).c_str(), boost::lexical_cast<std::string>(InsertTime).c_str());
	}
	else
	{
		fprintf(fp, "\t\tInsertTime = %s    [ί��ʱ��]\n", boost::lexical_cast<std::string>(InsertTime).c_str());
	}
	if (compare(UpdateDate, pOriginal->UpdateDate) != 0)
	{
		fprintf(fp, "\t\tUpdateDate = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->UpdateDate).c_str(), boost::lexical_cast<std::string>(UpdateDate).c_str());
	}
	else
	{
		fprintf(fp, "\t\tUpdateDate = %s    [��������]\n", boost::lexical_cast<std::string>(UpdateDate).c_str());
	}
	if (compare(UpdateTime, pOriginal->UpdateTime) != 0)
	{
		fprintf(fp, "\t\tUpdateTime = %s -> %s    [����ʱ��]\n", boost::lexical_cast<std::string>(pOriginal->UpdateTime).c_str(), boost::lexical_cast<std::string>(UpdateTime).c_str());
	}
	else
	{
		fprintf(fp, "\t\tUpdateTime = %s    [����ʱ��]\n", boost::lexical_cast<std::string>(UpdateTime).c_str());
	}
	if (compare(CancelTime, pOriginal->CancelTime) != 0)
	{
		fprintf(fp, "\t\tCancelTime = %s -> %s    [����ʱ��]\n", boost::lexical_cast<std::string>(pOriginal->CancelTime).c_str(), boost::lexical_cast<std::string>(CancelTime).c_str());
	}
	else
	{
		fprintf(fp, "\t\tCancelTime = %s    [����ʱ��]\n", boost::lexical_cast<std::string>(CancelTime).c_str());
	}
	if (compare(ErrorCode, pOriginal->ErrorCode) != 0)
	{
		fprintf(fp, "\t\tErrorCode = %s -> %s    [���һ�β���������Ϣ��]\n", boost::lexical_cast<std::string>(pOriginal->ErrorCode).c_str(), boost::lexical_cast<std::string>(ErrorCode).c_str());
	}
	else
	{
		fprintf(fp, "\t\tErrorCode = %s    [���һ�β���������Ϣ��]\n", boost::lexical_cast<std::string>(ErrorCode).c_str());
	}
	if (compare(StatusMsg, pOriginal->StatusMsg) != 0)
	{
		fprintf(fp, "\t\tStatusMsg = %s -> %s    [״̬��Ϣ]\n", boost::lexical_cast<std::string>(pOriginal->StatusMsg).c_str(), boost::lexical_cast<std::string>(StatusMsg).c_str());
	}
	else
	{
		fprintf(fp, "\t\tStatusMsg = %s    [״̬��Ϣ]\n", boost::lexical_cast<std::string>(StatusMsg).c_str());
	}
	if (compare(SettlementID, pOriginal->SettlementID) != 0)
	{
		fprintf(fp, "\t\tSettlementID = %s -> %s    [������]\n", boost::lexical_cast<std::string>(pOriginal->SettlementID).c_str(), boost::lexical_cast<std::string>(SettlementID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tSettlementID = %s    [������]\n", boost::lexical_cast<std::string>(SettlementID).c_str());
	}
	if (compare(OrderSource, pOriginal->OrderSource) != 0)
	{
		fprintf(fp, "\t\tOrderSource = %s -> %s    [������Դ]\n", boost::lexical_cast<std::string>(pOriginal->OrderSource).c_str(), boost::lexical_cast<std::string>(OrderSource).c_str());
	}
	else
	{
		fprintf(fp, "\t\tOrderSource = %s    [������Դ]\n", boost::lexical_cast<std::string>(OrderSource).c_str());
	}
	if (compare(BrokerOrderSeq, pOriginal->BrokerOrderSeq) != 0)
	{
		fprintf(fp, "\t\tBrokerOrderSeq = %s -> %s    [���͹�˾�������]\n", boost::lexical_cast<std::string>(pOriginal->BrokerOrderSeq).c_str(), boost::lexical_cast<std::string>(BrokerOrderSeq).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBrokerOrderSeq = %s    [���͹�˾�������]\n", boost::lexical_cast<std::string>(BrokerOrderSeq).c_str());
	}
	if (compare(OrderRef, pOriginal->OrderRef) != 0)
	{
		fprintf(fp, "\t\tOrderRef = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->OrderRef).c_str(), boost::lexical_cast<std::string>(OrderRef).c_str());
	}
	else
	{
		fprintf(fp, "\t\tOrderRef = %s    [��������]\n", boost::lexical_cast<std::string>(OrderRef).c_str());
	}
	if (compare(FrontID, pOriginal->FrontID) != 0)
	{
		fprintf(fp, "\t\tFrontID = %s -> %s    [ǰ�ñ��]\n", boost::lexical_cast<std::string>(pOriginal->FrontID).c_str(), boost::lexical_cast<std::string>(FrontID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tFrontID = %s    [ǰ�ñ��]\n", boost::lexical_cast<std::string>(FrontID).c_str());
	}
	if (compare(SessionID, pOriginal->SessionID) != 0)
	{
		fprintf(fp, "\t\tSessionID = %s -> %s    [�Ự���]\n", boost::lexical_cast<std::string>(pOriginal->SessionID).c_str(), boost::lexical_cast<std::string>(SessionID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tSessionID = %s    [�Ự���]\n", boost::lexical_cast<std::string>(SessionID).c_str());
	}
	fprintf(fp, "\t}\n");
}

void COrder::dumpInLine(FILE *fp) const
{
	if (fp == nullptr)
	{
		fp = stdout;
	}
	std::stringstream sbuf;

	sbuf << ",UserID," << UserID;
	sbuf << ",ExchangeID," << ExchangeID;
	sbuf << ",CommodityID," << CommodityID;
	sbuf << ",InstrumentID," << InstrumentID;
	sbuf << ",OrderPriceType," << OrderPriceType;
	sbuf << ",OrderMode," << OrderMode;
	sbuf << ",Direction," << Direction;
	sbuf << ",OffsetFlag," << OffsetFlag;
	sbuf << ",HedgeFlag," << HedgeFlag;
	sbuf << ",Price," << Price;
	sbuf << ",Volume," << Volume;
	sbuf << ",OrderInfo," << OrderInfo;
	sbuf << ",BrokerID," << BrokerID;
	sbuf << ",InvestorID," << InvestorID;
	sbuf << ",TimeCondition," << TimeCondition;
	sbuf << ",TradingDay," << TradingDay;
	sbuf << ",OrderInnerID," << OrderInnerID;
	sbuf << ",OrderSysID," << OrderSysID;
	sbuf << ",TradePrice," << TradePrice;
	sbuf << ",VolumeTraded," << VolumeTraded;
	sbuf << ",VolumeTotal," << VolumeTotal;
	sbuf << ",ExchangeInstID," << ExchangeInstID;
	sbuf << ",OrderSubmitStatus," << OrderSubmitStatus;
	sbuf << ",OrderState," << OrderState;
	sbuf << ",OrderStatus," << OrderStatus;
	sbuf << ",InsertDate," << InsertDate;
	sbuf << ",InsertTime," << InsertTime;
	sbuf << ",UpdateDate," << UpdateDate;
	sbuf << ",UpdateTime," << UpdateTime;
	sbuf << ",CancelTime," << CancelTime;
	sbuf << ",ErrorCode," << ErrorCode;
	sbuf << ",StatusMsg," << StatusMsg;
	sbuf << ",SettlementID," << SettlementID;
	sbuf << ",OrderSource," << OrderSource;
	sbuf << ",BrokerOrderSeq," << BrokerOrderSeq;
	sbuf << ",OrderRef," << OrderRef;
	sbuf << ",FrontID," << FrontID;
	sbuf << ",SessionID," << SessionID;
	fprintf(fp, "%s", sbuf.str().c_str());
}

void COrder::dumpString(char *target) const
{
	char *p = target;
	std::stringstream sbuf;

	sbuf << "UserID=" << UserID << ",";
	sbuf << "ExchangeID=" << ExchangeID << ",";
	sbuf << "CommodityID=" << CommodityID << ",";
	sbuf << "InstrumentID=" << InstrumentID << ",";
	sbuf << "OrderPriceType=" << OrderPriceType << ",";
	sbuf << "OrderMode=" << OrderMode << ",";
	sbuf << "Direction=" << Direction << ",";
	sbuf << "OffsetFlag=" << OffsetFlag << ",";
	sbuf << "HedgeFlag=" << HedgeFlag << ",";
	sbuf << "Price=" << Price << ",";
	sbuf << "Volume=" << Volume << ",";
	sbuf << "OrderInfo=" << OrderInfo << ",";
	sbuf << "BrokerID=" << BrokerID << ",";
	sbuf << "InvestorID=" << InvestorID << ",";
	sbuf << "TimeCondition=" << TimeCondition << ",";
	sbuf << "TradingDay=" << TradingDay << ",";
	sbuf << "OrderInnerID=" << OrderInnerID << ",";
	sbuf << "OrderSysID=" << OrderSysID << ",";
	sbuf << "TradePrice=" << TradePrice << ",";
	sbuf << "VolumeTraded=" << VolumeTraded << ",";
	sbuf << "VolumeTotal=" << VolumeTotal << ",";
	sbuf << "ExchangeInstID=" << ExchangeInstID << ",";
	sbuf << "OrderSubmitStatus=" << OrderSubmitStatus << ",";
	sbuf << "OrderState=" << OrderState << ",";
	sbuf << "OrderStatus=" << OrderStatus << ",";
	sbuf << "InsertDate=" << InsertDate << ",";
	sbuf << "InsertTime=" << InsertTime << ",";
	sbuf << "UpdateDate=" << UpdateDate << ",";
	sbuf << "UpdateTime=" << UpdateTime << ",";
	sbuf << "CancelTime=" << CancelTime << ",";
	sbuf << "ErrorCode=" << ErrorCode << ",";
	sbuf << "StatusMsg=" << StatusMsg << ",";
	sbuf << "SettlementID=" << SettlementID << ",";
	sbuf << "OrderSource=" << OrderSource << ",";
	sbuf << "BrokerOrderSeq=" << BrokerOrderSeq << ",";
	sbuf << "OrderRef=" << OrderRef << ",";
	sbuf << "FrontID=" << FrontID << ",";
	sbuf << "SessionID=" << SessionID << ",";

	sprintf(p, "%s", sbuf.str().c_str());
}

void CTrade::init(void)
{
	memset(this, 0, sizeof(CTrade));
}

int CTrade::read(FILE *input)
{
	if (fread(this, 1, sizeof(CTrade), input) != sizeof(CTrade))
		return 0;
	else
		return 1;
}

int CTrade::write(FILE *output) const
{
	if (fwrite(this, 1, sizeof(CTrade), output) != sizeof(CTrade))
		return 0;
	else
		return 1;
}

void CTrade::dump(FILE *fp, int index) const
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

	fprintf(fp, "\tCTrade%s = {\n", index_buf);
	fprintf(fp, "\t\tExchangeID = %s    [����������]\n", boost::lexical_cast<std::string>(ExchangeID).c_str());
	fprintf(fp, "\t\tTradingDay = %s    [������]\n", boost::lexical_cast<std::string>(TradingDay).c_str());
	fprintf(fp, "\t\tTradeID = %s    [�ɽ���]\n", boost::lexical_cast<std::string>(TradeID).c_str());
	fprintf(fp, "\t\tOrderSysID = %s    [�������]\n", boost::lexical_cast<std::string>(OrderSysID).c_str());
	fprintf(fp, "\t\tOrderInnerID = %s    [ϵͳ�ڲ�����(�ַ���)]\n", boost::lexical_cast<std::string>(OrderInnerID).c_str());
	fprintf(fp, "\t\tCommodityID = %s    [��Ʒ����]\n", boost::lexical_cast<std::string>(CommodityID).c_str());
	fprintf(fp, "\t\tInstrumentID = %s    [��Լ����]\n", boost::lexical_cast<std::string>(InstrumentID).c_str());
	fprintf(fp, "\t\tUserID = %s    [����Ա����]\n", boost::lexical_cast<std::string>(UserID).c_str());
	fprintf(fp, "\t\tDirection = %s    [��������]\n", boost::lexical_cast<std::string>(Direction).c_str());
	fprintf(fp, "\t\tOffsetFlag = %s    [����ƽ��]\n", boost::lexical_cast<std::string>(OffsetFlag).c_str());
	fprintf(fp, "\t\tTradePrice = %s    [�ɽ���]\n", boost::lexical_cast<std::string>(TradePrice).c_str());
	fprintf(fp, "\t\tVolumeTraded = %s    [�ɽ�����]\n", boost::lexical_cast<std::string>(VolumeTraded).c_str());
	fprintf(fp, "\t\tTradeDate = %s    [�ɽ�����]\n", boost::lexical_cast<std::string>(TradeDate).c_str());
	fprintf(fp, "\t\tTradeTime = %s    [�ɽ�ʱ��]\n", boost::lexical_cast<std::string>(TradeTime).c_str());
	fprintf(fp, "\t\tTradeFee = %s    [������]\n", boost::lexical_cast<std::string>(TradeFee).c_str());
	fprintf(fp, "\t\tCurrencyID = %s    [�����ѱ���]\n", boost::lexical_cast<std::string>(CurrencyID).c_str());
	fprintf(fp, "\t\tManualFee = %s    [�ֹ�������]\n", boost::lexical_cast<std::string>(ManualFee).c_str());
	fprintf(fp, "\t\tDeleted = %s    [ɾ����־]\n", boost::lexical_cast<std::string>(Deleted).c_str());
	fprintf(fp, "\t\tCoverPrice = %s    [ƽ�ּ۸�]\n", boost::lexical_cast<std::string>(CoverPrice).c_str());
	fprintf(fp, "\t\tExchangeInstID = %s    [��Լ�ڽ������Ĵ���]\n", boost::lexical_cast<std::string>(ExchangeInstID).c_str());
	fprintf(fp, "\t\tBrokerID = %s    [���ͻ�Ա����]\n", boost::lexical_cast<std::string>(BrokerID).c_str());
	fprintf(fp, "\t\tInvestorID = %s    [Ͷ���ߴ���]\n", boost::lexical_cast<std::string>(InvestorID).c_str());
	fprintf(fp, "\t\tOrderRef = %s    [��������]\n", boost::lexical_cast<std::string>(OrderRef).c_str());
	fprintf(fp, "\t\tHedgeFlag = %s    [Ͷ����ֵ]\n", boost::lexical_cast<std::string>(HedgeFlag).c_str());
	fprintf(fp, "\t}\n");
}

void CTrade::dumpDiff(FILE *fp, const CTrade *pOriginal) const
{
	if (fp == nullptr)
	{
		fp = stdout;
	}
	fprintf(fp, "\tCTrade = {\n");
	if (compare(ExchangeID, pOriginal->ExchangeID) != 0)
	{
		fprintf(fp, "\t\tExchangeID = %s -> %s    [����������]\n", boost::lexical_cast<std::string>(pOriginal->ExchangeID).c_str(), boost::lexical_cast<std::string>(ExchangeID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tExchangeID = %s    [����������]\n", boost::lexical_cast<std::string>(ExchangeID).c_str());
	}
	if (compare(TradingDay, pOriginal->TradingDay) != 0)
	{
		fprintf(fp, "\t\tTradingDay = %s -> %s    [������]\n", boost::lexical_cast<std::string>(pOriginal->TradingDay).c_str(), boost::lexical_cast<std::string>(TradingDay).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTradingDay = %s    [������]\n", boost::lexical_cast<std::string>(TradingDay).c_str());
	}
	if (compare(TradeID, pOriginal->TradeID) != 0)
	{
		fprintf(fp, "\t\tTradeID = %s -> %s    [�ɽ���]\n", boost::lexical_cast<std::string>(pOriginal->TradeID).c_str(), boost::lexical_cast<std::string>(TradeID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTradeID = %s    [�ɽ���]\n", boost::lexical_cast<std::string>(TradeID).c_str());
	}
	if (compare(OrderSysID, pOriginal->OrderSysID) != 0)
	{
		fprintf(fp, "\t\tOrderSysID = %s -> %s    [�������]\n", boost::lexical_cast<std::string>(pOriginal->OrderSysID).c_str(), boost::lexical_cast<std::string>(OrderSysID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tOrderSysID = %s    [�������]\n", boost::lexical_cast<std::string>(OrderSysID).c_str());
	}
	if (compare(OrderInnerID, pOriginal->OrderInnerID) != 0)
	{
		fprintf(fp, "\t\tOrderInnerID = %s -> %s    [ϵͳ�ڲ�����(�ַ���)]\n", boost::lexical_cast<std::string>(pOriginal->OrderInnerID).c_str(), boost::lexical_cast<std::string>(OrderInnerID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tOrderInnerID = %s    [ϵͳ�ڲ�����(�ַ���)]\n", boost::lexical_cast<std::string>(OrderInnerID).c_str());
	}
	if (compare(CommodityID, pOriginal->CommodityID) != 0)
	{
		fprintf(fp, "\t\tCommodityID = %s -> %s    [��Ʒ����]\n", boost::lexical_cast<std::string>(pOriginal->CommodityID).c_str(), boost::lexical_cast<std::string>(CommodityID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tCommodityID = %s    [��Ʒ����]\n", boost::lexical_cast<std::string>(CommodityID).c_str());
	}
	if (compare(InstrumentID, pOriginal->InstrumentID) != 0)
	{
		fprintf(fp, "\t\tInstrumentID = %s -> %s    [��Լ����]\n", boost::lexical_cast<std::string>(pOriginal->InstrumentID).c_str(), boost::lexical_cast<std::string>(InstrumentID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tInstrumentID = %s    [��Լ����]\n", boost::lexical_cast<std::string>(InstrumentID).c_str());
	}
	if (compare(UserID, pOriginal->UserID) != 0)
	{
		fprintf(fp, "\t\tUserID = %s -> %s    [����Ա����]\n", boost::lexical_cast<std::string>(pOriginal->UserID).c_str(), boost::lexical_cast<std::string>(UserID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tUserID = %s    [����Ա����]\n", boost::lexical_cast<std::string>(UserID).c_str());
	}
	if (compare(Direction, pOriginal->Direction) != 0)
	{
		fprintf(fp, "\t\tDirection = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->Direction).c_str(), boost::lexical_cast<std::string>(Direction).c_str());
	}
	else
	{
		fprintf(fp, "\t\tDirection = %s    [��������]\n", boost::lexical_cast<std::string>(Direction).c_str());
	}
	if (compare(OffsetFlag, pOriginal->OffsetFlag) != 0)
	{
		fprintf(fp, "\t\tOffsetFlag = %s -> %s    [����ƽ��]\n", boost::lexical_cast<std::string>(pOriginal->OffsetFlag).c_str(), boost::lexical_cast<std::string>(OffsetFlag).c_str());
	}
	else
	{
		fprintf(fp, "\t\tOffsetFlag = %s    [����ƽ��]\n", boost::lexical_cast<std::string>(OffsetFlag).c_str());
	}
	if (compare(TradePrice, pOriginal->TradePrice) != 0)
	{
		fprintf(fp, "\t\tTradePrice = %s -> %s    [�ɽ���]\n", boost::lexical_cast<std::string>(pOriginal->TradePrice).c_str(), boost::lexical_cast<std::string>(TradePrice).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTradePrice = %s    [�ɽ���]\n", boost::lexical_cast<std::string>(TradePrice).c_str());
	}
	if (compare(VolumeTraded, pOriginal->VolumeTraded) != 0)
	{
		fprintf(fp, "\t\tVolumeTraded = %s -> %s    [�ɽ�����]\n", boost::lexical_cast<std::string>(pOriginal->VolumeTraded).c_str(), boost::lexical_cast<std::string>(VolumeTraded).c_str());
	}
	else
	{
		fprintf(fp, "\t\tVolumeTraded = %s    [�ɽ�����]\n", boost::lexical_cast<std::string>(VolumeTraded).c_str());
	}
	if (compare(TradeDate, pOriginal->TradeDate) != 0)
	{
		fprintf(fp, "\t\tTradeDate = %s -> %s    [�ɽ�����]\n", boost::lexical_cast<std::string>(pOriginal->TradeDate).c_str(), boost::lexical_cast<std::string>(TradeDate).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTradeDate = %s    [�ɽ�����]\n", boost::lexical_cast<std::string>(TradeDate).c_str());
	}
	if (compare(TradeTime, pOriginal->TradeTime) != 0)
	{
		fprintf(fp, "\t\tTradeTime = %s -> %s    [�ɽ�ʱ��]\n", boost::lexical_cast<std::string>(pOriginal->TradeTime).c_str(), boost::lexical_cast<std::string>(TradeTime).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTradeTime = %s    [�ɽ�ʱ��]\n", boost::lexical_cast<std::string>(TradeTime).c_str());
	}
	if (compare(TradeFee, pOriginal->TradeFee) != 0)
	{
		fprintf(fp, "\t\tTradeFee = %s -> %s    [������]\n", boost::lexical_cast<std::string>(pOriginal->TradeFee).c_str(), boost::lexical_cast<std::string>(TradeFee).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTradeFee = %s    [������]\n", boost::lexical_cast<std::string>(TradeFee).c_str());
	}
	if (compare(CurrencyID, pOriginal->CurrencyID) != 0)
	{
		fprintf(fp, "\t\tCurrencyID = %s -> %s    [�����ѱ���]\n", boost::lexical_cast<std::string>(pOriginal->CurrencyID).c_str(), boost::lexical_cast<std::string>(CurrencyID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tCurrencyID = %s    [�����ѱ���]\n", boost::lexical_cast<std::string>(CurrencyID).c_str());
	}
	if (compare(ManualFee, pOriginal->ManualFee) != 0)
	{
		fprintf(fp, "\t\tManualFee = %s -> %s    [�ֹ�������]\n", boost::lexical_cast<std::string>(pOriginal->ManualFee).c_str(), boost::lexical_cast<std::string>(ManualFee).c_str());
	}
	else
	{
		fprintf(fp, "\t\tManualFee = %s    [�ֹ�������]\n", boost::lexical_cast<std::string>(ManualFee).c_str());
	}
	if (compare(Deleted, pOriginal->Deleted) != 0)
	{
		fprintf(fp, "\t\tDeleted = %s -> %s    [ɾ����־]\n", boost::lexical_cast<std::string>(pOriginal->Deleted).c_str(), boost::lexical_cast<std::string>(Deleted).c_str());
	}
	else
	{
		fprintf(fp, "\t\tDeleted = %s    [ɾ����־]\n", boost::lexical_cast<std::string>(Deleted).c_str());
	}
	if (compare(CoverPrice, pOriginal->CoverPrice) != 0)
	{
		fprintf(fp, "\t\tCoverPrice = %s -> %s    [ƽ�ּ۸�]\n", boost::lexical_cast<std::string>(pOriginal->CoverPrice).c_str(), boost::lexical_cast<std::string>(CoverPrice).c_str());
	}
	else
	{
		fprintf(fp, "\t\tCoverPrice = %s    [ƽ�ּ۸�]\n", boost::lexical_cast<std::string>(CoverPrice).c_str());
	}
	if (compare(ExchangeInstID, pOriginal->ExchangeInstID) != 0)
	{
		fprintf(fp, "\t\tExchangeInstID = %s -> %s    [��Լ�ڽ������Ĵ���]\n", boost::lexical_cast<std::string>(pOriginal->ExchangeInstID).c_str(), boost::lexical_cast<std::string>(ExchangeInstID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tExchangeInstID = %s    [��Լ�ڽ������Ĵ���]\n", boost::lexical_cast<std::string>(ExchangeInstID).c_str());
	}
	if (compare(BrokerID, pOriginal->BrokerID) != 0)
	{
		fprintf(fp, "\t\tBrokerID = %s -> %s    [���ͻ�Ա����]\n", boost::lexical_cast<std::string>(pOriginal->BrokerID).c_str(), boost::lexical_cast<std::string>(BrokerID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBrokerID = %s    [���ͻ�Ա����]\n", boost::lexical_cast<std::string>(BrokerID).c_str());
	}
	if (compare(InvestorID, pOriginal->InvestorID) != 0)
	{
		fprintf(fp, "\t\tInvestorID = %s -> %s    [Ͷ���ߴ���]\n", boost::lexical_cast<std::string>(pOriginal->InvestorID).c_str(), boost::lexical_cast<std::string>(InvestorID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tInvestorID = %s    [Ͷ���ߴ���]\n", boost::lexical_cast<std::string>(InvestorID).c_str());
	}
	if (compare(OrderRef, pOriginal->OrderRef) != 0)
	{
		fprintf(fp, "\t\tOrderRef = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->OrderRef).c_str(), boost::lexical_cast<std::string>(OrderRef).c_str());
	}
	else
	{
		fprintf(fp, "\t\tOrderRef = %s    [��������]\n", boost::lexical_cast<std::string>(OrderRef).c_str());
	}
	if (compare(HedgeFlag, pOriginal->HedgeFlag) != 0)
	{
		fprintf(fp, "\t\tHedgeFlag = %s -> %s    [Ͷ����ֵ]\n", boost::lexical_cast<std::string>(pOriginal->HedgeFlag).c_str(), boost::lexical_cast<std::string>(HedgeFlag).c_str());
	}
	else
	{
		fprintf(fp, "\t\tHedgeFlag = %s    [Ͷ����ֵ]\n", boost::lexical_cast<std::string>(HedgeFlag).c_str());
	}
	fprintf(fp, "\t}\n");
}

void CTrade::dumpInLine(FILE *fp) const
{
	if (fp == nullptr)
	{
		fp = stdout;
	}
	std::stringstream sbuf;

	sbuf << ",ExchangeID," << ExchangeID;
	sbuf << ",TradingDay," << TradingDay;
	sbuf << ",TradeID," << TradeID;
	sbuf << ",OrderSysID," << OrderSysID;
	sbuf << ",OrderInnerID," << OrderInnerID;
	sbuf << ",CommodityID," << CommodityID;
	sbuf << ",InstrumentID," << InstrumentID;
	sbuf << ",UserID," << UserID;
	sbuf << ",Direction," << Direction;
	sbuf << ",OffsetFlag," << OffsetFlag;
	sbuf << ",TradePrice," << TradePrice;
	sbuf << ",VolumeTraded," << VolumeTraded;
	sbuf << ",TradeDate," << TradeDate;
	sbuf << ",TradeTime," << TradeTime;
	sbuf << ",TradeFee," << TradeFee;
	sbuf << ",CurrencyID," << CurrencyID;
	sbuf << ",ManualFee," << ManualFee;
	sbuf << ",Deleted," << Deleted;
	sbuf << ",CoverPrice," << CoverPrice;
	sbuf << ",ExchangeInstID," << ExchangeInstID;
	sbuf << ",BrokerID," << BrokerID;
	sbuf << ",InvestorID," << InvestorID;
	sbuf << ",OrderRef," << OrderRef;
	sbuf << ",HedgeFlag," << HedgeFlag;
	fprintf(fp, "%s", sbuf.str().c_str());
}

void CTrade::dumpString(char *target) const
{
	char *p = target;
	std::stringstream sbuf;

	sbuf << "ExchangeID=" << ExchangeID << ",";
	sbuf << "TradingDay=" << TradingDay << ",";
	sbuf << "TradeID=" << TradeID << ",";
	sbuf << "OrderSysID=" << OrderSysID << ",";
	sbuf << "OrderInnerID=" << OrderInnerID << ",";
	sbuf << "CommodityID=" << CommodityID << ",";
	sbuf << "InstrumentID=" << InstrumentID << ",";
	sbuf << "UserID=" << UserID << ",";
	sbuf << "Direction=" << Direction << ",";
	sbuf << "OffsetFlag=" << OffsetFlag << ",";
	sbuf << "TradePrice=" << TradePrice << ",";
	sbuf << "VolumeTraded=" << VolumeTraded << ",";
	sbuf << "TradeDate=" << TradeDate << ",";
	sbuf << "TradeTime=" << TradeTime << ",";
	sbuf << "TradeFee=" << TradeFee << ",";
	sbuf << "CurrencyID=" << CurrencyID << ",";
	sbuf << "ManualFee=" << ManualFee << ",";
	sbuf << "Deleted=" << Deleted << ",";
	sbuf << "CoverPrice=" << CoverPrice << ",";
	sbuf << "ExchangeInstID=" << ExchangeInstID << ",";
	sbuf << "BrokerID=" << BrokerID << ",";
	sbuf << "InvestorID=" << InvestorID << ",";
	sbuf << "OrderRef=" << OrderRef << ",";
	sbuf << "HedgeFlag=" << HedgeFlag << ",";

	sprintf(p, "%s", sbuf.str().c_str());
}

void CEsfInstPartInfo::init(void)
{
	memset(this, 0, sizeof(CEsfInstPartInfo));
}

int CEsfInstPartInfo::read(FILE *input)
{
	if (fread(this, 1, sizeof(CEsfInstPartInfo), input) != sizeof(CEsfInstPartInfo))
		return 0;
	else
		return 1;
}

int CEsfInstPartInfo::write(FILE *output) const
{
	if (fwrite(this, 1, sizeof(CEsfInstPartInfo), output) != sizeof(CEsfInstPartInfo))
		return 0;
	else
		return 1;
}

void CEsfInstPartInfo::dump(FILE *fp, int index) const
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

	fprintf(fp, "\tCEsfInstPartInfo%s = {\n", index_buf);
	fprintf(fp, "\t\tExchangeName = %s    [����������]\n", boost::lexical_cast<std::string>(ExchangeName).c_str());
	fprintf(fp, "\t\tInstrumentID = %s    [��Լ����]\n", boost::lexical_cast<std::string>(InstrumentID).c_str());
	fprintf(fp, "\t\tInstrumentName = %s    [��Լ����]\n", boost::lexical_cast<std::string>(InstrumentName).c_str());
	fprintf(fp, "\t\tPrecision = %s    [���۾���]\n", boost::lexical_cast<std::string>(Precision).c_str());
	fprintf(fp, "\t}\n");
}

void CEsfInstPartInfo::dumpDiff(FILE *fp, const CEsfInstPartInfo *pOriginal) const
{
	if (fp == nullptr)
	{
		fp = stdout;
	}
	fprintf(fp, "\tCEsfInstPartInfo = {\n");
	if (compare(ExchangeName, pOriginal->ExchangeName) != 0)
	{
		fprintf(fp, "\t\tExchangeName = %s -> %s    [����������]\n", boost::lexical_cast<std::string>(pOriginal->ExchangeName).c_str(), boost::lexical_cast<std::string>(ExchangeName).c_str());
	}
	else
	{
		fprintf(fp, "\t\tExchangeName = %s    [����������]\n", boost::lexical_cast<std::string>(ExchangeName).c_str());
	}
	if (compare(InstrumentID, pOriginal->InstrumentID) != 0)
	{
		fprintf(fp, "\t\tInstrumentID = %s -> %s    [��Լ����]\n", boost::lexical_cast<std::string>(pOriginal->InstrumentID).c_str(), boost::lexical_cast<std::string>(InstrumentID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tInstrumentID = %s    [��Լ����]\n", boost::lexical_cast<std::string>(InstrumentID).c_str());
	}
	if (compare(InstrumentName, pOriginal->InstrumentName) != 0)
	{
		fprintf(fp, "\t\tInstrumentName = %s -> %s    [��Լ����]\n", boost::lexical_cast<std::string>(pOriginal->InstrumentName).c_str(), boost::lexical_cast<std::string>(InstrumentName).c_str());
	}
	else
	{
		fprintf(fp, "\t\tInstrumentName = %s    [��Լ����]\n", boost::lexical_cast<std::string>(InstrumentName).c_str());
	}
	if (compare(Precision, pOriginal->Precision) != 0)
	{
		fprintf(fp, "\t\tPrecision = %s -> %s    [���۾���]\n", boost::lexical_cast<std::string>(pOriginal->Precision).c_str(), boost::lexical_cast<std::string>(Precision).c_str());
	}
	else
	{
		fprintf(fp, "\t\tPrecision = %s    [���۾���]\n", boost::lexical_cast<std::string>(Precision).c_str());
	}
	fprintf(fp, "\t}\n");
}

void CEsfInstPartInfo::dumpInLine(FILE *fp) const
{
	if (fp == nullptr)
	{
		fp = stdout;
	}
	std::stringstream sbuf;

	sbuf << ",ExchangeName," << ExchangeName;
	sbuf << ",InstrumentID," << InstrumentID;
	sbuf << ",InstrumentName," << InstrumentName;
	sbuf << ",Precision," << Precision;
	fprintf(fp, "%s", sbuf.str().c_str());
}

void CEsfInstPartInfo::dumpString(char *target) const
{
	char *p = target;
	std::stringstream sbuf;

	sbuf << "ExchangeName=" << ExchangeName << ",";
	sbuf << "InstrumentID=" << InstrumentID << ",";
	sbuf << "InstrumentName=" << InstrumentName << ",";
	sbuf << "Precision=" << Precision << ",";

	sprintf(p, "%s", sbuf.str().c_str());
}

void CCurrency::init(void)
{
	memset(this, 0, sizeof(CCurrency));
}

int CCurrency::read(FILE *input)
{
	if (fread(this, 1, sizeof(CCurrency), input) != sizeof(CCurrency))
		return 0;
	else
		return 1;
}

int CCurrency::write(FILE *output) const
{
	if (fwrite(this, 1, sizeof(CCurrency), output) != sizeof(CCurrency))
		return 0;
	else
		return 1;
}

void CCurrency::dump(FILE *fp, int index) const
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
	fprintf(fp, "\tCCurrency%s = {\n", index_buf);
	fprintf(fp, "\t\tCurrencyID = %s    [���ұ��]\n", boost::lexical_cast<std::string>(CurrencyID).c_str());
	fprintf(fp, "\t\tCurrencyName = %s    [��������]\n", boost::lexical_cast<std::string>(CurrencyName).c_str());
	fprintf(fp, "\t\tIsPrimary = %s    [�ǻ���]\n", boost::lexical_cast<std::string>(IsPrimary).c_str());
	fprintf(fp, "\t\tIsShare = %s    [���ǻ���]\n", boost::lexical_cast<std::string>(IsShare).c_str());
	fprintf(fp, "\t\tExchangeRate = %s    [����(1��ǰ���һ�����ٻ���)]\n", boost::lexical_cast<std::string>(ExchangeRate).c_str());
	fprintf(fp, "\t}\n");
}

void CCurrency::dumpDiff(FILE *fp, const CCurrency *pOriginal) const
{
	if (fp == NULL)
	{
		fp = stdout;
	}
	fprintf(fp, "\tCCurrency = {\n");
	if (compare(CurrencyID, pOriginal->CurrencyID) != 0)
	{
		fprintf(fp, "\t\tCurrencyID = %s -> %s    [���ұ��]\n", boost::lexical_cast<std::string>(pOriginal->CurrencyID).c_str(), boost::lexical_cast<std::string>(CurrencyID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tCurrencyID = %s    [���ұ��]\n", boost::lexical_cast<std::string>(CurrencyID).c_str());
	}
	if (compare(CurrencyName, pOriginal->CurrencyName) != 0)
	{
		fprintf(fp, "\t\tCurrencyName = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->CurrencyName).c_str(), boost::lexical_cast<std::string>(CurrencyName).c_str());
	}
	else
	{
		fprintf(fp, "\t\tCurrencyName = %s    [��������]\n", boost::lexical_cast<std::string>(CurrencyName).c_str());
	}
	if (compare(IsPrimary, pOriginal->IsPrimary) != 0)
	{
		fprintf(fp, "\t\tIsPrimary = %s -> %s    [�ǻ���]\n", boost::lexical_cast<std::string>(pOriginal->IsPrimary).c_str(), boost::lexical_cast<std::string>(IsPrimary).c_str());
	}
	else
	{
		fprintf(fp, "\t\tIsPrimary = %s    [�ǻ���]\n", boost::lexical_cast<std::string>(IsPrimary).c_str());
	}
	if (compare(IsShare, pOriginal->IsShare) != 0)
	{
		fprintf(fp, "\t\tIsShare = %s -> %s    [���ǻ���]\n", boost::lexical_cast<std::string>(pOriginal->IsShare).c_str(), boost::lexical_cast<std::string>(IsShare).c_str());
	}
	else
	{
		fprintf(fp, "\t\tIsShare = %s    [���ǻ���]\n", boost::lexical_cast<std::string>(IsShare).c_str());
	}
	if (compare(ExchangeRate, pOriginal->ExchangeRate) != 0)
	{
		fprintf(fp, "\t\tExchangeRate = %s -> %s    [����(1��ǰ���һ�����ٻ���)]\n", boost::lexical_cast<std::string>(pOriginal->ExchangeRate).c_str(), boost::lexical_cast<std::string>(ExchangeRate).c_str());
	}
	else
	{
		fprintf(fp, "\t\tExchangeRate = %s    [����(1��ǰ���һ�����ٻ���)]\n", boost::lexical_cast<std::string>(ExchangeRate).c_str());
	}
	fprintf(fp, "\t}\n");
}

void CCurrency::dumpInLine(FILE *fp) const
{
	if (fp == nullptr)
	{
		fp = stdout;
	}
	std::stringstream sbuf;

	sbuf << ",CurrencyID," << CurrencyID;
	sbuf << ",CurrencyName," << CurrencyName;
	sbuf << ",IsPrimary," << IsPrimary;
	sbuf << ",IsShare," << IsShare;
	sbuf << ",ExchangeRate," << ExchangeRate;
	fprintf(fp, "%s", sbuf.str().c_str());
}

void CCurrency::dumpString(char *target) const
{
	char *p = target;

	std::stringstream sbuf;

	sbuf << "CurrencyID=" << CurrencyID << ",";
	sbuf << "CurrencyName=" << CurrencyName << ",";
	sbuf << "IsPrimary=" << IsPrimary << ",";
	sbuf << "IsShare=" << IsShare << ",";
	sbuf << "ExchangeRate=" << ExchangeRate << ",";

	sprintf(p, "%s", sbuf.str().c_str());
}

void CExchUserLogin::init(void)
{
	memset(this, 0, sizeof(CExchUserLogin));
}

int CExchUserLogin::read(FILE *input)
{
	if (fread(this, 1, sizeof(CExchUserLogin), input) != sizeof(CExchUserLogin))
		return 0;
	else
		return 1;
}

int CExchUserLogin::write(FILE *output) const
{
	if (fwrite(this, 1, sizeof(CExchUserLogin), output) != sizeof(CExchUserLogin))
		return 0;
	else
		return 1;
}

void CExchUserLogin::dump(FILE *fp, int index) const
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

	fprintf(fp, "\tCExchUserLogin%s = {\n", index_buf);
	fprintf(fp, "\t\tBrokerID = %s    [���͹�˾����]\n", boost::lexical_cast<std::string>(BrokerID).c_str());
	fprintf(fp, "\t\tUserID = %s    [�û�����]\n", boost::lexical_cast<std::string>(UserID).c_str());
	fprintf(fp, "\t\tPassword = %s    [��¼����]\n", boost::lexical_cast<std::string>(Password).c_str());
	fprintf(fp, "\t\tTradingDay = %s    [ϵͳ������]\n", boost::lexical_cast<std::string>(TradingDay).c_str());
	fprintf(fp, "\t\tLoginTime = %s    [��¼�ɹ�ʱ��]\n", boost::lexical_cast<std::string>(LoginTime).c_str());
	fprintf(fp, "\t\tMaxOrderRef = %s    [��󱨵�����]\n", boost::lexical_cast<std::string>(MaxOrderRef).c_str());
	fprintf(fp, "\t\tIPAddress = %s    [IP��ַ]\n", boost::lexical_cast<std::string>(IPAddress).c_str());
	fprintf(fp, "\t\tUserProductInfo = %s    [�û��˲�Ʒ��Ϣ]\n", boost::lexical_cast<std::string>(UserProductInfo).c_str());
	fprintf(fp, "\t\tInterfaceProductInfo = %s    [�ӿڶ˲�Ʒ��Ϣ]\n", boost::lexical_cast<std::string>(InterfaceProductInfo).c_str());
	fprintf(fp, "\t\tProtocolInfo = %s    [Э����Ϣ]\n", boost::lexical_cast<std::string>(ProtocolInfo).c_str());
	fprintf(fp, "\t}\n");
}

void CExchUserLogin::dumpDiff(FILE *fp, const CExchUserLogin *pOriginal) const
{
	if (fp == nullptr)
	{
		fp = stdout;
	}
	fprintf(fp, "\tCExchUserLogin = {\n");
	if (compare(BrokerID, pOriginal->BrokerID) != 0)
	{
		fprintf(fp, "\t\tBrokerID = %s -> %s    [���͹�˾����]\n", boost::lexical_cast<std::string>(pOriginal->BrokerID).c_str(), boost::lexical_cast<std::string>(BrokerID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBrokerID = %s    [���͹�˾����]\n", boost::lexical_cast<std::string>(BrokerID).c_str());
	}
	if (compare(UserID, pOriginal->UserID) != 0)
	{
		fprintf(fp, "\t\tUserID = %s -> %s    [�û�����]\n", boost::lexical_cast<std::string>(pOriginal->UserID).c_str(), boost::lexical_cast<std::string>(UserID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tUserID = %s    [�û�����]\n", boost::lexical_cast<std::string>(UserID).c_str());
	}
	if (compare(Password, pOriginal->Password) != 0)
	{
		fprintf(fp, "\t\tPassword = %s -> %s    [��¼����]\n", boost::lexical_cast<std::string>(pOriginal->Password).c_str(), boost::lexical_cast<std::string>(Password).c_str());
	}
	else
	{
		fprintf(fp, "\t\tPassword = %s    [��¼����]\n", boost::lexical_cast<std::string>(Password).c_str());
	}
	if (compare(TradingDay, pOriginal->TradingDay) != 0)
	{
		fprintf(fp, "\t\tTradingDay = %s -> %s    [ϵͳ������]\n", boost::lexical_cast<std::string>(pOriginal->TradingDay).c_str(), boost::lexical_cast<std::string>(TradingDay).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTradingDay = %s    [ϵͳ������]\n", boost::lexical_cast<std::string>(TradingDay).c_str());
	}
	if (compare(LoginTime, pOriginal->LoginTime) != 0)
	{
		fprintf(fp, "\t\tLoginTime = %s -> %s    [��¼�ɹ�ʱ��]\n", boost::lexical_cast<std::string>(pOriginal->LoginTime).c_str(), boost::lexical_cast<std::string>(LoginTime).c_str());
	}
	else
	{
		fprintf(fp, "\t\tLoginTime = %s    [��¼�ɹ�ʱ��]\n", boost::lexical_cast<std::string>(LoginTime).c_str());
	}
	if (compare(MaxOrderRef, pOriginal->MaxOrderRef) != 0)
	{
		fprintf(fp, "\t\tMaxOrderRef = %s -> %s    [��󱨵�����]\n", boost::lexical_cast<std::string>(pOriginal->MaxOrderRef).c_str(), boost::lexical_cast<std::string>(MaxOrderRef).c_str());
	}
	else
	{
		fprintf(fp, "\t\tMaxOrderRef = %s    [��󱨵�����]\n", boost::lexical_cast<std::string>(MaxOrderRef).c_str());
	}
	if (compare(IPAddress, pOriginal->IPAddress) != 0)
	{
		fprintf(fp, "\t\tIPAddress = %s -> %s    [IP��ַ]\n", boost::lexical_cast<std::string>(pOriginal->IPAddress).c_str(), boost::lexical_cast<std::string>(IPAddress).c_str());
	}
	else
	{
		fprintf(fp, "\t\tIPAddress = %s    [IP��ַ]\n", boost::lexical_cast<std::string>(IPAddress).c_str());
	}
	if (compare(UserProductInfo, pOriginal->UserProductInfo) != 0)
	{
		fprintf(fp, "\t\tUserProductInfo = %s -> %s    [�û��˲�Ʒ��Ϣ]\n", boost::lexical_cast<std::string>(pOriginal->UserProductInfo).c_str(), boost::lexical_cast<std::string>(UserProductInfo).c_str());
	}
	else
	{
		fprintf(fp, "\t\tUserProductInfo = %s    [�û��˲�Ʒ��Ϣ]\n", boost::lexical_cast<std::string>(UserProductInfo).c_str());
	}
	if (compare(InterfaceProductInfo, pOriginal->InterfaceProductInfo) != 0)
	{
		fprintf(fp, "\t\tInterfaceProductInfo = %s -> %s    [�ӿڶ˲�Ʒ��Ϣ]\n", boost::lexical_cast<std::string>(pOriginal->InterfaceProductInfo).c_str(), boost::lexical_cast<std::string>(InterfaceProductInfo).c_str());
	}
	else
	{
		fprintf(fp, "\t\tInterfaceProductInfo = %s    [�ӿڶ˲�Ʒ��Ϣ]\n", boost::lexical_cast<std::string>(InterfaceProductInfo).c_str());
	}
	if (compare(ProtocolInfo, pOriginal->ProtocolInfo) != 0)
	{
		fprintf(fp, "\t\tProtocolInfo = %s -> %s    [Э����Ϣ]\n", boost::lexical_cast<std::string>(pOriginal->ProtocolInfo).c_str(), boost::lexical_cast<std::string>(ProtocolInfo).c_str());
	}
	else
	{
		fprintf(fp, "\t\tProtocolInfo = %s    [Э����Ϣ]\n", boost::lexical_cast<std::string>(ProtocolInfo).c_str());
	}
	fprintf(fp, "\t}\n");
}

void CExchUserLogin::dumpInLine(FILE *fp) const
{
	if (fp == nullptr)
	{
		fp = stdout;
	}
	std::stringstream sbuf;

	sbuf << ",BrokerID," << BrokerID;
	sbuf << ",UserID," << UserID;
	sbuf << ",Password," << Password;
	sbuf << ",TradingDay," << TradingDay;
	sbuf << ",LoginTime," << LoginTime;
	sbuf << ",MaxOrderRef," << MaxOrderRef;
	sbuf << ",IPAddress," << IPAddress;
	sbuf << ",UserProductInfo," << UserProductInfo;
	sbuf << ",InterfaceProductInfo," << InterfaceProductInfo;
	sbuf << ",ProtocolInfo," << ProtocolInfo;
	fprintf(fp, "%s", sbuf.str().c_str());
}

void CExchUserLogin::dumpString(char *target) const
{
	char *p = target;
	std::stringstream sbuf;

	sbuf << "BrokerID=" << BrokerID << ",";
	sbuf << "UserID=" << UserID << ",";
	sbuf << "Password=" << Password << ",";
	sbuf << "TradingDay=" << TradingDay << ",";
	sbuf << "LoginTime=" << LoginTime << ",";
	sbuf << "MaxOrderRef=" << MaxOrderRef << ",";
	sbuf << "IPAddress=" << IPAddress << ",";
	sbuf << "UserProductInfo=" << UserProductInfo << ",";
	sbuf << "InterfaceProductInfo=" << InterfaceProductInfo << ",";
	sbuf << "ProtocolInfo=" << ProtocolInfo << ",";

	sprintf(p, "%s", sbuf.str().c_str());
}

void CExchUserLogout::init(void)
{
	memset(this, 0, sizeof(CExchUserLogout));
}

int CExchUserLogout::read(FILE *input)
{
	if (fread(this, 1, sizeof(CExchUserLogout), input) != sizeof(CExchUserLogout))
		return 0;
	else
		return 1;
}

int CExchUserLogout::write(FILE *output) const
{
	if (fwrite(this, 1, sizeof(CExchUserLogout), output) != sizeof(CExchUserLogout))
		return 0;
	else
		return 1;
}

void CExchUserLogout::dump(FILE *fp, int index) const
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
	fprintf(fp, "\tCExchUserLogout%s = {\n", index_buf);
	fprintf(fp, "\t\tUserID = %s    [�û�����]\n", boost::lexical_cast<std::string>(UserID).c_str());
	fprintf(fp, "\t\tBrokerID = %s    [���͹�˾����]\n", boost::lexical_cast<std::string>(BrokerID).c_str());
	fprintf(fp, "\t}\n");
}

void CExchUserLogout::dumpDiff(FILE *fp, const CExchUserLogout *pOriginal) const
{
	if (fp == nullptr)
	{
		fp = stdout;
	}
	fprintf(fp, "\tCExchUserLogout = {\n");
	if (compare(UserID, pOriginal->UserID) != 0)
	{
		fprintf(fp, "\t\tUserID = %s -> %s    [�û�����]\n", boost::lexical_cast<std::string>(pOriginal->UserID).c_str(), boost::lexical_cast<std::string>(UserID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tUserID = %s    [�û�����]\n", boost::lexical_cast<std::string>(UserID).c_str());
	}
	if (compare(BrokerID, pOriginal->BrokerID) != 0)
	{
		fprintf(fp, "\t\tBrokerID = %s -> %s    [���͹�˾����]\n", boost::lexical_cast<std::string>(pOriginal->BrokerID).c_str(), boost::lexical_cast<std::string>(BrokerID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBrokerID = %s    [���͹�˾����]\n", boost::lexical_cast<std::string>(BrokerID).c_str());
	}
	fprintf(fp, "\t}\n");
}

void CExchUserLogout::dumpInLine(FILE *fp) const
{
	if (fp == nullptr)
	{
		fp = stdout;
	}
	std::stringstream sbuf;

	sbuf << ",UserID," << UserID;
	sbuf << ",BrokerID," << BrokerID;
	fprintf(fp, "%s", sbuf.str().c_str());
}

void CExchUserLogout::dumpString(char *target) const
{
	char *p = target;

	std::stringstream sbuf;

	sbuf << "UserID=" << UserID << ",";
	sbuf << "BrokerID=" << BrokerID << ",";

	sprintf(p, "%s", sbuf.str().c_str());
}

void CExchMDUserLogin::init(void)
{
	memset(this, 0, sizeof(CExchMDUserLogin));
}

int CExchMDUserLogin::read(FILE *input)
{
	if (fread(this, 1, sizeof(CExchMDUserLogin), input) != sizeof(CExchMDUserLogin))
		return 0;
	else
		return 1;
}

int CExchMDUserLogin::write(FILE *output) const
{
	if (fwrite(this, 1, sizeof(CExchMDUserLogin), output) != sizeof(CExchMDUserLogin))
		return 0;
	else
		return 1;
}

void CExchMDUserLogin::dump(FILE *fp, int index) const
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
	fprintf(fp, "\tCExchMDUserLogin%s = {\n", index_buf);
	fprintf(fp, "\t\tBrokerID = %s    [���͹�˾����]\n", boost::lexical_cast<std::string>(BrokerID).c_str());
	fprintf(fp, "\t\tUserID = %s    [�û�����]\n", boost::lexical_cast<std::string>(UserID).c_str());
	fprintf(fp, "\t\tPassword = %s    [��¼����]\n", boost::lexical_cast<std::string>(Password).c_str());
	fprintf(fp, "\t\tTradingDay = %s    [ϵͳ������]\n", boost::lexical_cast<std::string>(TradingDay).c_str());
	fprintf(fp, "\t\tLoginTime = %s    [��¼�ɹ�ʱ��]\n", boost::lexical_cast<std::string>(LoginTime).c_str());
	fprintf(fp, "\t\tMaxOrderRef = %s    [��󱨵�����]\n", boost::lexical_cast<std::string>(MaxOrderRef).c_str());
	fprintf(fp, "\t\tIPAddress = %s    [IP��ַ]\n", boost::lexical_cast<std::string>(IPAddress).c_str());
	fprintf(fp, "\t\tUserProductInfo = %s    [�û��˲�Ʒ��Ϣ]\n", boost::lexical_cast<std::string>(UserProductInfo).c_str());
	fprintf(fp, "\t\tInterfaceProductInfo = %s    [�ӿڶ˲�Ʒ��Ϣ]\n", boost::lexical_cast<std::string>(InterfaceProductInfo).c_str());
	fprintf(fp, "\t\tProtocolInfo = %s    [Э����Ϣ]\n", boost::lexical_cast<std::string>(ProtocolInfo).c_str());
	fprintf(fp, "\t}\n");
}

void CExchMDUserLogin::dumpDiff(FILE *fp, const CExchMDUserLogin *pOriginal) const
{
	if (fp == nullptr)
	{
		fp = stdout;
	}
	fprintf(fp, "\tCExchMDUserLogin = {\n");
	if (compare(BrokerID, pOriginal->BrokerID) != 0)
	{
		fprintf(fp, "\t\tBrokerID = %s -> %s    [���͹�˾����]\n", boost::lexical_cast<std::string>(pOriginal->BrokerID).c_str(), boost::lexical_cast<std::string>(BrokerID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBrokerID = %s    [���͹�˾����]\n", boost::lexical_cast<std::string>(BrokerID).c_str());
	}
	if (compare(UserID, pOriginal->UserID) != 0)
	{
		fprintf(fp, "\t\tUserID = %s -> %s    [�û�����]\n", boost::lexical_cast<std::string>(pOriginal->UserID).c_str(), boost::lexical_cast<std::string>(UserID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tUserID = %s    [�û�����]\n", boost::lexical_cast<std::string>(UserID).c_str());
	}
	if (compare(Password, pOriginal->Password) != 0)
	{
		fprintf(fp, "\t\tPassword = %s -> %s    [��¼����]\n", boost::lexical_cast<std::string>(pOriginal->Password).c_str(), boost::lexical_cast<std::string>(Password).c_str());
	}
	else
	{
		fprintf(fp, "\t\tPassword = %s    [��¼����]\n", boost::lexical_cast<std::string>(Password).c_str());
	}
	if (compare(TradingDay, pOriginal->TradingDay) != 0)
	{
		fprintf(fp, "\t\tTradingDay = %s -> %s    [ϵͳ������]\n", boost::lexical_cast<std::string>(pOriginal->TradingDay).c_str(), boost::lexical_cast<std::string>(TradingDay).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTradingDay = %s    [ϵͳ������]\n", boost::lexical_cast<std::string>(TradingDay).c_str());
	}
	if (compare(LoginTime, pOriginal->LoginTime) != 0)
	{
		fprintf(fp, "\t\tLoginTime = %s -> %s    [��¼�ɹ�ʱ��]\n", boost::lexical_cast<std::string>(pOriginal->LoginTime).c_str(), boost::lexical_cast<std::string>(LoginTime).c_str());
	}
	else
	{
		fprintf(fp, "\t\tLoginTime = %s    [��¼�ɹ�ʱ��]\n", boost::lexical_cast<std::string>(LoginTime).c_str());
	}
	if (compare(MaxOrderRef, pOriginal->MaxOrderRef) != 0)
	{
		fprintf(fp, "\t\tMaxOrderRef = %s -> %s    [��󱨵�����]\n", boost::lexical_cast<std::string>(pOriginal->MaxOrderRef).c_str(), boost::lexical_cast<std::string>(MaxOrderRef).c_str());
	}
	else
	{
		fprintf(fp, "\t\tMaxOrderRef = %s    [��󱨵�����]\n", boost::lexical_cast<std::string>(MaxOrderRef).c_str());
	}
	if (compare(IPAddress, pOriginal->IPAddress) != 0)
	{
		fprintf(fp, "\t\tIPAddress = %s -> %s    [IP��ַ]\n", boost::lexical_cast<std::string>(pOriginal->IPAddress).c_str(), boost::lexical_cast<std::string>(IPAddress).c_str());
	}
	else
	{
		fprintf(fp, "\t\tIPAddress = %s    [IP��ַ]\n", boost::lexical_cast<std::string>(IPAddress).c_str());
	}
	if (compare(UserProductInfo, pOriginal->UserProductInfo) != 0)
	{
		fprintf(fp, "\t\tUserProductInfo = %s -> %s    [�û��˲�Ʒ��Ϣ]\n", boost::lexical_cast<std::string>(pOriginal->UserProductInfo).c_str(), boost::lexical_cast<std::string>(UserProductInfo).c_str());
	}
	else
	{
		fprintf(fp, "\t\tUserProductInfo = %s    [�û��˲�Ʒ��Ϣ]\n", boost::lexical_cast<std::string>(UserProductInfo).c_str());
	}
	if (compare(InterfaceProductInfo, pOriginal->InterfaceProductInfo) != 0)
	{
		fprintf(fp, "\t\tInterfaceProductInfo = %s -> %s    [�ӿڶ˲�Ʒ��Ϣ]\n", boost::lexical_cast<std::string>(pOriginal->InterfaceProductInfo).c_str(), boost::lexical_cast<std::string>(InterfaceProductInfo).c_str());
	}
	else
	{
		fprintf(fp, "\t\tInterfaceProductInfo = %s    [�ӿڶ˲�Ʒ��Ϣ]\n", boost::lexical_cast<std::string>(InterfaceProductInfo).c_str());
	}
	if (compare(ProtocolInfo, pOriginal->ProtocolInfo) != 0)
	{
		fprintf(fp, "\t\tProtocolInfo = %s -> %s    [Э����Ϣ]\n", boost::lexical_cast<std::string>(pOriginal->ProtocolInfo).c_str(), boost::lexical_cast<std::string>(ProtocolInfo).c_str());
	}
	else
	{
		fprintf(fp, "\t\tProtocolInfo = %s    [Э����Ϣ]\n", boost::lexical_cast<std::string>(ProtocolInfo).c_str());
	}
	fprintf(fp, "\t}\n");
}

void CExchMDUserLogin::dumpInLine(FILE *fp) const
{
	if (fp == nullptr)
	{
		fp = stdout;
	}
	std::stringstream sbuf;

	sbuf << ",BrokerID," << BrokerID;
	sbuf << ",UserID," << UserID;
	sbuf << ",Password," << Password;
	sbuf << ",TradingDay," << TradingDay;
	sbuf << ",LoginTime," << LoginTime;
	sbuf << ",MaxOrderRef," << MaxOrderRef;
	sbuf << ",IPAddress," << IPAddress;
	sbuf << ",UserProductInfo," << UserProductInfo;
	sbuf << ",InterfaceProductInfo," << InterfaceProductInfo;
	sbuf << ",ProtocolInfo," << ProtocolInfo;
	fprintf(fp, "%s", sbuf.str().c_str());
}

void CExchMDUserLogin::dumpString(char *target) const
{
	char *p = target;
	std::stringstream sbuf;

	sbuf << "BrokerID=" << BrokerID << ",";
	sbuf << "UserID=" << UserID << ",";
	sbuf << "Password=" << Password << ",";
	sbuf << "TradingDay=" << TradingDay << ",";
	sbuf << "LoginTime=" << LoginTime << ",";
	sbuf << "MaxOrderRef=" << MaxOrderRef << ",";
	sbuf << "IPAddress=" << IPAddress << ",";
	sbuf << "UserProductInfo=" << UserProductInfo << ",";
	sbuf << "InterfaceProductInfo=" << InterfaceProductInfo << ",";
	sbuf << "ProtocolInfo=" << ProtocolInfo << ",";

	sprintf(p, "%s", sbuf.str().c_str());
}

void CExchMDUserLogout::init(void)
{
	memset(this, 0, sizeof(CExchMDUserLogout));
}

int CExchMDUserLogout::read(FILE *input)
{
	if (fread(this, 1, sizeof(CExchMDUserLogout), input) != sizeof(CExchMDUserLogout))
		return 0;
	else
		return 1;
}

int CExchMDUserLogout::write(FILE *output) const
{
	if (fwrite(this, 1, sizeof(CExchMDUserLogout), output) != sizeof(CExchMDUserLogout))
		return 0;
	else
		return 1;
}

void CExchMDUserLogout::dump(FILE *fp, int index) const
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
	fprintf(fp, "\tCExchMDUserLogout%s = {\n", index_buf);
	fprintf(fp, "\t\tUserID = %s    [�û�����]\n", boost::lexical_cast<std::string>(UserID).c_str());
	fprintf(fp, "\t\tBrokerID = %s    [���͹�˾����]\n", boost::lexical_cast<std::string>(BrokerID).c_str());
	fprintf(fp, "\t}\n");
}

void CExchMDUserLogout::dumpDiff(FILE *fp, const CExchMDUserLogout *pOriginal) const
{
	if (fp == nullptr)
	{
		fp = stdout;
	}
	fprintf(fp, "\tCExchMDUserLogout = {\n");
	if (compare(UserID, pOriginal->UserID) != 0)
	{
		fprintf(fp, "\t\tUserID = %s -> %s    [�û�����]\n", boost::lexical_cast<std::string>(pOriginal->UserID).c_str(), boost::lexical_cast<std::string>(UserID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tUserID = %s    [�û�����]\n", boost::lexical_cast<std::string>(UserID).c_str());
	}
	if (compare(BrokerID, pOriginal->BrokerID) != 0)
	{
		fprintf(fp, "\t\tBrokerID = %s -> %s    [���͹�˾����]\n", boost::lexical_cast<std::string>(pOriginal->BrokerID).c_str(), boost::lexical_cast<std::string>(BrokerID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBrokerID = %s    [���͹�˾����]\n", boost::lexical_cast<std::string>(BrokerID).c_str());
	}
	fprintf(fp, "\t}\n");
}

void CExchMDUserLogout::dumpInLine(FILE *fp) const
{
	if (fp == nullptr)
	{
		fp = stdout;
	}
	std::stringstream sbuf;

	sbuf << ",UserID," << UserID;
	sbuf << ",BrokerID," << BrokerID;
	fprintf(fp, "%s", sbuf.str().c_str());
}

void CExchMDUserLogout::dumpString(char *target) const
{
	char *p = target;

	std::stringstream sbuf;

	sbuf << "UserID=" << UserID << ",";
	sbuf << "BrokerID=" << BrokerID << ",";

	sprintf(p, "%s", sbuf.str().c_str());
}

void CExchOrder::init(void)
{
	memset(this, 0, sizeof(CExchOrder));
}

int CExchOrder::read(FILE *input)
{
	if (fread(this, 1, sizeof(CExchOrder), input) != sizeof(CExchOrder))
		return 0;
	else
		return 1;
}

int CExchOrder::write(FILE *output) const
{
	if (fwrite(this, 1, sizeof(CExchOrder), output) != sizeof(CExchOrder))
		return 0;
	else
		return 1;
}

void CExchOrder::dump(FILE *fp, int index) const
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
	fprintf(fp, "\tCExchOrder%s = {\n", index_buf);
	fprintf(fp, "\t\tUserID = %s    [�û�����]\n", boost::lexical_cast<std::string>(UserID).c_str());
	fprintf(fp, "\t\tExchangeID = %s    [����������]\n", boost::lexical_cast<std::string>(ExchangeID).c_str());
	fprintf(fp, "\t\tCommodityID = %s    [��Ʒ����]\n", boost::lexical_cast<std::string>(CommodityID).c_str());
	fprintf(fp, "\t\tInstrumentID = %s    [��Լ����]\n", boost::lexical_cast<std::string>(InstrumentID).c_str());
	fprintf(fp, "\t\tOrderPriceType = %s    [�����۸�����]\n", boost::lexical_cast<std::string>(OrderPriceType).c_str());
	fprintf(fp, "\t\tOrderMode = %s    [ί��ģʽ]\n", boost::lexical_cast<std::string>(OrderMode).c_str());
	fprintf(fp, "\t\tDirection = %s    [��������]\n", boost::lexical_cast<std::string>(Direction).c_str());
	fprintf(fp, "\t\tOffsetFlag = %s    [����ƽ��]\n", boost::lexical_cast<std::string>(OffsetFlag).c_str());
	fprintf(fp, "\t\tHedgeFlag = %s    [Ͷ����ֵ]\n", boost::lexical_cast<std::string>(HedgeFlag).c_str());
	fprintf(fp, "\t\tPrice = %s    [ί�м۸�]\n", boost::lexical_cast<std::string>(Price).c_str());
	fprintf(fp, "\t\tVolume = %s    [ί������]\n", boost::lexical_cast<std::string>(Volume).c_str());
	fprintf(fp, "\t\tOrderInfo = %s    [�ͻ�������Ϣ]\n", boost::lexical_cast<std::string>(OrderInfo).c_str());
	fprintf(fp, "\t\tBrokerID = %s    [���ͻ�Ա����]\n", boost::lexical_cast<std::string>(BrokerID).c_str());
	fprintf(fp, "\t\tInvestorID = %s    [Ͷ���߱��]\n", boost::lexical_cast<std::string>(InvestorID).c_str());
	fprintf(fp, "\t\tTimeCondition = %s    [��Ч������]\n", boost::lexical_cast<std::string>(TimeCondition).c_str());
	fprintf(fp, "\t\tTradingDay = %s    [������]\n", boost::lexical_cast<std::string>(TradingDay).c_str());
	fprintf(fp, "\t\tOrderInnerID = %s    [ϵͳ�ڲ�����(�ַ���)]\n", boost::lexical_cast<std::string>(OrderInnerID).c_str());
	fprintf(fp, "\t\tOrderSysID = %s    [�������]\n", boost::lexical_cast<std::string>(OrderSysID).c_str());
	fprintf(fp, "\t\tTradePrice = %s    [�ɽ��۸�]\n", boost::lexical_cast<std::string>(TradePrice).c_str());
	fprintf(fp, "\t\tVolumeTraded = %s    [��ɽ�����]\n", boost::lexical_cast<std::string>(VolumeTraded).c_str());
	fprintf(fp, "\t\tVolumeTotal = %s    [ʣ������]\n", boost::lexical_cast<std::string>(VolumeTotal).c_str());
	fprintf(fp, "\t\tExchangeInstID = %s    [��Լ�ڽ������Ĵ���]\n", boost::lexical_cast<std::string>(ExchangeInstID).c_str());
	fprintf(fp, "\t\tOrderSubmitStatus = %s    [�����ύ״̬]\n", boost::lexical_cast<std::string>(OrderSubmitStatus).c_str());
	fprintf(fp, "\t\tOrderState = %s    [ί��״̬]\n", boost::lexical_cast<std::string>(OrderState).c_str());
	fprintf(fp, "\t\tOrderStatus = %s    [����״̬]\n", boost::lexical_cast<std::string>(OrderStatus).c_str());
	fprintf(fp, "\t\tInsertDate = %s    [��������]\n", boost::lexical_cast<std::string>(InsertDate).c_str());
	fprintf(fp, "\t\tInsertTime = %s    [ί��ʱ��]\n", boost::lexical_cast<std::string>(InsertTime).c_str());
	fprintf(fp, "\t\tUpdateDate = %s    [��������]\n", boost::lexical_cast<std::string>(UpdateDate).c_str());
	fprintf(fp, "\t\tUpdateTime = %s    [����ʱ��]\n", boost::lexical_cast<std::string>(UpdateTime).c_str());
	fprintf(fp, "\t\tCancelTime = %s    [����ʱ��]\n", boost::lexical_cast<std::string>(CancelTime).c_str());
	fprintf(fp, "\t\tErrorCode = %s    [���һ�β���������Ϣ��]\n", boost::lexical_cast<std::string>(ErrorCode).c_str());
	fprintf(fp, "\t\tStatusMsg = %s    [״̬��Ϣ]\n", boost::lexical_cast<std::string>(StatusMsg).c_str());
	fprintf(fp, "\t\tSettlementID = %s    [������]\n", boost::lexical_cast<std::string>(SettlementID).c_str());
	fprintf(fp, "\t\tOrderSource = %s    [������Դ]\n", boost::lexical_cast<std::string>(OrderSource).c_str());
	fprintf(fp, "\t\tBrokerOrderSeq = %s    [���͹�˾�������]\n", boost::lexical_cast<std::string>(BrokerOrderSeq).c_str());
	fprintf(fp, "\t\tOrderRef = %s    [��������]\n", boost::lexical_cast<std::string>(OrderRef).c_str());
	fprintf(fp, "\t\tFrontID = %s    [ǰ�ñ��]\n", boost::lexical_cast<std::string>(FrontID).c_str());
	fprintf(fp, "\t\tSessionID = %s    [�Ự���]\n", boost::lexical_cast<std::string>(SessionID).c_str());
	fprintf(fp, "\t\tTerminalID = %s    [�ն˻����]\n", boost::lexical_cast<std::string>(TerminalID).c_str());
	fprintf(fp, "\t\tTerminalType = %s    [�ն˻�����]\n", boost::lexical_cast<std::string>(TerminalType).c_str());
	fprintf(fp, "\t\tAppType = %s    [���׽ӿ�����]\n", boost::lexical_cast<std::string>(AppType).c_str());
	fprintf(fp, "\t}\n");
}

void CExchOrder::dumpDiff(FILE *fp, const CExchOrder *pOriginal) const
{
	if (fp == nullptr)
	{
		fp = stdout;
	}
	fprintf(fp, "\tCExchOrder = {\n");
	if (compare(UserID, pOriginal->UserID) != 0)
	{
		fprintf(fp, "\t\tUserID = %s -> %s    [�û�����]\n", boost::lexical_cast<std::string>(pOriginal->UserID).c_str(), boost::lexical_cast<std::string>(UserID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tUserID = %s    [�û�����]\n", boost::lexical_cast<std::string>(UserID).c_str());
	}
	if (compare(ExchangeID, pOriginal->ExchangeID) != 0)
	{
		fprintf(fp, "\t\tExchangeID = %s -> %s    [����������]\n", boost::lexical_cast<std::string>(pOriginal->ExchangeID).c_str(), boost::lexical_cast<std::string>(ExchangeID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tExchangeID = %s    [����������]\n", boost::lexical_cast<std::string>(ExchangeID).c_str());
	}
	if (compare(CommodityID, pOriginal->CommodityID) != 0)
	{
		fprintf(fp, "\t\tCommodityID = %s -> %s    [��Ʒ����]\n", boost::lexical_cast<std::string>(pOriginal->CommodityID).c_str(), boost::lexical_cast<std::string>(CommodityID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tCommodityID = %s    [��Ʒ����]\n", boost::lexical_cast<std::string>(CommodityID).c_str());
	}
	if (compare(InstrumentID, pOriginal->InstrumentID) != 0)
	{
		fprintf(fp, "\t\tInstrumentID = %s -> %s    [��Լ����]\n", boost::lexical_cast<std::string>(pOriginal->InstrumentID).c_str(), boost::lexical_cast<std::string>(InstrumentID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tInstrumentID = %s    [��Լ����]\n", boost::lexical_cast<std::string>(InstrumentID).c_str());
	}
	if (compare(OrderPriceType, pOriginal->OrderPriceType) != 0)
	{
		fprintf(fp, "\t\tOrderPriceType = %s -> %s    [�����۸�����]\n", boost::lexical_cast<std::string>(pOriginal->OrderPriceType).c_str(), boost::lexical_cast<std::string>(OrderPriceType).c_str());
	}
	else
	{
		fprintf(fp, "\t\tOrderPriceType = %s    [�����۸�����]\n", boost::lexical_cast<std::string>(OrderPriceType).c_str());
	}
	if (compare(OrderMode, pOriginal->OrderMode) != 0)
	{
		fprintf(fp, "\t\tOrderMode = %s -> %s    [ί��ģʽ]\n", boost::lexical_cast<std::string>(pOriginal->OrderMode).c_str(), boost::lexical_cast<std::string>(OrderMode).c_str());
	}
	else
	{
		fprintf(fp, "\t\tOrderMode = %s    [ί��ģʽ]\n", boost::lexical_cast<std::string>(OrderMode).c_str());
	}
	if (compare(Direction, pOriginal->Direction) != 0)
	{
		fprintf(fp, "\t\tDirection = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->Direction).c_str(), boost::lexical_cast<std::string>(Direction).c_str());
	}
	else
	{
		fprintf(fp, "\t\tDirection = %s    [��������]\n", boost::lexical_cast<std::string>(Direction).c_str());
	}
	if (compare(OffsetFlag, pOriginal->OffsetFlag) != 0)
	{
		fprintf(fp, "\t\tOffsetFlag = %s -> %s    [����ƽ��]\n", boost::lexical_cast<std::string>(pOriginal->OffsetFlag).c_str(), boost::lexical_cast<std::string>(OffsetFlag).c_str());
	}
	else
	{
		fprintf(fp, "\t\tOffsetFlag = %s    [����ƽ��]\n", boost::lexical_cast<std::string>(OffsetFlag).c_str());
	}
	if (compare(HedgeFlag, pOriginal->HedgeFlag) != 0)
	{
		fprintf(fp, "\t\tHedgeFlag = %s -> %s    [Ͷ����ֵ]\n", boost::lexical_cast<std::string>(pOriginal->HedgeFlag).c_str(), boost::lexical_cast<std::string>(HedgeFlag).c_str());
	}
	else
	{
		fprintf(fp, "\t\tHedgeFlag = %s    [Ͷ����ֵ]\n", boost::lexical_cast<std::string>(HedgeFlag).c_str());
	}
	if (compare(Price, pOriginal->Price) != 0)
	{
		fprintf(fp, "\t\tPrice = %s -> %s    [ί�м۸�]\n", boost::lexical_cast<std::string>(pOriginal->Price).c_str(), boost::lexical_cast<std::string>(Price).c_str());
	}
	else
	{
		fprintf(fp, "\t\tPrice = %s    [ί�м۸�]\n", boost::lexical_cast<std::string>(Price).c_str());
	}
	if (compare(Volume, pOriginal->Volume) != 0)
	{
		fprintf(fp, "\t\tVolume = %s -> %s    [ί������]\n", boost::lexical_cast<std::string>(pOriginal->Volume).c_str(), boost::lexical_cast<std::string>(Volume).c_str());
	}
	else
	{
		fprintf(fp, "\t\tVolume = %s    [ί������]\n", boost::lexical_cast<std::string>(Volume).c_str());
	}
	if (compare(OrderInfo, pOriginal->OrderInfo) != 0)
	{
		fprintf(fp, "\t\tOrderInfo = %s -> %s    [�ͻ�������Ϣ]\n", boost::lexical_cast<std::string>(pOriginal->OrderInfo).c_str(), boost::lexical_cast<std::string>(OrderInfo).c_str());
	}
	else
	{
		fprintf(fp, "\t\tOrderInfo = %s    [�ͻ�������Ϣ]\n", boost::lexical_cast<std::string>(OrderInfo).c_str());
	}
	if (compare(BrokerID, pOriginal->BrokerID) != 0)
	{
		fprintf(fp, "\t\tBrokerID = %s -> %s    [���ͻ�Ա����]\n", boost::lexical_cast<std::string>(pOriginal->BrokerID).c_str(), boost::lexical_cast<std::string>(BrokerID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBrokerID = %s    [���ͻ�Ա����]\n", boost::lexical_cast<std::string>(BrokerID).c_str());
	}
	if (compare(InvestorID, pOriginal->InvestorID) != 0)
	{
		fprintf(fp, "\t\tInvestorID = %s -> %s    [Ͷ���߱��]\n", boost::lexical_cast<std::string>(pOriginal->InvestorID).c_str(), boost::lexical_cast<std::string>(InvestorID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tInvestorID = %s    [Ͷ���߱��]\n", boost::lexical_cast<std::string>(InvestorID).c_str());
	}
	if (compare(TimeCondition, pOriginal->TimeCondition) != 0)
	{
		fprintf(fp, "\t\tTimeCondition = %s -> %s    [��Ч������]\n", boost::lexical_cast<std::string>(pOriginal->TimeCondition).c_str(), boost::lexical_cast<std::string>(TimeCondition).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTimeCondition = %s    [��Ч������]\n", boost::lexical_cast<std::string>(TimeCondition).c_str());
	}
	if (compare(TradingDay, pOriginal->TradingDay) != 0)
	{
		fprintf(fp, "\t\tTradingDay = %s -> %s    [������]\n", boost::lexical_cast<std::string>(pOriginal->TradingDay).c_str(), boost::lexical_cast<std::string>(TradingDay).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTradingDay = %s    [������]\n", boost::lexical_cast<std::string>(TradingDay).c_str());
	}
	if (compare(OrderInnerID, pOriginal->OrderInnerID) != 0)
	{
		fprintf(fp, "\t\tOrderInnerID = %s -> %s    [ϵͳ�ڲ�����(�ַ���)]\n", boost::lexical_cast<std::string>(pOriginal->OrderInnerID).c_str(), boost::lexical_cast<std::string>(OrderInnerID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tOrderInnerID = %s    [ϵͳ�ڲ�����(�ַ���)]\n", boost::lexical_cast<std::string>(OrderInnerID).c_str());
	}
	if (compare(OrderSysID, pOriginal->OrderSysID) != 0)
	{
		fprintf(fp, "\t\tOrderSysID = %s -> %s    [�������]\n", boost::lexical_cast<std::string>(pOriginal->OrderSysID).c_str(), boost::lexical_cast<std::string>(OrderSysID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tOrderSysID = %s    [�������]\n", boost::lexical_cast<std::string>(OrderSysID).c_str());
	}
	if (compare(TradePrice, pOriginal->TradePrice) != 0)
	{
		fprintf(fp, "\t\tTradePrice = %s -> %s    [�ɽ��۸�]\n", boost::lexical_cast<std::string>(pOriginal->TradePrice).c_str(), boost::lexical_cast<std::string>(TradePrice).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTradePrice = %s    [�ɽ��۸�]\n", boost::lexical_cast<std::string>(TradePrice).c_str());
	}
	if (compare(VolumeTraded, pOriginal->VolumeTraded) != 0)
	{
		fprintf(fp, "\t\tVolumeTraded = %s -> %s    [��ɽ�����]\n", boost::lexical_cast<std::string>(pOriginal->VolumeTraded).c_str(), boost::lexical_cast<std::string>(VolumeTraded).c_str());
	}
	else
	{
		fprintf(fp, "\t\tVolumeTraded = %s    [��ɽ�����]\n", boost::lexical_cast<std::string>(VolumeTraded).c_str());
	}
	if (compare(VolumeTotal, pOriginal->VolumeTotal) != 0)
	{
		fprintf(fp, "\t\tVolumeTotal = %s -> %s    [ʣ������]\n", boost::lexical_cast<std::string>(pOriginal->VolumeTotal).c_str(), boost::lexical_cast<std::string>(VolumeTotal).c_str());
	}
	else
	{
		fprintf(fp, "\t\tVolumeTotal = %s    [ʣ������]\n", boost::lexical_cast<std::string>(VolumeTotal).c_str());
	}
	if (compare(ExchangeInstID, pOriginal->ExchangeInstID) != 0)
	{
		fprintf(fp, "\t\tExchangeInstID = %s -> %s    [��Լ�ڽ������Ĵ���]\n", boost::lexical_cast<std::string>(pOriginal->ExchangeInstID).c_str(), boost::lexical_cast<std::string>(ExchangeInstID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tExchangeInstID = %s    [��Լ�ڽ������Ĵ���]\n", boost::lexical_cast<std::string>(ExchangeInstID).c_str());
	}
	if (compare(OrderSubmitStatus, pOriginal->OrderSubmitStatus) != 0)
	{
		fprintf(fp, "\t\tOrderSubmitStatus = %s -> %s    [�����ύ״̬]\n", boost::lexical_cast<std::string>(pOriginal->OrderSubmitStatus).c_str(), boost::lexical_cast<std::string>(OrderSubmitStatus).c_str());
	}
	else
	{
		fprintf(fp, "\t\tOrderSubmitStatus = %s    [�����ύ״̬]\n", boost::lexical_cast<std::string>(OrderSubmitStatus).c_str());
	}
	if (compare(OrderState, pOriginal->OrderState) != 0)
	{
		fprintf(fp, "\t\tOrderState = %s -> %s    [ί��״̬]\n", boost::lexical_cast<std::string>(pOriginal->OrderState).c_str(), boost::lexical_cast<std::string>(OrderState).c_str());
	}
	else
	{
		fprintf(fp, "\t\tOrderState = %s    [ί��״̬]\n", boost::lexical_cast<std::string>(OrderState).c_str());
	}
	if (compare(OrderStatus, pOriginal->OrderStatus) != 0)
	{
		fprintf(fp, "\t\tOrderStatus = %s -> %s    [����״̬]\n", boost::lexical_cast<std::string>(pOriginal->OrderStatus).c_str(), boost::lexical_cast<std::string>(OrderStatus).c_str());
	}
	else
	{
		fprintf(fp, "\t\tOrderStatus = %s    [����״̬]\n", boost::lexical_cast<std::string>(OrderStatus).c_str());
	}
	if (compare(InsertDate, pOriginal->InsertDate) != 0)
	{
		fprintf(fp, "\t\tInsertDate = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->InsertDate).c_str(), boost::lexical_cast<std::string>(InsertDate).c_str());
	}
	else
	{
		fprintf(fp, "\t\tInsertDate = %s    [��������]\n", boost::lexical_cast<std::string>(InsertDate).c_str());
	}
	if (compare(InsertTime, pOriginal->InsertTime) != 0)
	{
		fprintf(fp, "\t\tInsertTime = %s -> %s    [ί��ʱ��]\n", boost::lexical_cast<std::string>(pOriginal->InsertTime).c_str(), boost::lexical_cast<std::string>(InsertTime).c_str());
	}
	else
	{
		fprintf(fp, "\t\tInsertTime = %s    [ί��ʱ��]\n", boost::lexical_cast<std::string>(InsertTime).c_str());
	}
	if (compare(UpdateDate, pOriginal->UpdateDate) != 0)
	{
		fprintf(fp, "\t\tUpdateDate = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->UpdateDate).c_str(), boost::lexical_cast<std::string>(UpdateDate).c_str());
	}
	else
	{
		fprintf(fp, "\t\tUpdateDate = %s    [��������]\n", boost::lexical_cast<std::string>(UpdateDate).c_str());
	}
	if (compare(UpdateTime, pOriginal->UpdateTime) != 0)
	{
		fprintf(fp, "\t\tUpdateTime = %s -> %s    [����ʱ��]\n", boost::lexical_cast<std::string>(pOriginal->UpdateTime).c_str(), boost::lexical_cast<std::string>(UpdateTime).c_str());
	}
	else
	{
		fprintf(fp, "\t\tUpdateTime = %s    [����ʱ��]\n", boost::lexical_cast<std::string>(UpdateTime).c_str());
	}
	if (compare(CancelTime, pOriginal->CancelTime) != 0)
	{
		fprintf(fp, "\t\tCancelTime = %s -> %s    [����ʱ��]\n", boost::lexical_cast<std::string>(pOriginal->CancelTime).c_str(), boost::lexical_cast<std::string>(CancelTime).c_str());
	}
	else
	{
		fprintf(fp, "\t\tCancelTime = %s    [����ʱ��]\n", boost::lexical_cast<std::string>(CancelTime).c_str());
	}
	if (compare(ErrorCode, pOriginal->ErrorCode) != 0)
	{
		fprintf(fp, "\t\tErrorCode = %s -> %s    [���һ�β���������Ϣ��]\n", boost::lexical_cast<std::string>(pOriginal->ErrorCode).c_str(), boost::lexical_cast<std::string>(ErrorCode).c_str());
	}
	else
	{
		fprintf(fp, "\t\tErrorCode = %s    [���һ�β���������Ϣ��]\n", boost::lexical_cast<std::string>(ErrorCode).c_str());
	}
	if (compare(StatusMsg, pOriginal->StatusMsg) != 0)
	{
		fprintf(fp, "\t\tStatusMsg = %s -> %s    [״̬��Ϣ]\n", boost::lexical_cast<std::string>(pOriginal->StatusMsg).c_str(), boost::lexical_cast<std::string>(StatusMsg).c_str());
	}
	else
	{
		fprintf(fp, "\t\tStatusMsg = %s    [״̬��Ϣ]\n", boost::lexical_cast<std::string>(StatusMsg).c_str());
	}
	if (compare(SettlementID, pOriginal->SettlementID) != 0)
	{
		fprintf(fp, "\t\tSettlementID = %s -> %s    [������]\n", boost::lexical_cast<std::string>(pOriginal->SettlementID).c_str(), boost::lexical_cast<std::string>(SettlementID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tSettlementID = %s    [������]\n", boost::lexical_cast<std::string>(SettlementID).c_str());
	}
	if (compare(OrderSource, pOriginal->OrderSource) != 0)
	{
		fprintf(fp, "\t\tOrderSource = %s -> %s    [������Դ]\n", boost::lexical_cast<std::string>(pOriginal->OrderSource).c_str(), boost::lexical_cast<std::string>(OrderSource).c_str());
	}
	else
	{
		fprintf(fp, "\t\tOrderSource = %s    [������Դ]\n", boost::lexical_cast<std::string>(OrderSource).c_str());
	}
	if (compare(BrokerOrderSeq, pOriginal->BrokerOrderSeq) != 0)
	{
		fprintf(fp, "\t\tBrokerOrderSeq = %s -> %s    [���͹�˾�������]\n", boost::lexical_cast<std::string>(pOriginal->BrokerOrderSeq).c_str(), boost::lexical_cast<std::string>(BrokerOrderSeq).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBrokerOrderSeq = %s    [���͹�˾�������]\n", boost::lexical_cast<std::string>(BrokerOrderSeq).c_str());
	}
	if (compare(OrderRef, pOriginal->OrderRef) != 0)
	{
		fprintf(fp, "\t\tOrderRef = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->OrderRef).c_str(), boost::lexical_cast<std::string>(OrderRef).c_str());
	}
	else
	{
		fprintf(fp, "\t\tOrderRef = %s    [��������]\n", boost::lexical_cast<std::string>(OrderRef).c_str());
	}
	if (compare(FrontID, pOriginal->FrontID) != 0)
	{
		fprintf(fp, "\t\tFrontID = %s -> %s    [ǰ�ñ��]\n", boost::lexical_cast<std::string>(pOriginal->FrontID).c_str(), boost::lexical_cast<std::string>(FrontID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tFrontID = %s    [ǰ�ñ��]\n", boost::lexical_cast<std::string>(FrontID).c_str());
	}
	if (compare(SessionID, pOriginal->SessionID) != 0)
	{
		fprintf(fp, "\t\tSessionID = %s -> %s    [�Ự���]\n", boost::lexical_cast<std::string>(pOriginal->SessionID).c_str(), boost::lexical_cast<std::string>(SessionID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tSessionID = %s    [�Ự���]\n", boost::lexical_cast<std::string>(SessionID).c_str());
	}
	if (compare(TerminalID, pOriginal->TerminalID) != 0)
	{
		fprintf(fp, "\t\tTerminalID = %s -> %s    [�ն˻����]\n", boost::lexical_cast<std::string>(pOriginal->TerminalID).c_str(), boost::lexical_cast<std::string>(TerminalID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTerminalID = %s    [�ն˻����]\n", boost::lexical_cast<std::string>(TerminalID).c_str());
	}
	if (compare(TerminalType, pOriginal->TerminalType) != 0)
	{
		fprintf(fp, "\t\tTerminalType = %s -> %s    [�ն˻�����]\n", boost::lexical_cast<std::string>(pOriginal->TerminalType).c_str(), boost::lexical_cast<std::string>(TerminalType).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTerminalType = %s    [�ն˻�����]\n", boost::lexical_cast<std::string>(TerminalType).c_str());
	}
	if (compare(AppType, pOriginal->AppType) != 0)
	{
		fprintf(fp, "\t\tAppType = %s -> %s    [���׽ӿ�����]\n", boost::lexical_cast<std::string>(pOriginal->AppType).c_str(), boost::lexical_cast<std::string>(AppType).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAppType = %s    [���׽ӿ�����]\n", boost::lexical_cast<std::string>(AppType).c_str());
	}
	fprintf(fp, "\t}\n");
}

void CExchOrder::dumpInLine(FILE *fp) const
{
	if (fp == nullptr)
	{
		fp = stdout;
	}
	std::stringstream sbuf;

	sbuf << ",UserID," << UserID;
	sbuf << ",ExchangeID," << ExchangeID;
	sbuf << ",CommodityID," << CommodityID;
	sbuf << ",InstrumentID," << InstrumentID;
	sbuf << ",OrderPriceType," << OrderPriceType;
	sbuf << ",OrderMode," << OrderMode;
	sbuf << ",Direction," << Direction;
	sbuf << ",OffsetFlag," << OffsetFlag;
	sbuf << ",HedgeFlag," << HedgeFlag;
	sbuf << ",Price," << Price;
	sbuf << ",Volume," << Volume;
	sbuf << ",OrderInfo," << OrderInfo;
	sbuf << ",BrokerID," << BrokerID;
	sbuf << ",InvestorID," << InvestorID;
	sbuf << ",TimeCondition," << TimeCondition;
	sbuf << ",TradingDay," << TradingDay;
	sbuf << ",OrderInnerID," << OrderInnerID;
	sbuf << ",OrderSysID," << OrderSysID;
	sbuf << ",TradePrice," << TradePrice;
	sbuf << ",VolumeTraded," << VolumeTraded;
	sbuf << ",VolumeTotal," << VolumeTotal;
	sbuf << ",ExchangeInstID," << ExchangeInstID;
	sbuf << ",OrderSubmitStatus," << OrderSubmitStatus;
	sbuf << ",OrderState," << OrderState;
	sbuf << ",OrderStatus," << OrderStatus;
	sbuf << ",InsertDate," << InsertDate;
	sbuf << ",InsertTime," << InsertTime;
	sbuf << ",UpdateDate," << UpdateDate;
	sbuf << ",UpdateTime," << UpdateTime;
	sbuf << ",CancelTime," << CancelTime;
	sbuf << ",ErrorCode," << ErrorCode;
	sbuf << ",StatusMsg," << StatusMsg;
	sbuf << ",SettlementID," << SettlementID;
	sbuf << ",OrderSource," << OrderSource;
	sbuf << ",BrokerOrderSeq," << BrokerOrderSeq;
	sbuf << ",OrderRef," << OrderRef;
	sbuf << ",FrontID," << FrontID;
	sbuf << ",SessionID," << SessionID;
	sbuf << ",TerminalID," << TerminalID;
	sbuf << ",TerminalType," << TerminalType;
	sbuf << ",AppType," << AppType;
	fprintf(fp, "%s", sbuf.str().c_str());
}

void CExchOrder::dumpString(char *target) const
{
	char *p = target;

	std::stringstream sbuf;

	sbuf << "UserID=" << UserID << ",";
	sbuf << "ExchangeID=" << ExchangeID << ",";
	sbuf << "CommodityID=" << CommodityID << ",";
	sbuf << "InstrumentID=" << InstrumentID << ",";
	sbuf << "OrderPriceType=" << OrderPriceType << ",";
	sbuf << "OrderMode=" << OrderMode << ",";
	sbuf << "Direction=" << Direction << ",";
	sbuf << "OffsetFlag=" << OffsetFlag << ",";
	sbuf << "HedgeFlag=" << HedgeFlag << ",";
	sbuf << "Price=" << Price << ",";
	sbuf << "Volume=" << Volume << ",";
	sbuf << "OrderInfo=" << OrderInfo << ",";
	sbuf << "BrokerID=" << BrokerID << ",";
	sbuf << "InvestorID=" << InvestorID << ",";
	sbuf << "TimeCondition=" << TimeCondition << ",";
	sbuf << "TradingDay=" << TradingDay << ",";
	sbuf << "OrderInnerID=" << OrderInnerID << ",";
	sbuf << "OrderSysID=" << OrderSysID << ",";
	sbuf << "TradePrice=" << TradePrice << ",";
	sbuf << "VolumeTraded=" << VolumeTraded << ",";
	sbuf << "VolumeTotal=" << VolumeTotal << ",";
	sbuf << "ExchangeInstID=" << ExchangeInstID << ",";
	sbuf << "OrderSubmitStatus=" << OrderSubmitStatus << ",";
	sbuf << "OrderState=" << OrderState << ",";
	sbuf << "OrderStatus=" << OrderStatus << ",";
	sbuf << "InsertDate=" << InsertDate << ",";
	sbuf << "InsertTime=" << InsertTime << ",";
	sbuf << "UpdateDate=" << UpdateDate << ",";
	sbuf << "UpdateTime=" << UpdateTime << ",";
	sbuf << "CancelTime=" << CancelTime << ",";
	sbuf << "ErrorCode=" << ErrorCode << ",";
	sbuf << "StatusMsg=" << StatusMsg << ",";
	sbuf << "SettlementID=" << SettlementID << ",";
	sbuf << "OrderSource=" << OrderSource << ",";
	sbuf << "BrokerOrderSeq=" << BrokerOrderSeq << ",";
	sbuf << "OrderRef=" << OrderRef << ",";
	sbuf << "FrontID=" << FrontID << ",";
	sbuf << "SessionID=" << SessionID << ",";
	sbuf << "TerminalID=" << TerminalID << ",";
	sbuf << "TerminalType=" << TerminalType << ",";
	sbuf << "AppType=" << AppType << ",";

	sprintf(p, "%s", sbuf.str().c_str());
}

void CExchTrade::init(void)
{
	memset(this, 0, sizeof(CExchTrade));
}

int CExchTrade::read(FILE *input)
{
	if (fread(this, 1, sizeof(CExchTrade), input) != sizeof(CExchTrade))
		return 0;
	else
		return 1;
}

int CExchTrade::write(FILE *output) const
{
	if (fwrite(this, 1, sizeof(CExchTrade), output) != sizeof(CExchTrade))
		return 0;
	else
		return 1;
}

void CExchTrade::dump(FILE *fp, int index) const
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
	fprintf(fp, "\tCExchTrade%s = {\n", index_buf);
	fprintf(fp, "\t\tExchangeID = %s    [����������]\n", boost::lexical_cast<std::string>(ExchangeID).c_str());
	fprintf(fp, "\t\tTradingDay = %s    [������]\n", boost::lexical_cast<std::string>(TradingDay).c_str());
	fprintf(fp, "\t\tTradeID = %s    [�ɽ���]\n", boost::lexical_cast<std::string>(TradeID).c_str());
	fprintf(fp, "\t\tOrderSysID = %s    [�������]\n", boost::lexical_cast<std::string>(OrderSysID).c_str());
	fprintf(fp, "\t\tOrderInnerID = %s    [ϵͳ�ڲ�����(�ַ���)]\n", boost::lexical_cast<std::string>(OrderInnerID).c_str());
	fprintf(fp, "\t\tCommodityID = %s    [��Ʒ����]\n", boost::lexical_cast<std::string>(CommodityID).c_str());
	fprintf(fp, "\t\tInstrumentID = %s    [��Լ����]\n", boost::lexical_cast<std::string>(InstrumentID).c_str());
	fprintf(fp, "\t\tUserID = %s    [����Ա����]\n", boost::lexical_cast<std::string>(UserID).c_str());
	fprintf(fp, "\t\tDirection = %s    [��������]\n", boost::lexical_cast<std::string>(Direction).c_str());
	fprintf(fp, "\t\tOffsetFlag = %s    [����ƽ��]\n", boost::lexical_cast<std::string>(OffsetFlag).c_str());
	fprintf(fp, "\t\tTradePrice = %s    [�ɽ���]\n", boost::lexical_cast<std::string>(TradePrice).c_str());
	fprintf(fp, "\t\tVolumeTraded = %s    [�ɽ�����]\n", boost::lexical_cast<std::string>(VolumeTraded).c_str());
	fprintf(fp, "\t\tTradeDate = %s    [�ɽ�����]\n", boost::lexical_cast<std::string>(TradeDate).c_str());
	fprintf(fp, "\t\tTradeTime = %s    [�ɽ�ʱ��]\n", boost::lexical_cast<std::string>(TradeTime).c_str());
	fprintf(fp, "\t\tTradeFee = %s    [������]\n", boost::lexical_cast<std::string>(TradeFee).c_str());
	fprintf(fp, "\t\tCurrencyID = %s    [�����ѱ���]\n", boost::lexical_cast<std::string>(CurrencyID).c_str());
	fprintf(fp, "\t\tManualFee = %s    [�ֹ�������]\n", boost::lexical_cast<std::string>(ManualFee).c_str());
	fprintf(fp, "\t\tDeleted = %s    [ɾ����־]\n", boost::lexical_cast<std::string>(Deleted).c_str());
	fprintf(fp, "\t\tCoverPrice = %s    [ƽ�ּ۸�]\n", boost::lexical_cast<std::string>(CoverPrice).c_str());
	fprintf(fp, "\t\tExchangeInstID = %s    [��Լ�ڽ������Ĵ���]\n", boost::lexical_cast<std::string>(ExchangeInstID).c_str());
	fprintf(fp, "\t\tBrokerID = %s    [���ͻ�Ա����]\n", boost::lexical_cast<std::string>(BrokerID).c_str());
	fprintf(fp, "\t\tInvestorID = %s    [Ͷ���ߴ���]\n", boost::lexical_cast<std::string>(InvestorID).c_str());
	fprintf(fp, "\t\tOrderRef = %s    [��������]\n", boost::lexical_cast<std::string>(OrderRef).c_str());
	fprintf(fp, "\t\tHedgeFlag = %s    [Ͷ����ֵ]\n", boost::lexical_cast<std::string>(HedgeFlag).c_str());
	fprintf(fp, "\t}\n");
}

void CExchTrade::dumpDiff(FILE *fp, const CExchTrade *pOriginal) const
{
	if (fp == nullptr)
	{
		fp = stdout;
	}
	fprintf(fp, "\tCExchTrade = {\n");
	if (compare(ExchangeID, pOriginal->ExchangeID) != 0)
	{
		fprintf(fp, "\t\tExchangeID = %s -> %s    [����������]\n", boost::lexical_cast<std::string>(pOriginal->ExchangeID).c_str(), boost::lexical_cast<std::string>(ExchangeID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tExchangeID = %s    [����������]\n", boost::lexical_cast<std::string>(ExchangeID).c_str());
	}
	if (compare(TradingDay, pOriginal->TradingDay) != 0)
	{
		fprintf(fp, "\t\tTradingDay = %s -> %s    [������]\n", boost::lexical_cast<std::string>(pOriginal->TradingDay).c_str(), boost::lexical_cast<std::string>(TradingDay).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTradingDay = %s    [������]\n", boost::lexical_cast<std::string>(TradingDay).c_str());
	}
	if (compare(TradeID, pOriginal->TradeID) != 0)
	{
		fprintf(fp, "\t\tTradeID = %s -> %s    [�ɽ���]\n", boost::lexical_cast<std::string>(pOriginal->TradeID).c_str(), boost::lexical_cast<std::string>(TradeID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTradeID = %s    [�ɽ���]\n", boost::lexical_cast<std::string>(TradeID).c_str());
	}
	if (compare(OrderSysID, pOriginal->OrderSysID) != 0)
	{
		fprintf(fp, "\t\tOrderSysID = %s -> %s    [�������]\n", boost::lexical_cast<std::string>(pOriginal->OrderSysID).c_str(), boost::lexical_cast<std::string>(OrderSysID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tOrderSysID = %s    [�������]\n", boost::lexical_cast<std::string>(OrderSysID).c_str());
	}
	if (compare(OrderInnerID, pOriginal->OrderInnerID) != 0)
	{
		fprintf(fp, "\t\tOrderInnerID = %s -> %s    [ϵͳ�ڲ�����(�ַ���)]\n", boost::lexical_cast<std::string>(pOriginal->OrderInnerID).c_str(), boost::lexical_cast<std::string>(OrderInnerID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tOrderInnerID = %s    [ϵͳ�ڲ�����(�ַ���)]\n", boost::lexical_cast<std::string>(OrderInnerID).c_str());
	}
	if (compare(CommodityID, pOriginal->CommodityID) != 0)
	{
		fprintf(fp, "\t\tCommodityID = %s -> %s    [��Ʒ����]\n", boost::lexical_cast<std::string>(pOriginal->CommodityID).c_str(), boost::lexical_cast<std::string>(CommodityID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tCommodityID = %s    [��Ʒ����]\n", boost::lexical_cast<std::string>(CommodityID).c_str());
	}
	if (compare(InstrumentID, pOriginal->InstrumentID) != 0)
	{
		fprintf(fp, "\t\tInstrumentID = %s -> %s    [��Լ����]\n", boost::lexical_cast<std::string>(pOriginal->InstrumentID).c_str(), boost::lexical_cast<std::string>(InstrumentID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tInstrumentID = %s    [��Լ����]\n", boost::lexical_cast<std::string>(InstrumentID).c_str());
	}
	if (compare(UserID, pOriginal->UserID) != 0)
	{
		fprintf(fp, "\t\tUserID = %s -> %s    [����Ա����]\n", boost::lexical_cast<std::string>(pOriginal->UserID).c_str(), boost::lexical_cast<std::string>(UserID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tUserID = %s    [����Ա����]\n", boost::lexical_cast<std::string>(UserID).c_str());
	}
	if (compare(Direction, pOriginal->Direction) != 0)
	{
		fprintf(fp, "\t\tDirection = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->Direction).c_str(), boost::lexical_cast<std::string>(Direction).c_str());
	}
	else
	{
		fprintf(fp, "\t\tDirection = %s    [��������]\n", boost::lexical_cast<std::string>(Direction).c_str());
	}
	if (compare(OffsetFlag, pOriginal->OffsetFlag) != 0)
	{
		fprintf(fp, "\t\tOffsetFlag = %s -> %s    [����ƽ��]\n", boost::lexical_cast<std::string>(pOriginal->OffsetFlag).c_str(), boost::lexical_cast<std::string>(OffsetFlag).c_str());
	}
	else
	{
		fprintf(fp, "\t\tOffsetFlag = %s    [����ƽ��]\n", boost::lexical_cast<std::string>(OffsetFlag).c_str());
	}
	if (compare(TradePrice, pOriginal->TradePrice) != 0)
	{
		fprintf(fp, "\t\tTradePrice = %s -> %s    [�ɽ���]\n", boost::lexical_cast<std::string>(pOriginal->TradePrice).c_str(), boost::lexical_cast<std::string>(TradePrice).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTradePrice = %s    [�ɽ���]\n", boost::lexical_cast<std::string>(TradePrice).c_str());
	}
	if (compare(VolumeTraded, pOriginal->VolumeTraded) != 0)
	{
		fprintf(fp, "\t\tVolumeTraded = %s -> %s    [�ɽ�����]\n", boost::lexical_cast<std::string>(pOriginal->VolumeTraded).c_str(), boost::lexical_cast<std::string>(VolumeTraded).c_str());
	}
	else
	{
		fprintf(fp, "\t\tVolumeTraded = %s    [�ɽ�����]\n", boost::lexical_cast<std::string>(VolumeTraded).c_str());
	}
	if (compare(TradeDate, pOriginal->TradeDate) != 0)
	{
		fprintf(fp, "\t\tTradeDate = %s -> %s    [�ɽ�����]\n", boost::lexical_cast<std::string>(pOriginal->TradeDate).c_str(), boost::lexical_cast<std::string>(TradeDate).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTradeDate = %s    [�ɽ�����]\n", boost::lexical_cast<std::string>(TradeDate).c_str());
	}
	if (compare(TradeTime, pOriginal->TradeTime) != 0)
	{
		fprintf(fp, "\t\tTradeTime = %s -> %s    [�ɽ�ʱ��]\n", boost::lexical_cast<std::string>(pOriginal->TradeTime).c_str(), boost::lexical_cast<std::string>(TradeTime).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTradeTime = %s    [�ɽ�ʱ��]\n", boost::lexical_cast<std::string>(TradeTime).c_str());
	}
	if (compare(TradeFee, pOriginal->TradeFee) != 0)
	{
		fprintf(fp, "\t\tTradeFee = %s -> %s    [������]\n", boost::lexical_cast<std::string>(pOriginal->TradeFee).c_str(), boost::lexical_cast<std::string>(TradeFee).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTradeFee = %s    [������]\n", boost::lexical_cast<std::string>(TradeFee).c_str());
	}
	if (compare(CurrencyID, pOriginal->CurrencyID) != 0)
	{
		fprintf(fp, "\t\tCurrencyID = %s -> %s    [�����ѱ���]\n", boost::lexical_cast<std::string>(pOriginal->CurrencyID).c_str(), boost::lexical_cast<std::string>(CurrencyID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tCurrencyID = %s    [�����ѱ���]\n", boost::lexical_cast<std::string>(CurrencyID).c_str());
	}
	if (compare(ManualFee, pOriginal->ManualFee) != 0)
	{
		fprintf(fp, "\t\tManualFee = %s -> %s    [�ֹ�������]\n", boost::lexical_cast<std::string>(pOriginal->ManualFee).c_str(), boost::lexical_cast<std::string>(ManualFee).c_str());
	}
	else
	{
		fprintf(fp, "\t\tManualFee = %s    [�ֹ�������]\n", boost::lexical_cast<std::string>(ManualFee).c_str());
	}
	if (compare(Deleted, pOriginal->Deleted) != 0)
	{
		fprintf(fp, "\t\tDeleted = %s -> %s    [ɾ����־]\n", boost::lexical_cast<std::string>(pOriginal->Deleted).c_str(), boost::lexical_cast<std::string>(Deleted).c_str());
	}
	else
	{
		fprintf(fp, "\t\tDeleted = %s    [ɾ����־]\n", boost::lexical_cast<std::string>(Deleted).c_str());
	}
	if (compare(CoverPrice, pOriginal->CoverPrice) != 0)
	{
		fprintf(fp, "\t\tCoverPrice = %s -> %s    [ƽ�ּ۸�]\n", boost::lexical_cast<std::string>(pOriginal->CoverPrice).c_str(), boost::lexical_cast<std::string>(CoverPrice).c_str());
	}
	else
	{
		fprintf(fp, "\t\tCoverPrice = %s    [ƽ�ּ۸�]\n", boost::lexical_cast<std::string>(CoverPrice).c_str());
	}
	if (compare(ExchangeInstID, pOriginal->ExchangeInstID) != 0)
	{
		fprintf(fp, "\t\tExchangeInstID = %s -> %s    [��Լ�ڽ������Ĵ���]\n", boost::lexical_cast<std::string>(pOriginal->ExchangeInstID).c_str(), boost::lexical_cast<std::string>(ExchangeInstID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tExchangeInstID = %s    [��Լ�ڽ������Ĵ���]\n", boost::lexical_cast<std::string>(ExchangeInstID).c_str());
	}
	if (compare(BrokerID, pOriginal->BrokerID) != 0)
	{
		fprintf(fp, "\t\tBrokerID = %s -> %s    [���ͻ�Ա����]\n", boost::lexical_cast<std::string>(pOriginal->BrokerID).c_str(), boost::lexical_cast<std::string>(BrokerID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBrokerID = %s    [���ͻ�Ա����]\n", boost::lexical_cast<std::string>(BrokerID).c_str());
	}
	if (compare(InvestorID, pOriginal->InvestorID) != 0)
	{
		fprintf(fp, "\t\tInvestorID = %s -> %s    [Ͷ���ߴ���]\n", boost::lexical_cast<std::string>(pOriginal->InvestorID).c_str(), boost::lexical_cast<std::string>(InvestorID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tInvestorID = %s    [Ͷ���ߴ���]\n", boost::lexical_cast<std::string>(InvestorID).c_str());
	}
	if (compare(OrderRef, pOriginal->OrderRef) != 0)
	{
		fprintf(fp, "\t\tOrderRef = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->OrderRef).c_str(), boost::lexical_cast<std::string>(OrderRef).c_str());
	}
	else
	{
		fprintf(fp, "\t\tOrderRef = %s    [��������]\n", boost::lexical_cast<std::string>(OrderRef).c_str());
	}
	if (compare(HedgeFlag, pOriginal->HedgeFlag) != 0)
	{
		fprintf(fp, "\t\tHedgeFlag = %s -> %s    [Ͷ����ֵ]\n", boost::lexical_cast<std::string>(pOriginal->HedgeFlag).c_str(), boost::lexical_cast<std::string>(HedgeFlag).c_str());
	}
	else
	{
		fprintf(fp, "\t\tHedgeFlag = %s    [Ͷ����ֵ]\n", boost::lexical_cast<std::string>(HedgeFlag).c_str());
	}
	fprintf(fp, "\t}\n");
}

void CExchTrade::dumpInLine(FILE *fp) const
{
	if (fp == nullptr)
	{
		fp = stdout;
	}
	std::stringstream sbuf;

	sbuf << ",ExchangeID," << ExchangeID;
	sbuf << ",TradingDay," << TradingDay;
	sbuf << ",TradeID," << TradeID;
	sbuf << ",OrderSysID," << OrderSysID;
	sbuf << ",OrderInnerID," << OrderInnerID;
	sbuf << ",CommodityID," << CommodityID;
	sbuf << ",InstrumentID," << InstrumentID;
	sbuf << ",UserID," << UserID;
	sbuf << ",Direction," << Direction;
	sbuf << ",OffsetFlag," << OffsetFlag;
	sbuf << ",TradePrice," << TradePrice;
	sbuf << ",VolumeTraded," << VolumeTraded;
	sbuf << ",TradeDate," << TradeDate;
	sbuf << ",TradeTime," << TradeTime;
	sbuf << ",TradeFee," << TradeFee;
	sbuf << ",CurrencyID," << CurrencyID;
	sbuf << ",ManualFee," << ManualFee;
	sbuf << ",Deleted," << Deleted;
	sbuf << ",CoverPrice," << CoverPrice;
	sbuf << ",ExchangeInstID," << ExchangeInstID;
	sbuf << ",BrokerID," << BrokerID;
	sbuf << ",InvestorID," << InvestorID;
	sbuf << ",OrderRef," << OrderRef;
	sbuf << ",HedgeFlag," << HedgeFlag;
	fprintf(fp, "%s", sbuf.str().c_str());
}

void CExchTrade::dumpString(char *target) const
{
	char *p = target;
	std::stringstream sbuf;

	sbuf << "ExchangeID=" << ExchangeID << ",";
	sbuf << "TradingDay=" << TradingDay << ",";
	sbuf << "TradeID=" << TradeID << ",";
	sbuf << "OrderSysID=" << OrderSysID << ",";
	sbuf << "OrderInnerID=" << OrderInnerID << ",";
	sbuf << "CommodityID=" << CommodityID << ",";
	sbuf << "InstrumentID=" << InstrumentID << ",";
	sbuf << "UserID=" << UserID << ",";
	sbuf << "Direction=" << Direction << ",";
	sbuf << "OffsetFlag=" << OffsetFlag << ",";
	sbuf << "TradePrice=" << TradePrice << ",";
	sbuf << "VolumeTraded=" << VolumeTraded << ",";
	sbuf << "TradeDate=" << TradeDate << ",";
	sbuf << "TradeTime=" << TradeTime << ",";
	sbuf << "TradeFee=" << TradeFee << ",";
	sbuf << "CurrencyID=" << CurrencyID << ",";
	sbuf << "ManualFee=" << ManualFee << ",";
	sbuf << "Deleted=" << Deleted << ",";
	sbuf << "CoverPrice=" << CoverPrice << ",";
	sbuf << "ExchangeInstID=" << ExchangeInstID << ",";
	sbuf << "BrokerID=" << BrokerID << ",";
	sbuf << "InvestorID=" << InvestorID << ",";
	sbuf << "OrderRef=" << OrderRef << ",";
	sbuf << "HedgeFlag=" << HedgeFlag << ",";

	sprintf(p, "%s", sbuf.str().c_str());
}

void CExchInvestorPosition::init(void)
{
	memset(this, 0, sizeof(CExchInvestorPosition));
}

int CExchInvestorPosition::read(FILE *input)
{
	if (fread(this, 1, sizeof(CExchInvestorPosition), input) != sizeof(CExchInvestorPosition))
		return 0;
	else
		return 1;
}

int CExchInvestorPosition::write(FILE *output) const
{
	if (fwrite(this, 1, sizeof(CExchInvestorPosition), output) != sizeof(CExchInvestorPosition))
		return 0;
	else
		return 1;
}

void CExchInvestorPosition::dump(FILE *fp, int index) const
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
	fprintf(fp, "\tCExchInvestorPosition%s = {\n", index_buf);
	fprintf(fp, "\t\tInvestorID = %s    [Ͷ���߱��]\n", boost::lexical_cast<std::string>(InvestorID).c_str());
	fprintf(fp, "\t\tBrokerID = %s    [���͹�˾����]\n", boost::lexical_cast<std::string>(BrokerID).c_str());
	fprintf(fp, "\t\tExchangeID = %s    [����������]\n", boost::lexical_cast<std::string>(ExchangeID).c_str());
	fprintf(fp, "\t\tClientID = %s    [�ͻ�����]\n", boost::lexical_cast<std::string>(ClientID).c_str());
	fprintf(fp, "\t\tInstrumentID = %s    [��Լ����]\n", boost::lexical_cast<std::string>(InstrumentID).c_str());
	fprintf(fp, "\t\tDirection = %s    [��������]\n", boost::lexical_cast<std::string>(Direction).c_str());
	fprintf(fp, "\t\tHedgeFlag = %s    [Ͷ���ױ���־]\n", boost::lexical_cast<std::string>(HedgeFlag).c_str());
	fprintf(fp, "\t\tUsedMargin = %s    [ռ�ñ�֤��]\n", boost::lexical_cast<std::string>(UsedMargin).c_str());
	fprintf(fp, "\t\tPosition = %s    [��ֲ���]\n", boost::lexical_cast<std::string>(Position).c_str());
	fprintf(fp, "\t\tPositionCost = %s    [���ճֲֳɱ�]\n", boost::lexical_cast<std::string>(PositionCost).c_str());
	fprintf(fp, "\t\tYdPosition = %s    [��ֲ���]\n", boost::lexical_cast<std::string>(YdPosition).c_str());
	fprintf(fp, "\t\tYdPositionCost = %s    [���ճֲֳɱ�]\n", boost::lexical_cast<std::string>(YdPositionCost).c_str());
	fprintf(fp, "\t\tFrozenMargin = %s    [����ı�֤��]\n", boost::lexical_cast<std::string>(FrozenMargin).c_str());
	fprintf(fp, "\t\tFrozenPosition = %s    [���ֶ���ֲ�]\n", boost::lexical_cast<std::string>(FrozenPosition).c_str());
	fprintf(fp, "\t\tFrozenClosing = %s    [ƽ�ֶ���ֲ�]\n", boost::lexical_cast<std::string>(FrozenClosing).c_str());
	fprintf(fp, "\t\tFrozenPremium = %s    [�����Ȩ����]\n", boost::lexical_cast<std::string>(FrozenPremium).c_str());
	fprintf(fp, "\t\tLastTradeID = %s    [���һ�ʳɽ����]\n", boost::lexical_cast<std::string>(LastTradeID).c_str());
	fprintf(fp, "\t\tLastOrderLocalID = %s    [���һ�ʱ��ر������]\n", boost::lexical_cast<std::string>(LastOrderLocalID).c_str());
	fprintf(fp, "\t\tCurrency = %s    [����]\n", boost::lexical_cast<std::string>(Currency).c_str());
	fprintf(fp, "\t}\n");
}

void CExchInvestorPosition::dumpDiff(FILE *fp, const CExchInvestorPosition *pOriginal) const
{
	if (fp == NULL)
	{
		fp = stdout;
	}
	fprintf(fp, "\tCExchInvestorPosition = {\n");
	if (compare(InvestorID, pOriginal->InvestorID) != 0)
	{
		fprintf(fp, "\t\tInvestorID = %s -> %s    [Ͷ���߱��]\n", boost::lexical_cast<std::string>(pOriginal->InvestorID).c_str(), boost::lexical_cast<std::string>(InvestorID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tInvestorID = %s    [Ͷ���߱��]\n", boost::lexical_cast<std::string>(InvestorID).c_str());
	}
	if (compare(BrokerID, pOriginal->BrokerID) != 0)
	{
		fprintf(fp, "\t\tBrokerID = %s -> %s    [���͹�˾����]\n", boost::lexical_cast<std::string>(pOriginal->BrokerID).c_str(), boost::lexical_cast<std::string>(BrokerID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBrokerID = %s    [���͹�˾����]\n", boost::lexical_cast<std::string>(BrokerID).c_str());
	}
	if (compare(ExchangeID, pOriginal->ExchangeID) != 0)
	{
		fprintf(fp, "\t\tExchangeID = %s -> %s    [����������]\n", boost::lexical_cast<std::string>(pOriginal->ExchangeID).c_str(), boost::lexical_cast<std::string>(ExchangeID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tExchangeID = %s    [����������]\n", boost::lexical_cast<std::string>(ExchangeID).c_str());
	}
	if (compare(ClientID, pOriginal->ClientID) != 0)
	{
		fprintf(fp, "\t\tClientID = %s -> %s    [�ͻ�����]\n", boost::lexical_cast<std::string>(pOriginal->ClientID).c_str(), boost::lexical_cast<std::string>(ClientID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tClientID = %s    [�ͻ�����]\n", boost::lexical_cast<std::string>(ClientID).c_str());
	}
	if (compare(InstrumentID, pOriginal->InstrumentID) != 0)
	{
		fprintf(fp, "\t\tInstrumentID = %s -> %s    [��Լ����]\n", boost::lexical_cast<std::string>(pOriginal->InstrumentID).c_str(), boost::lexical_cast<std::string>(InstrumentID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tInstrumentID = %s    [��Լ����]\n", boost::lexical_cast<std::string>(InstrumentID).c_str());
	}
	if (compare(Direction, pOriginal->Direction) != 0)
	{
		fprintf(fp, "\t\tDirection = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->Direction).c_str(), boost::lexical_cast<std::string>(Direction).c_str());
	}
	else
	{
		fprintf(fp, "\t\tDirection = %s    [��������]\n", boost::lexical_cast<std::string>(Direction).c_str());
	}
	if (compare(HedgeFlag, pOriginal->HedgeFlag) != 0)
	{
		fprintf(fp, "\t\tHedgeFlag = %s -> %s    [Ͷ���ױ���־]\n", boost::lexical_cast<std::string>(pOriginal->HedgeFlag).c_str(), boost::lexical_cast<std::string>(HedgeFlag).c_str());
	}
	else
	{
		fprintf(fp, "\t\tHedgeFlag = %s    [Ͷ���ױ���־]\n", boost::lexical_cast<std::string>(HedgeFlag).c_str());
	}
	if (compare(UsedMargin, pOriginal->UsedMargin) != 0)
	{
		fprintf(fp, "\t\tUsedMargin = %s -> %s    [ռ�ñ�֤��]\n", boost::lexical_cast<std::string>(pOriginal->UsedMargin).c_str(), boost::lexical_cast<std::string>(UsedMargin).c_str());
	}
	else
	{
		fprintf(fp, "\t\tUsedMargin = %s    [ռ�ñ�֤��]\n", boost::lexical_cast<std::string>(UsedMargin).c_str());
	}
	if (compare(Position, pOriginal->Position) != 0)
	{
		fprintf(fp, "\t\tPosition = %s -> %s    [��ֲ���]\n", boost::lexical_cast<std::string>(pOriginal->Position).c_str(), boost::lexical_cast<std::string>(Position).c_str());
	}
	else
	{
		fprintf(fp, "\t\tPosition = %s    [��ֲ���]\n", boost::lexical_cast<std::string>(Position).c_str());
	}
	if (compare(PositionCost, pOriginal->PositionCost) != 0)
	{
		fprintf(fp, "\t\tPositionCost = %s -> %s    [���ճֲֳɱ�]\n", boost::lexical_cast<std::string>(pOriginal->PositionCost).c_str(), boost::lexical_cast<std::string>(PositionCost).c_str());
	}
	else
	{
		fprintf(fp, "\t\tPositionCost = %s    [���ճֲֳɱ�]\n", boost::lexical_cast<std::string>(PositionCost).c_str());
	}
	if (compare(YdPosition, pOriginal->YdPosition) != 0)
	{
		fprintf(fp, "\t\tYdPosition = %s -> %s    [��ֲ���]\n", boost::lexical_cast<std::string>(pOriginal->YdPosition).c_str(), boost::lexical_cast<std::string>(YdPosition).c_str());
	}
	else
	{
		fprintf(fp, "\t\tYdPosition = %s    [��ֲ���]\n", boost::lexical_cast<std::string>(YdPosition).c_str());
	}
	if (compare(YdPositionCost, pOriginal->YdPositionCost) != 0)
	{
		fprintf(fp, "\t\tYdPositionCost = %s -> %s    [���ճֲֳɱ�]\n", boost::lexical_cast<std::string>(pOriginal->YdPositionCost).c_str(), boost::lexical_cast<std::string>(YdPositionCost).c_str());
	}
	else
	{
		fprintf(fp, "\t\tYdPositionCost = %s    [���ճֲֳɱ�]\n", boost::lexical_cast<std::string>(YdPositionCost).c_str());
	}
	if (compare(FrozenMargin, pOriginal->FrozenMargin) != 0)
	{
		fprintf(fp, "\t\tFrozenMargin = %s -> %s    [����ı�֤��]\n", boost::lexical_cast<std::string>(pOriginal->FrozenMargin).c_str(), boost::lexical_cast<std::string>(FrozenMargin).c_str());
	}
	else
	{
		fprintf(fp, "\t\tFrozenMargin = %s    [����ı�֤��]\n", boost::lexical_cast<std::string>(FrozenMargin).c_str());
	}
	if (compare(FrozenPosition, pOriginal->FrozenPosition) != 0)
	{
		fprintf(fp, "\t\tFrozenPosition = %s -> %s    [���ֶ���ֲ�]\n", boost::lexical_cast<std::string>(pOriginal->FrozenPosition).c_str(), boost::lexical_cast<std::string>(FrozenPosition).c_str());
	}
	else
	{
		fprintf(fp, "\t\tFrozenPosition = %s    [���ֶ���ֲ�]\n", boost::lexical_cast<std::string>(FrozenPosition).c_str());
	}
	if (compare(FrozenClosing, pOriginal->FrozenClosing) != 0)
	{
		fprintf(fp, "\t\tFrozenClosing = %s -> %s    [ƽ�ֶ���ֲ�]\n", boost::lexical_cast<std::string>(pOriginal->FrozenClosing).c_str(), boost::lexical_cast<std::string>(FrozenClosing).c_str());
	}
	else
	{
		fprintf(fp, "\t\tFrozenClosing = %s    [ƽ�ֶ���ֲ�]\n", boost::lexical_cast<std::string>(FrozenClosing).c_str());
	}
	if (compare(FrozenPremium, pOriginal->FrozenPremium) != 0)
	{
		fprintf(fp, "\t\tFrozenPremium = %s -> %s    [�����Ȩ����]\n", boost::lexical_cast<std::string>(pOriginal->FrozenPremium).c_str(), boost::lexical_cast<std::string>(FrozenPremium).c_str());
	}
	else
	{
		fprintf(fp, "\t\tFrozenPremium = %s    [�����Ȩ����]\n", boost::lexical_cast<std::string>(FrozenPremium).c_str());
	}
	if (compare(LastTradeID, pOriginal->LastTradeID) != 0)
	{
		fprintf(fp, "\t\tLastTradeID = %s -> %s    [���һ�ʳɽ����]\n", boost::lexical_cast<std::string>(pOriginal->LastTradeID).c_str(), boost::lexical_cast<std::string>(LastTradeID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tLastTradeID = %s    [���һ�ʳɽ����]\n", boost::lexical_cast<std::string>(LastTradeID).c_str());
	}
	if (compare(LastOrderLocalID, pOriginal->LastOrderLocalID) != 0)
	{
		fprintf(fp, "\t\tLastOrderLocalID = %s -> %s    [���һ�ʱ��ر������]\n", boost::lexical_cast<std::string>(pOriginal->LastOrderLocalID).c_str(), boost::lexical_cast<std::string>(LastOrderLocalID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tLastOrderLocalID = %s    [���һ�ʱ��ر������]\n", boost::lexical_cast<std::string>(LastOrderLocalID).c_str());
	}
	if (compare(Currency, pOriginal->Currency) != 0)
	{
		fprintf(fp, "\t\tCurrency = %s -> %s    [����]\n", boost::lexical_cast<std::string>(pOriginal->Currency).c_str(), boost::lexical_cast<std::string>(Currency).c_str());
	}
	else
	{
		fprintf(fp, "\t\tCurrency = %s    [����]\n", boost::lexical_cast<std::string>(Currency).c_str());
	}
	fprintf(fp, "\t}\n");
}

void CExchInvestorPosition::dumpInLine(FILE *fp) const
{
	if (fp == nullptr)
	{
		fp = stdout;
	}
	std::stringstream sbuf;

	sbuf << ",InvestorID," << InvestorID;
	sbuf << ",BrokerID," << BrokerID;
	sbuf << ",ExchangeID," << ExchangeID;
	sbuf << ",ClientID," << ClientID;
	sbuf << ",InstrumentID," << InstrumentID;
	sbuf << ",Direction," << Direction;
	sbuf << ",HedgeFlag," << HedgeFlag;
	sbuf << ",UsedMargin," << UsedMargin;
	sbuf << ",Position," << Position;
	sbuf << ",PositionCost," << PositionCost;
	sbuf << ",YdPosition," << YdPosition;
	sbuf << ",YdPositionCost," << YdPositionCost;
	sbuf << ",FrozenMargin," << FrozenMargin;
	sbuf << ",FrozenPosition," << FrozenPosition;
	sbuf << ",FrozenClosing," << FrozenClosing;
	sbuf << ",FrozenPremium," << FrozenPremium;
	sbuf << ",LastTradeID," << LastTradeID;
	sbuf << ",LastOrderLocalID," << LastOrderLocalID;
	sbuf << ",Currency," << Currency;
	fprintf(fp, "%s", sbuf.str().c_str());
}

void CExchInvestorPosition::dumpString(char *target) const
{
	char *p = target;
	std::stringstream sbuf;

	sbuf << "InvestorID=" << InvestorID << ",";
	sbuf << "BrokerID=" << BrokerID << ",";
	sbuf << "ExchangeID=" << ExchangeID << ",";
	sbuf << "ClientID=" << ClientID << ",";
	sbuf << "InstrumentID=" << InstrumentID << ",";
	sbuf << "Direction=" << Direction << ",";
	sbuf << "HedgeFlag=" << HedgeFlag << ",";
	sbuf << "UsedMargin=" << UsedMargin << ",";
	sbuf << "Position=" << Position << ",";
	sbuf << "PositionCost=" << PositionCost << ",";
	sbuf << "YdPosition=" << YdPosition << ",";
	sbuf << "YdPositionCost=" << YdPositionCost << ",";
	sbuf << "FrozenMargin=" << FrozenMargin << ",";
	sbuf << "FrozenPosition=" << FrozenPosition << ",";
	sbuf << "FrozenClosing=" << FrozenClosing << ",";
	sbuf << "FrozenPremium=" << FrozenPremium << ",";
	sbuf << "LastTradeID=" << LastTradeID << ",";
	sbuf << "LastOrderLocalID=" << LastOrderLocalID << ",";
	sbuf << "Currency=" << Currency << ",";

	sprintf(p, "%s", sbuf.str().c_str());
}

void CExchInvestorAccount::init(void)
{
	memset(this, 0, sizeof(CExchInvestorAccount));
}

int CExchInvestorAccount::read(FILE *input)
{
	if (fread(this, 1, sizeof(CExchInvestorAccount), input) != sizeof(CExchInvestorAccount))
		return 0;
	else
		return 1;
}

int CExchInvestorAccount::write(FILE *output) const
{
	if (fwrite(this, 1, sizeof(CExchInvestorAccount), output) != sizeof(CExchInvestorAccount))
		return 0;
	else
		return 1;
}

void CExchInvestorAccount::dump(FILE *fp, int index) const
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

	fprintf(fp, "\tCExchInvestorAccount%s = {\n", index_buf);
	fprintf(fp, "\t\tBrokerID = %s    [���͹�˾����]\n", boost::lexical_cast<std::string>(BrokerID).c_str());
	fprintf(fp, "\t\tInvestorID = %s    [Ͷ���ߴ���]\n", boost::lexical_cast<std::string>(InvestorID).c_str());
	fprintf(fp, "\t\tAccountID = %s    [�ʽ��ʺ�]\n", boost::lexical_cast<std::string>(AccountID).c_str());
	fprintf(fp, "\t\tPreBalance = %s    [�ϴν���׼����]\n", boost::lexical_cast<std::string>(PreBalance).c_str());
	fprintf(fp, "\t\tDeposit = %s    [�����]\n", boost::lexical_cast<std::string>(Deposit).c_str());
	fprintf(fp, "\t\tWithdraw = %s    [������]\n", boost::lexical_cast<std::string>(Withdraw).c_str());
	fprintf(fp, "\t\tFrozenMargin = %s    [����ı�֤��]\n", boost::lexical_cast<std::string>(FrozenMargin).c_str());
	fprintf(fp, "\t\tFrozenFee = %s    [����������]\n", boost::lexical_cast<std::string>(FrozenFee).c_str());
	fprintf(fp, "\t\tFrozenPremium = %s    [����Ȩ����]\n", boost::lexical_cast<std::string>(FrozenPremium).c_str());
	fprintf(fp, "\t\tFee = %s    [������]\n", boost::lexical_cast<std::string>(Fee).c_str());
	fprintf(fp, "\t\tCloseProfit = %s    [ƽ��ӯ��]\n", boost::lexical_cast<std::string>(CloseProfit).c_str());
	fprintf(fp, "\t\tPositionProfit = %s    [�ֲ�ӯ��]\n", boost::lexical_cast<std::string>(PositionProfit).c_str());
	fprintf(fp, "\t\tAvailable = %s    [�����ʽ�]\n", boost::lexical_cast<std::string>(Available).c_str());
	fprintf(fp, "\t\tLongFrozenMargin = %s    [��ͷ����ı�֤��]\n", boost::lexical_cast<std::string>(LongFrozenMargin).c_str());
	fprintf(fp, "\t\tShortFrozenMargin = %s    [��ͷ����ı�֤��]\n", boost::lexical_cast<std::string>(ShortFrozenMargin).c_str());
	fprintf(fp, "\t\tLongMargin = %s    [��ͷռ�ñ�֤��]\n", boost::lexical_cast<std::string>(LongMargin).c_str());
	fprintf(fp, "\t\tShortMargin = %s    [��ͷռ�ñ�֤��]\n", boost::lexical_cast<std::string>(ShortMargin).c_str());
	fprintf(fp, "\t\tReleaseMargin = %s    [�����ͷű�֤��]\n", boost::lexical_cast<std::string>(ReleaseMargin).c_str());
	fprintf(fp, "\t\tDynamicRights = %s    [��̬Ȩ��]\n", boost::lexical_cast<std::string>(DynamicRights).c_str());
	fprintf(fp, "\t\tTodayInOut = %s    [���ճ����]\n", boost::lexical_cast<std::string>(TodayInOut).c_str());
	fprintf(fp, "\t\tMargin = %s    [ռ�ñ�֤��]\n", boost::lexical_cast<std::string>(Margin).c_str());
	fprintf(fp, "\t\tPremium = %s    [��ȨȨ������֧]\n", boost::lexical_cast<std::string>(Premium).c_str());
	fprintf(fp, "\t\tRisk = %s    [���ն�]\n", boost::lexical_cast<std::string>(Risk).c_str());
	fprintf(fp, "\t}\n");
}

void CExchInvestorAccount::dumpDiff(FILE *fp, const CExchInvestorAccount *pOriginal) const
{
	if (fp == nullptr)
	{
		fp = stdout;
	}
	fprintf(fp, "\tCExchInvestorAccount = {\n");
	if (compare(BrokerID, pOriginal->BrokerID) != 0)
	{
		fprintf(fp, "\t\tBrokerID = %s -> %s    [���͹�˾����]\n", boost::lexical_cast<std::string>(pOriginal->BrokerID).c_str(), boost::lexical_cast<std::string>(BrokerID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBrokerID = %s    [���͹�˾����]\n", boost::lexical_cast<std::string>(BrokerID).c_str());
	}
	if (compare(InvestorID, pOriginal->InvestorID) != 0)
	{
		fprintf(fp, "\t\tInvestorID = %s -> %s    [Ͷ���ߴ���]\n", boost::lexical_cast<std::string>(pOriginal->InvestorID).c_str(), boost::lexical_cast<std::string>(InvestorID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tInvestorID = %s    [Ͷ���ߴ���]\n", boost::lexical_cast<std::string>(InvestorID).c_str());
	}
	if (compare(AccountID, pOriginal->AccountID) != 0)
	{
		fprintf(fp, "\t\tAccountID = %s -> %s    [�ʽ��ʺ�]\n", boost::lexical_cast<std::string>(pOriginal->AccountID).c_str(), boost::lexical_cast<std::string>(AccountID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAccountID = %s    [�ʽ��ʺ�]\n", boost::lexical_cast<std::string>(AccountID).c_str());
	}
	if (compare(PreBalance, pOriginal->PreBalance) != 0)
	{
		fprintf(fp, "\t\tPreBalance = %s -> %s    [�ϴν���׼����]\n", boost::lexical_cast<std::string>(pOriginal->PreBalance).c_str(), boost::lexical_cast<std::string>(PreBalance).c_str());
	}
	else
	{
		fprintf(fp, "\t\tPreBalance = %s    [�ϴν���׼����]\n", boost::lexical_cast<std::string>(PreBalance).c_str());
	}
	if (compare(Deposit, pOriginal->Deposit) != 0)
	{
		fprintf(fp, "\t\tDeposit = %s -> %s    [�����]\n", boost::lexical_cast<std::string>(pOriginal->Deposit).c_str(), boost::lexical_cast<std::string>(Deposit).c_str());
	}
	else
	{
		fprintf(fp, "\t\tDeposit = %s    [�����]\n", boost::lexical_cast<std::string>(Deposit).c_str());
	}
	if (compare(Withdraw, pOriginal->Withdraw) != 0)
	{
		fprintf(fp, "\t\tWithdraw = %s -> %s    [������]\n", boost::lexical_cast<std::string>(pOriginal->Withdraw).c_str(), boost::lexical_cast<std::string>(Withdraw).c_str());
	}
	else
	{
		fprintf(fp, "\t\tWithdraw = %s    [������]\n", boost::lexical_cast<std::string>(Withdraw).c_str());
	}
	if (compare(FrozenMargin, pOriginal->FrozenMargin) != 0)
	{
		fprintf(fp, "\t\tFrozenMargin = %s -> %s    [����ı�֤��]\n", boost::lexical_cast<std::string>(pOriginal->FrozenMargin).c_str(), boost::lexical_cast<std::string>(FrozenMargin).c_str());
	}
	else
	{
		fprintf(fp, "\t\tFrozenMargin = %s    [����ı�֤��]\n", boost::lexical_cast<std::string>(FrozenMargin).c_str());
	}
	if (compare(FrozenFee, pOriginal->FrozenFee) != 0)
	{
		fprintf(fp, "\t\tFrozenFee = %s -> %s    [����������]\n", boost::lexical_cast<std::string>(pOriginal->FrozenFee).c_str(), boost::lexical_cast<std::string>(FrozenFee).c_str());
	}
	else
	{
		fprintf(fp, "\t\tFrozenFee = %s    [����������]\n", boost::lexical_cast<std::string>(FrozenFee).c_str());
	}
	if (compare(FrozenPremium, pOriginal->FrozenPremium) != 0)
	{
		fprintf(fp, "\t\tFrozenPremium = %s -> %s    [����Ȩ����]\n", boost::lexical_cast<std::string>(pOriginal->FrozenPremium).c_str(), boost::lexical_cast<std::string>(FrozenPremium).c_str());
	}
	else
	{
		fprintf(fp, "\t\tFrozenPremium = %s    [����Ȩ����]\n", boost::lexical_cast<std::string>(FrozenPremium).c_str());
	}
	if (compare(Fee, pOriginal->Fee) != 0)
	{
		fprintf(fp, "\t\tFee = %s -> %s    [������]\n", boost::lexical_cast<std::string>(pOriginal->Fee).c_str(), boost::lexical_cast<std::string>(Fee).c_str());
	}
	else
	{
		fprintf(fp, "\t\tFee = %s    [������]\n", boost::lexical_cast<std::string>(Fee).c_str());
	}
	if (compare(CloseProfit, pOriginal->CloseProfit) != 0)
	{
		fprintf(fp, "\t\tCloseProfit = %s -> %s    [ƽ��ӯ��]\n", boost::lexical_cast<std::string>(pOriginal->CloseProfit).c_str(), boost::lexical_cast<std::string>(CloseProfit).c_str());
	}
	else
	{
		fprintf(fp, "\t\tCloseProfit = %s    [ƽ��ӯ��]\n", boost::lexical_cast<std::string>(CloseProfit).c_str());
	}
	if (compare(PositionProfit, pOriginal->PositionProfit) != 0)
	{
		fprintf(fp, "\t\tPositionProfit = %s -> %s    [�ֲ�ӯ��]\n", boost::lexical_cast<std::string>(pOriginal->PositionProfit).c_str(), boost::lexical_cast<std::string>(PositionProfit).c_str());
	}
	else
	{
		fprintf(fp, "\t\tPositionProfit = %s    [�ֲ�ӯ��]\n", boost::lexical_cast<std::string>(PositionProfit).c_str());
	}
	if (compare(Available, pOriginal->Available) != 0)
	{
		fprintf(fp, "\t\tAvailable = %s -> %s    [�����ʽ�]\n", boost::lexical_cast<std::string>(pOriginal->Available).c_str(), boost::lexical_cast<std::string>(Available).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAvailable = %s    [�����ʽ�]\n", boost::lexical_cast<std::string>(Available).c_str());
	}
	if (compare(LongFrozenMargin, pOriginal->LongFrozenMargin) != 0)
	{
		fprintf(fp, "\t\tLongFrozenMargin = %s -> %s    [��ͷ����ı�֤��]\n", boost::lexical_cast<std::string>(pOriginal->LongFrozenMargin).c_str(), boost::lexical_cast<std::string>(LongFrozenMargin).c_str());
	}
	else
	{
		fprintf(fp, "\t\tLongFrozenMargin = %s    [��ͷ����ı�֤��]\n", boost::lexical_cast<std::string>(LongFrozenMargin).c_str());
	}
	if (compare(ShortFrozenMargin, pOriginal->ShortFrozenMargin) != 0)
	{
		fprintf(fp, "\t\tShortFrozenMargin = %s -> %s    [��ͷ����ı�֤��]\n", boost::lexical_cast<std::string>(pOriginal->ShortFrozenMargin).c_str(), boost::lexical_cast<std::string>(ShortFrozenMargin).c_str());
	}
	else
	{
		fprintf(fp, "\t\tShortFrozenMargin = %s    [��ͷ����ı�֤��]\n", boost::lexical_cast<std::string>(ShortFrozenMargin).c_str());
	}
	if (compare(LongMargin, pOriginal->LongMargin) != 0)
	{
		fprintf(fp, "\t\tLongMargin = %s -> %s    [��ͷռ�ñ�֤��]\n", boost::lexical_cast<std::string>(pOriginal->LongMargin).c_str(), boost::lexical_cast<std::string>(LongMargin).c_str());
	}
	else
	{
		fprintf(fp, "\t\tLongMargin = %s    [��ͷռ�ñ�֤��]\n", boost::lexical_cast<std::string>(LongMargin).c_str());
	}
	if (compare(ShortMargin, pOriginal->ShortMargin) != 0)
	{
		fprintf(fp, "\t\tShortMargin = %s -> %s    [��ͷռ�ñ�֤��]\n", boost::lexical_cast<std::string>(pOriginal->ShortMargin).c_str(), boost::lexical_cast<std::string>(ShortMargin).c_str());
	}
	else
	{
		fprintf(fp, "\t\tShortMargin = %s    [��ͷռ�ñ�֤��]\n", boost::lexical_cast<std::string>(ShortMargin).c_str());
	}
	if (compare(ReleaseMargin, pOriginal->ReleaseMargin) != 0)
	{
		fprintf(fp, "\t\tReleaseMargin = %s -> %s    [�����ͷű�֤��]\n", boost::lexical_cast<std::string>(pOriginal->ReleaseMargin).c_str(), boost::lexical_cast<std::string>(ReleaseMargin).c_str());
	}
	else
	{
		fprintf(fp, "\t\tReleaseMargin = %s    [�����ͷű�֤��]\n", boost::lexical_cast<std::string>(ReleaseMargin).c_str());
	}
	if (compare(DynamicRights, pOriginal->DynamicRights) != 0)
	{
		fprintf(fp, "\t\tDynamicRights = %s -> %s    [��̬Ȩ��]\n", boost::lexical_cast<std::string>(pOriginal->DynamicRights).c_str(), boost::lexical_cast<std::string>(DynamicRights).c_str());
	}
	else
	{
		fprintf(fp, "\t\tDynamicRights = %s    [��̬Ȩ��]\n", boost::lexical_cast<std::string>(DynamicRights).c_str());
	}
	if (compare(TodayInOut, pOriginal->TodayInOut) != 0)
	{
		fprintf(fp, "\t\tTodayInOut = %s -> %s    [���ճ����]\n", boost::lexical_cast<std::string>(pOriginal->TodayInOut).c_str(), boost::lexical_cast<std::string>(TodayInOut).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTodayInOut = %s    [���ճ����]\n", boost::lexical_cast<std::string>(TodayInOut).c_str());
	}
	if (compare(Margin, pOriginal->Margin) != 0)
	{
		fprintf(fp, "\t\tMargin = %s -> %s    [ռ�ñ�֤��]\n", boost::lexical_cast<std::string>(pOriginal->Margin).c_str(), boost::lexical_cast<std::string>(Margin).c_str());
	}
	else
	{
		fprintf(fp, "\t\tMargin = %s    [ռ�ñ�֤��]\n", boost::lexical_cast<std::string>(Margin).c_str());
	}
	if (compare(Premium, pOriginal->Premium) != 0)
	{
		fprintf(fp, "\t\tPremium = %s -> %s    [��ȨȨ������֧]\n", boost::lexical_cast<std::string>(pOriginal->Premium).c_str(), boost::lexical_cast<std::string>(Premium).c_str());
	}
	else
	{
		fprintf(fp, "\t\tPremium = %s    [��ȨȨ������֧]\n", boost::lexical_cast<std::string>(Premium).c_str());
	}
	if (compare(Risk, pOriginal->Risk) != 0)
	{
		fprintf(fp, "\t\tRisk = %s -> %s    [���ն�]\n", boost::lexical_cast<std::string>(pOriginal->Risk).c_str(), boost::lexical_cast<std::string>(Risk).c_str());
	}
	else
	{
		fprintf(fp, "\t\tRisk = %s    [���ն�]\n", boost::lexical_cast<std::string>(Risk).c_str());
	}
	fprintf(fp, "\t}\n");
}

void CExchInvestorAccount::dumpInLine(FILE *fp) const
{
	if (fp == nullptr)
	{
		fp = stdout;
	}
	std::stringstream sbuf;

	sbuf << ",BrokerID," << BrokerID;
	sbuf << ",InvestorID," << InvestorID;
	sbuf << ",AccountID," << AccountID;
	sbuf << ",PreBalance," << PreBalance;
	sbuf << ",Deposit," << Deposit;
	sbuf << ",Withdraw," << Withdraw;
	sbuf << ",FrozenMargin," << FrozenMargin;
	sbuf << ",FrozenFee," << FrozenFee;
	sbuf << ",FrozenPremium," << FrozenPremium;
	sbuf << ",Fee," << Fee;
	sbuf << ",CloseProfit," << CloseProfit;
	sbuf << ",PositionProfit," << PositionProfit;
	sbuf << ",Available," << Available;
	sbuf << ",LongFrozenMargin," << LongFrozenMargin;
	sbuf << ",ShortFrozenMargin," << ShortFrozenMargin;
	sbuf << ",LongMargin," << LongMargin;
	sbuf << ",ShortMargin," << ShortMargin;
	sbuf << ",ReleaseMargin," << ReleaseMargin;
	sbuf << ",DynamicRights," << DynamicRights;
	sbuf << ",TodayInOut," << TodayInOut;
	sbuf << ",Margin," << Margin;
	sbuf << ",Premium," << Premium;
	sbuf << ",Risk," << Risk;
	fprintf(fp, "%s", sbuf.str().c_str());
}

void CExchInvestorAccount::dumpString(char *target) const
{
	char *p = target;
	std::stringstream sbuf;

	sbuf << "BrokerID=" << BrokerID << ",";
	sbuf << "InvestorID=" << InvestorID << ",";
	sbuf << "AccountID=" << AccountID << ",";
	sbuf << "PreBalance=" << PreBalance << ",";
	sbuf << "Deposit=" << Deposit << ",";
	sbuf << "Withdraw=" << Withdraw << ",";
	sbuf << "FrozenMargin=" << FrozenMargin << ",";
	sbuf << "FrozenFee=" << FrozenFee << ",";
	sbuf << "FrozenPremium=" << FrozenPremium << ",";
	sbuf << "Fee=" << Fee << ",";
	sbuf << "CloseProfit=" << CloseProfit << ",";
	sbuf << "PositionProfit=" << PositionProfit << ",";
	sbuf << "Available=" << Available << ",";
	sbuf << "LongFrozenMargin=" << LongFrozenMargin << ",";
	sbuf << "ShortFrozenMargin=" << ShortFrozenMargin << ",";
	sbuf << "LongMargin=" << LongMargin << ",";
	sbuf << "ShortMargin=" << ShortMargin << ",";
	sbuf << "ReleaseMargin=" << ReleaseMargin << ",";
	sbuf << "DynamicRights=" << DynamicRights << ",";
	sbuf << "TodayInOut=" << TodayInOut << ",";
	sbuf << "Margin=" << Margin << ",";
	sbuf << "Premium=" << Premium << ",";
	sbuf << "Risk=" << Risk << ",";

	sprintf(p, "%s", sbuf.str().c_str());
}

void CExchDepthMarketData::init(void)
{
	memset(this, 0, sizeof(CExchDepthMarketData));
}

int CExchDepthMarketData::read(FILE *input)
{
	if (fread(this, 1, sizeof(CExchDepthMarketData), input) != sizeof(CExchDepthMarketData))
		return 0;
	else
		return 1;
}

int CExchDepthMarketData::write(FILE *output) const
{
	if (fwrite(this, 1, sizeof(CExchDepthMarketData), output) != sizeof(CExchDepthMarketData))
		return 0;
	else
		return 1;
}

void CExchDepthMarketData::dump(FILE *fp, int index) const
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
	fprintf(fp, "\tCExchDepthMarketData%s = {\n", index_buf);
	fprintf(fp, "\t\tTradingDay = %s    [������]\n", boost::lexical_cast<std::string>(TradingDay).c_str());
	fprintf(fp, "\t\tPreClearPrice = %s    [�����]\n", boost::lexical_cast<std::string>(PreClearPrice).c_str());
	fprintf(fp, "\t\tPreClosePrice = %s    [������]\n", boost::lexical_cast<std::string>(PreClosePrice).c_str());
	fprintf(fp, "\t\tPreOpenInterest = %s    [��ֲ���]\n", boost::lexical_cast<std::string>(PreOpenInterest).c_str());
	fprintf(fp, "\t\tPreDelta = %s    [����ʵ��]\n", boost::lexical_cast<std::string>(PreDelta).c_str());
	fprintf(fp, "\t\tHistoryHigh = %s    [��Լ���]\n", boost::lexical_cast<std::string>(HistoryHigh).c_str());
	fprintf(fp, "\t\tHistoryLow = %s    [��Լ���]\n", boost::lexical_cast<std::string>(HistoryLow).c_str());
	fprintf(fp, "\t\tOpenPrice = %s    [����]\n", boost::lexical_cast<std::string>(OpenPrice).c_str());
	fprintf(fp, "\t\tHighestPrice = %s    [��߼�]\n", boost::lexical_cast<std::string>(HighestPrice).c_str());
	fprintf(fp, "\t\tLowestPrice = %s    [��ͼ�]\n", boost::lexical_cast<std::string>(LowestPrice).c_str());
	fprintf(fp, "\t\tClosePrice = %s    [������]\n", boost::lexical_cast<std::string>(ClosePrice).c_str());
	fprintf(fp, "\t\tUpperLimitPrice = %s    [��ͣ���]\n", boost::lexical_cast<std::string>(UpperLimitPrice).c_str());
	fprintf(fp, "\t\tLowerLimitPrice = %s    [��ͣ���]\n", boost::lexical_cast<std::string>(LowerLimitPrice).c_str());
	fprintf(fp, "\t\tClearPrice = %s    [���ν����]\n", boost::lexical_cast<std::string>(ClearPrice).c_str());
	fprintf(fp, "\t\tCurrDelta = %s    [����ʵ��]\n", boost::lexical_cast<std::string>(CurrDelta).c_str());
	fprintf(fp, "\t\tPrecision = %s    [���۾���]\n", boost::lexical_cast<std::string>(Precision).c_str());
	fprintf(fp, "\t\tLastPrice = %s    [���¼�]\n", boost::lexical_cast<std::string>(LastPrice).c_str());
	fprintf(fp, "\t\tVolume = %s    [����]\n", boost::lexical_cast<std::string>(Volume).c_str());
	fprintf(fp, "\t\tTurnover = %s    [�ɽ����]\n", boost::lexical_cast<std::string>(Turnover).c_str());
	fprintf(fp, "\t\tOpenInterest = %s    [�ֲ���]\n", boost::lexical_cast<std::string>(OpenInterest).c_str());
	fprintf(fp, "\t\tNetChg = %s    [�ǵ�]\n", boost::lexical_cast<std::string>(NetChg).c_str());
	fprintf(fp, "\t\tMarkup = %s    [�ǵ���]\n", boost::lexical_cast<std::string>(Markup).c_str());
	fprintf(fp, "\t\tSwing = %s    [���]\n", boost::lexical_cast<std::string>(Swing).c_str());
	fprintf(fp, "\t\tAvgPrice = %s    [ƽ����]\n", boost::lexical_cast<std::string>(AvgPrice).c_str());
	fprintf(fp, "\t\tBidPrice1 = %s    [�����һ]\n", boost::lexical_cast<std::string>(BidPrice1).c_str());
	fprintf(fp, "\t\tBidVolume1 = %s    [������һ]\n", boost::lexical_cast<std::string>(BidVolume1).c_str());
	fprintf(fp, "\t\tAskPrice1 = %s    [������һ]\n", boost::lexical_cast<std::string>(AskPrice1).c_str());
	fprintf(fp, "\t\tAskVolume1 = %s    [������һ]\n", boost::lexical_cast<std::string>(AskVolume1).c_str());
	fprintf(fp, "\t\tBidPrice2 = %s    [����۶�]\n", boost::lexical_cast<std::string>(BidPrice2).c_str());
	fprintf(fp, "\t\tBidVolume2 = %s    [��������]\n", boost::lexical_cast<std::string>(BidVolume2).c_str());
	fprintf(fp, "\t\tBidPrice3 = %s    [�������]\n", boost::lexical_cast<std::string>(BidPrice3).c_str());
	fprintf(fp, "\t\tBidVolume3 = %s    [��������]\n", boost::lexical_cast<std::string>(BidVolume3).c_str());
	fprintf(fp, "\t\tAskPrice2 = %s    [�����۶�]\n", boost::lexical_cast<std::string>(AskPrice2).c_str());
	fprintf(fp, "\t\tAskVolume2 = %s    [��������]\n", boost::lexical_cast<std::string>(AskVolume2).c_str());
	fprintf(fp, "\t\tAskPrice3 = %s    [��������]\n", boost::lexical_cast<std::string>(AskPrice3).c_str());
	fprintf(fp, "\t\tAskVolume3 = %s    [��������]\n", boost::lexical_cast<std::string>(AskVolume3).c_str());
	fprintf(fp, "\t\tBidPrice4 = %s    [�������]\n", boost::lexical_cast<std::string>(BidPrice4).c_str());
	fprintf(fp, "\t\tBidVolume4 = %s    [��������]\n", boost::lexical_cast<std::string>(BidVolume4).c_str());
	fprintf(fp, "\t\tBidPrice5 = %s    [�������]\n", boost::lexical_cast<std::string>(BidPrice5).c_str());
	fprintf(fp, "\t\tBidVolume5 = %s    [��������]\n", boost::lexical_cast<std::string>(BidVolume5).c_str());
	fprintf(fp, "\t\tAskPrice4 = %s    [��������]\n", boost::lexical_cast<std::string>(AskPrice4).c_str());
	fprintf(fp, "\t\tAskVolume4 = %s    [��������]\n", boost::lexical_cast<std::string>(AskVolume4).c_str());
	fprintf(fp, "\t\tAskPrice5 = %s    [��������]\n", boost::lexical_cast<std::string>(AskPrice5).c_str());
	fprintf(fp, "\t\tAskVolume5 = %s    [��������]\n", boost::lexical_cast<std::string>(AskVolume5).c_str());
	fprintf(fp, "\t\tBidPrice6 = %s    [�������]\n", boost::lexical_cast<std::string>(BidPrice6).c_str());
	fprintf(fp, "\t\tBidVolume6 = %s    [��������]\n", boost::lexical_cast<std::string>(BidVolume6).c_str());
	fprintf(fp, "\t\tBidPrice7 = %s    [�������]\n", boost::lexical_cast<std::string>(BidPrice7).c_str());
	fprintf(fp, "\t\tBidVolume7 = %s    [��������]\n", boost::lexical_cast<std::string>(BidVolume7).c_str());
	fprintf(fp, "\t\tBidPrice8 = %s    [����۰�]\n", boost::lexical_cast<std::string>(BidPrice8).c_str());
	fprintf(fp, "\t\tBidVolume8 = %s    [��������]\n", boost::lexical_cast<std::string>(BidVolume8).c_str());
	fprintf(fp, "\t\tBidPrice9 = %s    [����۾�]\n", boost::lexical_cast<std::string>(BidPrice9).c_str());
	fprintf(fp, "\t\tBidVolume9 = %s    [��������]\n", boost::lexical_cast<std::string>(BidVolume9).c_str());
	fprintf(fp, "\t\tBidPrice10 = %s    [�����ʮ]\n", boost::lexical_cast<std::string>(BidPrice10).c_str());
	fprintf(fp, "\t\tBidVolume10 = %s    [������ʮ]\n", boost::lexical_cast<std::string>(BidVolume10).c_str());
	fprintf(fp, "\t\tAskPrice6 = %s    [��������]\n", boost::lexical_cast<std::string>(AskPrice6).c_str());
	fprintf(fp, "\t\tAskVolume6 = %s    [��������]\n", boost::lexical_cast<std::string>(AskVolume6).c_str());
	fprintf(fp, "\t\tAskPrice7 = %s    [��������]\n", boost::lexical_cast<std::string>(AskPrice7).c_str());
	fprintf(fp, "\t\tAskVolume7 = %s    [��������]\n", boost::lexical_cast<std::string>(AskVolume7).c_str());
	fprintf(fp, "\t\tAskPrice8 = %s    [�����۰�]\n", boost::lexical_cast<std::string>(AskPrice8).c_str());
	fprintf(fp, "\t\tAskVolume8 = %s    [��������]\n", boost::lexical_cast<std::string>(AskVolume8).c_str());
	fprintf(fp, "\t\tAskPrice9 = %s    [�����۾�]\n", boost::lexical_cast<std::string>(AskPrice9).c_str());
	fprintf(fp, "\t\tAskVolume9 = %s    [��������]\n", boost::lexical_cast<std::string>(AskVolume9).c_str());
	fprintf(fp, "\t\tAskPrice10 = %s    [������ʮ]\n", boost::lexical_cast<std::string>(AskPrice10).c_str());
	fprintf(fp, "\t\tAskVolume10 = %s    [������ʮ]\n", boost::lexical_cast<std::string>(AskVolume10).c_str());
	fprintf(fp, "\t\tSequenceNo = %s    [���]\n", boost::lexical_cast<std::string>(SequenceNo).c_str());
	fprintf(fp, "\t\tMarketName = %s    [�г�������]\n", boost::lexical_cast<std::string>(MarketName).c_str());
	fprintf(fp, "\t\tInstrumentID = %s    [��Լ����]\n", boost::lexical_cast<std::string>(InstrumentID).c_str());
	fprintf(fp, "\t\tInstrumentStatus = %s    [��Լ����״̬-1:δ֪0:����1:�޺���2:����3:����4:����5:����ǰ6:����ǰ7:����]\n", boost::lexical_cast<std::string>(InstrumentStatus).c_str());
	fprintf(fp, "\t\tUpdateTime = %s    [����޸�ʱ��]\n", boost::lexical_cast<std::string>(UpdateTime).c_str());
	fprintf(fp, "\t\tUpdateMillisec = %s    [����޸ĺ���]\n", boost::lexical_cast<std::string>(UpdateMillisec).c_str());
	fprintf(fp, "\t}\n");
}

void CExchDepthMarketData::dumpDiff(FILE *fp, const CExchDepthMarketData *pOriginal) const
{
	if (fp == NULL)
	{
		fp = stdout;
	}
	fprintf(fp, "\tCExchDepthMarketData = {\n");
	if (compare(TradingDay, pOriginal->TradingDay) != 0)
	{
		fprintf(fp, "\t\tTradingDay = %s -> %s    [������]\n", boost::lexical_cast<std::string>(pOriginal->TradingDay).c_str(), boost::lexical_cast<std::string>(TradingDay).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTradingDay = %s    [������]\n", boost::lexical_cast<std::string>(TradingDay).c_str());
	}
	if (compare(PreClearPrice, pOriginal->PreClearPrice) != 0)
	{
		fprintf(fp, "\t\tPreClearPrice = %s -> %s    [�����]\n", boost::lexical_cast<std::string>(pOriginal->PreClearPrice).c_str(), boost::lexical_cast<std::string>(PreClearPrice).c_str());
	}
	else
	{
		fprintf(fp, "\t\tPreClearPrice = %s    [�����]\n", boost::lexical_cast<std::string>(PreClearPrice).c_str());
	}
	if (compare(PreClosePrice, pOriginal->PreClosePrice) != 0)
	{
		fprintf(fp, "\t\tPreClosePrice = %s -> %s    [������]\n", boost::lexical_cast<std::string>(pOriginal->PreClosePrice).c_str(), boost::lexical_cast<std::string>(PreClosePrice).c_str());
	}
	else
	{
		fprintf(fp, "\t\tPreClosePrice = %s    [������]\n", boost::lexical_cast<std::string>(PreClosePrice).c_str());
	}
	if (compare(PreOpenInterest, pOriginal->PreOpenInterest) != 0)
	{
		fprintf(fp, "\t\tPreOpenInterest = %s -> %s    [��ֲ���]\n", boost::lexical_cast<std::string>(pOriginal->PreOpenInterest).c_str(), boost::lexical_cast<std::string>(PreOpenInterest).c_str());
	}
	else
	{
		fprintf(fp, "\t\tPreOpenInterest = %s    [��ֲ���]\n", boost::lexical_cast<std::string>(PreOpenInterest).c_str());
	}
	if (compare(PreDelta, pOriginal->PreDelta) != 0)
	{
		fprintf(fp, "\t\tPreDelta = %s -> %s    [����ʵ��]\n", boost::lexical_cast<std::string>(pOriginal->PreDelta).c_str(), boost::lexical_cast<std::string>(PreDelta).c_str());
	}
	else
	{
		fprintf(fp, "\t\tPreDelta = %s    [����ʵ��]\n", boost::lexical_cast<std::string>(PreDelta).c_str());
	}
	if (compare(HistoryHigh, pOriginal->HistoryHigh) != 0)
	{
		fprintf(fp, "\t\tHistoryHigh = %s -> %s    [��Լ���]\n", boost::lexical_cast<std::string>(pOriginal->HistoryHigh).c_str(), boost::lexical_cast<std::string>(HistoryHigh).c_str());
	}
	else
	{
		fprintf(fp, "\t\tHistoryHigh = %s    [��Լ���]\n", boost::lexical_cast<std::string>(HistoryHigh).c_str());
	}
	if (compare(HistoryLow, pOriginal->HistoryLow) != 0)
	{
		fprintf(fp, "\t\tHistoryLow = %s -> %s    [��Լ���]\n", boost::lexical_cast<std::string>(pOriginal->HistoryLow).c_str(), boost::lexical_cast<std::string>(HistoryLow).c_str());
	}
	else
	{
		fprintf(fp, "\t\tHistoryLow = %s    [��Լ���]\n", boost::lexical_cast<std::string>(HistoryLow).c_str());
	}
	if (compare(OpenPrice, pOriginal->OpenPrice) != 0)
	{
		fprintf(fp, "\t\tOpenPrice = %s -> %s    [����]\n", boost::lexical_cast<std::string>(pOriginal->OpenPrice).c_str(), boost::lexical_cast<std::string>(OpenPrice).c_str());
	}
	else
	{
		fprintf(fp, "\t\tOpenPrice = %s    [����]\n", boost::lexical_cast<std::string>(OpenPrice).c_str());
	}
	if (compare(HighestPrice, pOriginal->HighestPrice) != 0)
	{
		fprintf(fp, "\t\tHighestPrice = %s -> %s    [��߼�]\n", boost::lexical_cast<std::string>(pOriginal->HighestPrice).c_str(), boost::lexical_cast<std::string>(HighestPrice).c_str());
	}
	else
	{
		fprintf(fp, "\t\tHighestPrice = %s    [��߼�]\n", boost::lexical_cast<std::string>(HighestPrice).c_str());
	}
	if (compare(LowestPrice, pOriginal->LowestPrice) != 0)
	{
		fprintf(fp, "\t\tLowestPrice = %s -> %s    [��ͼ�]\n", boost::lexical_cast<std::string>(pOriginal->LowestPrice).c_str(), boost::lexical_cast<std::string>(LowestPrice).c_str());
	}
	else
	{
		fprintf(fp, "\t\tLowestPrice = %s    [��ͼ�]\n", boost::lexical_cast<std::string>(LowestPrice).c_str());
	}
	if (compare(ClosePrice, pOriginal->ClosePrice) != 0)
	{
		fprintf(fp, "\t\tClosePrice = %s -> %s    [������]\n", boost::lexical_cast<std::string>(pOriginal->ClosePrice).c_str(), boost::lexical_cast<std::string>(ClosePrice).c_str());
	}
	else
	{
		fprintf(fp, "\t\tClosePrice = %s    [������]\n", boost::lexical_cast<std::string>(ClosePrice).c_str());
	}
	if (compare(UpperLimitPrice, pOriginal->UpperLimitPrice) != 0)
	{
		fprintf(fp, "\t\tUpperLimitPrice = %s -> %s    [��ͣ���]\n", boost::lexical_cast<std::string>(pOriginal->UpperLimitPrice).c_str(), boost::lexical_cast<std::string>(UpperLimitPrice).c_str());
	}
	else
	{
		fprintf(fp, "\t\tUpperLimitPrice = %s    [��ͣ���]\n", boost::lexical_cast<std::string>(UpperLimitPrice).c_str());
	}
	if (compare(LowerLimitPrice, pOriginal->LowerLimitPrice) != 0)
	{
		fprintf(fp, "\t\tLowerLimitPrice = %s -> %s    [��ͣ���]\n", boost::lexical_cast<std::string>(pOriginal->LowerLimitPrice).c_str(), boost::lexical_cast<std::string>(LowerLimitPrice).c_str());
	}
	else
	{
		fprintf(fp, "\t\tLowerLimitPrice = %s    [��ͣ���]\n", boost::lexical_cast<std::string>(LowerLimitPrice).c_str());
	}
	if (compare(ClearPrice, pOriginal->ClearPrice) != 0)
	{
		fprintf(fp, "\t\tClearPrice = %s -> %s    [���ν����]\n", boost::lexical_cast<std::string>(pOriginal->ClearPrice).c_str(), boost::lexical_cast<std::string>(ClearPrice).c_str());
	}
	else
	{
		fprintf(fp, "\t\tClearPrice = %s    [���ν����]\n", boost::lexical_cast<std::string>(ClearPrice).c_str());
	}
	if (compare(CurrDelta, pOriginal->CurrDelta) != 0)
	{
		fprintf(fp, "\t\tCurrDelta = %s -> %s    [����ʵ��]\n", boost::lexical_cast<std::string>(pOriginal->CurrDelta).c_str(), boost::lexical_cast<std::string>(CurrDelta).c_str());
	}
	else
	{
		fprintf(fp, "\t\tCurrDelta = %s    [����ʵ��]\n", boost::lexical_cast<std::string>(CurrDelta).c_str());
	}
	if (compare(Precision, pOriginal->Precision) != 0)
	{
		fprintf(fp, "\t\tPrecision = %s -> %s    [���۾���]\n", boost::lexical_cast<std::string>(pOriginal->Precision).c_str(), boost::lexical_cast<std::string>(Precision).c_str());
	}
	else
	{
		fprintf(fp, "\t\tPrecision = %s    [���۾���]\n", boost::lexical_cast<std::string>(Precision).c_str());
	}
	if (compare(LastPrice, pOriginal->LastPrice) != 0)
	{
		fprintf(fp, "\t\tLastPrice = %s -> %s    [���¼�]\n", boost::lexical_cast<std::string>(pOriginal->LastPrice).c_str(), boost::lexical_cast<std::string>(LastPrice).c_str());
	}
	else
	{
		fprintf(fp, "\t\tLastPrice = %s    [���¼�]\n", boost::lexical_cast<std::string>(LastPrice).c_str());
	}
	if (compare(Volume, pOriginal->Volume) != 0)
	{
		fprintf(fp, "\t\tVolume = %s -> %s    [����]\n", boost::lexical_cast<std::string>(pOriginal->Volume).c_str(), boost::lexical_cast<std::string>(Volume).c_str());
	}
	else
	{
		fprintf(fp, "\t\tVolume = %s    [����]\n", boost::lexical_cast<std::string>(Volume).c_str());
	}
	if (compare(Turnover, pOriginal->Turnover) != 0)
	{
		fprintf(fp, "\t\tTurnover = %s -> %s    [�ɽ����]\n", boost::lexical_cast<std::string>(pOriginal->Turnover).c_str(), boost::lexical_cast<std::string>(Turnover).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTurnover = %s    [�ɽ����]\n", boost::lexical_cast<std::string>(Turnover).c_str());
	}
	if (compare(OpenInterest, pOriginal->OpenInterest) != 0)
	{
		fprintf(fp, "\t\tOpenInterest = %s -> %s    [�ֲ���]\n", boost::lexical_cast<std::string>(pOriginal->OpenInterest).c_str(), boost::lexical_cast<std::string>(OpenInterest).c_str());
	}
	else
	{
		fprintf(fp, "\t\tOpenInterest = %s    [�ֲ���]\n", boost::lexical_cast<std::string>(OpenInterest).c_str());
	}
	if (compare(NetChg, pOriginal->NetChg) != 0)
	{
		fprintf(fp, "\t\tNetChg = %s -> %s    [�ǵ�]\n", boost::lexical_cast<std::string>(pOriginal->NetChg).c_str(), boost::lexical_cast<std::string>(NetChg).c_str());
	}
	else
	{
		fprintf(fp, "\t\tNetChg = %s    [�ǵ�]\n", boost::lexical_cast<std::string>(NetChg).c_str());
	}
	if (compare(Markup, pOriginal->Markup) != 0)
	{
		fprintf(fp, "\t\tMarkup = %s -> %s    [�ǵ���]\n", boost::lexical_cast<std::string>(pOriginal->Markup).c_str(), boost::lexical_cast<std::string>(Markup).c_str());
	}
	else
	{
		fprintf(fp, "\t\tMarkup = %s    [�ǵ���]\n", boost::lexical_cast<std::string>(Markup).c_str());
	}
	if (compare(Swing, pOriginal->Swing) != 0)
	{
		fprintf(fp, "\t\tSwing = %s -> %s    [���]\n", boost::lexical_cast<std::string>(pOriginal->Swing).c_str(), boost::lexical_cast<std::string>(Swing).c_str());
	}
	else
	{
		fprintf(fp, "\t\tSwing = %s    [���]\n", boost::lexical_cast<std::string>(Swing).c_str());
	}
	if (compare(AvgPrice, pOriginal->AvgPrice) != 0)
	{
		fprintf(fp, "\t\tAvgPrice = %s -> %s    [ƽ����]\n", boost::lexical_cast<std::string>(pOriginal->AvgPrice).c_str(), boost::lexical_cast<std::string>(AvgPrice).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAvgPrice = %s    [ƽ����]\n", boost::lexical_cast<std::string>(AvgPrice).c_str());
	}
	if (compare(BidPrice1, pOriginal->BidPrice1) != 0)
	{
		fprintf(fp, "\t\tBidPrice1 = %s -> %s    [�����һ]\n", boost::lexical_cast<std::string>(pOriginal->BidPrice1).c_str(), boost::lexical_cast<std::string>(BidPrice1).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBidPrice1 = %s    [�����һ]\n", boost::lexical_cast<std::string>(BidPrice1).c_str());
	}
	if (compare(BidVolume1, pOriginal->BidVolume1) != 0)
	{
		fprintf(fp, "\t\tBidVolume1 = %s -> %s    [������һ]\n", boost::lexical_cast<std::string>(pOriginal->BidVolume1).c_str(), boost::lexical_cast<std::string>(BidVolume1).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBidVolume1 = %s    [������һ]\n", boost::lexical_cast<std::string>(BidVolume1).c_str());
	}
	if (compare(AskPrice1, pOriginal->AskPrice1) != 0)
	{
		fprintf(fp, "\t\tAskPrice1 = %s -> %s    [������һ]\n", boost::lexical_cast<std::string>(pOriginal->AskPrice1).c_str(), boost::lexical_cast<std::string>(AskPrice1).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAskPrice1 = %s    [������һ]\n", boost::lexical_cast<std::string>(AskPrice1).c_str());
	}
	if (compare(AskVolume1, pOriginal->AskVolume1) != 0)
	{
		fprintf(fp, "\t\tAskVolume1 = %s -> %s    [������һ]\n", boost::lexical_cast<std::string>(pOriginal->AskVolume1).c_str(), boost::lexical_cast<std::string>(AskVolume1).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAskVolume1 = %s    [������һ]\n", boost::lexical_cast<std::string>(AskVolume1).c_str());
	}
	if (compare(BidPrice2, pOriginal->BidPrice2) != 0)
	{
		fprintf(fp, "\t\tBidPrice2 = %s -> %s    [����۶�]\n", boost::lexical_cast<std::string>(pOriginal->BidPrice2).c_str(), boost::lexical_cast<std::string>(BidPrice2).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBidPrice2 = %s    [����۶�]\n", boost::lexical_cast<std::string>(BidPrice2).c_str());
	}
	if (compare(BidVolume2, pOriginal->BidVolume2) != 0)
	{
		fprintf(fp, "\t\tBidVolume2 = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->BidVolume2).c_str(), boost::lexical_cast<std::string>(BidVolume2).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBidVolume2 = %s    [��������]\n", boost::lexical_cast<std::string>(BidVolume2).c_str());
	}
	if (compare(BidPrice3, pOriginal->BidPrice3) != 0)
	{
		fprintf(fp, "\t\tBidPrice3 = %s -> %s    [�������]\n", boost::lexical_cast<std::string>(pOriginal->BidPrice3).c_str(), boost::lexical_cast<std::string>(BidPrice3).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBidPrice3 = %s    [�������]\n", boost::lexical_cast<std::string>(BidPrice3).c_str());
	}
	if (compare(BidVolume3, pOriginal->BidVolume3) != 0)
	{
		fprintf(fp, "\t\tBidVolume3 = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->BidVolume3).c_str(), boost::lexical_cast<std::string>(BidVolume3).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBidVolume3 = %s    [��������]\n", boost::lexical_cast<std::string>(BidVolume3).c_str());
	}
	if (compare(AskPrice2, pOriginal->AskPrice2) != 0)
	{
		fprintf(fp, "\t\tAskPrice2 = %s -> %s    [�����۶�]\n", boost::lexical_cast<std::string>(pOriginal->AskPrice2).c_str(), boost::lexical_cast<std::string>(AskPrice2).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAskPrice2 = %s    [�����۶�]\n", boost::lexical_cast<std::string>(AskPrice2).c_str());
	}
	if (compare(AskVolume2, pOriginal->AskVolume2) != 0)
	{
		fprintf(fp, "\t\tAskVolume2 = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->AskVolume2).c_str(), boost::lexical_cast<std::string>(AskVolume2).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAskVolume2 = %s    [��������]\n", boost::lexical_cast<std::string>(AskVolume2).c_str());
	}
	if (compare(AskPrice3, pOriginal->AskPrice3) != 0)
	{
		fprintf(fp, "\t\tAskPrice3 = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->AskPrice3).c_str(), boost::lexical_cast<std::string>(AskPrice3).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAskPrice3 = %s    [��������]\n", boost::lexical_cast<std::string>(AskPrice3).c_str());
	}
	if (compare(AskVolume3, pOriginal->AskVolume3) != 0)
	{
		fprintf(fp, "\t\tAskVolume3 = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->AskVolume3).c_str(), boost::lexical_cast<std::string>(AskVolume3).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAskVolume3 = %s    [��������]\n", boost::lexical_cast<std::string>(AskVolume3).c_str());
	}
	if (compare(BidPrice4, pOriginal->BidPrice4) != 0)
	{
		fprintf(fp, "\t\tBidPrice4 = %s -> %s    [�������]\n", boost::lexical_cast<std::string>(pOriginal->BidPrice4).c_str(), boost::lexical_cast<std::string>(BidPrice4).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBidPrice4 = %s    [�������]\n", boost::lexical_cast<std::string>(BidPrice4).c_str());
	}
	if (compare(BidVolume4, pOriginal->BidVolume4) != 0)
	{
		fprintf(fp, "\t\tBidVolume4 = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->BidVolume4).c_str(), boost::lexical_cast<std::string>(BidVolume4).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBidVolume4 = %s    [��������]\n", boost::lexical_cast<std::string>(BidVolume4).c_str());
	}
	if (compare(BidPrice5, pOriginal->BidPrice5) != 0)
	{
		fprintf(fp, "\t\tBidPrice5 = %s -> %s    [�������]\n", boost::lexical_cast<std::string>(pOriginal->BidPrice5).c_str(), boost::lexical_cast<std::string>(BidPrice5).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBidPrice5 = %s    [�������]\n", boost::lexical_cast<std::string>(BidPrice5).c_str());
	}
	if (compare(BidVolume5, pOriginal->BidVolume5) != 0)
	{
		fprintf(fp, "\t\tBidVolume5 = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->BidVolume5).c_str(), boost::lexical_cast<std::string>(BidVolume5).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBidVolume5 = %s    [��������]\n", boost::lexical_cast<std::string>(BidVolume5).c_str());
	}
	if (compare(AskPrice4, pOriginal->AskPrice4) != 0)
	{
		fprintf(fp, "\t\tAskPrice4 = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->AskPrice4).c_str(), boost::lexical_cast<std::string>(AskPrice4).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAskPrice4 = %s    [��������]\n", boost::lexical_cast<std::string>(AskPrice4).c_str());
	}
	if (compare(AskVolume4, pOriginal->AskVolume4) != 0)
	{
		fprintf(fp, "\t\tAskVolume4 = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->AskVolume4).c_str(), boost::lexical_cast<std::string>(AskVolume4).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAskVolume4 = %s    [��������]\n", boost::lexical_cast<std::string>(AskVolume4).c_str());
	}
	if (compare(AskPrice5, pOriginal->AskPrice5) != 0)
	{
		fprintf(fp, "\t\tAskPrice5 = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->AskPrice5).c_str(), boost::lexical_cast<std::string>(AskPrice5).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAskPrice5 = %s    [��������]\n", boost::lexical_cast<std::string>(AskPrice5).c_str());
	}
	if (compare(AskVolume5, pOriginal->AskVolume5) != 0)
	{
		fprintf(fp, "\t\tAskVolume5 = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->AskVolume5).c_str(), boost::lexical_cast<std::string>(AskVolume5).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAskVolume5 = %s    [��������]\n", boost::lexical_cast<std::string>(AskVolume5).c_str());
	}
	if (compare(BidPrice6, pOriginal->BidPrice6) != 0)
	{
		fprintf(fp, "\t\tBidPrice6 = %s -> %s    [�������]\n", boost::lexical_cast<std::string>(pOriginal->BidPrice6).c_str(), boost::lexical_cast<std::string>(BidPrice6).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBidPrice6 = %s    [�������]\n", boost::lexical_cast<std::string>(BidPrice6).c_str());
	}
	if (compare(BidVolume6, pOriginal->BidVolume6) != 0)
	{
		fprintf(fp, "\t\tBidVolume6 = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->BidVolume6).c_str(), boost::lexical_cast<std::string>(BidVolume6).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBidVolume6 = %s    [��������]\n", boost::lexical_cast<std::string>(BidVolume6).c_str());
	}
	if (compare(BidPrice7, pOriginal->BidPrice7) != 0)
	{
		fprintf(fp, "\t\tBidPrice7 = %s -> %s    [�������]\n", boost::lexical_cast<std::string>(pOriginal->BidPrice7).c_str(), boost::lexical_cast<std::string>(BidPrice7).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBidPrice7 = %s    [�������]\n", boost::lexical_cast<std::string>(BidPrice7).c_str());
	}
	if (compare(BidVolume7, pOriginal->BidVolume7) != 0)
	{
		fprintf(fp, "\t\tBidVolume7 = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->BidVolume7).c_str(), boost::lexical_cast<std::string>(BidVolume7).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBidVolume7 = %s    [��������]\n", boost::lexical_cast<std::string>(BidVolume7).c_str());
	}
	if (compare(BidPrice8, pOriginal->BidPrice8) != 0)
	{
		fprintf(fp, "\t\tBidPrice8 = %s -> %s    [����۰�]\n", boost::lexical_cast<std::string>(pOriginal->BidPrice8).c_str(), boost::lexical_cast<std::string>(BidPrice8).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBidPrice8 = %s    [����۰�]\n", boost::lexical_cast<std::string>(BidPrice8).c_str());
	}
	if (compare(BidVolume8, pOriginal->BidVolume8) != 0)
	{
		fprintf(fp, "\t\tBidVolume8 = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->BidVolume8).c_str(), boost::lexical_cast<std::string>(BidVolume8).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBidVolume8 = %s    [��������]\n", boost::lexical_cast<std::string>(BidVolume8).c_str());
	}
	if (compare(BidPrice9, pOriginal->BidPrice9) != 0)
	{
		fprintf(fp, "\t\tBidPrice9 = %s -> %s    [����۾�]\n", boost::lexical_cast<std::string>(pOriginal->BidPrice9).c_str(), boost::lexical_cast<std::string>(BidPrice9).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBidPrice9 = %s    [����۾�]\n", boost::lexical_cast<std::string>(BidPrice9).c_str());
	}
	if (compare(BidVolume9, pOriginal->BidVolume9) != 0)
	{
		fprintf(fp, "\t\tBidVolume9 = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->BidVolume9).c_str(), boost::lexical_cast<std::string>(BidVolume9).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBidVolume9 = %s    [��������]\n", boost::lexical_cast<std::string>(BidVolume9).c_str());
	}
	if (compare(BidPrice10, pOriginal->BidPrice10) != 0)
	{
		fprintf(fp, "\t\tBidPrice10 = %s -> %s    [�����ʮ]\n", boost::lexical_cast<std::string>(pOriginal->BidPrice10).c_str(), boost::lexical_cast<std::string>(BidPrice10).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBidPrice10 = %s    [�����ʮ]\n", boost::lexical_cast<std::string>(BidPrice10).c_str());
	}
	if (compare(BidVolume10, pOriginal->BidVolume10) != 0)
	{
		fprintf(fp, "\t\tBidVolume10 = %s -> %s    [������ʮ]\n", boost::lexical_cast<std::string>(pOriginal->BidVolume10).c_str(), boost::lexical_cast<std::string>(BidVolume10).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBidVolume10 = %s    [������ʮ]\n", boost::lexical_cast<std::string>(BidVolume10).c_str());
	}
	if (compare(AskPrice6, pOriginal->AskPrice6) != 0)
	{
		fprintf(fp, "\t\tAskPrice6 = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->AskPrice6).c_str(), boost::lexical_cast<std::string>(AskPrice6).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAskPrice6 = %s    [��������]\n", boost::lexical_cast<std::string>(AskPrice6).c_str());
	}
	if (compare(AskVolume6, pOriginal->AskVolume6) != 0)
	{
		fprintf(fp, "\t\tAskVolume6 = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->AskVolume6).c_str(), boost::lexical_cast<std::string>(AskVolume6).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAskVolume6 = %s    [��������]\n", boost::lexical_cast<std::string>(AskVolume6).c_str());
	}
	if (compare(AskPrice7, pOriginal->AskPrice7) != 0)
	{
		fprintf(fp, "\t\tAskPrice7 = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->AskPrice7).c_str(), boost::lexical_cast<std::string>(AskPrice7).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAskPrice7 = %s    [��������]\n", boost::lexical_cast<std::string>(AskPrice7).c_str());
	}
	if (compare(AskVolume7, pOriginal->AskVolume7) != 0)
	{
		fprintf(fp, "\t\tAskVolume7 = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->AskVolume7).c_str(), boost::lexical_cast<std::string>(AskVolume7).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAskVolume7 = %s    [��������]\n", boost::lexical_cast<std::string>(AskVolume7).c_str());
	}
	if (compare(AskPrice8, pOriginal->AskPrice8) != 0)
	{
		fprintf(fp, "\t\tAskPrice8 = %s -> %s    [�����۰�]\n", boost::lexical_cast<std::string>(pOriginal->AskPrice8).c_str(), boost::lexical_cast<std::string>(AskPrice8).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAskPrice8 = %s    [�����۰�]\n", boost::lexical_cast<std::string>(AskPrice8).c_str());
	}
	if (compare(AskVolume8, pOriginal->AskVolume8) != 0)
	{
		fprintf(fp, "\t\tAskVolume8 = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->AskVolume8).c_str(), boost::lexical_cast<std::string>(AskVolume8).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAskVolume8 = %s    [��������]\n", boost::lexical_cast<std::string>(AskVolume8).c_str());
	}
	if (compare(AskPrice9, pOriginal->AskPrice9) != 0)
	{
		fprintf(fp, "\t\tAskPrice9 = %s -> %s    [�����۾�]\n", boost::lexical_cast<std::string>(pOriginal->AskPrice9).c_str(), boost::lexical_cast<std::string>(AskPrice9).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAskPrice9 = %s    [�����۾�]\n", boost::lexical_cast<std::string>(AskPrice9).c_str());
	}
	if (compare(AskVolume9, pOriginal->AskVolume9) != 0)
	{
		fprintf(fp, "\t\tAskVolume9 = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->AskVolume9).c_str(), boost::lexical_cast<std::string>(AskVolume9).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAskVolume9 = %s    [��������]\n", boost::lexical_cast<std::string>(AskVolume9).c_str());
	}
	if (compare(AskPrice10, pOriginal->AskPrice10) != 0)
	{
		fprintf(fp, "\t\tAskPrice10 = %s -> %s    [������ʮ]\n", boost::lexical_cast<std::string>(pOriginal->AskPrice10).c_str(), boost::lexical_cast<std::string>(AskPrice10).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAskPrice10 = %s    [������ʮ]\n", boost::lexical_cast<std::string>(AskPrice10).c_str());
	}
	if (compare(AskVolume10, pOriginal->AskVolume10) != 0)
	{
		fprintf(fp, "\t\tAskVolume10 = %s -> %s    [������ʮ]\n", boost::lexical_cast<std::string>(pOriginal->AskVolume10).c_str(), boost::lexical_cast<std::string>(AskVolume10).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAskVolume10 = %s    [������ʮ]\n", boost::lexical_cast<std::string>(AskVolume10).c_str());
	}
	if (compare(SequenceNo, pOriginal->SequenceNo) != 0)
	{
		fprintf(fp, "\t\tSequenceNo = %s -> %s    [���]\n", boost::lexical_cast<std::string>(pOriginal->SequenceNo).c_str(), boost::lexical_cast<std::string>(SequenceNo).c_str());
	}
	else
	{
		fprintf(fp, "\t\tSequenceNo = %s    [���]\n", boost::lexical_cast<std::string>(SequenceNo).c_str());
	}
	if (compare(MarketName, pOriginal->MarketName) != 0)
	{
		fprintf(fp, "\t\tMarketName = %s -> %s    [�г�������]\n", boost::lexical_cast<std::string>(pOriginal->MarketName).c_str(), boost::lexical_cast<std::string>(MarketName).c_str());
	}
	else
	{
		fprintf(fp, "\t\tMarketName = %s    [�г�������]\n", boost::lexical_cast<std::string>(MarketName).c_str());
	}
	if (compare(InstrumentID, pOriginal->InstrumentID) != 0)
	{
		fprintf(fp, "\t\tInstrumentID = %s -> %s    [��Լ����]\n", boost::lexical_cast<std::string>(pOriginal->InstrumentID).c_str(), boost::lexical_cast<std::string>(InstrumentID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tInstrumentID = %s    [��Լ����]\n", boost::lexical_cast<std::string>(InstrumentID).c_str());
	}
	if (compare(InstrumentStatus, pOriginal->InstrumentStatus) != 0)
	{
		fprintf(fp, "\t\tInstrumentStatus = %s -> %s    [��Լ����״̬-1:δ֪0:����1:�޺���2:����3:����4:����5:����ǰ6:����ǰ7:����]\n", boost::lexical_cast<std::string>(pOriginal->InstrumentStatus).c_str(), boost::lexical_cast<std::string>(InstrumentStatus).c_str());
	}
	else
	{
		fprintf(fp, "\t\tInstrumentStatus = %s    [��Լ����״̬-1:δ֪0:����1:�޺���2:����3:����4:����5:����ǰ6:����ǰ7:����]\n", boost::lexical_cast<std::string>(InstrumentStatus).c_str());
	}
	if (compare(UpdateTime, pOriginal->UpdateTime) != 0)
	{
		fprintf(fp, "\t\tUpdateTime = %s -> %s    [����޸�ʱ��]\n", boost::lexical_cast<std::string>(pOriginal->UpdateTime).c_str(), boost::lexical_cast<std::string>(UpdateTime).c_str());
	}
	else
	{
		fprintf(fp, "\t\tUpdateTime = %s    [����޸�ʱ��]\n", boost::lexical_cast<std::string>(UpdateTime).c_str());
	}
	if (compare(UpdateMillisec, pOriginal->UpdateMillisec) != 0)
	{
		fprintf(fp, "\t\tUpdateMillisec = %s -> %s    [����޸ĺ���]\n", boost::lexical_cast<std::string>(pOriginal->UpdateMillisec).c_str(), boost::lexical_cast<std::string>(UpdateMillisec).c_str());
	}
	else
	{
		fprintf(fp, "\t\tUpdateMillisec = %s    [����޸ĺ���]\n", boost::lexical_cast<std::string>(UpdateMillisec).c_str());
	}
	fprintf(fp, "\t}\n");
}

void CExchDepthMarketData::dumpInLine(FILE *fp) const
{
	if (fp == nullptr)
	{
		fp = stdout;
	}
	std::stringstream sbuf;

	sbuf << ",TradingDay," << TradingDay;
	sbuf << ",PreClearPrice," << PreClearPrice;
	sbuf << ",PreClosePrice," << PreClosePrice;
	sbuf << ",PreOpenInterest," << PreOpenInterest;
	sbuf << ",PreDelta," << PreDelta;
	sbuf << ",HistoryHigh," << HistoryHigh;
	sbuf << ",HistoryLow," << HistoryLow;
	sbuf << ",OpenPrice," << OpenPrice;
	sbuf << ",HighestPrice," << HighestPrice;
	sbuf << ",LowestPrice," << LowestPrice;
	sbuf << ",ClosePrice," << ClosePrice;
	sbuf << ",UpperLimitPrice," << UpperLimitPrice;
	sbuf << ",LowerLimitPrice," << LowerLimitPrice;
	sbuf << ",ClearPrice," << ClearPrice;
	sbuf << ",CurrDelta," << CurrDelta;
	sbuf << ",Precision," << Precision;
	sbuf << ",LastPrice," << LastPrice;
	sbuf << ",Volume," << Volume;
	sbuf << ",Turnover," << Turnover;
	sbuf << ",OpenInterest," << OpenInterest;
	sbuf << ",NetChg," << NetChg;
	sbuf << ",Markup," << Markup;
	sbuf << ",Swing," << Swing;
	sbuf << ",AvgPrice," << AvgPrice;
	sbuf << ",BidPrice1," << BidPrice1;
	sbuf << ",BidVolume1," << BidVolume1;
	sbuf << ",AskPrice1," << AskPrice1;
	sbuf << ",AskVolume1," << AskVolume1;
	sbuf << ",BidPrice2," << BidPrice2;
	sbuf << ",BidVolume2," << BidVolume2;
	sbuf << ",BidPrice3," << BidPrice3;
	sbuf << ",BidVolume3," << BidVolume3;
	sbuf << ",AskPrice2," << AskPrice2;
	sbuf << ",AskVolume2," << AskVolume2;
	sbuf << ",AskPrice3," << AskPrice3;
	sbuf << ",AskVolume3," << AskVolume3;
	sbuf << ",BidPrice4," << BidPrice4;
	sbuf << ",BidVolume4," << BidVolume4;
	sbuf << ",BidPrice5," << BidPrice5;
	sbuf << ",BidVolume5," << BidVolume5;
	sbuf << ",AskPrice4," << AskPrice4;
	sbuf << ",AskVolume4," << AskVolume4;
	sbuf << ",AskPrice5," << AskPrice5;
	sbuf << ",AskVolume5," << AskVolume5;
	sbuf << ",BidPrice6," << BidPrice6;
	sbuf << ",BidVolume6," << BidVolume6;
	sbuf << ",BidPrice7," << BidPrice7;
	sbuf << ",BidVolume7," << BidVolume7;
	sbuf << ",BidPrice8," << BidPrice8;
	sbuf << ",BidVolume8," << BidVolume8;
	sbuf << ",BidPrice9," << BidPrice9;
	sbuf << ",BidVolume9," << BidVolume9;
	sbuf << ",BidPrice10," << BidPrice10;
	sbuf << ",BidVolume10," << BidVolume10;
	sbuf << ",AskPrice6," << AskPrice6;
	sbuf << ",AskVolume6," << AskVolume6;
	sbuf << ",AskPrice7," << AskPrice7;
	sbuf << ",AskVolume7," << AskVolume7;
	sbuf << ",AskPrice8," << AskPrice8;
	sbuf << ",AskVolume8," << AskVolume8;
	sbuf << ",AskPrice9," << AskPrice9;
	sbuf << ",AskVolume9," << AskVolume9;
	sbuf << ",AskPrice10," << AskPrice10;
	sbuf << ",AskVolume10," << AskVolume10;
	sbuf << ",SequenceNo," << SequenceNo;
	sbuf << ",MarketName," << MarketName;
	sbuf << ",InstrumentID," << InstrumentID;
	sbuf << ",InstrumentStatus," << InstrumentStatus;
	sbuf << ",UpdateTime," << UpdateTime;
	sbuf << ",UpdateMillisec," << UpdateMillisec;
	fprintf(fp, "%s", sbuf.str().c_str());
}

void CExchDepthMarketData::dumpString(char *target) const
{
	char *p = target;
	std::stringstream sbuf;

	sbuf << "TradingDay=" << TradingDay << ",";
	sbuf << "PreClearPrice=" << PreClearPrice << ",";
	sbuf << "PreClosePrice=" << PreClosePrice << ",";
	sbuf << "PreOpenInterest=" << PreOpenInterest << ",";
	sbuf << "PreDelta=" << PreDelta << ",";
	sbuf << "HistoryHigh=" << HistoryHigh << ",";
	sbuf << "HistoryLow=" << HistoryLow << ",";
	sbuf << "OpenPrice=" << OpenPrice << ",";
	sbuf << "HighestPrice=" << HighestPrice << ",";
	sbuf << "LowestPrice=" << LowestPrice << ",";
	sbuf << "ClosePrice=" << ClosePrice << ",";
	sbuf << "UpperLimitPrice=" << UpperLimitPrice << ",";
	sbuf << "LowerLimitPrice=" << LowerLimitPrice << ",";
	sbuf << "ClearPrice=" << ClearPrice << ",";
	sbuf << "CurrDelta=" << CurrDelta << ",";
	sbuf << "Precision=" << Precision << ",";
	sbuf << "LastPrice=" << LastPrice << ",";
	sbuf << "Volume=" << Volume << ",";
	sbuf << "Turnover=" << Turnover << ",";
	sbuf << "OpenInterest=" << OpenInterest << ",";
	sbuf << "NetChg=" << NetChg << ",";
	sbuf << "Markup=" << Markup << ",";
	sbuf << "Swing=" << Swing << ",";
	sbuf << "AvgPrice=" << AvgPrice << ",";
	sbuf << "BidPrice1=" << BidPrice1 << ",";
	sbuf << "BidVolume1=" << BidVolume1 << ",";
	sbuf << "AskPrice1=" << AskPrice1 << ",";
	sbuf << "AskVolume1=" << AskVolume1 << ",";
	sbuf << "BidPrice2=" << BidPrice2 << ",";
	sbuf << "BidVolume2=" << BidVolume2 << ",";
	sbuf << "BidPrice3=" << BidPrice3 << ",";
	sbuf << "BidVolume3=" << BidVolume3 << ",";
	sbuf << "AskPrice2=" << AskPrice2 << ",";
	sbuf << "AskVolume2=" << AskVolume2 << ",";
	sbuf << "AskPrice3=" << AskPrice3 << ",";
	sbuf << "AskVolume3=" << AskVolume3 << ",";
	sbuf << "BidPrice4=" << BidPrice4 << ",";
	sbuf << "BidVolume4=" << BidVolume4 << ",";
	sbuf << "BidPrice5=" << BidPrice5 << ",";
	sbuf << "BidVolume5=" << BidVolume5 << ",";
	sbuf << "AskPrice4=" << AskPrice4 << ",";
	sbuf << "AskVolume4=" << AskVolume4 << ",";
	sbuf << "AskPrice5=" << AskPrice5 << ",";
	sbuf << "AskVolume5=" << AskVolume5 << ",";
	sbuf << "BidPrice6=" << BidPrice6 << ",";
	sbuf << "BidVolume6=" << BidVolume6 << ",";
	sbuf << "BidPrice7=" << BidPrice7 << ",";
	sbuf << "BidVolume7=" << BidVolume7 << ",";
	sbuf << "BidPrice8=" << BidPrice8 << ",";
	sbuf << "BidVolume8=" << BidVolume8 << ",";
	sbuf << "BidPrice9=" << BidPrice9 << ",";
	sbuf << "BidVolume9=" << BidVolume9 << ",";
	sbuf << "BidPrice10=" << BidPrice10 << ",";
	sbuf << "BidVolume10=" << BidVolume10 << ",";
	sbuf << "AskPrice6=" << AskPrice6 << ",";
	sbuf << "AskVolume6=" << AskVolume6 << ",";
	sbuf << "AskPrice7=" << AskPrice7 << ",";
	sbuf << "AskVolume7=" << AskVolume7 << ",";
	sbuf << "AskPrice8=" << AskPrice8 << ",";
	sbuf << "AskVolume8=" << AskVolume8 << ",";
	sbuf << "AskPrice9=" << AskPrice9 << ",";
	sbuf << "AskVolume9=" << AskVolume9 << ",";
	sbuf << "AskPrice10=" << AskPrice10 << ",";
	sbuf << "AskVolume10=" << AskVolume10 << ",";
	sbuf << "SequenceNo=" << SequenceNo << ",";
	sbuf << "MarketName=" << MarketName << ",";
	sbuf << "InstrumentID=" << InstrumentID << ",";
	sbuf << "InstrumentStatus=" << InstrumentStatus << ",";
	sbuf << "UpdateTime=" << UpdateTime << ",";
	sbuf << "UpdateMillisec=" << UpdateMillisec << ",";

	sprintf(p, "%s", sbuf.str().c_str());
}

void CExchDepthMarketHistoryData::init(void)
{
	memset(this, 0, sizeof(CExchDepthMarketHistoryData));
}

int CExchDepthMarketHistoryData::read(FILE *input)
{
	if (fread(this, 1, sizeof(CExchDepthMarketHistoryData), input) != sizeof(CExchDepthMarketHistoryData))
		return 0;
	else
		return 1;
}

int CExchDepthMarketHistoryData::write(FILE *output) const
{
	if (fwrite(this, 1, sizeof(CExchDepthMarketHistoryData), output) != sizeof(CExchDepthMarketHistoryData))
		return 0;
	else
		return 1;
}

void CExchDepthMarketHistoryData::dump(FILE *fp, int index) const
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
	fprintf(fp, "\tCExchDepthMarketHistoryData%s = {\n", index_buf);
	fprintf(fp, "\t\tTradingDay = %s    [������]\n", boost::lexical_cast<std::string>(TradingDay).c_str());
	fprintf(fp, "\t\tPreClearPrice = %s    [�����]\n", boost::lexical_cast<std::string>(PreClearPrice).c_str());
	fprintf(fp, "\t\tPreClosePrice = %s    [������]\n", boost::lexical_cast<std::string>(PreClosePrice).c_str());
	fprintf(fp, "\t\tPreOpenInterest = %s    [��ֲ���]\n", boost::lexical_cast<std::string>(PreOpenInterest).c_str());
	fprintf(fp, "\t\tPreDelta = %s    [����ʵ��]\n", boost::lexical_cast<std::string>(PreDelta).c_str());
	fprintf(fp, "\t\tHistoryHigh = %s    [��Լ���]\n", boost::lexical_cast<std::string>(HistoryHigh).c_str());
	fprintf(fp, "\t\tHistoryLow = %s    [��Լ���]\n", boost::lexical_cast<std::string>(HistoryLow).c_str());
	fprintf(fp, "\t\tOpenPrice = %s    [����]\n", boost::lexical_cast<std::string>(OpenPrice).c_str());
	fprintf(fp, "\t\tHighestPrice = %s    [��߼�]\n", boost::lexical_cast<std::string>(HighestPrice).c_str());
	fprintf(fp, "\t\tLowestPrice = %s    [��ͼ�]\n", boost::lexical_cast<std::string>(LowestPrice).c_str());
	fprintf(fp, "\t\tClosePrice = %s    [������]\n", boost::lexical_cast<std::string>(ClosePrice).c_str());
	fprintf(fp, "\t\tUpperLimitPrice = %s    [��ͣ���]\n", boost::lexical_cast<std::string>(UpperLimitPrice).c_str());
	fprintf(fp, "\t\tLowerLimitPrice = %s    [��ͣ���]\n", boost::lexical_cast<std::string>(LowerLimitPrice).c_str());
	fprintf(fp, "\t\tClearPrice = %s    [���ν����]\n", boost::lexical_cast<std::string>(ClearPrice).c_str());
	fprintf(fp, "\t\tCurrDelta = %s    [����ʵ��]\n", boost::lexical_cast<std::string>(CurrDelta).c_str());
	fprintf(fp, "\t\tPrecision = %s    [���۾���]\n", boost::lexical_cast<std::string>(Precision).c_str());
	fprintf(fp, "\t\tLastPrice = %s    [���¼�]\n", boost::lexical_cast<std::string>(LastPrice).c_str());
	fprintf(fp, "\t\tVolume = %s    [����]\n", boost::lexical_cast<std::string>(Volume).c_str());
	fprintf(fp, "\t\tTurnover = %s    [�ɽ����]\n", boost::lexical_cast<std::string>(Turnover).c_str());
	fprintf(fp, "\t\tOpenInterest = %s    [�ֲ���]\n", boost::lexical_cast<std::string>(OpenInterest).c_str());
	fprintf(fp, "\t\tNetChg = %s    [�ǵ�]\n", boost::lexical_cast<std::string>(NetChg).c_str());
	fprintf(fp, "\t\tMarkup = %s    [�ǵ���]\n", boost::lexical_cast<std::string>(Markup).c_str());
	fprintf(fp, "\t\tSwing = %s    [���]\n", boost::lexical_cast<std::string>(Swing).c_str());
	fprintf(fp, "\t\tAvgPrice = %s    [ƽ����]\n", boost::lexical_cast<std::string>(AvgPrice).c_str());
	fprintf(fp, "\t\tBidPrice1 = %s    [�����һ]\n", boost::lexical_cast<std::string>(BidPrice1).c_str());
	fprintf(fp, "\t\tBidVolume1 = %s    [������һ]\n", boost::lexical_cast<std::string>(BidVolume1).c_str());
	fprintf(fp, "\t\tAskPrice1 = %s    [������һ]\n", boost::lexical_cast<std::string>(AskPrice1).c_str());
	fprintf(fp, "\t\tAskVolume1 = %s    [������һ]\n", boost::lexical_cast<std::string>(AskVolume1).c_str());
	fprintf(fp, "\t\tBidPrice2 = %s    [����۶�]\n", boost::lexical_cast<std::string>(BidPrice2).c_str());
	fprintf(fp, "\t\tBidVolume2 = %s    [��������]\n", boost::lexical_cast<std::string>(BidVolume2).c_str());
	fprintf(fp, "\t\tBidPrice3 = %s    [�������]\n", boost::lexical_cast<std::string>(BidPrice3).c_str());
	fprintf(fp, "\t\tBidVolume3 = %s    [��������]\n", boost::lexical_cast<std::string>(BidVolume3).c_str());
	fprintf(fp, "\t\tAskPrice2 = %s    [�����۶�]\n", boost::lexical_cast<std::string>(AskPrice2).c_str());
	fprintf(fp, "\t\tAskVolume2 = %s    [��������]\n", boost::lexical_cast<std::string>(AskVolume2).c_str());
	fprintf(fp, "\t\tAskPrice3 = %s    [��������]\n", boost::lexical_cast<std::string>(AskPrice3).c_str());
	fprintf(fp, "\t\tAskVolume3 = %s    [��������]\n", boost::lexical_cast<std::string>(AskVolume3).c_str());
	fprintf(fp, "\t\tBidPrice4 = %s    [�������]\n", boost::lexical_cast<std::string>(BidPrice4).c_str());
	fprintf(fp, "\t\tBidVolume4 = %s    [��������]\n", boost::lexical_cast<std::string>(BidVolume4).c_str());
	fprintf(fp, "\t\tBidPrice5 = %s    [�������]\n", boost::lexical_cast<std::string>(BidPrice5).c_str());
	fprintf(fp, "\t\tBidVolume5 = %s    [��������]\n", boost::lexical_cast<std::string>(BidVolume5).c_str());
	fprintf(fp, "\t\tAskPrice4 = %s    [��������]\n", boost::lexical_cast<std::string>(AskPrice4).c_str());
	fprintf(fp, "\t\tAskVolume4 = %s    [��������]\n", boost::lexical_cast<std::string>(AskVolume4).c_str());
	fprintf(fp, "\t\tAskPrice5 = %s    [��������]\n", boost::lexical_cast<std::string>(AskPrice5).c_str());
	fprintf(fp, "\t\tAskVolume5 = %s    [��������]\n", boost::lexical_cast<std::string>(AskVolume5).c_str());
	fprintf(fp, "\t\tBidPrice6 = %s    [�������]\n", boost::lexical_cast<std::string>(BidPrice6).c_str());
	fprintf(fp, "\t\tBidVolume6 = %s    [��������]\n", boost::lexical_cast<std::string>(BidVolume6).c_str());
	fprintf(fp, "\t\tBidPrice7 = %s    [�������]\n", boost::lexical_cast<std::string>(BidPrice7).c_str());
	fprintf(fp, "\t\tBidVolume7 = %s    [��������]\n", boost::lexical_cast<std::string>(BidVolume7).c_str());
	fprintf(fp, "\t\tBidPrice8 = %s    [����۰�]\n", boost::lexical_cast<std::string>(BidPrice8).c_str());
	fprintf(fp, "\t\tBidVolume8 = %s    [��������]\n", boost::lexical_cast<std::string>(BidVolume8).c_str());
	fprintf(fp, "\t\tBidPrice9 = %s    [����۾�]\n", boost::lexical_cast<std::string>(BidPrice9).c_str());
	fprintf(fp, "\t\tBidVolume9 = %s    [��������]\n", boost::lexical_cast<std::string>(BidVolume9).c_str());
	fprintf(fp, "\t\tBidPrice10 = %s    [�����ʮ]\n", boost::lexical_cast<std::string>(BidPrice10).c_str());
	fprintf(fp, "\t\tBidVolume10 = %s    [������ʮ]\n", boost::lexical_cast<std::string>(BidVolume10).c_str());
	fprintf(fp, "\t\tAskPrice6 = %s    [��������]\n", boost::lexical_cast<std::string>(AskPrice6).c_str());
	fprintf(fp, "\t\tAskVolume6 = %s    [��������]\n", boost::lexical_cast<std::string>(AskVolume6).c_str());
	fprintf(fp, "\t\tAskPrice7 = %s    [��������]\n", boost::lexical_cast<std::string>(AskPrice7).c_str());
	fprintf(fp, "\t\tAskVolume7 = %s    [��������]\n", boost::lexical_cast<std::string>(AskVolume7).c_str());
	fprintf(fp, "\t\tAskPrice8 = %s    [�����۰�]\n", boost::lexical_cast<std::string>(AskPrice8).c_str());
	fprintf(fp, "\t\tAskVolume8 = %s    [��������]\n", boost::lexical_cast<std::string>(AskVolume8).c_str());
	fprintf(fp, "\t\tAskPrice9 = %s    [�����۾�]\n", boost::lexical_cast<std::string>(AskPrice9).c_str());
	fprintf(fp, "\t\tAskVolume9 = %s    [��������]\n", boost::lexical_cast<std::string>(AskVolume9).c_str());
	fprintf(fp, "\t\tAskPrice10 = %s    [������ʮ]\n", boost::lexical_cast<std::string>(AskPrice10).c_str());
	fprintf(fp, "\t\tAskVolume10 = %s    [������ʮ]\n", boost::lexical_cast<std::string>(AskVolume10).c_str());
	fprintf(fp, "\t\tSequenceNo = %s    [���]\n", boost::lexical_cast<std::string>(SequenceNo).c_str());
	fprintf(fp, "\t\tMarketName = %s    [�г�������]\n", boost::lexical_cast<std::string>(MarketName).c_str());
	fprintf(fp, "\t\tInstrumentID = %s    [��Լ����]\n", boost::lexical_cast<std::string>(InstrumentID).c_str());
	fprintf(fp, "\t\tInstrumentStatus = %s    [��Լ����״̬-1:δ֪0:����1:�޺���2:����3:����4:����5:����ǰ6:����ǰ7:����]\n", boost::lexical_cast<std::string>(InstrumentStatus).c_str());
	fprintf(fp, "\t\tUpdateTime = %s    [����޸�ʱ��]\n", boost::lexical_cast<std::string>(UpdateTime).c_str());
	fprintf(fp, "\t\tUpdateMillisec = %s    [����޸ĺ���]\n", boost::lexical_cast<std::string>(UpdateMillisec).c_str());
	fprintf(fp, "\t}\n");
}

void CExchDepthMarketHistoryData::dumpDiff(FILE *fp, const CExchDepthMarketHistoryData *pOriginal) const
{
	if (fp == NULL)
	{
		fp = stdout;
	}
	fprintf(fp, "\tCExchDepthMarketHistoryData = {\n");
	if (compare(TradingDay, pOriginal->TradingDay) != 0)
	{
		fprintf(fp, "\t\tTradingDay = %s -> %s    [������]\n", boost::lexical_cast<std::string>(pOriginal->TradingDay).c_str(), boost::lexical_cast<std::string>(TradingDay).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTradingDay = %s    [������]\n", boost::lexical_cast<std::string>(TradingDay).c_str());
	}
	if (compare(PreClearPrice, pOriginal->PreClearPrice) != 0)
	{
		fprintf(fp, "\t\tPreClearPrice = %s -> %s    [�����]\n", boost::lexical_cast<std::string>(pOriginal->PreClearPrice).c_str(), boost::lexical_cast<std::string>(PreClearPrice).c_str());
	}
	else
	{
		fprintf(fp, "\t\tPreClearPrice = %s    [�����]\n", boost::lexical_cast<std::string>(PreClearPrice).c_str());
	}
	if (compare(PreClosePrice, pOriginal->PreClosePrice) != 0)
	{
		fprintf(fp, "\t\tPreClosePrice = %s -> %s    [������]\n", boost::lexical_cast<std::string>(pOriginal->PreClosePrice).c_str(), boost::lexical_cast<std::string>(PreClosePrice).c_str());
	}
	else
	{
		fprintf(fp, "\t\tPreClosePrice = %s    [������]\n", boost::lexical_cast<std::string>(PreClosePrice).c_str());
	}
	if (compare(PreOpenInterest, pOriginal->PreOpenInterest) != 0)
	{
		fprintf(fp, "\t\tPreOpenInterest = %s -> %s    [��ֲ���]\n", boost::lexical_cast<std::string>(pOriginal->PreOpenInterest).c_str(), boost::lexical_cast<std::string>(PreOpenInterest).c_str());
	}
	else
	{
		fprintf(fp, "\t\tPreOpenInterest = %s    [��ֲ���]\n", boost::lexical_cast<std::string>(PreOpenInterest).c_str());
	}
	if (compare(PreDelta, pOriginal->PreDelta) != 0)
	{
		fprintf(fp, "\t\tPreDelta = %s -> %s    [����ʵ��]\n", boost::lexical_cast<std::string>(pOriginal->PreDelta).c_str(), boost::lexical_cast<std::string>(PreDelta).c_str());
	}
	else
	{
		fprintf(fp, "\t\tPreDelta = %s    [����ʵ��]\n", boost::lexical_cast<std::string>(PreDelta).c_str());
	}
	if (compare(HistoryHigh, pOriginal->HistoryHigh) != 0)
	{
		fprintf(fp, "\t\tHistoryHigh = %s -> %s    [��Լ���]\n", boost::lexical_cast<std::string>(pOriginal->HistoryHigh).c_str(), boost::lexical_cast<std::string>(HistoryHigh).c_str());
	}
	else
	{
		fprintf(fp, "\t\tHistoryHigh = %s    [��Լ���]\n", boost::lexical_cast<std::string>(HistoryHigh).c_str());
	}
	if (compare(HistoryLow, pOriginal->HistoryLow) != 0)
	{
		fprintf(fp, "\t\tHistoryLow = %s -> %s    [��Լ���]\n", boost::lexical_cast<std::string>(pOriginal->HistoryLow).c_str(), boost::lexical_cast<std::string>(HistoryLow).c_str());
	}
	else
	{
		fprintf(fp, "\t\tHistoryLow = %s    [��Լ���]\n", boost::lexical_cast<std::string>(HistoryLow).c_str());
	}
	if (compare(OpenPrice, pOriginal->OpenPrice) != 0)
	{
		fprintf(fp, "\t\tOpenPrice = %s -> %s    [����]\n", boost::lexical_cast<std::string>(pOriginal->OpenPrice).c_str(), boost::lexical_cast<std::string>(OpenPrice).c_str());
	}
	else
	{
		fprintf(fp, "\t\tOpenPrice = %s    [����]\n", boost::lexical_cast<std::string>(OpenPrice).c_str());
	}
	if (compare(HighestPrice, pOriginal->HighestPrice) != 0)
	{
		fprintf(fp, "\t\tHighestPrice = %s -> %s    [��߼�]\n", boost::lexical_cast<std::string>(pOriginal->HighestPrice).c_str(), boost::lexical_cast<std::string>(HighestPrice).c_str());
	}
	else
	{
		fprintf(fp, "\t\tHighestPrice = %s    [��߼�]\n", boost::lexical_cast<std::string>(HighestPrice).c_str());
	}
	if (compare(LowestPrice, pOriginal->LowestPrice) != 0)
	{
		fprintf(fp, "\t\tLowestPrice = %s -> %s    [��ͼ�]\n", boost::lexical_cast<std::string>(pOriginal->LowestPrice).c_str(), boost::lexical_cast<std::string>(LowestPrice).c_str());
	}
	else
	{
		fprintf(fp, "\t\tLowestPrice = %s    [��ͼ�]\n", boost::lexical_cast<std::string>(LowestPrice).c_str());
	}
	if (compare(ClosePrice, pOriginal->ClosePrice) != 0)
	{
		fprintf(fp, "\t\tClosePrice = %s -> %s    [������]\n", boost::lexical_cast<std::string>(pOriginal->ClosePrice).c_str(), boost::lexical_cast<std::string>(ClosePrice).c_str());
	}
	else
	{
		fprintf(fp, "\t\tClosePrice = %s    [������]\n", boost::lexical_cast<std::string>(ClosePrice).c_str());
	}
	if (compare(UpperLimitPrice, pOriginal->UpperLimitPrice) != 0)
	{
		fprintf(fp, "\t\tUpperLimitPrice = %s -> %s    [��ͣ���]\n", boost::lexical_cast<std::string>(pOriginal->UpperLimitPrice).c_str(), boost::lexical_cast<std::string>(UpperLimitPrice).c_str());
	}
	else
	{
		fprintf(fp, "\t\tUpperLimitPrice = %s    [��ͣ���]\n", boost::lexical_cast<std::string>(UpperLimitPrice).c_str());
	}
	if (compare(LowerLimitPrice, pOriginal->LowerLimitPrice) != 0)
	{
		fprintf(fp, "\t\tLowerLimitPrice = %s -> %s    [��ͣ���]\n", boost::lexical_cast<std::string>(pOriginal->LowerLimitPrice).c_str(), boost::lexical_cast<std::string>(LowerLimitPrice).c_str());
	}
	else
	{
		fprintf(fp, "\t\tLowerLimitPrice = %s    [��ͣ���]\n", boost::lexical_cast<std::string>(LowerLimitPrice).c_str());
	}
	if (compare(ClearPrice, pOriginal->ClearPrice) != 0)
	{
		fprintf(fp, "\t\tClearPrice = %s -> %s    [���ν����]\n", boost::lexical_cast<std::string>(pOriginal->ClearPrice).c_str(), boost::lexical_cast<std::string>(ClearPrice).c_str());
	}
	else
	{
		fprintf(fp, "\t\tClearPrice = %s    [���ν����]\n", boost::lexical_cast<std::string>(ClearPrice).c_str());
	}
	if (compare(CurrDelta, pOriginal->CurrDelta) != 0)
	{
		fprintf(fp, "\t\tCurrDelta = %s -> %s    [����ʵ��]\n", boost::lexical_cast<std::string>(pOriginal->CurrDelta).c_str(), boost::lexical_cast<std::string>(CurrDelta).c_str());
	}
	else
	{
		fprintf(fp, "\t\tCurrDelta = %s    [����ʵ��]\n", boost::lexical_cast<std::string>(CurrDelta).c_str());
	}
	if (compare(Precision, pOriginal->Precision) != 0)
	{
		fprintf(fp, "\t\tPrecision = %s -> %s    [���۾���]\n", boost::lexical_cast<std::string>(pOriginal->Precision).c_str(), boost::lexical_cast<std::string>(Precision).c_str());
	}
	else
	{
		fprintf(fp, "\t\tPrecision = %s    [���۾���]\n", boost::lexical_cast<std::string>(Precision).c_str());
	}
	if (compare(LastPrice, pOriginal->LastPrice) != 0)
	{
		fprintf(fp, "\t\tLastPrice = %s -> %s    [���¼�]\n", boost::lexical_cast<std::string>(pOriginal->LastPrice).c_str(), boost::lexical_cast<std::string>(LastPrice).c_str());
	}
	else
	{
		fprintf(fp, "\t\tLastPrice = %s    [���¼�]\n", boost::lexical_cast<std::string>(LastPrice).c_str());
	}
	if (compare(Volume, pOriginal->Volume) != 0)
	{
		fprintf(fp, "\t\tVolume = %s -> %s    [����]\n", boost::lexical_cast<std::string>(pOriginal->Volume).c_str(), boost::lexical_cast<std::string>(Volume).c_str());
	}
	else
	{
		fprintf(fp, "\t\tVolume = %s    [����]\n", boost::lexical_cast<std::string>(Volume).c_str());
	}
	if (compare(Turnover, pOriginal->Turnover) != 0)
	{
		fprintf(fp, "\t\tTurnover = %s -> %s    [�ɽ����]\n", boost::lexical_cast<std::string>(pOriginal->Turnover).c_str(), boost::lexical_cast<std::string>(Turnover).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTurnover = %s    [�ɽ����]\n", boost::lexical_cast<std::string>(Turnover).c_str());
	}
	if (compare(OpenInterest, pOriginal->OpenInterest) != 0)
	{
		fprintf(fp, "\t\tOpenInterest = %s -> %s    [�ֲ���]\n", boost::lexical_cast<std::string>(pOriginal->OpenInterest).c_str(), boost::lexical_cast<std::string>(OpenInterest).c_str());
	}
	else
	{
		fprintf(fp, "\t\tOpenInterest = %s    [�ֲ���]\n", boost::lexical_cast<std::string>(OpenInterest).c_str());
	}
	if (compare(NetChg, pOriginal->NetChg) != 0)
	{
		fprintf(fp, "\t\tNetChg = %s -> %s    [�ǵ�]\n", boost::lexical_cast<std::string>(pOriginal->NetChg).c_str(), boost::lexical_cast<std::string>(NetChg).c_str());
	}
	else
	{
		fprintf(fp, "\t\tNetChg = %s    [�ǵ�]\n", boost::lexical_cast<std::string>(NetChg).c_str());
	}
	if (compare(Markup, pOriginal->Markup) != 0)
	{
		fprintf(fp, "\t\tMarkup = %s -> %s    [�ǵ���]\n", boost::lexical_cast<std::string>(pOriginal->Markup).c_str(), boost::lexical_cast<std::string>(Markup).c_str());
	}
	else
	{
		fprintf(fp, "\t\tMarkup = %s    [�ǵ���]\n", boost::lexical_cast<std::string>(Markup).c_str());
	}
	if (compare(Swing, pOriginal->Swing) != 0)
	{
		fprintf(fp, "\t\tSwing = %s -> %s    [���]\n", boost::lexical_cast<std::string>(pOriginal->Swing).c_str(), boost::lexical_cast<std::string>(Swing).c_str());
	}
	else
	{
		fprintf(fp, "\t\tSwing = %s    [���]\n", boost::lexical_cast<std::string>(Swing).c_str());
	}
	if (compare(AvgPrice, pOriginal->AvgPrice) != 0)
	{
		fprintf(fp, "\t\tAvgPrice = %s -> %s    [ƽ����]\n", boost::lexical_cast<std::string>(pOriginal->AvgPrice).c_str(), boost::lexical_cast<std::string>(AvgPrice).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAvgPrice = %s    [ƽ����]\n", boost::lexical_cast<std::string>(AvgPrice).c_str());
	}
	if (compare(BidPrice1, pOriginal->BidPrice1) != 0)
	{
		fprintf(fp, "\t\tBidPrice1 = %s -> %s    [�����һ]\n", boost::lexical_cast<std::string>(pOriginal->BidPrice1).c_str(), boost::lexical_cast<std::string>(BidPrice1).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBidPrice1 = %s    [�����һ]\n", boost::lexical_cast<std::string>(BidPrice1).c_str());
	}
	if (compare(BidVolume1, pOriginal->BidVolume1) != 0)
	{
		fprintf(fp, "\t\tBidVolume1 = %s -> %s    [������һ]\n", boost::lexical_cast<std::string>(pOriginal->BidVolume1).c_str(), boost::lexical_cast<std::string>(BidVolume1).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBidVolume1 = %s    [������һ]\n", boost::lexical_cast<std::string>(BidVolume1).c_str());
	}
	if (compare(AskPrice1, pOriginal->AskPrice1) != 0)
	{
		fprintf(fp, "\t\tAskPrice1 = %s -> %s    [������һ]\n", boost::lexical_cast<std::string>(pOriginal->AskPrice1).c_str(), boost::lexical_cast<std::string>(AskPrice1).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAskPrice1 = %s    [������һ]\n", boost::lexical_cast<std::string>(AskPrice1).c_str());
	}
	if (compare(AskVolume1, pOriginal->AskVolume1) != 0)
	{
		fprintf(fp, "\t\tAskVolume1 = %s -> %s    [������һ]\n", boost::lexical_cast<std::string>(pOriginal->AskVolume1).c_str(), boost::lexical_cast<std::string>(AskVolume1).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAskVolume1 = %s    [������һ]\n", boost::lexical_cast<std::string>(AskVolume1).c_str());
	}
	if (compare(BidPrice2, pOriginal->BidPrice2) != 0)
	{
		fprintf(fp, "\t\tBidPrice2 = %s -> %s    [����۶�]\n", boost::lexical_cast<std::string>(pOriginal->BidPrice2).c_str(), boost::lexical_cast<std::string>(BidPrice2).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBidPrice2 = %s    [����۶�]\n", boost::lexical_cast<std::string>(BidPrice2).c_str());
	}
	if (compare(BidVolume2, pOriginal->BidVolume2) != 0)
	{
		fprintf(fp, "\t\tBidVolume2 = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->BidVolume2).c_str(), boost::lexical_cast<std::string>(BidVolume2).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBidVolume2 = %s    [��������]\n", boost::lexical_cast<std::string>(BidVolume2).c_str());
	}
	if (compare(BidPrice3, pOriginal->BidPrice3) != 0)
	{
		fprintf(fp, "\t\tBidPrice3 = %s -> %s    [�������]\n", boost::lexical_cast<std::string>(pOriginal->BidPrice3).c_str(), boost::lexical_cast<std::string>(BidPrice3).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBidPrice3 = %s    [�������]\n", boost::lexical_cast<std::string>(BidPrice3).c_str());
	}
	if (compare(BidVolume3, pOriginal->BidVolume3) != 0)
	{
		fprintf(fp, "\t\tBidVolume3 = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->BidVolume3).c_str(), boost::lexical_cast<std::string>(BidVolume3).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBidVolume3 = %s    [��������]\n", boost::lexical_cast<std::string>(BidVolume3).c_str());
	}
	if (compare(AskPrice2, pOriginal->AskPrice2) != 0)
	{
		fprintf(fp, "\t\tAskPrice2 = %s -> %s    [�����۶�]\n", boost::lexical_cast<std::string>(pOriginal->AskPrice2).c_str(), boost::lexical_cast<std::string>(AskPrice2).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAskPrice2 = %s    [�����۶�]\n", boost::lexical_cast<std::string>(AskPrice2).c_str());
	}
	if (compare(AskVolume2, pOriginal->AskVolume2) != 0)
	{
		fprintf(fp, "\t\tAskVolume2 = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->AskVolume2).c_str(), boost::lexical_cast<std::string>(AskVolume2).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAskVolume2 = %s    [��������]\n", boost::lexical_cast<std::string>(AskVolume2).c_str());
	}
	if (compare(AskPrice3, pOriginal->AskPrice3) != 0)
	{
		fprintf(fp, "\t\tAskPrice3 = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->AskPrice3).c_str(), boost::lexical_cast<std::string>(AskPrice3).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAskPrice3 = %s    [��������]\n", boost::lexical_cast<std::string>(AskPrice3).c_str());
	}
	if (compare(AskVolume3, pOriginal->AskVolume3) != 0)
	{
		fprintf(fp, "\t\tAskVolume3 = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->AskVolume3).c_str(), boost::lexical_cast<std::string>(AskVolume3).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAskVolume3 = %s    [��������]\n", boost::lexical_cast<std::string>(AskVolume3).c_str());
	}
	if (compare(BidPrice4, pOriginal->BidPrice4) != 0)
	{
		fprintf(fp, "\t\tBidPrice4 = %s -> %s    [�������]\n", boost::lexical_cast<std::string>(pOriginal->BidPrice4).c_str(), boost::lexical_cast<std::string>(BidPrice4).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBidPrice4 = %s    [�������]\n", boost::lexical_cast<std::string>(BidPrice4).c_str());
	}
	if (compare(BidVolume4, pOriginal->BidVolume4) != 0)
	{
		fprintf(fp, "\t\tBidVolume4 = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->BidVolume4).c_str(), boost::lexical_cast<std::string>(BidVolume4).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBidVolume4 = %s    [��������]\n", boost::lexical_cast<std::string>(BidVolume4).c_str());
	}
	if (compare(BidPrice5, pOriginal->BidPrice5) != 0)
	{
		fprintf(fp, "\t\tBidPrice5 = %s -> %s    [�������]\n", boost::lexical_cast<std::string>(pOriginal->BidPrice5).c_str(), boost::lexical_cast<std::string>(BidPrice5).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBidPrice5 = %s    [�������]\n", boost::lexical_cast<std::string>(BidPrice5).c_str());
	}
	if (compare(BidVolume5, pOriginal->BidVolume5) != 0)
	{
		fprintf(fp, "\t\tBidVolume5 = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->BidVolume5).c_str(), boost::lexical_cast<std::string>(BidVolume5).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBidVolume5 = %s    [��������]\n", boost::lexical_cast<std::string>(BidVolume5).c_str());
	}
	if (compare(AskPrice4, pOriginal->AskPrice4) != 0)
	{
		fprintf(fp, "\t\tAskPrice4 = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->AskPrice4).c_str(), boost::lexical_cast<std::string>(AskPrice4).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAskPrice4 = %s    [��������]\n", boost::lexical_cast<std::string>(AskPrice4).c_str());
	}
	if (compare(AskVolume4, pOriginal->AskVolume4) != 0)
	{
		fprintf(fp, "\t\tAskVolume4 = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->AskVolume4).c_str(), boost::lexical_cast<std::string>(AskVolume4).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAskVolume4 = %s    [��������]\n", boost::lexical_cast<std::string>(AskVolume4).c_str());
	}
	if (compare(AskPrice5, pOriginal->AskPrice5) != 0)
	{
		fprintf(fp, "\t\tAskPrice5 = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->AskPrice5).c_str(), boost::lexical_cast<std::string>(AskPrice5).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAskPrice5 = %s    [��������]\n", boost::lexical_cast<std::string>(AskPrice5).c_str());
	}
	if (compare(AskVolume5, pOriginal->AskVolume5) != 0)
	{
		fprintf(fp, "\t\tAskVolume5 = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->AskVolume5).c_str(), boost::lexical_cast<std::string>(AskVolume5).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAskVolume5 = %s    [��������]\n", boost::lexical_cast<std::string>(AskVolume5).c_str());
	}
	if (compare(BidPrice6, pOriginal->BidPrice6) != 0)
	{
		fprintf(fp, "\t\tBidPrice6 = %s -> %s    [�������]\n", boost::lexical_cast<std::string>(pOriginal->BidPrice6).c_str(), boost::lexical_cast<std::string>(BidPrice6).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBidPrice6 = %s    [�������]\n", boost::lexical_cast<std::string>(BidPrice6).c_str());
	}
	if (compare(BidVolume6, pOriginal->BidVolume6) != 0)
	{
		fprintf(fp, "\t\tBidVolume6 = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->BidVolume6).c_str(), boost::lexical_cast<std::string>(BidVolume6).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBidVolume6 = %s    [��������]\n", boost::lexical_cast<std::string>(BidVolume6).c_str());
	}
	if (compare(BidPrice7, pOriginal->BidPrice7) != 0)
	{
		fprintf(fp, "\t\tBidPrice7 = %s -> %s    [�������]\n", boost::lexical_cast<std::string>(pOriginal->BidPrice7).c_str(), boost::lexical_cast<std::string>(BidPrice7).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBidPrice7 = %s    [�������]\n", boost::lexical_cast<std::string>(BidPrice7).c_str());
	}
	if (compare(BidVolume7, pOriginal->BidVolume7) != 0)
	{
		fprintf(fp, "\t\tBidVolume7 = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->BidVolume7).c_str(), boost::lexical_cast<std::string>(BidVolume7).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBidVolume7 = %s    [��������]\n", boost::lexical_cast<std::string>(BidVolume7).c_str());
	}
	if (compare(BidPrice8, pOriginal->BidPrice8) != 0)
	{
		fprintf(fp, "\t\tBidPrice8 = %s -> %s    [����۰�]\n", boost::lexical_cast<std::string>(pOriginal->BidPrice8).c_str(), boost::lexical_cast<std::string>(BidPrice8).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBidPrice8 = %s    [����۰�]\n", boost::lexical_cast<std::string>(BidPrice8).c_str());
	}
	if (compare(BidVolume8, pOriginal->BidVolume8) != 0)
	{
		fprintf(fp, "\t\tBidVolume8 = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->BidVolume8).c_str(), boost::lexical_cast<std::string>(BidVolume8).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBidVolume8 = %s    [��������]\n", boost::lexical_cast<std::string>(BidVolume8).c_str());
	}
	if (compare(BidPrice9, pOriginal->BidPrice9) != 0)
	{
		fprintf(fp, "\t\tBidPrice9 = %s -> %s    [����۾�]\n", boost::lexical_cast<std::string>(pOriginal->BidPrice9).c_str(), boost::lexical_cast<std::string>(BidPrice9).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBidPrice9 = %s    [����۾�]\n", boost::lexical_cast<std::string>(BidPrice9).c_str());
	}
	if (compare(BidVolume9, pOriginal->BidVolume9) != 0)
	{
		fprintf(fp, "\t\tBidVolume9 = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->BidVolume9).c_str(), boost::lexical_cast<std::string>(BidVolume9).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBidVolume9 = %s    [��������]\n", boost::lexical_cast<std::string>(BidVolume9).c_str());
	}
	if (compare(BidPrice10, pOriginal->BidPrice10) != 0)
	{
		fprintf(fp, "\t\tBidPrice10 = %s -> %s    [�����ʮ]\n", boost::lexical_cast<std::string>(pOriginal->BidPrice10).c_str(), boost::lexical_cast<std::string>(BidPrice10).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBidPrice10 = %s    [�����ʮ]\n", boost::lexical_cast<std::string>(BidPrice10).c_str());
	}
	if (compare(BidVolume10, pOriginal->BidVolume10) != 0)
	{
		fprintf(fp, "\t\tBidVolume10 = %s -> %s    [������ʮ]\n", boost::lexical_cast<std::string>(pOriginal->BidVolume10).c_str(), boost::lexical_cast<std::string>(BidVolume10).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBidVolume10 = %s    [������ʮ]\n", boost::lexical_cast<std::string>(BidVolume10).c_str());
	}
	if (compare(AskPrice6, pOriginal->AskPrice6) != 0)
	{
		fprintf(fp, "\t\tAskPrice6 = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->AskPrice6).c_str(), boost::lexical_cast<std::string>(AskPrice6).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAskPrice6 = %s    [��������]\n", boost::lexical_cast<std::string>(AskPrice6).c_str());
	}
	if (compare(AskVolume6, pOriginal->AskVolume6) != 0)
	{
		fprintf(fp, "\t\tAskVolume6 = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->AskVolume6).c_str(), boost::lexical_cast<std::string>(AskVolume6).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAskVolume6 = %s    [��������]\n", boost::lexical_cast<std::string>(AskVolume6).c_str());
	}
	if (compare(AskPrice7, pOriginal->AskPrice7) != 0)
	{
		fprintf(fp, "\t\tAskPrice7 = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->AskPrice7).c_str(), boost::lexical_cast<std::string>(AskPrice7).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAskPrice7 = %s    [��������]\n", boost::lexical_cast<std::string>(AskPrice7).c_str());
	}
	if (compare(AskVolume7, pOriginal->AskVolume7) != 0)
	{
		fprintf(fp, "\t\tAskVolume7 = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->AskVolume7).c_str(), boost::lexical_cast<std::string>(AskVolume7).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAskVolume7 = %s    [��������]\n", boost::lexical_cast<std::string>(AskVolume7).c_str());
	}
	if (compare(AskPrice8, pOriginal->AskPrice8) != 0)
	{
		fprintf(fp, "\t\tAskPrice8 = %s -> %s    [�����۰�]\n", boost::lexical_cast<std::string>(pOriginal->AskPrice8).c_str(), boost::lexical_cast<std::string>(AskPrice8).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAskPrice8 = %s    [�����۰�]\n", boost::lexical_cast<std::string>(AskPrice8).c_str());
	}
	if (compare(AskVolume8, pOriginal->AskVolume8) != 0)
	{
		fprintf(fp, "\t\tAskVolume8 = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->AskVolume8).c_str(), boost::lexical_cast<std::string>(AskVolume8).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAskVolume8 = %s    [��������]\n", boost::lexical_cast<std::string>(AskVolume8).c_str());
	}
	if (compare(AskPrice9, pOriginal->AskPrice9) != 0)
	{
		fprintf(fp, "\t\tAskPrice9 = %s -> %s    [�����۾�]\n", boost::lexical_cast<std::string>(pOriginal->AskPrice9).c_str(), boost::lexical_cast<std::string>(AskPrice9).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAskPrice9 = %s    [�����۾�]\n", boost::lexical_cast<std::string>(AskPrice9).c_str());
	}
	if (compare(AskVolume9, pOriginal->AskVolume9) != 0)
	{
		fprintf(fp, "\t\tAskVolume9 = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->AskVolume9).c_str(), boost::lexical_cast<std::string>(AskVolume9).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAskVolume9 = %s    [��������]\n", boost::lexical_cast<std::string>(AskVolume9).c_str());
	}
	if (compare(AskPrice10, pOriginal->AskPrice10) != 0)
	{
		fprintf(fp, "\t\tAskPrice10 = %s -> %s    [������ʮ]\n", boost::lexical_cast<std::string>(pOriginal->AskPrice10).c_str(), boost::lexical_cast<std::string>(AskPrice10).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAskPrice10 = %s    [������ʮ]\n", boost::lexical_cast<std::string>(AskPrice10).c_str());
	}
	if (compare(AskVolume10, pOriginal->AskVolume10) != 0)
	{
		fprintf(fp, "\t\tAskVolume10 = %s -> %s    [������ʮ]\n", boost::lexical_cast<std::string>(pOriginal->AskVolume10).c_str(), boost::lexical_cast<std::string>(AskVolume10).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAskVolume10 = %s    [������ʮ]\n", boost::lexical_cast<std::string>(AskVolume10).c_str());
	}
	if (compare(SequenceNo, pOriginal->SequenceNo) != 0)
	{
		fprintf(fp, "\t\tSequenceNo = %s -> %s    [���]\n", boost::lexical_cast<std::string>(pOriginal->SequenceNo).c_str(), boost::lexical_cast<std::string>(SequenceNo).c_str());
	}
	else
	{
		fprintf(fp, "\t\tSequenceNo = %s    [���]\n", boost::lexical_cast<std::string>(SequenceNo).c_str());
	}
	if (compare(MarketName, pOriginal->MarketName) != 0)
	{
		fprintf(fp, "\t\tMarketName = %s -> %s    [�г�������]\n", boost::lexical_cast<std::string>(pOriginal->MarketName).c_str(), boost::lexical_cast<std::string>(MarketName).c_str());
	}
	else
	{
		fprintf(fp, "\t\tMarketName = %s    [�г�������]\n", boost::lexical_cast<std::string>(MarketName).c_str());
	}
	if (compare(InstrumentID, pOriginal->InstrumentID) != 0)
	{
		fprintf(fp, "\t\tInstrumentID = %s -> %s    [��Լ����]\n", boost::lexical_cast<std::string>(pOriginal->InstrumentID).c_str(), boost::lexical_cast<std::string>(InstrumentID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tInstrumentID = %s    [��Լ����]\n", boost::lexical_cast<std::string>(InstrumentID).c_str());
	}
	if (compare(InstrumentStatus, pOriginal->InstrumentStatus) != 0)
	{
		fprintf(fp, "\t\tInstrumentStatus = %s -> %s    [��Լ����״̬-1:δ֪0:����1:�޺���2:����3:����4:����5:����ǰ6:����ǰ7:����]\n", boost::lexical_cast<std::string>(pOriginal->InstrumentStatus).c_str(), boost::lexical_cast<std::string>(InstrumentStatus).c_str());
	}
	else
	{
		fprintf(fp, "\t\tInstrumentStatus = %s    [��Լ����״̬-1:δ֪0:����1:�޺���2:����3:����4:����5:����ǰ6:����ǰ7:����]\n", boost::lexical_cast<std::string>(InstrumentStatus).c_str());
	}
	if (compare(UpdateTime, pOriginal->UpdateTime) != 0)
	{
		fprintf(fp, "\t\tUpdateTime = %s -> %s    [����޸�ʱ��]\n", boost::lexical_cast<std::string>(pOriginal->UpdateTime).c_str(), boost::lexical_cast<std::string>(UpdateTime).c_str());
	}
	else
	{
		fprintf(fp, "\t\tUpdateTime = %s    [����޸�ʱ��]\n", boost::lexical_cast<std::string>(UpdateTime).c_str());
	}
	if (compare(UpdateMillisec, pOriginal->UpdateMillisec) != 0)
	{
		fprintf(fp, "\t\tUpdateMillisec = %s -> %s    [����޸ĺ���]\n", boost::lexical_cast<std::string>(pOriginal->UpdateMillisec).c_str(), boost::lexical_cast<std::string>(UpdateMillisec).c_str());
	}
	else
	{
		fprintf(fp, "\t\tUpdateMillisec = %s    [����޸ĺ���]\n", boost::lexical_cast<std::string>(UpdateMillisec).c_str());
	}
	fprintf(fp, "\t}\n");
}

void CExchDepthMarketHistoryData::dumpInLine(FILE *fp) const
{
	if (fp == nullptr)
	{
		fp = stdout;
	}
	std::stringstream sbuf;

	sbuf << ",TradingDay," << TradingDay;
	sbuf << ",PreClearPrice," << PreClearPrice;
	sbuf << ",PreClosePrice," << PreClosePrice;
	sbuf << ",PreOpenInterest," << PreOpenInterest;
	sbuf << ",PreDelta," << PreDelta;
	sbuf << ",HistoryHigh," << HistoryHigh;
	sbuf << ",HistoryLow," << HistoryLow;
	sbuf << ",OpenPrice," << OpenPrice;
	sbuf << ",HighestPrice," << HighestPrice;
	sbuf << ",LowestPrice," << LowestPrice;
	sbuf << ",ClosePrice," << ClosePrice;
	sbuf << ",UpperLimitPrice," << UpperLimitPrice;
	sbuf << ",LowerLimitPrice," << LowerLimitPrice;
	sbuf << ",ClearPrice," << ClearPrice;
	sbuf << ",CurrDelta," << CurrDelta;
	sbuf << ",Precision," << Precision;
	sbuf << ",LastPrice," << LastPrice;
	sbuf << ",Volume," << Volume;
	sbuf << ",Turnover," << Turnover;
	sbuf << ",OpenInterest," << OpenInterest;
	sbuf << ",NetChg," << NetChg;
	sbuf << ",Markup," << Markup;
	sbuf << ",Swing," << Swing;
	sbuf << ",AvgPrice," << AvgPrice;
	sbuf << ",BidPrice1," << BidPrice1;
	sbuf << ",BidVolume1," << BidVolume1;
	sbuf << ",AskPrice1," << AskPrice1;
	sbuf << ",AskVolume1," << AskVolume1;
	sbuf << ",BidPrice2," << BidPrice2;
	sbuf << ",BidVolume2," << BidVolume2;
	sbuf << ",BidPrice3," << BidPrice3;
	sbuf << ",BidVolume3," << BidVolume3;
	sbuf << ",AskPrice2," << AskPrice2;
	sbuf << ",AskVolume2," << AskVolume2;
	sbuf << ",AskPrice3," << AskPrice3;
	sbuf << ",AskVolume3," << AskVolume3;
	sbuf << ",BidPrice4," << BidPrice4;
	sbuf << ",BidVolume4," << BidVolume4;
	sbuf << ",BidPrice5," << BidPrice5;
	sbuf << ",BidVolume5," << BidVolume5;
	sbuf << ",AskPrice4," << AskPrice4;
	sbuf << ",AskVolume4," << AskVolume4;
	sbuf << ",AskPrice5," << AskPrice5;
	sbuf << ",AskVolume5," << AskVolume5;
	sbuf << ",BidPrice6," << BidPrice6;
	sbuf << ",BidVolume6," << BidVolume6;
	sbuf << ",BidPrice7," << BidPrice7;
	sbuf << ",BidVolume7," << BidVolume7;
	sbuf << ",BidPrice8," << BidPrice8;
	sbuf << ",BidVolume8," << BidVolume8;
	sbuf << ",BidPrice9," << BidPrice9;
	sbuf << ",BidVolume9," << BidVolume9;
	sbuf << ",BidPrice10," << BidPrice10;
	sbuf << ",BidVolume10," << BidVolume10;
	sbuf << ",AskPrice6," << AskPrice6;
	sbuf << ",AskVolume6," << AskVolume6;
	sbuf << ",AskPrice7," << AskPrice7;
	sbuf << ",AskVolume7," << AskVolume7;
	sbuf << ",AskPrice8," << AskPrice8;
	sbuf << ",AskVolume8," << AskVolume8;
	sbuf << ",AskPrice9," << AskPrice9;
	sbuf << ",AskVolume9," << AskVolume9;
	sbuf << ",AskPrice10," << AskPrice10;
	sbuf << ",AskVolume10," << AskVolume10;
	sbuf << ",SequenceNo," << SequenceNo;
	sbuf << ",MarketName," << MarketName;
	sbuf << ",InstrumentID," << InstrumentID;
	sbuf << ",InstrumentStatus," << InstrumentStatus;
	sbuf << ",UpdateTime," << UpdateTime;
	sbuf << ",UpdateMillisec," << UpdateMillisec;
	fprintf(fp, "%s", sbuf.str().c_str());
}

void CExchDepthMarketHistoryData::dumpString(char *target) const
{
	char *p = target;

	std::stringstream sbuf;

	sbuf << "TradingDay=" << TradingDay << ",";
	sbuf << "PreClearPrice=" << PreClearPrice << ",";
	sbuf << "PreClosePrice=" << PreClosePrice << ",";
	sbuf << "PreOpenInterest=" << PreOpenInterest << ",";
	sbuf << "PreDelta=" << PreDelta << ",";
	sbuf << "HistoryHigh=" << HistoryHigh << ",";
	sbuf << "HistoryLow=" << HistoryLow << ",";
	sbuf << "OpenPrice=" << OpenPrice << ",";
	sbuf << "HighestPrice=" << HighestPrice << ",";
	sbuf << "LowestPrice=" << LowestPrice << ",";
	sbuf << "ClosePrice=" << ClosePrice << ",";
	sbuf << "UpperLimitPrice=" << UpperLimitPrice << ",";
	sbuf << "LowerLimitPrice=" << LowerLimitPrice << ",";
	sbuf << "ClearPrice=" << ClearPrice << ",";
	sbuf << "CurrDelta=" << CurrDelta << ",";
	sbuf << "Precision=" << Precision << ",";
	sbuf << "LastPrice=" << LastPrice << ",";
	sbuf << "Volume=" << Volume << ",";
	sbuf << "Turnover=" << Turnover << ",";
	sbuf << "OpenInterest=" << OpenInterest << ",";
	sbuf << "NetChg=" << NetChg << ",";
	sbuf << "Markup=" << Markup << ",";
	sbuf << "Swing=" << Swing << ",";
	sbuf << "AvgPrice=" << AvgPrice << ",";
	sbuf << "BidPrice1=" << BidPrice1 << ",";
	sbuf << "BidVolume1=" << BidVolume1 << ",";
	sbuf << "AskPrice1=" << AskPrice1 << ",";
	sbuf << "AskVolume1=" << AskVolume1 << ",";
	sbuf << "BidPrice2=" << BidPrice2 << ",";
	sbuf << "BidVolume2=" << BidVolume2 << ",";
	sbuf << "BidPrice3=" << BidPrice3 << ",";
	sbuf << "BidVolume3=" << BidVolume3 << ",";
	sbuf << "AskPrice2=" << AskPrice2 << ",";
	sbuf << "AskVolume2=" << AskVolume2 << ",";
	sbuf << "AskPrice3=" << AskPrice3 << ",";
	sbuf << "AskVolume3=" << AskVolume3 << ",";
	sbuf << "BidPrice4=" << BidPrice4 << ",";
	sbuf << "BidVolume4=" << BidVolume4 << ",";
	sbuf << "BidPrice5=" << BidPrice5 << ",";
	sbuf << "BidVolume5=" << BidVolume5 << ",";
	sbuf << "AskPrice4=" << AskPrice4 << ",";
	sbuf << "AskVolume4=" << AskVolume4 << ",";
	sbuf << "AskPrice5=" << AskPrice5 << ",";
	sbuf << "AskVolume5=" << AskVolume5 << ",";
	sbuf << "BidPrice6=" << BidPrice6 << ",";
	sbuf << "BidVolume6=" << BidVolume6 << ",";
	sbuf << "BidPrice7=" << BidPrice7 << ",";
	sbuf << "BidVolume7=" << BidVolume7 << ",";
	sbuf << "BidPrice8=" << BidPrice8 << ",";
	sbuf << "BidVolume8=" << BidVolume8 << ",";
	sbuf << "BidPrice9=" << BidPrice9 << ",";
	sbuf << "BidVolume9=" << BidVolume9 << ",";
	sbuf << "BidPrice10=" << BidPrice10 << ",";
	sbuf << "BidVolume10=" << BidVolume10 << ",";
	sbuf << "AskPrice6=" << AskPrice6 << ",";
	sbuf << "AskVolume6=" << AskVolume6 << ",";
	sbuf << "AskPrice7=" << AskPrice7 << ",";
	sbuf << "AskVolume7=" << AskVolume7 << ",";
	sbuf << "AskPrice8=" << AskPrice8 << ",";
	sbuf << "AskVolume8=" << AskVolume8 << ",";
	sbuf << "AskPrice9=" << AskPrice9 << ",";
	sbuf << "AskVolume9=" << AskVolume9 << ",";
	sbuf << "AskPrice10=" << AskPrice10 << ",";
	sbuf << "AskVolume10=" << AskVolume10 << ",";
	sbuf << "SequenceNo=" << SequenceNo << ",";
	sbuf << "MarketName=" << MarketName << ",";
	sbuf << "InstrumentID=" << InstrumentID << ",";
	sbuf << "InstrumentStatus=" << InstrumentStatus << ",";
	sbuf << "UpdateTime=" << UpdateTime << ",";
	sbuf << "UpdateMillisec=" << UpdateMillisec << ",";

	sprintf(p, "%s", sbuf.str().c_str());
}

void CExchInstrument::init(void)
{
	memset(this, 0, sizeof(CExchInstrument));
}

int CExchInstrument::read(FILE *input)
{
	if (fread(this, 1, sizeof(CExchInstrument), input) != sizeof(CExchInstrument))
		return 0;
	else
		return 1;
}

int CExchInstrument::write(FILE *output) const
{
	if (fwrite(this, 1, sizeof(CExchInstrument), output) != sizeof(CExchInstrument))
		return 0;
	else
		return 1;
}

void CExchInstrument::dump(FILE *fp, int index) const
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
	fprintf(fp, "\tCExchInstrument%s = {\n", index_buf);
	fprintf(fp, "\t\tAppType = %s    [���׽ӿ�����]\n", boost::lexical_cast<std::string>(AppType).c_str());
	fprintf(fp, "\t\tExchangeID = %s    [����������]\n", boost::lexical_cast<std::string>(ExchangeID).c_str());
	fprintf(fp, "\t\tCommodityID = %s    [��Ʒ]\n", boost::lexical_cast<std::string>(CommodityID).c_str());
	fprintf(fp, "\t\tCommodityType = %s    [��Ʒ����]\n", boost::lexical_cast<std::string>(CommodityType).c_str());
	fprintf(fp, "\t\tInstrumentID = %s    [��Լ]\n", boost::lexical_cast<std::string>(InstrumentID).c_str());
	fprintf(fp, "\t\tInstrumentName = %s    [��Լ����]\n", boost::lexical_cast<std::string>(InstrumentName).c_str());
	fprintf(fp, "\t\tInstrumentType = %s    [��Լ����]\n", boost::lexical_cast<std::string>(InstrumentType).c_str());
	fprintf(fp, "\t\tInstrumentState = %s    [��Լ״̬]\n", boost::lexical_cast<std::string>(InstrumentState).c_str());
	fprintf(fp, "\t\tExchangeInstID = %s    [��Լ�ڽ������Ĵ��루CTP��������ʢ�У�ָ��RelateCommodityNo��������Լ��]\n", boost::lexical_cast<std::string>(ExchangeInstID).c_str());
	fprintf(fp, "\t\tInstLifePhase = %s    [��Լ��������״̬]\n", boost::lexical_cast<std::string>(InstLifePhase).c_str());
	fprintf(fp, "\t\tCommodityName = %s    [��Ʒ����]\n", boost::lexical_cast<std::string>(CommodityName).c_str());
	fprintf(fp, "\t\tCommodityAttribute = %s    [��Ʒ����]\n", boost::lexical_cast<std::string>(CommodityAttribute).c_str());
	fprintf(fp, "\t\tTradeRight = %s    [��Ʒ����Ȩ��]\n", boost::lexical_cast<std::string>(TradeRight).c_str());
	fprintf(fp, "\t\tMultipleValue = %s    [ÿ�ֳ���]\n", boost::lexical_cast<std::string>(MultipleValue).c_str());
	fprintf(fp, "\t\tPriceTick = %s    [��С�䶯��λ]\n", boost::lexical_cast<std::string>(PriceTick).c_str());
	fprintf(fp, "\t\tUpperTick = %s    [��С�䶯�۷���]\n", boost::lexical_cast<std::string>(UpperTick).c_str());
	fprintf(fp, "\t\tLowerTick = %s    [��С�䶯�۷�ĸ]\n", boost::lexical_cast<std::string>(LowerTick).c_str());
	fprintf(fp, "\t\tCurrencyID = %s    [��Ʒʹ�ñ���]\n", boost::lexical_cast<std::string>(CurrencyID).c_str());
	fprintf(fp, "\t\tPrecision = %s    [���۾���]\n", boost::lexical_cast<std::string>(Precision).c_str());
	fprintf(fp, "\t\tDeliveryMode = %s    [���ʽ]\n", boost::lexical_cast<std::string>(DeliveryMode).c_str());
	fprintf(fp, "\t\tDeliveryDays = %s    [������ƫ��]\n", boost::lexical_cast<std::string>(DeliveryDays).c_str());
	fprintf(fp, "\t\tDeliveryYear = %s    [�������]\n", boost::lexical_cast<std::string>(DeliveryYear).c_str());
	fprintf(fp, "\t\tDeliveryMonth = %s    [������]\n", boost::lexical_cast<std::string>(DeliveryMonth).c_str());
	fprintf(fp, "\t\tMaxMarketOrderVolume = %s    [�м۵�����µ���]\n", boost::lexical_cast<std::string>(MaxMarketOrderVolume).c_str());
	fprintf(fp, "\t\tMinMarketOrderVolume = %s    [�м۵���С�µ���]\n", boost::lexical_cast<std::string>(MinMarketOrderVolume).c_str());
	fprintf(fp, "\t\tMaxLimitOrderVolume = %s    [�޼۵�����µ���]\n", boost::lexical_cast<std::string>(MaxLimitOrderVolume).c_str());
	fprintf(fp, "\t\tMinLimitOrderVolume = %s    [�޼۵���С�µ���]\n", boost::lexical_cast<std::string>(MinLimitOrderVolume).c_str());
	fprintf(fp, "\t\tDepositCalculateMode = %s    [��֤����㷽ʽ]\n", boost::lexical_cast<std::string>(DepositCalculateMode).c_str());
	fprintf(fp, "\t\tMaxHoldVol = %s    [���ֲ���]\n", boost::lexical_cast<std::string>(MaxHoldVol).c_str());
	fprintf(fp, "\t\tAddOneTime = %s    [T+1ʱ��,���ڴ�ʱ��ΪT+1����]\n", boost::lexical_cast<std::string>(AddOneTime).c_str());
	fprintf(fp, "\t\tCmbDirect = %s    [�����������(��һ��)]\n", boost::lexical_cast<std::string>(CmbDirect).c_str());
	fprintf(fp, "\t\tCoverMode = %s    [ƽ�ַ�ʽ]\n", boost::lexical_cast<std::string>(CoverMode).c_str());
	fprintf(fp, "\t\tCreateDate = %s    [������]\n", boost::lexical_cast<std::string>(CreateDate).c_str());
	fprintf(fp, "\t\tOpenDate = %s    [������]\n", boost::lexical_cast<std::string>(OpenDate).c_str());
	fprintf(fp, "\t\tExpiryDate = %s    [������]\n", boost::lexical_cast<std::string>(ExpiryDate).c_str());
	fprintf(fp, "\t\tStartDelivDate = %s    [��ʼ������]\n", boost::lexical_cast<std::string>(StartDelivDate).c_str());
	fprintf(fp, "\t\tEndDelivDate = %s    [����������]\n", boost::lexical_cast<std::string>(EndDelivDate).c_str());
	fprintf(fp, "\t\tPositionType = %s    [�ֲ�����]\n", boost::lexical_cast<std::string>(PositionType).c_str());
	fprintf(fp, "\t\tPositionDateType = %s    [�ֲ���������]\n", boost::lexical_cast<std::string>(PositionDateType).c_str());
	fprintf(fp, "\t\tLongMarginRatio = %s    [��ͷ��֤����]\n", boost::lexical_cast<std::string>(LongMarginRatio).c_str());
	fprintf(fp, "\t\tShortMarginRatio = %s    [��ͷ��֤����]\n", boost::lexical_cast<std::string>(ShortMarginRatio).c_str());
	fprintf(fp, "\t\tMaxMarginSideAlgorithm = %s    [�Ƿ�ʹ�ô��߱�֤���㷨]\n", boost::lexical_cast<std::string>(MaxMarginSideAlgorithm).c_str());
	fprintf(fp, "\t}\n");
}

void CExchInstrument::dumpDiff(FILE *fp, const CExchInstrument *pOriginal) const
{
	if (fp == nullptr)
	{
		fp = stdout;
	}
	fprintf(fp, "\tCExchInstrument = {\n");
	if (compare(AppType, pOriginal->AppType) != 0)
	{
		fprintf(fp, "\t\tAppType = %s -> %s    [���׽ӿ�����]\n", boost::lexical_cast<std::string>(pOriginal->AppType).c_str(), boost::lexical_cast<std::string>(AppType).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAppType = %s    [���׽ӿ�����]\n", boost::lexical_cast<std::string>(AppType).c_str());
	}
	if (compare(ExchangeID, pOriginal->ExchangeID) != 0)
	{
		fprintf(fp, "\t\tExchangeID = %s -> %s    [����������]\n", boost::lexical_cast<std::string>(pOriginal->ExchangeID).c_str(), boost::lexical_cast<std::string>(ExchangeID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tExchangeID = %s    [����������]\n", boost::lexical_cast<std::string>(ExchangeID).c_str());
	}
	if (compare(CommodityID, pOriginal->CommodityID) != 0)
	{
		fprintf(fp, "\t\tCommodityID = %s -> %s    [��Ʒ]\n", boost::lexical_cast<std::string>(pOriginal->CommodityID).c_str(), boost::lexical_cast<std::string>(CommodityID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tCommodityID = %s    [��Ʒ]\n", boost::lexical_cast<std::string>(CommodityID).c_str());
	}
	if (compare(CommodityType, pOriginal->CommodityType) != 0)
	{
		fprintf(fp, "\t\tCommodityType = %s -> %s    [��Ʒ����]\n", boost::lexical_cast<std::string>(pOriginal->CommodityType).c_str(), boost::lexical_cast<std::string>(CommodityType).c_str());
	}
	else
	{
		fprintf(fp, "\t\tCommodityType = %s    [��Ʒ����]\n", boost::lexical_cast<std::string>(CommodityType).c_str());
	}
	if (compare(InstrumentID, pOriginal->InstrumentID) != 0)
	{
		fprintf(fp, "\t\tInstrumentID = %s -> %s    [��Լ]\n", boost::lexical_cast<std::string>(pOriginal->InstrumentID).c_str(), boost::lexical_cast<std::string>(InstrumentID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tInstrumentID = %s    [��Լ]\n", boost::lexical_cast<std::string>(InstrumentID).c_str());
	}
	if (compare(InstrumentName, pOriginal->InstrumentName) != 0)
	{
		fprintf(fp, "\t\tInstrumentName = %s -> %s    [��Լ����]\n", boost::lexical_cast<std::string>(pOriginal->InstrumentName).c_str(), boost::lexical_cast<std::string>(InstrumentName).c_str());
	}
	else
	{
		fprintf(fp, "\t\tInstrumentName = %s    [��Լ����]\n", boost::lexical_cast<std::string>(InstrumentName).c_str());
	}
	if (compare(InstrumentType, pOriginal->InstrumentType) != 0)
	{
		fprintf(fp, "\t\tInstrumentType = %s -> %s    [��Լ����]\n", boost::lexical_cast<std::string>(pOriginal->InstrumentType).c_str(), boost::lexical_cast<std::string>(InstrumentType).c_str());
	}
	else
	{
		fprintf(fp, "\t\tInstrumentType = %s    [��Լ����]\n", boost::lexical_cast<std::string>(InstrumentType).c_str());
	}
	if (compare(InstrumentState, pOriginal->InstrumentState) != 0)
	{
		fprintf(fp, "\t\tInstrumentState = %s -> %s    [��Լ״̬]\n", boost::lexical_cast<std::string>(pOriginal->InstrumentState).c_str(), boost::lexical_cast<std::string>(InstrumentState).c_str());
	}
	else
	{
		fprintf(fp, "\t\tInstrumentState = %s    [��Լ״̬]\n", boost::lexical_cast<std::string>(InstrumentState).c_str());
	}
	if (compare(ExchangeInstID, pOriginal->ExchangeInstID) != 0)
	{
		fprintf(fp, "\t\tExchangeInstID = %s -> %s    [��Լ�ڽ������Ĵ��루CTP��������ʢ�У�ָ��RelateCommodityNo��������Լ��]\n", boost::lexical_cast<std::string>(pOriginal->ExchangeInstID).c_str(), boost::lexical_cast<std::string>(ExchangeInstID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tExchangeInstID = %s    [��Լ�ڽ������Ĵ��루CTP��������ʢ�У�ָ��RelateCommodityNo��������Լ��]\n", boost::lexical_cast<std::string>(ExchangeInstID).c_str());
	}
	if (compare(InstLifePhase, pOriginal->InstLifePhase) != 0)
	{
		fprintf(fp, "\t\tInstLifePhase = %s -> %s    [��Լ��������״̬]\n", boost::lexical_cast<std::string>(pOriginal->InstLifePhase).c_str(), boost::lexical_cast<std::string>(InstLifePhase).c_str());
	}
	else
	{
		fprintf(fp, "\t\tInstLifePhase = %s    [��Լ��������״̬]\n", boost::lexical_cast<std::string>(InstLifePhase).c_str());
	}
	if (compare(CommodityName, pOriginal->CommodityName) != 0)
	{
		fprintf(fp, "\t\tCommodityName = %s -> %s    [��Ʒ����]\n", boost::lexical_cast<std::string>(pOriginal->CommodityName).c_str(), boost::lexical_cast<std::string>(CommodityName).c_str());
	}
	else
	{
		fprintf(fp, "\t\tCommodityName = %s    [��Ʒ����]\n", boost::lexical_cast<std::string>(CommodityName).c_str());
	}
	if (compare(CommodityAttribute, pOriginal->CommodityAttribute) != 0)
	{
		fprintf(fp, "\t\tCommodityAttribute = %s -> %s    [��Ʒ����]\n", boost::lexical_cast<std::string>(pOriginal->CommodityAttribute).c_str(), boost::lexical_cast<std::string>(CommodityAttribute).c_str());
	}
	else
	{
		fprintf(fp, "\t\tCommodityAttribute = %s    [��Ʒ����]\n", boost::lexical_cast<std::string>(CommodityAttribute).c_str());
	}
	if (compare(TradeRight, pOriginal->TradeRight) != 0)
	{
		fprintf(fp, "\t\tTradeRight = %s -> %s    [��Ʒ����Ȩ��]\n", boost::lexical_cast<std::string>(pOriginal->TradeRight).c_str(), boost::lexical_cast<std::string>(TradeRight).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTradeRight = %s    [��Ʒ����Ȩ��]\n", boost::lexical_cast<std::string>(TradeRight).c_str());
	}
	if (compare(MultipleValue, pOriginal->MultipleValue) != 0)
	{
		fprintf(fp, "\t\tMultipleValue = %s -> %s    [ÿ�ֳ���]\n", boost::lexical_cast<std::string>(pOriginal->MultipleValue).c_str(), boost::lexical_cast<std::string>(MultipleValue).c_str());
	}
	else
	{
		fprintf(fp, "\t\tMultipleValue = %s    [ÿ�ֳ���]\n", boost::lexical_cast<std::string>(MultipleValue).c_str());
	}
	if (compare(PriceTick, pOriginal->PriceTick) != 0)
	{
		fprintf(fp, "\t\tPriceTick = %s -> %s    [��С�䶯��λ]\n", boost::lexical_cast<std::string>(pOriginal->PriceTick).c_str(), boost::lexical_cast<std::string>(PriceTick).c_str());
	}
	else
	{
		fprintf(fp, "\t\tPriceTick = %s    [��С�䶯��λ]\n", boost::lexical_cast<std::string>(PriceTick).c_str());
	}
	if (compare(UpperTick, pOriginal->UpperTick) != 0)
	{
		fprintf(fp, "\t\tUpperTick = %s -> %s    [��С�䶯�۷���]\n", boost::lexical_cast<std::string>(pOriginal->UpperTick).c_str(), boost::lexical_cast<std::string>(UpperTick).c_str());
	}
	else
	{
		fprintf(fp, "\t\tUpperTick = %s    [��С�䶯�۷���]\n", boost::lexical_cast<std::string>(UpperTick).c_str());
	}
	if (compare(LowerTick, pOriginal->LowerTick) != 0)
	{
		fprintf(fp, "\t\tLowerTick = %s -> %s    [��С�䶯�۷�ĸ]\n", boost::lexical_cast<std::string>(pOriginal->LowerTick).c_str(), boost::lexical_cast<std::string>(LowerTick).c_str());
	}
	else
	{
		fprintf(fp, "\t\tLowerTick = %s    [��С�䶯�۷�ĸ]\n", boost::lexical_cast<std::string>(LowerTick).c_str());
	}
	if (compare(CurrencyID, pOriginal->CurrencyID) != 0)
	{
		fprintf(fp, "\t\tCurrencyID = %s -> %s    [��Ʒʹ�ñ���]\n", boost::lexical_cast<std::string>(pOriginal->CurrencyID).c_str(), boost::lexical_cast<std::string>(CurrencyID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tCurrencyID = %s    [��Ʒʹ�ñ���]\n", boost::lexical_cast<std::string>(CurrencyID).c_str());
	}
	if (compare(Precision, pOriginal->Precision) != 0)
	{
		fprintf(fp, "\t\tPrecision = %s -> %s    [���۾���]\n", boost::lexical_cast<std::string>(pOriginal->Precision).c_str(), boost::lexical_cast<std::string>(Precision).c_str());
	}
	else
	{
		fprintf(fp, "\t\tPrecision = %s    [���۾���]\n", boost::lexical_cast<std::string>(Precision).c_str());
	}
	if (compare(DeliveryMode, pOriginal->DeliveryMode) != 0)
	{
		fprintf(fp, "\t\tDeliveryMode = %s -> %s    [���ʽ]\n", boost::lexical_cast<std::string>(pOriginal->DeliveryMode).c_str(), boost::lexical_cast<std::string>(DeliveryMode).c_str());
	}
	else
	{
		fprintf(fp, "\t\tDeliveryMode = %s    [���ʽ]\n", boost::lexical_cast<std::string>(DeliveryMode).c_str());
	}
	if (compare(DeliveryDays, pOriginal->DeliveryDays) != 0)
	{
		fprintf(fp, "\t\tDeliveryDays = %s -> %s    [������ƫ��]\n", boost::lexical_cast<std::string>(pOriginal->DeliveryDays).c_str(), boost::lexical_cast<std::string>(DeliveryDays).c_str());
	}
	else
	{
		fprintf(fp, "\t\tDeliveryDays = %s    [������ƫ��]\n", boost::lexical_cast<std::string>(DeliveryDays).c_str());
	}
	if (compare(DeliveryYear, pOriginal->DeliveryYear) != 0)
	{
		fprintf(fp, "\t\tDeliveryYear = %s -> %s    [�������]\n", boost::lexical_cast<std::string>(pOriginal->DeliveryYear).c_str(), boost::lexical_cast<std::string>(DeliveryYear).c_str());
	}
	else
	{
		fprintf(fp, "\t\tDeliveryYear = %s    [�������]\n", boost::lexical_cast<std::string>(DeliveryYear).c_str());
	}
	if (compare(DeliveryMonth, pOriginal->DeliveryMonth) != 0)
	{
		fprintf(fp, "\t\tDeliveryMonth = %s -> %s    [������]\n", boost::lexical_cast<std::string>(pOriginal->DeliveryMonth).c_str(), boost::lexical_cast<std::string>(DeliveryMonth).c_str());
	}
	else
	{
		fprintf(fp, "\t\tDeliveryMonth = %s    [������]\n", boost::lexical_cast<std::string>(DeliveryMonth).c_str());
	}
	if (compare(MaxMarketOrderVolume, pOriginal->MaxMarketOrderVolume) != 0)
	{
		fprintf(fp, "\t\tMaxMarketOrderVolume = %s -> %s    [�м۵�����µ���]\n", boost::lexical_cast<std::string>(pOriginal->MaxMarketOrderVolume).c_str(), boost::lexical_cast<std::string>(MaxMarketOrderVolume).c_str());
	}
	else
	{
		fprintf(fp, "\t\tMaxMarketOrderVolume = %s    [�м۵�����µ���]\n", boost::lexical_cast<std::string>(MaxMarketOrderVolume).c_str());
	}
	if (compare(MinMarketOrderVolume, pOriginal->MinMarketOrderVolume) != 0)
	{
		fprintf(fp, "\t\tMinMarketOrderVolume = %s -> %s    [�м۵���С�µ���]\n", boost::lexical_cast<std::string>(pOriginal->MinMarketOrderVolume).c_str(), boost::lexical_cast<std::string>(MinMarketOrderVolume).c_str());
	}
	else
	{
		fprintf(fp, "\t\tMinMarketOrderVolume = %s    [�м۵���С�µ���]\n", boost::lexical_cast<std::string>(MinMarketOrderVolume).c_str());
	}
	if (compare(MaxLimitOrderVolume, pOriginal->MaxLimitOrderVolume) != 0)
	{
		fprintf(fp, "\t\tMaxLimitOrderVolume = %s -> %s    [�޼۵�����µ���]\n", boost::lexical_cast<std::string>(pOriginal->MaxLimitOrderVolume).c_str(), boost::lexical_cast<std::string>(MaxLimitOrderVolume).c_str());
	}
	else
	{
		fprintf(fp, "\t\tMaxLimitOrderVolume = %s    [�޼۵�����µ���]\n", boost::lexical_cast<std::string>(MaxLimitOrderVolume).c_str());
	}
	if (compare(MinLimitOrderVolume, pOriginal->MinLimitOrderVolume) != 0)
	{
		fprintf(fp, "\t\tMinLimitOrderVolume = %s -> %s    [�޼۵���С�µ���]\n", boost::lexical_cast<std::string>(pOriginal->MinLimitOrderVolume).c_str(), boost::lexical_cast<std::string>(MinLimitOrderVolume).c_str());
	}
	else
	{
		fprintf(fp, "\t\tMinLimitOrderVolume = %s    [�޼۵���С�µ���]\n", boost::lexical_cast<std::string>(MinLimitOrderVolume).c_str());
	}
	if (compare(DepositCalculateMode, pOriginal->DepositCalculateMode) != 0)
	{
		fprintf(fp, "\t\tDepositCalculateMode = %s -> %s    [��֤����㷽ʽ]\n", boost::lexical_cast<std::string>(pOriginal->DepositCalculateMode).c_str(), boost::lexical_cast<std::string>(DepositCalculateMode).c_str());
	}
	else
	{
		fprintf(fp, "\t\tDepositCalculateMode = %s    [��֤����㷽ʽ]\n", boost::lexical_cast<std::string>(DepositCalculateMode).c_str());
	}
	if (compare(MaxHoldVol, pOriginal->MaxHoldVol) != 0)
	{
		fprintf(fp, "\t\tMaxHoldVol = %s -> %s    [���ֲ���]\n", boost::lexical_cast<std::string>(pOriginal->MaxHoldVol).c_str(), boost::lexical_cast<std::string>(MaxHoldVol).c_str());
	}
	else
	{
		fprintf(fp, "\t\tMaxHoldVol = %s    [���ֲ���]\n", boost::lexical_cast<std::string>(MaxHoldVol).c_str());
	}
	if (compare(AddOneTime, pOriginal->AddOneTime) != 0)
	{
		fprintf(fp, "\t\tAddOneTime = %s -> %s    [T+1ʱ��,���ڴ�ʱ��ΪT+1����]\n", boost::lexical_cast<std::string>(pOriginal->AddOneTime).c_str(), boost::lexical_cast<std::string>(AddOneTime).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAddOneTime = %s    [T+1ʱ��,���ڴ�ʱ��ΪT+1����]\n", boost::lexical_cast<std::string>(AddOneTime).c_str());
	}
	if (compare(CmbDirect, pOriginal->CmbDirect) != 0)
	{
		fprintf(fp, "\t\tCmbDirect = %s -> %s    [�����������(��һ��)]\n", boost::lexical_cast<std::string>(pOriginal->CmbDirect).c_str(), boost::lexical_cast<std::string>(CmbDirect).c_str());
	}
	else
	{
		fprintf(fp, "\t\tCmbDirect = %s    [�����������(��һ��)]\n", boost::lexical_cast<std::string>(CmbDirect).c_str());
	}
	if (compare(CoverMode, pOriginal->CoverMode) != 0)
	{
		fprintf(fp, "\t\tCoverMode = %s -> %s    [ƽ�ַ�ʽ]\n", boost::lexical_cast<std::string>(pOriginal->CoverMode).c_str(), boost::lexical_cast<std::string>(CoverMode).c_str());
	}
	else
	{
		fprintf(fp, "\t\tCoverMode = %s    [ƽ�ַ�ʽ]\n", boost::lexical_cast<std::string>(CoverMode).c_str());
	}
	if (compare(CreateDate, pOriginal->CreateDate) != 0)
	{
		fprintf(fp, "\t\tCreateDate = %s -> %s    [������]\n", boost::lexical_cast<std::string>(pOriginal->CreateDate).c_str(), boost::lexical_cast<std::string>(CreateDate).c_str());
	}
	else
	{
		fprintf(fp, "\t\tCreateDate = %s    [������]\n", boost::lexical_cast<std::string>(CreateDate).c_str());
	}
	if (compare(OpenDate, pOriginal->OpenDate) != 0)
	{
		fprintf(fp, "\t\tOpenDate = %s -> %s    [������]\n", boost::lexical_cast<std::string>(pOriginal->OpenDate).c_str(), boost::lexical_cast<std::string>(OpenDate).c_str());
	}
	else
	{
		fprintf(fp, "\t\tOpenDate = %s    [������]\n", boost::lexical_cast<std::string>(OpenDate).c_str());
	}
	if (compare(ExpiryDate, pOriginal->ExpiryDate) != 0)
	{
		fprintf(fp, "\t\tExpiryDate = %s -> %s    [������]\n", boost::lexical_cast<std::string>(pOriginal->ExpiryDate).c_str(), boost::lexical_cast<std::string>(ExpiryDate).c_str());
	}
	else
	{
		fprintf(fp, "\t\tExpiryDate = %s    [������]\n", boost::lexical_cast<std::string>(ExpiryDate).c_str());
	}
	if (compare(StartDelivDate, pOriginal->StartDelivDate) != 0)
	{
		fprintf(fp, "\t\tStartDelivDate = %s -> %s    [��ʼ������]\n", boost::lexical_cast<std::string>(pOriginal->StartDelivDate).c_str(), boost::lexical_cast<std::string>(StartDelivDate).c_str());
	}
	else
	{
		fprintf(fp, "\t\tStartDelivDate = %s    [��ʼ������]\n", boost::lexical_cast<std::string>(StartDelivDate).c_str());
	}
	if (compare(EndDelivDate, pOriginal->EndDelivDate) != 0)
	{
		fprintf(fp, "\t\tEndDelivDate = %s -> %s    [����������]\n", boost::lexical_cast<std::string>(pOriginal->EndDelivDate).c_str(), boost::lexical_cast<std::string>(EndDelivDate).c_str());
	}
	else
	{
		fprintf(fp, "\t\tEndDelivDate = %s    [����������]\n", boost::lexical_cast<std::string>(EndDelivDate).c_str());
	}
	if (compare(PositionType, pOriginal->PositionType) != 0)
	{
		fprintf(fp, "\t\tPositionType = %s -> %s    [�ֲ�����]\n", boost::lexical_cast<std::string>(pOriginal->PositionType).c_str(), boost::lexical_cast<std::string>(PositionType).c_str());
	}
	else
	{
		fprintf(fp, "\t\tPositionType = %s    [�ֲ�����]\n", boost::lexical_cast<std::string>(PositionType).c_str());
	}
	if (compare(PositionDateType, pOriginal->PositionDateType) != 0)
	{
		fprintf(fp, "\t\tPositionDateType = %s -> %s    [�ֲ���������]\n", boost::lexical_cast<std::string>(pOriginal->PositionDateType).c_str(), boost::lexical_cast<std::string>(PositionDateType).c_str());
	}
	else
	{
		fprintf(fp, "\t\tPositionDateType = %s    [�ֲ���������]\n", boost::lexical_cast<std::string>(PositionDateType).c_str());
	}
	if (compare(LongMarginRatio, pOriginal->LongMarginRatio) != 0)
	{
		fprintf(fp, "\t\tLongMarginRatio = %s -> %s    [��ͷ��֤����]\n", boost::lexical_cast<std::string>(pOriginal->LongMarginRatio).c_str(), boost::lexical_cast<std::string>(LongMarginRatio).c_str());
	}
	else
	{
		fprintf(fp, "\t\tLongMarginRatio = %s    [��ͷ��֤����]\n", boost::lexical_cast<std::string>(LongMarginRatio).c_str());
	}
	if (compare(ShortMarginRatio, pOriginal->ShortMarginRatio) != 0)
	{
		fprintf(fp, "\t\tShortMarginRatio = %s -> %s    [��ͷ��֤����]\n", boost::lexical_cast<std::string>(pOriginal->ShortMarginRatio).c_str(), boost::lexical_cast<std::string>(ShortMarginRatio).c_str());
	}
	else
	{
		fprintf(fp, "\t\tShortMarginRatio = %s    [��ͷ��֤����]\n", boost::lexical_cast<std::string>(ShortMarginRatio).c_str());
	}
	if (compare(MaxMarginSideAlgorithm, pOriginal->MaxMarginSideAlgorithm) != 0)
	{
		fprintf(fp, "\t\tMaxMarginSideAlgorithm = %s -> %s    [�Ƿ�ʹ�ô��߱�֤���㷨]\n", boost::lexical_cast<std::string>(pOriginal->MaxMarginSideAlgorithm).c_str(), boost::lexical_cast<std::string>(MaxMarginSideAlgorithm).c_str());
	}
	else
	{
		fprintf(fp, "\t\tMaxMarginSideAlgorithm = %s    [�Ƿ�ʹ�ô��߱�֤���㷨]\n", boost::lexical_cast<std::string>(MaxMarginSideAlgorithm).c_str());
	}
	fprintf(fp, "\t}\n");
}

void CExchInstrument::dumpInLine(FILE *fp) const
{
	if (fp == nullptr)
	{
		fp = stdout;
	}
	std::stringstream sbuf;

	sbuf << ",AppType," << AppType;
	sbuf << ",ExchangeID," << ExchangeID;
	sbuf << ",CommodityID," << CommodityID;
	sbuf << ",CommodityType," << CommodityType;
	sbuf << ",InstrumentID," << InstrumentID;
	sbuf << ",InstrumentName," << InstrumentName;
	sbuf << ",InstrumentType," << InstrumentType;
	sbuf << ",InstrumentState," << InstrumentState;
	sbuf << ",ExchangeInstID," << ExchangeInstID;
	sbuf << ",InstLifePhase," << InstLifePhase;
	sbuf << ",CommodityName," << CommodityName;
	sbuf << ",CommodityAttribute," << CommodityAttribute;
	sbuf << ",TradeRight," << TradeRight;
	sbuf << ",MultipleValue," << MultipleValue;
	sbuf << ",PriceTick," << PriceTick;
	sbuf << ",UpperTick," << UpperTick;
	sbuf << ",LowerTick," << LowerTick;
	sbuf << ",CurrencyID," << CurrencyID;
	sbuf << ",Precision," << Precision;
	sbuf << ",DeliveryMode," << DeliveryMode;
	sbuf << ",DeliveryDays," << DeliveryDays;
	sbuf << ",DeliveryYear," << DeliveryYear;
	sbuf << ",DeliveryMonth," << DeliveryMonth;
	sbuf << ",MaxMarketOrderVolume," << MaxMarketOrderVolume;
	sbuf << ",MinMarketOrderVolume," << MinMarketOrderVolume;
	sbuf << ",MaxLimitOrderVolume," << MaxLimitOrderVolume;
	sbuf << ",MinLimitOrderVolume," << MinLimitOrderVolume;
	sbuf << ",DepositCalculateMode," << DepositCalculateMode;
	sbuf << ",MaxHoldVol," << MaxHoldVol;
	sbuf << ",AddOneTime," << AddOneTime;
	sbuf << ",CmbDirect," << CmbDirect;
	sbuf << ",CoverMode," << CoverMode;
	sbuf << ",CreateDate," << CreateDate;
	sbuf << ",OpenDate," << OpenDate;
	sbuf << ",ExpiryDate," << ExpiryDate;
	sbuf << ",StartDelivDate," << StartDelivDate;
	sbuf << ",EndDelivDate," << EndDelivDate;
	sbuf << ",PositionType," << PositionType;
	sbuf << ",PositionDateType," << PositionDateType;
	sbuf << ",LongMarginRatio," << LongMarginRatio;
	sbuf << ",ShortMarginRatio," << ShortMarginRatio;
	sbuf << ",MaxMarginSideAlgorithm," << MaxMarginSideAlgorithm;
	fprintf(fp, "%s", sbuf.str().c_str());
}

void CExchInstrument::dumpString(char *target) const
{
	char *p = target;
	std::stringstream sbuf;

	sbuf << "AppType=" << AppType << ",";
	sbuf << "ExchangeID=" << ExchangeID << ",";
	sbuf << "CommodityID=" << CommodityID << ",";
	sbuf << "CommodityType=" << CommodityType << ",";
	sbuf << "InstrumentID=" << InstrumentID << ",";
	sbuf << "InstrumentName=" << InstrumentName << ",";
	sbuf << "InstrumentType=" << InstrumentType << ",";
	sbuf << "InstrumentState=" << InstrumentState << ",";
	sbuf << "ExchangeInstID=" << ExchangeInstID << ",";
	sbuf << "InstLifePhase=" << InstLifePhase << ",";
	sbuf << "CommodityName=" << CommodityName << ",";
	sbuf << "CommodityAttribute=" << CommodityAttribute << ",";
	sbuf << "TradeRight=" << TradeRight << ",";
	sbuf << "MultipleValue=" << MultipleValue << ",";
	sbuf << "PriceTick=" << PriceTick << ",";
	sbuf << "UpperTick=" << UpperTick << ",";
	sbuf << "LowerTick=" << LowerTick << ",";
	sbuf << "CurrencyID=" << CurrencyID << ",";
	sbuf << "Precision=" << Precision << ",";
	sbuf << "DeliveryMode=" << DeliveryMode << ",";
	sbuf << "DeliveryDays=" << DeliveryDays << ",";
	sbuf << "DeliveryYear=" << DeliveryYear << ",";
	sbuf << "DeliveryMonth=" << DeliveryMonth << ",";
	sbuf << "MaxMarketOrderVolume=" << MaxMarketOrderVolume << ",";
	sbuf << "MinMarketOrderVolume=" << MinMarketOrderVolume << ",";
	sbuf << "MaxLimitOrderVolume=" << MaxLimitOrderVolume << ",";
	sbuf << "MinLimitOrderVolume=" << MinLimitOrderVolume << ",";
	sbuf << "DepositCalculateMode=" << DepositCalculateMode << ",";
	sbuf << "MaxHoldVol=" << MaxHoldVol << ",";
	sbuf << "AddOneTime=" << AddOneTime << ",";
	sbuf << "CmbDirect=" << CmbDirect << ",";
	sbuf << "CoverMode=" << CoverMode << ",";
	sbuf << "CreateDate=" << CreateDate << ",";
	sbuf << "OpenDate=" << OpenDate << ",";
	sbuf << "ExpiryDate=" << ExpiryDate << ",";
	sbuf << "StartDelivDate=" << StartDelivDate << ",";
	sbuf << "EndDelivDate=" << EndDelivDate << ",";
	sbuf << "PositionType=" << PositionType << ",";
	sbuf << "PositionDateType=" << PositionDateType << ",";
	sbuf << "LongMarginRatio=" << LongMarginRatio << ",";
	sbuf << "ShortMarginRatio=" << ShortMarginRatio << ",";
	sbuf << "MaxMarginSideAlgorithm=" << MaxMarginSideAlgorithm << ",";

	sprintf(p, "%s", sbuf.str().c_str());
}

void CExchInstrumentStatus::init(void)
{
	memset(this, 0, sizeof(CExchInstrumentStatus));
}

int CExchInstrumentStatus::read(FILE *input)
{
	if (fread(this, 1, sizeof(CExchInstrumentStatus), input) != sizeof(CExchInstrumentStatus))
		return 0;
	else
		return 1;
}

int CExchInstrumentStatus::write(FILE *output) const
{
	if (fwrite(this, 1, sizeof(CExchInstrumentStatus), output) != sizeof(CExchInstrumentStatus))
		return 0;
	else
		return 1;
}

void CExchInstrumentStatus::dump(FILE *fp, int index) const
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
	fprintf(fp, "\tCExchInstrumentStatus%s = {\n", index_buf);
	fprintf(fp, "\t\tExchangeID = %s    [����������]\n", boost::lexical_cast<std::string>(ExchangeID).c_str());
	fprintf(fp, "\t\tExchangeInstID = %s    [��Լ�ڽ������Ĵ���]\n", boost::lexical_cast<std::string>(ExchangeInstID).c_str());
	fprintf(fp, "\t\tInstrumentID = %s    [��Լ����]\n", boost::lexical_cast<std::string>(InstrumentID).c_str());
	fprintf(fp, "\t\tInstrumentStatus = %s    [��Լ����״̬]\n", boost::lexical_cast<std::string>(InstrumentStatus).c_str());
	fprintf(fp, "\t\tTradingSegmentSN = %s    [���׽׶α��]\n", boost::lexical_cast<std::string>(TradingSegmentSN).c_str());
	fprintf(fp, "\t\tEnterTime = %s    [���뱾״̬ʱ��]\n", boost::lexical_cast<std::string>(EnterTime).c_str());
	fprintf(fp, "\t\tEnterReason = %s    [���뱾״̬ԭ��]\n", boost::lexical_cast<std::string>(EnterReason).c_str());
	fprintf(fp, "\t}\n");
}

void CExchInstrumentStatus::dumpDiff(FILE *fp, const CExchInstrumentStatus *pOriginal) const
{
	if (fp == nullptr)
	{
		fp = stdout;
	}
	fprintf(fp, "\tCExchInstrumentStatus = {\n");
	if (compare(ExchangeID, pOriginal->ExchangeID) != 0)
	{
		fprintf(fp, "\t\tExchangeID = %s -> %s    [����������]\n", boost::lexical_cast<std::string>(pOriginal->ExchangeID).c_str(), boost::lexical_cast<std::string>(ExchangeID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tExchangeID = %s    [����������]\n", boost::lexical_cast<std::string>(ExchangeID).c_str());
	}
	if (compare(ExchangeInstID, pOriginal->ExchangeInstID) != 0)
	{
		fprintf(fp, "\t\tExchangeInstID = %s -> %s    [��Լ�ڽ������Ĵ���]\n", boost::lexical_cast<std::string>(pOriginal->ExchangeInstID).c_str(), boost::lexical_cast<std::string>(ExchangeInstID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tExchangeInstID = %s    [��Լ�ڽ������Ĵ���]\n", boost::lexical_cast<std::string>(ExchangeInstID).c_str());
	}
	if (compare(InstrumentID, pOriginal->InstrumentID) != 0)
	{
		fprintf(fp, "\t\tInstrumentID = %s -> %s    [��Լ����]\n", boost::lexical_cast<std::string>(pOriginal->InstrumentID).c_str(), boost::lexical_cast<std::string>(InstrumentID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tInstrumentID = %s    [��Լ����]\n", boost::lexical_cast<std::string>(InstrumentID).c_str());
	}
	if (compare(InstrumentStatus, pOriginal->InstrumentStatus) != 0)
	{
		fprintf(fp, "\t\tInstrumentStatus = %s -> %s    [��Լ����״̬]\n", boost::lexical_cast<std::string>(pOriginal->InstrumentStatus).c_str(), boost::lexical_cast<std::string>(InstrumentStatus).c_str());
	}
	else
	{
		fprintf(fp, "\t\tInstrumentStatus = %s    [��Լ����״̬]\n", boost::lexical_cast<std::string>(InstrumentStatus).c_str());
	}
	if (compare(TradingSegmentSN, pOriginal->TradingSegmentSN) != 0)
	{
		fprintf(fp, "\t\tTradingSegmentSN = %s -> %s    [���׽׶α��]\n", boost::lexical_cast<std::string>(pOriginal->TradingSegmentSN).c_str(), boost::lexical_cast<std::string>(TradingSegmentSN).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTradingSegmentSN = %s    [���׽׶α��]\n", boost::lexical_cast<std::string>(TradingSegmentSN).c_str());
	}
	if (compare(EnterTime, pOriginal->EnterTime) != 0)
	{
		fprintf(fp, "\t\tEnterTime = %s -> %s    [���뱾״̬ʱ��]\n", boost::lexical_cast<std::string>(pOriginal->EnterTime).c_str(), boost::lexical_cast<std::string>(EnterTime).c_str());
	}
	else
	{
		fprintf(fp, "\t\tEnterTime = %s    [���뱾״̬ʱ��]\n", boost::lexical_cast<std::string>(EnterTime).c_str());
	}
	if (compare(EnterReason, pOriginal->EnterReason) != 0)
	{
		fprintf(fp, "\t\tEnterReason = %s -> %s    [���뱾״̬ԭ��]\n", boost::lexical_cast<std::string>(pOriginal->EnterReason).c_str(), boost::lexical_cast<std::string>(EnterReason).c_str());
	}
	else
	{
		fprintf(fp, "\t\tEnterReason = %s    [���뱾״̬ԭ��]\n", boost::lexical_cast<std::string>(EnterReason).c_str());
	}
	fprintf(fp, "\t}\n");
}

void CExchInstrumentStatus::dumpInLine(FILE *fp) const
{
	if (fp == nullptr)
	{
		fp = stdout;
	}
	std::stringstream sbuf;

	sbuf << ",ExchangeID," << ExchangeID;
	sbuf << ",ExchangeInstID," << ExchangeInstID;
	sbuf << ",InstrumentID," << InstrumentID;
	sbuf << ",InstrumentStatus," << InstrumentStatus;
	sbuf << ",TradingSegmentSN," << TradingSegmentSN;
	sbuf << ",EnterTime," << EnterTime;
	sbuf << ",EnterReason," << EnterReason;
	fprintf(fp, "%s", sbuf.str().c_str());
}

void CExchInstrumentStatus::dumpString(char *target) const
{
	char *p = target;

	std::stringstream sbuf;

	sbuf << "ExchangeID=" << ExchangeID << ",";
	sbuf << "ExchangeInstID=" << ExchangeInstID << ",";
	sbuf << "InstrumentID=" << InstrumentID << ",";
	sbuf << "InstrumentStatus=" << InstrumentStatus << ",";
	sbuf << "TradingSegmentSN=" << TradingSegmentSN << ",";
	sbuf << "EnterTime=" << EnterTime << ",";
	sbuf << "EnterReason=" << EnterReason << ",";

	sprintf(p, "%s", sbuf.str().c_str());
}

void CPhyAccount::init(void)
{
	memset(this, 0, sizeof(CPhyAccount));
}

int CPhyAccount::read(FILE *input)
{
	if (fread(this, 1, sizeof(CPhyAccount), input) != sizeof(CPhyAccount))
		return 0;
	else
		return 1;
}

int CPhyAccount::write(FILE *output) const
{
	if (fwrite(this, 1, sizeof(CPhyAccount), output) != sizeof(CPhyAccount))
		return 0;
	else
		return 1;
}

void CPhyAccount::dump(FILE *fp, int index) const
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
	fprintf(fp, "\tCPhyAccount%s = {\n", index_buf);
	fprintf(fp, "\t\tBrokerID = %s    [���͹�˾����]\n", boost::lexical_cast<std::string>(BrokerID).c_str());
	fprintf(fp, "\t\tUserID = %s    [�û�����]\n", boost::lexical_cast<std::string>(UserID).c_str());
	fprintf(fp, "\t\tPassword = %s    [����]\n", boost::lexical_cast<std::string>(Password).c_str());
	fprintf(fp, "\t\tTradeFrontAddr = %s    [����ǰ�õ�ַ��]\n", boost::lexical_cast<std::string>(TradeFrontAddr).c_str());
	fprintf(fp, "\t\tTradeFrontNmSrv = %s    [����Fens��ַ��]\n", boost::lexical_cast<std::string>(TradeFrontNmSrv).c_str());
	fprintf(fp, "\t\tMarketFrontAddr = %s    [����ǰ�õ�ַ��]\n", boost::lexical_cast<std::string>(MarketFrontAddr).c_str());
	fprintf(fp, "\t\tMarketFrontNmSrv = %s    [����Fens��ַ��]\n", boost::lexical_cast<std::string>(MarketFrontNmSrv).c_str());
	fprintf(fp, "\t\tPrivateResumeType = %s    [˽�����ش���ʽ]\n", boost::lexical_cast<std::string>(PrivateResumeType).c_str());
	fprintf(fp, "\t\tPublicResumeType = %s    [�������ش���ʽ]\n", boost::lexical_cast<std::string>(PublicResumeType).c_str());
	fprintf(fp, "\t\tMarketResumeType = %s    [������������]\n", boost::lexical_cast<std::string>(MarketResumeType).c_str());
	fprintf(fp, "\t\tMarketTopic = %s    [���������б�]\n", boost::lexical_cast<std::string>(MarketTopic).c_str());
	fprintf(fp, "\t}\n");
}

void CPhyAccount::dumpDiff(FILE *fp, const CPhyAccount *pOriginal) const
{
	if (fp == NULL)
	{
		fp = stdout;
	}
	fprintf(fp, "\tCPhyAccount = {\n");
	if (compare(BrokerID, pOriginal->BrokerID) != 0)
	{
		fprintf(fp, "\t\tBrokerID = %s -> %s    [���͹�˾����]\n", boost::lexical_cast<std::string>(pOriginal->BrokerID).c_str(), boost::lexical_cast<std::string>(BrokerID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBrokerID = %s    [���͹�˾����]\n", boost::lexical_cast<std::string>(BrokerID).c_str());
	}
	if (compare(UserID, pOriginal->UserID) != 0)
	{
		fprintf(fp, "\t\tUserID = %s -> %s    [�û�����]\n", boost::lexical_cast<std::string>(pOriginal->UserID).c_str(), boost::lexical_cast<std::string>(UserID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tUserID = %s    [�û�����]\n", boost::lexical_cast<std::string>(UserID).c_str());
	}
	if (compare(Password, pOriginal->Password) != 0)
	{
		fprintf(fp, "\t\tPassword = %s -> %s    [����]\n", boost::lexical_cast<std::string>(pOriginal->Password).c_str(), boost::lexical_cast<std::string>(Password).c_str());
	}
	else
	{
		fprintf(fp, "\t\tPassword = %s    [����]\n", boost::lexical_cast<std::string>(Password).c_str());
	}
	if (compare(TradeFrontAddr, pOriginal->TradeFrontAddr) != 0)
	{
		fprintf(fp, "\t\tTradeFrontAddr = %s -> %s    [����ǰ�õ�ַ��]\n", boost::lexical_cast<std::string>(pOriginal->TradeFrontAddr).c_str(), boost::lexical_cast<std::string>(TradeFrontAddr).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTradeFrontAddr = %s    [����ǰ�õ�ַ��]\n", boost::lexical_cast<std::string>(TradeFrontAddr).c_str());
	}
	if (compare(TradeFrontNmSrv, pOriginal->TradeFrontNmSrv) != 0)
	{
		fprintf(fp, "\t\tTradeFrontNmSrv = %s -> %s    [����Fens��ַ��]\n", boost::lexical_cast<std::string>(pOriginal->TradeFrontNmSrv).c_str(), boost::lexical_cast<std::string>(TradeFrontNmSrv).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTradeFrontNmSrv = %s    [����Fens��ַ��]\n", boost::lexical_cast<std::string>(TradeFrontNmSrv).c_str());
	}
	if (compare(MarketFrontAddr, pOriginal->MarketFrontAddr) != 0)
	{
		fprintf(fp, "\t\tMarketFrontAddr = %s -> %s    [����ǰ�õ�ַ��]\n", boost::lexical_cast<std::string>(pOriginal->MarketFrontAddr).c_str(), boost::lexical_cast<std::string>(MarketFrontAddr).c_str());
	}
	else
	{
		fprintf(fp, "\t\tMarketFrontAddr = %s    [����ǰ�õ�ַ��]\n", boost::lexical_cast<std::string>(MarketFrontAddr).c_str());
	}
	if (compare(MarketFrontNmSrv, pOriginal->MarketFrontNmSrv) != 0)
	{
		fprintf(fp, "\t\tMarketFrontNmSrv = %s -> %s    [����Fens��ַ��]\n", boost::lexical_cast<std::string>(pOriginal->MarketFrontNmSrv).c_str(), boost::lexical_cast<std::string>(MarketFrontNmSrv).c_str());
	}
	else
	{
		fprintf(fp, "\t\tMarketFrontNmSrv = %s    [����Fens��ַ��]\n", boost::lexical_cast<std::string>(MarketFrontNmSrv).c_str());
	}
	if (compare(PrivateResumeType, pOriginal->PrivateResumeType) != 0)
	{
		fprintf(fp, "\t\tPrivateResumeType = %s -> %s    [˽�����ش���ʽ]\n", boost::lexical_cast<std::string>(pOriginal->PrivateResumeType).c_str(), boost::lexical_cast<std::string>(PrivateResumeType).c_str());
	}
	else
	{
		fprintf(fp, "\t\tPrivateResumeType = %s    [˽�����ش���ʽ]\n", boost::lexical_cast<std::string>(PrivateResumeType).c_str());
	}
	if (compare(PublicResumeType, pOriginal->PublicResumeType) != 0)
	{
		fprintf(fp, "\t\tPublicResumeType = %s -> %s    [�������ش���ʽ]\n", boost::lexical_cast<std::string>(pOriginal->PublicResumeType).c_str(), boost::lexical_cast<std::string>(PublicResumeType).c_str());
	}
	else
	{
		fprintf(fp, "\t\tPublicResumeType = %s    [�������ش���ʽ]\n", boost::lexical_cast<std::string>(PublicResumeType).c_str());
	}
	if (compare(MarketResumeType, pOriginal->MarketResumeType) != 0)
	{
		fprintf(fp, "\t\tMarketResumeType = %s -> %s    [������������]\n", boost::lexical_cast<std::string>(pOriginal->MarketResumeType).c_str(), boost::lexical_cast<std::string>(MarketResumeType).c_str());
	}
	else
	{
		fprintf(fp, "\t\tMarketResumeType = %s    [������������]\n", boost::lexical_cast<std::string>(MarketResumeType).c_str());
	}
	if (compare(MarketTopic, pOriginal->MarketTopic) != 0)
	{
		fprintf(fp, "\t\tMarketTopic = %s -> %s    [���������б�]\n", boost::lexical_cast<std::string>(pOriginal->MarketTopic).c_str(), boost::lexical_cast<std::string>(MarketTopic).c_str());
	}
	else
	{
		fprintf(fp, "\t\tMarketTopic = %s    [���������б�]\n", boost::lexical_cast<std::string>(MarketTopic).c_str());
	}
	fprintf(fp, "\t}\n");
}

void CPhyAccount::dumpInLine(FILE *fp) const
{
	if (fp == nullptr)
	{
		fp = stdout;
	}
	std::stringstream sbuf;

	sbuf << ",BrokerID," << BrokerID;
	sbuf << ",UserID," << UserID;
	sbuf << ",Password," << Password;
	sbuf << ",TradeFrontAddr," << TradeFrontAddr;
	sbuf << ",TradeFrontNmSrv," << TradeFrontNmSrv;
	sbuf << ",MarketFrontAddr," << MarketFrontAddr;
	sbuf << ",MarketFrontNmSrv," << MarketFrontNmSrv;
	sbuf << ",PrivateResumeType," << PrivateResumeType;
	sbuf << ",PublicResumeType," << PublicResumeType;
	sbuf << ",MarketResumeType," << MarketResumeType;
	sbuf << ",MarketTopic," << MarketTopic;
	fprintf(fp, "%s", sbuf.str().c_str());
}

void CPhyAccount::dumpString(char *target) const
{
	char *p = target;
	std::stringstream sbuf;

	sbuf << "BrokerID=" << BrokerID << ",";
	sbuf << "UserID=" << UserID << ",";
	sbuf << "Password=" << Password << ",";
	sbuf << "TradeFrontAddr=" << TradeFrontAddr << ",";
	sbuf << "TradeFrontNmSrv=" << TradeFrontNmSrv << ",";
	sbuf << "MarketFrontAddr=" << MarketFrontAddr << ",";
	sbuf << "MarketFrontNmSrv=" << MarketFrontNmSrv << ",";
	sbuf << "PrivateResumeType=" << PrivateResumeType << ",";
	sbuf << "PublicResumeType=" << PublicResumeType << ",";
	sbuf << "MarketResumeType=" << MarketResumeType << ",";
	sbuf << "MarketTopic=" << MarketTopic << ",";

	sprintf(p, "%s", sbuf.str().c_str());
}

void CInvestorPosition::init(void)
{
	memset(this, 0, sizeof(CInvestorPosition));
}

int CInvestorPosition::read(FILE *input)
{
	if (fread(this, 1, sizeof(CInvestorPosition), input) != sizeof(CInvestorPosition))
		return 0;
	else
		return 1;
}

int CInvestorPosition::write(FILE *output) const
{
	if (fwrite(this, 1, sizeof(CInvestorPosition), output) != sizeof(CInvestorPosition))
		return 0;
	else
		return 1;
}

void CInvestorPosition::dump(FILE *fp, int index) const
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
	fprintf(fp, "\tCInvestorPosition%s = {\n", index_buf);
	fprintf(fp, "\t\tInvestorID = %s    [Ͷ���߱��]\n", boost::lexical_cast<std::string>(InvestorID).c_str());
	fprintf(fp, "\t\tBrokerID = %s    [���͹�˾����]\n", boost::lexical_cast<std::string>(BrokerID).c_str());
	fprintf(fp, "\t\tExchangeID = %s    [����������]\n", boost::lexical_cast<std::string>(ExchangeID).c_str());
	fprintf(fp, "\t\tClientID = %s    [�ͻ�����]\n", boost::lexical_cast<std::string>(ClientID).c_str());
	fprintf(fp, "\t\tInstrumentID = %s    [��Լ����]\n", boost::lexical_cast<std::string>(InstrumentID).c_str());
	fprintf(fp, "\t\tDirection = %s    [��������]\n", boost::lexical_cast<std::string>(Direction).c_str());
	fprintf(fp, "\t\tHedgeFlag = %s    [Ͷ���ױ���־]\n", boost::lexical_cast<std::string>(HedgeFlag).c_str());
	fprintf(fp, "\t\tUsedMargin = %s    [ռ�ñ�֤��]\n", boost::lexical_cast<std::string>(UsedMargin).c_str());
	fprintf(fp, "\t\tPosition = %s    [��ֲ���]\n", boost::lexical_cast<std::string>(Position).c_str());
	fprintf(fp, "\t\tPositionCost = %s    [���ճֲֳɱ�]\n", boost::lexical_cast<std::string>(PositionCost).c_str());
	fprintf(fp, "\t\tYdPosition = %s    [��ֲ���]\n", boost::lexical_cast<std::string>(YdPosition).c_str());
	fprintf(fp, "\t\tYdPositionCost = %s    [���ճֲֳɱ�]\n", boost::lexical_cast<std::string>(YdPositionCost).c_str());
	fprintf(fp, "\t\tFrozenMargin = %s    [����ı�֤��]\n", boost::lexical_cast<std::string>(FrozenMargin).c_str());
	fprintf(fp, "\t\tFrozenPosition = %s    [���ֶ���ֲ�]\n", boost::lexical_cast<std::string>(FrozenPosition).c_str());
	fprintf(fp, "\t\tFrozenClosing = %s    [ƽ�ֶ���ֲ�]\n", boost::lexical_cast<std::string>(FrozenClosing).c_str());
	fprintf(fp, "\t\tFrozenPremium = %s    [�����Ȩ����]\n", boost::lexical_cast<std::string>(FrozenPremium).c_str());
	fprintf(fp, "\t\tLastTradeID = %s    [���һ�ʳɽ����]\n", boost::lexical_cast<std::string>(LastTradeID).c_str());
	fprintf(fp, "\t\tLastOrderLocalID = %s    [���һ�ʱ��ر������]\n", boost::lexical_cast<std::string>(LastOrderLocalID).c_str());
	fprintf(fp, "\t\tCurrency = %s    [����]\n", boost::lexical_cast<std::string>(Currency).c_str());
	fprintf(fp, "\t\tFrozenCommission = %s    [����������]\n", boost::lexical_cast<std::string>(FrozenCommission).c_str());
	fprintf(fp, "\t\tCommission = %s    [������]\n", boost::lexical_cast<std::string>(Commission).c_str());
	fprintf(fp, "\t\tFloatProfit = %s    [����ӯ��]\n", boost::lexical_cast<std::string>(FloatProfit).c_str());
	fprintf(fp, "\t\tCloseProfit = %s    [ƽ��ӯ��]\n", boost::lexical_cast<std::string>(CloseProfit).c_str());
	fprintf(fp, "\t\tCloseVolume = %s    [ƽ������]\n", boost::lexical_cast<std::string>(CloseVolume).c_str());
	fprintf(fp, "\t\tCloseAmount = %s    [ƽ�ֽ��]\n", boost::lexical_cast<std::string>(CloseAmount).c_str());
	fprintf(fp, "\t\tLongFrozenMargin = %s    [��ͷ����ı�֤��]\n", boost::lexical_cast<std::string>(LongFrozenMargin).c_str());
	fprintf(fp, "\t\tShortFrozenMargin = %s    [��ͷ����ı�֤��]\n", boost::lexical_cast<std::string>(ShortFrozenMargin).c_str());
	fprintf(fp, "\t\tLongMargin = %s    [��ͷռ�ñ�֤��]\n", boost::lexical_cast<std::string>(LongMargin).c_str());
	fprintf(fp, "\t\tShortMargin = %s    [��ͷռ�ñ�֤��]\n", boost::lexical_cast<std::string>(ShortMargin).c_str());
	fprintf(fp, "\t\tReleaseMargin = %s    [�����ͷű�֤��]\n", boost::lexical_cast<std::string>(ReleaseMargin).c_str());
	fprintf(fp, "\t\tAvailable = %s    [�����ʽ�]\n", boost::lexical_cast<std::string>(Available).c_str());
	fprintf(fp, "\t\tDeposit = %s    [�����]\n", boost::lexical_cast<std::string>(Deposit).c_str());
	fprintf(fp, "\t\tWithdraw = %s    [������]\n", boost::lexical_cast<std::string>(Withdraw).c_str());
	fprintf(fp, "\t\tPreBalance = %s    [�ϴν���׼����]\n", boost::lexical_cast<std::string>(PreBalance).c_str());
	fprintf(fp, "\t\tDynamicRights = %s    [��̬Ȩ��]\n", boost::lexical_cast<std::string>(DynamicRights).c_str());
	fprintf(fp, "\t\tTodayInOut = %s    [���ճ����]\n", boost::lexical_cast<std::string>(TodayInOut).c_str());
	fprintf(fp, "\t\tPremium = %s    [��ȨȨ������֧]\n", boost::lexical_cast<std::string>(Premium).c_str());
	fprintf(fp, "\t\tRisk = %s    [���ն�]\n", boost::lexical_cast<std::string>(Risk).c_str());
	fprintf(fp, "\t}\n");
}

void CInvestorPosition::dumpDiff(FILE *fp, const CInvestorPosition *pOriginal) const
{
	if (fp == NULL)
	{
		fp = stdout;
	}
	fprintf(fp, "\tCInvestorPosition = {\n");
	if (compare(InvestorID, pOriginal->InvestorID) != 0)
	{
		fprintf(fp, "\t\tInvestorID = %s -> %s    [Ͷ���߱��]\n", boost::lexical_cast<std::string>(pOriginal->InvestorID).c_str(), boost::lexical_cast<std::string>(InvestorID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tInvestorID = %s    [Ͷ���߱��]\n", boost::lexical_cast<std::string>(InvestorID).c_str());
	}
	if (compare(BrokerID, pOriginal->BrokerID) != 0)
	{
		fprintf(fp, "\t\tBrokerID = %s -> %s    [���͹�˾����]\n", boost::lexical_cast<std::string>(pOriginal->BrokerID).c_str(), boost::lexical_cast<std::string>(BrokerID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBrokerID = %s    [���͹�˾����]\n", boost::lexical_cast<std::string>(BrokerID).c_str());
	}
	if (compare(ExchangeID, pOriginal->ExchangeID) != 0)
	{
		fprintf(fp, "\t\tExchangeID = %s -> %s    [����������]\n", boost::lexical_cast<std::string>(pOriginal->ExchangeID).c_str(), boost::lexical_cast<std::string>(ExchangeID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tExchangeID = %s    [����������]\n", boost::lexical_cast<std::string>(ExchangeID).c_str());
	}
	if (compare(ClientID, pOriginal->ClientID) != 0)
	{
		fprintf(fp, "\t\tClientID = %s -> %s    [�ͻ�����]\n", boost::lexical_cast<std::string>(pOriginal->ClientID).c_str(), boost::lexical_cast<std::string>(ClientID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tClientID = %s    [�ͻ�����]\n", boost::lexical_cast<std::string>(ClientID).c_str());
	}
	if (compare(InstrumentID, pOriginal->InstrumentID) != 0)
	{
		fprintf(fp, "\t\tInstrumentID = %s -> %s    [��Լ����]\n", boost::lexical_cast<std::string>(pOriginal->InstrumentID).c_str(), boost::lexical_cast<std::string>(InstrumentID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tInstrumentID = %s    [��Լ����]\n", boost::lexical_cast<std::string>(InstrumentID).c_str());
	}
	if (compare(Direction, pOriginal->Direction) != 0)
	{
		fprintf(fp, "\t\tDirection = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->Direction).c_str(), boost::lexical_cast<std::string>(Direction).c_str());
	}
	else
	{
		fprintf(fp, "\t\tDirection = %s    [��������]\n", boost::lexical_cast<std::string>(Direction).c_str());
	}
	if (compare(HedgeFlag, pOriginal->HedgeFlag) != 0)
	{
		fprintf(fp, "\t\tHedgeFlag = %s -> %s    [Ͷ���ױ���־]\n", boost::lexical_cast<std::string>(pOriginal->HedgeFlag).c_str(), boost::lexical_cast<std::string>(HedgeFlag).c_str());
	}
	else
	{
		fprintf(fp, "\t\tHedgeFlag = %s    [Ͷ���ױ���־]\n", boost::lexical_cast<std::string>(HedgeFlag).c_str());
	}
	if (compare(UsedMargin, pOriginal->UsedMargin) != 0)
	{
		fprintf(fp, "\t\tUsedMargin = %s -> %s    [ռ�ñ�֤��]\n", boost::lexical_cast<std::string>(pOriginal->UsedMargin).c_str(), boost::lexical_cast<std::string>(UsedMargin).c_str());
	}
	else
	{
		fprintf(fp, "\t\tUsedMargin = %s    [ռ�ñ�֤��]\n", boost::lexical_cast<std::string>(UsedMargin).c_str());
	}
	if (compare(Position, pOriginal->Position) != 0)
	{
		fprintf(fp, "\t\tPosition = %s -> %s    [��ֲ���]\n", boost::lexical_cast<std::string>(pOriginal->Position).c_str(), boost::lexical_cast<std::string>(Position).c_str());
	}
	else
	{
		fprintf(fp, "\t\tPosition = %s    [��ֲ���]\n", boost::lexical_cast<std::string>(Position).c_str());
	}
	if (compare(PositionCost, pOriginal->PositionCost) != 0)
	{
		fprintf(fp, "\t\tPositionCost = %s -> %s    [���ճֲֳɱ�]\n", boost::lexical_cast<std::string>(pOriginal->PositionCost).c_str(), boost::lexical_cast<std::string>(PositionCost).c_str());
	}
	else
	{
		fprintf(fp, "\t\tPositionCost = %s    [���ճֲֳɱ�]\n", boost::lexical_cast<std::string>(PositionCost).c_str());
	}
	if (compare(YdPosition, pOriginal->YdPosition) != 0)
	{
		fprintf(fp, "\t\tYdPosition = %s -> %s    [��ֲ���]\n", boost::lexical_cast<std::string>(pOriginal->YdPosition).c_str(), boost::lexical_cast<std::string>(YdPosition).c_str());
	}
	else
	{
		fprintf(fp, "\t\tYdPosition = %s    [��ֲ���]\n", boost::lexical_cast<std::string>(YdPosition).c_str());
	}
	if (compare(YdPositionCost, pOriginal->YdPositionCost) != 0)
	{
		fprintf(fp, "\t\tYdPositionCost = %s -> %s    [���ճֲֳɱ�]\n", boost::lexical_cast<std::string>(pOriginal->YdPositionCost).c_str(), boost::lexical_cast<std::string>(YdPositionCost).c_str());
	}
	else
	{
		fprintf(fp, "\t\tYdPositionCost = %s    [���ճֲֳɱ�]\n", boost::lexical_cast<std::string>(YdPositionCost).c_str());
	}
	if (compare(FrozenMargin, pOriginal->FrozenMargin) != 0)
	{
		fprintf(fp, "\t\tFrozenMargin = %s -> %s    [����ı�֤��]\n", boost::lexical_cast<std::string>(pOriginal->FrozenMargin).c_str(), boost::lexical_cast<std::string>(FrozenMargin).c_str());
	}
	else
	{
		fprintf(fp, "\t\tFrozenMargin = %s    [����ı�֤��]\n", boost::lexical_cast<std::string>(FrozenMargin).c_str());
	}
	if (compare(FrozenPosition, pOriginal->FrozenPosition) != 0)
	{
		fprintf(fp, "\t\tFrozenPosition = %s -> %s    [���ֶ���ֲ�]\n", boost::lexical_cast<std::string>(pOriginal->FrozenPosition).c_str(), boost::lexical_cast<std::string>(FrozenPosition).c_str());
	}
	else
	{
		fprintf(fp, "\t\tFrozenPosition = %s    [���ֶ���ֲ�]\n", boost::lexical_cast<std::string>(FrozenPosition).c_str());
	}
	if (compare(FrozenClosing, pOriginal->FrozenClosing) != 0)
	{
		fprintf(fp, "\t\tFrozenClosing = %s -> %s    [ƽ�ֶ���ֲ�]\n", boost::lexical_cast<std::string>(pOriginal->FrozenClosing).c_str(), boost::lexical_cast<std::string>(FrozenClosing).c_str());
	}
	else
	{
		fprintf(fp, "\t\tFrozenClosing = %s    [ƽ�ֶ���ֲ�]\n", boost::lexical_cast<std::string>(FrozenClosing).c_str());
	}
	if (compare(FrozenPremium, pOriginal->FrozenPremium) != 0)
	{
		fprintf(fp, "\t\tFrozenPremium = %s -> %s    [�����Ȩ����]\n", boost::lexical_cast<std::string>(pOriginal->FrozenPremium).c_str(), boost::lexical_cast<std::string>(FrozenPremium).c_str());
	}
	else
	{
		fprintf(fp, "\t\tFrozenPremium = %s    [�����Ȩ����]\n", boost::lexical_cast<std::string>(FrozenPremium).c_str());
	}
	if (compare(LastTradeID, pOriginal->LastTradeID) != 0)
	{
		fprintf(fp, "\t\tLastTradeID = %s -> %s    [���һ�ʳɽ����]\n", boost::lexical_cast<std::string>(pOriginal->LastTradeID).c_str(), boost::lexical_cast<std::string>(LastTradeID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tLastTradeID = %s    [���һ�ʳɽ����]\n", boost::lexical_cast<std::string>(LastTradeID).c_str());
	}
	if (compare(LastOrderLocalID, pOriginal->LastOrderLocalID) != 0)
	{
		fprintf(fp, "\t\tLastOrderLocalID = %s -> %s    [���һ�ʱ��ر������]\n", boost::lexical_cast<std::string>(pOriginal->LastOrderLocalID).c_str(), boost::lexical_cast<std::string>(LastOrderLocalID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tLastOrderLocalID = %s    [���һ�ʱ��ر������]\n", boost::lexical_cast<std::string>(LastOrderLocalID).c_str());
	}
	if (compare(Currency, pOriginal->Currency) != 0)
	{
		fprintf(fp, "\t\tCurrency = %s -> %s    [����]\n", boost::lexical_cast<std::string>(pOriginal->Currency).c_str(), boost::lexical_cast<std::string>(Currency).c_str());
	}
	else
	{
		fprintf(fp, "\t\tCurrency = %s    [����]\n", boost::lexical_cast<std::string>(Currency).c_str());
	}
	if (compare(FrozenCommission, pOriginal->FrozenCommission) != 0)
	{
		fprintf(fp, "\t\tFrozenCommission = %s -> %s    [����������]\n", boost::lexical_cast<std::string>(pOriginal->FrozenCommission).c_str(), boost::lexical_cast<std::string>(FrozenCommission).c_str());
	}
	else
	{
		fprintf(fp, "\t\tFrozenCommission = %s    [����������]\n", boost::lexical_cast<std::string>(FrozenCommission).c_str());
	}
	if (compare(Commission, pOriginal->Commission) != 0)
	{
		fprintf(fp, "\t\tCommission = %s -> %s    [������]\n", boost::lexical_cast<std::string>(pOriginal->Commission).c_str(), boost::lexical_cast<std::string>(Commission).c_str());
	}
	else
	{
		fprintf(fp, "\t\tCommission = %s    [������]\n", boost::lexical_cast<std::string>(Commission).c_str());
	}
	if (compare(FloatProfit, pOriginal->FloatProfit) != 0)
	{
		fprintf(fp, "\t\tFloatProfit = %s -> %s    [����ӯ��]\n", boost::lexical_cast<std::string>(pOriginal->FloatProfit).c_str(), boost::lexical_cast<std::string>(FloatProfit).c_str());
	}
	else
	{
		fprintf(fp, "\t\tFloatProfit = %s    [����ӯ��]\n", boost::lexical_cast<std::string>(FloatProfit).c_str());
	}
	if (compare(CloseProfit, pOriginal->CloseProfit) != 0)
	{
		fprintf(fp, "\t\tCloseProfit = %s -> %s    [ƽ��ӯ��]\n", boost::lexical_cast<std::string>(pOriginal->CloseProfit).c_str(), boost::lexical_cast<std::string>(CloseProfit).c_str());
	}
	else
	{
		fprintf(fp, "\t\tCloseProfit = %s    [ƽ��ӯ��]\n", boost::lexical_cast<std::string>(CloseProfit).c_str());
	}
	if (compare(CloseVolume, pOriginal->CloseVolume) != 0)
	{
		fprintf(fp, "\t\tCloseVolume = %s -> %s    [ƽ������]\n", boost::lexical_cast<std::string>(pOriginal->CloseVolume).c_str(), boost::lexical_cast<std::string>(CloseVolume).c_str());
	}
	else
	{
		fprintf(fp, "\t\tCloseVolume = %s    [ƽ������]\n", boost::lexical_cast<std::string>(CloseVolume).c_str());
	}
	if (compare(CloseAmount, pOriginal->CloseAmount) != 0)
	{
		fprintf(fp, "\t\tCloseAmount = %s -> %s    [ƽ�ֽ��]\n", boost::lexical_cast<std::string>(pOriginal->CloseAmount).c_str(), boost::lexical_cast<std::string>(CloseAmount).c_str());
	}
	else
	{
		fprintf(fp, "\t\tCloseAmount = %s    [ƽ�ֽ��]\n", boost::lexical_cast<std::string>(CloseAmount).c_str());
	}
	if (compare(LongFrozenMargin, pOriginal->LongFrozenMargin) != 0)
	{
		fprintf(fp, "\t\tLongFrozenMargin = %s -> %s    [��ͷ����ı�֤��]\n", boost::lexical_cast<std::string>(pOriginal->LongFrozenMargin).c_str(), boost::lexical_cast<std::string>(LongFrozenMargin).c_str());
	}
	else
	{
		fprintf(fp, "\t\tLongFrozenMargin = %s    [��ͷ����ı�֤��]\n", boost::lexical_cast<std::string>(LongFrozenMargin).c_str());
	}
	if (compare(ShortFrozenMargin, pOriginal->ShortFrozenMargin) != 0)
	{
		fprintf(fp, "\t\tShortFrozenMargin = %s -> %s    [��ͷ����ı�֤��]\n", boost::lexical_cast<std::string>(pOriginal->ShortFrozenMargin).c_str(), boost::lexical_cast<std::string>(ShortFrozenMargin).c_str());
	}
	else
	{
		fprintf(fp, "\t\tShortFrozenMargin = %s    [��ͷ����ı�֤��]\n", boost::lexical_cast<std::string>(ShortFrozenMargin).c_str());
	}
	if (compare(LongMargin, pOriginal->LongMargin) != 0)
	{
		fprintf(fp, "\t\tLongMargin = %s -> %s    [��ͷռ�ñ�֤��]\n", boost::lexical_cast<std::string>(pOriginal->LongMargin).c_str(), boost::lexical_cast<std::string>(LongMargin).c_str());
	}
	else
	{
		fprintf(fp, "\t\tLongMargin = %s    [��ͷռ�ñ�֤��]\n", boost::lexical_cast<std::string>(LongMargin).c_str());
	}
	if (compare(ShortMargin, pOriginal->ShortMargin) != 0)
	{
		fprintf(fp, "\t\tShortMargin = %s -> %s    [��ͷռ�ñ�֤��]\n", boost::lexical_cast<std::string>(pOriginal->ShortMargin).c_str(), boost::lexical_cast<std::string>(ShortMargin).c_str());
	}
	else
	{
		fprintf(fp, "\t\tShortMargin = %s    [��ͷռ�ñ�֤��]\n", boost::lexical_cast<std::string>(ShortMargin).c_str());
	}
	if (compare(ReleaseMargin, pOriginal->ReleaseMargin) != 0)
	{
		fprintf(fp, "\t\tReleaseMargin = %s -> %s    [�����ͷű�֤��]\n", boost::lexical_cast<std::string>(pOriginal->ReleaseMargin).c_str(), boost::lexical_cast<std::string>(ReleaseMargin).c_str());
	}
	else
	{
		fprintf(fp, "\t\tReleaseMargin = %s    [�����ͷű�֤��]\n", boost::lexical_cast<std::string>(ReleaseMargin).c_str());
	}
	if (compare(Available, pOriginal->Available) != 0)
	{
		fprintf(fp, "\t\tAvailable = %s -> %s    [�����ʽ�]\n", boost::lexical_cast<std::string>(pOriginal->Available).c_str(), boost::lexical_cast<std::string>(Available).c_str());
	}
	else
	{
		fprintf(fp, "\t\tAvailable = %s    [�����ʽ�]\n", boost::lexical_cast<std::string>(Available).c_str());
	}
	if (compare(Deposit, pOriginal->Deposit) != 0)
	{
		fprintf(fp, "\t\tDeposit = %s -> %s    [�����]\n", boost::lexical_cast<std::string>(pOriginal->Deposit).c_str(), boost::lexical_cast<std::string>(Deposit).c_str());
	}
	else
	{
		fprintf(fp, "\t\tDeposit = %s    [�����]\n", boost::lexical_cast<std::string>(Deposit).c_str());
	}
	if (compare(Withdraw, pOriginal->Withdraw) != 0)
	{
		fprintf(fp, "\t\tWithdraw = %s -> %s    [������]\n", boost::lexical_cast<std::string>(pOriginal->Withdraw).c_str(), boost::lexical_cast<std::string>(Withdraw).c_str());
	}
	else
	{
		fprintf(fp, "\t\tWithdraw = %s    [������]\n", boost::lexical_cast<std::string>(Withdraw).c_str());
	}
	if (compare(PreBalance, pOriginal->PreBalance) != 0)
	{
		fprintf(fp, "\t\tPreBalance = %s -> %s    [�ϴν���׼����]\n", boost::lexical_cast<std::string>(pOriginal->PreBalance).c_str(), boost::lexical_cast<std::string>(PreBalance).c_str());
	}
	else
	{
		fprintf(fp, "\t\tPreBalance = %s    [�ϴν���׼����]\n", boost::lexical_cast<std::string>(PreBalance).c_str());
	}
	if (compare(DynamicRights, pOriginal->DynamicRights) != 0)
	{
		fprintf(fp, "\t\tDynamicRights = %s -> %s    [��̬Ȩ��]\n", boost::lexical_cast<std::string>(pOriginal->DynamicRights).c_str(), boost::lexical_cast<std::string>(DynamicRights).c_str());
	}
	else
	{
		fprintf(fp, "\t\tDynamicRights = %s    [��̬Ȩ��]\n", boost::lexical_cast<std::string>(DynamicRights).c_str());
	}
	if (compare(TodayInOut, pOriginal->TodayInOut) != 0)
	{
		fprintf(fp, "\t\tTodayInOut = %s -> %s    [���ճ����]\n", boost::lexical_cast<std::string>(pOriginal->TodayInOut).c_str(), boost::lexical_cast<std::string>(TodayInOut).c_str());
	}
	else
	{
		fprintf(fp, "\t\tTodayInOut = %s    [���ճ����]\n", boost::lexical_cast<std::string>(TodayInOut).c_str());
	}
	if (compare(Premium, pOriginal->Premium) != 0)
	{
		fprintf(fp, "\t\tPremium = %s -> %s    [��ȨȨ������֧]\n", boost::lexical_cast<std::string>(pOriginal->Premium).c_str(), boost::lexical_cast<std::string>(Premium).c_str());
	}
	else
	{
		fprintf(fp, "\t\tPremium = %s    [��ȨȨ������֧]\n", boost::lexical_cast<std::string>(Premium).c_str());
	}
	if (compare(Risk, pOriginal->Risk) != 0)
	{
		fprintf(fp, "\t\tRisk = %s -> %s    [���ն�]\n", boost::lexical_cast<std::string>(pOriginal->Risk).c_str(), boost::lexical_cast<std::string>(Risk).c_str());
	}
	else
	{
		fprintf(fp, "\t\tRisk = %s    [���ն�]\n", boost::lexical_cast<std::string>(Risk).c_str());
	}
	fprintf(fp, "\t}\n");
}

void CInvestorPosition::dumpInLine(FILE *fp) const
{
	if (fp == nullptr)
	{
		fp = stdout;
	}
	std::stringstream sbuf;

	sbuf << ",InvestorID," << InvestorID;
	sbuf << ",BrokerID," << BrokerID;
	sbuf << ",ExchangeID," << ExchangeID;
	sbuf << ",ClientID," << ClientID;
	sbuf << ",InstrumentID," << InstrumentID;
	sbuf << ",Direction," << Direction;
	sbuf << ",HedgeFlag," << HedgeFlag;
	sbuf << ",UsedMargin," << UsedMargin;
	sbuf << ",Position," << Position;
	sbuf << ",PositionCost," << PositionCost;
	sbuf << ",YdPosition," << YdPosition;
	sbuf << ",YdPositionCost," << YdPositionCost;
	sbuf << ",FrozenMargin," << FrozenMargin;
	sbuf << ",FrozenPosition," << FrozenPosition;
	sbuf << ",FrozenClosing," << FrozenClosing;
	sbuf << ",FrozenPremium," << FrozenPremium;
	sbuf << ",LastTradeID," << LastTradeID;
	sbuf << ",LastOrderLocalID," << LastOrderLocalID;
	sbuf << ",Currency," << Currency;
	sbuf << ",FrozenCommission," << FrozenCommission;
	sbuf << ",Commission," << Commission;
	sbuf << ",FloatProfit," << FloatProfit;
	sbuf << ",CloseProfit," << CloseProfit;
	sbuf << ",CloseVolume," << CloseVolume;
	sbuf << ",CloseAmount," << CloseAmount;
	sbuf << ",LongFrozenMargin," << LongFrozenMargin;
	sbuf << ",ShortFrozenMargin," << ShortFrozenMargin;
	sbuf << ",LongMargin," << LongMargin;
	sbuf << ",ShortMargin," << ShortMargin;
	sbuf << ",ReleaseMargin," << ReleaseMargin;
	sbuf << ",Available," << Available;
	sbuf << ",Deposit," << Deposit;
	sbuf << ",Withdraw," << Withdraw;
	sbuf << ",PreBalance," << PreBalance;
	sbuf << ",DynamicRights," << DynamicRights;
	sbuf << ",TodayInOut," << TodayInOut;
	sbuf << ",Premium," << Premium;
	sbuf << ",Risk," << Risk;
	fprintf(fp, "%s", sbuf.str().c_str());
}

void CInvestorPosition::dumpString(char *target) const
{
	char *p = target;
	std::stringstream sbuf;

	sbuf << "InvestorID=" << InvestorID << ",";
	sbuf << "BrokerID=" << BrokerID << ",";
	sbuf << "ExchangeID=" << ExchangeID << ",";
	sbuf << "ClientID=" << ClientID << ",";
	sbuf << "InstrumentID=" << InstrumentID << ",";
	sbuf << "Direction=" << Direction << ",";
	sbuf << "HedgeFlag=" << HedgeFlag << ",";
	sbuf << "UsedMargin=" << UsedMargin << ",";
	sbuf << "Position=" << Position << ",";
	sbuf << "PositionCost=" << PositionCost << ",";
	sbuf << "YdPosition=" << YdPosition << ",";
	sbuf << "YdPositionCost=" << YdPositionCost << ",";
	sbuf << "FrozenMargin=" << FrozenMargin << ",";
	sbuf << "FrozenPosition=" << FrozenPosition << ",";
	sbuf << "FrozenClosing=" << FrozenClosing << ",";
	sbuf << "FrozenPremium=" << FrozenPremium << ",";
	sbuf << "LastTradeID=" << LastTradeID << ",";
	sbuf << "LastOrderLocalID=" << LastOrderLocalID << ",";
	sbuf << "Currency=" << Currency << ",";
	sbuf << "FrozenCommission=" << FrozenCommission << ",";
	sbuf << "Commission=" << Commission << ",";
	sbuf << "FloatProfit=" << FloatProfit << ",";
	sbuf << "CloseProfit=" << CloseProfit << ",";
	sbuf << "CloseVolume=" << CloseVolume << ",";
	sbuf << "CloseAmount=" << CloseAmount << ",";
	sbuf << "LongFrozenMargin=" << LongFrozenMargin << ",";
	sbuf << "ShortFrozenMargin=" << ShortFrozenMargin << ",";
	sbuf << "LongMargin=" << LongMargin << ",";
	sbuf << "ShortMargin=" << ShortMargin << ",";
	sbuf << "ReleaseMargin=" << ReleaseMargin << ",";
	sbuf << "Available=" << Available << ",";
	sbuf << "Deposit=" << Deposit << ",";
	sbuf << "Withdraw=" << Withdraw << ",";
	sbuf << "PreBalance=" << PreBalance << ",";
	sbuf << "DynamicRights=" << DynamicRights << ",";
	sbuf << "TodayInOut=" << TodayInOut << ",";
	sbuf << "Premium=" << Premium << ",";
	sbuf << "Risk=" << Risk << ",";

	sprintf(p, "%s", sbuf.str().c_str());
}

void CRuleInfo::init(void)
{
	memset(this, 0, sizeof(CRuleInfo));
}

int CRuleInfo::read(FILE *input)
{
	if (fread(this, 1, sizeof(CRuleInfo), input) != sizeof(CRuleInfo))
		return 0;
	else
		return 1;
}

int CRuleInfo::write(FILE *output) const
{
	if (fwrite(this, 1, sizeof(CRuleInfo), output) != sizeof(CRuleInfo))
		return 0;
	else
		return 1;
}

void CRuleInfo::dump(FILE *fp, int index) const
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
	fprintf(fp, "\tCRuleInfo%s = {\n", index_buf);
	fprintf(fp, "\t\tRuleID = %s    [���Դ���]\n", boost::lexical_cast<std::string>(RuleID).c_str());
	fprintf(fp, "\t\tRulePath = %s    [����Dll�洢λ��]\n", boost::lexical_cast<std::string>(RulePath).c_str());
	fprintf(fp, "\t\tRuleVersion = %s    [���Եİ汾]\n", boost::lexical_cast<std::string>(RuleVersion).c_str());
	fprintf(fp, "\t\tRuleName = %s    [��������]\n", boost::lexical_cast<std::string>(RuleName).c_str());
	fprintf(fp, "\t\tConfigPath = %s    [���������ļ��洢λ��]\n", boost::lexical_cast<std::string>(ConfigPath).c_str());
	fprintf(fp, "\t}\n");
}

void CRuleInfo::dumpDiff(FILE *fp, const CRuleInfo *pOriginal) const
{
	if (fp == nullptr)
	{
		fp = stdout;
	}
	fprintf(fp, "\tCRuleInfo = {\n");
	if (compare(RuleID, pOriginal->RuleID) != 0)
	{
		fprintf(fp, "\t\tRuleID = %s -> %s    [���Դ���]\n", boost::lexical_cast<std::string>(pOriginal->RuleID).c_str(), boost::lexical_cast<std::string>(RuleID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tRuleID = %s    [���Դ���]\n", boost::lexical_cast<std::string>(RuleID).c_str());
	}
	if (compare(RulePath, pOriginal->RulePath) != 0)
	{
		fprintf(fp, "\t\tRulePath = %s -> %s    [����Dll�洢λ��]\n", boost::lexical_cast<std::string>(pOriginal->RulePath).c_str(), boost::lexical_cast<std::string>(RulePath).c_str());
	}
	else
	{
		fprintf(fp, "\t\tRulePath = %s    [����Dll�洢λ��]\n", boost::lexical_cast<std::string>(RulePath).c_str());
	}
	if (compare(RuleVersion, pOriginal->RuleVersion) != 0)
	{
		fprintf(fp, "\t\tRuleVersion = %s -> %s    [���Եİ汾]\n", boost::lexical_cast<std::string>(pOriginal->RuleVersion).c_str(), boost::lexical_cast<std::string>(RuleVersion).c_str());
	}
	else
	{
		fprintf(fp, "\t\tRuleVersion = %s    [���Եİ汾]\n", boost::lexical_cast<std::string>(RuleVersion).c_str());
	}
	if (compare(RuleName, pOriginal->RuleName) != 0)
	{
		fprintf(fp, "\t\tRuleName = %s -> %s    [��������]\n", boost::lexical_cast<std::string>(pOriginal->RuleName).c_str(), boost::lexical_cast<std::string>(RuleName).c_str());
	}
	else
	{
		fprintf(fp, "\t\tRuleName = %s    [��������]\n", boost::lexical_cast<std::string>(RuleName).c_str());
	}
	if (compare(ConfigPath, pOriginal->ConfigPath) != 0)
	{
		fprintf(fp, "\t\tConfigPath = %s -> %s    [���������ļ��洢λ��]\n", boost::lexical_cast<std::string>(pOriginal->ConfigPath).c_str(), boost::lexical_cast<std::string>(ConfigPath).c_str());
	}
	else
	{
		fprintf(fp, "\t\tConfigPath = %s    [���������ļ��洢λ��]\n", boost::lexical_cast<std::string>(ConfigPath).c_str());
	}
	fprintf(fp, "\t}\n");
}

void CRuleInfo::dumpInLine(FILE *fp) const
{
	if (fp == nullptr)
	{
		fp = stdout;
	}
	std::stringstream sbuf;

	sbuf << ",RuleID," << RuleID;
	sbuf << ",RulePath," << RulePath;
	sbuf << ",RuleVersion," << RuleVersion;
	sbuf << ",RuleName," << RuleName;
	sbuf << ",ConfigPath," << ConfigPath;
	fprintf(fp, "%s", sbuf.str().c_str());
}

void CRuleInfo::dumpString(char *target) const
{
	char *p = target;

	std::stringstream sbuf;

	sbuf << "RuleID=" << RuleID << ",";
	sbuf << "RulePath=" << RulePath << ",";
	sbuf << "RuleVersion=" << RuleVersion << ",";
	sbuf << "RuleName=" << RuleName << ",";
	sbuf << "ConfigPath=" << ConfigPath << ",";

	sprintf(p, "%s", sbuf.str().c_str());
}

void CExchInvestorFee::init(void)
{
	memset(this, 0, sizeof(CExchInvestorFee));
}

int CExchInvestorFee::read(FILE *input)
{
	if (fread(this, 1, sizeof(CExchInvestorFee), input) != sizeof(CExchInvestorFee))
		return 0;
	else
		return 1;
}

int CExchInvestorFee::write(FILE *output) const
{
	if (fwrite(this, 1, sizeof(CExchInvestorFee), output) != sizeof(CExchInvestorFee))
		return 0;
	else
		return 1;
}

void CExchInvestorFee::dump(FILE *fp, int index) const
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

	fprintf(fp, "\tCExchInvestorFee%s = {\n", index_buf);
	fprintf(fp, "\t\tBrokerID = %s    [���͹�˾����]\n", boost::lexical_cast<std::string>(BrokerID).c_str());
	fprintf(fp, "\t\tClientID = %s    [�ͻ�����]\n", boost::lexical_cast<std::string>(ClientID).c_str());
	fprintf(fp, "\t\tExchangeID = %s    [����������]\n", boost::lexical_cast<std::string>(ExchangeID).c_str());
	fprintf(fp, "\t\tInstrumentID = %s    [��Լ����]\n", boost::lexical_cast<std::string>(InstrumentID).c_str());
	fprintf(fp, "\t\tProductID = %s    [Ʒ�ִ���]\n", boost::lexical_cast<std::string>(ProductID).c_str());
	fprintf(fp, "\t\tOpenFeeRate = %s    [���������Ѱ�����]\n", boost::lexical_cast<std::string>(OpenFeeRate).c_str());
	fprintf(fp, "\t\tOpenFeeAmt = %s    [���������Ѱ�����]\n", boost::lexical_cast<std::string>(OpenFeeAmt).c_str());
	fprintf(fp, "\t\tOffsetFeeRate = %s    [ƽ�������Ѱ�����]\n", boost::lexical_cast<std::string>(OffsetFeeRate).c_str());
	fprintf(fp, "\t\tOffsetFeeAmt = %s    [ƽ�������Ѱ�����]\n", boost::lexical_cast<std::string>(OffsetFeeAmt).c_str());
	fprintf(fp, "\t\tOTFeeRate = %s    [ƽ��������Ѱ�����]\n", boost::lexical_cast<std::string>(OTFeeRate).c_str());
	fprintf(fp, "\t\tOTFeeAmt = %s    [ƽ��������Ѱ�����]\n", boost::lexical_cast<std::string>(OTFeeAmt).c_str());
	fprintf(fp, "\t}\n");
}

void CExchInvestorFee::dumpDiff(FILE *fp, const CExchInvestorFee *pOriginal) const
{
	if (fp == NULL)
	{
		fp = stdout;
	}
	fprintf(fp, "\tCExchInvestorFee = {\n");
	if (compare(BrokerID, pOriginal->BrokerID) != 0)
	{
		fprintf(fp, "\t\tBrokerID = %s -> %s    [���͹�˾����]\n", boost::lexical_cast<std::string>(pOriginal->BrokerID).c_str(), boost::lexical_cast<std::string>(BrokerID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBrokerID = %s    [���͹�˾����]\n", boost::lexical_cast<std::string>(BrokerID).c_str());
	}
	if (compare(ClientID, pOriginal->ClientID) != 0)
	{
		fprintf(fp, "\t\tClientID = %s -> %s    [�ͻ�����]\n", boost::lexical_cast<std::string>(pOriginal->ClientID).c_str(), boost::lexical_cast<std::string>(ClientID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tClientID = %s    [�ͻ�����]\n", boost::lexical_cast<std::string>(ClientID).c_str());
	}
	if (compare(ExchangeID, pOriginal->ExchangeID) != 0)
	{
		fprintf(fp, "\t\tExchangeID = %s -> %s    [����������]\n", boost::lexical_cast<std::string>(pOriginal->ExchangeID).c_str(), boost::lexical_cast<std::string>(ExchangeID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tExchangeID = %s    [����������]\n", boost::lexical_cast<std::string>(ExchangeID).c_str());
	}
	if (compare(InstrumentID, pOriginal->InstrumentID) != 0)
	{
		fprintf(fp, "\t\tInstrumentID = %s -> %s    [��Լ����]\n", boost::lexical_cast<std::string>(pOriginal->InstrumentID).c_str(), boost::lexical_cast<std::string>(InstrumentID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tInstrumentID = %s    [��Լ����]\n", boost::lexical_cast<std::string>(InstrumentID).c_str());
	}
	if (compare(ProductID, pOriginal->ProductID) != 0)
	{
		fprintf(fp, "\t\tProductID = %s -> %s    [Ʒ�ִ���]\n", boost::lexical_cast<std::string>(pOriginal->ProductID).c_str(), boost::lexical_cast<std::string>(ProductID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tProductID = %s    [Ʒ�ִ���]\n", boost::lexical_cast<std::string>(ProductID).c_str());
	}
	if (compare(OpenFeeRate, pOriginal->OpenFeeRate) != 0)
	{
		fprintf(fp, "\t\tOpenFeeRate = %s -> %s    [���������Ѱ�����]\n", boost::lexical_cast<std::string>(pOriginal->OpenFeeRate).c_str(), boost::lexical_cast<std::string>(OpenFeeRate).c_str());
	}
	else
	{
		fprintf(fp, "\t\tOpenFeeRate = %s    [���������Ѱ�����]\n", boost::lexical_cast<std::string>(OpenFeeRate).c_str());
	}
	if (compare(OpenFeeAmt, pOriginal->OpenFeeAmt) != 0)
	{
		fprintf(fp, "\t\tOpenFeeAmt = %s -> %s    [���������Ѱ�����]\n", boost::lexical_cast<std::string>(pOriginal->OpenFeeAmt).c_str(), boost::lexical_cast<std::string>(OpenFeeAmt).c_str());
	}
	else
	{
		fprintf(fp, "\t\tOpenFeeAmt = %s    [���������Ѱ�����]\n", boost::lexical_cast<std::string>(OpenFeeAmt).c_str());
	}
	if (compare(OffsetFeeRate, pOriginal->OffsetFeeRate) != 0)
	{
		fprintf(fp, "\t\tOffsetFeeRate = %s -> %s    [ƽ�������Ѱ�����]\n", boost::lexical_cast<std::string>(pOriginal->OffsetFeeRate).c_str(), boost::lexical_cast<std::string>(OffsetFeeRate).c_str());
	}
	else
	{
		fprintf(fp, "\t\tOffsetFeeRate = %s    [ƽ�������Ѱ�����]\n", boost::lexical_cast<std::string>(OffsetFeeRate).c_str());
	}
	if (compare(OffsetFeeAmt, pOriginal->OffsetFeeAmt) != 0)
	{
		fprintf(fp, "\t\tOffsetFeeAmt = %s -> %s    [ƽ�������Ѱ�����]\n", boost::lexical_cast<std::string>(pOriginal->OffsetFeeAmt).c_str(), boost::lexical_cast<std::string>(OffsetFeeAmt).c_str());
	}
	else
	{
		fprintf(fp, "\t\tOffsetFeeAmt = %s    [ƽ�������Ѱ�����]\n", boost::lexical_cast<std::string>(OffsetFeeAmt).c_str());
	}
	if (compare(OTFeeRate, pOriginal->OTFeeRate) != 0)
	{
		fprintf(fp, "\t\tOTFeeRate = %s -> %s    [ƽ��������Ѱ�����]\n", boost::lexical_cast<std::string>(pOriginal->OTFeeRate).c_str(), boost::lexical_cast<std::string>(OTFeeRate).c_str());
	}
	else
	{
		fprintf(fp, "\t\tOTFeeRate = %s    [ƽ��������Ѱ�����]\n", boost::lexical_cast<std::string>(OTFeeRate).c_str());
	}
	if (compare(OTFeeAmt, pOriginal->OTFeeAmt) != 0)
	{
		fprintf(fp, "\t\tOTFeeAmt = %s -> %s    [ƽ��������Ѱ�����]\n", boost::lexical_cast<std::string>(pOriginal->OTFeeAmt).c_str(), boost::lexical_cast<std::string>(OTFeeAmt).c_str());
	}
	else
	{
		fprintf(fp, "\t\tOTFeeAmt = %s    [ƽ��������Ѱ�����]\n", boost::lexical_cast<std::string>(OTFeeAmt).c_str());
	}
	fprintf(fp, "\t}\n");
}

void CExchInvestorFee::dumpInLine(FILE *fp) const
{
	if (fp == nullptr)
	{
		fp = stdout;
	}
	std::stringstream sbuf;

	sbuf << ",BrokerID," << BrokerID;
	sbuf << ",ClientID," << ClientID;
	sbuf << ",ExchangeID," << ExchangeID;
	sbuf << ",InstrumentID," << InstrumentID;
	sbuf << ",ProductID," << ProductID;
	sbuf << ",OpenFeeRate," << OpenFeeRate;
	sbuf << ",OpenFeeAmt," << OpenFeeAmt;
	sbuf << ",OffsetFeeRate," << OffsetFeeRate;
	sbuf << ",OffsetFeeAmt," << OffsetFeeAmt;
	sbuf << ",OTFeeRate," << OTFeeRate;
	sbuf << ",OTFeeAmt," << OTFeeAmt;
	fprintf(fp, "%s", sbuf.str().c_str());
}

void CExchInvestorFee::dumpString(char *target) const
{
	char *p = target;
	std::stringstream sbuf;

	sbuf << "BrokerID=" << BrokerID << ",";
	sbuf << "ClientID=" << ClientID << ",";
	sbuf << "ExchangeID=" << ExchangeID << ",";
	sbuf << "InstrumentID=" << InstrumentID << ",";
	sbuf << "ProductID=" << ProductID << ",";
	sbuf << "OpenFeeRate=" << OpenFeeRate << ",";
	sbuf << "OpenFeeAmt=" << OpenFeeAmt << ",";
	sbuf << "OffsetFeeRate=" << OffsetFeeRate << ",";
	sbuf << "OffsetFeeAmt=" << OffsetFeeAmt << ",";
	sbuf << "OTFeeRate=" << OTFeeRate << ",";
	sbuf << "OTFeeAmt=" << OTFeeAmt << ",";

	sprintf(p, "%s", sbuf.str().c_str());
}

void CExchInvestorMargin::init(void)
{
	memset(this, 0, sizeof(CExchInvestorMargin));
}

int CExchInvestorMargin::read(FILE *input)
{
	if (fread(this, 1, sizeof(CExchInvestorMargin), input) != sizeof(CExchInvestorMargin))
		return 0;
	else
		return 1;
}

int CExchInvestorMargin::write(FILE *output) const
{
	if (fwrite(this, 1, sizeof(CExchInvestorMargin), output) != sizeof(CExchInvestorMargin))
		return 0;
	else
		return 1;
}

void CExchInvestorMargin::dump(FILE *fp, int index) const
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
	fprintf(fp, "\tCExchInvestorMargin%s = {\n", index_buf);
	fprintf(fp, "\t\tBrokerID = %s    [���͹�˾����]\n", boost::lexical_cast<std::string>(BrokerID).c_str());
	fprintf(fp, "\t\tClientID = %s    [�ͻ�����]\n", boost::lexical_cast<std::string>(ClientID).c_str());
	fprintf(fp, "\t\tExchangeID = %s    [����������]\n", boost::lexical_cast<std::string>(ExchangeID).c_str());
	fprintf(fp, "\t\tInstrumentID = %s    [��Լ����]\n", boost::lexical_cast<std::string>(InstrumentID).c_str());
	fprintf(fp, "\t\tProductID = %s    [Ʒ�ִ���]\n", boost::lexical_cast<std::string>(ProductID).c_str());
	fprintf(fp, "\t\tLongMarginRate = %s    [��ͷռ�ñ�֤�𰴱���]\n", boost::lexical_cast<std::string>(LongMarginRate).c_str());
	fprintf(fp, "\t\tLongMarginAmt = %s    [��ͷ��֤������]\n", boost::lexical_cast<std::string>(LongMarginAmt).c_str());
	fprintf(fp, "\t\tShortMarginRate = %s    [��ͷռ�ñ�֤�𰴱���]\n", boost::lexical_cast<std::string>(ShortMarginRate).c_str());
	fprintf(fp, "\t\tShortMarginAmt = %s    [��ͷ��֤������]\n", boost::lexical_cast<std::string>(ShortMarginAmt).c_str());
	fprintf(fp, "\t}\n");
}

void CExchInvestorMargin::dumpDiff(FILE *fp, const CExchInvestorMargin *pOriginal) const
{
	if (fp == nullptr)
	{
		fp = stdout;
	}
	fprintf(fp, "\tCExchInvestorMargin = {\n");
	if (compare(BrokerID, pOriginal->BrokerID) != 0)
	{
		fprintf(fp, "\t\tBrokerID = %s -> %s    [���͹�˾����]\n", boost::lexical_cast<std::string>(pOriginal->BrokerID).c_str(), boost::lexical_cast<std::string>(BrokerID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tBrokerID = %s    [���͹�˾����]\n", boost::lexical_cast<std::string>(BrokerID).c_str());
	}
	if (compare(ClientID, pOriginal->ClientID) != 0)
	{
		fprintf(fp, "\t\tClientID = %s -> %s    [�ͻ�����]\n", boost::lexical_cast<std::string>(pOriginal->ClientID).c_str(), boost::lexical_cast<std::string>(ClientID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tClientID = %s    [�ͻ�����]\n", boost::lexical_cast<std::string>(ClientID).c_str());
	}
	if (compare(ExchangeID, pOriginal->ExchangeID) != 0)
	{
		fprintf(fp, "\t\tExchangeID = %s -> %s    [����������]\n", boost::lexical_cast<std::string>(pOriginal->ExchangeID).c_str(), boost::lexical_cast<std::string>(ExchangeID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tExchangeID = %s    [����������]\n", boost::lexical_cast<std::string>(ExchangeID).c_str());
	}
	if (compare(InstrumentID, pOriginal->InstrumentID) != 0)
	{
		fprintf(fp, "\t\tInstrumentID = %s -> %s    [��Լ����]\n", boost::lexical_cast<std::string>(pOriginal->InstrumentID).c_str(), boost::lexical_cast<std::string>(InstrumentID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tInstrumentID = %s    [��Լ����]\n", boost::lexical_cast<std::string>(InstrumentID).c_str());
	}
	if (compare(ProductID, pOriginal->ProductID) != 0)
	{
		fprintf(fp, "\t\tProductID = %s -> %s    [Ʒ�ִ���]\n", boost::lexical_cast<std::string>(pOriginal->ProductID).c_str(), boost::lexical_cast<std::string>(ProductID).c_str());
	}
	else
	{
		fprintf(fp, "\t\tProductID = %s    [Ʒ�ִ���]\n", boost::lexical_cast<std::string>(ProductID).c_str());
	}
	if (compare(LongMarginRate, pOriginal->LongMarginRate) != 0)
	{
		fprintf(fp, "\t\tLongMarginRate = %s -> %s    [��ͷռ�ñ�֤�𰴱���]\n", boost::lexical_cast<std::string>(pOriginal->LongMarginRate).c_str(), boost::lexical_cast<std::string>(LongMarginRate).c_str());
	}
	else
	{
		fprintf(fp, "\t\tLongMarginRate = %s    [��ͷռ�ñ�֤�𰴱���]\n", boost::lexical_cast<std::string>(LongMarginRate).c_str());
	}
	if (compare(LongMarginAmt, pOriginal->LongMarginAmt) != 0)
	{
		fprintf(fp, "\t\tLongMarginAmt = %s -> %s    [��ͷ��֤������]\n", boost::lexical_cast<std::string>(pOriginal->LongMarginAmt).c_str(), boost::lexical_cast<std::string>(LongMarginAmt).c_str());
	}
	else
	{
		fprintf(fp, "\t\tLongMarginAmt = %s    [��ͷ��֤������]\n", boost::lexical_cast<std::string>(LongMarginAmt).c_str());
	}
	if (compare(ShortMarginRate, pOriginal->ShortMarginRate) != 0)
	{
		fprintf(fp, "\t\tShortMarginRate = %s -> %s    [��ͷռ�ñ�֤�𰴱���]\n", boost::lexical_cast<std::string>(pOriginal->ShortMarginRate).c_str(), boost::lexical_cast<std::string>(ShortMarginRate).c_str());
	}
	else
	{
		fprintf(fp, "\t\tShortMarginRate = %s    [��ͷռ�ñ�֤�𰴱���]\n", boost::lexical_cast<std::string>(ShortMarginRate).c_str());
	}
	if (compare(ShortMarginAmt, pOriginal->ShortMarginAmt) != 0)
	{
		fprintf(fp, "\t\tShortMarginAmt = %s -> %s    [��ͷ��֤������]\n", boost::lexical_cast<std::string>(pOriginal->ShortMarginAmt).c_str(), boost::lexical_cast<std::string>(ShortMarginAmt).c_str());
	}
	else
	{
		fprintf(fp, "\t\tShortMarginAmt = %s    [��ͷ��֤������]\n", boost::lexical_cast<std::string>(ShortMarginAmt).c_str());
	}
	fprintf(fp, "\t}\n");
}

void CExchInvestorMargin::dumpInLine(FILE *fp) const
{
	if (fp == nullptr)
	{
		fp = stdout;
	}
	std::stringstream sbuf;

	sbuf << ",BrokerID," << BrokerID;
	sbuf << ",ClientID," << ClientID;
	sbuf << ",ExchangeID," << ExchangeID;
	sbuf << ",InstrumentID," << InstrumentID;
	sbuf << ",ProductID," << ProductID;
	sbuf << ",LongMarginRate," << LongMarginRate;
	sbuf << ",LongMarginAmt," << LongMarginAmt;
	sbuf << ",ShortMarginRate," << ShortMarginRate;
	sbuf << ",ShortMarginAmt," << ShortMarginAmt;
	fprintf(fp, "%s", sbuf.str().c_str());
}

void CExchInvestorMargin::dumpString(char *target) const
{
	char *p = target;
	std::stringstream sbuf;

	sbuf << "BrokerID=" << BrokerID << ",";
	sbuf << "ClientID=" << ClientID << ",";
	sbuf << "ExchangeID=" << ExchangeID << ",";
	sbuf << "InstrumentID=" << InstrumentID << ",";
	sbuf << "ProductID=" << ProductID << ",";
	sbuf << "LongMarginRate=" << LongMarginRate << ",";
	sbuf << "LongMarginAmt=" << LongMarginAmt << ",";
	sbuf << "ShortMarginRate=" << ShortMarginRate << ",";
	sbuf << "ShortMarginAmt=" << ShortMarginAmt << ",";

	sprintf(p, "%s", sbuf.str().c_str());
}