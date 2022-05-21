#pragma once

#include "MothUtil.h"
#include "pch.h"
#include "Events.h"

#define MOTH_FRAMERATE 60

namespace Moth
{
	class MOTH_API MothApp
	{
	public: 
		MothApp();
		void Run();
		virtual void OnUpdate();
		void SetKeyPressedCallback(std::function<void(const KeyPressedEvent &)> keyPressedCallback);
		void SetKeyReleasedCallback(std::function<void(const KeyReleasedEvent &)> keyReleaseCallback);

	private:
		std::chrono::milliseconds mFrameDuration{ 1000 / MOTH_FRAMERATE };
		std::chrono::steady_clock::time_point mNextFrameTime;
	};
}
