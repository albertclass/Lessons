solution "profile"
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

function make_project( prj )
    project( prj )
        print( "build project " .. prj )

        kind "ConsoleApp"
        location "prj"
        includedirs { prj }
        systemversion "10.0.15063.0"

        files {
            prj .. "/**.h",
            prj .. "/**.hpp",
            prj .. "/**.cpp",
            prj .. "/**.inl",
        }

        vpaths {
            ["Header Files/*"] = { prj .. "/**.h", prj .. "/**.hpp" },
            ["Source Files/*"] = { prj .. "/**.cpp", prj .. "/**.inl" }
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

make_project( 'slow' )
make_project( 'fix1' )