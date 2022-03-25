#include "pch.h"


#include "MothApp.h"
#include "GameWindow.h"
#include "GLFW/glfw3.h"
#include "glad/glad.h"

namespace Moth 
{
	void MothApp::Run()
	{
		MOTH_LOG("MothApp Running...\n");

		Moth::GameWindow::Init();

		Moth::GameWindow::GetWindow()->CreateWindow(800, 600, "game window");

		float verticies[] = {
				-0.5f, -0.5f, // bottom-left
				-0.5f,  0.5f, // top-left
				 0.5f,  0.5f, // top-right
				 0.5f, -0.5f  // bottom-right
		};

		unsigned int indices[] = {
			0, 1, 2,  // upper-left triangle
			0, 2, 3   // bottom-left triangle
		};

		unsigned VAO, VBO, EBO;
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glGenBuffers(1, &EBO);

		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(verticies), verticies, GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GL_FLOAT), (void*)0);
		glEnableVertexAttribArray(0);

		// =============================================================================

		std::string vertex_code{ R"()" };

		while (true) 
		{
			OnUpdate();

			Moth::GameWindow::GetWindow()->SwapBuffers();
			Moth::GameWindow::GetWindow()->CollectEvents();
		}
	}

	void MothApp::OnUpdate()
	{
	}

	

}