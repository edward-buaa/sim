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
