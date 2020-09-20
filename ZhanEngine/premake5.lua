workspace "ZhanEngine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"]="ZhanEngine/vendor/GLFW/include"
IncludeDir["Glad"]="ZhanEngine/vendor/Glad/include"
IncludeDir["ImGui"]="ZhanEngine/vendor/imgui"
IncludeDir["glm"]="ZhanEngine/vendor/glm"
-- include premake file from GLFW -- 
include "ZhanEngine/vendor/Glad"
include "ZhanEngine/vendor/GLFW"
include "ZhanEngine/vendor/imgui"
project "ZhanEngine"
	location "ZhanEngine"
	kind "StaticLib"
	language "C++" 
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}" )
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

		
	pchheader "zhpch.h"
	pchsource "ZhanEngine/src/zhpch.cpp"


	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}
	 
	includedirs {
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"

	}

	links {
		"GLFW",
		"Glad",
		"opengl32.lib",
		"ImGui"
	}

	filter "system:windows" 
		systemversion "latest"
		defines {
			"ZH_PLATFORM_WINDOWS",
			"ZH_BUILD_DLL",
			"ZH_ENABLE_ASSERT",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "ZH_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "ZH_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "ZH_DIST"
		runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"
	targetdir ("bin/" .. outputdir .. "/%{prj.name}" )
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	 
	includedirs {
		"ZhanEngine/vendor/spdlog/include",
		"ZhanEngine/src",
		"%{IncludeDir.glm}"
	}

	links {
		"ZhanEngine"
	}
	filter "system:windows" 
	
		systemversion "latest"
		defines {
			"ZH_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "ZH_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "ZH_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "ZH_DIST"
		runtime "Release"
		optimize "on"
		
