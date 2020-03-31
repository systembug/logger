#include "logger.h"
#include "core/Core.h"
#include <memory>

namespace cys {
namespace logger {
	static std::unique_ptr<Core> g_core;
	static bool g_setCreate = false;
	bool create() 
	{
		return create(LoggerType::TRIVIAL);
	}

	bool create(const LoggerType& loggerType) 
	{
		if (!g_setCreate) return false;
		g_core = std::make_unique<Core>(loggerType);
		g_setCreate = true;
		return true;
	}

	void trace(const char* contents)
	{
		if (!g_setCreate) return;
		print(contents, "trace");
		
	}

	void debug(const char* contents)
	{
		if (!g_setCreate) return;
		print(contents, "debug");
	}

	void info(const char* contents)
	{
		if (!g_setCreate) return;
		print(contents, "info");
	}

	void warning(const char* contents) 
	{
		if (!g_setCreate) return;
		print(contents, "warning");
	}

	void error(const char* contents)
	{
		if (!g_setCreate) return;
		print(contents, "error");
	}

	void fatal(const char* contents)
	{
		if (!g_setCreate) return;
		print(contents, "fatal");
	}

	void print(const char* contents, const char* severity)
	{
		if (!g_setCreate) return;
		g_core->print(contents, severity);
	}

	void print(const char* contents, std::size_t severity)
	{
		if (!g_setCreate) return;
		g_core->print(contents, severity);
	}

	bool destroy() 
	{
		g_core.reset(nullptr);
		g_setCreate = false;
		return true;
	}
}
}