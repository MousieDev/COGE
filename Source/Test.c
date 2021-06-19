#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#include <glad.h>
#include <GLFW/glfw3.h>

// Credits: https://github.com/templalizer1284/cshader
// This file is messy as hell. I'd reformat it but whatever, i dont really care about this file. -MousieDev

#include <IndexBuffer.h>
#include <VertexArray.h>
#include <VertexBuffer.h>
#include <Shader.h>
#include <Texture.h>
#include <Keyboard.h>
#include <Mouse.h>
#include <Joystick.h>
#include <Renderer.h>
#include <log.h>

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

Texture tex;
float vertices[20] = {
 	-0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
	 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
	 0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
	-0.5f,  0.5f, 0.0f, 0.0f, 1.0f        
};


unsigned int indices[] = {
    0, 1, 2,
    2, 3, 0
};

unsigned int vertexNum;
unsigned int columns;

float movementVec[4] = {
    0, 0, 0, 0
};

void Init() {
    window = WindowInit(640, 480, "Dev Testing");
    shaderID = LoadShader("Resources/Shaders/vertex_core_one.glsl", "Resources/Shaders/fragment_core_one.glsl");

    glUseProgram(0);
    glUseProgram(shaderID);

    tex.path = "Resources/Images/Square.png";
    tex.slot = 0;

    GenTexture(&tex);
    BindTexture(&tex, 0); 

    props = Gen(vertices, indices, sizeof(vertices), sizeof(indices), GL_STATIC_DRAW, GL_STATIC_DRAW);
   
    vertexNum = sizeof(indices) / sizeof(indices[0]);
    columns = 5;


    unsigned int index[2]  = { 0, 1 };
    int size[4]            = { 3, 2 };
    /*    long stride            = sizeof(Vertex);
          int pointers[4]        = { offsetof(Vertex, Position), offsetof(Vertex, Color), offsetof(Vertex, TexCoords), offsetof(Vertex, TexID) }; */

    int stride = columns * sizeof(float);
    int pointers[2] = { 0, 3 * sizeof(float) };
    int vertex_pointer_num = 2;
    
    int i;

    for (i = 0; i < vertex_pointer_num; i++) {
        glEnableVertexAttribArray(index[i]);
        glVertexAttribPointer(index[i], size[i], GL_FLOAT, GL_FALSE, stride, (void *) pointers[i]);
    }


    uLocation = glGetUniformLocation(shaderID, "uTexture");
    glUniform1i(uLocation, tex.slot);
    ResetULoc();

    InitKeyboard();
    glfwSetKeyCallback(window, KeyCallback);

    InitMouse();
    glfwSetCursorPosCallback(window, CursorPosCallback);
    glfwSetMouseButtonCallback(window, MouseButtonCallback);
    glfwSetScrollCallback(window, MouseWheelCallback);

    InitJoysticks(0);
    UpdateJoysticks();

    if (JoystickIsPresent()) {
	LogWarn("No Joystick", NULL);
    }

    else {
	LogWarn("No Joystick", NULL);
    }

    uLocation = glGetUniformLocation(shaderID, "move");
    glUseProgram(0);
}

void Update() {
    
    if (KeyDown(GLFW_KEY_R)) {
	movementVec[0] = 0;
	movementVec[1] = 1;
	movementVec[2] = 2;
	movementVec[3] = 3;
    }

    if (KeyHeldDown(window, GLFW_KEY_W)) {
	if (movementVec[3] >= 2) {
	    movementVec[3] -= 0.5;
	}
    }

    if (KeyHeldDown(window, GLFW_KEY_S)) {
	movementVec[3] += 1;
    }


    if (KeyHeldDown(window, GLFW_KEY_LEFT) || KeyHeldDown(window, GLFW_KEY_A)) {
	movementVec[0] += 0.1; 
    }

    if (KeyHeldDown(window, GLFW_KEY_RIGHT) || KeyHeldDown(window, GLFW_KEY_D)) {
	movementVec[0] -= 0.1; 
    }

    if (KeyHeldDown(window, GLFW_KEY_UP)) {
	movementVec[1] -= 0.1;
    }

    if (KeyHeldDown(window, GLFW_KEY_DOWN)) {
	movementVec[1] += 0.1;
    }


    glUseProgram(shaderID);
    glUniform4f(uLocation, movementVec[0], movementVec[1], movementVec[2], movementVec[3]);
}

void Render() {
    RenderBegin(0.2f, 0.3f, 0.5f, 1.0f);

	Draw(vertexNum);

    RenderEnd();
}



void Run() {
    Init();

    while (!glfwWindowShouldClose(window)) {
	Update();
	Render();
    }

    Destroy();
}

int main(void) {
    Run();
    return 0;
}