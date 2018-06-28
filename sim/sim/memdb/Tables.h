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

/////////////////////////////////////////////////////////////////////////
//CUserTraderFactory是一个用户交易员关系表的对象工厂。它包含了一批用户交易员关系表，
//同时又建立了如下索引，以方便查询：
//	TraderUserIDIndex
//	UserIDIndex
//	TraderIDIndex
//使用本对象工厂，可以完成对用户交易员关系表的增删改查操作。具体方法如下：
//	增加：叫用add，完成加入
//	删除：叫用remove就可以删除
//	查询：有如下方法可以查询：
//		使用findByUserID，唯一找到对象
//		使用startFindByTraderID，findNextByTraderID和endFindByTraderID完成查询操作
//	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
//	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
//		在retrieve时，也可以指定事务，此时将取出经过update的新数据
/////////////////////////////////////////////////////////////////////////
class CUserTraderFactory : public COutputTable, public CMemMITable<CUserTrader, Idx_Cont_UserTrader>
{
public:
	CUserTraderFactory(const std::string &TableName);
	~CUserTraderFactory(void);

	typedef Idx_Cont_UserTrader Data_Container_Type;
	typedef Idx_Cont_UserTrader Index_Container_Type;

	//--------------------导入 导出 数据-------------------------------
	int writeCSV(const char *filename);
	int writeCSV(config::CConfig *pConfig);
	int readCSV(const char *filename);
	int readCSV(config::CConfig *pConfig);

	//将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	//将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	std::size_t getCount(void)
	{
		return count();
	}

	Idx_Cont_UserTrader &getContainer()
	{
		return get_cont();
	}

	//清空所有的记录
	void clearAll(void);

	//增加或者更新数据
	//@param	pUserTrader	  需要被刷新或者新增的CUserTrader,等于NULL表示是需要新增的
	//@param	pNewUserTrader	新的值
	//@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	//@param	updateIndex	  是否需要更新索引
	//@param	新增或者修改后的数据
	CUserTrader* addOrUpdate(CUserTrader *pUserTrader, CWriteableUserTrader *pNewUserTrader, CTransaction *pTransaction = NULL, bool updateIndex = true);

	//获取某个CUserTrader
	//@param	pUserTrader	要读取的CUserTrader
	//@param	pTragetUserTrader	存放结果的CUserTrader
	void retrieve(CUserTrader *pUserTrader, CWriteableUserTrader *pTargetUserTrader);
};

/////////////////////////////////////////////////////////////////////////
//CUserFunctionRightFactory是一个用户权限的对象工厂。它包含了一批用户权限，
//同时又建立了如下索引，以方便查询：
//	UserIDIndex
//使用本对象工厂，可以完成对用户权限的增删改查操作。具体方法如下：
//	增加：叫用add，完成加入
//	删除：叫用remove就可以删除
//	查询：有如下方法可以查询：
//		使用findByUserID，唯一找到对象
//		使用startFindStartByUserID，findNextStartByUserID和endFindStartByUserID完成查询操作
//	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
//	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
//		在retrieve时，也可以指定事务，此时将取出经过update的新数据
/////////////////////////////////////////////////////////////////////////
class CUserFunctionRightFactory : public COutputTable, public CMemMITable<CUserFunctionRight, Idx_Cont_UserFunctionRight>
{
public:
	CUserFunctionRightFactory(const std::string &TableName);
	~CUserFunctionRightFactory(void);

	typedef Idx_Cont_UserFunctionRight Data_Container_Type;
	typedef Idx_Cont_UserFunctionRight Index_Container_Type;

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
	//@param	pUserFunctionRight	  需要被刷新或者新增的CUserFunctionRight,等于NULL表示是需要新增的
	//@param	pNewUserFunctionRight	新的值
	//@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	//@param	updateIndex	  是否需要更新索引
	//@param	新增或者修改后的数据
	CUserFunctionRight* addOrUpdate(CUserFunctionRight *pUserFunctionRight,
		CWriteableUserFunctionRight *pNewUserFunctionRight,
		CTransaction *pTransaction = NULL, bool updateIndex = true);

	//获取某个CUserFunctionRight
	//@param	pUserFunctionRight	要读取的CUserFunctionRight
	//@param	pTragetUserFunctionRight	存放结果的CUserFunctionRight
	void retrieve(CUserFunctionRight *pUserFunctionRight,
		CWriteableUserFunctionRight *pTargetUserFunctionRight);

	std::size_t getCount(void)
	{
		return count();
	}
	Idx_Cont_UserFunctionRight &getContainer()
	{
		return get_cont();
	}
};

/////////////////////////////////////////////////////////////////////////
//CSysInfoFactory是一个系统信息的对象工厂。它包含了一批系统信息，
//同时又建立了如下索引，以方便查询：
//	AppIDIndex
//使用本对象工厂，可以完成对系统信息的增删改查操作。具体方法如下：
//	增加：叫用add，完成加入
//	删除：叫用remove就可以删除
//	查询：有如下方法可以查询：
//		使用findByAppID，唯一找到对象
//	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
//	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
//		在retrieve时，也可以指定事务，此时将取出经过update的新数据
/////////////////////////////////////////////////////////////////////////
class CSysInfoFactory : public COutputTable, public CMemMITable<CSysInfo, Idx_Cont_SysInfo>
{
public:
	CSysInfoFactory(const std::string &TableName);
	~CSysInfoFactory(void);

	typedef Idx_Cont_SysInfo Data_Container_Type;
	typedef Idx_Cont_SysInfo Index_Container_Type;

	//--------------------导入 导出 数据-------------------------------
	int writeCSV(const char *filename);
	int writeCSV(config::CConfig *pConfig);
	int readCSV(const char *filename);
	int readCSV(config::CConfig *pConfig);

	//将内容写到文件中,用于DEBUG
	virtual void dump(FILE *);

	//将内容写到文件中,用于DEBUG
	virtual void dump(char *filename);

	std::size_t getCount(void)
	{
		return count();
	}

	Idx_Cont_SysInfo &getContainer()
	{
		return get_cont();
	}

	//清空所有的记录
	void clearAll(void);

	//增加或者更新数据
	//@param	pSysInfo	  需要被刷新或者新增的CSysInfo,等于NULL表示是需要新增的
	//@param	pNewSysInfo	新的值
	//@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	//@param	updateIndex	  是否需要更新索引
	//@param	新增或者修改后的数据
	CSysInfo* addOrUpdate(CSysInfo *pSysInfo, CWriteableSysInfo *pNewSysInfo, CTransaction *pTransaction = NULL, bool updateIndex = true);

	//获取某个CSysInfo
	//@param	pSysInfo	要读取的CSysInfo
	//@param	pTragetSysInfo	存放结果的CSysInfo
	void retrieve(CSysInfo *pSysInfo, CWriteableSysInfo *pTargetSysInfo);
};

/////////////////////////////////////////////////////////////////////////
//CUserSessionFactory是一个交易员在线会话的对象工厂。它包含了一批交易员在线会话，
//同时又建立了如下索引，以方便查询：
//	FrontIDIndex
//	UserIDIndex
//使用本对象工厂，可以完成对交易员在线会话的增删改查操作。具体方法如下：
//	增加：叫用add，完成加入
//	删除：叫用remove就可以删除
//	查询：有如下方法可以查询：
//		使用findBySessionID，唯一找到对象
//		使用startFindByFrontID，findNextByFrontID和endFindByFrontID完成查询操作
//		使用findByUserID，唯一找到对象
//		使用startFindStartByUserID，findNextStartByUserID和endFindStartByUserID完成查询操作
//	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
//	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
//		在retrieve时，也可以指定事务，此时将取出经过update的新数据
/////////////////////////////////////////////////////////////////////////
class CUserSessionFactory 
	: public COutputTable, public CMemMITable<CUserSession, Idx_Cont_UserSession>
{
public:
	CUserSessionFactory(const std::string &TableName);
	~CUserSessionFactory(void);

	typedef Idx_Cont_UserSession Data_Container_Type;
	typedef Idx_Cont_UserSession Index_Container_Type;

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
	//@param	pUserSession	  需要被刷新或者新增的CUserSession,等于NULL表示是需要新增的
	//@param	pNewUserSession	新的值
	//@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	//@param	updateIndex	  是否需要更新索引
	//@param	新增或者修改后的数据
	CUserSession* addOrUpdate(CUserSession *pUserSession, CWriteableUserSession *pNewUserSession,
		CTransaction *pTransaction = nullptr, bool updateIndex = true);

	//获取某个CUserSession
	//@param	pUserSession	要读取的CUserSession
	//@param	pTragetUserSession	存放结果的CUserSession
	void retrieve(CUserSession *pUserSession, CWriteableUserSession *pTargetUserSession);

	std::size_t getCount(void)
	{
		return count();
	}

	Idx_Cont_UserSession &getContainer()
	{
		return get_cont();
	}
};

/////////////////////////////////////////////////////////////////////////
//CMDSessionFactory是一个行情订阅者在线会话的对象工厂。它包含了一批行情订阅者在线会话，
//同时又建立了如下索引，以方便查询：
//	SessionIDIndex
//	UserIndex
//使用本对象工厂，可以完成对行情订阅者在线会话的增删改查操作。具体方法如下：
//	增加：叫用add，完成加入
//	删除：叫用remove就可以删除
//	查询：有如下方法可以查询：
//		使用findBySessionID，唯一找到对象
//		使用findByUserID，唯一找到对象
//	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
//	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
//		在retrieve时，也可以指定事务，此时将取出经过update的新数据
/////////////////////////////////////////////////////////////////////////
class CMDSessionFactory : public COutputTable, public CMemMITable<CMDSession, Idx_Cont_MDSession>
{
public:
	CMDSessionFactory(const std::string &TableName);
	~CMDSessionFactory(void);

	typedef Idx_Cont_MDSession Data_Container_Type;
	typedef Idx_Cont_MDSession Index_Container_Type;

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
	//@param	pMDSession	  需要被刷新或者新增的CMDSession,等于NULL表示是需要新增的
	//@param	pNewMDSession	新的值
	//@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	//@param	updateIndex	  是否需要更新索引
	//@param	新增或者修改后的数据
	CMDSession* addOrUpdate(CMDSession *pMDSession, CWriteableMDSession *pNewMDSession,
		CTransaction *pTransaction = nullptr, bool updateIndex = true);

	//获取某个CMDSession
	//@param	pMDSession	要读取的CMDSession
	//@param	pTragetMDSession	存放结果的CMDSession
	void retrieve(CMDSession *pMDSession, CWriteableMDSession *pTargetMDSession);
	
	std::size_t getCount(void)
	{
		return count();
	}

	Idx_Cont_MDSession &getContainer()
	{
		return get_cont();
	}
};

/////////////////////////////////////////////////////////////////////////
//CMaxLocalIDFactory是一个最大本地报单号的对象工厂。它包含了一批最大本地报单号，
//同时又建立了如下索引，以方便查询：
//	UserIndex
//使用本对象工厂，可以完成对最大本地报单号的增删改查操作。具体方法如下：
//	增加：叫用add，完成加入
//	删除：叫用remove就可以删除
//	查询：有如下方法可以查询：
//		使用findByUserID，唯一找到对象
//	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
//	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
//		在retrieve时，也可以指定事务，此时将取出经过update的新数据
/////////////////////////////////////////////////////////////////////////
class CMaxLocalIDFactory : public COutputTable, public CMemMITable<CMaxLocalID, Idx_Cont_MaxLocalID>
{
public:
	CMaxLocalIDFactory(const std::string &TableName);
	~CMaxLocalIDFactory(void);

	typedef Idx_Cont_MaxLocalID Data_Container_Type;
	typedef Idx_Cont_MaxLocalID Index_Container_Type;

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
	//@param	pMaxLocalID	  需要被刷新或者新增的CMaxLocalID,等于NULL表示是需要新增的
	//@param	pNewMaxLocalID	新的值
	//@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	//@param	updateIndex	  是否需要更新索引
	//@param	新增或者修改后的数据
	CMaxLocalID* addOrUpdate(CMaxLocalID *pMaxLocalID, CWriteableMaxLocalID *pNewMaxLocalID,
		CTransaction *pTransaction = nullptr, bool updateIndex = true);

	//获取某个CMaxLocalID
	//@param	pMaxLocalID	要读取的CMaxLocalID
	//@param	pTragetMaxLocalID	存放结果的CMaxLocalID
	void retrieve(CMaxLocalID *pMaxLocalID, CWriteableMaxLocalID *pTargetMaxLocalID);

	std::size_t getCount(void)
	{
		return count();
	}

	Idx_Cont_MaxLocalID &getContainer()
	{
		return get_cont();
	}
};

/////////////////////////////////////////////////////////////////////////
//CUserSubMarketDataFactory是一个行情订阅的对象工厂。它包含了一批行情订阅，
//同时又建立了如下索引，以方便查询：
//	UserIndex
//	SubMarketDataIndex
//使用本对象工厂，可以完成对行情订阅的增删改查操作。具体方法如下：
//	增加：叫用add，完成加入
//	删除：叫用remove就可以删除
//	查询：有如下方法可以查询：
//		使用findByInstrumentID，唯一找到对象
//		使用findByUserSession，唯一找到对象
//		使用findByUserID，唯一找到对象
//	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
//	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
//		在retrieve时，也可以指定事务，此时将取出经过update的新数据
/////////////////////////////////////////////////////////////////////////
class CUserSubMarketDataFactory 
	: public COutputTable, public CMemMITable<CUserSubMarketData, Idx_Cont_UserSubMarketData>
{
public:
	CUserSubMarketDataFactory(const std::string &TableName);
	~CUserSubMarketDataFactory(void);

	typedef Idx_Cont_UserSubMarketData Data_Container_Type;
	typedef Idx_Cont_UserSubMarketData Index_Container_Type;

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
	//@param	pUserSubMarketData	  需要被刷新或者新增的CUserSubMarketData,等于NULL表示是需要新增的
	//@param	pNewUserSubMarketData	新的值
	//@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	//@param	updateIndex	  是否需要更新索引
	//@param	新增或者修改后的数据
	CUserSubMarketData* addOrUpdate(CUserSubMarketData *pUserSubMarketData,
		CWriteableUserSubMarketData *pNewUserSubMarketData,
		CTransaction *pTransaction = nullptr, bool updateIndex = true);

	//获取某个CUserSubMarketData
	//@param	pUserSubMarketData	要读取的CUserSubMarketData
	//@param	pTragetUserSubMarketData	存放结果的CUserSubMarketData
	void retrieve(CUserSubMarketData *pUserSubMarketData,
		CWriteableUserSubMarketData *pTargetUserSubMarketData);

	std::size_t getCount(void)
	{
		return count();
	}

	Idx_Cont_UserSubMarketData &getContainer()
	{
		return get_cont();
	}
};

/////////////////////////////////////////////////////////////////////////
//CDepthMarketDataFactory是一个深度行情的对象工厂。它包含了一批深度行情，
//同时又建立了如下索引，以方便查询：
//	InstrumentIDIndex
//使用本对象工厂，可以完成对深度行情的增删改查操作。具体方法如下：
//	增加：叫用add，完成加入
//	删除：叫用remove就可以删除
//	查询：有如下方法可以查询：
//		使用findByInstrumentID，唯一找到对象
//	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
//	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
//		在retrieve时，也可以指定事务，此时将取出经过update的新数据
/////////////////////////////////////////////////////////////////////////
class CDepthMarketDataFactory 
	: public COutputTable, public CMemMITable<CDepthMarketData, Idx_Cont_DepthMarketData>
{
public:
	CDepthMarketDataFactory(const std::string &TableName);
	~CDepthMarketDataFactory(void);

	typedef Idx_Cont_DepthMarketData Data_Container_Type;
	typedef Idx_Cont_DepthMarketData Index_Container_Type;

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
	//@param	pDepthMarketData	  需要被刷新或者新增的CDepthMarketData,等于NULL表示是需要新增的
	//@param	pNewDepthMarketData	新的值
	//@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	//@param	updateIndex	  是否需要更新索引
	//@param	新增或者修改后的数据
	CDepthMarketData* addOrUpdate(CDepthMarketData *pDepthMarketData, CWriteableDepthMarketData *pNewDepthMarketData, CTransaction *pTransaction = NULL, bool updateIndex = true);

	//获取某个CDepthMarketData
	//@param	pDepthMarketData	要读取的CDepthMarketData
	//@param	pTragetDepthMarketData	存放结果的CDepthMarketData
	void retrieve(CDepthMarketData *pDepthMarketData,
		CWriteableDepthMarketData *pTargetDepthMarketData);

	std::size_t getCount(void)
	{
		return count();
	}

	Idx_Cont_DepthMarketData &getContainer()
	{
		return get_cont();
	}
};

/////////////////////////////////////////////////////////////////////////
//CCommodityFactory是一个商品的对象工厂。它包含了一批商品，
//同时又建立了如下索引，以方便查询：
//	CommodityIDIndex
//使用本对象工厂，可以完成对商品的增删改查操作。具体方法如下：
//	增加：叫用add，完成加入
//	删除：叫用remove就可以删除
//	查询：有如下方法可以查询：
//		使用findByCommodityID，唯一找到对象
//	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
//	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
//		在retrieve时，也可以指定事务，此时将取出经过update的新数据
/////////////////////////////////////////////////////////////////////////
class CCommodityFactory 
	: public COutputTable, public CMemMITable<CCommodity, Idx_Cont_Commodity>
{
public:
	CCommodityFactory(const std::string &TableName);
	~CCommodityFactory(void);

	typedef Idx_Cont_Commodity Data_Container_Type;
	typedef Idx_Cont_Commodity Index_Container_Type;

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
	//@param	pCommodity	  需要被刷新或者新增的CCommodity,等于NULL表示是需要新增的
	//@param	pNewCommodity	新的值
	//@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	//@param	updateIndex	  是否需要更新索引
	//@param	新增或者修改后的数据
	CCommodity* addOrUpdate(CCommodity *pCommodity, CWriteableCommodity *pNewCommodity,
		CTransaction *pTransaction = nullptr, bool updateIndex = true);

	//获取某个CCommodity
	//@param	pCommodity	要读取的CCommodity
	//@param	pTragetCommodity	存放结果的CCommodity
	void retrieve(CCommodity *pCommodity, CWriteableCommodity *pTargetCommodity);

	std::size_t getCount(void)
	{
		return count();
	}

	Idx_Cont_Commodity &getContainer()
	{
		return get_cont();
	}
};

/////////////////////////////////////////////////////////////////////////
//CInstrumentFactory是一个合约的对象工厂。它包含了一批合约，
//同时又建立了如下索引，以方便查询：
//	InstrumentIDIndex
//	CommodityIDIndex
//	ExchInstrumentIDIndex
//使用本对象工厂，可以完成对合约的增删改查操作。具体方法如下：
//	增加：叫用add，完成加入
//	删除：叫用remove就可以删除
//	查询：有如下方法可以查询：
//		使用findByInstrumentID，唯一找到对象
//	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
//	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
//		在retrieve时，也可以指定事务，此时将取出经过update的新数据
/////////////////////////////////////////////////////////////////////////
class CInstrumentFactory 
	: public COutputTable, public CMemMITable<CInstrument, Idx_Cont_Instrument>
{
public:
	CInstrumentFactory(const std::string &TableName);
	~CInstrumentFactory(void);

	typedef Idx_Cont_Instrument Data_Container_Type;
	typedef Idx_Cont_Instrument Index_Container_Type;

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
	//@param	pInstrument	  需要被刷新或者新增的CInstrument,等于NULL表示是需要新增的
	//@param	pNewInstrument	新的值
	//@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	//@param	updateIndex	  是否需要更新索引
	//@param	新增或者修改后的数据
	CInstrument* addOrUpdate(CInstrument *pInstrument, CWriteableInstrument *pNewInstrument,
		CTransaction *pTransaction = nullptr, bool updateIndex = true);

	//获取某个CInstrument
	//@param	pInstrument	要读取的CInstrument
	//@param	pTragetInstrument	存放结果的CInstrument
	void retrieve(CInstrument *pInstrument, CWriteableInstrument *pTargetInstrument);

	std::size_t getCount(void)
	{
		return count();
	}

	Idx_Cont_Instrument &getContainer()
	{
		return get_cont();
	}
};

/////////////////////////////////////////////////////////////////////////
//COrderActionFactory是一个合约修改的对象工厂。它包含了一批合约修改，
//同时又建立了如下索引，以方便查询：
//	InnerIDIndex
//	SysIDIndex
//使用本对象工厂，可以完成对合约修改的增删改查操作。具体方法如下：
//	增加：叫用add，完成加入
//	删除：叫用remove就可以删除
//	查询：有如下方法可以查询：
//	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
//	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
//		在retrieve时，也可以指定事务，此时将取出经过update的新数据
/////////////////////////////////////////////////////////////////////////
class COrderActionFactory 
	: public COutputTable, public CMemMITable<COrderAction, Idx_Cont_OrderAction>
{
public:
	COrderActionFactory(const std::string &TableName);
	~COrderActionFactory(void);

	typedef Idx_Cont_OrderAction Data_Container_Type;
	typedef Idx_Cont_OrderAction Index_Container_Type;

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
	//@param	pOrderAction	  需要被刷新或者新增的COrderAction,等于NULL表示是需要新增的
	//@param	pNewOrderAction	新的值
	//@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	//@param	updateIndex	  是否需要更新索引
	//@param	新增或者修改后的数据
	COrderAction* addOrUpdate(COrderAction *pOrderAction,
		CWriteableOrderAction *pNewOrderAction, CTransaction *pTransaction = nullptr,
		bool updateIndex = true);

	//获取某个COrderAction
	//@param	pOrderAction	要读取的COrderAction
	//@param	pTragetOrderAction	存放结果的COrderAction
	void retrieve(COrderAction *pOrderAction, CWriteableOrderAction *pTargetOrderAction);

	std::size_t getCount(void)
	{
		return count();
	}

	Idx_Cont_OrderAction &getContainer()
	{
		return get_cont();
	}
};

/////////////////////////////////////////////////////////////////////////
//CExchOrderActionFactory是一个合约修改的对象工厂。它包含了一批合约修改，
//同时又建立了如下索引，以方便查询：
//	InnerIDIndex
//	SysIDIndex
//使用本对象工厂，可以完成对合约修改的增删改查操作。具体方法如下：
//	增加：叫用add，完成加入
//	删除：叫用remove就可以删除
//	查询：有如下方法可以查询：
//		使用findByInstrumentID，唯一找到对象
//	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
//	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
//		在retrieve时，也可以指定事务，此时将取出经过update的新数据
/////////////////////////////////////////////////////////////////////////
class CExchOrderActionFactory 
	: public COutputTable, public CMemMITable<CExchOrderAction, Idx_Cont_ExchOrderAction>
{
public:
	CExchOrderActionFactory(const std::string &TableName);
	~CExchOrderActionFactory(void);

	typedef Idx_Cont_ExchOrderAction Data_Container_Type;
	typedef Idx_Cont_ExchOrderAction Index_Container_Type;

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
	//@param	pExchOrderAction	  需要被刷新或者新增的CExchOrderAction,等于NULL表示是需要新增的
	//@param	pNewExchOrderAction	新的值
	//@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	//@param	updateIndex	  是否需要更新索引
	//@param	新增或者修改后的数据
	CExchOrderAction* addOrUpdate(CExchOrderAction *pExchOrderAction,
		CWriteableExchOrderAction *pNewExchOrderAction,
		CTransaction *pTransaction = nullptr, bool updateIndex = true);

	//获取某个CExchOrderAction
	//@param	pExchOrderAction	要读取的CExchOrderAction
	//@param	pTragetExchOrderAction	存放结果的CExchOrderAction
	void retrieve(CExchOrderAction *pExchOrderAction,
		CWriteableExchOrderAction *pTargetExchOrderAction);

	std::size_t getCount(void)
	{
		return count();
	}

	Idx_Cont_ExchOrderAction &getContainer()
	{
		return get_cont();
	}
};

/////////////////////////////////////////////////////////////////////////
//COrderFactory是一个报单的对象工厂。它包含了一批报单，
//同时又建立了如下索引，以方便查询：
//	InnerIDIndex
//	OrderSysIDIndex
//	InstrumentIDIndex
//	OrderRefIndex
//使用本对象工厂，可以完成对报单的增删改查操作。具体方法如下：
//	增加：叫用add，完成加入
//	删除：叫用remove就可以删除
//	查询：有如下方法可以查询：
//		使用findByOrderID，唯一找到对象
//		使用findByOrderLocalID，唯一找到对象
//		使用startFindByUserID，findNextByUserID和endFindByUserID完成查询操作
//		使用startFindByInstrumentID，findNextByInstrumentID和endFindByInstrumentID完成查询操作
//		使用startFindStartByInstrumentID，findNextStartByInstrumentID和endFindStartByInstrumentID完成查询操作
//		使用startFindByOrderRef，findNextByOrderRef和endFindByOrderRef完成查询操作
//	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
//	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
//		在retrieve时，也可以指定事务，此时将取出经过update的新数据
/////////////////////////////////////////////////////////////////////////
class COrderFactory : public COutputTable, public CMemMITable<COrder, Idx_Cont_Order>
{
public:
	COrderFactory(const std::string &TableName);
	~COrderFactory(void);

	typedef Idx_Cont_Order Data_Container_Type;
	typedef Idx_Cont_Order Index_Container_Type;

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
	//@param	pOrder	  需要被刷新或者新增的COrder,等于NULL表示是需要新增的
	//@param	pNewOrder	新的值
	//@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	//@param	updateIndex	  是否需要更新索引
	//@param	新增或者修改后的数据
	COrder* addOrUpdate(COrder *pOrder, CWriteableOrder *pNewOrder,
		CTransaction *pTransaction = nullptr, bool updateIndex = true);

	//获取某个COrder
	//@param	pOrder	要读取的COrder
	//@param	pTragetOrder	存放结果的COrder
	void retrieve(COrder *pOrder, CWriteableOrder *pTargetOrder);

	std::size_t getCount(void)
	{
		return count();
	}

	Idx_Cont_Order &getContainer()
	{
		return get_cont();
	}
};

/////////////////////////////////////////////////////////////////////////
//CTradeFactory是一个成交的对象工厂。它包含了一批成交，
//同时又建立了如下索引，以方便查询：
//	TradeIDIndex
//	InstrumentIDIndex
//使用本对象工厂，可以完成对成交的增删改查操作。具体方法如下：
//	增加：叫用add，完成加入
//	删除：叫用remove就可以删除
//	查询：有如下方法可以查询：
//		使用startFindStartByTradeID，findNextStartByTradeID和endFindStartByTradeID完成查询操作
//		使用startFindStartByInstrumentID，findNextStartByInstrumentID和endFindStartByInstrumentID完成查询操作
//	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
//	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
//		在retrieve时，也可以指定事务，此时将取出经过update的新数据
/////////////////////////////////////////////////////////////////////////
class CTradeFactory : public COutputTable, public CMemMITable<CTrade, Idx_Cont_Trade>
{
public:
	CTradeFactory(const std::string &TableName);
	~CTradeFactory(void);

	typedef Idx_Cont_Trade Data_Container_Type;
	typedef Idx_Cont_Trade Index_Container_Type;

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
	//@param	pTrade	  需要被刷新或者新增的CTrade,等于NULL表示是需要新增的
	//@param	pNewTrade	新的值
	//@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	//@param	updateIndex	  是否需要更新索引
	//@param	新增或者修改后的数据
	CTrade* addOrUpdate(CTrade *pTrade, CWriteableTrade *pNewTrade,
		CTransaction *pTransaction = nullptr, bool updateIndex = true);

	//获取某个CTrade
	//@param	pTrade	要读取的CTrade
	//@param	pTragetTrade	存放结果的CTrade
	void retrieve(CTrade *pTrade, CWriteableTrade *pTargetTrade);

	std::size_t getCount(void)
	{
		return count();
	}

	Idx_Cont_Trade &getContainer()
	{
		return get_cont();
	}
};

/////////////////////////////////////////////////////////////////////////
//CEsfInstPartInfoFactory是一个合约部分信息的对象工厂。它包含了一批合约部分信息，
//同时又建立了如下索引，以方便查询：
//	InstrumentIDIndex
//使用本对象工厂，可以完成对合约部分信息的增删改查操作。具体方法如下：
//	增加：叫用add，完成加入
//	删除：叫用remove就可以删除
//	查询：有如下方法可以查询：
//	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
//	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
//		在retrieve时，也可以指定事务，此时将取出经过update的新数据
/////////////////////////////////////////////////////////////////////////
class CEsfInstPartInfoFactory 
	: public COutputTable, public CMemMITable<CEsfInstPartInfo, Idx_Cont_EsfInstPartInfo>
{
public:
	CEsfInstPartInfoFactory(const std::string &TableName);
	~CEsfInstPartInfoFactory(void);

	typedef Idx_Cont_EsfInstPartInfo Data_Container_Type;
	typedef Idx_Cont_EsfInstPartInfo Index_Container_Type;

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
	//@param	pEsfInstPartInfo	  需要被刷新或者新增的CEsfInstPartInfo,等于NULL表示是需要新增的
	//@param	pNewEsfInstPartInfo	新的值
	//@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	//@param	updateIndex	  是否需要更新索引
	//@param	新增或者修改后的数据
	CEsfInstPartInfo* addOrUpdate(CEsfInstPartInfo *pEsfInstPartInfo,
		CWriteableEsfInstPartInfo *pNewEsfInstPartInfo,
		CTransaction *pTransaction = nullptr, bool updateIndex = true);

	//获取某个CEsfInstPartInfo
	//@param	pEsfInstPartInfo	要读取的CEsfInstPartInfo
	//@param	pTragetEsfInstPartInfo	存放结果的CEsfInstPartInfo
	void retrieve(CEsfInstPartInfo *pEsfInstPartInfo,
		CWriteableEsfInstPartInfo *pTargetEsfInstPartInfo);

	std::size_t getCount(void)
	{
		return count();
	}

	Idx_Cont_EsfInstPartInfo &getContainer()
	{
		return get_cont();
	}
};

/////////////////////////////////////////////////////////////////////////
//CCurrencyFactory是一个币种信息的对象工厂。它包含了一批币种信息，
//同时又建立了如下索引，以方便查询：
//	CurrencyIDIndex
//使用本对象工厂，可以完成对币种信息的增删改查操作。具体方法如下：
//	增加：叫用add，完成加入
//	删除：叫用remove就可以删除
//	查询：有如下方法可以查询：
//	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
//	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
//		在retrieve时，也可以指定事务，此时将取出经过update的新数据
/////////////////////////////////////////////////////////////////////////
class CCurrencyFactory : public COutputTable, public CMemMITable<CCurrency, Idx_Cont_Currency>
{
public:
	CCurrencyFactory(const std::string &TableName);
	~CCurrencyFactory(void);

	typedef Idx_Cont_Currency Data_Container_Type;
	typedef Idx_Cont_Currency Index_Container_Type;

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
	//@param	pCurrency	  需要被刷新或者新增的CCurrency,等于NULL表示是需要新增的
	//@param	pNewCurrency	新的值
	//@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	//@param	updateIndex	  是否需要更新索引
	//@param	新增或者修改后的数据
	CCurrency* addOrUpdate(CCurrency *pCurrency, CWriteableCurrency *pNewCurrency,
		CTransaction *pTransaction = nullptr, bool updateIndex = true);

	//获取某个CCurrency
	//@param	pCurrency	要读取的CCurrency
	//@param	pTragetCurrency	存放结果的CCurrency
	void retrieve(CCurrency *pCurrency, CWriteableCurrency *pTargetCurrency);

	std::size_t getCount(void)
	{
		return count();
	}

	Idx_Cont_Currency &getContainer()
	{
		return get_cont();
	}
};

/////////////////////////////////////////////////////////////////////////
//CExchUserLoginFactory是一个交易用户登录的对象工厂。它包含了一批交易用户登录，
//同时又建立了如下索引，以方便查询：
//	TradeUserIDIndex
//使用本对象工厂，可以完成对交易用户登录的增删改查操作。具体方法如下：
//	增加：叫用add，完成加入
//	删除：叫用remove就可以删除
//	查询：有如下方法可以查询：
//		使用findByUserID，唯一找到对象
//	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
//	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
//		在retrieve时，也可以指定事务，此时将取出经过update的新数据
/////////////////////////////////////////////////////////////////////////
class CExchUserLoginFactory : public COutputTable, public CMemMITable<CExchUserLogin, Idx_Cont_ExchUserLogin>
{
public:
	CExchUserLoginFactory(const std::string &TableName);
	~CExchUserLoginFactory(void);

	typedef Idx_Cont_ExchUserLogin Data_Container_Type;
	typedef Idx_Cont_ExchUserLogin Index_Container_Type;

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
	//@param	pExchUserLogin	  需要被刷新或者新增的CExchUserLogin,等于NULL表示是需要新增的
	//@param	pNewExchUserLogin	新的值
	//@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	//@param	updateIndex	  是否需要更新索引
	//@param	新增或者修改后的数据
	CExchUserLogin* addOrUpdate(CExchUserLogin *pExchUserLogin,
		CWriteableExchUserLogin *pNewExchUserLogin,
		CTransaction *pTransaction = nullptr, bool updateIndex = true);

	//获取某个CExchUserLogin
	//@param	pExchUserLogin	要读取的CExchUserLogin
	//@param	pTragetExchUserLogin	存放结果的CExchUserLogin
	void retrieve(CExchUserLogin *pExchUserLogin,
		CWriteableExchUserLogin *pTargetExchUserLogin);

	std::size_t getCount(void)
	{
		return count();
	}

	Idx_Cont_ExchUserLogin &getContainer()
	{
		return get_cont();
	}
};

/////////////////////////////////////////////////////////////////////////
//CExchUserLogoutFactory是一个交易用户登出的对象工厂。它包含了一批交易用户登出，
//同时又建立了如下索引，以方便查询：
//	TradeUserIDIndex
//使用本对象工厂，可以完成对交易用户登出的增删改查操作。具体方法如下：
//	增加：叫用add，完成加入
//	删除：叫用remove就可以删除
//	查询：有如下方法可以查询：
//		使用findByUserID，唯一找到对象
//	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
//	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
//		在retrieve时，也可以指定事务，此时将取出经过update的新数据
/////////////////////////////////////////////////////////////////////////
class CExchUserLogoutFactory : public COutputTable, public CMemMITable<CExchUserLogout, Idx_Cont_ExchUserLogout>
{
public:
	CExchUserLogoutFactory(const std::string &TableName);
	~CExchUserLogoutFactory(void);

	typedef Idx_Cont_ExchUserLogout Data_Container_Type;
	typedef Idx_Cont_ExchUserLogout Index_Container_Type;

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
	//@param	pExchUserLogout	  需要被刷新或者新增的CExchUserLogout,等于NULL表示是需要新增的
	//@param	pNewExchUserLogout	新的值
	//@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	//@param	updateIndex	  是否需要更新索引
	//@param	新增或者修改后的数据
	CExchUserLogout* addOrUpdate(CExchUserLogout *pExchUserLogout,
		CWriteableExchUserLogout *pNewExchUserLogout,
		CTransaction *pTransaction = nullptr, bool updateIndex = true);

	//获取某个CExchUserLogout
	//@param	pExchUserLogout	要读取的CExchUserLogout
	//@param	pTragetExchUserLogout	存放结果的CExchUserLogout
	void retrieve(CExchUserLogout *pExchUserLogout,
		CWriteableExchUserLogout *pTargetExchUserLogout);

	std::size_t getCount(void)
	{
		return count();
	}

	Idx_Cont_ExchUserLogout &getContainer()
	{
		return get_cont();
	}
};

/////////////////////////////////////////////////////////////////////////
//CExchMDUserLoginFactory是一个行情用户登录的对象工厂。它包含了一批行情用户登录，
//同时又建立了如下索引，以方便查询：
//	MDUserIDIndex
//使用本对象工厂，可以完成对行情用户登录的增删改查操作。具体方法如下：
//	增加：叫用add，完成加入
//	删除：叫用remove就可以删除
//	查询：有如下方法可以查询：
//		使用findByUserID，唯一找到对象
//	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
//	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
//		在retrieve时，也可以指定事务，此时将取出经过update的新数据
/////////////////////////////////////////////////////////////////////////
class CExchMDUserLoginFactory : public COutputTable, public CMemMITable<CExchMDUserLogin, Idx_Cont_ExchMDUserLogin>
{
public:
	CExchMDUserLoginFactory(const std::string &TableName);
	~CExchMDUserLoginFactory(void);

	typedef Idx_Cont_ExchMDUserLogin Data_Container_Type;
	typedef Idx_Cont_ExchMDUserLogin Index_Container_Type;

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
	//@param	pExchMDUserLogin	  需要被刷新或者新增的CExchMDUserLogin,等于NULL表示是需要新增的
	//@param	pNewExchMDUserLogin	新的值
	//@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	//@param	updateIndex	  是否需要更新索引
	//@param	新增或者修改后的数据
	CExchMDUserLogin* addOrUpdate(CExchMDUserLogin *pExchMDUserLogin,
		CWriteableExchMDUserLogin *pNewExchMDUserLogin,
		CTransaction *pTransaction = nullptr, bool updateIndex = true);

	//获取某个CExchMDUserLogin
	//@param	pExchMDUserLogin	要读取的CExchMDUserLogin
	//@param	pTragetExchMDUserLogin	存放结果的CExchMDUserLogin
	void retrieve(CExchMDUserLogin *pExchMDUserLogin,
		CWriteableExchMDUserLogin *pTargetExchMDUserLogin);

	std::size_t getCount(void)
	{
		return count();
	}

	Idx_Cont_ExchMDUserLogin &getContainer()
	{
		return get_cont();
	}
};

/////////////////////////////////////////////////////////////////////////
//CExchMDUserLogoutFactory是一个行情用户登出的对象工厂。它包含了一批行情用户登出，
//同时又建立了如下索引，以方便查询：
//	MDUserIDIndex
//使用本对象工厂，可以完成对行情用户登出的增删改查操作。具体方法如下：
//	增加：叫用add，完成加入
//	删除：叫用remove就可以删除
//	查询：有如下方法可以查询：
//		使用findByUserID，唯一找到对象
//	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
//	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
//		在retrieve时，也可以指定事务，此时将取出经过update的新数据
/////////////////////////////////////////////////////////////////////////
class CExchMDUserLogoutFactory : public COutputTable, public CMemMITable<CExchMDUserLogout, Idx_Cont_ExchMDUserLogout>
{
public:
	CExchMDUserLogoutFactory(const std::string &TableName);
	~CExchMDUserLogoutFactory(void);

	typedef Idx_Cont_ExchMDUserLogout Data_Container_Type;
	typedef Idx_Cont_ExchMDUserLogout Index_Container_Type;

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
	//@param	pExchMDUserLogout	  需要被刷新或者新增的CExchMDUserLogout,等于NULL表示是需要新增的
	//@param	pNewExchMDUserLogout	新的值
	//@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	//@param	updateIndex	  是否需要更新索引
	//@param	新增或者修改后的数据
	CExchMDUserLogout* addOrUpdate(CExchMDUserLogout *pExchMDUserLogout,
		CWriteableExchMDUserLogout *pNewExchMDUserLogout,
		CTransaction *pTransaction = nullptr, bool updateIndex = true);

	//获取某个CExchMDUserLogout
	//@param	pExchMDUserLogout	要读取的CExchMDUserLogout
	//@param	pTragetExchMDUserLogout	存放结果的CExchMDUserLogout
	void retrieve(CExchMDUserLogout *pExchMDUserLogout,
		CWriteableExchMDUserLogout *pTargetExchMDUserLogout);

	std::size_t getCount(void)
	{
		return count();
	}

	Idx_Cont_ExchMDUserLogout &getContainer()
	{
		return get_cont();
	}
};

/////////////////////////////////////////////////////////////////////////
//CExchOrderFactory是一个报单的对象工厂。它包含了一批报单，
//同时又建立了如下索引，以方便查询：
//	InnerIDIndex
//	OrderSysIDIndex
//使用本对象工厂，可以完成对报单的增删改查操作。具体方法如下：
//	增加：叫用add，完成加入
//	删除：叫用remove就可以删除
//	查询：有如下方法可以查询：
//		使用findByOrderID，唯一找到对象
//		使用findByOrderLocalID，唯一找到对象
//		使用startFindByUserID，findNextByUserID和endFindByUserID完成查询操作
//		使用startFindByInstrumentID，findNextByInstrumentID和endFindByInstrumentID完成查询操作
//		使用startFindStartByInstrumentID，findNextStartByInstrumentID和endFindStartByInstrumentID完成查询操作
//	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
//	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
//		在retrieve时，也可以指定事务，此时将取出经过update的新数据
/////////////////////////////////////////////////////////////////////////
class CExchOrderFactory : public COutputTable, public CMemMITable<CExchOrder, Idx_Cont_ExchOrder>
{
public:
	CExchOrderFactory(const std::string &TableName);
	~CExchOrderFactory(void);

	typedef Idx_Cont_ExchOrder Data_Container_Type;
	typedef Idx_Cont_ExchOrder Index_Container_Type;

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
	//@param	pExchOrder	  需要被刷新或者新增的CExchOrder,等于NULL表示是需要新增的
	//@param	pNewExchOrder	新的值
	//@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	//@param	updateIndex	  是否需要更新索引
	//@param	新增或者修改后的数据
	CExchOrder* addOrUpdate(CExchOrder *pExchOrder, CWriteableExchOrder *pNewExchOrder,
		CTransaction *pTransaction = nullptr, bool updateIndex = true);

	//获取某个CExchOrder
	//@param	pExchOrder	要读取的CExchOrder
	//@param	pTragetExchOrder	存放结果的CExchOrder
	void retrieve(CExchOrder *pExchOrder, CWriteableExchOrder *pTargetExchOrder);

	std::size_t getCount(void)
	{
		return count();
	}

	Idx_Cont_ExchOrder &getContainer()
	{
		return get_cont();
	}
};

/////////////////////////////////////////////////////////////////////////
//CExchTradeFactory是一个成交的对象工厂。它包含了一批成交，
//同时又建立了如下索引，以方便查询：
//	TradeIDIndex
//	InstrumentIDIndex
//使用本对象工厂，可以完成对成交的增删改查操作。具体方法如下：
//	增加：叫用add，完成加入
//	删除：叫用remove就可以删除
//	查询：有如下方法可以查询：
//		使用startFindStartByTradeID，findNextStartByTradeID和endFindStartByTradeID完成查询操作
//		使用startFindStartByInstrumentID，findNextStartByInstrumentID和endFindStartByInstrumentID完成查询操作
//	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
//	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
//		在retrieve时，也可以指定事务，此时将取出经过update的新数据
/////////////////////////////////////////////////////////////////////////
class CExchTradeFactory : public COutputTable, public CMemMITable<CExchTrade, Idx_Cont_ExchTrade>
{
public:
	CExchTradeFactory(const std::string &TableName);
	~CExchTradeFactory(void);

	typedef Idx_Cont_ExchTrade Data_Container_Type;
	typedef Idx_Cont_ExchTrade Index_Container_Type;

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
	//@param	pExchTrade	  需要被刷新或者新增的CExchTrade,等于NULL表示是需要新增的
	//@param	pNewExchTrade	新的值
	//@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	//@param	updateIndex	  是否需要更新索引
	//@param	新增或者修改后的数据
	CExchTrade* addOrUpdate(CExchTrade *pExchTrade, CWriteableExchTrade *pNewExchTrade,
		CTransaction *pTransaction = nullptr, bool updateIndex = true);

	//获取某个CExchTrade
	//@param	pExchTrade	要读取的CExchTrade
	//@param	pTragetExchTrade	存放结果的CExchTrade
	void retrieve(CExchTrade *pExchTrade, CWriteableExchTrade *pTargetExchTrade);

	std::size_t getCount(void)
	{
		return count();
	}

	Idx_Cont_ExchTrade &getContainer()
	{
		return get_cont();
	}
};

/////////////////////////////////////////////////////////////////////////
//CExchInvestorPositionFactory是一个投资者仓位的对象工厂。它包含了一批投资者仓位，
//同时又建立了如下索引，以方便查询：
//	InvestorIDIndex
//使用本对象工厂，可以完成对投资者仓位的增删改查操作。具体方法如下：
//	增加：叫用add，完成加入
//	删除：叫用remove就可以删除
//	查询：有如下方法可以查询：
//		使用findByInvestorID，唯一找到对象
//	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
//	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
//		在retrieve时，也可以指定事务，此时将取出经过update的新数据
/////////////////////////////////////////////////////////////////////////
class CExchInvestorPositionFactory : public COutputTable, public CMemMITable<CExchInvestorPosition, Idx_Cont_ExchInvestorPosition>
{
public:
	CExchInvestorPositionFactory(const std::string &TableName);
	~CExchInvestorPositionFactory(void);

	typedef Idx_Cont_ExchInvestorPosition Data_Container_Type;
	typedef Idx_Cont_ExchInvestorPosition Index_Container_Type;

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
	//@param	pExchInvestorPosition	  需要被刷新或者新增的CExchInvestorPosition,等于NULL表示是需要新增的
	//@param	pNewExchInvestorPosition	新的值
	//@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	//@param	updateIndex	  是否需要更新索引
	//@param	新增或者修改后的数据
	CExchInvestorPosition* addOrUpdate(CExchInvestorPosition *pExchInvestorPosition,
		CWriteableExchInvestorPosition *pNewExchInvestorPosition,
		CTransaction *pTransaction = nullptr, bool updateIndex = true);

	//获取某个CExchInvestorPosition
	//@param	pExchInvestorPosition	要读取的CExchInvestorPosition
	//@param	pTragetExchInvestorPosition	存放结果的CExchInvestorPosition
	void retrieve(CExchInvestorPosition *pExchInvestorPosition,
		CWriteableExchInvestorPosition *pTargetExchInvestorPosition);

	std::size_t getCount(void)
	{
		return count();
	}

	Idx_Cont_ExchInvestorPosition &getContainer()
	{
		return get_cont();
	}
};

/////////////////////////////////////////////////////////////////////////
//CExchInvestorAccountFactory是一个投资者资金的对象工厂。它包含了一批投资者资金，
//同时又建立了如下索引，以方便查询：
//	InvestorIDIndex
//使用本对象工厂，可以完成对投资者资金的增删改查操作。具体方法如下：
//	增加：叫用add，完成加入
//	删除：叫用remove就可以删除
//	查询：有如下方法可以查询：
//		使用findByInvestorID，唯一找到对象
//	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
//	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
//		在retrieve时，也可以指定事务，此时将取出经过update的新数据
/////////////////////////////////////////////////////////////////////////
class CExchInvestorAccountFactory 
	: public COutputTable, public CMemMITable<CExchInvestorAccount, Idx_Cont_ExchInvestorAccount>
{
public:
	CExchInvestorAccountFactory(const std::string &TableName);
	~CExchInvestorAccountFactory(void);

	typedef Idx_Cont_ExchInvestorAccount Data_Container_Type;
	typedef Idx_Cont_ExchInvestorAccount Index_Container_Type;

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
	//@param	pExchInvestorAccount	  需要被刷新或者新增的CExchInvestorAccount,等于NULL表示是需要新增的
	//@param	pNewExchInvestorAccount	新的值
	//@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	//@param	updateIndex	  是否需要更新索引
	//@param	新增或者修改后的数据
	CExchInvestorAccount* addOrUpdate(CExchInvestorAccount *pExchInvestorAccount,
		CWriteableExchInvestorAccount *pNewExchInvestorAccount,
		CTransaction *pTransaction = nullptr, bool updateIndex = true);

	//获取某个CExchInvestorAccount
	//@param	pExchInvestorAccount	要读取的CExchInvestorAccount
	//@param	pTragetExchInvestorAccount	存放结果的CExchInvestorAccount
	void retrieve(CExchInvestorAccount *pExchInvestorAccount,
		CWriteableExchInvestorAccount *pTargetExchInvestorAccount);

	std::size_t getCount(void)
	{
		return count();
	}

	Idx_Cont_ExchInvestorAccount &getContainer()
	{
		return get_cont();
	}
};

/////////////////////////////////////////////////////////////////////////
//CExchDepthMarketDataFactory是一个深度行情的对象工厂。它包含了一批深度行情，
//同时又建立了如下索引，以方便查询：
//	InstrumentIDIndex
//使用本对象工厂，可以完成对深度行情的增删改查操作。具体方法如下：
//	增加：叫用add，完成加入
//	删除：叫用remove就可以删除
//	查询：有如下方法可以查询：
//		使用findByInstrumentID，唯一找到对象
//	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
//	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
//		在retrieve时，也可以指定事务，此时将取出经过update的新数据
/////////////////////////////////////////////////////////////////////////
class CExchDepthMarketDataFactory : public COutputTable, public CMemMITable<CExchDepthMarketData, Idx_Cont_ExchDepthMarketData>
{
public:
	CExchDepthMarketDataFactory(const std::string &TableName);
	~CExchDepthMarketDataFactory(void);

	typedef Idx_Cont_ExchDepthMarketData Data_Container_Type;
	typedef Idx_Cont_ExchDepthMarketData Index_Container_Type;

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
	//@param	pExchDepthMarketData	  需要被刷新或者新增的CExchDepthMarketData,等于NULL表示是需要新增的
	//@param	pNewExchDepthMarketData	新的值
	//@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	//@param	updateIndex	  是否需要更新索引
	//@param	新增或者修改后的数据
	CExchDepthMarketData* addOrUpdate(CExchDepthMarketData *pExchDepthMarketData,
		CWriteableExchDepthMarketData *pNewExchDepthMarketData,
		CTransaction *pTransaction = nullptr, bool updateIndex = true);

	//获取某个CExchDepthMarketData
	//@param	pExchDepthMarketData	要读取的CExchDepthMarketData
	//@param	pTragetExchDepthMarketData	存放结果的CExchDepthMarketData
	void retrieve(CExchDepthMarketData *pExchDepthMarketData,
		CWriteableExchDepthMarketData *pTargetExchDepthMarketData);

	std::size_t getCount(void)
	{
		return count();
	}

	Idx_Cont_ExchDepthMarketData &getContainer()
	{
		return get_cont();
	}
};

/////////////////////////////////////////////////////////////////////////
//CExchDepthMarketHistoryDataFactory是一个深度行情历史的对象工厂。它包含了一批深度行情历史，
//同时又建立了如下索引，以方便查询：
//	InstrumentTimeIndex
//使用本对象工厂，可以完成对深度行情历史的增删改查操作。具体方法如下：
//	增加：叫用add，完成加入
//	删除：叫用remove就可以删除
//	查询：有如下方法可以查询：
//		使用findByInstrumentID，唯一找到对象
//	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
//	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
//		在retrieve时，也可以指定事务，此时将取出经过update的新数据
/////////////////////////////////////////////////////////////////////////
class CExchDepthMarketHistoryDataFactory : public COutputTable, public CMemMITable<CExchDepthMarketHistoryData, Idx_Cont_ExchDepthMarketHistoryData>
{
public:
	CExchDepthMarketHistoryDataFactory(const std::string &TableName);
	~CExchDepthMarketHistoryDataFactory(void);

	typedef Idx_Cont_ExchDepthMarketHistoryData Data_Container_Type;
	typedef Idx_Cont_ExchDepthMarketHistoryData Index_Container_Type;

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
	//@param	pExchDepthMarketHistoryData	  需要被刷新或者新增的CExchDepthMarketHistoryData,等于NULL表示是需要新增的
	//@param	pNewExchDepthMarketHistoryData	新的值
	//@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	//@param	updateIndex	  是否需要更新索引
	//@param	新增或者修改后的数据
	CExchDepthMarketHistoryData* addOrUpdate(CExchDepthMarketHistoryData *pExchDepthMarketHistoryData, CWriteableExchDepthMarketHistoryData *pNewExchDepthMarketHistoryData, CTransaction *pTransaction = NULL, bool updateIndex = true);

	//获取某个CExchDepthMarketHistoryData
	//@param	pExchDepthMarketHistoryData	要读取的CExchDepthMarketHistoryData
	//@param	pTragetExchDepthMarketHistoryData	存放结果的CExchDepthMarketHistoryData
	void retrieve(CExchDepthMarketHistoryData *pExchDepthMarketHistoryData,
		CWriteableExchDepthMarketHistoryData *pTargetExchDepthMarketHistoryData);

	std::size_t getCount(void)
	{
		return count();
	}

	Idx_Cont_ExchDepthMarketHistoryData &getContainer()
	{
		return get_cont();
	}
};

/////////////////////////////////////////////////////////////////////////
//CExchInstrumentFactory是一个合约的对象工厂。它包含了一批合约，
//同时又建立了如下索引，以方便查询：
//	InstrumentIDIndex
//	CommodityIDIndex
//	ExchInstrumentIDIndex
//使用本对象工厂，可以完成对合约的增删改查操作。具体方法如下：
//	增加：叫用add，完成加入
//	删除：叫用remove就可以删除
//	查询：有如下方法可以查询：
//		使用findByInstrumentID，唯一找到对象
//	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
//	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
//		在retrieve时，也可以指定事务，此时将取出经过update的新数据
/////////////////////////////////////////////////////////////////////////
class CExchInstrumentFactory : public COutputTable, public CMemMITable<CExchInstrument, Idx_Cont_ExchInstrument>
{
public:
	CExchInstrumentFactory(const std::string &TableName);
	~CExchInstrumentFactory(void);

	typedef Idx_Cont_ExchInstrument Data_Container_Type;
	typedef Idx_Cont_ExchInstrument Index_Container_Type;

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
	//@param	pExchInstrument	  需要被刷新或者新增的CExchInstrument,等于NULL表示是需要新增的
	//@param	pNewExchInstrument	新的值
	//@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	//@param	updateIndex	  是否需要更新索引
	//@param	新增或者修改后的数据
	CExchInstrument* addOrUpdate(CExchInstrument *pExchInstrument,
		CWriteableExchInstrument *pNewExchInstrument,
		CTransaction *pTransaction = nullptr, bool updateIndex = true);

	//获取某个CExchInstrument
	//@param	pExchInstrument	要读取的CExchInstrument
	//@param	pTragetExchInstrument	存放结果的CExchInstrument
	void retrieve(CExchInstrument *pExchInstrument,
		CWriteableExchInstrument *pTargetExchInstrument);

	std::size_t getCount(void)
	{
		return count();
	}

	Idx_Cont_ExchInstrument &getContainer()
	{
		return get_cont();
	}
};

/////////////////////////////////////////////////////////////////////////
//CExchInstrumentStatusFactory是一个合约的对象工厂。它包含了一批合约，
//同时又建立了如下索引，以方便查询：
//	InstrumentIDIndex
//	ExchInstrumentIDIndex
//使用本对象工厂，可以完成对合约的增删改查操作。具体方法如下：
//	增加：叫用add，完成加入
//	删除：叫用remove就可以删除
//	查询：有如下方法可以查询：
//		使用findByInstrumentID，唯一找到对象
//	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
//	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
//		在retrieve时，也可以指定事务，此时将取出经过update的新数据
/////////////////////////////////////////////////////////////////////////
class CExchInstrumentStatusFactory : public COutputTable, public CMemMITable<CExchInstrumentStatus, Idx_Cont_ExchInstrumentStatus>
{
public:
	CExchInstrumentStatusFactory(const std::string &TableName);
	~CExchInstrumentStatusFactory(void);

	typedef Idx_Cont_ExchInstrumentStatus Data_Container_Type;
	typedef Idx_Cont_ExchInstrumentStatus Index_Container_Type;

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
	//@param	pExchInstrumentStatus	  需要被刷新或者新增的CExchInstrumentStatus,等于NULL表示是需要新增的
	//@param	pNewExchInstrumentStatus	新的值
	//@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	//@param	updateIndex	  是否需要更新索引
	//@param	新增或者修改后的数据
	CExchInstrumentStatus* addOrUpdate(CExchInstrumentStatus *pExchInstrumentStatus,
		CWriteableExchInstrumentStatus *pNewExchInstrumentStatus,
		CTransaction *pTransaction = nullptr, bool updateIndex = true);

	//获取某个CExchInstrumentStatus
	//@param	pExchInstrumentStatus	要读取的CExchInstrumentStatus
	//@param	pTragetExchInstrumentStatus	存放结果的CExchInstrumentStatus
	void retrieve(CExchInstrumentStatus *pExchInstrumentStatus,
		CWriteableExchInstrumentStatus *pTargetExchInstrumentStatus);

	std::size_t getCount(void)
	{
		return count();
	}

	Idx_Cont_ExchInstrumentStatus &getContainer()
	{
		return get_cont();
	}
};

/////////////////////////////////////////////////////////////////////////
//CPhyAccountFactory是一个物理账号的对象工厂。它包含了一批物理账号，
//同时又建立了如下索引，以方便查询：
//	UserIDIdx
//使用本对象工厂，可以完成对物理账号的增删改查操作。具体方法如下：
//	增加：叫用add，完成加入
//	删除：叫用remove就可以删除
//	查询：有如下方法可以查询：
//	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
//	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
//		在retrieve时，也可以指定事务，此时将取出经过update的新数据
/////////////////////////////////////////////////////////////////////////
class CPhyAccountFactory 
	: public COutputTable, public CMemMITable<CPhyAccount, Idx_Cont_PhyAccount>
{
public:
	CPhyAccountFactory(const std::string &TableName);
	~CPhyAccountFactory(void);

	typedef Idx_Cont_PhyAccount Data_Container_Type;
	typedef Idx_Cont_PhyAccount Index_Container_Type;

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
	//@param	pPhyAccount	  需要被刷新或者新增的CPhyAccount,等于NULL表示是需要新增的
	//@param	pNewPhyAccount	新的值
	//@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	//@param	updateIndex	  是否需要更新索引
	//@param	新增或者修改后的数据
	CPhyAccount* addOrUpdate(CPhyAccount *pPhyAccount, CWriteablePhyAccount *pNewPhyAccount,
		CTransaction *pTransaction = nullptr, bool updateIndex = true);

	//获取某个CPhyAccount
	//@param	pPhyAccount	要读取的CPhyAccount
	//@param	pTragetPhyAccount	存放结果的CPhyAccount
	void retrieve(CPhyAccount *pPhyAccount, CWriteablePhyAccount *pTargetPhyAccount);

	std::size_t getCount(void)
	{
		return count();
	}

	Idx_Cont_PhyAccount &getContainer()
	{
		return get_cont();
	}
};

/////////////////////////////////////////////////////////////////////////
//CInvestorPositionFactory是一个持仓信息的对象工厂。它包含了一批持仓信息，
//同时又建立了如下索引，以方便查询：
//	InstDirectIndex
//使用本对象工厂，可以完成对持仓信息的增删改查操作。具体方法如下：
//	增加：叫用add，完成加入
//	删除：叫用remove就可以删除
//	查询：有如下方法可以查询：
//		使用findByInvestorID，唯一找到对象
//	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
//	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
//		在retrieve时，也可以指定事务，此时将取出经过update的新数据
/////////////////////////////////////////////////////////////////////////
class CInvestorPositionFactory : public COutputTable, public CMemMITable<CInvestorPosition, Idx_Cont_InvestorPosition>
{
public:
	CInvestorPositionFactory(const std::string &TableName);
	~CInvestorPositionFactory(void);

	typedef Idx_Cont_InvestorPosition Data_Container_Type;
	typedef Idx_Cont_InvestorPosition Index_Container_Type;

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
	//@param	pInvestorPosition	  需要被刷新或者新增的CInvestorPosition,等于NULL表示是需要新增的
	//@param	pNewInvestorPosition	新的值
	//@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	//@param	updateIndex	  是否需要更新索引
	//@param	新增或者修改后的数据
	CInvestorPosition* addOrUpdate(CInvestorPosition *pInvestorPosition,
		CWriteableInvestorPosition *pNewInvestorPosition,
		CTransaction *pTransaction = nullptr, bool updateIndex = true);

	//获取某个CInvestorPosition
	//@param	pInvestorPosition	要读取的CInvestorPosition
	//@param	pTragetInvestorPosition	存放结果的CInvestorPosition
	void retrieve(CInvestorPosition *pInvestorPosition,
		CWriteableInvestorPosition *pTargetInvestorPosition);

	std::size_t getCount(void)
	{
		return count();
	}
	Idx_Cont_InvestorPosition &getContainer()
	{
		return get_cont();
	}
};

/////////////////////////////////////////////////////////////////////////
//CRuleInfoFactory是一个策略信息的对象工厂。它包含了一批策略信息，
//同时又建立了如下索引，以方便查询：
//	RuleIDIdx
//使用本对象工厂，可以完成对策略信息的增删改查操作。具体方法如下：
//	增加：叫用add，完成加入
//	删除：叫用remove就可以删除
//	查询：有如下方法可以查询：
//	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
//	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
//		在retrieve时，也可以指定事务，此时将取出经过update的新数据
/////////////////////////////////////////////////////////////////////////
class CRuleInfoFactory : public COutputTable, public CMemMITable<CRuleInfo, Idx_Cont_RuleInfo>
{
public:
	CRuleInfoFactory(const std::string &TableName);
	~CRuleInfoFactory(void);

	typedef Idx_Cont_RuleInfo Data_Container_Type;
	typedef Idx_Cont_RuleInfo Index_Container_Type;

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
	//@param	pRuleInfo	  需要被刷新或者新增的CRuleInfo,等于NULL表示是需要新增的
	//@param	pNewRuleInfo	新的值
	//@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	//@param	updateIndex	  是否需要更新索引
	//@param	新增或者修改后的数据
	CRuleInfo* addOrUpdate(CRuleInfo *pRuleInfo, CWriteableRuleInfo *pNewRuleInfo,
		CTransaction *pTransaction = nullptr, bool updateIndex = true);

	//获取某个CRuleInfo
	//@param	pRuleInfo	要读取的CRuleInfo
	//@param	pTragetRuleInfo	存放结果的CRuleInfo
	void retrieve(CRuleInfo *pRuleInfo, CWriteableRuleInfo *pTargetRuleInfo);

	std::size_t getCount(void)
	{
		return count();
	}

	Idx_Cont_RuleInfo &getContainer()
	{
		return get_cont();
	}
};

/////////////////////////////////////////////////////////////////////////
//CExchInvestorFeeFactory是一个投资者手续费率的对象工厂。它包含了一批投资者手续费率，
//同时又建立了如下索引，以方便查询：
//	ExchInstrumentIDIndex
//使用本对象工厂，可以完成对投资者手续费率的增删改查操作。具体方法如下：
//	增加：叫用add，完成加入
//	删除：叫用remove就可以删除
//	查询：有如下方法可以查询：
//		使用findByExchInstrumentID，唯一找到对象
//	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
//	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
//		在retrieve时，也可以指定事务，此时将取出经过update的新数据
/////////////////////////////////////////////////////////////////////////
class CExchInvestorFeeFactory : public COutputTable, public CMemMITable<CExchInvestorFee, Idx_Cont_ExchInvestorFee>
{
public:
	CExchInvestorFeeFactory(const std::string &TableName);
	~CExchInvestorFeeFactory(void);

	typedef Idx_Cont_ExchInvestorFee Data_Container_Type;
	typedef Idx_Cont_ExchInvestorFee Index_Container_Type;

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
	//@param	pExchInvestorFee	  需要被刷新或者新增的CExchInvestorFee,等于NULL表示是需要新增的
	//@param	pNewExchInvestorFee	新的值
	//@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	//@param	updateIndex	  是否需要更新索引
	//@param	新增或者修改后的数据
	CExchInvestorFee* addOrUpdate(CExchInvestorFee *pExchInvestorFee,
		CWriteableExchInvestorFee *pNewExchInvestorFee,
		CTransaction *pTransaction = nullptr, bool updateIndex = true);

	//获取某个CExchInvestorFee
	//@param	pExchInvestorFee	要读取的CExchInvestorFee
	//@param	pTragetExchInvestorFee	存放结果的CExchInvestorFee
	void retrieve(CExchInvestorFee *pExchInvestorFee,
		CWriteableExchInvestorFee *pTargetExchInvestorFee);

	std::size_t getCount(void)
	{
		return count();
	}

	Idx_Cont_ExchInvestorFee &getContainer()
	{
		return get_cont();
	}
};

/////////////////////////////////////////////////////////////////////////
//CExchInvestorMarginFactory是一个交易保证金率的对象工厂。它包含了一批交易保证金率，
//同时又建立了如下索引，以方便查询：
//	ExchInstrumentIDIndex
//使用本对象工厂，可以完成对交易保证金率的增删改查操作。具体方法如下：
//	增加：叫用add，完成加入
//	删除：叫用remove就可以删除
//	查询：有如下方法可以查询：
//		使用findByExchInstrumentID，唯一找到对象
//	修改：对于查到的结果，可以通过retrieve取出，修改后，通过update放回
//	事务管理：所有的增加、删除和修改都可以指定事务，在事务commit时，真正写入
//		在retrieve时，也可以指定事务，此时将取出经过update的新数据
/////////////////////////////////////////////////////////////////////////
class CExchInvestorMarginFactory : public COutputTable, public CMemMITable<CExchInvestorMargin, Idx_Cont_ExchInvestorMargin>
{
public:
	CExchInvestorMarginFactory(const std::string &TableName);
	~CExchInvestorMarginFactory(void);

	typedef Idx_Cont_ExchInvestorMargin Data_Container_Type;
	typedef Idx_Cont_ExchInvestorMargin Index_Container_Type;

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
	//@param	pExchInvestorMargin	  需要被刷新或者新增的CExchInvestorMargin,等于NULL表示是需要新增的
	//@param	pNewExchInvestorMargin	新的值
	//@param	pTransaction	本次操作所属的事务，如果是NULL，表示不使用事务管理，立即生效，否则需要在该事务commit时生效
	//@param	updateIndex	  是否需要更新索引
	//@param	新增或者修改后的数据
	CExchInvestorMargin* addOrUpdate(CExchInvestorMargin *pExchInvestorMargin,
		CWriteableExchInvestorMargin *pNewExchInvestorMargin,
		CTransaction *pTransaction = nullptr, bool updateIndex = true);

	//获取某个CExchInvestorMargin
	//@param	pExchInvestorMargin	要读取的CExchInvestorMargin
	//@param	pTragetExchInvestorMargin	存放结果的CExchInvestorMargin
	void retrieve(CExchInvestorMargin *pExchInvestorMargin,
		CWriteableExchInvestorMargin *pTargetExchInvestorMargin);

	std::size_t getCount(void)
	{
		return count();
	}

	Idx_Cont_ExchInvestorMargin &getContainer()
	{
		return get_cont();
	}
};

#endif
