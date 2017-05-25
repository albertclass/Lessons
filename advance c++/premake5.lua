solution "lessons"
    configurations { "Debug", "Release" }
    location "prj"
    characterset "MBCS"
    architecture "x64"

    symbols "On"
    flags { 
        "MultiProcessorCompile" 
    }

project "framework"
    kind "StaticLib"
    language "C++11"
    location "prj/framework"
    includedirs { "framework", "../curses" }
    targetdir "bin/%{cfg.buildcfg}"
    objdir "obj/%{prj.name}/%{cfg.buildcfg}"
    implibdir "lib/%{cfg.buildcfg}"

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


project "lesson-01"
    kind "WindowedApp"
    language "C++11"
    location "prj/%{prj.name}"
    includedirs { "framework", "../curses" }
    targetdir "bin/%{cfg.buildcfg}"
    objdir "obj/%{prj.name}/%{cfg.buildcfg}"
    libdirs { "lib/%{cfg.buildcfg}", "../curses/win32a/%{cfg.buildcfg}" }
    links { "framework", "pdcurses" }

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

project "lesson-02"
    kind "WindowedApp"
    language "C++11"
    location "prj/%{prj.name}"
    includedirs { "framework", "../curses" }
    targetdir "bin/%{cfg.buildcfg}"
    objdir "obj/%{prj.name}/%{cfg.buildcfg}"
    libdirs { "lib/%{cfg.buildcfg}", "../curses/win32a/%{cfg.buildcfg}" }
    links { "framework", "pdcurses" }

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
