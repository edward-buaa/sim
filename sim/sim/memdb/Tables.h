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
	int writeCSV(CConfig *pConfig);
	int readCSV(const char *filename);
	int readCSV(CConfig *pConfig);

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






#endif
