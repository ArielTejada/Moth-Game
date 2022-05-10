#pragma once

#include "RendererImplementation.h"

namespace Moth
{
	class OpenGLRenderer: public RendererImplementation
	{
	public:
		virtual void Draw(Moth::Sprite& picture, int xPos, int yPos, int zPos, Moth::Shader shader) override;
		virtual void ClearScreen() override;
	};
}