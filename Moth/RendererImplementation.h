#pragma once

#include "Sprite.h"
#include "Shader.h"

namespace Moth
{
	class RendererImplementation
	{
	public:
		virtual void Draw(Moth::Sprite& picture, int xPos, int yPos, int zPos, Moth::Shader shader) = 0;
		virtual void ClearScreen() = 0;
	};
}