#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#include "../Data/GLAD/gl.h"
#include "../Data/GLFW/glfw3.h"

// Credits: https://github.com/templalizer1284/cshader

#include "../Data/IndexBuffer.h"
#include "../Data/VertexArray.h"
#include "../Data/VertexBuffer.h"
#include "../Data/Shader.h"
#include "../Data/Texture.h"
#include "../Data/Keyboard.h"
#include "../Data/Mouse.h"
#include "../Data/Joystick.h"
#include "../Data/Renderer.h"

GLFWwindow * window;
unsigned int shaderID;
int uLocation;
ProgramProps props;

void Init();
void Update();
void RenderBegin(float r, float g, float b, float a) {
    ClearScreen(r, g, b, a);        
}

void Render();

void RenderEnd() {
    glfwSwapBuffers(window);
    glfwPollEvents();
}

void Destroy() {
    glUseProgram(0);
    glfwTerminate();
}

void ResetULoc() {
    uLocation = -1;
}

void Run() {
    Init();

    while (!glfwWindowShouldClose(window)) {
	Update();
	Render();
    }

    Destroy();
}

