#include "Log.h"

namespace Min
{
	 std::shared_ptr<spdlog::logger> Log::core_logger_;
	 std::shared_ptr<spdlog::logger> Log::client_logger_;

	 void Log::Init()
	 {
		// time pattern
		 spdlog::set_pattern("%^[%T] %n: %v%$");
		 core_logger_ = spdlog::stdout_color_mt("Min");
		 core_logger_->set_level(spdlog::level::trace);

		  client_logger_= spdlog::stdout_color_mt("APP");
		 client_logger_->set_level(spdlog::level::trace);
	 }
	 
}
