#ifndef __RECORD_STRUCT_H__
#define __RECORD_STRUCT_H__

#include "../network/field_describe.h"
#include "../customDataType/customDataType.h"

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
	//@param	input	读入的文件
	//@return	1表示读入成功，0表示读入失败
	int read(FILE* input);

	//向文件写出
	//@param	output 写出的文件
	//@return	1表时写出成功，0表示写出失败
	int write(FILE* output) const;

	//将内容写到文件中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	index	要在前面显示的下标值，一般用于数组分量的显示，用-1表示不显示
	void dump(FILE *fp = NULL, int index = -1) const;
};


#endif