#pragma once

typedef struct {
	int size;
	const void *data;
	int usage;
	unsigned int vbo;
} VBO;

void GenVBO(VBO *vbo);
void RmVBO(VBO *vbo);
void BindVBO(VBO *vbo);
void UnbindVBO();