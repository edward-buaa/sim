#ifndef __MEMORY_TRANSACTION_H__
#define __MEMORY_TRANSACTION_H__

/*
/* һ������Ļ�����
/* ����ʵ������ʵ�֣� SavePoint Command���ر������ȴ���
*/

class ITranCommand
{
public:
	virtual void undo() = 0;
};

//xww  �������ʲô�ã�����
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
