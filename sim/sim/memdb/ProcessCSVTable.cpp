
#include "ProcessCSVTable.h"

void CProcessCSVRecordFile::writeCSVHead(FILE *fpCSV, FieldDescribe *desc)
{
	TMemberDesc* p;
	for (int i = 0; i < desc->GetMemberCount(); ++i)
	{
		p = desc->GetMemberDesc(i);
		if (i > 0)
			fprintf(fpCSV, ",");
		fprintf(fpCSV, "\"%s\"", p->szName);
	}
	fprintf(fpCSV, "\n");
}

void CProcessCSVRecordFile::writeCSVRow(FILE *fpCSV, void *pStruct, FieldDescribe *desc)
{

}

std::vector<int> CProcessCSVRecordFile::readCSVHead(FILE *input, FieldDescribe *desc)
{
	std::vector<int> a;
	return a;
}

int CProcessCSVRecordFile::readCSVRow(FILE *input, void *pResult,
	std::vector<int> &head, FieldDescribe *desc)
{
	return 0;
}

void CProcessCSVRecordFile::TransField(char *pMember, int nIndex,
	const TMemberDesc *pColInfo, std::vector<char *> *pRecord)
{

}

const char* CProcessCSVRecordFile::GetFieldAsString(const char *p)
{
	return 0;
}

char CProcessCSVRecordFile::GetFieldAsChar(const char *pszFieldContent)
{
	return 0;
}

short CProcessCSVRecordFile::GetFieldAsShort(const char *pszFieldContent)
{
	return 0;
}

int CProcessCSVRecordFile::GetFieldAsInt(const char *pszFieldContent)
{
	return 0;
}

double CProcessCSVRecordFile::GetFieldAsDouble(const char *pszFieldContent)
{
	return 0;
}

long long CProcessCSVRecordFile::GetFieldAsLong(const char *pszFieldContent)
{
	return 1;
}
