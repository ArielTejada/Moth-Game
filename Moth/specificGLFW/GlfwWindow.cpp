#include "pch.h"
#include "GlfwWindow.h"
#include "MothUtil.h"

namespace Moth
{
	GlfwWindow::GlfwWindow()
	{
		if (!glfwInit())
			MOTH_LOG("Error: GLFW failed to initialize!");
		
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
			MOTH_LOG("Error: GLAD failed to initialize!");

	}

	bool GlfwWindow::CreateWindow(int width, int height, const std::string& windowName)
	{
		mGlfwWindow = glfwCreateWindow(width, height, windowName.c_str(), NULL, NULL);

		if (mGlfwWindow == nullptr)
		{
			MOTH_LOG("Error: Window creation failed!");
			return false;
		}

		glfwMakeContextCurrent(mGlfwWindow);

		return true;
	}

	void GlfwWindow::SwapBuffers()
	{
		glfwSwapBuffers(mGlfwWindow);
	}

	void GlfwWindow::CollectEvents()
	{
		glfwPollEvents();
	}

	int GlfwWindow::GetWidth() const
	{
		int width, height;
		glfwGetWindowSize(mGlfwWindow, &width, &height);
		return width;
	}

	int GlfwWindow::GetHeight() const
	{
		int width, height;
		glfwGetWindowSize(mGlfwWindow, &width, &height);
		return height;
	}

	GlfwWindow::~GlfwWindow()
	{
		if (mGlfwWindow != nullptr)
			glfwDestroyWindow(mGlfwWindow);

		glfwTerminate();
	}
	
}