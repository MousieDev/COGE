#pragma once

#include <glad.h>

typedef struct {
	unsigned int vao;
} VAO;

void GenVAO(VAO *vao);

// Error might occur, remove the ampersands

void RmVAO(VAO *vao);
void BindVAO(VAO *vao);
void UnbindVAO();