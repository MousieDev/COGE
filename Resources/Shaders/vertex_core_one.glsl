#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;

out vec2 TexCoord;

uniform vec4 move;

void main() {
    gl_Position = vec4(aPos, 1.0) + move;
    TexCoord = aTexCoord;
}
