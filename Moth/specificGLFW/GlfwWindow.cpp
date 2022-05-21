#include "pch.h"

#include "glad/glad.h"
#include "GlfwWindow.h"
#include "MothUtil.h"

namespace Moth
{
	GlfwWindow::GlfwWindow()
	{
		if (!glfwInit())
			MOTH_LOG("Error: GLFW failed to initialize!");
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
		glfwSwapInterval(1);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
			MOTH_LOG("Error: GLAD failed to initialize!");

		glfwSetWindowUserPointer(mGlfwWindow, &mCallbacks);

		glfwSetKeyCallback(mGlfwWindow, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				if (action == GLFW_PRESS || action == GLFW_REPEAT)
				{
					Callbacks* userPointer{ (Callbacks*)glfwGetWindowUserPointer(window) };

					KeyPressedEvent event{ key };
					userPointer->keyPressedCallback(event);
				}
				else if (action == GLFW_RELEASE) 
				{
					Callbacks* userPointer{ (Callbacks*)glfwGetWindowUserPointer(window) };

					KeyReleasedEvent event{ key };
					userPointer->keyReleasedCallback(event);
				}

			}
		);

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

	void GlfwWindow::SetKeyPressedCallback(std::function<void(const KeyPressedEvent&)> keyPressedCallback)
	{
		mCallbacks.keyPressedCallback = keyPressedCallback;
	}

	void GlfwWindow::SetKeyReleasedCallback(std::function<void(const KeyReleasedEvent&)> keyReleasedCallback)
	{
		mCallbacks.keyReleasedCallback = keyReleasedCallback;
	}
	
}