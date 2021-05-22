#pragma once

#include "STB/stb_image.h"
#include "GLAD/gl.h"

typedef struct {
    unsigned int id;
    const char * path;
    unsigned int slot;
    unsigned char * buffer;
    int width, height, bpp;
} Texture;

void GenTexture(Texture * tex);
void BindTexture(Texture * tex);

