#pragma once

#include <stdio.h>
#include "3rd_party/GLAD/gl.h"

typedef struct {
    const unsigned int * data;
    unsigned int size;
    int usage; 
    unsigned int ibo;
    unsigned int count;
} IBO;

void GenIBO(IBO * indexBuffer) {
    glGenBuffers(1, &indexBuffer -> ibo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer -> ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexBuffer -> size, indexBuffer -> data, indexBuffer -> usage);
    indexBuffer -> count = indexBuffer -> size / sizeof(unsigned int);
}

void RmIBO(IBO * indexBuffer) {
    glDeleteBuffers(1, &indexBuffer -> ibo);
}

void BindIBO(IBO * indexBuffer) {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer -> ibo);
}

void UnbindIBO() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

