#pragma once

#include "SpriteImplementation.h"
#include "MothUtil.h"

namespace Moth {

	class MOTH_API Sprite
	{
	public:
		Sprite(const std::string& filename);
		int GetWidth() const;
		int GetHeight() const;

		void Bind();

	private:
		SpriteImplementation* mImplementation;
	};
}
