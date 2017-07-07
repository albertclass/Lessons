solution "lessons"
    configurations { "Debug", "Release" }
    location "prj"
    characterset "MBCS"
    architecture "x64"

    symbols "On"
    language "C++"
    cppdialect "C++14"

    targetdir "bin/%{cfg.buildcfg}"
    objdir "obj/%{prj.name}/%{cfg.buildcfg}"
    libdirs { "lib/%{cfg.buildcfg}", "../curses/win32a/%{cfg.buildcfg}" }

    flags { 
        "MultiProcessorCompile" 
    }

project "framework"
    kind "StaticLib"
    includedirs { "framework", "../curses" }
    implibdir "lib/%{cfg.buildcfg}"
    systemversion "10.0.15063.0"

    files {
        "%{prj.name}/**.h",
        "%{prj.name}/**.hpp",
        "%{prj.name}/**.cpp",
        "%{prj.name}/**.inl",
    }

    vpaths {
        ["Header Files/*"] = { "%{prj.name}/**.h", "%{prj.name}/**.hpp" },
        ["Source Files/*"] = { "%{prj.name}/**.cpp", "%{prj.name}/**.inl" }
    }

    filter "configurations:Debug"
        defines { "_DEBUG", "_LIB_EXPORTS" }

    filter "configurations:Release"
        defines { "NDEBUG", "_LIB_EXPORTS" }
        optimize "On"

    filter "system:windows"
        defines { "WIN64" }

    filter "system:linux"
        links { "stdc++" }
        defines { "LINUX64" }

for idx=1, 15, 1 do
    local prj = "lesson-"..string.format( "%02d", idx )
    if not os.isdir(prj) then
        os.mkdir(prj)
        file = io.open( prj .. "\\sample.cpp", "w" )
        file:write( [[
#include "header.h"
           
void do_lesson( int rows, int cols )
{
}
        ]] )
        file:close()
    end

    project( prj )
        print( prj )

        kind "ConsoleApp"
        location "prj/%{prj.name}"
        includedirs { "framework",  prj }
        links { "framework" }
        systemversion "10.0.15063.0"

        files {
            "%{prj.name}/**.h",
            "%{prj.name}/**.hpp",
            "%{prj.name}/**.cpp",
            "%{prj.name}/**.inl",
        }

        vpaths {
            ["Header Files/*"] = { "%{prj.name}/**.h", "%{prj.name}/**.hpp" },
            ["Source Files/*"] = { "%{prj.name}/**.cpp", "%{prj.name}/**.inl" }
        }

        filter "configurations:Debug"
            defines { "_DEBUG", "_LIB_EXPORTS" }

        filter "configurations:Release"
            defines { "NDEBUG", "_LIB_EXPORTS" }
            optimize "On"

        filter "system:windows"
            defines { "WIN64" }

        filter "system:linux"
            links { "stdc++" }
            defines { "LINUX64" }
end