#pragma once

#include "GLAD/gl.h"

typedef struct {
    unsigned int vao;
} VAO;

void GenVAO(VAO * vao)  {
    glGenVertexArrays(1, &vao -> vao);
    glBindVertexArray(vao -> vao);
} 

void RmVAO(VAO * vao) {
    glDeleteVertexArrays(1, &vao -> vao);
}

void BindVAO(VAO * vao) {
    glBindVertexArray(vao -> vao);
}

void UnbindVAO() {
    glBindVertexArray(0);
}


