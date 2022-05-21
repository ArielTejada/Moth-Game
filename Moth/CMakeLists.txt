set(HEADER_FILES
	Moth.h 
	MothApp.h 
	MothUtil.h
	GameWindow.h
	WindowImplementation.h
	specificGLFW/GlfwWindow.h
	Sprite.h
	Shader.h
	Renderer.h
	SpriteImplementation.h
	ShaderImplementation.h
	RendererImplementation.h
	specificOpenGL/OpenGLSprite.h
	specificOpenGL/OpenGLShader.h
	specificOpenGL/OpenGLRenderer.h
	Events.h
	KeyCodes.h
	)

set(SOURCE_FILES 
	MothApp.cpp
	GameWindow.cpp
	specificGLFW/GlfwWindow.cpp
	Sprite.cpp
	Shader.cpp
	Renderer.cpp
	specificOpenGL/OpenGLSprite.cpp
	specificOpenGL/OpenGLShader.cpp
	specificOpenGL/OpenGLRenderer.cpp
	Events.cpp
	)

add_library(Moth SHARED ${HEADER_FILES} ${SOURCE_FILES})

add_definitions(-DMOTH_LIB)
add_definitions(-DMOTH_DEBUG)
add_definitions(-DMOTH_OPENGL)

include_directories(../glfw/include)
include_directories(../Moth)
include_directories(../stbi)
include_directories(../glad/include)

target_precompile_headers(Moth PRIVATE pch.h)

target_link_libraries(Moth glfw glad stbi)