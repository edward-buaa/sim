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

//向文件写出
int CCurrentTime::write(FILE* output) const
{
	if (fwrite(this, 1, sizeof(CCurrentTime), output) != sizeof(CCurrentTime))
		return 0;
	else
		return 1;
}

//将内容写到文件中,用于DEBUG
void CCurrentTime::dump(FILE *fp, int index) const
{
	char index_buf[64];
	if (fp == NULL)
	{
		fp = stdout;
	}
	if (index >= 0)
		sprintf(index_buf, "[%d]", index);
	else
		index_buf[0] = '\0';
	fprintf(fp, "\tCCurrentTime%s = {\n", index_buf);
	fprintf(fp, "\t\tCurrDate = %s    [当前日期]\n", boost::lexical_cast<std::string>(CurrDate).c_str());
	fprintf(fp, "\t\tCurrTime = %s    [当前时间]\n", boost::lexical_cast<std::string>(CurrTime).c_str());
	fprintf(fp, "\t\tCurrMillisec = %s    [当前时间（毫秒）]\n", boost::lexical_cast<std::string>(CurrMillisec).c_str());
	fprintf(fp, "\t\tActionDay = %s    [业务日期]\n", boost::lexical_cast<std::string>(ActionDay).c_str());
	fprintf(fp, "\t\tOldTime = %s    [原来时间]\n", boost::lexical_cast<std::string>(OldTime).c_str());
	fprintf(fp, "\t\tOldMillisec = %s    [原来时间（毫秒）]\n", boost::lexical_cast<std::string>(OldMillisec).c_str());
	fprintf(fp, "\t}\n");
}