#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#include "../Src/3rd_party/GLAD/gl.h"
#include "../Src/3rd_party/GLFW/glfw3.h"

// Credits: https://github.com/templalizer1284/cshader

#include "../Src/IndexBuffer.h"
#include "../Src/VertexArray.h"
#include "../Src/VertexBuffer.h"
#include "../Src/Shader.h"
#include "../Src/Texture.h"
#include "../Src/Keyboard.h"
#include "../Src/Mouse.h"
#include "../Src/Joystick.h"
#include "../Src/Renderer.h"
#include "../Src/Log.h"

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

