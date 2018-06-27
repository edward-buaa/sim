#ifndef __PROCESS_CSV_TABLE_H__
#define __PROCESS_CSV_TABLE_H__

#include <vector>
#include <map>
#include "../network/field_describe.h"


class CProcessCSVRecordFile
{
public:
	static char* getNextToken(char* buffer);
	static void writeCSVHead(FILE *fpCSV, FieldDescribe* desc);
	static void writeCSVRow(FILE *fpCSV, void *pStruct, FieldDescribe* desc);
	static std::vector<int> readCSVHead(FILE *input, FieldDescribe *desc);

	static int readCSVRow(FILE *input, void *pStruct, 
		std::vector<int>& arrayFieldOffset, FieldDescribe* desc);

	static void TransField(char *pMember, int nIndex, const TMemberDesc* pColInfo, 
		std::vector<char *> *pRecord);

	static const char *GetFieldAsString(const char *p);
	static char GetFieldAsChar(const char *pszFieldContent);
	static short GetFieldAsShort(const char *pszFieldContent);
	static int GetFieldAsInt(const char *pszFieldContent);
	static double GetFieldAsDouble(const char *pszFieldContent);
	static long long GetFieldAsLong(const char *pszFieldContent);
};

#endif