#ifndef __RECORD_STRUCT_H__
#define __RECORD_STRUCT_H__

#include "../network/field_describe.h"
#include "../customDataType/customDataType.h"

/////////////////////////////////////////////////////////////////////////
///CWriteableCurrentTime��һ���洢[��ǰʱ��]�Ķ��󣬿���д����
///@author	RE
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrentTime
{
public:
	//��ʼ�������������е��ֶ����
	void init();

	//���ļ�����
	//@param	input	������ļ�
	//@return	1��ʾ����ɹ���0��ʾ����ʧ��
	int read(FILE* input);

	//���ļ�д��
	//@param	output д�����ļ�
	//@return	1��ʱд���ɹ���0��ʾд��ʧ��
	int write(FILE* output) const;

	//������д���ļ���,����DEBUG
	//@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	//@param	index	Ҫ��ǰ����ʾ���±�ֵ��һ�����������������ʾ����-1��ʾ����ʾ
	void dump(FILE *fp = NULL, int index = -1) const;

	//������д���ļ���ͻ����ʾ�仯������
	//@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	//@param	pOriginal	Ҫ�Ƚϵ�ԭ������
	void dumpDiff(FILE *fp, const CCurrentTime *pOriginal) const;

	//������д���ļ���һ����,����DEBUG
	//@param	fp	Ҫд�����ļ�,NULL��ʾstdout
	void dumpInLine(FILE *fp = NULL) const;

	//������д��һ���ַ�����
	//@param	target	Ҫд���ַ��������÷�Ӧ����֤�����㹻�Ŀռ�
	void dumpString(char *target) const;

public:
	//��ǰ����
	CDateType CurrDate;
	//��ǰʱ��
	CTimeType CurrTime;
	//��ǰʱ�䣨���룩
	CMillisecType CurrMillisec;
	//ҵ��ʱ��
	CDateType ActionDay;
	//ԭ��ʱ��
	CTimeType OldTime;
	//ԭ��ʱ�䣨���룩
	CMillisecType OldMillisec;
};


#endif