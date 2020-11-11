workspace "GameofLife"
   configurations { "Debug", "Release" }
   startproject "GameofLife"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "GameofLife/vendor/glfw/include"

group "Dpendencies" 
   include "GameofLife/vendor/glfw"
group ""

include "GameofLife"
