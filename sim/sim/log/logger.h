#ifndef __POLO_LOGGER_H__
#define __POLO_LOGGER_H__

/*
日志类，基于spdlog
*/

#include <spdlog.h>

namespace polo {

class logger
{
public:
	logger();
	~logger();
	logger(logger&) = delete;
	logger(logger&&) = delete;
	logger& operator=(logger&) = delete;
	logger& operator=(logger&&) = delete;
};

}	//end of namespace


#endif
