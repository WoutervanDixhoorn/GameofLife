project "Douter"
   kind "StaticLib"
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
      "src",
      "%{IncludeDir.GLFW}",
      "%{IncludeDir.Glad}"
   }

   links {
      "GLFW",
      "Glad",
      "opengl32.lib"
   }

   filter "system:windows"
      systemversion "latest"

      defines
      {
      }

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