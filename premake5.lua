workspace "Min"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
-- IncludeDir = {}
-- IncludeDir["GLFW"] = "Min/vendor/GLFW/include"
-- IncludeDir["Glad"] = "Min/vendor/Glad/include"
-- IncludeDir["ImGui"] = "Min/vendor/imgui"
-- IncludeDir["glm"] = "Min/vendor/glm"

-- include "Min/vendor/GLFW"
-- include "Min/vendor/Glad"
-- include "Min/vendor/imgui"

project "Min"
	location "Min"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	-- pchheader "hzpch.h"
	-- pchsource "Min/src/hzpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl",
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		-- "%{IncludeDir.GLFW}",
		-- "%{IncludeDir.Glad}",
		-- "%{IncludeDir.ImGui}",
		-- "%{IncludeDir.glm}"
	}

	links 
	{ 
		-- "GLFW",
		-- "Glad",
		-- "ImGui",
		-- "opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"MIN_PLATFORM_WINDOWS",
			"MIN_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

	filter "configurations:Debug"
		defines "MIN_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "MIN_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "MIN_DIST"
		runtime "Release"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Min/vendor/spdlog/include",
		"Min/src",
		"Min/vendor",
		-- "%{IncludeDir.glm}"
	}

	links
	{
		"Min"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"MIN_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "MIN_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "MIN_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "MIN_DIST"
		runtime "Release"
		optimize "On"
