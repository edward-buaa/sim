
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


