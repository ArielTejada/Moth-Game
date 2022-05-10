#pragma once

#include "Sprite.h"
#include "Shader.h"
#include "RendererImplementation.h"
#include "MothUtil.h"

namespace Moth
{
	class MOTH_API Renderer
	{
	public:
		static void Init();
		static void Draw(Moth::Sprite& picture, int xPos, int yPos, int zPos);
		static void ClearScreen();

	private:
		inline static Renderer* mInstance{ nullptr };

		RendererImplementation* mImplementation{ nullptr };

		Renderer();

		Moth::Shader mShader;
	};
}


