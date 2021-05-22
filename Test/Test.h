#include "../Includes.h"

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

