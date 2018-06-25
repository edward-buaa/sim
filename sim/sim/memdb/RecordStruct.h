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

	//将内容写入文件，突出显示变化的内容
	//@param	fp	要写出的文件,NULL表示stdout
	//@param	pOriginal	要比较的原来内容
	void dumpDiff(FILE *fp, const CCurrentTime *pOriginal) const;

	//将内容写到文件的一行中,用于DEBUG
	//@param	fp	要写出的文件,NULL表示stdout
	void dumpInLine(FILE *fp = NULL) const;

	//将内容写到一个字符串中
	//@param	target	要写的字符串，叫用方应当保证其有足够的空间
	void dumpString(char *target) const;

public:
	//当前日期
	CDateType CurrDate;
	//当前时间
	CTimeType CurrTime;
	//当前时间（毫秒）
	CMillisecType CurrMillisec;
	//业务时期
	CDateType ActionDay;
	//原来时间
	CTimeType OldTime;
	//原来时间（毫秒）
	CMillisecType OldMillisec;
};


#endif