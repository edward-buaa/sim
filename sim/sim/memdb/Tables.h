#ifndef __TABLES_DEFINE_H__
#define __TABLES_DEFINE_H__

/*
功能：定义内存数据库的表
*/

#include "OutputTable.h"
#include "mem_mi_table.h"
#include "RecordStruct.h"
#include "RecordIndexCont.h"
#include "../config/config.h"


/////////////////////////////////////////////////////////////////////////
//CCurrentTimeFactory是一个当前时间的对象工厂。它包含了一批当前时间，
//同时又建立了如下索引，以方便查询：
//使用本对象工厂，可以完成对当前时间的增删改查操作。具体方法如下：
//	增加：叫用add，完成加入
//	删除：叫用remove就可以删除
//	查询：有如下方法可以查询：
//	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
//	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
//		在retrieve时，也可以指定事务，此时将取出经过update的新数据
/////////////////////////////////////////////////////////////////////////
class CCurrentTimeFactory
	: public COutputTable,
	  public CMemMITable<CCurrentTime, Idx_Cont_CurrentTime>
{
public:
	explicit CCurrentTimeFactory(const std::string& TableName);
	~CCurrentTimeFactory();

	typedef Idx_Cont_CurrentTime Data_Container_Type;
	typedef Idx_Cont_CurrentTime Index_Container_Type;

	//--------------导入导出数据------------
	int writeCSV(const char* filename);
	int writeCSV(config::CConfig *pConfig);
	int readCSV(const char *filename);
	int readCSV(config::CConfig *pConfig);

	//讲内容写到文件中，用于debug
	virtual void dump(FILE* fp);

	//讲内容写到文件中，用于debug
	virtual void dump(char* filename);

	std::size_t getCount(void)
	{
		return count();
	}

	Idx_Cont_CurrentTime &getContainer()
	{
		return get_cont();
	}
};

#endif
