#ifndef __TABLES_DEFINE_H__
#define __TABLES_DEFINE_H__

/*
���ܣ������ڴ����ݿ�ı�
*/

#include "OutputTable.h"
#include "mem_mi_table.h"


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
//	: public COutputTable,
//	  public CMemMITable<CCurrentTime, Idx_Cont_CurrentTime>
{
public:
	explicit CCurrentTimeFactory(const std::string& TableName);
};

#endif
