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