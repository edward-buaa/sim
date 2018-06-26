
#include "ProcessCSVTable.h"
#include "../utility/type_dec.h"

char* CProcessCSVRecordFile::getNextToken(char* buffer)
{
	static char *last;
	char *from, *to;

	if (buffer == NULL)
	{
		from = last;
		if (from == NULL)
		{
			return NULL;
		}
	}
	else
	{
		from = buffer;
	}

	bool hasQuote = false;
	if (*from == '"')
	{
		from++;
		hasQuote = true;
	}

	to = from;
	while ((*to != '\0') && (*to != ',') && (*to != '\n') && (*to != '\r'))
	{
		if (hasQuote && (*to == '"'))
		{
			to++;
			break;
		}
		to++;
	}

	if (*to != ',')
	{
		last = NULL;
	}
	else
	{
		last = to + 1;
	}

	if (!hasQuote)
	{
		*to = '\0';
	}
	else
	{
		*(to - 1) = '\0';
	}

	return from;
}

void CProcessCSVRecordFile::writeCSVHead(FILE *fpCSV, FieldDescribe *desc)
{
	TMemberDesc* p;
	for (int i = 0; i < desc->GetMemberCount(); ++i)
	{
		p = desc->GetMemberDesc(i);
		if (i > 0)
			fprintf(fpCSV, ",");
		fprintf(fpCSV, "\"%s\"", p->szName.c_str());
	}
	fprintf(fpCSV, "\n");
}

void CProcessCSVRecordFile::writeCSVRow(FILE *fpCSV, void *pStruct, FieldDescribe *desc)
{
	for (int i = 0; i < desc->GetMemberCount(); ++i)
	{
		if (i != 0)
		{
			fprintf(fpCSV, ",");
		}

		TMemberDesc* pColumnInfo = desc->GetMemberDesc(i);
		const char* pMember = ((const char*)pStruct) + pColumnInfo->nStructOffset;

		switch (pColumnInfo->nType)
		{
		case FT_CHAR:
			if (CHAR_NULL_VAL != (*pMember & 0xFF))
			{
				fprintf(fpCSV, "%c", *pMember & 0xFF);
			}
			break;
		case FT_SHORT:
			if (WORD_NULL_VAL != (*((WORD *)pMember) & 0xFFFF))
			{
				fprintf(fpCSV, "%d", *((WORD *)pMember) & 0xFFFF);
			}
			break;
		case FT_INT:
			if (INT_NULL_VAL != *((int *)pMember))
			{
				fprintf(fpCSV, "%d", *((int *)pMember));
			}
			break;
		case FT_LONGLONG:
		{
			LONGLONG d = *((LONGLONG *)pMember);
			if (LONG_NULL_VAL != d)
			{
#ifdef WIN32
				fprintf(fpCSV, "%I64d", d);
#else
				fprintf(fpCSV, "%lld", d);
#endif
			}
		}
		break;
		case FT_FLOAT:
		{
			float d = *((REAL4 *)pMember);
			if (d != FLOAT_NULL_VAL)
			{
				fprintf(fpCSV, "%f", d);
			}
		}
		break;
		case FT_DOUBLE:
		{
			double d = *((REAL8 *)pMember);
			if (d != DOUBLE_NULL_VAL)
			{
				fprintf(fpCSV, "%lf", d);
			}
		}
		break;
		case FT_STRING:
			fprintf(fpCSV, "\"%s\"", pMember);
			break;
		}
	}
	fprintf(fpCSV, "\n");
}

std::vector<int> CProcessCSVRecordFile::readCSVHead(FILE *input, FieldDescribe *desc)
{
	char buffer[4096];
	char* token;

	std::vector<char*> fieldList;
	fgets(buffer, 4096, input);
	token = getNextToken(buffer);
	while (token != nullptr)
	{
		fieldList.push_back(token);
		token = getNextToken(nullptr);
	}

	//xww modify  这个有什么用？？？
	/*struct ltstr
	{
		bool operator()(const char* s1, const char* s2)
		{
			return strcmp(s1, s2) < 0;
		}
	};*/

	typedef std::map<const char*, int> CCSVFieldMap;
	CCSVFieldMap m_mapCSVField;
	for (size_t i = 0; i < fieldList.size(); ++i)
	{
		m_mapCSVField.insert(std::make_pair(fieldList.at(i), i));
	}

	std::vector<int> arrayFieldOffset;
	for (int i = 0; i < desc->GetMemberCount(); ++i)
	{
		TMemberDesc *pColumnInfo = desc->GetMemberDesc(i);
		CCSVFieldMap::iterator itor = m_mapCSVField.find(pColumnInfo->szName.c_str());
		int nIndex = (itor == m_mapCSVField.end()) ? -1 : itor->second;
		if (nIndex < 0)
		{
			std::stringstream ss;
			ss << "LoadRecord" << " " << desc->GetFieldName() << " " << 
				desc->GetComment() << " " << " field [" << 
				pColumnInfo->szName << "] not found" << "\n";
			throw new std::runtime_error(ss.str().c_str());
		}
		arrayFieldOffset.push_back(nIndex);
	}
	return arrayFieldOffset;
}

int CProcessCSVRecordFile::readCSVRow(FILE *input, void *pStruct,
	std::vector<int>& arrayFieldOffset, FieldDescribe *desc)
{
	char buffer[4096];
	char *token;

	std::vector<char *> fieldList;
	while (fgets(buffer, 4096, input))
	{
		fieldList.clear();
		token = getNextToken(buffer);
		while (token != nullptr) {
			fieldList.push_back(token);
			token = getNextToken(nullptr);
		}
		if (fieldList.size() < desc->GetMemberCount())
		{
			std::stringstream ss;
			ss << "缺少 CSV record content";
			throw new std::runtime_error(ss.str().c_str());
		}
		for (int i = 0; i<desc->GetMemberCount(); i++)
		{
			TMemberDesc *pColumnInfo = desc->GetMemberDesc(i);
			char *pMember = ((char *)pStruct) + pColumnInfo->nStructOffset;
			TransField(pMember, arrayFieldOffset[i], pColumnInfo, &fieldList);
		}
		return 1;
	}
	return 0;
}

void CProcessCSVRecordFile::TransField(char *pMember, int nIndex,
	const TMemberDesc *pColInfo, std::vector<char *> *pRecord)
{
	switch (pColInfo->nType)
	{
	case FT_CHAR:
		*((BYTE *)pMember) = (BYTE)GetFieldAsChar(pRecord->at(nIndex));
		break;
	case FT_SHORT:
		*((WORD *)pMember) = (WORD)GetFieldAsShort(pRecord->at(nIndex));
		break;
	case FT_INT:
		*((DWORD *)pMember) = (DWORD)GetFieldAsInt(pRecord->at(nIndex));
		break;
	case FT_LONGLONG:
		*((LONGLONG *)pMember) = GetFieldAsLong(pRecord->at(nIndex));
		break;
	case FT_FLOAT:
		*((REAL4 *)pMember) = (REAL4)GetFieldAsDouble(pRecord->at(nIndex));
		break;
	case FT_DOUBLE:
		*((REAL8 *)pMember) = GetFieldAsDouble(pRecord->at(nIndex));
		break;
	case FT_STRING:
		memset(pMember, 0, pColInfo->nSize);
		strncpy(pMember, GetFieldAsString(pRecord->at(nIndex)), pColInfo->nSize);
		pMember[pColInfo->nSize - 1] = '\0';
		char *p = pMember + strlen(pMember);
		while (p > pMember)
		{
			p--;
			if (*p != ' ')
			{
				break;
			}
			*p = '\0';
		}
	}
}

const char* CProcessCSVRecordFile::GetFieldAsString(const char *p)
{
	return p;
}

char CProcessCSVRecordFile::GetFieldAsChar(const char *pszFieldContent)
{
	if (pszFieldContent == nullptr || *pszFieldContent == '\0')
	{
		return CHAR_NULL_VAL;
	}
	return *pszFieldContent;
}

short CProcessCSVRecordFile::GetFieldAsShort(const char *pszFieldContent)
{
	if (pszFieldContent == nullptr || *pszFieldContent == '\0')
	{
		return WORD_NULL_VAL;
	}
	return *pszFieldContent;
}

int CProcessCSVRecordFile::GetFieldAsInt(const char *pszFieldContent)
{
	if (pszFieldContent == nullptr || *pszFieldContent == '\0')
	{
		return INT_NULL_VAL;
	}
	return atoi(pszFieldContent);
}

double CProcessCSVRecordFile::GetFieldAsDouble(const char *pszFieldContent)
{
	if (pszFieldContent == nullptr || *pszFieldContent == '\0')
	{
		return DOUBLE_NULL_VAL;
	}
	return atof(pszFieldContent);
}

long long CProcessCSVRecordFile::GetFieldAsLong(const char *pszFieldContent)
{
	if (pszFieldContent == nullptr || *pszFieldContent == '\0')
	{
		return LONG_NULL_VAL;
	}
	return atoll(pszFieldContent);
}
