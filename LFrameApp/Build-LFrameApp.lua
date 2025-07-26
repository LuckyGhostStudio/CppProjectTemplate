project "LFrameApp"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"
    targetdir "Binaries/%{cfg.buildcfg}"
    staticruntime "off"

    targetdir ("%{wks.location}/Binaries/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/Binaries/Intermediates/" .. outputdir .. "/%{prj.name}")

    files
    {
        "Source/**.h",
        "Source/**.cpp"
    }

    includedirs
    {
        "Source",

        -- Include Core
        "%{wks.location}/LFrame/Source",
        "%{wks.location}/LFrame/Vendor",
        "%{wks.location}/LFrame/Vendor/EasyX/include",
    }

    libdirs
    {
        "%{wks.location}/LFrame/Vendor/EasyX/lib/x64"
    }

    links
    {
        "LFrame",
        "EasyXw.lib",
    }

    filter "system:windows"
         systemversion "latest"
         defines { "WINDOWS" }

    filter "configurations:Debug"
         defines { "LF_DEBUG" }
         runtime "Debug"
         symbols "On"

    filter "configurations:Release"
         defines { "LF_RELEASE" }
         runtime "Release"
         optimize "On"
         symbols "On"

    filter "configurations:Dist"
         defines { "LF_DIST" }
         runtime "Release"
         optimize "On"
         symbols "Off"