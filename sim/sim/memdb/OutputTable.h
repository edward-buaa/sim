#ifndef __BASE_TABLE_DEFINE_H__
#define __BASE_TABLE_DEFINE_H__

#include <string>

class COutputTable
{
public:
	explicit COutputTable(const std::string& tableName)
	{
		m_TableName = tableName;
		m_CsvFileName = tableName;
		m_CsvFileName += ".csv";
	}

	std::string& getTableName()
	{
		return m_TableName;
	}

	std::string& getCsvFileName()
	{
		return m_CsvFileName;
	}

private:
	std::string m_TableName;
	std::string m_CsvFileName;
};


#endif
