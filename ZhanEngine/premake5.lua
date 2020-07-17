workspace "ZhanEngine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
project "ZhanEngine"
	location "ZhanEngine"
	kind "SharedLib"
	language "C++" 
	targetdir ("bin/" .. outputdir .. "/%{prj.name}" )
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

		
	pchheader "zhpch.h"
	pchsource "ZhanEngine/src/zhpch.cpp"


	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	 
	includedirs {
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows" 
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		defines {
			"ZH_PLATFORM_WINDOWS",
			"ZH_BUILD_DLL"
		}

		postbuildcommands {
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "ZH_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "ZH_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "ZH_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	targetdir ("bin/" .. outputdir .. "/%{prj.name}" )
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	 
	includedirs {
		"ZhanEngine/vendor/spdlog/include",
		"ZhanEngine/src"
	}

	links {
		"ZhanEngine"
	}
	filter "system:windows" 
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		defines {
			"ZH_PLATFORM_WINDOWS"
		}

		
