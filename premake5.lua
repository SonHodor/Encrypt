workspace "Encrypt"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release"
    }

outputdir = "bin/%{prj.name}"

project "Encrypt"

    kind "ConsoleApp"
    language "C++"

    targetdir(outputdir)

    files
    {
        "**.h",
        "**.cpp"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

    filter "configurations:Debug"
        defines "VK_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "VK_RELEASE"
        optimize "On"

