#ifndef __MEMORY_DB_H__
#define __MEMORY_DB_H__

/*
功能：内存数据库类，包含了所有定义的表信息
*/

#include "Tables.h"

class CMemoryDB
{
public:
	explicit CMemoryDB();
	virtual ~CMemoryDB();

private:
	//当前时间表
	//CCurrentTimeFactory* m_CurrentTimeFactory;
};

#endif
