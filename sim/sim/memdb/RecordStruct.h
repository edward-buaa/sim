#ifndef __RECORD_STRUCT_H__
#define __RECORD_STRUCT_H__


/////////////////////////////////////////////////////////////////////////
///CWriteableCurrentTime是一个存储[当前时间]的对象，可以写出。
///@author	RE
///@version	1.0
/////////////////////////////////////////////////////////////////////////
class CCurrentTime
{
public:
	//初始化操作，将所有的字段清空
	void init();

	//从文件读入
	int read(FILE* input);
};


#endif