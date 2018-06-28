
#include "Tables.h"
#include "RecordStruct.h"
#include "ProcessCSVTable.h"
#include "../utility/mpath.h"
#include <boost/foreach.hpp>


//强制进行复制，不理会const标记
//@param	target	复制的目标地址
//@param	source	复制的源地址
//@param	size	复制的空间大小
static void forceCopy(const void *target, const void *source, int size)
{
	if ((source == nullptr) || (target == nullptr))
		return;
	
	memcpy((void *)target, source, size);
}

CCurrentTimeFactory::CCurrentTimeFactory(const std::string &TableName) 
	: COutputTable(TableName)
{
	
}

CCurrentTimeFactory::~CCurrentTimeFactory()
{

}

int CCurrentTimeFactory::writeCSV(const char* filename)
{
	FILE* input;
	input = mfopen(filename, "rt");
	if (input == nullptr)
		return 0;
	
	std::vector<int> headmap = CProcessCSVRecordFile::readCSVHead(input, 
		&CWriteableCurrentTime::field_desc_);
	
	if (headmap.empty())
	{
		//没有取得csv的字段头
		return 0;
	}

	CWriteableCurrentTime thisCurrentTime;
	while (CProcessCSVRecordFile::readCSVRow(input, &thisCurrentTime,
		headmap, &CWriteableCurrentTime::field_desc_));
	{
		insert(&thisCurrentTime, 0);
	}
	
	fclose(input);
	return 1;
}

int CCurrentTimeFactory::writeCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVWritePath");
	szFileName += getCsvFileName();
	return writeCSV(szFileName.c_str());
}

int CCurrentTimeFactory::readCSV(const char *filename)
{
	FILE *input;
	input = mfopen(filename, "rt");
	if (input == NULL) { return 0; }

	std::vector<int> headmap = CProcessCSVRecordFile::readCSVHead(input, &CWriteableCurrentTime::field_desc_);
	if (headmap.empty())
	{
		// 没有取得csv的字段头
		return 0;
	}

	CWriteableCurrentTime thisCurrentTime;
	while (CProcessCSVRecordFile::readCSVRow(input, &thisCurrentTime, headmap, &CWriteableCurrentTime::field_desc_))
	{
		insert(&thisCurrentTime, 0);
	}
	fclose(input);
	return 1;
}

int CCurrentTimeFactory::readCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVReadPath");
	szFileName += getCsvFileName();
	return readCSV(szFileName.c_str());
}

//讲内容写到文件中，用于debug
void CCurrentTimeFactory::dump(FILE* fp)
{
	int index = 0; ///下标
	if (fp == nullptr) 
		fp = stdout;

	fprintf(fp, "CCurrentTimeFactory={       Total Count=%d\n", getCount());
	BOOST_FOREACH(Idx_Cont_CurrentTime::value_type v, getContainer())
	{
		v->dump(fp, index++);
	}
	fprintf(fp, "}\n");
}

//讲内容写到文件中，用于debug
void CCurrentTimeFactory::dump(char* filename)
{
	FILE *fp;
	fp = mfopen(filename, "w+b");
	dump(fp);
	if (fp != nullptr) 
		fclose(fp);
}

//清空所有记录
void CCurrentTimeFactory::clearAll()
{
	getContainer().clear();
}

//增加或者更新数据
CCurrentTime* CCurrentTimeFactory::addOrUpdate(CCurrentTime *pCurrentTime,
	CWriteableCurrentTime *pNewCurrentTime, CTransaction *pTransaction, bool updateIndex)
{
	if (pCurrentTime == nullptr)
	{
		return insert(pNewCurrentTime, pTransaction);
	}
	else
	{
		update(pCurrentTime, pNewCurrentTime, pTransaction);
		return pCurrentTime;
	}
}

//获取某个CCurrentTime
void CCurrentTimeFactory::retrieve(CCurrentTime *pCurrentTime,
	CWriteableCurrentTime *pTargetCurrentTime)
{
	forceCopy(pTargetCurrentTime, pCurrentTime, sizeof(CCurrentTime));
}

CTerminalFactory::CTerminalFactory(const std::string &TableName) 
	: COutputTable(TableName)
{

}

CTerminalFactory::~CTerminalFactory(void)
{

}

int  CTerminalFactory::readCSV(const char *filename)
{
	FILE *input;
	input = mfopen(filename, "rt");
	if (input == nullptr) 
		return 0;

	std::vector<int> headmap = CProcessCSVRecordFile::readCSVHead(input, &CWriteableTerminal::field_desc_);
	if (headmap.empty())
	{
		// 没有取得csv的字段头
		return 0;
	}

	CWriteableTerminal thisTerminal;
	while (CProcessCSVRecordFile::readCSVRow(input, &thisTerminal, headmap, &CWriteableTerminal::field_desc_))
	{
		insert(&thisTerminal, 0);
	}
	fclose(input);
	return 1;
}

int  CTerminalFactory::readCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVReadPath");
	szFileName += getCsvFileName();
	return readCSV(szFileName.c_str());
}

int  CTerminalFactory::writeCSV(const char *filename)
{
	FILE *output = mfopen(filename, "wt");
	if (output == nullptr)
		return 0;

	CProcessCSVRecordFile::writeCSVHead(output, &CWriteableTerminal::field_desc_);

	typedef Index_Container_Type::nth_index<0>::type BaseIndex;
	typedef BaseIndex::value_type value_type;
	BaseIndex &baseIndex = getContainer().get<0>();

	BOOST_FOREACH(value_type v, baseIndex)
	{
		CProcessCSVRecordFile::writeCSVRow(output, v.get(), &CWriteableTerminal::field_desc_);
	}
	fclose(output);
	return 1;
}

int  CTerminalFactory::writeCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVWritePath");
	szFileName += getCsvFileName();
	return writeCSV(szFileName.c_str());
}

void CTerminalFactory::dump(char *filename)
{
	FILE *fp;
	fp = mfopen(filename, "w+b");
	dump(fp);
	if (fp != nullptr) 
		fclose(fp);
}

void CTerminalFactory::dump(FILE *fp)
{
	int index = 0; ///下标
	if (fp == nullptr) 
		fp = stdout;

	fprintf(fp, "CTerminalFactory={       Total Count=%d\n", getCount());
	BOOST_FOREACH(Idx_Cont_Terminal::value_type v, getContainer())
	{
		v->dump(fp, index++);
	}
	fprintf(fp, "}\n");
}

void CTerminalFactory::clearAll(void)
{
	getContainer().clear();
}

CTerminal* CTerminalFactory::addOrUpdate(CTerminal *pTerminal, CWriteableTerminal *pNewTerminal, CTransaction *pTransaction, bool updateIndex)
{
	if (pTerminal == nullptr) 
	{
		return insert(pNewTerminal, pTransaction);
	}
	else 
	{
		update(pTerminal, pNewTerminal, pTransaction);
		return pTerminal;
	}
}

void CTerminalFactory::retrieve(CTerminal *pTerminal, CWriteableTerminal *pTargetTerminal)
{
	forceCopy(pTargetTerminal, pTerminal, sizeof(CTerminal));
}

CFrontFactory::CFrontFactory(const std::string &TableName) 
	: COutputTable(TableName)
{

}

CFrontFactory::~CFrontFactory(void)
{

}

int  CFrontFactory::readCSV(const char *filename)
{
	FILE *input;
	input = mfopen(filename, "rt");
	if (input == nullptr)
		return 0;

	std::vector<int> headmap = CProcessCSVRecordFile::readCSVHead(input, &CWriteableFront::field_desc_);
	if (headmap.empty())
	{
		// 没有取得csv的字段头
		return 0;
	}

	CWriteableFront thisFront;
	while (CProcessCSVRecordFile::readCSVRow(input, &thisFront, headmap, &CWriteableFront::field_desc_))
	{
		insert(&thisFront, 0);
	}
	fclose(input);
	return 1;
}

int  CFrontFactory::readCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVReadPath");
	szFileName += getCsvFileName();
	return readCSV(szFileName.c_str());
}

int  CFrontFactory::writeCSV(const char *filename)
{
	FILE *output = mfopen(filename, "wt");
	if (output == nullptr)
		return 0;

	CProcessCSVRecordFile::writeCSVHead(output, &CWriteableFront::field_desc_);

	typedef Index_Container_Type::nth_index<0>::type BaseIndex;
	typedef BaseIndex::value_type value_type;
	BaseIndex &baseIndex = getContainer().get<0>();

	BOOST_FOREACH(value_type v, baseIndex)
	{
		CProcessCSVRecordFile::writeCSVRow(output, v.get(), &CWriteableFront::field_desc_);
	}
	fclose(output);
	return 1;
}

int  CFrontFactory::writeCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVWritePath");
	szFileName += getCsvFileName();
	return writeCSV(szFileName.c_str());
}

void CFrontFactory::dump(char *filename)
{
	FILE *fp;
	fp = mfopen(filename, "w+b");
	dump(fp);
	if (fp != nullptr) 
		fclose(fp);
}

void CFrontFactory::dump(FILE *fp)
{
	int index = 0; ///下标
	if (fp == nullptr) 
		fp = stdout;

	fprintf(fp, "CFrontFactory={       Total Count=%d\n", getCount());
	BOOST_FOREACH(Idx_Cont_Front::value_type v, getContainer())
	{
		v->dump(fp, index++);
	}
	fprintf(fp, "}\n");
}

void CFrontFactory::clearAll(void)
{
	getContainer().clear();
}

CFront* CFrontFactory::addOrUpdate(CFront *pFront, CWriteableFront *pNewFront, CTransaction *pTransaction, bool updateIndex)
{
	if (pFront == nullptr) 
	{
		return insert(pNewFront, pTransaction);
	}
	else 
	{
		update(pFront, pNewFront, pTransaction);
		return pFront;
	}
}

void CFrontFactory::retrieve(CFront *pFront, CWriteableFront *pTargetFront)
{
	forceCopy(pTargetFront, pFront, sizeof(CFront));
}

CTraderFactory::CTraderFactory(const std::string &TableName) :COutputTable(TableName)
{

}

CTraderFactory::~CTraderFactory(void)
{

}

int  CTraderFactory::readCSV(const char *filename)
{
	FILE *input;
	input = mfopen(filename, "rt");
	if (input == nullptr)
		return 0;

	std::vector<int> headmap = CProcessCSVRecordFile::readCSVHead(input, &CWriteableTrader::field_desc_);
	if (headmap.empty())
	{
		// 没有取得csv的字段头
		return 0;
	}

	CWriteableTrader thisTrader;
	while (CProcessCSVRecordFile::readCSVRow(input, &thisTrader, headmap, &CWriteableTrader::field_desc_))
	{
		insert(&thisTrader, 0);
	}
	fclose(input);
	return 1;
}

int  CTraderFactory::readCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVReadPath");
	szFileName += getCsvFileName();
	return readCSV(szFileName.c_str());
}

int  CTraderFactory::writeCSV(const char *filename)
{
	FILE *output = mfopen(filename, "wt");
	if (output == nullptr)
		return 0;

	CProcessCSVRecordFile::writeCSVHead(output, &CWriteableTrader::field_desc_);

	typedef Index_Container_Type::nth_index<0>::type BaseIndex;
	typedef BaseIndex::value_type value_type;
	BaseIndex &baseIndex = getContainer().get<0>();

	BOOST_FOREACH(value_type v, baseIndex)
	{
		CProcessCSVRecordFile::writeCSVRow(output, v.get(), &CWriteableTrader::field_desc_);
	}
	fclose(output);
	return 1;
}

int  CTraderFactory::writeCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVWritePath");
	szFileName += getCsvFileName();
	return writeCSV(szFileName.c_str());
}

void CTraderFactory::dump(char *filename)
{
	FILE *fp;
	fp = mfopen(filename, "w+b");
	dump(fp);
	if (fp != nullptr) 
		fclose(fp);
}

void CTraderFactory::dump(FILE *fp)
{
	int index = 0; ///下标
	if (fp == nullptr) 
		fp = stdout;

	fprintf(fp, "CTraderFactory={       Total Count=%d\n", getCount());
	BOOST_FOREACH(Idx_Cont_Trader::value_type v, getContainer())
	{
		v->dump(fp, index++);
	}
	fprintf(fp, "}\n");
}

void CTraderFactory::clearAll(void)
{
	getContainer().clear();
}

CTrader* CTraderFactory::addOrUpdate(CTrader *pTrader, CWriteableTrader *pNewTrader, CTransaction *pTransaction, bool updateIndex)
{
	if (pTrader == nullptr) 
	{
		return insert(pNewTrader, pTransaction);
	}
	else 
	{
		update(pTrader, pNewTrader, pTransaction);
		return pTrader;
	}
}

void CTraderFactory::retrieve(CTrader *pTrader, CWriteableTrader *pTargetTrader)
{
	forceCopy(pTargetTrader, pTrader, sizeof(CTrader));
}

CTraderParalleFactory::CTraderParalleFactory(const std::string &TableName) :COutputTable(TableName)
{

}

CTraderParalleFactory::~CTraderParalleFactory(void)
{

}

int  CTraderParalleFactory::readCSV(const char *filename)
{
	FILE *input;
	input = mfopen(filename, "rt");
	if (input == nullptr)
		return 0;

	std::vector<int> headmap = CProcessCSVRecordFile::readCSVHead(input, &CWriteableTraderParalle::field_desc_);
	if (headmap.empty())
	{
		// 没有取得csv的字段头
		return 0;
	}

	CWriteableTraderParalle thisTraderParalle;
	while (CProcessCSVRecordFile::readCSVRow(input, &thisTraderParalle, headmap, &CWriteableTraderParalle::field_desc_))
	{
		insert(&thisTraderParalle, 0);
	}
	fclose(input);
	return 1;
}

int  CTraderParalleFactory::readCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVReadPath");
	szFileName += getCsvFileName();
	return readCSV(szFileName.c_str());
}

int  CTraderParalleFactory::writeCSV(const char *filename)
{
	FILE *output = mfopen(filename, "wt");
	if (output == nullptr)
		return 0;

	CProcessCSVRecordFile::writeCSVHead(output, &CWriteableTraderParalle::field_desc_);

	typedef Index_Container_Type::nth_index<0>::type BaseIndex;
	typedef BaseIndex::value_type value_type;
	BaseIndex &baseIndex = getContainer().get<0>();

	BOOST_FOREACH(value_type v, baseIndex)
	{
		CProcessCSVRecordFile::writeCSVRow(output, v.get(), &CWriteableTraderParalle::field_desc_);
	}
	fclose(output);
	return 1;
}

int  CTraderParalleFactory::writeCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVWritePath");
	szFileName += getCsvFileName();
	return writeCSV(szFileName.c_str());
}

void CTraderParalleFactory::dump(char *filename)
{
	FILE *fp;
	fp = mfopen(filename, "w+b");
	dump(fp);
	if (fp != nullptr) 
		fclose(fp);
}

void CTraderParalleFactory::dump(FILE *fp)
{
	int index = 0; ///下标
	if (fp == nullptr) 
		fp = stdout;

	fprintf(fp, "CTraderParalleFactory={       Total Count=%d\n", getCount());
	BOOST_FOREACH(Idx_Cont_TraderParalle::value_type v, getContainer())
	{
		v->dump(fp, index++);
	}
	fprintf(fp, "}\n");
}

void CTraderParalleFactory::clearAll(void)
{
	getContainer().clear();
}

CTraderParalle* CTraderParalleFactory::addOrUpdate(CTraderParalle *pTraderParalle, CWriteableTraderParalle *pNewTraderParalle, CTransaction *pTransaction, bool updateIndex)
{
	if (pTraderParalle == nullptr) 
	{
		return insert(pNewTraderParalle, pTransaction);
	}
	else 
	{
		update(pTraderParalle, pNewTraderParalle, pTransaction);
		return pTraderParalle;
	}
}

void CTraderParalleFactory::retrieve(CTraderParalle *pTraderParalle, CWriteableTraderParalle *pTargetTraderParalle)
{
	forceCopy(pTargetTraderParalle, pTraderParalle, sizeof(CTraderParalle));
}

CTraderLoginLogFactory::CTraderLoginLogFactory(const std::string &TableName) :COutputTable(TableName)
{

}

CTraderLoginLogFactory::~CTraderLoginLogFactory(void)
{

}

int  CTraderLoginLogFactory::readCSV(const char *filename)
{
	FILE *input;
	input = mfopen(filename, "rt");
	if (input == nullptr)
		return 0;

	std::vector<int> headmap = CProcessCSVRecordFile::readCSVHead(input, &CWriteableTraderLoginLog::field_desc_);
	if (headmap.empty())
	{
		return 0;
	}

	CWriteableTraderLoginLog thisTraderLoginLog;
	while (CProcessCSVRecordFile::readCSVRow(input, &thisTraderLoginLog, headmap, &CWriteableTraderLoginLog::field_desc_))
	{
		insert(&thisTraderLoginLog, 0);
	}
	fclose(input);
	return 1;
}

int  CTraderLoginLogFactory::readCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVReadPath");
	szFileName += getCsvFileName();
	return readCSV(szFileName.c_str());
}

int  CTraderLoginLogFactory::writeCSV(const char *filename)
{
	FILE *output = mfopen(filename, "wt");
	if (output == NULL) { return 0; }

	CProcessCSVRecordFile::writeCSVHead(output, &CWriteableTraderLoginLog::field_desc_);

	typedef Index_Container_Type::nth_index<0>::type BaseIndex;
	typedef BaseIndex::value_type value_type;
	BaseIndex &baseIndex = getContainer().get<0>();

	BOOST_FOREACH(value_type v, baseIndex)
	{
		CProcessCSVRecordFile::writeCSVRow(output, v.get(), &CWriteableTraderLoginLog::field_desc_);
	}
	fclose(output);
	return 1;
}

int  CTraderLoginLogFactory::writeCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVWritePath");
	szFileName += getCsvFileName();
	return writeCSV(szFileName.c_str());
}

void CTraderLoginLogFactory::dump(char *filename)
{
	FILE *fp;
	fp = mfopen(filename, "w+b");
	dump(fp);
	if (fp != nullptr) 
		fclose(fp);
}

void CTraderLoginLogFactory::dump(FILE *fp)
{
	int index = 0; ///下标
	if (fp == nullptr)
		fp = stdout;

	fprintf(fp, "CTraderLoginLogFactory={       Total Count=%d\n", getCount());
	BOOST_FOREACH(Idx_Cont_TraderLoginLog::value_type v, getContainer())
	{
		v->dump(fp, index++);
	}
	fprintf(fp, "}\n");
}

void CTraderLoginLogFactory::clearAll(void)
{
	getContainer().clear();
}

CTraderLoginLog* CTraderLoginLogFactory::addOrUpdate(CTraderLoginLog *pTraderLoginLog, CWriteableTraderLoginLog *pNewTraderLoginLog, CTransaction *pTransaction, bool updateIndex)
{
	if (pTraderLoginLog == nullptr) 
	{
		return insert(pNewTraderLoginLog, pTransaction);
	}
	else 
	{
		update(pTraderLoginLog, pNewTraderLoginLog, pTransaction);
		return pTraderLoginLog;
	}
}

void CTraderLoginLogFactory::retrieve(CTraderLoginLog *pTraderLoginLog, CWriteableTraderLoginLog *pTargetTraderLoginLog)
{
	forceCopy(pTargetTraderLoginLog, pTraderLoginLog, sizeof(CTraderLoginLog));
}

CTraderConnectFactory::CTraderConnectFactory(const std::string &TableName) :COutputTable(TableName)
{

}

CTraderConnectFactory::~CTraderConnectFactory(void)
{

}

int  CTraderConnectFactory::readCSV(const char *filename)
{
	FILE *input;
	input = mfopen(filename, "rt");
	if (input == nullptr)
		return 0;

	std::vector<int> headmap = CProcessCSVRecordFile::readCSVHead(input, &CWriteableTraderConnect::field_desc_);
	if (headmap.empty())
	{
		// 没有取得csv的字段头
		return 0;
	}

	CWriteableTraderConnect thisTraderConnect;
	while (CProcessCSVRecordFile::readCSVRow(input, &thisTraderConnect, headmap, &CWriteableTraderConnect::field_desc_))
	{
		insert(&thisTraderConnect, 0);
	}
	fclose(input);
	return 1;
}

int  CTraderConnectFactory::readCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVReadPath");
	szFileName += getCsvFileName();
	return readCSV(szFileName.c_str());
}

int  CTraderConnectFactory::writeCSV(const char *filename)
{
	FILE *output = mfopen(filename, "wt");
	if (output == NULL) { return 0; }

	CProcessCSVRecordFile::writeCSVHead(output, &CWriteableTraderConnect::field_desc_);

	typedef Index_Container_Type::nth_index<0>::type BaseIndex;
	typedef BaseIndex::value_type value_type;
	BaseIndex &baseIndex = getContainer().get<0>();

	BOOST_FOREACH(value_type v, baseIndex)
	{
		CProcessCSVRecordFile::writeCSVRow(output, v.get(), &CWriteableTraderConnect::field_desc_);
	}
	fclose(output);
	return 1;
}

int  CTraderConnectFactory::writeCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVWritePath");
	szFileName += getCsvFileName();
	return writeCSV(szFileName.c_str());
}

void CTraderConnectFactory::dump(char *filename)
{
	FILE *fp;
	fp = mfopen(filename, "w+b");
	dump(fp);
	if (fp != nullptr) 
		fclose(fp);
}

void CTraderConnectFactory::dump(FILE *fp)
{
	int index = 0; ///下标
	if (fp == nullptr) 
		fp = stdout;

	fprintf(fp, "CTraderConnectFactory={       Total Count=%d\n", getCount());
	BOOST_FOREACH(Idx_Cont_TraderConnect::value_type v, getContainer())
	{
		v->dump(fp, index++);
	}
	fprintf(fp, "}\n");
}

void CTraderConnectFactory::clearAll(void)
{
	getContainer().clear();
}

CTraderConnect* CTraderConnectFactory::addOrUpdate(CTraderConnect *pTraderConnect, 
	CWriteableTraderConnect *pNewTraderConnect, CTransaction *pTransaction, bool updateIndex)
{
	if (pTraderConnect == nullptr) {
		return insert(pNewTraderConnect, pTransaction);
	}
	else {
		update(pTraderConnect, pNewTraderConnect, pTransaction);
		return pTraderConnect;
	}
}

void CTraderConnectFactory::retrieve(CTraderConnect *pTraderConnect, 
	CWriteableTraderConnect *pTargetTraderConnect)
{
	forceCopy(pTargetTraderConnect, pTraderConnect, sizeof(CTraderConnect));
}

CTraderCertInfoFactory::CTraderCertInfoFactory(const std::string &TableName) :COutputTable(TableName)
{

}

CTraderCertInfoFactory::~CTraderCertInfoFactory(void)
{

}

int  CTraderCertInfoFactory::readCSV(const char *filename)
{
	FILE *input;
	input = mfopen(filename, "rt");
	if (input == nullptr)
		return 0;

	std::vector<int> headmap = CProcessCSVRecordFile::readCSVHead(input, 
		&CWriteableTraderCertInfo::field_desc_);
	if (headmap.empty())
	{
		// 没有取得csv的字段头
		return 0;
	}

	CWriteableTraderCertInfo thisTraderCertInfo;
	while (CProcessCSVRecordFile::readCSVRow(input, &thisTraderCertInfo, 
		headmap, &CWriteableTraderCertInfo::field_desc_))
	{
		insert(&thisTraderCertInfo, 0);
	}
	fclose(input);
	return 1;
}

int  CTraderCertInfoFactory::readCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVReadPath");
	szFileName += getCsvFileName();
	return readCSV(szFileName.c_str());
}

int  CTraderCertInfoFactory::writeCSV(const char *filename)
{
	FILE *output = mfopen(filename, "wt");
	if (output == nullptr)
		return 0;

	CProcessCSVRecordFile::writeCSVHead(output, &CWriteableTraderCertInfo::field_desc_);

	typedef Index_Container_Type::nth_index<0>::type BaseIndex;
	typedef BaseIndex::value_type value_type;
	BaseIndex &baseIndex = getContainer().get<0>();

	BOOST_FOREACH(value_type v, baseIndex)
	{
		CProcessCSVRecordFile::writeCSVRow(output, v.get(), &CWriteableTraderCertInfo::field_desc_);
	}
	fclose(output);
	return 1;
}

int  CTraderCertInfoFactory::writeCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVWritePath");
	szFileName += getCsvFileName();
	return writeCSV(szFileName.c_str());
}

void CTraderCertInfoFactory::dump(char *filename)
{
	FILE *fp;
	fp = mfopen(filename, "w+b");
	dump(fp);
	if (fp != nullptr) 
		fclose(fp);
}

void CTraderCertInfoFactory::dump(FILE *fp)
{
	int index = 0; ///下标
	if (fp == nullptr) 
		fp = stdout;

	fprintf(fp, "CTraderCertInfoFactory={       Total Count=%d\n", getCount());
	BOOST_FOREACH(Idx_Cont_TraderCertInfo::value_type v, getContainer())
	{
		v->dump(fp, index++);
	}
	fprintf(fp, "}\n");
}

void CTraderCertInfoFactory::clearAll(void)
{
	getContainer().clear();
}

CTraderCertInfo* CTraderCertInfoFactory::addOrUpdate(CTraderCertInfo *pTraderCertInfo, 
	CWriteableTraderCertInfo *pNewTraderCertInfo, CTransaction *pTransaction, bool updateIndex)
{
	if (pTraderCertInfo == nullptr) {
		return insert(pNewTraderCertInfo, pTransaction);
	}
	else {
		update(pTraderCertInfo, pNewTraderCertInfo, pTransaction);
		return pTraderCertInfo;
	}
}

void CTraderCertInfoFactory::retrieve(CTraderCertInfo *pTraderCertInfo, 
	CWriteableTraderCertInfo *pTargetTraderCertInfo)
{
	forceCopy(pTargetTraderCertInfo, pTraderCertInfo, sizeof(CTraderCertInfo));
}

CUserFactory::CUserFactory(const std::string &TableName) :COutputTable(TableName)
{

}

CUserFactory::~CUserFactory(void)
{

}

int  CUserFactory::readCSV(const char *filename)
{
	FILE *input;
	input = mfopen(filename, "rt");
	if (input == nullptr)
		return 0;

	std::vector<int> headmap = CProcessCSVRecordFile::readCSVHead(input, &CWriteableUser::field_desc_);
	if (headmap.empty())
	{
		// 没有取得csv的字段头
		return 0;
	}

	CWriteableUser thisUser;
	while (CProcessCSVRecordFile::readCSVRow(input, &thisUser, headmap, &CWriteableUser::field_desc_))
	{
		insert(&thisUser, 0);
	}
	fclose(input);
	return 1;
}

int  CUserFactory::readCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVReadPath");
	szFileName += getCsvFileName();
	return readCSV(szFileName.c_str());
}

int  CUserFactory::writeCSV(const char *filename)
{
	FILE *output = mfopen(filename, "wt");
	if (output == nullptr)
		return 0;

	CProcessCSVRecordFile::writeCSVHead(output, &CWriteableUser::field_desc_);

	typedef Index_Container_Type::nth_index<0>::type BaseIndex;
	typedef BaseIndex::value_type value_type;
	BaseIndex &baseIndex = getContainer().get<0>();

	BOOST_FOREACH(value_type v, baseIndex)
	{
		CProcessCSVRecordFile::writeCSVRow(output, v.get(), &CWriteableUser::field_desc_);
	}
	fclose(output);
	return 1;
}

int  CUserFactory::writeCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVWritePath");
	szFileName += getCsvFileName();
	return writeCSV(szFileName.c_str());
}

void CUserFactory::dump(char *filename)
{
	FILE *fp;
	fp = mfopen(filename, "w+b");
	dump(fp);
	if (fp != nullptr) 
		fclose(fp);
}

void CUserFactory::dump(FILE *fp)
{
	int index = 0; ///下标
	if (fp == nullptr) 
		fp = stdout;

	fprintf(fp, "CUserFactory={       Total Count=%d\n", getCount());
	BOOST_FOREACH(Idx_Cont_User::value_type v, getContainer())
	{
		v->dump(fp, index++);
	}
	fprintf(fp, "}\n");
}

void CUserFactory::clearAll(void)
{
	getContainer().clear();
}

CUser* CUserFactory::addOrUpdate(CUser *pUser, CWriteableUser *pNewUser, CTransaction *pTransaction, bool updateIndex)
{
	if (pUser == nullptr) {
		return insert(pNewUser, pTransaction);
	}
	else {
		update(pUser, pNewUser, pTransaction);
		return pUser;
	}
}

void CUserFactory::retrieve(CUser *pUser, CWriteableUser *pTargetUser)
{
	forceCopy(pTargetUser, pUser, sizeof(CUser));
}

CUserTraderFactory::CUserTraderFactory(const std::string &TableName) :COutputTable(TableName)
{

}

CUserTraderFactory::~CUserTraderFactory(void)
{

}

int  CUserTraderFactory::readCSV(const char *filename)
{
	FILE *input;
	input = mfopen(filename, "rt");
	if (input == NULL) { return 0; }

	std::vector<int> headmap = CProcessCSVRecordFile::readCSVHead(input, &CWriteableUserTrader::field_desc_);
	if (headmap.empty())
	{
		// 没有取得csv的字段头
		return 0;
	}

	CWriteableUserTrader thisUserTrader;
	while (CProcessCSVRecordFile::readCSVRow(input, &thisUserTrader, headmap, &CWriteableUserTrader::field_desc_))
	{
		insert(&thisUserTrader, 0);
	}
	fclose(input);
	return 1;
}

int  CUserTraderFactory::readCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVReadPath");
	szFileName += getCsvFileName();
	return readCSV(szFileName.c_str());
}

int  CUserTraderFactory::writeCSV(const char *filename)
{
	FILE *output = mfopen(filename, "wt");
	if (output == nullptr)
		return 0;

	CProcessCSVRecordFile::writeCSVHead(output, &CWriteableUserTrader::field_desc_);

	typedef Index_Container_Type::nth_index<0>::type BaseIndex;
	typedef BaseIndex::value_type value_type;
	BaseIndex &baseIndex = getContainer().get<0>();

	BOOST_FOREACH(value_type v, baseIndex)
	{
		CProcessCSVRecordFile::writeCSVRow(output, v.get(), &CWriteableUserTrader::field_desc_);
	}
	fclose(output);
	return 1;
}

int  CUserTraderFactory::writeCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVWritePath");
	szFileName += getCsvFileName();
	return writeCSV(szFileName.c_str());
}

void CUserTraderFactory::dump(char *filename)
{
	FILE *fp;
	fp = mfopen(filename, "w+b");
	dump(fp);
	if (fp != nullptr)
		fclose(fp);
}

void CUserTraderFactory::dump(FILE *fp)
{
	int index = 0; ///下标
	if (fp == nullptr) 
		fp = stdout;

	fprintf(fp, "CUserTraderFactory={       Total Count=%d\n", getCount());
	BOOST_FOREACH(Idx_Cont_UserTrader::value_type v, getContainer())
	{
		v->dump(fp, index++);
	}
	fprintf(fp, "}\n");
}

void CUserTraderFactory::clearAll(void)
{
	getContainer().clear();
}

CUserTrader* CUserTraderFactory::addOrUpdate(CUserTrader *pUserTrader, CWriteableUserTrader *pNewUserTrader, CTransaction *pTransaction, bool updateIndex)
{
	if (pUserTrader == nullptr) {
		return insert(pNewUserTrader, pTransaction);
	}
	else {
		update(pUserTrader, pNewUserTrader, pTransaction);
		return pUserTrader;
	}
}

void CUserTraderFactory::retrieve(CUserTrader *pUserTrader, CWriteableUserTrader *pTargetUserTrader)
{
	forceCopy(pTargetUserTrader, pUserTrader, sizeof(CUserTrader));
}

CUserFunctionRightFactory::CUserFunctionRightFactory(const std::string &TableName) :COutputTable(TableName)
{

}

CUserFunctionRightFactory::~CUserFunctionRightFactory(void)
{

}

int  CUserFunctionRightFactory::readCSV(const char *filename)
{
	FILE *input;
	input = mfopen(filename, "rt");
	if (input == nullptr)
		return 0;

	std::vector<int> headmap = CProcessCSVRecordFile::readCSVHead(input, &CWriteableUserFunctionRight::field_desc_);
	if (headmap.empty())
	{
		// 没有取得csv的字段头
		return 0;
	}

	CWriteableUserFunctionRight thisUserFunctionRight;
	while (CProcessCSVRecordFile::readCSVRow(input, &thisUserFunctionRight, headmap, &CWriteableUserFunctionRight::field_desc_))
	{
		insert(&thisUserFunctionRight, 0);
	}
	fclose(input);
	return 1;
}

int  CUserFunctionRightFactory::readCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVReadPath");
	szFileName += getCsvFileName();
	return readCSV(szFileName.c_str());
}

int  CUserFunctionRightFactory::writeCSV(const char *filename)
{
	FILE *output = mfopen(filename, "wt");
	if (output == nullptr)
		return 0;

	CProcessCSVRecordFile::writeCSVHead(output, &CWriteableUserFunctionRight::field_desc_);

	typedef Index_Container_Type::nth_index<0>::type BaseIndex;
	typedef BaseIndex::value_type value_type;
	BaseIndex &baseIndex = getContainer().get<0>();

	BOOST_FOREACH(value_type v, baseIndex)
	{
		CProcessCSVRecordFile::writeCSVRow(output, v.get(), &CWriteableUserFunctionRight::field_desc_);
	}
	fclose(output);
	return 1;
}

int  CUserFunctionRightFactory::writeCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVWritePath");
	szFileName += getCsvFileName();
	return writeCSV(szFileName.c_str());
}

void CUserFunctionRightFactory::dump(char *filename)
{
	FILE *fp;
	fp = mfopen(filename, "w+b");
	dump(fp);
	if (fp != nullptr) 
		fclose(fp);
}

void CUserFunctionRightFactory::dump(FILE *fp)
{
	int index = 0; ///下标
	if (fp == nullptr) 
		fp = stdout;

	fprintf(fp, "CUserFunctionRightFactory={       Total Count=%d\n", getCount());
	BOOST_FOREACH(Idx_Cont_UserFunctionRight::value_type v, getContainer())
	{
		v->dump(fp, index++);
	}
	fprintf(fp, "}\n");
}

void CUserFunctionRightFactory::clearAll(void)
{
	getContainer().clear();
}

CUserFunctionRight* CUserFunctionRightFactory::addOrUpdate(CUserFunctionRight *pUserFunctionRight, CWriteableUserFunctionRight *pNewUserFunctionRight, CTransaction *pTransaction, bool updateIndex)
{
	if (pUserFunctionRight == nullptr) {
		return insert(pNewUserFunctionRight, pTransaction);
	}
	else {
		update(pUserFunctionRight, pNewUserFunctionRight, pTransaction);
		return pUserFunctionRight;
	}
}

void CUserFunctionRightFactory::retrieve(CUserFunctionRight *pUserFunctionRight, CWriteableUserFunctionRight *pTargetUserFunctionRight)
{
	forceCopy(pTargetUserFunctionRight, pUserFunctionRight, sizeof(CUserFunctionRight));
}

CSysInfoFactory::CSysInfoFactory(const std::string &TableName) :COutputTable(TableName)
{

}

CSysInfoFactory::~CSysInfoFactory(void)
{

}

int  CSysInfoFactory::readCSV(const char *filename)
{
	FILE *input;
	input = mfopen(filename, "rt");
	if (input == nullptr)
		return 0;

	std::vector<int> headmap = CProcessCSVRecordFile::readCSVHead(input, &CWriteableSysInfo::field_desc_);
	if (headmap.empty())
	{
		// 没有取得csv的字段头
		return 0;
	}

	CWriteableSysInfo thisSysInfo;
	while (CProcessCSVRecordFile::readCSVRow(input, &thisSysInfo, headmap, &CWriteableSysInfo::field_desc_))
	{
		insert(&thisSysInfo, 0);
	}
	fclose(input);
	return 1;
}

int  CSysInfoFactory::readCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVReadPath");
	szFileName += getCsvFileName();
	return readCSV(szFileName.c_str());
}

int  CSysInfoFactory::writeCSV(const char *filename)
{
	FILE *output = mfopen(filename, "wt");
	if (output == nullptr)
		return 0;

	CProcessCSVRecordFile::writeCSVHead(output, &CWriteableSysInfo::field_desc_);

	typedef Index_Container_Type::nth_index<0>::type BaseIndex;
	typedef BaseIndex::value_type value_type;
	BaseIndex &baseIndex = getContainer().get<0>();

	BOOST_FOREACH(value_type v, baseIndex)
	{
		CProcessCSVRecordFile::writeCSVRow(output, v.get(), &CWriteableSysInfo::field_desc_);
	}
	fclose(output);
	return 1;
}

int  CSysInfoFactory::writeCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVWritePath");
	szFileName += getCsvFileName();
	return writeCSV(szFileName.c_str());
}

void CSysInfoFactory::dump(char *filename)
{
	FILE *fp;
	fp = mfopen(filename, "w+b");
	dump(fp);
	if (fp != nullptr) 
		fclose(fp);
}

void CSysInfoFactory::dump(FILE *fp)
{
	int index = 0; ///下标
	if (fp == nullptr) 
		fp = stdout;

	fprintf(fp, "CSysInfoFactory={       Total Count=%d\n", getCount());
	BOOST_FOREACH(Idx_Cont_SysInfo::value_type v, getContainer())
	{
		v->dump(fp, index++);
	}
	fprintf(fp, "}\n");
}

void CSysInfoFactory::clearAll(void)
{
	getContainer().clear();
}

CSysInfo* CSysInfoFactory::addOrUpdate(CSysInfo *pSysInfo, CWriteableSysInfo *pNewSysInfo, CTransaction *pTransaction, bool updateIndex)
{
	if (pSysInfo == nullptr) {
		return insert(pNewSysInfo, pTransaction);
	}
	else {
		update(pSysInfo, pNewSysInfo, pTransaction);
		return pSysInfo;
	}
}

void CSysInfoFactory::retrieve(CSysInfo *pSysInfo, CWriteableSysInfo *pTargetSysInfo)
{
	forceCopy(pTargetSysInfo, pSysInfo, sizeof(CSysInfo));
}

CUserSessionFactory::CUserSessionFactory(const std::string &TableName) :COutputTable(TableName)
{

}

CUserSessionFactory::~CUserSessionFactory(void)
{

}

int  CUserSessionFactory::readCSV(const char *filename)
{
	FILE *input;
	input = mfopen(filename, "rt");
	if (input == nullptr)
		return 0;

	std::vector<int> headmap = CProcessCSVRecordFile::readCSVHead(input, &CWriteableUserSession::field_desc_);
	if (headmap.empty())
	{
		// 没有取得csv的字段头
		return 0;
	}

	CWriteableUserSession thisUserSession;
	while (CProcessCSVRecordFile::readCSVRow(input, &thisUserSession, headmap, &CWriteableUserSession::field_desc_))
	{
		insert(&thisUserSession, 0);
	}
	fclose(input);
	return 1;
}

int  CUserSessionFactory::readCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVReadPath");
	szFileName += getCsvFileName();
	return readCSV(szFileName.c_str());
}

int  CUserSessionFactory::writeCSV(const char *filename)
{
	FILE *output = mfopen(filename, "wt");
	if (output == NULL) { return 0; }

	CProcessCSVRecordFile::writeCSVHead(output, &CWriteableUserSession::field_desc_);

	typedef Index_Container_Type::nth_index<0>::type BaseIndex;
	typedef BaseIndex::value_type value_type;
	BaseIndex &baseIndex = getContainer().get<0>();

	BOOST_FOREACH(value_type v, baseIndex)
	{
		CProcessCSVRecordFile::writeCSVRow(output, v.get(), &CWriteableUserSession::field_desc_);
	}
	fclose(output);
	return 1;
}

int  CUserSessionFactory::writeCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVWritePath");
	szFileName += getCsvFileName();
	return writeCSV(szFileName.c_str());
}

void CUserSessionFactory::dump(char *filename)
{
	FILE *fp;
	fp = mfopen(filename, "w+b");
	dump(fp);
	if (fp != nullptr) 
		fclose(fp);
}

void CUserSessionFactory::dump(FILE *fp)
{
	int index = 0; ///下标
	if (fp == nullptr) 
		fp = stdout;

	fprintf(fp, "CUserSessionFactory={       Total Count=%d\n", getCount());
	BOOST_FOREACH(Idx_Cont_UserSession::value_type v, getContainer())
	{
		v->dump(fp, index++);
	}
	fprintf(fp, "}\n");
}

void CUserSessionFactory::clearAll(void)
{
	getContainer().clear();
}

CUserSession* CUserSessionFactory::addOrUpdate(CUserSession *pUserSession, CWriteableUserSession *pNewUserSession, CTransaction *pTransaction, bool updateIndex)
{
	if (pUserSession == nullptr) {
		return insert(pNewUserSession, pTransaction);
	}
	else {
		update(pUserSession, pNewUserSession, pTransaction);
		return pUserSession;
	}
}

void CUserSessionFactory::retrieve(CUserSession *pUserSession, CWriteableUserSession *pTargetUserSession)
{
	forceCopy(pTargetUserSession, pUserSession, sizeof(CUserSession));
}

CMDSessionFactory::CMDSessionFactory(const std::string &TableName) :COutputTable(TableName)
{

}

CMDSessionFactory::~CMDSessionFactory(void)
{

}

int  CMDSessionFactory::readCSV(const char *filename)
{
	FILE *input;
	input = mfopen(filename, "rt");
	if (input == nullptr)
		return 0;

	std::vector<int> headmap = CProcessCSVRecordFile::readCSVHead(input, &CWriteableMDSession::field_desc_);
	if (headmap.empty())
	{
		// 没有取得csv的字段头
		return 0;
	}

	CWriteableMDSession thisMDSession;
	while (CProcessCSVRecordFile::readCSVRow(input, &thisMDSession, headmap, &CWriteableMDSession::field_desc_))
	{
		insert(&thisMDSession, 0);
	}
	fclose(input);
	return 1;
}

int  CMDSessionFactory::readCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVReadPath");
	szFileName += getCsvFileName();
	return readCSV(szFileName.c_str());
}

int  CMDSessionFactory::writeCSV(const char *filename)
{
	FILE *output = mfopen(filename, "wt");
	if (output == NULL) { return 0; }

	CProcessCSVRecordFile::writeCSVHead(output, &CWriteableMDSession::field_desc_);

	typedef Index_Container_Type::nth_index<0>::type BaseIndex;
	typedef BaseIndex::value_type value_type;
	BaseIndex &baseIndex = getContainer().get<0>();

	BOOST_FOREACH(value_type v, baseIndex)
	{
		CProcessCSVRecordFile::writeCSVRow(output, v.get(), &CWriteableMDSession::field_desc_);
	}
	fclose(output);
	return 1;
}

int  CMDSessionFactory::writeCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVWritePath");
	szFileName += getCsvFileName();
	return writeCSV(szFileName.c_str());
}

void CMDSessionFactory::dump(char *filename)
{
	FILE *fp;
	fp = mfopen(filename, "w+b");
	dump(fp);
	if (fp != NULL) fclose(fp);
}

void CMDSessionFactory::dump(FILE *fp)
{
	int index = 0; ///下标
	if (fp == nullptr) 
		fp = stdout;

	fprintf(fp, "CMDSessionFactory={       Total Count=%d\n", getCount());
	BOOST_FOREACH(Idx_Cont_MDSession::value_type v, getContainer())
	{
		v->dump(fp, index++);
	}
	fprintf(fp, "}\n");
}

void CMDSessionFactory::clearAll(void)
{
	getContainer().clear();
}

CMDSession* CMDSessionFactory::addOrUpdate(CMDSession *pMDSession, CWriteableMDSession *pNewMDSession, CTransaction *pTransaction, bool updateIndex)
{
	if (pMDSession == nullptr)
	{
		return insert(pNewMDSession, pTransaction);
	}
	else
	{
		update(pMDSession, pNewMDSession, pTransaction);
		return pMDSession;
	}
}

void CMDSessionFactory::retrieve(CMDSession *pMDSession, CWriteableMDSession *pTargetMDSession)
{
	forceCopy(pTargetMDSession, pMDSession, sizeof(CMDSession));
}

CMaxLocalIDFactory::CMaxLocalIDFactory(const std::string &TableName) :COutputTable(TableName)
{

}

CMaxLocalIDFactory::~CMaxLocalIDFactory(void)
{

}

int  CMaxLocalIDFactory::readCSV(const char *filename)
{
	FILE *input;
	input = mfopen(filename, "rt");
	if (input == nullptr)
		return 0;

	std::vector<int> headmap = CProcessCSVRecordFile::readCSVHead(input, &CWriteableMaxLocalID::field_desc_);
	if (headmap.empty())
	{
		// 没有取得csv的字段头
		return 0;
	}

	CWriteableMaxLocalID thisMaxLocalID;
	while (CProcessCSVRecordFile::readCSVRow(input, &thisMaxLocalID, headmap, &CWriteableMaxLocalID::field_desc_))
	{
		insert(&thisMaxLocalID, 0);
	}
	fclose(input);
	return 1;
}

int  CMaxLocalIDFactory::readCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVReadPath");
	szFileName += getCsvFileName();
	return readCSV(szFileName.c_str());
}

int  CMaxLocalIDFactory::writeCSV(const char *filename)
{
	FILE *output = mfopen(filename, "wt");
	if (output == nullptr)
		return 0;

	CProcessCSVRecordFile::writeCSVHead(output, &CWriteableMaxLocalID::field_desc_);

	typedef Index_Container_Type::nth_index<0>::type BaseIndex;
	typedef BaseIndex::value_type value_type;
	BaseIndex &baseIndex = getContainer().get<0>();

	BOOST_FOREACH(value_type v, baseIndex)
	{
		CProcessCSVRecordFile::writeCSVRow(output, v.get(), &CWriteableMaxLocalID::field_desc_);
	}
	fclose(output);
	return 1;
}

int  CMaxLocalIDFactory::writeCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVWritePath");
	szFileName += getCsvFileName();
	return writeCSV(szFileName.c_str());
}

void CMaxLocalIDFactory::dump(char *filename)
{
	FILE *fp;
	fp = mfopen(filename, "w+b");
	dump(fp);
	if (fp != nullptr)
		fclose(fp);
}

void CMaxLocalIDFactory::dump(FILE *fp)
{
	int index = 0; ///下标
	if (fp == nullptr) 
		fp = stdout;

	fprintf(fp, "CMaxLocalIDFactory={       Total Count=%d\n", getCount());
	BOOST_FOREACH(Idx_Cont_MaxLocalID::value_type v, getContainer())
	{
		v->dump(fp, index++);
	}
	fprintf(fp, "}\n");
}

void CMaxLocalIDFactory::clearAll(void)
{
	getContainer().clear();
}

CMaxLocalID* CMaxLocalIDFactory::addOrUpdate(CMaxLocalID *pMaxLocalID, CWriteableMaxLocalID *pNewMaxLocalID, CTransaction *pTransaction, bool updateIndex)
{
	if (pMaxLocalID == nullptr) 
	{
		return insert(pNewMaxLocalID, pTransaction);
	}
	else 
	{
		update(pMaxLocalID, pNewMaxLocalID, pTransaction);
		return pMaxLocalID;
	}
}

void CMaxLocalIDFactory::retrieve(CMaxLocalID *pMaxLocalID, CWriteableMaxLocalID *pTargetMaxLocalID)
{
	forceCopy(pTargetMaxLocalID, pMaxLocalID, sizeof(CMaxLocalID));
}

CUserSubMarketDataFactory::CUserSubMarketDataFactory(const std::string &TableName) :COutputTable(TableName)
{

}

CUserSubMarketDataFactory::~CUserSubMarketDataFactory(void)
{

}

int  CUserSubMarketDataFactory::readCSV(const char *filename)
{
	FILE *input;
	input = mfopen(filename, "rt");
	if (input == nullptr)
		return 0;

	std::vector<int> headmap = CProcessCSVRecordFile::readCSVHead(input, &CWriteableUserSubMarketData::field_desc_);
	if (headmap.empty())
	{
		// 没有取得csv的字段头
		return 0;
	}

	CWriteableUserSubMarketData thisUserSubMarketData;
	while (CProcessCSVRecordFile::readCSVRow(input, &thisUserSubMarketData, headmap, &CWriteableUserSubMarketData::field_desc_))
	{
		insert(&thisUserSubMarketData, 0);
	}
	fclose(input);
	return 1;
}

int  CUserSubMarketDataFactory::readCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVReadPath");
	szFileName += getCsvFileName();
	return readCSV(szFileName.c_str());
}

int  CUserSubMarketDataFactory::writeCSV(const char *filename)
{
	FILE *output = mfopen(filename, "wt");
	if (output == nullptr)
		return 0;

	CProcessCSVRecordFile::writeCSVHead(output, &CWriteableUserSubMarketData::field_desc_);

	typedef Index_Container_Type::nth_index<0>::type BaseIndex;
	typedef BaseIndex::value_type value_type;
	BaseIndex &baseIndex = getContainer().get<0>();

	BOOST_FOREACH(value_type v, baseIndex)
	{
		CProcessCSVRecordFile::writeCSVRow(output, v.get(), &CWriteableUserSubMarketData::field_desc_);
	}
	fclose(output);
	return 1;
}

int  CUserSubMarketDataFactory::writeCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVWritePath");
	szFileName += getCsvFileName();
	return writeCSV(szFileName.c_str());
}

void CUserSubMarketDataFactory::dump(char *filename)
{
	FILE *fp;
	fp = mfopen(filename, "w+b");
	dump(fp);
	if (fp != nullptr) 
		fclose(fp);
}

void CUserSubMarketDataFactory::dump(FILE *fp)
{
	int index = 0; ///下标
	if (fp == nullptr) 
		fp = stdout;

	fprintf(fp, "CUserSubMarketDataFactory={       Total Count=%d\n", getCount());
	BOOST_FOREACH(Idx_Cont_UserSubMarketData::value_type v, getContainer())
	{
		v->dump(fp, index++);
	}
	fprintf(fp, "}\n");
}

void CUserSubMarketDataFactory::clearAll(void)
{
	getContainer().clear();
}

CUserSubMarketData* CUserSubMarketDataFactory::addOrUpdate(CUserSubMarketData *pUserSubMarketData, 
	CWriteableUserSubMarketData *pNewUserSubMarketData, CTransaction *pTransaction, bool updateIndex)
{
	if (pUserSubMarketData == nullptr) {
		return insert(pNewUserSubMarketData, pTransaction);
	}
	else {
		update(pUserSubMarketData, pNewUserSubMarketData, pTransaction);
		return pUserSubMarketData;
	}
}

void CUserSubMarketDataFactory::retrieve(CUserSubMarketData *pUserSubMarketData, 
	CWriteableUserSubMarketData *pTargetUserSubMarketData)
{
	forceCopy(pTargetUserSubMarketData, pUserSubMarketData, sizeof(CUserSubMarketData));
}

CDepthMarketDataFactory::CDepthMarketDataFactory(const std::string &TableName) :COutputTable(TableName)
{

}

CDepthMarketDataFactory::~CDepthMarketDataFactory(void)
{

}

int  CDepthMarketDataFactory::readCSV(const char *filename)
{
	FILE *input;
	input = mfopen(filename, "rt");
	if (input == nullptr)
		return 0;

	std::vector<int> headmap = CProcessCSVRecordFile::readCSVHead(input, &CWriteableDepthMarketData::field_desc_);
	if (headmap.empty())
	{
		// 没有取得csv的字段头
		return 0;
	}

	CWriteableDepthMarketData thisDepthMarketData;
	while (CProcessCSVRecordFile::readCSVRow(input, &thisDepthMarketData, headmap, &CWriteableDepthMarketData::field_desc_))
	{
		insert(&thisDepthMarketData, 0);
	}
	fclose(input);
	return 1;
}

int  CDepthMarketDataFactory::readCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVReadPath");
	szFileName += getCsvFileName();
	return readCSV(szFileName.c_str());
}

int  CDepthMarketDataFactory::writeCSV(const char *filename)
{
	FILE *output = mfopen(filename, "wt");
	if (output == nullptr)
		return 0;

	CProcessCSVRecordFile::writeCSVHead(output, &CWriteableDepthMarketData::field_desc_);

	typedef Index_Container_Type::nth_index<0>::type BaseIndex;
	typedef BaseIndex::value_type value_type;
	BaseIndex &baseIndex = getContainer().get<0>();

	BOOST_FOREACH(value_type v, baseIndex)
	{
		CProcessCSVRecordFile::writeCSVRow(output, v.get(), &CWriteableDepthMarketData::field_desc_);
	}
	fclose(output);
	return 1;
}

int  CDepthMarketDataFactory::writeCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVWritePath");
	szFileName += getCsvFileName();
	return writeCSV(szFileName.c_str());
}

void CDepthMarketDataFactory::dump(char *filename)
{
	FILE *fp;
	fp = mfopen(filename, "w+b");
	dump(fp);
	if (fp != nullptr) 
		fclose(fp);
}

void CDepthMarketDataFactory::dump(FILE *fp)
{
	int index = 0; ///下标
	if (fp == nullptr) 
		fp = stdout;

	fprintf(fp, "CDepthMarketDataFactory={       Total Count=%d\n", getCount());
	BOOST_FOREACH(Idx_Cont_DepthMarketData::value_type v, getContainer())
	{
		v->dump(fp, index++);
	}
	fprintf(fp, "}\n");
}

void CDepthMarketDataFactory::clearAll(void)
{
	getContainer().clear();
}

CDepthMarketData* CDepthMarketDataFactory::addOrUpdate(CDepthMarketData *pDepthMarketData, CWriteableDepthMarketData *pNewDepthMarketData, CTransaction *pTransaction, bool updateIndex)
{
	if (pDepthMarketData == nullptr) {
		return insert(pNewDepthMarketData, pTransaction);
	}
	else {
		update(pDepthMarketData, pNewDepthMarketData, pTransaction);
		return pDepthMarketData;
	}
}

void CDepthMarketDataFactory::retrieve(CDepthMarketData *pDepthMarketData, CWriteableDepthMarketData *pTargetDepthMarketData)
{
	forceCopy(pTargetDepthMarketData, pDepthMarketData, sizeof(CDepthMarketData));
}

CCommodityFactory::CCommodityFactory(const std::string &TableName) :COutputTable(TableName)
{

}

CCommodityFactory::~CCommodityFactory(void)
{

}

int  CCommodityFactory::readCSV(const char *filename)
{
	FILE *input;
	input = mfopen(filename, "rt");
	if (input == nullptr)
		return 0;

	std::vector<int> headmap = CProcessCSVRecordFile::readCSVHead(input, &CWriteableCommodity::field_desc_);
	if (headmap.empty())
	{
		// 没有取得csv的字段头
		return 0;
	}

	CWriteableCommodity thisCommodity;
	while (CProcessCSVRecordFile::readCSVRow(input, &thisCommodity, headmap, &CWriteableCommodity::field_desc_))
	{
		insert(&thisCommodity, 0);
	}
	fclose(input);
	return 1;
}

int  CCommodityFactory::readCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVReadPath");
	szFileName += getCsvFileName();
	return readCSV(szFileName.c_str());
}

int  CCommodityFactory::writeCSV(const char *filename)
{
	FILE *output = mfopen(filename, "wt");
	if (output == nullptr)
		return 0;

	CProcessCSVRecordFile::writeCSVHead(output, &CWriteableCommodity::field_desc_);

	typedef Index_Container_Type::nth_index<0>::type BaseIndex;
	typedef BaseIndex::value_type value_type;
	BaseIndex &baseIndex = getContainer().get<0>();

	BOOST_FOREACH(value_type v, baseIndex)
	{
		CProcessCSVRecordFile::writeCSVRow(output, v.get(), &CWriteableCommodity::field_desc_);
	}
	fclose(output);
	return 1;
}

int  CCommodityFactory::writeCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVWritePath");
	szFileName += getCsvFileName();
	return writeCSV(szFileName.c_str());
}

void CCommodityFactory::dump(char *filename)
{
	FILE *fp;
	fp = mfopen(filename, "w+b");
	dump(fp);
	if (fp != nullptr) 
		fclose(fp);
}

void CCommodityFactory::dump(FILE *fp)
{
	int index = 0; ///下标
	if (fp == nullptr) 
		fp = stdout;

	fprintf(fp, "CCommodityFactory={       Total Count=%d\n", getCount());
	BOOST_FOREACH(Idx_Cont_Commodity::value_type v, getContainer())
	{
		v->dump(fp, index++);
	}
	fprintf(fp, "}\n");
}

void CCommodityFactory::clearAll(void)
{
	getContainer().clear();
}

CCommodity* CCommodityFactory::addOrUpdate(CCommodity *pCommodity, CWriteableCommodity *pNewCommodity, CTransaction *pTransaction, bool updateIndex)
{
	if (pCommodity == nullptr) {
		return insert(pNewCommodity, pTransaction);
	}
	else {
		update(pCommodity, pNewCommodity, pTransaction);
		return pCommodity;
	}
}

void CCommodityFactory::retrieve(CCommodity *pCommodity, CWriteableCommodity *pTargetCommodity)
{
	forceCopy(pTargetCommodity, pCommodity, sizeof(CCommodity));
}

CInstrumentFactory::CInstrumentFactory(const std::string &TableName) :COutputTable(TableName)
{

}

CInstrumentFactory::~CInstrumentFactory(void)
{

}

int  CInstrumentFactory::readCSV(const char *filename)
{
	FILE *input;
	input = mfopen(filename, "rt");
	if (input == NULL) { return 0; }

	std::vector<int> headmap = CProcessCSVRecordFile::readCSVHead(input, &CWriteableInstrument::field_desc_);
	if (headmap.empty())
	{
		// 没有取得csv的字段头
		return 0;
	}

	CWriteableInstrument thisInstrument;
	while (CProcessCSVRecordFile::readCSVRow(input, &thisInstrument, headmap, &CWriteableInstrument::field_desc_))
	{
		insert(&thisInstrument, 0);
	}
	fclose(input);
	return 1;
}

int  CInstrumentFactory::readCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVReadPath");
	szFileName += getCsvFileName();
	return readCSV(szFileName.c_str());
}

int  CInstrumentFactory::writeCSV(const char *filename)
{
	FILE *output = mfopen(filename, "wt");
	if (output == nullptr)
		return 0;

	CProcessCSVRecordFile::writeCSVHead(output, &CWriteableInstrument::field_desc_);

	typedef Index_Container_Type::nth_index<0>::type BaseIndex;
	typedef BaseIndex::value_type value_type;
	BaseIndex &baseIndex = getContainer().get<0>();

	BOOST_FOREACH(value_type v, baseIndex)
	{
		CProcessCSVRecordFile::writeCSVRow(output, v.get(), &CWriteableInstrument::field_desc_);
	}
	fclose(output);
	return 1;
}

int  CInstrumentFactory::writeCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVWritePath");
	szFileName += getCsvFileName();
	return writeCSV(szFileName.c_str());
}

void CInstrumentFactory::dump(char *filename)
{
	FILE *fp;
	fp = mfopen(filename, "w+b");
	dump(fp);
	if (fp != nullptr) 
		fclose(fp);
}

void CInstrumentFactory::dump(FILE *fp)
{
	int index = 0; ///下标
	if (fp == nullptr)
		fp = stdout;

	fprintf(fp, "CInstrumentFactory={       Total Count=%d\n", getCount());
	BOOST_FOREACH(Idx_Cont_Instrument::value_type v, getContainer())
	{
		v->dump(fp, index++);
	}
	fprintf(fp, "}\n");
}

void CInstrumentFactory::clearAll(void)
{
	getContainer().clear();
}

CInstrument* CInstrumentFactory::addOrUpdate(CInstrument *pInstrument, CWriteableInstrument *pNewInstrument, CTransaction *pTransaction, bool updateIndex)
{
	if (pInstrument == nullptr) {
		return insert(pNewInstrument, pTransaction);
	}
	else {
		update(pInstrument, pNewInstrument, pTransaction);
		return pInstrument;
	}
}

void CInstrumentFactory::retrieve(CInstrument *pInstrument, CWriteableInstrument *pTargetInstrument)
{
	forceCopy(pTargetInstrument, pInstrument, sizeof(CInstrument));
}

COrderActionFactory::COrderActionFactory(const std::string &TableName) :COutputTable(TableName)
{

}

COrderActionFactory::~COrderActionFactory(void)
{

}

int  COrderActionFactory::readCSV(const char *filename)
{
	FILE *input;
	input = mfopen(filename, "rt");
	if (input == nullptr)
		return 0;

	std::vector<int> headmap = CProcessCSVRecordFile::readCSVHead(input, &CWriteableOrderAction::field_desc_);
	if (headmap.empty())
	{
		// 没有取得csv的字段头
		return 0;
	}

	CWriteableOrderAction thisOrderAction;
	while (CProcessCSVRecordFile::readCSVRow(input, &thisOrderAction, headmap, &CWriteableOrderAction::field_desc_))
	{
		insert(&thisOrderAction, 0);
	}
	fclose(input);
	return 1;
}

int  COrderActionFactory::readCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVReadPath");
	szFileName += getCsvFileName();
	return readCSV(szFileName.c_str());
}

int  COrderActionFactory::writeCSV(const char *filename)
{
	FILE *output = mfopen(filename, "wt");
	if (output == nullptr)
		return 0;

	CProcessCSVRecordFile::writeCSVHead(output, &CWriteableOrderAction::field_desc_);

	typedef Index_Container_Type::nth_index<0>::type BaseIndex;
	typedef BaseIndex::value_type value_type;
	BaseIndex &baseIndex = getContainer().get<0>();

	BOOST_FOREACH(value_type v, baseIndex)
	{
		CProcessCSVRecordFile::writeCSVRow(output, v.get(), &CWriteableOrderAction::field_desc_);
	}
	fclose(output);
	return 1;
}

int  COrderActionFactory::writeCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVWritePath");
	szFileName += getCsvFileName();
	return writeCSV(szFileName.c_str());
}

void COrderActionFactory::dump(char *filename)
{
	FILE *fp;
	fp = mfopen(filename, "w+b");
	dump(fp);
	if (fp != nullptr) 
		fclose(fp);
}

void COrderActionFactory::dump(FILE *fp)
{
	int index = 0; ///下标
	if (fp == nullptr) 
		fp = stdout;

	fprintf(fp, "COrderActionFactory={       Total Count=%d\n", getCount());
	BOOST_FOREACH(Idx_Cont_OrderAction::value_type v, getContainer())
	{
		v->dump(fp, index++);
	}
	fprintf(fp, "}\n");
}

void COrderActionFactory::clearAll(void)
{
	getContainer().clear();
}

COrderAction* COrderActionFactory::addOrUpdate(COrderAction *pOrderAction, 
	CWriteableOrderAction *pNewOrderAction, CTransaction *pTransaction, bool updateIndex)
{
	if (pOrderAction == nullptr) {
		return insert(pNewOrderAction, pTransaction);
	}
	else {
		update(pOrderAction, pNewOrderAction, pTransaction);
		return pOrderAction;
	}
}

void COrderActionFactory::retrieve(COrderAction *pOrderAction, 
	CWriteableOrderAction *pTargetOrderAction)
{
	forceCopy(pTargetOrderAction, pOrderAction, sizeof(COrderAction));
}

CExchOrderActionFactory::CExchOrderActionFactory(const std::string &TableName) :COutputTable(TableName)
{

}

CExchOrderActionFactory::~CExchOrderActionFactory(void)
{

}

int  CExchOrderActionFactory::readCSV(const char *filename)
{
	FILE *input;
	input = mfopen(filename, "rt");
	if (input == nullptr)
		return 0;

	std::vector<int> headmap = CProcessCSVRecordFile::readCSVHead(input, &CWriteableExchOrderAction::field_desc_);
	if (headmap.empty())
	{
		// 没有取得csv的字段头
		return 0;
	}

	CWriteableExchOrderAction thisExchOrderAction;
	while (CProcessCSVRecordFile::readCSVRow(input, &thisExchOrderAction, headmap, &CWriteableExchOrderAction::field_desc_))
	{
		insert(&thisExchOrderAction, 0);
	}
	fclose(input);
	return 1;
}

int  CExchOrderActionFactory::readCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVReadPath");
	szFileName += getCsvFileName();
	return readCSV(szFileName.c_str());
}

int  CExchOrderActionFactory::writeCSV(const char *filename)
{
	FILE *output = mfopen(filename, "wt");
	if (output == nullptr)
		return 0;

	CProcessCSVRecordFile::writeCSVHead(output, &CWriteableExchOrderAction::field_desc_);

	typedef Index_Container_Type::nth_index<0>::type BaseIndex;
	typedef BaseIndex::value_type value_type;
	BaseIndex &baseIndex = getContainer().get<0>();

	BOOST_FOREACH(value_type v, baseIndex)
	{
		CProcessCSVRecordFile::writeCSVRow(output, v.get(), &CWriteableExchOrderAction::field_desc_);
	}
	fclose(output);
	return 1;
}

int  CExchOrderActionFactory::writeCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVWritePath");
	szFileName += getCsvFileName();
	return writeCSV(szFileName.c_str());
}

void CExchOrderActionFactory::dump(char *filename)
{
	FILE *fp;
	fp = mfopen(filename, "w+b");
	dump(fp);
	if (fp != nullptr)
		fclose(fp);
}

void CExchOrderActionFactory::dump(FILE *fp)
{
	int index = 0; ///下标
	if (fp == nullptr) 
		fp = stdout;

	fprintf(fp, "CExchOrderActionFactory={       Total Count=%d\n", getCount());
	BOOST_FOREACH(Idx_Cont_ExchOrderAction::value_type v, getContainer())
	{
		v->dump(fp, index++);
	}
	fprintf(fp, "}\n");
}

void CExchOrderActionFactory::clearAll(void)
{
	getContainer().clear();
}

CExchOrderAction* CExchOrderActionFactory::addOrUpdate(CExchOrderAction *pExchOrderAction,
	CWriteableExchOrderAction *pNewExchOrderAction, 
	CTransaction *pTransaction, bool updateIndex)
{
	if (pExchOrderAction == nullptr) {
		return insert(pNewExchOrderAction, pTransaction);
	}
	else {
		update(pExchOrderAction, pNewExchOrderAction, pTransaction);
		return pExchOrderAction;
	}
}

void CExchOrderActionFactory::retrieve(CExchOrderAction *pExchOrderAction, 
	CWriteableExchOrderAction *pTargetExchOrderAction)
{
	forceCopy(pTargetExchOrderAction, pExchOrderAction, sizeof(CExchOrderAction));
}

COrderFactory::COrderFactory(const std::string &TableName) :COutputTable(TableName)
{

}

COrderFactory::~COrderFactory(void)
{

}

int  COrderFactory::readCSV(const char *filename)
{
	FILE *input;
	input = mfopen(filename, "rt");
	if (input == nullptr)
		return 0;

	std::vector<int> headmap = CProcessCSVRecordFile::readCSVHead(input, &CWriteableOrder::field_desc_);
	if (headmap.empty())
	{
		// 没有取得csv的字段头
		return 0;
	}

	CWriteableOrder thisOrder;
	while (CProcessCSVRecordFile::readCSVRow(input, &thisOrder, headmap, &CWriteableOrder::field_desc_))
	{
		insert(&thisOrder, 0);
	}
	fclose(input);
	return 1;
}

int  COrderFactory::readCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVReadPath");
	szFileName += getCsvFileName();
	return readCSV(szFileName.c_str());
}

int  COrderFactory::writeCSV(const char *filename)
{
	FILE *output = mfopen(filename, "wt");
	if (output == nullptr)
		return 0;

	CProcessCSVRecordFile::writeCSVHead(output, &CWriteableOrder::field_desc_);

	typedef Index_Container_Type::nth_index<0>::type BaseIndex;
	typedef BaseIndex::value_type value_type;
	BaseIndex &baseIndex = getContainer().get<0>();

	BOOST_FOREACH(value_type v, baseIndex)
	{
		CProcessCSVRecordFile::writeCSVRow(output, v.get(), &CWriteableOrder::field_desc_);
	}
	fclose(output);
	return 1;
}

int  COrderFactory::writeCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVWritePath");
	szFileName += getCsvFileName();
	return writeCSV(szFileName.c_str());
}

void COrderFactory::dump(char *filename)
{
	FILE *fp;
	fp = mfopen(filename, "w+b");
	dump(fp);
	if (fp != nullptr)
		fclose(fp);
}

void COrderFactory::dump(FILE *fp)
{
	int index = 0; ///下标
	if (fp == nullptr) 
		fp = stdout;

	fprintf(fp, "COrderFactory={       Total Count=%d\n", getCount());
	BOOST_FOREACH(Idx_Cont_Order::value_type v, getContainer())
	{
		v->dump(fp, index++);
	}
	fprintf(fp, "}\n");
}

void COrderFactory::clearAll(void)
{
	getContainer().clear();
}

COrder* COrderFactory::addOrUpdate(COrder *pOrder, CWriteableOrder *pNewOrder, 
	CTransaction *pTransaction, bool updateIndex)
{
	if (pOrder == nullptr) {
		return insert(pNewOrder, pTransaction);
	}
	else {
		update(pOrder, pNewOrder, pTransaction);
		return pOrder;
	}
}

void COrderFactory::retrieve(COrder *pOrder, CWriteableOrder *pTargetOrder)
{
	forceCopy(pTargetOrder, pOrder, sizeof(COrder));
}

CTradeFactory::CTradeFactory(const std::string &TableName) :COutputTable(TableName)
{

}

CTradeFactory::~CTradeFactory(void)
{

}

int  CTradeFactory::readCSV(const char *filename)
{
	FILE *input;
	input = mfopen(filename, "rt");
	if (input == nullptr)
		return 0;

	std::vector<int> headmap = CProcessCSVRecordFile::readCSVHead(input, &CWriteableTrade::field_desc_);
	if (headmap.empty())
	{
		// 没有取得csv的字段头
		return 0;
	}

	CWriteableTrade thisTrade;
	while (CProcessCSVRecordFile::readCSVRow(input, &thisTrade, headmap, &CWriteableTrade::field_desc_))
	{
		insert(&thisTrade, 0);
	}
	fclose(input);
	return 1;
}

int  CTradeFactory::readCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVReadPath");
	szFileName += getCsvFileName();
	return readCSV(szFileName.c_str());
}

int  CTradeFactory::writeCSV(const char *filename)
{
	FILE *output = mfopen(filename, "wt");
	if (output == nullptr)
		return 0;

	CProcessCSVRecordFile::writeCSVHead(output, &CWriteableTrade::field_desc_);

	typedef Index_Container_Type::nth_index<0>::type BaseIndex;
	typedef BaseIndex::value_type value_type;
	BaseIndex &baseIndex = getContainer().get<0>();

	BOOST_FOREACH(value_type v, baseIndex)
	{
		CProcessCSVRecordFile::writeCSVRow(output, v.get(), &CWriteableTrade::field_desc_);
	}
	fclose(output);
	return 1;
}

int  CTradeFactory::writeCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVWritePath");
	szFileName += getCsvFileName();
	return writeCSV(szFileName.c_str());
}

void CTradeFactory::dump(char *filename)
{
	FILE *fp;
	fp = mfopen(filename, "w+b");
	dump(fp);
	if (fp != nullptr) 
		fclose(fp);
}

void CTradeFactory::dump(FILE *fp)
{
	int index = 0; ///下标
	if (fp == nullptr)
		fp = stdout;

	fprintf(fp, "CTradeFactory={       Total Count=%d\n", getCount());
	BOOST_FOREACH(Idx_Cont_Trade::value_type v, getContainer())
	{
		v->dump(fp, index++);
	}
	fprintf(fp, "}\n");
}

void CTradeFactory::clearAll(void)
{
	getContainer().clear();
}

CTrade* CTradeFactory::addOrUpdate(CTrade *pTrade, CWriteableTrade *pNewTrade, 
	CTransaction *pTransaction, bool updateIndex)
{
	if (pTrade == nullptr) {
		return insert(pNewTrade, pTransaction);
	}
	else {
		update(pTrade, pNewTrade, pTransaction);
		return pTrade;
	}
}

void CTradeFactory::retrieve(CTrade *pTrade, CWriteableTrade *pTargetTrade)
{
	forceCopy(pTargetTrade, pTrade, sizeof(CTrade));
}

CEsfInstPartInfoFactory::CEsfInstPartInfoFactory(const std::string &TableName) :COutputTable(TableName)
{

}

CEsfInstPartInfoFactory::~CEsfInstPartInfoFactory(void)
{

}

int  CEsfInstPartInfoFactory::readCSV(const char *filename)
{
	FILE *input;
	input = mfopen(filename, "rt");
	if (input == NULL) { return 0; }

	std::vector<int> headmap = CProcessCSVRecordFile::readCSVHead(input, &CWriteableEsfInstPartInfo::field_desc_);
	if (headmap.empty())
	{
		// 没有取得csv的字段头
		return 0;
	}

	CWriteableEsfInstPartInfo thisEsfInstPartInfo;
	while (CProcessCSVRecordFile::readCSVRow(input, &thisEsfInstPartInfo, headmap, &CWriteableEsfInstPartInfo::field_desc_))
	{
		insert(&thisEsfInstPartInfo, 0);
	}
	fclose(input);
	return 1;
}

int  CEsfInstPartInfoFactory::readCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVReadPath");
	szFileName += getCsvFileName();
	return readCSV(szFileName.c_str());
}

int  CEsfInstPartInfoFactory::writeCSV(const char *filename)
{
	FILE *output = mfopen(filename, "wt");
	if (output == NULL) { return 0; }

	CProcessCSVRecordFile::writeCSVHead(output, &CWriteableEsfInstPartInfo::field_desc_);

	typedef Index_Container_Type::nth_index<0>::type BaseIndex;
	typedef BaseIndex::value_type value_type;
	BaseIndex &baseIndex = getContainer().get<0>();

	BOOST_FOREACH(value_type v, baseIndex)
	{
		CProcessCSVRecordFile::writeCSVRow(output, v.get(), &CWriteableEsfInstPartInfo::field_desc_);
	}
	fclose(output);
	return 1;
}

int  CEsfInstPartInfoFactory::writeCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVWritePath");
	szFileName += getCsvFileName();
	return writeCSV(szFileName.c_str());
}

void CEsfInstPartInfoFactory::dump(char *filename)
{
	FILE *fp;
	fp = mfopen(filename, "w+b");
	dump(fp);
	if (fp != NULL) fclose(fp);
}

void CEsfInstPartInfoFactory::dump(FILE *fp)
{
	int index = 0; ///下标
	if (fp == NULL) fp = stdout;
	fprintf(fp, "CEsfInstPartInfoFactory={       Total Count=%d\n", getCount());
	BOOST_FOREACH(Idx_Cont_EsfInstPartInfo::value_type v, getContainer())
	{
		v->dump(fp, index++);
	}
	fprintf(fp, "}\n");
}

void CEsfInstPartInfoFactory::clearAll(void)
{
	getContainer().clear();
}

CEsfInstPartInfo* CEsfInstPartInfoFactory::addOrUpdate(CEsfInstPartInfo *pEsfInstPartInfo, CWriteableEsfInstPartInfo *pNewEsfInstPartInfo, CTransaction *pTransaction, bool updateIndex)
{
	if (pEsfInstPartInfo == NULL) {
		return insert(pNewEsfInstPartInfo, pTransaction);
	}
	else {
		update(pEsfInstPartInfo, pNewEsfInstPartInfo, pTransaction);
		return pEsfInstPartInfo;
	}
}

void CEsfInstPartInfoFactory::retrieve(CEsfInstPartInfo *pEsfInstPartInfo, CWriteableEsfInstPartInfo *pTargetEsfInstPartInfo)
{
	forceCopy(pTargetEsfInstPartInfo, pEsfInstPartInfo, sizeof(CEsfInstPartInfo));
}

extern int compareForCurrencyIDIndexinCurrency(const void *pV1, const void *pV2);

CCurrencyFactory::CCurrencyFactory(const std::string &TableName) :COutputTable(TableName)
{

}

CCurrencyFactory::~CCurrencyFactory(void)
{

}

int  CCurrencyFactory::readCSV(const char *filename)
{
	FILE *input;
	input = mfopen(filename, "rt");
	if (input == NULL) { return 0; }

	std::vector<int> headmap = CProcessCSVRecordFile::readCSVHead(input, &CWriteableCurrency::field_desc_);
	if (headmap.empty())
	{
		// 没有取得csv的字段头
		return 0;
	}

	CWriteableCurrency thisCurrency;
	while (CProcessCSVRecordFile::readCSVRow(input, &thisCurrency, headmap, &CWriteableCurrency::field_desc_))
	{
		insert(&thisCurrency, 0);
	}
	fclose(input);
	return 1;
}

int  CCurrencyFactory::readCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVReadPath");
	szFileName += getCsvFileName();
	return readCSV(szFileName.c_str());
}

int  CCurrencyFactory::writeCSV(const char *filename)
{
	FILE *output = mfopen(filename, "wt");
	if (output == NULL) { return 0; }

	CProcessCSVRecordFile::writeCSVHead(output, &CWriteableCurrency::field_desc_);

	typedef Index_Container_Type::nth_index<0>::type BaseIndex;
	typedef BaseIndex::value_type value_type;
	BaseIndex &baseIndex = getContainer().get<0>();

	BOOST_FOREACH(value_type v, baseIndex)
	{
		CProcessCSVRecordFile::writeCSVRow(output, v.get(), &CWriteableCurrency::field_desc_);
	}
	fclose(output);
	return 1;
}

int  CCurrencyFactory::writeCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVWritePath");
	szFileName += getCsvFileName();
	return writeCSV(szFileName.c_str());
}

void CCurrencyFactory::dump(char *filename)
{
	FILE *fp;
	fp = mfopen(filename, "w+b");
	dump(fp);
	if (fp != NULL) fclose(fp);
}

void CCurrencyFactory::dump(FILE *fp)
{
	int index = 0; ///下标
	if (fp == NULL) fp = stdout;
	fprintf(fp, "CCurrencyFactory={       Total Count=%d\n", getCount());
	BOOST_FOREACH(Idx_Cont_Currency::value_type v, getContainer())
	{
		v->dump(fp, index++);
	}
	fprintf(fp, "}\n");
}

void CCurrencyFactory::clearAll(void)
{
	getContainer().clear();
}

CCurrency* CCurrencyFactory::addOrUpdate(CCurrency *pCurrency, CWriteableCurrency *pNewCurrency, CTransaction *pTransaction, bool updateIndex)
{
	if (pCurrency == NULL) {
		return insert(pNewCurrency, pTransaction);
	}
	else {
		update(pCurrency, pNewCurrency, pTransaction);
		return pCurrency;
	}
}

void CCurrencyFactory::retrieve(CCurrency *pCurrency, CWriteableCurrency *pTargetCurrency)
{
	forceCopy(pTargetCurrency, pCurrency, sizeof(CCurrency));
}

extern int compareForTradeUserIDIndexinExchUserLogin(const void *pV1, const void *pV2);

CExchUserLoginFactory::CExchUserLoginFactory(const std::string &TableName) :COutputTable(TableName)
{

}

CExchUserLoginFactory::~CExchUserLoginFactory(void)
{

}

int  CExchUserLoginFactory::readCSV(const char *filename)
{
	FILE *input;
	input = mfopen(filename, "rt");
	if (input == NULL) { return 0; }

	std::vector<int> headmap = CProcessCSVRecordFile::readCSVHead(input, &CWriteableExchUserLogin::field_desc_);
	if (headmap.empty())
	{
		// 没有取得csv的字段头
		return 0;
	}

	CWriteableExchUserLogin thisExchUserLogin;
	while (CProcessCSVRecordFile::readCSVRow(input, &thisExchUserLogin, headmap, &CWriteableExchUserLogin::field_desc_))
	{
		insert(&thisExchUserLogin, 0);
	}
	fclose(input);
	return 1;
}

int  CExchUserLoginFactory::readCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVReadPath");
	szFileName += getCsvFileName();
	return readCSV(szFileName.c_str());
}

int  CExchUserLoginFactory::writeCSV(const char *filename)
{
	FILE *output = mfopen(filename, "wt");
	if (output == NULL) { return 0; }

	CProcessCSVRecordFile::writeCSVHead(output, &CWriteableExchUserLogin::field_desc_);

	typedef Index_Container_Type::nth_index<0>::type BaseIndex;
	typedef BaseIndex::value_type value_type;
	BaseIndex &baseIndex = getContainer().get<0>();

	BOOST_FOREACH(value_type v, baseIndex)
	{
		CProcessCSVRecordFile::writeCSVRow(output, v.get(), &CWriteableExchUserLogin::field_desc_);
	}
	fclose(output);
	return 1;
}

int  CExchUserLoginFactory::writeCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVWritePath");
	szFileName += getCsvFileName();
	return writeCSV(szFileName.c_str());
}

void CExchUserLoginFactory::dump(char *filename)
{
	FILE *fp;
	fp = mfopen(filename, "w+b");
	dump(fp);
	if (fp != NULL) fclose(fp);
}

void CExchUserLoginFactory::dump(FILE *fp)
{
	int index = 0; ///下标
	if (fp == NULL) fp = stdout;
	fprintf(fp, "CExchUserLoginFactory={       Total Count=%d\n", getCount());
	BOOST_FOREACH(Idx_Cont_ExchUserLogin::value_type v, getContainer())
	{
		v->dump(fp, index++);
	}
	fprintf(fp, "}\n");
}

void CExchUserLoginFactory::clearAll(void)
{
	getContainer().clear();
}

CExchUserLogin* CExchUserLoginFactory::addOrUpdate(CExchUserLogin *pExchUserLogin, CWriteableExchUserLogin *pNewExchUserLogin, CTransaction *pTransaction, bool updateIndex)
{
	if (pExchUserLogin == NULL) {
		return insert(pNewExchUserLogin, pTransaction);
	}
	else {
		update(pExchUserLogin, pNewExchUserLogin, pTransaction);
		return pExchUserLogin;
	}
}

void CExchUserLoginFactory::retrieve(CExchUserLogin *pExchUserLogin, CWriteableExchUserLogin *pTargetExchUserLogin)
{
	forceCopy(pTargetExchUserLogin, pExchUserLogin, sizeof(CExchUserLogin));
}

extern int compareForTradeUserIDIndexinExchUserLogout(const void *pV1, const void *pV2);

CExchUserLogoutFactory::CExchUserLogoutFactory(const std::string &TableName) :COutputTable(TableName)
{

}

CExchUserLogoutFactory::~CExchUserLogoutFactory(void)
{

}

int  CExchUserLogoutFactory::readCSV(const char *filename)
{
	FILE *input;
	input = mfopen(filename, "rt");
	if (input == NULL) { return 0; }

	std::vector<int> headmap = CProcessCSVRecordFile::readCSVHead(input, &CWriteableExchUserLogout::field_desc_);
	if (headmap.empty())
	{
		// 没有取得csv的字段头
		return 0;
	}

	CWriteableExchUserLogout thisExchUserLogout;
	while (CProcessCSVRecordFile::readCSVRow(input, &thisExchUserLogout, headmap, &CWriteableExchUserLogout::field_desc_))
	{
		insert(&thisExchUserLogout, 0);
	}
	fclose(input);
	return 1;
}

int  CExchUserLogoutFactory::readCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVReadPath");
	szFileName += getCsvFileName();
	return readCSV(szFileName.c_str());
}

int  CExchUserLogoutFactory::writeCSV(const char *filename)
{
	FILE *output = mfopen(filename, "wt");
	if (output == NULL) { return 0; }

	CProcessCSVRecordFile::writeCSVHead(output, &CWriteableExchUserLogout::field_desc_);

	typedef Index_Container_Type::nth_index<0>::type BaseIndex;
	typedef BaseIndex::value_type value_type;
	BaseIndex &baseIndex = getContainer().get<0>();

	BOOST_FOREACH(value_type v, baseIndex)
	{
		CProcessCSVRecordFile::writeCSVRow(output, v.get(), &CWriteableExchUserLogout::field_desc_);
	}
	fclose(output);
	return 1;
}

int  CExchUserLogoutFactory::writeCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVWritePath");
	szFileName += getCsvFileName();
	return writeCSV(szFileName.c_str());
}

void CExchUserLogoutFactory::dump(char *filename)
{
	FILE *fp;
	fp = mfopen(filename, "w+b");
	dump(fp);
	if (fp != NULL) fclose(fp);
}

void CExchUserLogoutFactory::dump(FILE *fp)
{
	int index = 0; ///下标
	if (fp == NULL) fp = stdout;
	fprintf(fp, "CExchUserLogoutFactory={       Total Count=%d\n", getCount());
	BOOST_FOREACH(Idx_Cont_ExchUserLogout::value_type v, getContainer())
	{
		v->dump(fp, index++);
	}
	fprintf(fp, "}\n");
}

void CExchUserLogoutFactory::clearAll(void)
{
	getContainer().clear();
}

CExchUserLogout* CExchUserLogoutFactory::addOrUpdate(CExchUserLogout *pExchUserLogout, CWriteableExchUserLogout *pNewExchUserLogout, CTransaction *pTransaction, bool updateIndex)
{
	if (pExchUserLogout == NULL) {
		return insert(pNewExchUserLogout, pTransaction);
	}
	else {
		update(pExchUserLogout, pNewExchUserLogout, pTransaction);
		return pExchUserLogout;
	}
}

void CExchUserLogoutFactory::retrieve(CExchUserLogout *pExchUserLogout, CWriteableExchUserLogout *pTargetExchUserLogout)
{
	forceCopy(pTargetExchUserLogout, pExchUserLogout, sizeof(CExchUserLogout));
}

extern int compareForMDUserIDIndexinExchMDUserLogin(const void *pV1, const void *pV2);

CExchMDUserLoginFactory::CExchMDUserLoginFactory(const std::string &TableName) :COutputTable(TableName)
{

}

CExchMDUserLoginFactory::~CExchMDUserLoginFactory(void)
{

}

int  CExchMDUserLoginFactory::readCSV(const char *filename)
{
	FILE *input;
	input = mfopen(filename, "rt");
	if (input == NULL) { return 0; }

	std::vector<int> headmap = CProcessCSVRecordFile::readCSVHead(input, &CWriteableExchMDUserLogin::field_desc_);
	if (headmap.empty())
	{
		// 没有取得csv的字段头
		return 0;
	}

	CWriteableExchMDUserLogin thisExchMDUserLogin;
	while (CProcessCSVRecordFile::readCSVRow(input, &thisExchMDUserLogin, headmap, &CWriteableExchMDUserLogin::field_desc_))
	{
		insert(&thisExchMDUserLogin, 0);
	}
	fclose(input);
	return 1;
}

int  CExchMDUserLoginFactory::readCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVReadPath");
	szFileName += getCsvFileName();
	return readCSV(szFileName.c_str());
}

int  CExchMDUserLoginFactory::writeCSV(const char *filename)
{
	FILE *output = mfopen(filename, "wt");
	if (output == NULL) { return 0; }

	CProcessCSVRecordFile::writeCSVHead(output, &CWriteableExchMDUserLogin::field_desc_);

	typedef Index_Container_Type::nth_index<0>::type BaseIndex;
	typedef BaseIndex::value_type value_type;
	BaseIndex &baseIndex = getContainer().get<0>();

	BOOST_FOREACH(value_type v, baseIndex)
	{
		CProcessCSVRecordFile::writeCSVRow(output, v.get(), &CWriteableExchMDUserLogin::field_desc_);
	}
	fclose(output);
	return 1;
}

int  CExchMDUserLoginFactory::writeCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVWritePath");
	szFileName += getCsvFileName();
	return writeCSV(szFileName.c_str());
}

void CExchMDUserLoginFactory::dump(char *filename)
{
	FILE *fp;
	fp = mfopen(filename, "w+b");
	dump(fp);
	if (fp != NULL) fclose(fp);
}

void CExchMDUserLoginFactory::dump(FILE *fp)
{
	int index = 0; ///下标
	if (fp == NULL) fp = stdout;
	fprintf(fp, "CExchMDUserLoginFactory={       Total Count=%d\n", getCount());
	BOOST_FOREACH(Idx_Cont_ExchMDUserLogin::value_type v, getContainer())
	{
		v->dump(fp, index++);
	}
	fprintf(fp, "}\n");
}

void CExchMDUserLoginFactory::clearAll(void)
{
	getContainer().clear();
}

CExchMDUserLogin* CExchMDUserLoginFactory::addOrUpdate(CExchMDUserLogin *pExchMDUserLogin, CWriteableExchMDUserLogin *pNewExchMDUserLogin, CTransaction *pTransaction, bool updateIndex)
{
	if (pExchMDUserLogin == NULL) {
		return insert(pNewExchMDUserLogin, pTransaction);
	}
	else {
		update(pExchMDUserLogin, pNewExchMDUserLogin, pTransaction);
		return pExchMDUserLogin;
	}
}

void CExchMDUserLoginFactory::retrieve(CExchMDUserLogin *pExchMDUserLogin, CWriteableExchMDUserLogin *pTargetExchMDUserLogin)
{
	forceCopy(pTargetExchMDUserLogin, pExchMDUserLogin, sizeof(CExchMDUserLogin));
}

extern int compareForMDUserIDIndexinExchMDUserLogout(const void *pV1, const void *pV2);

CExchMDUserLogoutFactory::CExchMDUserLogoutFactory(const std::string &TableName) :COutputTable(TableName)
{

}

CExchMDUserLogoutFactory::~CExchMDUserLogoutFactory(void)
{

}

int  CExchMDUserLogoutFactory::readCSV(const char *filename)
{
	FILE *input;
	input = mfopen(filename, "rt");
	if (input == NULL) { return 0; }

	std::vector<int> headmap = CProcessCSVRecordFile::readCSVHead(input, &CWriteableExchMDUserLogout::field_desc_);
	if (headmap.empty())
	{
		// 没有取得csv的字段头
		return 0;
	}

	CWriteableExchMDUserLogout thisExchMDUserLogout;
	while (CProcessCSVRecordFile::readCSVRow(input, &thisExchMDUserLogout, headmap, &CWriteableExchMDUserLogout::field_desc_))
	{
		insert(&thisExchMDUserLogout, 0);
	}
	fclose(input);
	return 1;
}

int  CExchMDUserLogoutFactory::readCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVReadPath");
	szFileName += getCsvFileName();
	return readCSV(szFileName.c_str());
}

int  CExchMDUserLogoutFactory::writeCSV(const char *filename)
{
	FILE *output = mfopen(filename, "wt");
	if (output == NULL) { return 0; }

	CProcessCSVRecordFile::writeCSVHead(output, &CWriteableExchMDUserLogout::field_desc_);

	typedef Index_Container_Type::nth_index<0>::type BaseIndex;
	typedef BaseIndex::value_type value_type;
	BaseIndex &baseIndex = getContainer().get<0>();

	BOOST_FOREACH(value_type v, baseIndex)
	{
		CProcessCSVRecordFile::writeCSVRow(output, v.get(), &CWriteableExchMDUserLogout::field_desc_);
	}
	fclose(output);
	return 1;
}

int  CExchMDUserLogoutFactory::writeCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVWritePath");
	szFileName += getCsvFileName();
	return writeCSV(szFileName.c_str());
}

void CExchMDUserLogoutFactory::dump(char *filename)
{
	FILE *fp;
	fp = mfopen(filename, "w+b");
	dump(fp);
	if (fp != NULL) fclose(fp);
}

void CExchMDUserLogoutFactory::dump(FILE *fp)
{
	int index = 0; ///下标
	if (fp == NULL) fp = stdout;
	fprintf(fp, "CExchMDUserLogoutFactory={       Total Count=%d\n", getCount());
	BOOST_FOREACH(Idx_Cont_ExchMDUserLogout::value_type v, getContainer())
	{
		v->dump(fp, index++);
	}
	fprintf(fp, "}\n");
}

void CExchMDUserLogoutFactory::clearAll(void)
{
	getContainer().clear();
}

CExchMDUserLogout* CExchMDUserLogoutFactory::addOrUpdate(CExchMDUserLogout *pExchMDUserLogout, CWriteableExchMDUserLogout *pNewExchMDUserLogout, CTransaction *pTransaction, bool updateIndex)
{
	if (pExchMDUserLogout == NULL) {
		return insert(pNewExchMDUserLogout, pTransaction);
	}
	else {
		update(pExchMDUserLogout, pNewExchMDUserLogout, pTransaction);
		return pExchMDUserLogout;
	}
}

void CExchMDUserLogoutFactory::retrieve(CExchMDUserLogout *pExchMDUserLogout, CWriteableExchMDUserLogout *pTargetExchMDUserLogout)
{
	forceCopy(pTargetExchMDUserLogout, pExchMDUserLogout, sizeof(CExchMDUserLogout));
}

extern int compareForInnerIDIndexinExchOrder(const void *pV1, const void *pV2);
extern int compareForOrderSysIDIndexinExchOrder(const void *pV1, const void *pV2);

CExchOrderFactory::CExchOrderFactory(const std::string &TableName) :COutputTable(TableName)
{

}

CExchOrderFactory::~CExchOrderFactory(void)
{

}

int  CExchOrderFactory::readCSV(const char *filename)
{
	FILE *input;
	input = mfopen(filename, "rt");
	if (input == NULL) { return 0; }

	std::vector<int> headmap = CProcessCSVRecordFile::readCSVHead(input, &CWriteableExchOrder::field_desc_);
	if (headmap.empty())
	{
		// 没有取得csv的字段头
		return 0;
	}

	CWriteableExchOrder thisExchOrder;
	while (CProcessCSVRecordFile::readCSVRow(input, &thisExchOrder, headmap, &CWriteableExchOrder::field_desc_))
	{
		insert(&thisExchOrder, 0);
	}
	fclose(input);
	return 1;
}

int  CExchOrderFactory::readCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVReadPath");
	szFileName += getCsvFileName();
	return readCSV(szFileName.c_str());
}

int  CExchOrderFactory::writeCSV(const char *filename)
{
	FILE *output = mfopen(filename, "wt");
	if (output == NULL) { return 0; }

	CProcessCSVRecordFile::writeCSVHead(output, &CWriteableExchOrder::field_desc_);

	typedef Index_Container_Type::nth_index<0>::type BaseIndex;
	typedef BaseIndex::value_type value_type;
	BaseIndex &baseIndex = getContainer().get<0>();

	BOOST_FOREACH(value_type v, baseIndex)
	{
		CProcessCSVRecordFile::writeCSVRow(output, v.get(), &CWriteableExchOrder::field_desc_);
	}
	fclose(output);
	return 1;
}

int  CExchOrderFactory::writeCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVWritePath");
	szFileName += getCsvFileName();
	return writeCSV(szFileName.c_str());
}

void CExchOrderFactory::dump(char *filename)
{
	FILE *fp;
	fp = mfopen(filename, "w+b");
	dump(fp);
	if (fp != NULL) fclose(fp);
}

void CExchOrderFactory::dump(FILE *fp)
{
	int index = 0; ///下标
	if (fp == NULL) fp = stdout;
	fprintf(fp, "CExchOrderFactory={       Total Count=%d\n", getCount());
	BOOST_FOREACH(Idx_Cont_ExchOrder::value_type v, getContainer())
	{
		v->dump(fp, index++);
	}
	fprintf(fp, "}\n");
}

void CExchOrderFactory::clearAll(void)
{
	getContainer().clear();
}

CExchOrder* CExchOrderFactory::addOrUpdate(CExchOrder *pExchOrder, CWriteableExchOrder *pNewExchOrder, CTransaction *pTransaction, bool updateIndex)
{
	if (pExchOrder == NULL) {
		return insert(pNewExchOrder, pTransaction);
	}
	else {
		update(pExchOrder, pNewExchOrder, pTransaction);
		return pExchOrder;
	}
}

void CExchOrderFactory::retrieve(CExchOrder *pExchOrder, CWriteableExchOrder *pTargetExchOrder)
{
	forceCopy(pTargetExchOrder, pExchOrder, sizeof(CExchOrder));
}

extern int compareForTradeIDIndexinExchTrade(const void *pV1, const void *pV2);
extern int compareForInstrumentIDIndexinExchTrade(const void *pV1, const void *pV2);

CExchTradeFactory::CExchTradeFactory(const std::string &TableName) :COutputTable(TableName)
{

}

CExchTradeFactory::~CExchTradeFactory(void)
{

}

int  CExchTradeFactory::readCSV(const char *filename)
{
	FILE *input;
	input = mfopen(filename, "rt");
	if (input == NULL) { return 0; }

	std::vector<int> headmap = CProcessCSVRecordFile::readCSVHead(input, &CWriteableExchTrade::field_desc_);
	if (headmap.empty())
	{
		// 没有取得csv的字段头
		return 0;
	}

	CWriteableExchTrade thisExchTrade;
	while (CProcessCSVRecordFile::readCSVRow(input, &thisExchTrade, headmap, &CWriteableExchTrade::field_desc_))
	{
		insert(&thisExchTrade, 0);
	}
	fclose(input);
	return 1;
}

int  CExchTradeFactory::readCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVReadPath");
	szFileName += getCsvFileName();
	return readCSV(szFileName.c_str());
}

int  CExchTradeFactory::writeCSV(const char *filename)
{
	FILE *output = mfopen(filename, "wt");
	if (output == NULL) { return 0; }

	CProcessCSVRecordFile::writeCSVHead(output, &CWriteableExchTrade::field_desc_);

	typedef Index_Container_Type::nth_index<0>::type BaseIndex;
	typedef BaseIndex::value_type value_type;
	BaseIndex &baseIndex = getContainer().get<0>();

	BOOST_FOREACH(value_type v, baseIndex)
	{
		CProcessCSVRecordFile::writeCSVRow(output, v.get(), &CWriteableExchTrade::field_desc_);
	}
	fclose(output);
	return 1;
}

int  CExchTradeFactory::writeCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVWritePath");
	szFileName += getCsvFileName();
	return writeCSV(szFileName.c_str());
}

void CExchTradeFactory::dump(char *filename)
{
	FILE *fp;
	fp = mfopen(filename, "w+b");
	dump(fp);
	if (fp != NULL) fclose(fp);
}

void CExchTradeFactory::dump(FILE *fp)
{
	int index = 0; ///下标
	if (fp == NULL) fp = stdout;
	fprintf(fp, "CExchTradeFactory={       Total Count=%d\n", getCount());
	BOOST_FOREACH(Idx_Cont_ExchTrade::value_type v, getContainer())
	{
		v->dump(fp, index++);
	}
	fprintf(fp, "}\n");
}

void CExchTradeFactory::clearAll(void)
{
	getContainer().clear();
}

CExchTrade* CExchTradeFactory::addOrUpdate(CExchTrade *pExchTrade, CWriteableExchTrade *pNewExchTrade, CTransaction *pTransaction, bool updateIndex)
{
	if (pExchTrade == NULL) {
		return insert(pNewExchTrade, pTransaction);
	}
	else {
		update(pExchTrade, pNewExchTrade, pTransaction);
		return pExchTrade;
	}
}

void CExchTradeFactory::retrieve(CExchTrade *pExchTrade, CWriteableExchTrade *pTargetExchTrade)
{
	forceCopy(pTargetExchTrade, pExchTrade, sizeof(CExchTrade));
}

extern int compareForInvestorIDIndexinExchInvestorPosition(const void *pV1, const void *pV2);


CExchInvestorPositionFactory::CExchInvestorPositionFactory(const std::string &TableName) :COutputTable(TableName)
{

}

CExchInvestorPositionFactory::~CExchInvestorPositionFactory(void)
{

}

int  CExchInvestorPositionFactory::readCSV(const char *filename)
{
	FILE *input;
	input = mfopen(filename, "rt");
	if (input == NULL) { return 0; }

	std::vector<int> headmap = CProcessCSVRecordFile::readCSVHead(input, &CWriteableExchInvestorPosition::field_desc_);
	if (headmap.empty())
	{
		// 没有取得csv的字段头
		return 0;
	}

	CWriteableExchInvestorPosition thisExchInvestorPosition;
	while (CProcessCSVRecordFile::readCSVRow(input, &thisExchInvestorPosition, headmap, &CWriteableExchInvestorPosition::field_desc_))
	{
		insert(&thisExchInvestorPosition, 0);
	}
	fclose(input);
	return 1;
}

int  CExchInvestorPositionFactory::readCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVReadPath");
	szFileName += getCsvFileName();
	return readCSV(szFileName.c_str());
}

int  CExchInvestorPositionFactory::writeCSV(const char *filename)
{
	FILE *output = mfopen(filename, "wt");
	if (output == NULL) { return 0; }

	CProcessCSVRecordFile::writeCSVHead(output, &CWriteableExchInvestorPosition::field_desc_);

	typedef Index_Container_Type::nth_index<0>::type BaseIndex;
	typedef BaseIndex::value_type value_type;
	BaseIndex &baseIndex = getContainer().get<0>();

	BOOST_FOREACH(value_type v, baseIndex)
	{
		CProcessCSVRecordFile::writeCSVRow(output, v.get(), &CWriteableExchInvestorPosition::field_desc_);
	}
	fclose(output);
	return 1;
}

int  CExchInvestorPositionFactory::writeCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVWritePath");
	szFileName += getCsvFileName();
	return writeCSV(szFileName.c_str());
}

void CExchInvestorPositionFactory::dump(char *filename)
{
	FILE *fp;
	fp = mfopen(filename, "w+b");
	dump(fp);
	if (fp != NULL) fclose(fp);
}

void CExchInvestorPositionFactory::dump(FILE *fp)
{
	int index = 0; ///下标
	if (fp == NULL) fp = stdout;
	fprintf(fp, "CExchInvestorPositionFactory={       Total Count=%d\n", getCount());
	BOOST_FOREACH(Idx_Cont_ExchInvestorPosition::value_type v, getContainer())
	{
		v->dump(fp, index++);
	}
	fprintf(fp, "}\n");
}

void CExchInvestorPositionFactory::clearAll(void)
{
	getContainer().clear();
}

CExchInvestorPosition* CExchInvestorPositionFactory::addOrUpdate(CExchInvestorPosition *pExchInvestorPosition, CWriteableExchInvestorPosition *pNewExchInvestorPosition, CTransaction *pTransaction, bool updateIndex)
{
	if (pExchInvestorPosition == NULL) {
		return insert(pNewExchInvestorPosition, pTransaction);
	}
	else {
		update(pExchInvestorPosition, pNewExchInvestorPosition, pTransaction);
		return pExchInvestorPosition;
	}
}

void CExchInvestorPositionFactory::retrieve(CExchInvestorPosition *pExchInvestorPosition, CWriteableExchInvestorPosition *pTargetExchInvestorPosition)
{
	forceCopy(pTargetExchInvestorPosition, pExchInvestorPosition, sizeof(CExchInvestorPosition));
}

extern int compareForInvestorIDIndexinExchInvestorAccount(const void *pV1, const void *pV2);

CExchInvestorAccountFactory::CExchInvestorAccountFactory(const std::string &TableName) :COutputTable(TableName)
{

}

CExchInvestorAccountFactory::~CExchInvestorAccountFactory(void)
{

}

int  CExchInvestorAccountFactory::readCSV(const char *filename)
{
	FILE *input;
	input = mfopen(filename, "rt");
	if (input == NULL) { return 0; }

	std::vector<int> headmap = CProcessCSVRecordFile::readCSVHead(input, &CWriteableExchInvestorAccount::field_desc_);
	if (headmap.empty())
	{
		// 没有取得csv的字段头
		return 0;
	}

	CWriteableExchInvestorAccount thisExchInvestorAccount;
	while (CProcessCSVRecordFile::readCSVRow(input, &thisExchInvestorAccount, headmap, &CWriteableExchInvestorAccount::field_desc_))
	{
		insert(&thisExchInvestorAccount, 0);
	}
	fclose(input);
	return 1;
}

int  CExchInvestorAccountFactory::readCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVReadPath");
	szFileName += getCsvFileName();
	return readCSV(szFileName.c_str());
}

int  CExchInvestorAccountFactory::writeCSV(const char *filename)
{
	FILE *output = mfopen(filename, "wt");
	if (output == NULL) { return 0; }

	CProcessCSVRecordFile::writeCSVHead(output, &CWriteableExchInvestorAccount::field_desc_);

	typedef Index_Container_Type::nth_index<0>::type BaseIndex;
	typedef BaseIndex::value_type value_type;
	BaseIndex &baseIndex = getContainer().get<0>();

	BOOST_FOREACH(value_type v, baseIndex)
	{
		CProcessCSVRecordFile::writeCSVRow(output, v.get(), &CWriteableExchInvestorAccount::field_desc_);
	}
	fclose(output);
	return 1;
}

int  CExchInvestorAccountFactory::writeCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVWritePath");
	szFileName += getCsvFileName();
	return writeCSV(szFileName.c_str());
}

void CExchInvestorAccountFactory::dump(char *filename)
{
	FILE *fp;
	fp = mfopen(filename, "w+b");
	dump(fp);
	if (fp != NULL) fclose(fp);
}

void CExchInvestorAccountFactory::dump(FILE *fp)
{
	int index = 0; ///下标
	if (fp == NULL) fp = stdout;
	fprintf(fp, "CExchInvestorAccountFactory={       Total Count=%d\n", getCount());
	BOOST_FOREACH(Idx_Cont_ExchInvestorAccount::value_type v, getContainer())
	{
		v->dump(fp, index++);
	}
	fprintf(fp, "}\n");
}

void CExchInvestorAccountFactory::clearAll(void)
{
	getContainer().clear();
}

CExchInvestorAccount* CExchInvestorAccountFactory::addOrUpdate(CExchInvestorAccount *pExchInvestorAccount, CWriteableExchInvestorAccount *pNewExchInvestorAccount, CTransaction *pTransaction, bool updateIndex)
{
	if (pExchInvestorAccount == NULL) {
		return insert(pNewExchInvestorAccount, pTransaction);
	}
	else {
		update(pExchInvestorAccount, pNewExchInvestorAccount, pTransaction);
		return pExchInvestorAccount;
	}
}

void CExchInvestorAccountFactory::retrieve(CExchInvestorAccount *pExchInvestorAccount, CWriteableExchInvestorAccount *pTargetExchInvestorAccount)
{
	forceCopy(pTargetExchInvestorAccount, pExchInvestorAccount, sizeof(CExchInvestorAccount));
}

extern int compareForInstrumentIDIndexinExchDepthMarketData(const void *pV1, const void *pV2);

CExchDepthMarketDataFactory::CExchDepthMarketDataFactory(const std::string &TableName) :COutputTable(TableName)
{

}

CExchDepthMarketDataFactory::~CExchDepthMarketDataFactory(void)
{

}

int  CExchDepthMarketDataFactory::readCSV(const char *filename)
{
	FILE *input;
	input = mfopen(filename, "rt");
	if (input == NULL) { return 0; }

	std::vector<int> headmap = CProcessCSVRecordFile::readCSVHead(input, &CWriteableExchDepthMarketData::field_desc_);
	if (headmap.empty())
	{
		// 没有取得csv的字段头
		return 0;
	}

	CWriteableExchDepthMarketData thisExchDepthMarketData;
	while (CProcessCSVRecordFile::readCSVRow(input, &thisExchDepthMarketData, headmap, &CWriteableExchDepthMarketData::field_desc_))
	{
		insert(&thisExchDepthMarketData, 0);
	}
	fclose(input);
	return 1;
}

int  CExchDepthMarketDataFactory::readCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVReadPath");
	szFileName += getCsvFileName();
	return readCSV(szFileName.c_str());
}

int  CExchDepthMarketDataFactory::writeCSV(const char *filename)
{
	FILE *output = mfopen(filename, "wt");
	if (output == NULL) { return 0; }

	CProcessCSVRecordFile::writeCSVHead(output, &CWriteableExchDepthMarketData::field_desc_);

	typedef Index_Container_Type::nth_index<0>::type BaseIndex;
	typedef BaseIndex::value_type value_type;
	BaseIndex &baseIndex = getContainer().get<0>();

	BOOST_FOREACH(value_type v, baseIndex)
	{
		CProcessCSVRecordFile::writeCSVRow(output, v.get(), &CWriteableExchDepthMarketData::field_desc_);
	}
	fclose(output);
	return 1;
}

int  CExchDepthMarketDataFactory::writeCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVWritePath");
	szFileName += getCsvFileName();
	return writeCSV(szFileName.c_str());
}

void CExchDepthMarketDataFactory::dump(char *filename)
{
	FILE *fp;
	fp = mfopen(filename, "w+b");
	dump(fp);
	if (fp != NULL) fclose(fp);
}

void CExchDepthMarketDataFactory::dump(FILE *fp)
{
	int index = 0; ///下标
	if (fp == NULL) fp = stdout;
	fprintf(fp, "CExchDepthMarketDataFactory={       Total Count=%d\n", getCount());
	BOOST_FOREACH(Idx_Cont_ExchDepthMarketData::value_type v, getContainer())
	{
		v->dump(fp, index++);
	}
	fprintf(fp, "}\n");
}

void CExchDepthMarketDataFactory::clearAll(void)
{
	getContainer().clear();
}

CExchDepthMarketData* CExchDepthMarketDataFactory::addOrUpdate(CExchDepthMarketData *pExchDepthMarketData, CWriteableExchDepthMarketData *pNewExchDepthMarketData, CTransaction *pTransaction, bool updateIndex)
{
	if (pExchDepthMarketData == NULL) {
		return insert(pNewExchDepthMarketData, pTransaction);
	}
	else {
		update(pExchDepthMarketData, pNewExchDepthMarketData, pTransaction);
		return pExchDepthMarketData;
	}
}

void CExchDepthMarketDataFactory::retrieve(CExchDepthMarketData *pExchDepthMarketData, CWriteableExchDepthMarketData *pTargetExchDepthMarketData)
{
	forceCopy(pTargetExchDepthMarketData, pExchDepthMarketData, sizeof(CExchDepthMarketData));
}

extern int compareForInstrumentTimeIndexinExchDepthMarketHistoryData(const void *pV1, const void *pV2);

CExchDepthMarketHistoryDataFactory::CExchDepthMarketHistoryDataFactory(const std::string &TableName) :COutputTable(TableName)
{

}

CExchDepthMarketHistoryDataFactory::~CExchDepthMarketHistoryDataFactory(void)
{

}

int  CExchDepthMarketHistoryDataFactory::readCSV(const char *filename)
{
	FILE *input;
	input = mfopen(filename, "rt");
	if (input == NULL) { return 0; }

	std::vector<int> headmap = CProcessCSVRecordFile::readCSVHead(input, &CWriteableExchDepthMarketHistoryData::field_desc_);
	if (headmap.empty())
	{
		// 没有取得csv的字段头
		return 0;
	}

	CWriteableExchDepthMarketHistoryData thisExchDepthMarketHistoryData;
	while (CProcessCSVRecordFile::readCSVRow(input, &thisExchDepthMarketHistoryData, headmap, &CWriteableExchDepthMarketHistoryData::field_desc_))
	{
		insert(&thisExchDepthMarketHistoryData, 0);
	}
	fclose(input);
	return 1;
}

int  CExchDepthMarketHistoryDataFactory::readCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVReadPath");
	szFileName += getCsvFileName();
	return readCSV(szFileName.c_str());
}

int  CExchDepthMarketHistoryDataFactory::writeCSV(const char *filename)
{
	FILE *output = mfopen(filename, "wt");
	if (output == NULL) { return 0; }

	CProcessCSVRecordFile::writeCSVHead(output, &CWriteableExchDepthMarketHistoryData::field_desc_);

	typedef Index_Container_Type::nth_index<0>::type BaseIndex;
	typedef BaseIndex::value_type value_type;
	BaseIndex &baseIndex = getContainer().get<0>();

	BOOST_FOREACH(value_type v, baseIndex)
	{
		CProcessCSVRecordFile::writeCSVRow(output, v.get(), &CWriteableExchDepthMarketHistoryData::field_desc_);
	}
	fclose(output);
	return 1;
}

int  CExchDepthMarketHistoryDataFactory::writeCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVWritePath");
	szFileName += getCsvFileName();
	return writeCSV(szFileName.c_str());
}

void CExchDepthMarketHistoryDataFactory::dump(char *filename)
{
	FILE *fp;
	fp = mfopen(filename, "w+b");
	dump(fp);
	if (fp != NULL) fclose(fp);
}

void CExchDepthMarketHistoryDataFactory::dump(FILE *fp)
{
	int index = 0; ///下标
	if (fp == NULL) fp = stdout;
	fprintf(fp, "CExchDepthMarketHistoryDataFactory={       Total Count=%d\n", getCount());
	BOOST_FOREACH(Idx_Cont_ExchDepthMarketHistoryData::value_type v, getContainer())
	{
		v->dump(fp, index++);
	}
	fprintf(fp, "}\n");
}

void CExchDepthMarketHistoryDataFactory::clearAll(void)
{
	getContainer().clear();
}

CExchDepthMarketHistoryData* CExchDepthMarketHistoryDataFactory::addOrUpdate(CExchDepthMarketHistoryData *pExchDepthMarketHistoryData, CWriteableExchDepthMarketHistoryData *pNewExchDepthMarketHistoryData, CTransaction *pTransaction, bool updateIndex)
{
	if (pExchDepthMarketHistoryData == NULL) {
		return insert(pNewExchDepthMarketHistoryData, pTransaction);
	}
	else {
		update(pExchDepthMarketHistoryData, pNewExchDepthMarketHistoryData, pTransaction);
		return pExchDepthMarketHistoryData;
	}
}

void CExchDepthMarketHistoryDataFactory::retrieve(CExchDepthMarketHistoryData *pExchDepthMarketHistoryData, CWriteableExchDepthMarketHistoryData *pTargetExchDepthMarketHistoryData)
{
	forceCopy(pTargetExchDepthMarketHistoryData, pExchDepthMarketHistoryData, sizeof(CExchDepthMarketHistoryData));
}

extern int compareForInstrumentIDIndexinExchInstrument(const void *pV1, const void *pV2);
extern int compareForCommodityIDIndexinExchInstrument(const void *pV1, const void *pV2);
extern int compareForExchInstrumentIDIndexinExchInstrument(const void *pV1, const void *pV2);

CExchInstrumentFactory::CExchInstrumentFactory(const std::string &TableName) :COutputTable(TableName)
{

}

CExchInstrumentFactory::~CExchInstrumentFactory(void)
{

}

int  CExchInstrumentFactory::readCSV(const char *filename)
{
	FILE *input;
	input = mfopen(filename, "rt");
	if (input == NULL) { return 0; }

	std::vector<int> headmap = CProcessCSVRecordFile::readCSVHead(input, &CWriteableExchInstrument::field_desc_);
	if (headmap.empty())
	{
		// 没有取得csv的字段头
		return 0;
	}

	CWriteableExchInstrument thisExchInstrument;
	while (CProcessCSVRecordFile::readCSVRow(input, &thisExchInstrument, headmap, &CWriteableExchInstrument::field_desc_))
	{
		insert(&thisExchInstrument, 0);
	}
	fclose(input);
	return 1;
}

int  CExchInstrumentFactory::readCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVReadPath");
	szFileName += getCsvFileName();
	return readCSV(szFileName.c_str());
}

int  CExchInstrumentFactory::writeCSV(const char *filename)
{
	FILE *output = mfopen(filename, "wt");
	if (output == NULL) { return 0; }

	CProcessCSVRecordFile::writeCSVHead(output, &CWriteableExchInstrument::field_desc_);

	typedef Index_Container_Type::nth_index<0>::type BaseIndex;
	typedef BaseIndex::value_type value_type;
	BaseIndex &baseIndex = getContainer().get<0>();

	BOOST_FOREACH(value_type v, baseIndex)
	{
		CProcessCSVRecordFile::writeCSVRow(output, v.get(), &CWriteableExchInstrument::field_desc_);
	}
	fclose(output);
	return 1;
}

int  CExchInstrumentFactory::writeCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVWritePath");
	szFileName += getCsvFileName();
	return writeCSV(szFileName.c_str());
}

void CExchInstrumentFactory::dump(char *filename)
{
	FILE *fp;
	fp = mfopen(filename, "w+b");
	dump(fp);
	if (fp != NULL) fclose(fp);
}

void CExchInstrumentFactory::dump(FILE *fp)
{
	int index = 0; ///下标
	if (fp == NULL) fp = stdout;
	fprintf(fp, "CExchInstrumentFactory={       Total Count=%d\n", getCount());
	BOOST_FOREACH(Idx_Cont_ExchInstrument::value_type v, getContainer())
	{
		v->dump(fp, index++);
	}
	fprintf(fp, "}\n");
}

void CExchInstrumentFactory::clearAll(void)
{
	getContainer().clear();
}

CExchInstrument* CExchInstrumentFactory::addOrUpdate(CExchInstrument *pExchInstrument, CWriteableExchInstrument *pNewExchInstrument, CTransaction *pTransaction, bool updateIndex)
{
	if (pExchInstrument == NULL) {
		return insert(pNewExchInstrument, pTransaction);
	}
	else {
		update(pExchInstrument, pNewExchInstrument, pTransaction);
		return pExchInstrument;
	}
}

void CExchInstrumentFactory::retrieve(CExchInstrument *pExchInstrument, CWriteableExchInstrument *pTargetExchInstrument)
{
	forceCopy(pTargetExchInstrument, pExchInstrument, sizeof(CExchInstrument));
}

extern int compareForInstrumentIDIndexinExchInstrumentStatus(const void *pV1, const void *pV2);
extern int compareForExchInstrumentIDIndexinExchInstrumentStatus(const void *pV1, const void *pV2);

CExchInstrumentStatusFactory::CExchInstrumentStatusFactory(const std::string &TableName) :COutputTable(TableName)
{

}

CExchInstrumentStatusFactory::~CExchInstrumentStatusFactory(void)
{

}

int  CExchInstrumentStatusFactory::readCSV(const char *filename)
{
	FILE *input;
	input = mfopen(filename, "rt");
	if (input == NULL) { return 0; }

	std::vector<int> headmap = CProcessCSVRecordFile::readCSVHead(input, &CWriteableExchInstrumentStatus::field_desc_);
	if (headmap.empty())
	{
		// 没有取得csv的字段头
		return 0;
	}

	CWriteableExchInstrumentStatus thisExchInstrumentStatus;
	while (CProcessCSVRecordFile::readCSVRow(input, &thisExchInstrumentStatus, headmap, &CWriteableExchInstrumentStatus::field_desc_))
	{
		insert(&thisExchInstrumentStatus, 0);
	}
	fclose(input);
	return 1;
}

int  CExchInstrumentStatusFactory::readCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVReadPath");
	szFileName += getCsvFileName();
	return readCSV(szFileName.c_str());
}

int  CExchInstrumentStatusFactory::writeCSV(const char *filename)
{
	FILE *output = mfopen(filename, "wt");
	if (output == NULL) { return 0; }

	CProcessCSVRecordFile::writeCSVHead(output, &CWriteableExchInstrumentStatus::field_desc_);

	typedef Index_Container_Type::nth_index<0>::type BaseIndex;
	typedef BaseIndex::value_type value_type;
	BaseIndex &baseIndex = getContainer().get<0>();

	BOOST_FOREACH(value_type v, baseIndex)
	{
		CProcessCSVRecordFile::writeCSVRow(output, v.get(), &CWriteableExchInstrumentStatus::field_desc_);
	}
	fclose(output);
	return 1;
}

int  CExchInstrumentStatusFactory::writeCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVWritePath");
	szFileName += getCsvFileName();
	return writeCSV(szFileName.c_str());
}

void CExchInstrumentStatusFactory::dump(char *filename)
{
	FILE *fp;
	fp = mfopen(filename, "w+b");
	dump(fp);
	if (fp != NULL) fclose(fp);
}

void CExchInstrumentStatusFactory::dump(FILE *fp)
{
	int index = 0; ///下标
	if (fp == NULL) fp = stdout;
	fprintf(fp, "CExchInstrumentStatusFactory={       Total Count=%d\n", getCount());
	BOOST_FOREACH(Idx_Cont_ExchInstrumentStatus::value_type v, getContainer())
	{
		v->dump(fp, index++);
	}
	fprintf(fp, "}\n");
}

void CExchInstrumentStatusFactory::clearAll(void)
{
	getContainer().clear();
}

CExchInstrumentStatus* CExchInstrumentStatusFactory::addOrUpdate(CExchInstrumentStatus *pExchInstrumentStatus, CWriteableExchInstrumentStatus *pNewExchInstrumentStatus, CTransaction *pTransaction, bool updateIndex)
{
	if (pExchInstrumentStatus == NULL) {
		return insert(pNewExchInstrumentStatus, pTransaction);
	}
	else {
		update(pExchInstrumentStatus, pNewExchInstrumentStatus, pTransaction);
		return pExchInstrumentStatus;
	}
}

void CExchInstrumentStatusFactory::retrieve(CExchInstrumentStatus *pExchInstrumentStatus, CWriteableExchInstrumentStatus *pTargetExchInstrumentStatus)
{
	forceCopy(pTargetExchInstrumentStatus, pExchInstrumentStatus, sizeof(CExchInstrumentStatus));
}

extern int compareForUserIDIdxinPhyAccount(const void *pV1, const void *pV2);

CPhyAccountFactory::CPhyAccountFactory(const std::string &TableName) :COutputTable(TableName)
{

}

CPhyAccountFactory::~CPhyAccountFactory(void)
{

}

int  CPhyAccountFactory::readCSV(const char *filename)
{
	FILE *input;
	input = mfopen(filename, "rt");
	if (input == NULL) { return 0; }

	std::vector<int> headmap = CProcessCSVRecordFile::readCSVHead(input, &CWriteablePhyAccount::field_desc_);
	if (headmap.empty())
	{
		// 没有取得csv的字段头
		return 0;
	}

	CWriteablePhyAccount thisPhyAccount;
	while (CProcessCSVRecordFile::readCSVRow(input, &thisPhyAccount, headmap, &CWriteablePhyAccount::field_desc_))
	{
		insert(&thisPhyAccount, 0);
	}
	fclose(input);
	return 1;
}

int  CPhyAccountFactory::readCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVReadPath");
	szFileName += getCsvFileName();
	return readCSV(szFileName.c_str());
}

int  CPhyAccountFactory::writeCSV(const char *filename)
{
	FILE *output = mfopen(filename, "wt");
	if (output == NULL) { return 0; }

	CProcessCSVRecordFile::writeCSVHead(output, &CWriteablePhyAccount::field_desc_);

	typedef Index_Container_Type::nth_index<0>::type BaseIndex;
	typedef BaseIndex::value_type value_type;
	BaseIndex &baseIndex = getContainer().get<0>();

	BOOST_FOREACH(value_type v, baseIndex)
	{
		CProcessCSVRecordFile::writeCSVRow(output, v.get(), &CWriteablePhyAccount::field_desc_);
	}
	fclose(output);
	return 1;
}

int  CPhyAccountFactory::writeCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVWritePath");
	szFileName += getCsvFileName();
	return writeCSV(szFileName.c_str());
}

void CPhyAccountFactory::dump(char *filename)
{
	FILE *fp;
	fp = mfopen(filename, "w+b");
	dump(fp);
	if (fp != NULL) fclose(fp);
}

void CPhyAccountFactory::dump(FILE *fp)
{
	int index = 0; ///下标
	if (fp == NULL) fp = stdout;
	fprintf(fp, "CPhyAccountFactory={       Total Count=%d\n", getCount());
	BOOST_FOREACH(Idx_Cont_PhyAccount::value_type v, getContainer())
	{
		v->dump(fp, index++);
	}
	fprintf(fp, "}\n");
}

void CPhyAccountFactory::clearAll(void)
{
	getContainer().clear();
}

CPhyAccount* CPhyAccountFactory::addOrUpdate(CPhyAccount *pPhyAccount, CWriteablePhyAccount *pNewPhyAccount, CTransaction *pTransaction, bool updateIndex)
{
	if (pPhyAccount == NULL) {
		return insert(pNewPhyAccount, pTransaction);
	}
	else {
		update(pPhyAccount, pNewPhyAccount, pTransaction);
		return pPhyAccount;
	}
}

void CPhyAccountFactory::retrieve(CPhyAccount *pPhyAccount, CWriteablePhyAccount *pTargetPhyAccount)
{
	forceCopy(pTargetPhyAccount, pPhyAccount, sizeof(CPhyAccount));
}

extern int compareForInstDirectIndexinInvestorPosition(const void *pV1, const void *pV2);

CInvestorPositionFactory::CInvestorPositionFactory(const std::string &TableName) :COutputTable(TableName)
{

}

CInvestorPositionFactory::~CInvestorPositionFactory(void)
{

}

int  CInvestorPositionFactory::readCSV(const char *filename)
{
	FILE *input;
	input = mfopen(filename, "rt");
	if (input == NULL) { return 0; }

	std::vector<int> headmap = CProcessCSVRecordFile::readCSVHead(input, &CWriteableInvestorPosition::field_desc_);
	if (headmap.empty())
	{
		// 没有取得csv的字段头
		return 0;
	}

	CWriteableInvestorPosition thisInvestorPosition;
	while (CProcessCSVRecordFile::readCSVRow(input, &thisInvestorPosition, headmap, &CWriteableInvestorPosition::field_desc_))
	{
		insert(&thisInvestorPosition, 0);
	}
	fclose(input);
	return 1;
}

int  CInvestorPositionFactory::readCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVReadPath");
	szFileName += getCsvFileName();
	return readCSV(szFileName.c_str());
}

int  CInvestorPositionFactory::writeCSV(const char *filename)
{
	FILE *output = mfopen(filename, "wt");
	if (output == NULL) { return 0; }

	CProcessCSVRecordFile::writeCSVHead(output, &CWriteableInvestorPosition::field_desc_);

	typedef Index_Container_Type::nth_index<0>::type BaseIndex;
	typedef BaseIndex::value_type value_type;
	BaseIndex &baseIndex = getContainer().get<0>();

	BOOST_FOREACH(value_type v, baseIndex)
	{
		CProcessCSVRecordFile::writeCSVRow(output, v.get(), &CWriteableInvestorPosition::field_desc_);
	}
	fclose(output);
	return 1;
}

int  CInvestorPositionFactory::writeCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVWritePath");
	szFileName += getCsvFileName();
	return writeCSV(szFileName.c_str());
}

void CInvestorPositionFactory::dump(char *filename)
{
	FILE *fp;
	fp = mfopen(filename, "w+b");
	dump(fp);
	if (fp != NULL) fclose(fp);
}

void CInvestorPositionFactory::dump(FILE *fp)
{
	int index = 0; ///下标
	if (fp == NULL) fp = stdout;
	fprintf(fp, "CInvestorPositionFactory={       Total Count=%d\n", getCount());
	BOOST_FOREACH(Idx_Cont_InvestorPosition::value_type v, getContainer())
	{
		v->dump(fp, index++);
	}
	fprintf(fp, "}\n");
}

void CInvestorPositionFactory::clearAll(void)
{
	getContainer().clear();
}

CInvestorPosition* CInvestorPositionFactory::addOrUpdate(CInvestorPosition *pInvestorPosition, CWriteableInvestorPosition *pNewInvestorPosition, CTransaction *pTransaction, bool updateIndex)
{
	if (pInvestorPosition == NULL) {
		return insert(pNewInvestorPosition, pTransaction);
	}
	else {
		update(pInvestorPosition, pNewInvestorPosition, pTransaction);
		return pInvestorPosition;
	}
}

void CInvestorPositionFactory::retrieve(CInvestorPosition *pInvestorPosition, CWriteableInvestorPosition *pTargetInvestorPosition)
{
	forceCopy(pTargetInvestorPosition, pInvestorPosition, sizeof(CInvestorPosition));
}

extern int compareForRuleIDIdxinRuleInfo(const void *pV1, const void *pV2);

CRuleInfoFactory::CRuleInfoFactory(const std::string &TableName) :COutputTable(TableName)
{

}

CRuleInfoFactory::~CRuleInfoFactory(void)
{

}

int  CRuleInfoFactory::readCSV(const char *filename)
{
	FILE *input;
	input = mfopen(filename, "rt");
	if (input == NULL) { return 0; }

	std::vector<int> headmap = CProcessCSVRecordFile::readCSVHead(input, &CWriteableRuleInfo::field_desc_);
	if (headmap.empty())
	{
		// 没有取得csv的字段头
		return 0;
	}

	CWriteableRuleInfo thisRuleInfo;
	while (CProcessCSVRecordFile::readCSVRow(input, &thisRuleInfo, headmap, &CWriteableRuleInfo::field_desc_))
	{
		insert(&thisRuleInfo, 0);
	}
	fclose(input);
	return 1;
}

int  CRuleInfoFactory::readCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVReadPath");
	szFileName += getCsvFileName();
	return readCSV(szFileName.c_str());
}

int  CRuleInfoFactory::writeCSV(const char *filename)
{
	FILE *output = mfopen(filename, "wt");
	if (output == NULL) { return 0; }

	CProcessCSVRecordFile::writeCSVHead(output, &CWriteableRuleInfo::field_desc_);

	typedef Index_Container_Type::nth_index<0>::type BaseIndex;
	typedef BaseIndex::value_type value_type;
	BaseIndex &baseIndex = getContainer().get<0>();

	BOOST_FOREACH(value_type v, baseIndex)
	{
		CProcessCSVRecordFile::writeCSVRow(output, v.get(), &CWriteableRuleInfo::field_desc_);
	}
	fclose(output);
	return 1;
}

int  CRuleInfoFactory::writeCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVWritePath");
	szFileName += getCsvFileName();
	return writeCSV(szFileName.c_str());
}

void CRuleInfoFactory::dump(char *filename)
{
	FILE *fp;
	fp = mfopen(filename, "w+b");
	dump(fp);
	if (fp != NULL) fclose(fp);
}

void CRuleInfoFactory::dump(FILE *fp)
{
	int index = 0; ///下标
	if (fp == NULL) fp = stdout;
	fprintf(fp, "CRuleInfoFactory={       Total Count=%d\n", getCount());
	BOOST_FOREACH(Idx_Cont_RuleInfo::value_type v, getContainer())
	{
		v->dump(fp, index++);
	}
	fprintf(fp, "}\n");
}

void CRuleInfoFactory::clearAll(void)
{
	getContainer().clear();
}

CRuleInfo* CRuleInfoFactory::addOrUpdate(CRuleInfo *pRuleInfo, CWriteableRuleInfo *pNewRuleInfo, CTransaction *pTransaction, bool updateIndex)
{
	if (pRuleInfo == NULL) {
		return insert(pNewRuleInfo, pTransaction);
	}
	else {
		update(pRuleInfo, pNewRuleInfo, pTransaction);
		return pRuleInfo;
	}
}

void CRuleInfoFactory::retrieve(CRuleInfo *pRuleInfo, CWriteableRuleInfo *pTargetRuleInfo)
{
	forceCopy(pTargetRuleInfo, pRuleInfo, sizeof(CRuleInfo));
}

extern int compareForExchInstrumentIDIndexinExchInvestorFee(const void *pV1, const void *pV2);

CExchInvestorFeeFactory::CExchInvestorFeeFactory(const std::string &TableName) :COutputTable(TableName)
{

}

CExchInvestorFeeFactory::~CExchInvestorFeeFactory(void)
{

}

int  CExchInvestorFeeFactory::readCSV(const char *filename)
{
	FILE *input;
	input = mfopen(filename, "rt");
	if (input == NULL) { return 0; }

	std::vector<int> headmap = CProcessCSVRecordFile::readCSVHead(input, &CWriteableExchInvestorFee::field_desc_);
	if (headmap.empty())
	{
		// 没有取得csv的字段头
		return 0;
	}

	CWriteableExchInvestorFee thisExchInvestorFee;
	while (CProcessCSVRecordFile::readCSVRow(input, &thisExchInvestorFee, headmap, &CWriteableExchInvestorFee::field_desc_))
	{
		insert(&thisExchInvestorFee, 0);
	}
	fclose(input);
	return 1;
}

int  CExchInvestorFeeFactory::readCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVReadPath");
	szFileName += getCsvFileName();
	return readCSV(szFileName.c_str());
}

int  CExchInvestorFeeFactory::writeCSV(const char *filename)
{
	FILE *output = mfopen(filename, "wt");
	if (output == NULL) { return 0; }

	CProcessCSVRecordFile::writeCSVHead(output, &CWriteableExchInvestorFee::field_desc_);

	typedef Index_Container_Type::nth_index<0>::type BaseIndex;
	typedef BaseIndex::value_type value_type;
	BaseIndex &baseIndex = getContainer().get<0>();

	BOOST_FOREACH(value_type v, baseIndex)
	{
		CProcessCSVRecordFile::writeCSVRow(output, v.get(), &CWriteableExchInvestorFee::field_desc_);
	}
	fclose(output);
	return 1;
}

int  CExchInvestorFeeFactory::writeCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVWritePath");
	szFileName += getCsvFileName();
	return writeCSV(szFileName.c_str());
}

void CExchInvestorFeeFactory::dump(char *filename)
{
	FILE *fp;
	fp = mfopen(filename, "w+b");
	dump(fp);
	if (fp != NULL) fclose(fp);
}

void CExchInvestorFeeFactory::dump(FILE *fp)
{
	int index = 0; ///下标
	if (fp == NULL) fp = stdout;
	fprintf(fp, "CExchInvestorFeeFactory={       Total Count=%d\n", getCount());
	BOOST_FOREACH(Idx_Cont_ExchInvestorFee::value_type v, getContainer())
	{
		v->dump(fp, index++);
	}
	fprintf(fp, "}\n");
}

void CExchInvestorFeeFactory::clearAll(void)
{
	getContainer().clear();
}

CExchInvestorFee* CExchInvestorFeeFactory::addOrUpdate(CExchInvestorFee *pExchInvestorFee, CWriteableExchInvestorFee *pNewExchInvestorFee, CTransaction *pTransaction, bool updateIndex)
{
	if (pExchInvestorFee == NULL) {
		return insert(pNewExchInvestorFee, pTransaction);
	}
	else {
		update(pExchInvestorFee, pNewExchInvestorFee, pTransaction);
		return pExchInvestorFee;
	}
}

void CExchInvestorFeeFactory::retrieve(CExchInvestorFee *pExchInvestorFee, CWriteableExchInvestorFee *pTargetExchInvestorFee)
{
	forceCopy(pTargetExchInvestorFee, pExchInvestorFee, sizeof(CExchInvestorFee));
}

extern int compareForExchInstrumentIDIndexinExchInvestorMargin(const void *pV1, const void *pV2);

CExchInvestorMarginFactory::CExchInvestorMarginFactory(const std::string &TableName) :COutputTable(TableName)
{

}

CExchInvestorMarginFactory::~CExchInvestorMarginFactory(void)
{

}

int  CExchInvestorMarginFactory::readCSV(const char *filename)
{
	FILE *input;
	input = mfopen(filename, "rt");
	if (input == NULL) { return 0; }

	std::vector<int> headmap = CProcessCSVRecordFile::readCSVHead(input, &CWriteableExchInvestorMargin::field_desc_);
	if (headmap.empty())
	{
		// 没有取得csv的字段头
		return 0;
	}

	CWriteableExchInvestorMargin thisExchInvestorMargin;
	while (CProcessCSVRecordFile::readCSVRow(input, &thisExchInvestorMargin, headmap, &CWriteableExchInvestorMargin::field_desc_))
	{
		insert(&thisExchInvestorMargin, 0);
	}
	fclose(input);
	return 1;
}

int  CExchInvestorMarginFactory::readCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVReadPath");
	szFileName += getCsvFileName();
	return readCSV(szFileName.c_str());
}

int  CExchInvestorMarginFactory::writeCSV(const char *filename)
{
	FILE *output = mfopen(filename, "wt");
	if (output == NULL) { return 0; }

	CProcessCSVRecordFile::writeCSVHead(output, &CWriteableExchInvestorMargin::field_desc_);

	typedef Index_Container_Type::nth_index<0>::type BaseIndex;
	typedef BaseIndex::value_type value_type;
	BaseIndex &baseIndex = getContainer().get<0>();

	BOOST_FOREACH(value_type v, baseIndex)
	{
		CProcessCSVRecordFile::writeCSVRow(output, v.get(), &CWriteableExchInvestorMargin::field_desc_);
	}
	fclose(output);
	return 1;
}

int CExchInvestorMarginFactory::writeCSV(config::CConfig *pConfig)
{
	std::string szFileName = pConfig->getString("CSVWritePath");
	szFileName += getCsvFileName();
	return writeCSV(szFileName.c_str());
}

void CExchInvestorMarginFactory::dump(char *filename)
{
	FILE *fp;
	fp = mfopen(filename, "w+b");
	dump(fp);
	if (fp != NULL) fclose(fp);
}

void CExchInvestorMarginFactory::dump(FILE *fp)
{
	int index = 0; ///下标
	if (fp == NULL) fp = stdout;
	fprintf(fp, "CExchInvestorMarginFactory={       Total Count=%d\n", getCount());
	BOOST_FOREACH(Idx_Cont_ExchInvestorMargin::value_type v, getContainer())
	{
		v->dump(fp, index++);
	}
	fprintf(fp, "}\n");
}

void CExchInvestorMarginFactory::clearAll(void)
{
	getContainer().clear();
}

CExchInvestorMargin* CExchInvestorMarginFactory::addOrUpdate(CExchInvestorMargin *pExchInvestorMargin, CWriteableExchInvestorMargin *pNewExchInvestorMargin, CTransaction *pTransaction, bool updateIndex)
{
	if (pExchInvestorMargin == NULL) {
		return insert(pNewExchInvestorMargin, pTransaction);
	}
	else {
		update(pExchInvestorMargin, pNewExchInvestorMargin, pTransaction);
		return pExchInvestorMargin;
	}
}

void CExchInvestorMarginFactory::retrieve(CExchInvestorMargin *pExchInvestorMargin, CWriteableExchInvestorMargin *pTargetExchInvestorMargin)
{
	forceCopy(pTargetExchInvestorMargin, pExchInvestorMargin, sizeof(CExchInvestorMargin));
}