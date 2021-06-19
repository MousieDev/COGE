#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;

out vec2 TexCoord;
uniform vec4 trans;
uniform int sub;
uniform vec2 xy;

void main() {
    gl_Position = trans * (vec4(aPos, 1.0) + vec4(0.0, 0.0, 0.0, sub) + vec4(xy, 0.0, 0.0));
    TexCoord = aTexCoord;
}
