project "App"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"
    targetdir "Binaries/%{cfg.buildcfg}"
    staticruntime "off"

    targetdir ("../Binaries/" .. OutputDir .. "/%{prj.name}")
    objdir ("../Binaries/Intermediates/" .. OutputDir .. "/%{prj.name}")

    files
    {
        "Source/**.h",
        "Source/**.cpp"
    }

    includedirs
    {
        "Source",

        -- Include Core
        "../Core/Source"
    }

    libdirs
    {
        "../Core/Vendor/EasyX/lib/x64"
    }

    links
    {
        "Core",
        "EasyXw.lib",
    }

    filter "system:windows"
         systemversion "latest"
         defines { "WINDOWS" }

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