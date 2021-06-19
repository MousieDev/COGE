#pragma once

#include <glad.h>
#include <GLFW/glfw3.h>

static int keys[GLFW_KEY_LAST + 1];
static int keysChanged[GLFW_KEY_LAST + 1];

void InitKeyboard();
void KeyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);
int Key(int key);
int KeyChanged(int key);
int KeyDown(int key);
int KeyUp(int key);
int KeyHeldDown(GLFWwindow *window, int key);
int KeyHeldUp(GLFWwindow *window, int key);