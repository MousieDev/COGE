#pragma once

typedef struct {
	unsigned int id;
	const char *path;
	unsigned int slot;
	unsigned char *buffer;
	int width, height, bpp;
} Texture;

void GenTexture(Texture *tex);
void BindTexture(Texture *tex, unsigned int slot);