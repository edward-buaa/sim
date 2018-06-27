#ifndef __TABLES_DEFINE_H__
#define __TABLES_DEFINE_H__

/*
���ܣ������ڴ����ݿ�ı�
*/

#include "OutputTable.h"
#include "mem_mi_table.h"
#include "RecordStruct.h"
#include "RecordIndexCont.h"
#include "../config/config.h"

/////////////////////////////////////////////////////////////////////////
//CCurrentTimeFactory��һ����ǰʱ��Ķ��󹤳�����������һ����ǰʱ�䣬
//ͬʱ�ֽ����������������Է����ѯ��
//ʹ�ñ����󹤳���������ɶԵ�ǰʱ�����ɾ�Ĳ���������巽�����£�
//	���ӣ�����add����ɼ���
//	ɾ��������remove�Ϳ���ɾ��
//	��ѯ�������·������Բ�ѯ��
//	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
//	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
//		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
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

	//--------------���뵼������------------
	int writeCSV(const char* filename);
	int writeCSV(config::CConfig *pConfig);
	int readCSV(const char *filename);
	int readCSV(config::CConfig *pConfig);

	//������д���ļ��У�����debug
	virtual void dump(FILE* fp);

	//������д���ļ��У�����debug
	virtual void dump(char* filename);

	//������м�¼
	void clearAll();

	//���ӻ��߸�������
	//@param	pCurrentTime	  ��Ҫ��ˢ�»���������CCurrentTime,����NULL��ʾ����Ҫ������
	//@param	pNewCurrentTime	�µ�ֵ
	//@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	//@param	updateIndex	  �Ƿ���Ҫ��������
	//@param	���������޸ĺ������
	CCurrentTime* addOrUpdate(CCurrentTime *pCurrentTime, CWriteableCurrentTime *pNewCurrentTime, 
		CTransaction *pTransaction = NULL, bool updateIndex = true);

	//��ȡĳ��CCurrentTime
	//@param	pCurrentTime	Ҫ��ȡ��CCurrentTime
	//@param	pTragetCurrentTime	��Ž����CCurrentTime
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
//CTerminalFactory��һ���ն˻��Ķ��󹤳�����������һ���ն˻���
//ͬʱ�ֽ����������������Է����ѯ��
//	TerminalIDIndex
//	SessionIDIndex
//ʹ�ñ����󹤳���������ɶ��ն˻�����ɾ�Ĳ���������巽�����£�
//	���ӣ�����add����ɼ���
//	ɾ��������remove�Ϳ���ɾ��
//	��ѯ�������·������Բ�ѯ��
//		ʹ��findByTerminalID��Ψһ�ҵ�����
//		ʹ��startFindAll��findNextAll��endFindAll��ɲ�ѯ����
//	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
//	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
//		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
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

	//--------------------���� ���� ����-------------------------------
	int writeCSV(const char *filename);
	int writeCSV(config::CConfig *pConfig);
	int readCSV(const char *filename);
	int readCSV(config::CConfig *pConfig);

	//������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	//������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	//������еļ�¼
	void clearAll(void);

	//���ӻ��߸�������
	//@param	pTerminal	  ��Ҫ��ˢ�»���������CTerminal,����NULL��ʾ����Ҫ������
	//@param	pNewTerminal	�µ�ֵ
	//@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	//@param	updateIndex	  �Ƿ���Ҫ��������
	//@param	���������޸ĺ������
	CTerminal* addOrUpdate(CTerminal *pTerminal, CWriteableTerminal *pNewTerminal, CTransaction *pTransaction = NULL, bool updateIndex = true);

	//��ȡĳ��CTerminal
	//@param	pTerminal	Ҫ��ȡ��CTerminal
	//@param	pTragetTerminal	��Ž����CTerminal
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
//CFrontFactory��һ��ǰ�û��Ķ��󹤳�����������һ��ǰ�û���
//ͬʱ�ֽ����������������Է����ѯ��
//	FrontIDIndex
//	SessionIDIndex
//ʹ�ñ����󹤳���������ɶ�ǰ�û�����ɾ�Ĳ���������巽�����£�
//	���ӣ�����add����ɼ���
//	ɾ��������remove�Ϳ���ɾ��
//	��ѯ�������·������Բ�ѯ��
//		ʹ��findByFrontID��Ψһ�ҵ�����
//		ʹ��startFindAll��findNextAll��endFindAll��ɲ�ѯ����
//	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
//	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
//		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
/////////////////////////////////////////////////////////////////////////
class CFrontFactory : public COutputTable, public CMemMITable<CFront, Idx_Cont_Front>
{
public:
	CFrontFactory(const std::string &TableName);
	~CFrontFactory(void);

public:
	typedef Idx_Cont_Front Data_Container_Type;
	typedef Idx_Cont_Front Index_Container_Type;

	//--------------------���� ���� ����-------------------------------
	int writeCSV(const char *filename);
	int writeCSV(config::CConfig *pConfig);
	int readCSV(const char *filename);
	int readCSV(config::CConfig *pConfig);

	//������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	//������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	//������еļ�¼
	void clearAll(void);

	//���ӻ��߸�������
	//@param	pFront	  ��Ҫ��ˢ�»���������CFront,����NULL��ʾ����Ҫ������
	//@param	pNewFront	�µ�ֵ
	//@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	//@param	updateIndex	  �Ƿ���Ҫ��������
	//@param	���������޸ĺ������
	CFront* addOrUpdate(CFront *pFront, CWriteableFront *pNewFront, CTransaction *pTransaction = NULL, bool updateIndex = true);

	//��ȡĳ��CFront
	//@param	pFront	Ҫ��ȡ��CFront
	//@param	pTragetFront	��Ž����CFront
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
//CTraderFactory��һ������Ա�Ķ��󹤳�����������һ������Ա��
//ͬʱ�ֽ����������������Է����ѯ��
//	TraderIDIndex
//ʹ�ñ����󹤳���������ɶԽ���Ա����ɾ�Ĳ���������巽�����£�
//	���ӣ�����add����ɼ���
//	ɾ��������remove�Ϳ���ɾ��
//	��ѯ�������·������Բ�ѯ��
//		ʹ��startFindByTraderID��findNextByTraderID��endFindByTraderID��ɲ�ѯ����
//	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
//	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
//		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
/////////////////////////////////////////////////////////////////////////
class CTraderFactory : public COutputTable, public CMemMITable<CTrader, Idx_Cont_Trader>
{
public:
	CTraderFactory(const std::string &TableName);
	~CTraderFactory(void);

	typedef Idx_Cont_Trader Data_Container_Type;
	typedef Idx_Cont_Trader Index_Container_Type;

	//--------------------���� ���� ����-------------------------------
	int writeCSV(const char *filename);
	int writeCSV(config::CConfig *pConfig);
	int readCSV(const char *filename);
	int readCSV(config::CConfig *pConfig);

	//������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	//������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	//������еļ�¼
	void clearAll(void);

	//���ӻ��߸�������
	//@param	pTrader	  ��Ҫ��ˢ�»���������CTrader,����NULL��ʾ����Ҫ������
	//@param	pNewTrader	�µ�ֵ
	//@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	//@param	updateIndex	  �Ƿ���Ҫ��������
	//@param	���������޸ĺ������
	CTrader* addOrUpdate(CTrader *pTrader, CWriteableTrader *pNewTrader, CTransaction *pTransaction = NULL, bool updateIndex = true);

	//��ȡĳ��CTrader
	//@param	pTrader	Ҫ��ȡ��CTrader
	//@param	pTragetTrader	��Ž����CTrader
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
