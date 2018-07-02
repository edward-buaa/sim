
#include "logger.h"
#include <memory>

Logger::Logger()
{

}

Logger::~Logger()
{

}

void Logger::setupLogSystem(const std::string filename, const std::string modulename, 
	int loglevel, const bool haveStdout)
{
	
	spdlog::sink_ptr file_skin = 
			std::make_shared<spdlog::sinks::simple_file_sink_mt>(filename);
	auto aggr_logger = std::make_shared<spdlog::logger>("logger", file_skin);
	spdlog::register_logger(aggr_logger);
	
	if (haveStdout)
	{
		auto console = spdlog::stderr_color_mt("console");
	}

	if (!modulename.empty())
	{
		std::string pt = "[%Y-%m-%d %H:%M:%S.%f] [%L]";
		pt += " [" + modulename + "]";
		pt += " %v";
		spdlog::set_pattern(pt);
	}
	else
	{
		spdlog::set_pattern("[%Y-%m-%d %H:%M:%S.%f] [%L] %v");
	}

	spdlog::set_async_mode(8192);

	switch (loglevel)
	{
	case 0:
		spdlog::set_level(spdlog::level::trace);
		break;
	case 1:
		spdlog::set_level(spdlog::level::debug);
		break;
	case 2:
		spdlog::set_level(spdlog::level::info);
		break;
	case 3:
		spdlog::set_level(spdlog::level::warn);
		break;
	case 4:
		spdlog::set_level(spdlog::level::err);
		break;
	case 5:
		spdlog::set_level(spdlog::level::critical);
		break;
	case 6:
		spdlog::set_level(spdlog::level::off);
		break;
	}
}