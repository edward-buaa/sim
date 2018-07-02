#ifndef __POLO_LOGGER_H__
#define __POLO_LOGGER_H__

/*
��־�࣬����spdlog
*/

#include <spdlog.h>
#include <string>


class Logger
{
public:
	Logger();
	~Logger();
	Logger(Logger&) = delete;
	Logger(Logger&&) = delete;
	Logger& operator=(Logger&) = delete;
	Logger& operator=(Logger&&) = delete;

	//��װ��־
	void setupLogSystem(const std::string filename, const std::string modulename,
		int loglevel, const bool haveStdout = false);
};



#endif
