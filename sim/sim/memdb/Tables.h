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

	//清空所有记录
	void clearAll();

	//增加或者更新数据
	//@param	pCurrentTime	  需要被刷新或者新增的CCurrentTime,等于NULL表示是需要新增的
	//@param	pNewCurrentTime	新的值
	//@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	//@param	updateIndex	  是否需要更新索引
	//@param	新增或者修改后的数据
	CCurrentTime* addOrUpdate(CCurrentTime *pCurrentTime, CWriteableCurrentTime *pNewCurrentTime, 
		CTransaction *pTransaction = NULL, bool updateIndex = true);

	//获取某个CCurrentTime
	//@param	pCurrentTime	要读取的CCurrentTime
	//@param	pTragetCurrentTime	存放结果的CCurrentTime
	void retrieve(CCurrentTime *pCurrentTime, CWriteableCurrentTime *pTargetCurrentTime);

	std::size_t getCount(void)
	{
		return count();
	}

	Idx_Cont_CurrentTime &getContainer()
	{
		return get_cont();
	}
};

/////////////////////////////////////////////////////////////////////////
//CTerminalFactory是一个终端机的对象工厂。它包含了一批终端机，
//同时又建立了如下索引，以方便查询：
//	TerminalIDIndex
//	SessionIDIndex
//使用本对象工厂，可以完成对终端机的增删改查操作。具体方法如下：
//	增加：叫用add，完成加入
//	删除：叫用remove就可以删除
//	查询：有如下方法可以查询：
//		使用findByTerminalID，唯一找到对象
//		使用startFindAll，findNextAll和endFindAll完成查询操作
//	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
//	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
//		在retrieve时，也可以指定事务，此时将取出经过update的新数据
/////////////////////////////////////////////////////////////////////////
class CTerminalFactory : public COutputTable, public CMemMITable<CTerminal, Idx_Cont_Terminal>
{
public:
	//CTerminalFactory(CConfig *pConfig,const std::string &TableName);
	CTerminalFactory(const std::string &TableName);
	~CTerminalFactory(void);

public:
	//Idx_Cont_Terminal m_Index;
	typedef Idx_Cont_Terminal Data_Container_Type;
	typedef Idx_Cont_Terminal Index_Container_Type;

	//--------------------导入 导出 数据-------------------------------
	int writeCSV(const char *filename);
	int writeCSV(config::CConfig *pConfig);
	int readCSV(const char *filename);
	int readCSV(config::CConfig *pConfig);

	//将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	//将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	//清空所有的记录
	void clearAll(void);

	//增加或者更新数据
	//@param	pTerminal	  需要被刷新或者新增的CTerminal,等于NULL表示是需要新增的
	//@param	pNewTerminal	新的值
	//@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	//@param	updateIndex	  是否需要更新索引
	//@param	新增或者修改后的数据
	CTerminal* addOrUpdate(CTerminal *pTerminal, CWriteableTerminal *pNewTerminal, CTransaction *pTransaction = NULL, bool updateIndex = true);

	//获取某个CTerminal
	//@param	pTerminal	要读取的CTerminal
	//@param	pTragetTerminal	存放结果的CTerminal
	void retrieve(CTerminal *pTerminal, CWriteableTerminal *pTargetTerminal);

	//-----------------------------------------------------------------------
	std::size_t getCount(void)
	{
		return count();
	}
	Idx_Cont_Terminal &getContainer()
	{
		return get_cont();
	}
};

/////////////////////////////////////////////////////////////////////////
//CFrontFactory是一个前置机的对象工厂。它包含了一批前置机，
//同时又建立了如下索引，以方便查询：
//	FrontIDIndex
//	SessionIDIndex
//使用本对象工厂，可以完成对前置机的增删改查操作。具体方法如下：
//	增加：叫用add，完成加入
//	删除：叫用remove就可以删除
//	查询：有如下方法可以查询：
//		使用findByFrontID，唯一找到对象
//		使用startFindAll，findNextAll和endFindAll完成查询操作
//	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
//	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
//		在retrieve时，也可以指定事务，此时将取出经过update的新数据
/////////////////////////////////////////////////////////////////////////
class CFrontFactory : public COutputTable, public CMemMITable<CFront, Idx_Cont_Front>
{
public:
	CFrontFactory(const std::string &TableName);
	~CFrontFactory(void);

public:
	typedef Idx_Cont_Front Data_Container_Type;
	typedef Idx_Cont_Front Index_Container_Type;

	//--------------------导入 导出 数据-------------------------------
	int writeCSV(const char *filename);
	int writeCSV(config::CConfig *pConfig);
	int readCSV(const char *filename);
	int readCSV(config::CConfig *pConfig);

	//将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	//将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	//清空所有的记录
	void clearAll(void);

	//增加或者更新数据
	//@param	pFront	  需要被刷新或者新增的CFront,等于NULL表示是需要新增的
	//@param	pNewFront	新的值
	//@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	//@param	updateIndex	  是否需要更新索引
	//@param	新增或者修改后的数据
	CFront* addOrUpdate(CFront *pFront, CWriteableFront *pNewFront, CTransaction *pTransaction = NULL, bool updateIndex = true);

	//获取某个CFront
	//@param	pFront	要读取的CFront
	//@param	pTragetFront	存放结果的CFront
	void retrieve(CFront *pFront, CWriteableFront *pTargetFront);

	std::size_t getCount(void)
	{
		return count();
	}

	Idx_Cont_Front &getContainer()
	{
		return get_cont();
	}
};

/////////////////////////////////////////////////////////////////////////
//CTraderFactory是一个交易员的对象工厂。它包含了一批交易员，
//同时又建立了如下索引，以方便查询：
//	TraderIDIndex
//使用本对象工厂，可以完成对交易员的增删改查操作。具体方法如下：
//	增加：叫用add，完成加入
//	删除：叫用remove就可以删除
//	查询：有如下方法可以查询：
//		使用startFindByTraderID，findNextByTraderID和endFindByTraderID完成查询操作
//	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
//	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
//		在retrieve时，也可以指定事务，此时将取出经过update的新数据
/////////////////////////////////////////////////////////////////////////
class CTraderFactory : public COutputTable, public CMemMITable<CTrader, Idx_Cont_Trader>
{
public:
	CTraderFactory(const std::string &TableName);
	~CTraderFactory(void);

	typedef Idx_Cont_Trader Data_Container_Type;
	typedef Idx_Cont_Trader Index_Container_Type;

	//--------------------导入 导出 数据-------------------------------
	int writeCSV(const char *filename);
	int writeCSV(config::CConfig *pConfig);
	int readCSV(const char *filename);
	int readCSV(config::CConfig *pConfig);

	//将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	//将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	//清空所有的记录
	void clearAll(void);

	//增加或者更新数据
	//@param	pTrader	  需要被刷新或者新增的CTrader,等于NULL表示是需要新增的
	//@param	pNewTrader	新的值
	//@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	//@param	updateIndex	  是否需要更新索引
	//@param	新增或者修改后的数据
	CTrader* addOrUpdate(CTrader *pTrader, CWriteableTrader *pNewTrader, CTransaction *pTransaction = NULL, bool updateIndex = true);

	//获取某个CTrader
	//@param	pTrader	要读取的CTrader
	//@param	pTragetTrader	存放结果的CTrader
	void retrieve(CTrader *pTrader, CWriteableTrader *pTargetTrader);

	std::size_t getCount(void)
	{
		return count();
	}

	Idx_Cont_Trader &getContainer()
	{
		return get_cont();
	}
};







#endif
