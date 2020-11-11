project "GameofLife"
   kind "ConsoleApp"
   language "C++"

   targetdir ("bin/" .. outputdir .. "/%{prj.name}")
   objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

   files { "**.h", "**.cpp" }

   includedirs {
      "src",
      "%{IncludeDir.GLFW}"
   }

   links {
      "GLFW",
      "opengl32.lib"
   }

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"