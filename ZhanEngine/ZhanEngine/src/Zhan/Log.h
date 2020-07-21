#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
namespace Zhan {
	class ZHAN_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr < spdlog::logger > s_CoreLogger;
		static std::shared_ptr < spdlog::logger > s_ClientLogger;
	};
}
 
#define ZH_CORE_ERROR(...)	 ::Zhan::Log::GetCoreLogger()->error(__VA_ARGS__) 
#define ZH_CORE_WARN(...)	 ::Zhan::Log::GetCoreLogger()->warn(__VA_ARGS__) 
#define ZH_CORE_INFO(...)	 ::Zhan::Log::GetCoreLogger()->info(__VA_ARGS__) 
#define ZH_CORE_TRACE(...)	 ::Zhan::Log::GetCoreLogger()->trace(__VA_ARGS__) 

#define ZH_CLIENT_ERROR(...)	 ::Zhan::Log::GetClientLogger()->error(__VA_ARGS__) 
#define ZH_CLIENT_WARN(...)		 ::Zhan::Log::GetClientLogger()->warn(__VA_ARGS__) 
#define ZH_CLIENT_INFO(...)	     ::Zhan::Log::GetClientLogger()->info(__VA_ARGS__) 
#define ZH_CLIENT_TRACE(...)	 ::Zhan::Log::GetClientLogger()->trace(__VA_ARGS__)

#define ZH_ERROR(...)	 ::Zhan::Log::GetClientLogger()->error(__VA_ARGS__) 
#define ZH_WARN(...)	 ::Zhan::Log::GetClientLogger()->warn(__VA_ARGS__) 
#define ZH_INFO(...)	 ::Zhan::Log::GetClientLogger()->info(__VA_ARGS__) 
#define ZH_TRACE(...)	 ::Zhan::Log::GetClientLogger()->trace(__VA_ARGS__)