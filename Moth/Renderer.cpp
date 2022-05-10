#include "pch.h"
#include "Renderer.h"
#include "GameWindow.h"
#include "specificOpenGL/OpenGLRenderer.h"

namespace Moth
{
	void Renderer::Init()
	{
		if(mInstance == nullptr)
			mInstance = new Renderer;
	}

	void Renderer::Draw(Moth::Sprite& picture, int xPos, int yPos, int zPos)
	{
		assert(mInstance != nullptr);

		mInstance->mImplementation->Draw(picture, xPos, yPos, zPos, mInstance->mShader);
	}

	void Renderer::ClearScreen()
	{
		mInstance->mImplementation->ClearScreen();
	}

	Renderer::Renderer(): 
		mShader("../Moth/Assets/Shaders/defaultVertex.glsl", "../Moth/Assets/Shaders/defaultFragment.glsl")
	{
#ifdef MOTH_OPENGL
		mImplementation = new OpenGLRenderer;
#else
		#Only_OpenGL_is_supported_for_now
#endif
	}
}
