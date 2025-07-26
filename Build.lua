-- premake5.lua
workspace "LFrame"
   architecture "x64"
   configurations { "Debug", "Release", "Dist" }
   startproject "LFrameApp"

   flags { "MultiProcessorCompile" }

outputdir = "%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}"

group "Core"
    include "LFrame/Build-LFrame.lua"
group ""

include "LFrameApp/Build-LFrameApp.lua"