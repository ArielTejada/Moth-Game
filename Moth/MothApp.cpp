#include "pch.h"


#include "MothApp.h"
#include "GameWindow.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

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
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GL_FLOAT), (void*)0);
		glEnableVertexAttribArray(0);

		// =============================================================================

		const char* vertexShader = R"(
		#version 330 core
		layout (location = 0) in vec2 rawCoords

		void main ()
		{
			gl_Position = vec4(rawCoords.x, rawCoords.y, 0.0f, 1.0f);
		}

		)";

		const char* fragmentShader = R"(
		#version 330 core
		out vec4 fragColor

		void main ()
		{
			fragColor = vec4(0.0f, 1.0f, 0.0f, 1.0f)
		}

		)";


		/*
		unsigned int vertexProg = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
		glCompileShader(vertexShader);
		// check for shader compile errors
		int success;
		char infoLog[512];
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
		}
		// fragment shader
		unsigned int fragmentProg = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
		glCompileShader(fragmentShader);
		// check for shader compile errors
		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
		}
		// link shaders
		unsigned int shaderProgram = glCreateProgram();
		glAttachShader(shaderProgram, vertexShader);
		glAttachShader(shaderProgram, fragmentShader);
		glLinkProgram(shaderProgram);
		// check for linking errors
		glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
		}
		glDeleteShader(vertexProg);
		glDeleteShader(fragmentProg);

		*/

		while (true) 
		{
			OnUpdate();

			//glUseProgram(shaderProgram);
			//glBindVertexArray(VAO);
			//glDrawArrays(GL_TRIANGLES, 0, 4);


			Moth::GameWindow::GetWindow()->SwapBuffers();
			Moth::GameWindow::GetWindow()->CollectEvents();
		}
	}

	void MothApp::OnUpdate()
	{
	}

	

}