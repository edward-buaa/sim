
#include "Tables.h"
#include "../utility/mpath.h"
#include "ProcessCSVTable.h"
#include <boost/foreach.hpp>


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
		//û��ȡ��csv���ֶ�ͷ
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
		// û��ȡ��csv���ֶ�ͷ
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

//������д���ļ��У�����debug
void CCurrentTimeFactory::dump(FILE* fp)
{
	int index = 0; ///�±�
	if (fp == NULL) 
		fp = stdout;

	fprintf(fp, "CCurrentTimeFactory={       Total Count=%d\n", getCount());
	BOOST_FOREACH(Idx_Cont_CurrentTime::value_type v, getContainer())
	{
		v->dump(fp, index++);
	}
	fprintf(fp, "}\n");
}

//������д���ļ��У�����debug
void CCurrentTimeFactory::dump(char* filename)
{
	FILE *fp;
	fp = mfopen(filename, "w+b");
	dump(fp);
	if (fp != NULL) 
		fclose(fp);
}



