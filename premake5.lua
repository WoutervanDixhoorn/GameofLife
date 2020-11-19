include "./vendor/premake/premake_customizations/solution_items.lua"

workspace "GameofLife"
   architecture "x64"
   startproject "GameofLife"

   configurations { "Debug", "Release", "Dist" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "%{wks.location}/Douter/vendor/glfw/include"
IncludeDir["Glad"] = "%{wks.location}/Douter/vendor/glad/include"

group "Dependencies"
	include "Douter/vendor/glfw"
	include "Douter/vendor/glad"
group ""

include "Douter"
include "GameofLife"
