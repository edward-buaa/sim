#ifndef __MEMORY_TRANSACTION_H__
#define __MEMORY_TRANSACTION_H__

/*
/* 一个事务的基本类
/* 具体实现类来实现： SavePoint Command的特别特征等处理
*/

class ITranCommand
{
public:
	virtual void undo() = 0;
};

//xww  这个类有什么用？？？
class CTransaction
{
public:
	virtual ~CTransaction() {}
	virtual void add_action(ITranCommand* pCmd) = 0;
	virtual void commit() = 0;
	virtual void rollback(void* savepoint = 0) = 0;
	virtual int count() = 0;
	virtual ITranCommand* create_savepoint() = 0;
};


#endif
