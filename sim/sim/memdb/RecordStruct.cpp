#include "RecordStruct.h"


//��ʼ�������������е��ֶ����
void CCurrentTime::init()
{
	memset(this, 0, sizeof(CCurrentTime));
}

//���ļ�����
int CCurrentTime::read(FILE* input)
{
	if (fread(this, 1, sizeof(CCurrentTime), input) != sizeof(CCurrentTime))
		return 0;
	else
		return 1;
}