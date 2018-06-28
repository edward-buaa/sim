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

/////////////////////////////////////////////////////////////////////////
//CTraderParalleFactory是一个交易员并行资源的对象工厂。它包含了一批交易员并行资源，
//同时又建立了如下索引，以方便查询：
//	TraderIDIndex
//使用本对象工厂，可以完成对交易员并行资源的增删改查操作。具体方法如下：
//	增加：叫用add，完成加入
//	删除：叫用remove就可以删除
//	查询：有如下方法可以查询：
//		使用startFindByTraderID，findNextByTraderID和endFindByTraderID完成查询操作
//	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
//	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
//		在retrieve时，也可以指定事务，此时将取出经过update的新数据
////////////////////////////////////////////////////////////////////////
class CTraderParalleFactory : public COutputTable, public CMemMITable<CTraderParalle, Idx_Cont_TraderParalle>
{
public:
	CTraderParalleFactory(const std::string &TableName);
	~CTraderParalleFactory(void);

	typedef Idx_Cont_TraderParalle Data_Container_Type;
	typedef Idx_Cont_TraderParalle Index_Container_Type;

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
	//@param	pTraderParalle	  需要被刷新或者新增的CTraderParalle,等于NULL表示是需要新增的
	//@param	pNewTraderParalle	新的值
	//@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	//@param	updateIndex	  是否需要更新索引
	//@param	新增或者修改后的数据
	CTraderParalle* addOrUpdate(CTraderParalle *pTraderParalle, CWriteableTraderParalle *pNewTraderParalle, CTransaction *pTransaction = NULL, bool updateIndex = true);

	//获取某个CTraderParalle
	//@param	pTraderParalle	要读取的CTraderParalle
	//@param	pTragetTraderParalle	存放结果的CTraderParalle
	void retrieve(CTraderParalle *pTraderParalle, CWriteableTraderParalle *pTargetTraderParalle);

	std::size_t getCount(void)
	{
		return count();
	}

	Idx_Cont_TraderParalle &getContainer()
	{
		return get_cont();
	}
};

/////////////////////////////////////////////////////////////////////////
//CTraderLoginLogFactory是一个交易员登录记录的对象工厂。它包含了一批交易员登录记录，
//同时又建立了如下索引，以方便查询：
//	TraderIDIndex
//使用本对象工厂，可以完成对交易员登录记录的增删改查操作。具体方法如下：
//	增加：叫用add，完成加入
//	删除：叫用remove就可以删除
//	查询：有如下方法可以查询：
//		使用findByTraderID，唯一找到对象
//	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
//	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
//		在retrieve时，也可以指定事务，此时将取出经过update的新数据
/////////////////////////////////////////////////////////////////////////
class CTraderLoginLogFactory 
	: public COutputTable, public CMemMITable<CTraderLoginLog, Idx_Cont_TraderLoginLog>
{
public:
	CTraderLoginLogFactory(const std::string &TableName);
	~CTraderLoginLogFactory(void);

	typedef Idx_Cont_TraderLoginLog Data_Container_Type;
	typedef Idx_Cont_TraderLoginLog Index_Container_Type;

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
	//@param	pTraderLoginLog	  需要被刷新或者新增的CTraderLoginLog,等于NULL表示是需要新增的
	//@param	pNewTraderLoginLog	新的值
	//@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	//@param	updateIndex	  是否需要更新索引
	//@param	新增或者修改后的数据
	CTraderLoginLog* addOrUpdate(CTraderLoginLog *pTraderLoginLog, 
		CWriteableTraderLoginLog *pNewTraderLoginLog, 
		CTransaction *pTransaction = nullptr, bool updateIndex = true);

	//获取某个CTraderLoginLog
	//@param	pTraderLoginLog	要读取的CTraderLoginLog
	//@param	pTragetTraderLoginLog	存放结果的CTraderLoginLog
	void retrieve(CTraderLoginLog *pTraderLoginLog, CWriteableTraderLoginLog *pTargetTraderLoginLog);

	std::size_t getCount(void)
	{
		return count();
	}

	Idx_Cont_TraderLoginLog &getContainer()
	{
		return get_cont();
	}
};


/////////////////////////////////////////////////////////////////////////
//CTraderConnectFactory是一个交易员连接状态的对象工厂。它包含了一批交易员连接状态，
//同时又建立了如下索引，以方便查询：
//	TraderConnectIndex
//	TraderBaseIndex
//	SessionIndex
//使用本对象工厂，可以完成对交易员连接状态的增删改查操作。具体方法如下：
//	增加：叫用add，完成加入
//	删除：叫用remove就可以删除
//	查询：有如下方法可以查询：
//		使用findByTraderID，唯一找到对象
//	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
//	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
//		在retrieve时，也可以指定事务，此时将取出经过update的新数据
/////////////////////////////////////////////////////////////////////////
class CTraderConnectFactory : public COutputTable, public CMemMITable<CTraderConnect, Idx_Cont_TraderConnect>
{
public:
	CTraderConnectFactory(const std::string &TableName);
	~CTraderConnectFactory(void);

	typedef Idx_Cont_TraderConnect Data_Container_Type;
	typedef Idx_Cont_TraderConnect Index_Container_Type;

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
	//@param	pTraderConnect	  需要被刷新或者新增的CTraderConnect,等于NULL表示是需要新增的
	//@param	pNewTraderConnect	新的值
	//@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	//@param	updateIndex	  是否需要更新索引
	//@param	新增或者修改后的数据
	CTraderConnect* addOrUpdate(CTraderConnect *pTraderConnect, CWriteableTraderConnect *pNewTraderConnect, CTransaction *pTransaction = NULL, bool updateIndex = true);

	//获取某个CTraderConnect
	//@param	pTraderConnect	要读取的CTraderConnect
	//@param	pTragetTraderConnect	存放结果的CTraderConnect
	void retrieve(CTraderConnect *pTraderConnect, CWriteableTraderConnect *pTargetTraderConnect);

	std::size_t getCount(void)
	{
		return count();
	}

	Idx_Cont_TraderConnect &getContainer()
	{
		return get_cont();
	}
};

/////////////////////////////////////////////////////////////////////////
//CTraderCertInfoFactory是一个交易员连接的对象工厂。它包含了一批交易员连接，
//同时又建立了如下索引，以方便查询：
//	TraderIDIndex
//使用本对象工厂，可以完成对交易员连接的增删改查操作。具体方法如下：
//	增加：叫用add，完成加入
//	删除：叫用remove就可以删除
//	查询：有如下方法可以查询：
//		使用startFindByTraderID，findNextByTraderID和endFindByTraderID完成查询操作
//	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
//	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
//		在retrieve时，也可以指定事务，此时将取出经过update的新数据
/////////////////////////////////////////////////////////////////////////
class CTraderCertInfoFactory 
	: public COutputTable, public CMemMITable<CTraderCertInfo, Idx_Cont_TraderCertInfo>
{
public:

	CTraderCertInfoFactory(const std::string &TableName);
	~CTraderCertInfoFactory(void);

public:
	typedef Idx_Cont_TraderCertInfo Data_Container_Type;
	typedef Idx_Cont_TraderCertInfo Index_Container_Type;

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
	//@param	pTraderCertInfo	  需要被刷新或者新增的CTraderCertInfo,等于NULL表示是需要新增的
	//@param	pNewTraderCertInfo	新的值
	//@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	//@param	updateIndex	  是否需要更新索引
	//@param	新增或者修改后的数据
	CTraderCertInfo* addOrUpdate(CTraderCertInfo *pTraderCertInfo,
		CWriteableTraderCertInfo *pNewTraderCertInfo,
		CTransaction *pTransaction = NULL, bool updateIndex = true);

	//获取某个CTraderCertInfo
	//@param	pTraderCertInfo	要读取的CTraderCertInfo
	//@param	pTragetTraderCertInfo	存放结果的CTraderCertInfo
	void retrieve(CTraderCertInfo *pTraderCertInfo, CWriteableTraderCertInfo *pTargetTraderCertInfo);

	std::size_t getCount(void)
	{
		return count();
	}

	Idx_Cont_TraderCertInfo &getContainer()
	{
		return get_cont();
	}
};

/////////////////////////////////////////////////////////////////////////
//CUserFactory是一个用户的对象工厂。它包含了一批用户，
//同时又建立了如下索引，以方便查询：
//	UserIDIndex
//使用本对象工厂，可以完成对用户的增删改查操作。具体方法如下：
//	增加：叫用add，完成加入
//	删除：叫用remove就可以删除
//	查询：有如下方法可以查询：
//		使用findByUserID，唯一找到对象
//		使用startFindStartByUserID，findNextStartByUserID和endFindStartByUserID完成查询操作
//	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
//	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
//		在retrieve时，也可以指定事务，此时将取出经过update的新数据
/////////////////////////////////////////////////////////////////////////
class CUserFactory : public COutputTable, public CMemMITable<CUser, Idx_Cont_User>
{
public:
	CUserFactory(const std::string &TableName);
	~CUserFactory(void);

	typedef Idx_Cont_User Data_Container_Type;
	typedef Idx_Cont_User Index_Container_Type;

	//--------------------导入 导出 数据-------------------------------
	int writeCSV(const char *filename);
	int writeCSV(CConfig *pConfig);
	int readCSV(const char *filename);
	int readCSV(CConfig *pConfig);

	//将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	//将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	//清空所有的记录
	void clearAll(void);

	//增加或者更新数据
	//@param	pUser	  需要被刷新或者新增的CUser,等于NULL表示是需要新增的
	//@param	pNewUser	新的值
	//@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	//@param	updateIndex	  是否需要更新索引
	//@param	新增或者修改后的数据
	CUser* addOrUpdate(CUser *pUser, CWriteableUser *pNewUser,
		CTransaction *pTransaction = NULL, bool updateIndex = true);

	//获取某个CUser
	//@param	pUser	要读取的CUser
	//@param	pTragetUser	存放结果的CUser
	void retrieve(CUser *pUser, CWriteableUser *pTargetUser);

	std::size_t getCount(void)
	{
		return count();
	}

	Idx_Cont_User &getContainer()
	{
		return get_cont();
	}
};






#endif
