#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glad.h>
#include <GLFW/glfw3.h>

// Credits: https://github.com/templalizer1284/cshader
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "Shader.h"
#include "Texture.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Joystick.h"
#include "Renderer.h"

// Add more header files, ../../, OpenGL-CPP/OpenGL-Website-Video-Tuts 
// Add keyboard support, maybe make it more centered to Main.c rather than Keyboard.h
int main(void) {
	GLFWwindow *window = WindowInit(640, 480, "OpenGL");

	unsigned int programID = LoadShader("Resources/Shaders/vertex_core_one.glsl", "Resources/Shaders/fragment_core_one.glsl");

	glUseProgram(0);
	glUseProgram(programID);

	Texture tex;
	tex.path = "Resources/Images/Square.png";
	tex.slot = 0;

	float vertices[] = {
		-0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
		 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
		 0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
		-0.5f,  0.5f, 0.0f, 0.0f, 1.0f
	};

	unsigned int indices[] = {
		0, 1, 2,
		2, 3, 0
	};

	ProgramProps props = Gen(vertices, indices, sizeof(vertices), sizeof(indices), GL_STATIC_DRAW, GL_STATIC_DRAW);

	GenTexture(&tex);

	unsigned int vertexNum = sizeof(indices) / sizeof(indices[0]);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 *sizeof(float), (void *) 0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 *sizeof(float), (void *) (3 *sizeof(float)));

	BindTexture(&tex, 1);

	int loc = glGetUniformLocation(programID, "t");
	glUniform1i(loc, 1);

	InitKeyboard();
	glfwSetKeyCallback(window, KeyCallback);

	InitMouse();
	glfwSetCursorPosCallback(window, CursorPosCallback);
	glfwSetMouseButtonCallback(window, MouseButtonCallback);
	glfwSetScrollCallback(window, MouseWheelCallback);

	InitJoysticks(0);
	UpdateJoysticks();

	if (JoystickIsPresent()) {
		printf("Joystick\n");
	}

	else {
		printf("No Joystick\n");
	}

	float proj[4][4];

	for (int i = 0; i < 4; i++) {
		for (int y = 0; y < 4; y++) {
			proj[y][i] = 1.0f;
		}
	}

	/*
	mat4 view = {
		1, 0, 0, 0, 
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
	};


	mat4 model = {
		1, 0, 0, 0, 
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
	};


	mat4 mvp, viewProj; 

	glm_mat4_mul(proj, view, viewProj);
	glm_mat4_mul(viewProj, model, mvp); */
	const char *n = "t";
	int loc2 = glGetUniformLocation(programID, "trans");
	printf("%d\n", loc2);
	
	int vec4[4] = { 1, 1, 1, 1 };

	int loc3 = glGetUniformLocation(programID, "sub");
	printf("%d\n", loc3);

	int w = 1;

	int loc4 = glGetUniformLocation(programID, "xy");
	printf("%d\n", loc4);

	float xy[2] = { 0, 0 };

	glUseProgram(0);
	while (!glfwWindowShouldClose(window)) {
		ClearScreen(0.2f, 0.3f, 0.5f, 1.0f);

		glUseProgram(programID);

		// Multiply NDC with 255 to get RGB value
		// glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glUniform4f(loc2, vec4[0], vec4[1], vec4[2], vec4[3]);
		glUniform1i(loc3, w);
		glUniform2f(loc4, xy[0], xy[1]);
		Draw(vertexNum);

		if (KeyDown(GLFW_KEY_R)) {
			for (int i = 0; i < 4; i++) {
				vec4[i] = 1;
			}
			w = 1;

			for (int i = 0; i < 2; i++) {
				xy[i] = 0;
			}
		}

		if (KeyHeldDown(window, GLFW_KEY_W)) {
			if (w >= 2) {
				w -= 0.5;
			}
		}

		if (KeyHeldDown(window, GLFW_KEY_S))  w += 1;
		if (KeyHeldDown(window, GLFW_KEY_LEFT) || KeyHeldDown(window, GLFW_KEY_A)) xy[0] += 0.1; 
		if (KeyHeldDown(window, GLFW_KEY_RIGHT) || KeyHeldDown(window, GLFW_KEY_D)) xy[0] -= 0.1; 
		if (KeyHeldDown(window, GLFW_KEY_UP)) xy[1] -= 0.1;
		if (KeyHeldDown(window, GLFW_KEY_DOWN)) xy[1] += 0.1;

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
