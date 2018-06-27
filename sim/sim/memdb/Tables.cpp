
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




