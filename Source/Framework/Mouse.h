#pragma once

#include <glad.h>
#include <GLFW/glfw3.h>

static double x, y;
static double lastX, lastY;
static double dx, dy;
static double scrollDX, scrollDY;
static int firstMouse; 
static int buttons[GLFW_MOUSE_BUTTON_LAST + 1];
static int buttonsChanged[GLFW_MOUSE_BUTTON_LAST + 1];

void InitMouse();
void CursorPosCallback(GLFWwindow *window, double _x, double _y);
void MouseButtonCallback(GLFWwindow *window, int button, int action, int mods);
void MouseWheelCallback(GLFWwindow *window, double _dx, double _dy);
double GetMouseX();
double GetMouseY();
double GetDX();
double GetDY();
double GetScrollDX();
double GetScrollDY();
int Button(int button);
int ButtonChanged(int button);
int ButtonDown(int button);
int ButtonUp(int button);