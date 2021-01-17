include "./vendor/premake/premake_customizations/solution_items.lua"

workspace "GameofLife"
   architecture "x64"
   startproject "GameofLife"

   configurations { "Debug", "Release", "Dist" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "%{wks.location}/Douter/vendor/glfw/include"
IncludeDir["Glad"] = "%{wks.location}/Douter/vendor/glad/include"
IncludeDir["ImGui"] = "%{wks.location}/Douter/vendor/ImGui"
IncludeDir["stb_image"] = "%{wks.location}/Douter/vendor/stb_image"

group "Dependencies"
	include "Douter/vendor/glfw"
	include "Douter/vendor/glad"
	include "Douter/vendor/ImGui"
group ""

include "Douter"
include "GameofLife"
