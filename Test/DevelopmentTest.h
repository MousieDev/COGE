#pragma once

#include "Test.h"

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

