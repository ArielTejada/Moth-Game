#include "pch.h"
#include "GameWindow.h"
#include "specificGLFW\GlfwWindow.h"

namespace Moth
{

	void GameWindow::Init()
	{
		if (mInstance == nullptr)
			mInstance = new GameWindow;


	}

	GameWindow* GameWindow::GetWindow()
	{
		assert(mInstance);
		return mInstance;
	}

	bool GameWindow::CreateWindow(int width, int height, const std::string& windowName)
	{
		return mWindow->CreateWindow(800, 600, "Spring 2022");
	}

	void GameWindow::SwapBuffers()
	{
		mWindow->SwapBuffers();
	}

	void GameWindow::CollectEvents()
	{
		mWindow->CollectEvents();
	}

	int GameWindow::GetWidth() const
	{
		return mWindow->GetWidth();
	}

	int GameWindow::GetHeight() const
	{
		return mWindow->GetHeight();
	}

	GameWindow::GameWindow()
	{
		#ifdef MOTH_WINDOWS
			mWindow = new GlfwWindow;
		#elif defined MOTH_MACOS
			mWindow = new GlfwWindow;
		#elif defined MOTH_LINUX
			mWindow = new GlfwWindow;
		#else
			#Unsupported_platform
		#endif
	}

}


