
#ifndef __M_PATH_H__
#define __M_PATH_H__

/*
�����ƽ̨��·������
*/

#include <cstdio>
#include <string>
#include <boost/filesystem.hpp>

#ifdef _WIN32
#define PATH_SPLIT '\\'
#elif defined(LINUX)
#define PATH_SPLIT '/'
#endif

#define ALL_SPLITS "\\/$"
#define MAX_PATH_LEN 200

//ת��·��
//@param	target	Ŀ��
//@param	source	Դ
void convertPath(char *target, const char *source)
{
	const char *s;
	char *t;
	for (s = source, t = target; ((s - source)<MAX_PATH_LEN) && (*s != '\0'); s++, t++)
	{
		if (strchr(ALL_SPLITS, *s) != NULL)
		{
			*t = PATH_SPLIT;
		}
		else
		{
			*t = *s;
		}
	}
	*t = '\0';
}

std::string convertPath(const std::string &source)
{
	using boost::filesystem::path;
#ifdef _WIN32
#pragma warning(disable:4996)
	return path(source).make_preferred().string();
#else
	return path(source).make_preferred().string();
#endif
}


//�滻��׼��fopen����
FILE *mfopen(const char *filename, const char *mode)
{
	return fopen(filename, mode);
}

//�滻��׼��fopen����
FILE *mfopen(const std::string &filename, const char *mode)
{
	return mfopen(convertPath(filename).c_str(), mode);
}

#endif