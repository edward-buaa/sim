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
	int read(FILE* input);
};


#endif