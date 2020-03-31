#pragma once
#include <cstddef>
#include "core/const.h"

namespace cys {
namespace logger {
	bool create();
	bool create(const LoggerType& loggerType);
	void trace(const char* contents);
	void debug(const char* contents);
	void info(const char* contents);
	void warning(const char* contents);
	void error(const char* contents);
	void fatal(const char* contents);
	void print(const char* contents, const char* severity);
	void print(const char* contents, std::size_t severity);
	bool destroy();
}
}