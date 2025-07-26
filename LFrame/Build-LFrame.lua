project "LFrame"
    kind "StaticLib"
    language "C++"
    cppdialect "C++20"
    targetdir "Binaries/%{cfg.buildcfg}"
    staticruntime "off"

    targetdir ("%{wks.location}/Binaries/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/Binaries/Intermediates/" .. outputdir .. "/%{prj.name}")

    -- pchheader "lpch.h"  -- Ô¤±àÒëÍ·ÎÄ¼þ
    -- pchsource "Source/lpch.cpp"

    files
    {
        "Source/**.h",
        "Source/**.cpp"
    }

    includedirs
    {
        "Source",
        "Vendor",
        "Vendor/EasyX/include"
    }

    libdirs
    {
        "Vendor/EasyX/lib/x64"
    }

    links
    {
        "EasyXw.lib",
    }

    filter "system:windows"
        systemversion "latest"
        defines { }

    filter "configurations:Debug"
        defines { "DEBUG" }
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines { "RELEASE" }
        runtime "Release"
        optimize "On"
        symbols "On"

    filter "configurations:Dist"
        defines { "DIST" }
        runtime "Release"
        optimize "On"
        symbols "Off"