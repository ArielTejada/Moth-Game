cmake_minimum_required(VERSION 3.16)

project(CS_395_Project) 

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

if(WIN32)
	add_definitions(-DMOTH_WINDOWS)
elseif(APPLE)
	add_definitions(-DMOTH_MACOS)
elseif(UNIX)
	add_definitions(-DMOTH_LINUX)
endif()

add_subdirectory(CS_395_Project)
add_subdirectory(Moth)
add_subdirectory(glfw)
add_subdirectory(glad)
add_subdirectory(stbi)