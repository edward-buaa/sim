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

//���ļ�д��
int CCurrentTime::write(FILE* output) const
{
	if (fwrite(this, 1, sizeof(CCurrentTime), output) != sizeof(CCurrentTime))
		return 0;
	else
		return 1;
}

//������д���ļ���,����DEBUG
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
	fprintf(fp, "\t\tCurrDate = %s    [��ǰ����]\n", boost::lexical_cast<std::string>(CurrDate).c_str());
	fprintf(fp, "\t\tCurrTime = %s    [��ǰʱ��]\n", boost::lexical_cast<std::string>(CurrTime).c_str());
	fprintf(fp, "\t\tCurrMillisec = %s    [��ǰʱ�䣨���룩]\n", boost::lexical_cast<std::string>(CurrMillisec).c_str());
	fprintf(fp, "\t\tActionDay = %s    [ҵ������]\n", boost::lexical_cast<std::string>(ActionDay).c_str());
	fprintf(fp, "\t\tOldTime = %s    [ԭ��ʱ��]\n", boost::lexical_cast<std::string>(OldTime).c_str());
	fprintf(fp, "\t\tOldMillisec = %s    [ԭ��ʱ�䣨���룩]\n", boost::lexical_cast<std::string>(OldMillisec).c_str());
	fprintf(fp, "\t}\n");
}