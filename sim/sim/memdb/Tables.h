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

/////////////////////////////////////////////////////////////////////////
//CTraderParalleFactory��һ������Ա������Դ�Ķ��󹤳�����������һ������Ա������Դ��
//ͬʱ�ֽ����������������Է����ѯ��
//	TraderIDIndex
//ʹ�ñ����󹤳���������ɶԽ���Ա������Դ����ɾ�Ĳ���������巽�����£�
//	���ӣ�����add����ɼ���
//	ɾ��������remove�Ϳ���ɾ��
//	��ѯ�������·������Բ�ѯ��
//		ʹ��startFindByTraderID��findNextByTraderID��endFindByTraderID��ɲ�ѯ����
//	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
//	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
//		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
////////////////////////////////////////////////////////////////////////
class CTraderParalleFactory : public COutputTable, public CMemMITable<CTraderParalle, Idx_Cont_TraderParalle>
{
public:
	CTraderParalleFactory(const std::string &TableName);
	~CTraderParalleFactory(void);

	typedef Idx_Cont_TraderParalle Data_Container_Type;
	typedef Idx_Cont_TraderParalle Index_Container_Type;

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
	//@param	pTraderParalle	  ��Ҫ��ˢ�»���������CTraderParalle,����NULL��ʾ����Ҫ������
	//@param	pNewTraderParalle	�µ�ֵ
	//@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	//@param	updateIndex	  �Ƿ���Ҫ��������
	//@param	���������޸ĺ������
	CTraderParalle* addOrUpdate(CTraderParalle *pTraderParalle, CWriteableTraderParalle *pNewTraderParalle, CTransaction *pTransaction = NULL, bool updateIndex = true);

	//��ȡĳ��CTraderParalle
	//@param	pTraderParalle	Ҫ��ȡ��CTraderParalle
	//@param	pTragetTraderParalle	��Ž����CTraderParalle
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
//CTraderLoginLogFactory��һ������Ա��¼��¼�Ķ��󹤳�����������һ������Ա��¼��¼��
//ͬʱ�ֽ����������������Է����ѯ��
//	TraderIDIndex
//ʹ�ñ����󹤳���������ɶԽ���Ա��¼��¼����ɾ�Ĳ���������巽�����£�
//	���ӣ�����add����ɼ���
//	ɾ��������remove�Ϳ���ɾ��
//	��ѯ�������·������Բ�ѯ��
//		ʹ��findByTraderID��Ψһ�ҵ�����
//	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
//	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
//		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
/////////////////////////////////////////////////////////////////////////
class CTraderLoginLogFactory 
	: public COutputTable, public CMemMITable<CTraderLoginLog, Idx_Cont_TraderLoginLog>
{
public:
	CTraderLoginLogFactory(const std::string &TableName);
	~CTraderLoginLogFactory(void);

	typedef Idx_Cont_TraderLoginLog Data_Container_Type;
	typedef Idx_Cont_TraderLoginLog Index_Container_Type;

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
	//@param	pTraderLoginLog	  ��Ҫ��ˢ�»���������CTraderLoginLog,����NULL��ʾ����Ҫ������
	//@param	pNewTraderLoginLog	�µ�ֵ
	//@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	//@param	updateIndex	  �Ƿ���Ҫ��������
	//@param	���������޸ĺ������
	CTraderLoginLog* addOrUpdate(CTraderLoginLog *pTraderLoginLog, 
		CWriteableTraderLoginLog *pNewTraderLoginLog, 
		CTransaction *pTransaction = nullptr, bool updateIndex = true);

	//��ȡĳ��CTraderLoginLog
	//@param	pTraderLoginLog	Ҫ��ȡ��CTraderLoginLog
	//@param	pTragetTraderLoginLog	��Ž����CTraderLoginLog
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
//CTraderConnectFactory��һ������Ա����״̬�Ķ��󹤳�����������һ������Ա����״̬��
//ͬʱ�ֽ����������������Է����ѯ��
//	TraderConnectIndex
//	TraderBaseIndex
//	SessionIndex
//ʹ�ñ����󹤳���������ɶԽ���Ա����״̬����ɾ�Ĳ���������巽�����£�
//	���ӣ�����add����ɼ���
//	ɾ��������remove�Ϳ���ɾ��
//	��ѯ�������·������Բ�ѯ��
//		ʹ��findByTraderID��Ψһ�ҵ�����
//	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
//	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
//		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
/////////////////////////////////////////////////////////////////////////
class CTraderConnectFactory : public COutputTable, public CMemMITable<CTraderConnect, Idx_Cont_TraderConnect>
{
public:
	CTraderConnectFactory(const std::string &TableName);
	~CTraderConnectFactory(void);

	typedef Idx_Cont_TraderConnect Data_Container_Type;
	typedef Idx_Cont_TraderConnect Index_Container_Type;

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
	//@param	pTraderConnect	  ��Ҫ��ˢ�»���������CTraderConnect,����NULL��ʾ����Ҫ������
	//@param	pNewTraderConnect	�µ�ֵ
	//@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	//@param	updateIndex	  �Ƿ���Ҫ��������
	//@param	���������޸ĺ������
	CTraderConnect* addOrUpdate(CTraderConnect *pTraderConnect, CWriteableTraderConnect *pNewTraderConnect, CTransaction *pTransaction = NULL, bool updateIndex = true);

	//��ȡĳ��CTraderConnect
	//@param	pTraderConnect	Ҫ��ȡ��CTraderConnect
	//@param	pTragetTraderConnect	��Ž����CTraderConnect
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
//CTraderCertInfoFactory��һ������Ա���ӵĶ��󹤳�����������һ������Ա���ӣ�
//ͬʱ�ֽ����������������Է����ѯ��
//	TraderIDIndex
//ʹ�ñ����󹤳���������ɶԽ���Ա���ӵ���ɾ�Ĳ���������巽�����£�
//	���ӣ�����add����ɼ���
//	ɾ��������remove�Ϳ���ɾ��
//	��ѯ�������·������Բ�ѯ��
//		ʹ��startFindByTraderID��findNextByTraderID��endFindByTraderID��ɲ�ѯ����
//	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
//	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
//		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
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
	//@param	pTraderCertInfo	  ��Ҫ��ˢ�»���������CTraderCertInfo,����NULL��ʾ����Ҫ������
	//@param	pNewTraderCertInfo	�µ�ֵ
	//@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	//@param	updateIndex	  �Ƿ���Ҫ��������
	//@param	���������޸ĺ������
	CTraderCertInfo* addOrUpdate(CTraderCertInfo *pTraderCertInfo,
		CWriteableTraderCertInfo *pNewTraderCertInfo,
		CTransaction *pTransaction = NULL, bool updateIndex = true);

	//��ȡĳ��CTraderCertInfo
	//@param	pTraderCertInfo	Ҫ��ȡ��CTraderCertInfo
	//@param	pTragetTraderCertInfo	��Ž����CTraderCertInfo
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
//CUserFactory��һ���û��Ķ��󹤳�����������һ���û���
//ͬʱ�ֽ����������������Է����ѯ��
//	UserIDIndex
//ʹ�ñ����󹤳���������ɶ��û�����ɾ�Ĳ���������巽�����£�
//	���ӣ�����add����ɼ���
//	ɾ��������remove�Ϳ���ɾ��
//	��ѯ�������·������Բ�ѯ��
//		ʹ��findByUserID��Ψһ�ҵ�����
//		ʹ��startFindStartByUserID��findNextStartByUserID��endFindStartByUserID��ɲ�ѯ����
//	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
//	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
//		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
/////////////////////////////////////////////////////////////////////////
class CUserFactory : public COutputTable, public CMemMITable<CUser, Idx_Cont_User>
{
public:
	CUserFactory(const std::string &TableName);
	~CUserFactory(void);

	typedef Idx_Cont_User Data_Container_Type;
	typedef Idx_Cont_User Index_Container_Type;

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
	//@param	pUser	  ��Ҫ��ˢ�»���������CUser,����NULL��ʾ����Ҫ������
	//@param	pNewUser	�µ�ֵ
	//@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	//@param	updateIndex	  �Ƿ���Ҫ��������
	//@param	���������޸ĺ������
	CUser* addOrUpdate(CUser *pUser, CWriteableUser *pNewUser,
		CTransaction *pTransaction = NULL, bool updateIndex = true);

	//��ȡĳ��CUser
	//@param	pUser	Ҫ��ȡ��CUser
	//@param	pTragetUser	��Ž����CUser
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
//CUserTraderFactory��һ���û�����Ա��ϵ��Ķ��󹤳�����������һ���û�����Ա��ϵ��
//ͬʱ�ֽ����������������Է����ѯ��
//	TraderUserIDIndex
//	UserIDIndex
//	TraderIDIndex
//ʹ�ñ����󹤳���������ɶ��û�����Ա��ϵ�����ɾ�Ĳ���������巽�����£�
//	���ӣ�����add����ɼ���
//	ɾ��������remove�Ϳ���ɾ��
//	��ѯ�������·������Բ�ѯ��
//		ʹ��findByUserID��Ψһ�ҵ�����
//		ʹ��startFindByTraderID��findNextByTraderID��endFindByTraderID��ɲ�ѯ����
//	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
//	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
//		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
/////////////////////////////////////////////////////////////////////////
class CUserTraderFactory : public COutputTable, public CMemMITable<CUserTrader, Idx_Cont_UserTrader>
{
public:
	CUserTraderFactory(const std::string &TableName);
	~CUserTraderFactory(void);

	typedef Idx_Cont_UserTrader Data_Container_Type;
	typedef Idx_Cont_UserTrader Index_Container_Type;

	//--------------------���� ���� ����-------------------------------
	int writeCSV(const char *filename);
	int writeCSV(config::CConfig *pConfig);
	int readCSV(const char *filename);
	int readCSV(config::CConfig *pConfig);

	//������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	//������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	std::size_t getCount(void)
	{
		return count();
	}

	Idx_Cont_UserTrader &getContainer()
	{
		return get_cont();
	}

	//������еļ�¼
	void clearAll(void);

	//���ӻ��߸�������
	//@param	pUserTrader	  ��Ҫ��ˢ�»���������CUserTrader,����NULL��ʾ����Ҫ������
	//@param	pNewUserTrader	�µ�ֵ
	//@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	//@param	updateIndex	  �Ƿ���Ҫ��������
	//@param	���������޸ĺ������
	CUserTrader* addOrUpdate(CUserTrader *pUserTrader, CWriteableUserTrader *pNewUserTrader, CTransaction *pTransaction = NULL, bool updateIndex = true);

	//��ȡĳ��CUserTrader
	//@param	pUserTrader	Ҫ��ȡ��CUserTrader
	//@param	pTragetUserTrader	��Ž����CUserTrader
	void retrieve(CUserTrader *pUserTrader, CWriteableUserTrader *pTargetUserTrader);
};

/////////////////////////////////////////////////////////////////////////
//CUserFunctionRightFactory��һ���û�Ȩ�޵Ķ��󹤳�����������һ���û�Ȩ�ޣ�
//ͬʱ�ֽ����������������Է����ѯ��
//	UserIDIndex
//ʹ�ñ����󹤳���������ɶ��û�Ȩ�޵���ɾ�Ĳ���������巽�����£�
//	���ӣ�����add����ɼ���
//	ɾ��������remove�Ϳ���ɾ��
//	��ѯ�������·������Բ�ѯ��
//		ʹ��findByUserID��Ψһ�ҵ�����
//		ʹ��startFindStartByUserID��findNextStartByUserID��endFindStartByUserID��ɲ�ѯ����
//	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
//	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
//		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
/////////////////////////////////////////////////////////////////////////
class CUserFunctionRightFactory : public COutputTable, public CMemMITable<CUserFunctionRight, Idx_Cont_UserFunctionRight>
{
public:
	CUserFunctionRightFactory(const std::string &TableName);
	~CUserFunctionRightFactory(void);

	typedef Idx_Cont_UserFunctionRight Data_Container_Type;
	typedef Idx_Cont_UserFunctionRight Index_Container_Type;

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
	//@param	pUserFunctionRight	  ��Ҫ��ˢ�»���������CUserFunctionRight,����NULL��ʾ����Ҫ������
	//@param	pNewUserFunctionRight	�µ�ֵ
	//@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	//@param	updateIndex	  �Ƿ���Ҫ��������
	//@param	���������޸ĺ������
	CUserFunctionRight* addOrUpdate(CUserFunctionRight *pUserFunctionRight,
		CWriteableUserFunctionRight *pNewUserFunctionRight,
		CTransaction *pTransaction = NULL, bool updateIndex = true);

	//��ȡĳ��CUserFunctionRight
	//@param	pUserFunctionRight	Ҫ��ȡ��CUserFunctionRight
	//@param	pTragetUserFunctionRight	��Ž����CUserFunctionRight
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
//CSysInfoFactory��һ��ϵͳ��Ϣ�Ķ��󹤳�����������һ��ϵͳ��Ϣ��
//ͬʱ�ֽ����������������Է����ѯ��
//	AppIDIndex
//ʹ�ñ����󹤳���������ɶ�ϵͳ��Ϣ����ɾ�Ĳ���������巽�����£�
//	���ӣ�����add����ɼ���
//	ɾ��������remove�Ϳ���ɾ��
//	��ѯ�������·������Բ�ѯ��
//		ʹ��findByAppID��Ψһ�ҵ�����
//	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
//	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
//		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
/////////////////////////////////////////////////////////////////////////
class CSysInfoFactory : public COutputTable, public CMemMITable<CSysInfo, Idx_Cont_SysInfo>
{
public:
	CSysInfoFactory(const std::string &TableName);
	~CSysInfoFactory(void);

	typedef Idx_Cont_SysInfo Data_Container_Type;
	typedef Idx_Cont_SysInfo Index_Container_Type;

	//--------------------���� ���� ����-------------------------------
	int writeCSV(const char *filename);
	int writeCSV(config::CConfig *pConfig);
	int readCSV(const char *filename);
	int readCSV(config::CConfig *pConfig);

	//������д���ļ���,����DEBUG
	virtual void dump(FILE *);

	//������д���ļ���,����DEBUG
	virtual void dump(char *filename);

	std::size_t getCount(void)
	{
		return count();
	}

	Idx_Cont_SysInfo &getContainer()
	{
		return get_cont();
	}

	//������еļ�¼
	void clearAll(void);

	//���ӻ��߸�������
	//@param	pSysInfo	  ��Ҫ��ˢ�»���������CSysInfo,����NULL��ʾ����Ҫ������
	//@param	pNewSysInfo	�µ�ֵ
	//@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	//@param	updateIndex	  �Ƿ���Ҫ��������
	//@param	���������޸ĺ������
	CSysInfo* addOrUpdate(CSysInfo *pSysInfo, CWriteableSysInfo *pNewSysInfo, CTransaction *pTransaction = NULL, bool updateIndex = true);

	//��ȡĳ��CSysInfo
	//@param	pSysInfo	Ҫ��ȡ��CSysInfo
	//@param	pTragetSysInfo	��Ž����CSysInfo
	void retrieve(CSysInfo *pSysInfo, CWriteableSysInfo *pTargetSysInfo);
};

/////////////////////////////////////////////////////////////////////////
//CUserSessionFactory��һ������Ա���߻Ự�Ķ��󹤳�����������һ������Ա���߻Ự��
//ͬʱ�ֽ����������������Է����ѯ��
//	FrontIDIndex
//	UserIDIndex
//ʹ�ñ����󹤳���������ɶԽ���Ա���߻Ự����ɾ�Ĳ���������巽�����£�
//	���ӣ�����add����ɼ���
//	ɾ��������remove�Ϳ���ɾ��
//	��ѯ�������·������Բ�ѯ��
//		ʹ��findBySessionID��Ψһ�ҵ�����
//		ʹ��startFindByFrontID��findNextByFrontID��endFindByFrontID��ɲ�ѯ����
//		ʹ��findByUserID��Ψһ�ҵ�����
//		ʹ��startFindStartByUserID��findNextStartByUserID��endFindStartByUserID��ɲ�ѯ����
//	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
//	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
//		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
/////////////////////////////////////////////////////////////////////////
class CUserSessionFactory 
	: public COutputTable, public CMemMITable<CUserSession, Idx_Cont_UserSession>
{
public:
	CUserSessionFactory(const std::string &TableName);
	~CUserSessionFactory(void);

	typedef Idx_Cont_UserSession Data_Container_Type;
	typedef Idx_Cont_UserSession Index_Container_Type;

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
	//@param	pUserSession	  ��Ҫ��ˢ�»���������CUserSession,����NULL��ʾ����Ҫ������
	//@param	pNewUserSession	�µ�ֵ
	//@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	//@param	updateIndex	  �Ƿ���Ҫ��������
	//@param	���������޸ĺ������
	CUserSession* addOrUpdate(CUserSession *pUserSession, CWriteableUserSession *pNewUserSession,
		CTransaction *pTransaction = nullptr, bool updateIndex = true);

	//��ȡĳ��CUserSession
	//@param	pUserSession	Ҫ��ȡ��CUserSession
	//@param	pTragetUserSession	��Ž����CUserSession
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
//CMDSessionFactory��һ�����鶩�������߻Ự�Ķ��󹤳�����������һ�����鶩�������߻Ự��
//ͬʱ�ֽ����������������Է����ѯ��
//	SessionIDIndex
//	UserIndex
//ʹ�ñ����󹤳���������ɶ����鶩�������߻Ự����ɾ�Ĳ���������巽�����£�
//	���ӣ�����add����ɼ���
//	ɾ��������remove�Ϳ���ɾ��
//	��ѯ�������·������Բ�ѯ��
//		ʹ��findBySessionID��Ψһ�ҵ�����
//		ʹ��findByUserID��Ψһ�ҵ�����
//	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
//	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
//		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
/////////////////////////////////////////////////////////////////////////
class CMDSessionFactory : public COutputTable, public CMemMITable<CMDSession, Idx_Cont_MDSession>
{
public:
	CMDSessionFactory(const std::string &TableName);
	~CMDSessionFactory(void);

	typedef Idx_Cont_MDSession Data_Container_Type;
	typedef Idx_Cont_MDSession Index_Container_Type;

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
	//@param	pMDSession	  ��Ҫ��ˢ�»���������CMDSession,����NULL��ʾ����Ҫ������
	//@param	pNewMDSession	�µ�ֵ
	//@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	//@param	updateIndex	  �Ƿ���Ҫ��������
	//@param	���������޸ĺ������
	CMDSession* addOrUpdate(CMDSession *pMDSession, CWriteableMDSession *pNewMDSession,
		CTransaction *pTransaction = nullptr, bool updateIndex = true);

	//��ȡĳ��CMDSession
	//@param	pMDSession	Ҫ��ȡ��CMDSession
	//@param	pTragetMDSession	��Ž����CMDSession
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
//CMaxLocalIDFactory��һ����󱾵ر����ŵĶ��󹤳�����������һ����󱾵ر����ţ�
//ͬʱ�ֽ����������������Է����ѯ��
//	UserIndex
//ʹ�ñ����󹤳���������ɶ���󱾵ر����ŵ���ɾ�Ĳ���������巽�����£�
//	���ӣ�����add����ɼ���
//	ɾ��������remove�Ϳ���ɾ��
//	��ѯ�������·������Բ�ѯ��
//		ʹ��findByUserID��Ψһ�ҵ�����
//	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
//	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
//		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
/////////////////////////////////////////////////////////////////////////
class CMaxLocalIDFactory : public COutputTable, public CMemMITable<CMaxLocalID, Idx_Cont_MaxLocalID>
{
public:
	CMaxLocalIDFactory(const std::string &TableName);
	~CMaxLocalIDFactory(void);

	typedef Idx_Cont_MaxLocalID Data_Container_Type;
	typedef Idx_Cont_MaxLocalID Index_Container_Type;

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
	//@param	pMaxLocalID	  ��Ҫ��ˢ�»���������CMaxLocalID,����NULL��ʾ����Ҫ������
	//@param	pNewMaxLocalID	�µ�ֵ
	//@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	//@param	updateIndex	  �Ƿ���Ҫ��������
	//@param	���������޸ĺ������
	CMaxLocalID* addOrUpdate(CMaxLocalID *pMaxLocalID, CWriteableMaxLocalID *pNewMaxLocalID,
		CTransaction *pTransaction = nullptr, bool updateIndex = true);

	//��ȡĳ��CMaxLocalID
	//@param	pMaxLocalID	Ҫ��ȡ��CMaxLocalID
	//@param	pTragetMaxLocalID	��Ž����CMaxLocalID
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
//CUserSubMarketDataFactory��һ�����鶩�ĵĶ��󹤳�����������һ�����鶩�ģ�
//ͬʱ�ֽ����������������Է����ѯ��
//	UserIndex
//	SubMarketDataIndex
//ʹ�ñ����󹤳���������ɶ����鶩�ĵ���ɾ�Ĳ���������巽�����£�
//	���ӣ�����add����ɼ���
//	ɾ��������remove�Ϳ���ɾ��
//	��ѯ�������·������Բ�ѯ��
//		ʹ��findByInstrumentID��Ψһ�ҵ�����
//		ʹ��findByUserSession��Ψһ�ҵ�����
//		ʹ��findByUserID��Ψһ�ҵ�����
//	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
//	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
//		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
/////////////////////////////////////////////////////////////////////////
class CUserSubMarketDataFactory 
	: public COutputTable, public CMemMITable<CUserSubMarketData, Idx_Cont_UserSubMarketData>
{
public:
	CUserSubMarketDataFactory(const std::string &TableName);
	~CUserSubMarketDataFactory(void);

	typedef Idx_Cont_UserSubMarketData Data_Container_Type;
	typedef Idx_Cont_UserSubMarketData Index_Container_Type;

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
	//@param	pUserSubMarketData	  ��Ҫ��ˢ�»���������CUserSubMarketData,����NULL��ʾ����Ҫ������
	//@param	pNewUserSubMarketData	�µ�ֵ
	//@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	//@param	updateIndex	  �Ƿ���Ҫ��������
	//@param	���������޸ĺ������
	CUserSubMarketData* addOrUpdate(CUserSubMarketData *pUserSubMarketData,
		CWriteableUserSubMarketData *pNewUserSubMarketData,
		CTransaction *pTransaction = nullptr, bool updateIndex = true);

	//��ȡĳ��CUserSubMarketData
	//@param	pUserSubMarketData	Ҫ��ȡ��CUserSubMarketData
	//@param	pTragetUserSubMarketData	��Ž����CUserSubMarketData
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
//CDepthMarketDataFactory��һ���������Ķ��󹤳�����������һ��������飬
//ͬʱ�ֽ����������������Է����ѯ��
//	InstrumentIDIndex
//ʹ�ñ����󹤳���������ɶ�����������ɾ�Ĳ���������巽�����£�
//	���ӣ�����add����ɼ���
//	ɾ��������remove�Ϳ���ɾ��
//	��ѯ�������·������Բ�ѯ��
//		ʹ��findByInstrumentID��Ψһ�ҵ�����
//	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
//	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
//		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
/////////////////////////////////////////////////////////////////////////
class CDepthMarketDataFactory 
	: public COutputTable, public CMemMITable<CDepthMarketData, Idx_Cont_DepthMarketData>
{
public:
	CDepthMarketDataFactory(const std::string &TableName);
	~CDepthMarketDataFactory(void);

	typedef Idx_Cont_DepthMarketData Data_Container_Type;
	typedef Idx_Cont_DepthMarketData Index_Container_Type;

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
	//@param	pDepthMarketData	  ��Ҫ��ˢ�»���������CDepthMarketData,����NULL��ʾ����Ҫ������
	//@param	pNewDepthMarketData	�µ�ֵ
	//@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	//@param	updateIndex	  �Ƿ���Ҫ��������
	//@param	���������޸ĺ������
	CDepthMarketData* addOrUpdate(CDepthMarketData *pDepthMarketData, CWriteableDepthMarketData *pNewDepthMarketData, CTransaction *pTransaction = NULL, bool updateIndex = true);

	//��ȡĳ��CDepthMarketData
	//@param	pDepthMarketData	Ҫ��ȡ��CDepthMarketData
	//@param	pTragetDepthMarketData	��Ž����CDepthMarketData
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
//CCommodityFactory��һ����Ʒ�Ķ��󹤳�����������һ����Ʒ��
//ͬʱ�ֽ����������������Է����ѯ��
//	CommodityIDIndex
//ʹ�ñ����󹤳���������ɶ���Ʒ����ɾ�Ĳ���������巽�����£�
//	���ӣ�����add����ɼ���
//	ɾ��������remove�Ϳ���ɾ��
//	��ѯ�������·������Բ�ѯ��
//		ʹ��findByCommodityID��Ψһ�ҵ�����
//	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
//	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
//		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
/////////////////////////////////////////////////////////////////////////
class CCommodityFactory 
	: public COutputTable, public CMemMITable<CCommodity, Idx_Cont_Commodity>
{
public:
	CCommodityFactory(const std::string &TableName);
	~CCommodityFactory(void);

	typedef Idx_Cont_Commodity Data_Container_Type;
	typedef Idx_Cont_Commodity Index_Container_Type;

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
	//@param	pCommodity	  ��Ҫ��ˢ�»���������CCommodity,����NULL��ʾ����Ҫ������
	//@param	pNewCommodity	�µ�ֵ
	//@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	//@param	updateIndex	  �Ƿ���Ҫ��������
	//@param	���������޸ĺ������
	CCommodity* addOrUpdate(CCommodity *pCommodity, CWriteableCommodity *pNewCommodity,
		CTransaction *pTransaction = nullptr, bool updateIndex = true);

	//��ȡĳ��CCommodity
	//@param	pCommodity	Ҫ��ȡ��CCommodity
	//@param	pTragetCommodity	��Ž����CCommodity
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
//CInstrumentFactory��һ����Լ�Ķ��󹤳�����������һ����Լ��
//ͬʱ�ֽ����������������Է����ѯ��
//	InstrumentIDIndex
//	CommodityIDIndex
//	ExchInstrumentIDIndex
//ʹ�ñ����󹤳���������ɶԺ�Լ����ɾ�Ĳ���������巽�����£�
//	���ӣ�����add����ɼ���
//	ɾ��������remove�Ϳ���ɾ��
//	��ѯ�������·������Բ�ѯ��
//		ʹ��findByInstrumentID��Ψһ�ҵ�����
//	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
//	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
//		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
/////////////////////////////////////////////////////////////////////////
class CInstrumentFactory 
	: public COutputTable, public CMemMITable<CInstrument, Idx_Cont_Instrument>
{
public:
	CInstrumentFactory(const std::string &TableName);
	~CInstrumentFactory(void);

	typedef Idx_Cont_Instrument Data_Container_Type;
	typedef Idx_Cont_Instrument Index_Container_Type;

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
	//@param	pInstrument	  ��Ҫ��ˢ�»���������CInstrument,����NULL��ʾ����Ҫ������
	//@param	pNewInstrument	�µ�ֵ
	//@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	//@param	updateIndex	  �Ƿ���Ҫ��������
	//@param	���������޸ĺ������
	CInstrument* addOrUpdate(CInstrument *pInstrument, CWriteableInstrument *pNewInstrument,
		CTransaction *pTransaction = nullptr, bool updateIndex = true);

	//��ȡĳ��CInstrument
	//@param	pInstrument	Ҫ��ȡ��CInstrument
	//@param	pTragetInstrument	��Ž����CInstrument
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
//COrderActionFactory��һ����Լ�޸ĵĶ��󹤳�����������һ����Լ�޸ģ�
//ͬʱ�ֽ����������������Է����ѯ��
//	InnerIDIndex
//	SysIDIndex
//ʹ�ñ����󹤳���������ɶԺ�Լ�޸ĵ���ɾ�Ĳ���������巽�����£�
//	���ӣ�����add����ɼ���
//	ɾ��������remove�Ϳ���ɾ��
//	��ѯ�������·������Բ�ѯ��
//	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
//	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
//		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
/////////////////////////////////////////////////////////////////////////
class COrderActionFactory 
	: public COutputTable, public CMemMITable<COrderAction, Idx_Cont_OrderAction>
{
public:
	COrderActionFactory(const std::string &TableName);
	~COrderActionFactory(void);

	typedef Idx_Cont_OrderAction Data_Container_Type;
	typedef Idx_Cont_OrderAction Index_Container_Type;

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
	//@param	pOrderAction	  ��Ҫ��ˢ�»���������COrderAction,����NULL��ʾ����Ҫ������
	//@param	pNewOrderAction	�µ�ֵ
	//@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	//@param	updateIndex	  �Ƿ���Ҫ��������
	//@param	���������޸ĺ������
	COrderAction* addOrUpdate(COrderAction *pOrderAction,
		CWriteableOrderAction *pNewOrderAction, CTransaction *pTransaction = nullptr,
		bool updateIndex = true);

	//��ȡĳ��COrderAction
	//@param	pOrderAction	Ҫ��ȡ��COrderAction
	//@param	pTragetOrderAction	��Ž����COrderAction
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
//CExchOrderActionFactory��һ����Լ�޸ĵĶ��󹤳�����������һ����Լ�޸ģ�
//ͬʱ�ֽ����������������Է����ѯ��
//	InnerIDIndex
//	SysIDIndex
//ʹ�ñ����󹤳���������ɶԺ�Լ�޸ĵ���ɾ�Ĳ���������巽�����£�
//	���ӣ�����add����ɼ���
//	ɾ��������remove�Ϳ���ɾ��
//	��ѯ�������·������Բ�ѯ��
//		ʹ��findByInstrumentID��Ψһ�ҵ�����
//	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
//	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
//		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
/////////////////////////////////////////////////////////////////////////
class CExchOrderActionFactory 
	: public COutputTable, public CMemMITable<CExchOrderAction, Idx_Cont_ExchOrderAction>
{
public:
	CExchOrderActionFactory(const std::string &TableName);
	~CExchOrderActionFactory(void);

	typedef Idx_Cont_ExchOrderAction Data_Container_Type;
	typedef Idx_Cont_ExchOrderAction Index_Container_Type;

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
	//@param	pExchOrderAction	  ��Ҫ��ˢ�»���������CExchOrderAction,����NULL��ʾ����Ҫ������
	//@param	pNewExchOrderAction	�µ�ֵ
	//@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	//@param	updateIndex	  �Ƿ���Ҫ��������
	//@param	���������޸ĺ������
	CExchOrderAction* addOrUpdate(CExchOrderAction *pExchOrderAction,
		CWriteableExchOrderAction *pNewExchOrderAction,
		CTransaction *pTransaction = nullptr, bool updateIndex = true);

	//��ȡĳ��CExchOrderAction
	//@param	pExchOrderAction	Ҫ��ȡ��CExchOrderAction
	//@param	pTragetExchOrderAction	��Ž����CExchOrderAction
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
//COrderFactory��һ�������Ķ��󹤳�����������һ��������
//ͬʱ�ֽ����������������Է����ѯ��
//	InnerIDIndex
//	OrderSysIDIndex
//	InstrumentIDIndex
//	OrderRefIndex
//ʹ�ñ����󹤳���������ɶԱ�������ɾ�Ĳ���������巽�����£�
//	���ӣ�����add����ɼ���
//	ɾ��������remove�Ϳ���ɾ��
//	��ѯ�������·������Բ�ѯ��
//		ʹ��findByOrderID��Ψһ�ҵ�����
//		ʹ��findByOrderLocalID��Ψһ�ҵ�����
//		ʹ��startFindByUserID��findNextByUserID��endFindByUserID��ɲ�ѯ����
//		ʹ��startFindByInstrumentID��findNextByInstrumentID��endFindByInstrumentID��ɲ�ѯ����
//		ʹ��startFindStartByInstrumentID��findNextStartByInstrumentID��endFindStartByInstrumentID��ɲ�ѯ����
//		ʹ��startFindByOrderRef��findNextByOrderRef��endFindByOrderRef��ɲ�ѯ����
//	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
//	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
//		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
/////////////////////////////////////////////////////////////////////////
class COrderFactory : public COutputTable, public CMemMITable<COrder, Idx_Cont_Order>
{
public:
	COrderFactory(const std::string &TableName);
	~COrderFactory(void);

	typedef Idx_Cont_Order Data_Container_Type;
	typedef Idx_Cont_Order Index_Container_Type;

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
	//@param	pOrder	  ��Ҫ��ˢ�»���������COrder,����NULL��ʾ����Ҫ������
	//@param	pNewOrder	�µ�ֵ
	//@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	//@param	updateIndex	  �Ƿ���Ҫ��������
	//@param	���������޸ĺ������
	COrder* addOrUpdate(COrder *pOrder, CWriteableOrder *pNewOrder,
		CTransaction *pTransaction = nullptr, bool updateIndex = true);

	//��ȡĳ��COrder
	//@param	pOrder	Ҫ��ȡ��COrder
	//@param	pTragetOrder	��Ž����COrder
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
//CTradeFactory��һ���ɽ��Ķ��󹤳�����������һ���ɽ���
//ͬʱ�ֽ����������������Է����ѯ��
//	TradeIDIndex
//	InstrumentIDIndex
//ʹ�ñ����󹤳���������ɶԳɽ�����ɾ�Ĳ���������巽�����£�
//	���ӣ�����add����ɼ���
//	ɾ��������remove�Ϳ���ɾ��
//	��ѯ�������·������Բ�ѯ��
//		ʹ��startFindStartByTradeID��findNextStartByTradeID��endFindStartByTradeID��ɲ�ѯ����
//		ʹ��startFindStartByInstrumentID��findNextStartByInstrumentID��endFindStartByInstrumentID��ɲ�ѯ����
//	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
//	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
//		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
/////////////////////////////////////////////////////////////////////////
class CTradeFactory : public COutputTable, public CMemMITable<CTrade, Idx_Cont_Trade>
{
public:
	CTradeFactory(const std::string &TableName);
	~CTradeFactory(void);

	typedef Idx_Cont_Trade Data_Container_Type;
	typedef Idx_Cont_Trade Index_Container_Type;

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
	//@param	pTrade	  ��Ҫ��ˢ�»���������CTrade,����NULL��ʾ����Ҫ������
	//@param	pNewTrade	�µ�ֵ
	//@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	//@param	updateIndex	  �Ƿ���Ҫ��������
	//@param	���������޸ĺ������
	CTrade* addOrUpdate(CTrade *pTrade, CWriteableTrade *pNewTrade,
		CTransaction *pTransaction = nullptr, bool updateIndex = true);

	//��ȡĳ��CTrade
	//@param	pTrade	Ҫ��ȡ��CTrade
	//@param	pTragetTrade	��Ž����CTrade
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
//CEsfInstPartInfoFactory��һ����Լ������Ϣ�Ķ��󹤳�����������һ����Լ������Ϣ��
//ͬʱ�ֽ����������������Է����ѯ��
//	InstrumentIDIndex
//ʹ�ñ����󹤳���������ɶԺ�Լ������Ϣ����ɾ�Ĳ���������巽�����£�
//	���ӣ�����add����ɼ���
//	ɾ��������remove�Ϳ���ɾ��
//	��ѯ�������·������Բ�ѯ��
//	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
//	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
//		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
/////////////////////////////////////////////////////////////////////////
class CEsfInstPartInfoFactory 
	: public COutputTable, public CMemMITable<CEsfInstPartInfo, Idx_Cont_EsfInstPartInfo>
{
public:
	CEsfInstPartInfoFactory(const std::string &TableName);
	~CEsfInstPartInfoFactory(void);

	typedef Idx_Cont_EsfInstPartInfo Data_Container_Type;
	typedef Idx_Cont_EsfInstPartInfo Index_Container_Type;

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
	//@param	pEsfInstPartInfo	  ��Ҫ��ˢ�»���������CEsfInstPartInfo,����NULL��ʾ����Ҫ������
	//@param	pNewEsfInstPartInfo	�µ�ֵ
	//@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	//@param	updateIndex	  �Ƿ���Ҫ��������
	//@param	���������޸ĺ������
	CEsfInstPartInfo* addOrUpdate(CEsfInstPartInfo *pEsfInstPartInfo,
		CWriteableEsfInstPartInfo *pNewEsfInstPartInfo,
		CTransaction *pTransaction = nullptr, bool updateIndex = true);

	//��ȡĳ��CEsfInstPartInfo
	//@param	pEsfInstPartInfo	Ҫ��ȡ��CEsfInstPartInfo
	//@param	pTragetEsfInstPartInfo	��Ž����CEsfInstPartInfo
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
//CCurrencyFactory��һ��������Ϣ�Ķ��󹤳�����������һ��������Ϣ��
//ͬʱ�ֽ����������������Է����ѯ��
//	CurrencyIDIndex
//ʹ�ñ����󹤳���������ɶԱ�����Ϣ����ɾ�Ĳ���������巽�����£�
//	���ӣ�����add����ɼ���
//	ɾ��������remove�Ϳ���ɾ��
//	��ѯ�������·������Բ�ѯ��
//	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
//	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
//		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
/////////////////////////////////////////////////////////////////////////
class CCurrencyFactory : public COutputTable, public CMemMITable<CCurrency, Idx_Cont_Currency>
{
public:
	CCurrencyFactory(const std::string &TableName);
	~CCurrencyFactory(void);

	typedef Idx_Cont_Currency Data_Container_Type;
	typedef Idx_Cont_Currency Index_Container_Type;

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
	//@param	pCurrency	  ��Ҫ��ˢ�»���������CCurrency,����NULL��ʾ����Ҫ������
	//@param	pNewCurrency	�µ�ֵ
	//@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	//@param	updateIndex	  �Ƿ���Ҫ��������
	//@param	���������޸ĺ������
	CCurrency* addOrUpdate(CCurrency *pCurrency, CWriteableCurrency *pNewCurrency,
		CTransaction *pTransaction = nullptr, bool updateIndex = true);

	//��ȡĳ��CCurrency
	//@param	pCurrency	Ҫ��ȡ��CCurrency
	//@param	pTragetCurrency	��Ž����CCurrency
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
//CExchUserLoginFactory��һ�������û���¼�Ķ��󹤳�����������һ�������û���¼��
//ͬʱ�ֽ����������������Է����ѯ��
//	TradeUserIDIndex
//ʹ�ñ����󹤳���������ɶԽ����û���¼����ɾ�Ĳ���������巽�����£�
//	���ӣ�����add����ɼ���
//	ɾ��������remove�Ϳ���ɾ��
//	��ѯ�������·������Բ�ѯ��
//		ʹ��findByUserID��Ψһ�ҵ�����
//	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
//	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
//		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
/////////////////////////////////////////////////////////////////////////
class CExchUserLoginFactory : public COutputTable, public CMemMITable<CExchUserLogin, Idx_Cont_ExchUserLogin>
{
public:
	CExchUserLoginFactory(const std::string &TableName);
	~CExchUserLoginFactory(void);

	typedef Idx_Cont_ExchUserLogin Data_Container_Type;
	typedef Idx_Cont_ExchUserLogin Index_Container_Type;

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
	//@param	pExchUserLogin	  ��Ҫ��ˢ�»���������CExchUserLogin,����NULL��ʾ����Ҫ������
	//@param	pNewExchUserLogin	�µ�ֵ
	//@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	//@param	updateIndex	  �Ƿ���Ҫ��������
	//@param	���������޸ĺ������
	CExchUserLogin* addOrUpdate(CExchUserLogin *pExchUserLogin,
		CWriteableExchUserLogin *pNewExchUserLogin,
		CTransaction *pTransaction = nullptr, bool updateIndex = true);

	//��ȡĳ��CExchUserLogin
	//@param	pExchUserLogin	Ҫ��ȡ��CExchUserLogin
	//@param	pTragetExchUserLogin	��Ž����CExchUserLogin
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
//CExchUserLogoutFactory��һ�������û��ǳ��Ķ��󹤳�����������һ�������û��ǳ���
//ͬʱ�ֽ����������������Է����ѯ��
//	TradeUserIDIndex
//ʹ�ñ����󹤳���������ɶԽ����û��ǳ�����ɾ�Ĳ���������巽�����£�
//	���ӣ�����add����ɼ���
//	ɾ��������remove�Ϳ���ɾ��
//	��ѯ�������·������Բ�ѯ��
//		ʹ��findByUserID��Ψһ�ҵ�����
//	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
//	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
//		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
/////////////////////////////////////////////////////////////////////////
class CExchUserLogoutFactory : public COutputTable, public CMemMITable<CExchUserLogout, Idx_Cont_ExchUserLogout>
{
public:
	CExchUserLogoutFactory(const std::string &TableName);
	~CExchUserLogoutFactory(void);

	typedef Idx_Cont_ExchUserLogout Data_Container_Type;
	typedef Idx_Cont_ExchUserLogout Index_Container_Type;

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
	//@param	pExchUserLogout	  ��Ҫ��ˢ�»���������CExchUserLogout,����NULL��ʾ����Ҫ������
	//@param	pNewExchUserLogout	�µ�ֵ
	//@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	//@param	updateIndex	  �Ƿ���Ҫ��������
	//@param	���������޸ĺ������
	CExchUserLogout* addOrUpdate(CExchUserLogout *pExchUserLogout,
		CWriteableExchUserLogout *pNewExchUserLogout,
		CTransaction *pTransaction = nullptr, bool updateIndex = true);

	//��ȡĳ��CExchUserLogout
	//@param	pExchUserLogout	Ҫ��ȡ��CExchUserLogout
	//@param	pTragetExchUserLogout	��Ž����CExchUserLogout
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
//CExchMDUserLoginFactory��һ�������û���¼�Ķ��󹤳�����������һ�������û���¼��
//ͬʱ�ֽ����������������Է����ѯ��
//	MDUserIDIndex
//ʹ�ñ����󹤳���������ɶ������û���¼����ɾ�Ĳ���������巽�����£�
//	���ӣ�����add����ɼ���
//	ɾ��������remove�Ϳ���ɾ��
//	��ѯ�������·������Բ�ѯ��
//		ʹ��findByUserID��Ψһ�ҵ�����
//	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
//	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
//		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
/////////////////////////////////////////////////////////////////////////
class CExchMDUserLoginFactory : public COutputTable, public CMemMITable<CExchMDUserLogin, Idx_Cont_ExchMDUserLogin>
{
public:
	CExchMDUserLoginFactory(const std::string &TableName);
	~CExchMDUserLoginFactory(void);

	typedef Idx_Cont_ExchMDUserLogin Data_Container_Type;
	typedef Idx_Cont_ExchMDUserLogin Index_Container_Type;

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
	//@param	pExchMDUserLogin	  ��Ҫ��ˢ�»���������CExchMDUserLogin,����NULL��ʾ����Ҫ������
	//@param	pNewExchMDUserLogin	�µ�ֵ
	//@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	//@param	updateIndex	  �Ƿ���Ҫ��������
	//@param	���������޸ĺ������
	CExchMDUserLogin* addOrUpdate(CExchMDUserLogin *pExchMDUserLogin,
		CWriteableExchMDUserLogin *pNewExchMDUserLogin,
		CTransaction *pTransaction = nullptr, bool updateIndex = true);

	//��ȡĳ��CExchMDUserLogin
	//@param	pExchMDUserLogin	Ҫ��ȡ��CExchMDUserLogin
	//@param	pTragetExchMDUserLogin	��Ž����CExchMDUserLogin
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
//CExchMDUserLogoutFactory��һ�������û��ǳ��Ķ��󹤳�����������һ�������û��ǳ���
//ͬʱ�ֽ����������������Է����ѯ��
//	MDUserIDIndex
//ʹ�ñ����󹤳���������ɶ������û��ǳ�����ɾ�Ĳ���������巽�����£�
//	���ӣ�����add����ɼ���
//	ɾ��������remove�Ϳ���ɾ��
//	��ѯ�������·������Բ�ѯ��
//		ʹ��findByUserID��Ψһ�ҵ�����
//	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
//	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
//		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
/////////////////////////////////////////////////////////////////////////
class CExchMDUserLogoutFactory : public COutputTable, public CMemMITable<CExchMDUserLogout, Idx_Cont_ExchMDUserLogout>
{
public:
	CExchMDUserLogoutFactory(const std::string &TableName);
	~CExchMDUserLogoutFactory(void);

	typedef Idx_Cont_ExchMDUserLogout Data_Container_Type;
	typedef Idx_Cont_ExchMDUserLogout Index_Container_Type;

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
	//@param	pExchMDUserLogout	  ��Ҫ��ˢ�»���������CExchMDUserLogout,����NULL��ʾ����Ҫ������
	//@param	pNewExchMDUserLogout	�µ�ֵ
	//@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	//@param	updateIndex	  �Ƿ���Ҫ��������
	//@param	���������޸ĺ������
	CExchMDUserLogout* addOrUpdate(CExchMDUserLogout *pExchMDUserLogout,
		CWriteableExchMDUserLogout *pNewExchMDUserLogout,
		CTransaction *pTransaction = nullptr, bool updateIndex = true);

	//��ȡĳ��CExchMDUserLogout
	//@param	pExchMDUserLogout	Ҫ��ȡ��CExchMDUserLogout
	//@param	pTragetExchMDUserLogout	��Ž����CExchMDUserLogout
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
//CExchOrderFactory��һ�������Ķ��󹤳�����������һ��������
//ͬʱ�ֽ����������������Է����ѯ��
//	InnerIDIndex
//	OrderSysIDIndex
//ʹ�ñ����󹤳���������ɶԱ�������ɾ�Ĳ���������巽�����£�
//	���ӣ�����add����ɼ���
//	ɾ��������remove�Ϳ���ɾ��
//	��ѯ�������·������Բ�ѯ��
//		ʹ��findByOrderID��Ψһ�ҵ�����
//		ʹ��findByOrderLocalID��Ψһ�ҵ�����
//		ʹ��startFindByUserID��findNextByUserID��endFindByUserID��ɲ�ѯ����
//		ʹ��startFindByInstrumentID��findNextByInstrumentID��endFindByInstrumentID��ɲ�ѯ����
//		ʹ��startFindStartByInstrumentID��findNextStartByInstrumentID��endFindStartByInstrumentID��ɲ�ѯ����
//	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
//	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
//		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
/////////////////////////////////////////////////////////////////////////
class CExchOrderFactory : public COutputTable, public CMemMITable<CExchOrder, Idx_Cont_ExchOrder>
{
public:
	CExchOrderFactory(const std::string &TableName);
	~CExchOrderFactory(void);

	typedef Idx_Cont_ExchOrder Data_Container_Type;
	typedef Idx_Cont_ExchOrder Index_Container_Type;

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
	//@param	pExchOrder	  ��Ҫ��ˢ�»���������CExchOrder,����NULL��ʾ����Ҫ������
	//@param	pNewExchOrder	�µ�ֵ
	//@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	//@param	updateIndex	  �Ƿ���Ҫ��������
	//@param	���������޸ĺ������
	CExchOrder* addOrUpdate(CExchOrder *pExchOrder, CWriteableExchOrder *pNewExchOrder,
		CTransaction *pTransaction = nullptr, bool updateIndex = true);

	//��ȡĳ��CExchOrder
	//@param	pExchOrder	Ҫ��ȡ��CExchOrder
	//@param	pTragetExchOrder	��Ž����CExchOrder
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
//CExchTradeFactory��һ���ɽ��Ķ��󹤳�����������һ���ɽ���
//ͬʱ�ֽ����������������Է����ѯ��
//	TradeIDIndex
//	InstrumentIDIndex
//ʹ�ñ����󹤳���������ɶԳɽ�����ɾ�Ĳ���������巽�����£�
//	���ӣ�����add����ɼ���
//	ɾ��������remove�Ϳ���ɾ��
//	��ѯ�������·������Բ�ѯ��
//		ʹ��startFindStartByTradeID��findNextStartByTradeID��endFindStartByTradeID��ɲ�ѯ����
//		ʹ��startFindStartByInstrumentID��findNextStartByInstrumentID��endFindStartByInstrumentID��ɲ�ѯ����
//	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
//	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
//		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
/////////////////////////////////////////////////////////////////////////
class CExchTradeFactory : public COutputTable, public CMemMITable<CExchTrade, Idx_Cont_ExchTrade>
{
public:
	CExchTradeFactory(const std::string &TableName);
	~CExchTradeFactory(void);

	typedef Idx_Cont_ExchTrade Data_Container_Type;
	typedef Idx_Cont_ExchTrade Index_Container_Type;

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
	//@param	pExchTrade	  ��Ҫ��ˢ�»���������CExchTrade,����NULL��ʾ����Ҫ������
	//@param	pNewExchTrade	�µ�ֵ
	//@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	//@param	updateIndex	  �Ƿ���Ҫ��������
	//@param	���������޸ĺ������
	CExchTrade* addOrUpdate(CExchTrade *pExchTrade, CWriteableExchTrade *pNewExchTrade,
		CTransaction *pTransaction = nullptr, bool updateIndex = true);

	//��ȡĳ��CExchTrade
	//@param	pExchTrade	Ҫ��ȡ��CExchTrade
	//@param	pTragetExchTrade	��Ž����CExchTrade
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
//CExchInvestorPositionFactory��һ��Ͷ���߲�λ�Ķ��󹤳�����������һ��Ͷ���߲�λ��
//ͬʱ�ֽ����������������Է����ѯ��
//	InvestorIDIndex
//ʹ�ñ����󹤳���������ɶ�Ͷ���߲�λ����ɾ�Ĳ���������巽�����£�
//	���ӣ�����add����ɼ���
//	ɾ��������remove�Ϳ���ɾ��
//	��ѯ�������·������Բ�ѯ��
//		ʹ��findByInvestorID��Ψһ�ҵ�����
//	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
//	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
//		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
/////////////////////////////////////////////////////////////////////////
class CExchInvestorPositionFactory : public COutputTable, public CMemMITable<CExchInvestorPosition, Idx_Cont_ExchInvestorPosition>
{
public:
	CExchInvestorPositionFactory(const std::string &TableName);
	~CExchInvestorPositionFactory(void);

	typedef Idx_Cont_ExchInvestorPosition Data_Container_Type;
	typedef Idx_Cont_ExchInvestorPosition Index_Container_Type;

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
	//@param	pExchInvestorPosition	  ��Ҫ��ˢ�»���������CExchInvestorPosition,����NULL��ʾ����Ҫ������
	//@param	pNewExchInvestorPosition	�µ�ֵ
	//@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	//@param	updateIndex	  �Ƿ���Ҫ��������
	//@param	���������޸ĺ������
	CExchInvestorPosition* addOrUpdate(CExchInvestorPosition *pExchInvestorPosition,
		CWriteableExchInvestorPosition *pNewExchInvestorPosition,
		CTransaction *pTransaction = nullptr, bool updateIndex = true);

	//��ȡĳ��CExchInvestorPosition
	//@param	pExchInvestorPosition	Ҫ��ȡ��CExchInvestorPosition
	//@param	pTragetExchInvestorPosition	��Ž����CExchInvestorPosition
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
//CExchInvestorAccountFactory��һ��Ͷ�����ʽ�Ķ��󹤳�����������һ��Ͷ�����ʽ�
//ͬʱ�ֽ����������������Է����ѯ��
//	InvestorIDIndex
//ʹ�ñ����󹤳���������ɶ�Ͷ�����ʽ����ɾ�Ĳ���������巽�����£�
//	���ӣ�����add����ɼ���
//	ɾ��������remove�Ϳ���ɾ��
//	��ѯ�������·������Բ�ѯ��
//		ʹ��findByInvestorID��Ψһ�ҵ�����
//	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
//	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
//		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
/////////////////////////////////////////////////////////////////////////
class CExchInvestorAccountFactory 
	: public COutputTable, public CMemMITable<CExchInvestorAccount, Idx_Cont_ExchInvestorAccount>
{
public:
	CExchInvestorAccountFactory(const std::string &TableName);
	~CExchInvestorAccountFactory(void);

	typedef Idx_Cont_ExchInvestorAccount Data_Container_Type;
	typedef Idx_Cont_ExchInvestorAccount Index_Container_Type;

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
	//@param	pExchInvestorAccount	  ��Ҫ��ˢ�»���������CExchInvestorAccount,����NULL��ʾ����Ҫ������
	//@param	pNewExchInvestorAccount	�µ�ֵ
	//@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	//@param	updateIndex	  �Ƿ���Ҫ��������
	//@param	���������޸ĺ������
	CExchInvestorAccount* addOrUpdate(CExchInvestorAccount *pExchInvestorAccount,
		CWriteableExchInvestorAccount *pNewExchInvestorAccount,
		CTransaction *pTransaction = nullptr, bool updateIndex = true);

	//��ȡĳ��CExchInvestorAccount
	//@param	pExchInvestorAccount	Ҫ��ȡ��CExchInvestorAccount
	//@param	pTragetExchInvestorAccount	��Ž����CExchInvestorAccount
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
//CExchDepthMarketDataFactory��һ���������Ķ��󹤳�����������һ��������飬
//ͬʱ�ֽ����������������Է����ѯ��
//	InstrumentIDIndex
//ʹ�ñ����󹤳���������ɶ�����������ɾ�Ĳ���������巽�����£�
//	���ӣ�����add����ɼ���
//	ɾ��������remove�Ϳ���ɾ��
//	��ѯ�������·������Բ�ѯ��
//		ʹ��findByInstrumentID��Ψһ�ҵ�����
//	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
//	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
//		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
/////////////////////////////////////////////////////////////////////////
class CExchDepthMarketDataFactory : public COutputTable, public CMemMITable<CExchDepthMarketData, Idx_Cont_ExchDepthMarketData>
{
public:
	CExchDepthMarketDataFactory(const std::string &TableName);
	~CExchDepthMarketDataFactory(void);

	typedef Idx_Cont_ExchDepthMarketData Data_Container_Type;
	typedef Idx_Cont_ExchDepthMarketData Index_Container_Type;

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
	//@param	pExchDepthMarketData	  ��Ҫ��ˢ�»���������CExchDepthMarketData,����NULL��ʾ����Ҫ������
	//@param	pNewExchDepthMarketData	�µ�ֵ
	//@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	//@param	updateIndex	  �Ƿ���Ҫ��������
	//@param	���������޸ĺ������
	CExchDepthMarketData* addOrUpdate(CExchDepthMarketData *pExchDepthMarketData,
		CWriteableExchDepthMarketData *pNewExchDepthMarketData,
		CTransaction *pTransaction = nullptr, bool updateIndex = true);

	//��ȡĳ��CExchDepthMarketData
	//@param	pExchDepthMarketData	Ҫ��ȡ��CExchDepthMarketData
	//@param	pTragetExchDepthMarketData	��Ž����CExchDepthMarketData
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
//CExchDepthMarketHistoryDataFactory��һ�����������ʷ�Ķ��󹤳�����������һ�����������ʷ��
//ͬʱ�ֽ����������������Է����ѯ��
//	InstrumentTimeIndex
//ʹ�ñ����󹤳���������ɶ����������ʷ����ɾ�Ĳ���������巽�����£�
//	���ӣ�����add����ɼ���
//	ɾ��������remove�Ϳ���ɾ��
//	��ѯ�������·������Բ�ѯ��
//		ʹ��findByInstrumentID��Ψһ�ҵ�����
//	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
//	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
//		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
/////////////////////////////////////////////////////////////////////////
class CExchDepthMarketHistoryDataFactory : public COutputTable, public CMemMITable<CExchDepthMarketHistoryData, Idx_Cont_ExchDepthMarketHistoryData>
{
public:
	CExchDepthMarketHistoryDataFactory(const std::string &TableName);
	~CExchDepthMarketHistoryDataFactory(void);

	typedef Idx_Cont_ExchDepthMarketHistoryData Data_Container_Type;
	typedef Idx_Cont_ExchDepthMarketHistoryData Index_Container_Type;

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
	//@param	pExchDepthMarketHistoryData	  ��Ҫ��ˢ�»���������CExchDepthMarketHistoryData,����NULL��ʾ����Ҫ������
	//@param	pNewExchDepthMarketHistoryData	�µ�ֵ
	//@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	//@param	updateIndex	  �Ƿ���Ҫ��������
	//@param	���������޸ĺ������
	CExchDepthMarketHistoryData* addOrUpdate(CExchDepthMarketHistoryData *pExchDepthMarketHistoryData, CWriteableExchDepthMarketHistoryData *pNewExchDepthMarketHistoryData, CTransaction *pTransaction = NULL, bool updateIndex = true);

	//��ȡĳ��CExchDepthMarketHistoryData
	//@param	pExchDepthMarketHistoryData	Ҫ��ȡ��CExchDepthMarketHistoryData
	//@param	pTragetExchDepthMarketHistoryData	��Ž����CExchDepthMarketHistoryData
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
//CExchInstrumentFactory��һ����Լ�Ķ��󹤳�����������һ����Լ��
//ͬʱ�ֽ����������������Է����ѯ��
//	InstrumentIDIndex
//	CommodityIDIndex
//	ExchInstrumentIDIndex
//ʹ�ñ����󹤳���������ɶԺ�Լ����ɾ�Ĳ���������巽�����£�
//	���ӣ�����add����ɼ���
//	ɾ��������remove�Ϳ���ɾ��
//	��ѯ�������·������Բ�ѯ��
//		ʹ��findByInstrumentID��Ψһ�ҵ�����
//	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
//	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
//		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
/////////////////////////////////////////////////////////////////////////
class CExchInstrumentFactory : public COutputTable, public CMemMITable<CExchInstrument, Idx_Cont_ExchInstrument>
{
public:
	CExchInstrumentFactory(const std::string &TableName);
	~CExchInstrumentFactory(void);

	typedef Idx_Cont_ExchInstrument Data_Container_Type;
	typedef Idx_Cont_ExchInstrument Index_Container_Type;

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
	//@param	pExchInstrument	  ��Ҫ��ˢ�»���������CExchInstrument,����NULL��ʾ����Ҫ������
	//@param	pNewExchInstrument	�µ�ֵ
	//@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	//@param	updateIndex	  �Ƿ���Ҫ��������
	//@param	���������޸ĺ������
	CExchInstrument* addOrUpdate(CExchInstrument *pExchInstrument,
		CWriteableExchInstrument *pNewExchInstrument,
		CTransaction *pTransaction = nullptr, bool updateIndex = true);

	//��ȡĳ��CExchInstrument
	//@param	pExchInstrument	Ҫ��ȡ��CExchInstrument
	//@param	pTragetExchInstrument	��Ž����CExchInstrument
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
//CExchInstrumentStatusFactory��һ����Լ�Ķ��󹤳�����������һ����Լ��
//ͬʱ�ֽ����������������Է����ѯ��
//	InstrumentIDIndex
//	ExchInstrumentIDIndex
//ʹ�ñ����󹤳���������ɶԺ�Լ����ɾ�Ĳ���������巽�����£�
//	���ӣ�����add����ɼ���
//	ɾ��������remove�Ϳ���ɾ��
//	��ѯ�������·������Բ�ѯ��
//		ʹ��findByInstrumentID��Ψһ�ҵ�����
//	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
//	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
//		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
/////////////////////////////////////////////////////////////////////////
class CExchInstrumentStatusFactory : public COutputTable, public CMemMITable<CExchInstrumentStatus, Idx_Cont_ExchInstrumentStatus>
{
public:
	CExchInstrumentStatusFactory(const std::string &TableName);
	~CExchInstrumentStatusFactory(void);

	typedef Idx_Cont_ExchInstrumentStatus Data_Container_Type;
	typedef Idx_Cont_ExchInstrumentStatus Index_Container_Type;

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
	//@param	pExchInstrumentStatus	  ��Ҫ��ˢ�»���������CExchInstrumentStatus,����NULL��ʾ����Ҫ������
	//@param	pNewExchInstrumentStatus	�µ�ֵ
	//@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	//@param	updateIndex	  �Ƿ���Ҫ��������
	//@param	���������޸ĺ������
	CExchInstrumentStatus* addOrUpdate(CExchInstrumentStatus *pExchInstrumentStatus,
		CWriteableExchInstrumentStatus *pNewExchInstrumentStatus,
		CTransaction *pTransaction = nullptr, bool updateIndex = true);

	//��ȡĳ��CExchInstrumentStatus
	//@param	pExchInstrumentStatus	Ҫ��ȡ��CExchInstrumentStatus
	//@param	pTragetExchInstrumentStatus	��Ž����CExchInstrumentStatus
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
//CPhyAccountFactory��һ�������˺ŵĶ��󹤳�����������һ�������˺ţ�
//ͬʱ�ֽ����������������Է����ѯ��
//	UserIDIdx
//ʹ�ñ����󹤳���������ɶ������˺ŵ���ɾ�Ĳ���������巽�����£�
//	���ӣ�����add����ɼ���
//	ɾ��������remove�Ϳ���ɾ��
//	��ѯ�������·������Բ�ѯ��
//	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
//	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
//		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
/////////////////////////////////////////////////////////////////////////
class CPhyAccountFactory 
	: public COutputTable, public CMemMITable<CPhyAccount, Idx_Cont_PhyAccount>
{
public:
	CPhyAccountFactory(const std::string &TableName);
	~CPhyAccountFactory(void);

	typedef Idx_Cont_PhyAccount Data_Container_Type;
	typedef Idx_Cont_PhyAccount Index_Container_Type;

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
	//@param	pPhyAccount	  ��Ҫ��ˢ�»���������CPhyAccount,����NULL��ʾ����Ҫ������
	//@param	pNewPhyAccount	�µ�ֵ
	//@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	//@param	updateIndex	  �Ƿ���Ҫ��������
	//@param	���������޸ĺ������
	CPhyAccount* addOrUpdate(CPhyAccount *pPhyAccount, CWriteablePhyAccount *pNewPhyAccount,
		CTransaction *pTransaction = nullptr, bool updateIndex = true);

	//��ȡĳ��CPhyAccount
	//@param	pPhyAccount	Ҫ��ȡ��CPhyAccount
	//@param	pTragetPhyAccount	��Ž����CPhyAccount
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
//CInvestorPositionFactory��һ���ֲ���Ϣ�Ķ��󹤳�����������һ���ֲ���Ϣ��
//ͬʱ�ֽ����������������Է����ѯ��
//	InstDirectIndex
//ʹ�ñ����󹤳���������ɶԳֲ���Ϣ����ɾ�Ĳ���������巽�����£�
//	���ӣ�����add����ɼ���
//	ɾ��������remove�Ϳ���ɾ��
//	��ѯ�������·������Բ�ѯ��
//		ʹ��findByInvestorID��Ψһ�ҵ�����
//	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
//	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
//		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
/////////////////////////////////////////////////////////////////////////
class CInvestorPositionFactory : public COutputTable, public CMemMITable<CInvestorPosition, Idx_Cont_InvestorPosition>
{
public:
	CInvestorPositionFactory(const std::string &TableName);
	~CInvestorPositionFactory(void);

	typedef Idx_Cont_InvestorPosition Data_Container_Type;
	typedef Idx_Cont_InvestorPosition Index_Container_Type;

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
	//@param	pInvestorPosition	  ��Ҫ��ˢ�»���������CInvestorPosition,����NULL��ʾ����Ҫ������
	//@param	pNewInvestorPosition	�µ�ֵ
	//@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	//@param	updateIndex	  �Ƿ���Ҫ��������
	//@param	���������޸ĺ������
	CInvestorPosition* addOrUpdate(CInvestorPosition *pInvestorPosition,
		CWriteableInvestorPosition *pNewInvestorPosition,
		CTransaction *pTransaction = nullptr, bool updateIndex = true);

	//��ȡĳ��CInvestorPosition
	//@param	pInvestorPosition	Ҫ��ȡ��CInvestorPosition
	//@param	pTragetInvestorPosition	��Ž����CInvestorPosition
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
//CRuleInfoFactory��һ��������Ϣ�Ķ��󹤳�����������һ��������Ϣ��
//ͬʱ�ֽ����������������Է����ѯ��
//	RuleIDIdx
//ʹ�ñ����󹤳���������ɶԲ�����Ϣ����ɾ�Ĳ���������巽�����£�
//	���ӣ�����add����ɼ���
//	ɾ��������remove�Ϳ���ɾ��
//	��ѯ�������·������Բ�ѯ��
//	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
//	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
//		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
/////////////////////////////////////////////////////////////////////////
class CRuleInfoFactory : public COutputTable, public CMemMITable<CRuleInfo, Idx_Cont_RuleInfo>
{
public:
	CRuleInfoFactory(const std::string &TableName);
	~CRuleInfoFactory(void);

	typedef Idx_Cont_RuleInfo Data_Container_Type;
	typedef Idx_Cont_RuleInfo Index_Container_Type;

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
	//@param	pRuleInfo	  ��Ҫ��ˢ�»���������CRuleInfo,����NULL��ʾ����Ҫ������
	//@param	pNewRuleInfo	�µ�ֵ
	//@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	//@param	updateIndex	  �Ƿ���Ҫ��������
	//@param	���������޸ĺ������
	CRuleInfo* addOrUpdate(CRuleInfo *pRuleInfo, CWriteableRuleInfo *pNewRuleInfo,
		CTransaction *pTransaction = nullptr, bool updateIndex = true);

	//��ȡĳ��CRuleInfo
	//@param	pRuleInfo	Ҫ��ȡ��CRuleInfo
	//@param	pTragetRuleInfo	��Ž����CRuleInfo
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
//CExchInvestorFeeFactory��һ��Ͷ�����������ʵĶ��󹤳�����������һ��Ͷ�����������ʣ�
//ͬʱ�ֽ����������������Է����ѯ��
//	ExchInstrumentIDIndex
//ʹ�ñ����󹤳���������ɶ�Ͷ�����������ʵ���ɾ�Ĳ���������巽�����£�
//	���ӣ�����add����ɼ���
//	ɾ��������remove�Ϳ���ɾ��
//	��ѯ�������·������Բ�ѯ��
//		ʹ��findByExchInstrumentID��Ψһ�ҵ�����
//	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
//	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
//		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
/////////////////////////////////////////////////////////////////////////
class CExchInvestorFeeFactory : public COutputTable, public CMemMITable<CExchInvestorFee, Idx_Cont_ExchInvestorFee>
{
public:
	CExchInvestorFeeFactory(const std::string &TableName);
	~CExchInvestorFeeFactory(void);

	typedef Idx_Cont_ExchInvestorFee Data_Container_Type;
	typedef Idx_Cont_ExchInvestorFee Index_Container_Type;

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
	//@param	pExchInvestorFee	  ��Ҫ��ˢ�»���������CExchInvestorFee,����NULL��ʾ����Ҫ������
	//@param	pNewExchInvestorFee	�µ�ֵ
	//@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	//@param	updateIndex	  �Ƿ���Ҫ��������
	//@param	���������޸ĺ������
	CExchInvestorFee* addOrUpdate(CExchInvestorFee *pExchInvestorFee,
		CWriteableExchInvestorFee *pNewExchInvestorFee,
		CTransaction *pTransaction = nullptr, bool updateIndex = true);

	//��ȡĳ��CExchInvestorFee
	//@param	pExchInvestorFee	Ҫ��ȡ��CExchInvestorFee
	//@param	pTragetExchInvestorFee	��Ž����CExchInvestorFee
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
//CExchInvestorMarginFactory��һ�����ױ�֤���ʵĶ��󹤳�����������һ�����ױ�֤���ʣ�
//ͬʱ�ֽ����������������Է����ѯ��
//	ExchInstrumentIDIndex
//ʹ�ñ����󹤳���������ɶԽ��ױ�֤���ʵ���ɾ�Ĳ���������巽�����£�
//	���ӣ�����add����ɼ���
//	ɾ��������remove�Ϳ���ɾ��
//	��ѯ�������·������Բ�ѯ��
//		ʹ��findByExchInstrumentID��Ψһ�ҵ�����
//	�޸ģ����ڲ鵽�Ľ��������ͨ��retrieveȡ�����޸ĺ�ͨ��update�Ż�
//	����������е����ӡ�ɾ�����޸Ķ�����ָ������������commitʱ������д��
//		��retrieveʱ��Ҳ����ָ�����񣬴�ʱ��ȡ������update��������
/////////////////////////////////////////////////////////////////////////
class CExchInvestorMarginFactory : public COutputTable, public CMemMITable<CExchInvestorMargin, Idx_Cont_ExchInvestorMargin>
{
public:
	CExchInvestorMarginFactory(const std::string &TableName);
	~CExchInvestorMarginFactory(void);

	typedef Idx_Cont_ExchInvestorMargin Data_Container_Type;
	typedef Idx_Cont_ExchInvestorMargin Index_Container_Type;

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
	//@param	pExchInvestorMargin	  ��Ҫ��ˢ�»���������CExchInvestorMargin,����NULL��ʾ����Ҫ������
	//@param	pNewExchInvestorMargin	�µ�ֵ
	//@param	pTransaction	���β������������������NULL����ʾ��ʹ���������������Ч��������Ҫ�ڸ�����commitʱ��Ч
	//@param	updateIndex	  �Ƿ���Ҫ��������
	//@param	���������޸ĺ������
	CExchInvestorMargin* addOrUpdate(CExchInvestorMargin *pExchInvestorMargin,
		CWriteableExchInvestorMargin *pNewExchInvestorMargin,
		CTransaction *pTransaction = nullptr, bool updateIndex = true);

	//��ȡĳ��CExchInvestorMargin
	//@param	pExchInvestorMargin	Ҫ��ȡ��CExchInvestorMargin
	//@param	pTragetExchInvestorMargin	��Ž����CExchInvestorMargin
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
