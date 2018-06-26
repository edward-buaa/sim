
#include "Tables.h"
#include "../utility/mpath.h"

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

	return 1;
}