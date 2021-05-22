#pragma once

#include "GLAD/gl.h"

typedef struct {
    unsigned int vao;
} VAO;

void GenVAO(VAO * vao);
void RmVAO(VAO * vao);
void BindVAO(VAO * vao);
void UnbindVAO();
