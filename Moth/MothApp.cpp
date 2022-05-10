#include "pch.h"

#include "MothApp.h"
#include "GameWindow.h"
#include "Sprite.h"
#include "Shader.h"
#include "Renderer.h"
#include "Events.h"
#include "KeyCodes.h"

namespace Moth 
{
	void MothApp::Run()
	{
		MOTH_LOG("MothApp Running...\n");

		Moth::GameWindow::Init();

		Moth::GameWindow::GetWindow()->CreateWindow(800, 600, "game window");

		Renderer::Init();

		Moth::Sprite star{"../Moth/Assets/Images/Moth2.png"};

		mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

		int x{ 50 }, y{ 50 };
		auto keyCall = [&x](const KeyPressedEvent& event) {
			if (event.GetKeyCode() == MOTH_KEY_LEFT) x -= 5;
			else if(event.GetKeyCode() == MOTH_KEY_RIGHT) x += 5;
		};
		auto keyRelease = [](const KeyReleasedEvent& event) {MOTH_LOG(event.GetKeyCode()); };
		SetKeyPressedCallback(keyCall);
		//SetKeyReleasedCallback(keyRelease);

		while (true) 
		{
			OnUpdate();

			Renderer::ClearScreen();

			Renderer::Draw(star, x, y, 1);

			std::this_thread::sleep_until(mNextFrameTime);

			Moth::GameWindow::GetWindow()->SwapBuffers();
			Moth::GameWindow::GetWindow()->CollectEvents();

			mNextFrameTime += mFrameDuration;
		}
	}

	void MothApp::OnUpdate()
	{
	}

	void MothApp::SetKeyPressedCallback(std::function<void(const KeyPressedEvent&)> keyPressedCallback)
	{
		GameWindow::GetWindow()->SetKeyPressedCallback(keyPressedCallback);
	}

	void MothApp::SetKeyReleasedCallback(std::function<void(const KeyReleasedEvent&)> keyReleasedCallback)
	{
		GameWindow::GetWindow()->SetKeyReleasedCallback(keyReleasedCallback);
	}

	

}