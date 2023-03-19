project "DialogueEditor"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"Source/**.h",
		"Source/**.cpp",
		"ThirdParty/include/ImGUI/**.cpp",
		"ThirdParty/include/ImGUI/**.h",
		"ThirdParty/include/ImNodes/**.cpp",
		"ThirdParty/include/ImNodes/**.h"
	}

	includedirs 
	{
		"ThirdParty/include",
		"ThirdParty/include/GLFW",
		"ThirdParty/include/ImGUI",
		"ThirdParty/include/ImNodes",
		"Source"
	}
	
	libdirs
	{
		"ThirdParty/lib/GLFW/"
	}
	
	links
	{
		"glfw3.lib",
		"opengl32.lib"	
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
	filter { "system:windows"}
		buildoptions "/MD"