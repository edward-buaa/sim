#ifndef __RECORD_STRUCT_H__
#define __RECORD_STRUCT_H__


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