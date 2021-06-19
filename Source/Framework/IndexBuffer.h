#pragma once

#include <stdio.h>
#include <glad.h>

typedef struct {
	const unsigned int *data;
	unsigned int size;
	int usage;
	unsigned int ibo;
	unsigned int count;
} IBO;

void GenIBO(IBO *indexBuffer);
void RmIBO(IBO *indexBuffer);
void BindIBO(IBO *indexBuffer);
void UnbindIBO();