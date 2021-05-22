#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec4 aColor;
layout (location = 2) in vec2 aTexCoord;
layout (location = 3) in float a_TexIndex;

out vec4 ourColor;
out vec2 TexCoord;
out float v_TexIndex;

uniform mat4 transform;
uniform mat4 special_;

void main() {
    if (a_TexIndex == -2) gl_Position = transform * special_ * vec4(aPos, 1.0);
    else gl_Position = transform * vec4(aPos, 1.0);
    ourColor = aColor;
    v_TexIndex = a_TexIndex;
    TexCoord = aTexCoord;
}

