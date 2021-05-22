#pragma once

#include <stdio.h>

#include "GLAD/gl.h"
#include "GLFW/glfw3.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"

typedef struct {
    VAO vao;
    VBO vbo;
    IBO ibo;
} ProgramProps;

ProgramProps Gen(float * vertices, unsigned int * indices, unsigned int verticesSize, unsigned int indicesSize, unsigned int vboUsage, unsigned int iboUsage);
GLFWwindow * WindowInit(int width, int height, const char * name); 
void ClearScreen(float v0, float v1, float v2, float v3);
void Draw(unsigned int vertexNum);
