#include "RecordStruct.h"


//初始化操作，将所有的字段清空
void CCurrentTime::init()
{
	memset(this, 0, sizeof(CCurrentTime));
}

//从文件读入
int CCurrentTime::read(FILE* input)
{
	if (fread(this, 1, sizeof(CCurrentTime), input) != sizeof(CCurrentTime))
		return 0;
	else
		return 1;
}