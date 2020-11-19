project "GameofLife"
   kind "ConsoleApp"
   language "C++"
   cppdialect "C++17"
   staticruntime "on"

   targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
   objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

   files { 
      "src/**.h",
      "src/**.cpp"
   }

   includedirs {
      "%{wks.location}/Douter/src",
      "%{wks.location}/Douter/vendor"
   }

   links {
      "Douter"
   }

   filter "system:windows"
      systemversion "latest"

   filter "configurations:Debug"
      defines "DT_DEBUG"
      runtime "Debug"
      symbols "on"

   filter "configurations:Release"
      defines "DT_RELEASE"
      runtime "Release"
      optimize "on"

   filter "configurations:Dist"
      defines "DT_DIST"
      runtime "Release"
      optimize "on"