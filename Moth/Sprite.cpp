#include "pch.h"
#include "Sprite.h"
#include "specificOpenGL/OpenGLSprite.h"

namespace Moth
{
	Sprite::Sprite(const std::string& filename)
	{
#ifdef MOTH_OPENGL
		mImplementation = new OpenGLSprite{filename};
#else
	#Only_OpenGL_is_supported_for_now
#endif
	}

	int Sprite::GetWidth() const
	{
		return mImplementation->GetWidth();
	}

	int Sprite::GetHeight() const
	{
		return mImplementation->GetHeight();
	}
	void Sprite::Bind()
	{
		mImplementation->Bind();
	}
}