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

#ifdef ZH_ENABLE_ASSERT
	#define ZH_ASSERT(x, ...) { if(!(x)) { ZH_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } } 
	#define ZH_CORE_ASSERT(x, ...) {if(!(x)) { ZH_CORE_ERROR ("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }}
#else
	#define ZH_ASSERT(x, ...)
	#define ZH_CORE_ASSERT(x, ...)

#endif

#define BIT(x) (1 << x)
#define ZH_BIND_EVENT_FN(fn) std::bind(&fn,this,std::placeholders::_1)

#if !defined(IMGUI_IMPL_OPENGL_LOADER_GL3W)     \
 && !defined(IMGUI_IMPL_OPENGL_LOADER_GLEW)     \
 && !defined(IMGUI_IMPL_OPENGL_LOADER_GLAD)     \
 && !defined(IMGUI_IMPL_OPENGL_LOADER_CUSTOM)
#define IMGUI_IMPL_OPENGL_LOADER_GLAD
#endif
