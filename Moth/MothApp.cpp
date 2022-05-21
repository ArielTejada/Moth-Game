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
	MothApp::MothApp()
	{
		MOTH_LOG("MothApp Running...\n");

		Moth::GameWindow::Init();

		Moth::GameWindow::GetWindow()->CreateWindow(1200, 700, "game window");

		Renderer::Init();
	}

	void MothApp::Run()
	{
		mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

		while (true) 
		{
			Renderer::ClearScreen();

			OnUpdate();

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