#include "Texture.h"
#include <stb_image.h>
#include <glad.h>

void GenTexture(Texture *tex) {
	stbi_set_flip_vertically_on_load(1);

	unsigned int color;

	if (tex -> path != "") {
		tex -> buffer = stbi_load(tex -> path, &tex -> width, &tex -> height, &tex -> bpp, 4);
	} else {
		unsigned int color = 0xffffffff;
	}

	glGenTextures(1, &tex -> id);
	glBindTexture(GL_TEXTURE_2D, tex -> id);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	if (tex -> path != "") {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, tex -> width, tex -> height, 0, GL_RGBA, GL_UNSIGNED_BYTE, tex -> buffer);
	}
	else glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, 1, 1, 0, GL_RGBA, GL_UNSIGNED_BYTE, &color);

	glActiveTexture(0);
	glBindTexture(GL_TEXTURE_2D, tex -> id);

	if (tex -> buffer) {
		stbi_image_free(tex -> buffer);
	}
}

void BindTexture(Texture *tex, unsigned int slot) { 
	glActiveTexture(slot);
	glBindTexture(GL_TEXTURE_2D, tex -> id);
}