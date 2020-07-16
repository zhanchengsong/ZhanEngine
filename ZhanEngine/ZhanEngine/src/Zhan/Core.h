#pragma once

#ifdef ZH_PLATFORM_WINDOWS 
	#ifdef ZH_BUILD_DLL
		#define ZHAN_API __declspec(dllexport)
	#else
		#define ZHAN_API __declspec(dllimport)
	#endif
#else 
	#error ZHAN only support windows for now 
#endif

#define BIT(x) (1 << x)