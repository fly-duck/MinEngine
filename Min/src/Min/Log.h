#pragma once


#include "Core.h"

#include <memory>

#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
#include "spdlog/sinks/stdout_color_sinks.h"



namespace Min
{

class MIN_API Log
{
public:

	static void Init();
	inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return   core_logger_; }
	inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return client_logger_; }
 
private:	
 static std::shared_ptr<spdlog::logger> core_logger_;
 static	std::shared_ptr<spdlog::logger> client_logger_;

};
}

// Core log macros
#define MIN_CORE_TRACE(...)    ::Min::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define MIN_CORE_INFO(...)     ::Min::Log::GetCoreLogger()->info(__VA_ARGS__)
#define MIN_CORE_WARN(...)     ::Min::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define MIN_CORE_ERROR(...)    ::Min::Log::GetCoreLogger()->error(__VA_ARGS__)
#define MIN_CORE_FATAL(...)    ::Min::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros			 
#define MIN_TRACE(...)	      ::Min::Log::GetClientLogger()->trace(__VA_ARGS__)
#define MIN_INFO(...)	      ::Min::Log::GetClientLogger()->info(__VA_ARGS__)
#define MIN_WARN(...)	      ::Min::Log::GetClientLogger()->warn(__VA_ARGS__)
#define MIN_ERROR(...)	      ::Min::Log::GetClientLogger()->error(__VA_ARGS__)
#define MIN_FATAL(...)	      ::Min::Log::GetClientLogger()->fatal(__VA_ARGS__)

