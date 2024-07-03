workspace "WEngined"
architecture "x64"
    
    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }
    
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "WEngined/vendor/GLFW/include"
IncludeDir["Glad"] = "WEngined/vendor/Glad/include"
IncludeDir["ImGui"] = "WEngined/vendor/imgui"

include "WEngined/vendor/GLFW"
include "WEngined/vendor/Glad"
include "WEngined/vendor/imgui"
    
project "WEngined"
    location "WEngined"
    kind "SharedLib"
    language "C++"
    
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "wedpch.h"
    pchsource "WEngined/src/wedpch.cpp"
    
    files
    {
       "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }
    
    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}"
    }

    links {
        "GLFW",
        "Glad",
        "ImGui",
        "opengl32.lib"
    }
    
    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "10.0.22621.0"
    
        defines
        {
            "WED_PLATFORM_WINDOWS",
            "WED_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }
    
        postbuildcommands
        {
            "copy /B /Y ..\\bin\\" .. outputdir .. "\\WEngined\\WEngined.dll ..\\bin\\" .. outputdir .. "\\Sandbox\\ > nul"
        }
    
    filter "configurations:Debug"
        defines "WED_DEBUG"
        buildoptions "/MDd"
        symbols "On"
    
    filter "configurations:Release"
        defines "WED_RELEASE"
        buildoptions "/MD"
        optimize "On"
    
    filter "configurations:Dist"
        defines "WED_DIST"
        buildoptions "/MD"
        optimize "On"
    
project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
    
    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }
    
    includedirs
    {
        "WEngined/vendor/spdlog/include",
        "WEngined/src"
    }
    
    links
    {
        "WEngined"
    }
    
    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "10.0.22621.0"
    
        defines
        {
            "WED_PLATFORM_WINDOWS"
        }
    
    filter "configurations:Debug"
        defines "WED_DEBUG"
        buildoptions "/MDd"
        symbols "On"
    
    filter "configurations:Release"
        defines "WED_RELEASE"
        buildoptions "/MD"
        optimize "On"
    
    filter "configurations:Dist"
        defines "WED_DIST"
        buildoptions "/MD"
        optimize "On"