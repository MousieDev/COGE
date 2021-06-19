#include "VertexBuffer.h"

void GenVBO(VBO *vbo) {    
	glGenBuffers(1, &vbo -> vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo -> vbo);
	glBufferData(GL_ARRAY_BUFFER, vbo -> size, vbo -> data, vbo -> usage);
}

void RmVBO(VBO *vbo) {
	glDeleteBuffers(1, &vbo -> vbo);
}

void BindVBO(VBO *vbo) {
	glBindBuffer(GL_ARRAY_BUFFER, vbo -> vbo);
}

void UnbindVBO() {
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}