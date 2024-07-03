#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace WEngined {

	class WENGINED_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		#pragma warning(suppress: 4251)
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		#pragma warning(suppress: 4251)
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define HZ_CORE_CRITICAL(...)		::WEngined::Log::GetCoreLogger()->critical(__VA_ARGS__)
#define HZ_CORE_ERROR(...)			::WEngined::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HZ_CORE_WARN(...)			::WEngined::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HZ_CORE_INFO(...)			::WEngined::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HZ_CORE_TRACE(...)			::WEngined::Log::GetCoreLogger()->trace(__VA_ARGS__)

// Client log macros
#define HZ_CRITICAL(...)			::WEngined::Log::GetClientLogger()->critical(__VA_ARGS__)
#define HZ_ERROR(...)				::WEngined::Log::GetClientLogger()->error(__VA_ARGS__)
#define HZ_WARN(...)				::WEngined::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HZ_INFO(...)				::WEngined::Log::GetClientLogger()->info(__VA_ARGS__)
#define HZ_TRACE(...)				::WEngined::Log::GetClientLogger()->trace(__VA_ARGS__)