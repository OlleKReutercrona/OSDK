local WORKSPACE_NAME = "OSDK"
local MATH_PROJECT = "Math"
local UTILITY_PROJECT = "Utility"

local USE_ABSOLUTE_PATHS = false
local basePath = USE_ABSOLUTE_PATHS and os.realpath("../") or "../"

local cppVersion = "C++20"

local PROJECT_KIND = "StaticLib"

local DEBUG_BUILD_NAME = "Debug"
local RELEASE_BUILD_NAME = "Release"

local CONFIG_FILTERS = {
    DEBUG = "configurations:"..tostring(DEBUG_BUILD_NAME),
    RELEASE = "configurations:"..tostring(RELEASE_BUILD_NAME),
}

local LINKER_OPTIONS =  {
    "/ignore:4099", -- linking object as if no debug info
}

local directories = {
    root            = basePath,
    temp            = basePath .. "Temp/",

    intermediate    = basePath .. "Intermediate/",
    output          = basePath .. "Output/",

    source          = basePath .. "Source/",
    sourceMath      = basePath .. "Source/Math/",
    sourceUtility   = basePath .. "Source/Utility/",

    premake         = basePath .. "Premake",
 }

 workspace(WORKSPACE_NAME)
    location(directories.root)
    architecture("x64")

    configurations {
        DEBUG_BUILD_NAME,
        RELEASE_BUILD_NAME
    }

    debugdir(directories.output.."%{cfg.buildcfg}/")
    targetdir(directories.output.."%{cfg.buildcfg}/")
    targetname(WORKSPACE_NAME.."_%{cfg.buildcfg}")
    objdir(directories.intermediate)
    
project(MATH_PROJECT)
    location(directories.temp)
    language("C++")
    cppdialect(cppVersion)
    kind(PROJECT_KIND)

    files {
        directories.sourceMath.."**.h",
        directories.sourceMath.."**.hpp",
        directories.sourceMath.."**.cpp",
    }

    includedirs {
        directories.sourceMath
    }

    filter (CONFIG_FILTERS.DEBUG)
        runtime "Debug"
        symbols "on"
    filter (CONFIG_FILTERS.RELEASE)
        runtime "Release"
        optimize "on"

    filter "system:windows"
        staticruntime "off"
        symbols "On"
        systemversion "latest"
        warnings "Off"
    
    flags {
        "MultiProcessorCompile"
    }

project(UTILITY_PROJECT)
    location(directories.temp)
    language("C++")
    cppdialect(cppVersion)
    kind(PROJECT_KIND)

    files {
        directories.sourceUtility.."**.h",
        directories.sourceUtility.."**.hpp",
        directories.sourceUtility.."**.cpp",
    }

    includedirs {
        directories.sourceUtility
    }

    filter (CONFIG_FILTERS.DEBUG)
        runtime "Debug"
        symbols "on"
    filter (CONFIG_FILTERS.RELEASE)
        runtime "Release"
        optimize "on"

    filter "system:windows"
        staticruntime "off"
        symbols "On"
        systemversion "latest"
        warnings "Off"
    
    flags {
        "MultiProcessorCompile"
    }

    local function MakeFolderStructure()
        for _, dir in pairs(directories) do
            if not os.isdir(dir) then
                os.mkdir(dir)
            end
        end
    end
    
    MakeFolderStructure()