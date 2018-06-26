
#include "Tables.h"
#include "../utility/mpath.h"
#include "ProcessCSVTable.h"

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
		&CCurrentTime::field_desc_);
	/*
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
	*/
	fclose(input);
	return 1;
}


