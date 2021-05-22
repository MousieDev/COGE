#include "Joystick.h"

int GetJoystickID(int i) {
    return GLFW_JOYSTICK_1 + i;
}

void UpdateJoysticks() {
    present = glfwJoystickPresent(id);

    if (present) {
        name = glfwGetJoystickName(id);
        axes = glfwGetJoystickAxes(id, &axesCount);
        JoystickButtons = glfwGetJoystickButtons(id, &buttonCount);
    }
}

void InitJoysticks(int i) {
    id = GetJoystickID(i);
    UpdateJoysticks();
}

float JoystickAxesState(int axis) {
    if (present) {
        return axes[axis];
    }

    return -1;
}

unsigned char JoystickButtonState(int button) {
    if (present) {
        return JoystickButtons[button];
    }

    return GLFW_RELEASE;
}

int GetJoystickAxesCount() {
    return axesCount;
}

int GetJoystickButtonCount() {
    return buttonCount;
}

int JoystickIsPresent() {
    return present;
}

const char * GetJoystickName() {
    return name;
}

 
