#ifndef _COGE_JOYSTICK 

    #define _COGE_JOYSTICK
    #include "External/GLAD/gl.h"
    #include "External/GLFW/glfw3.h"
				
    #define GLFW_JOYSTICK_BTN_LEFT 0
    #define GLFW_JOYSTICK_BTN_DOWN 1
    #define GLFW_JOYSTICK_BTN_RIGHT 2
    #define GLFW_JOYSTICK_BTN_UP 3	
    #define GLFW_JOYSTICK_SHOULDER_LEFT 4
    #define GLFW_JOYSTICK_SHOULDER_RIGHT 5	
    #define GLFW_JOYSTICK_TRIGGER_LEFT 6
    #define GLFW_JOYSTICK_TRIGGER_RIGHT 7
    #define GLFW_JOYSTICK_SELECT 8		
    #define GLFW_JOYSTICK_START 9			
    #define GLFW_JOYSTICK_LEFT_STICK 10				
    #define GLFW_JOYSTICK_RIGHT_STICK 11		   	        
    #define GLFW_JOYSTICK_HOE 12			
    #define GLFW_JOYSTICK_CLICK 13	
    #define GLFW_JOYSTICK_DPAD_UP 14				
    #define GLFW_JOYSTICK_DPAD_RIGHT 15		
    #define GLFW_JOYSTICK_DPAD_DOWN 16			
    #define GLFW_JOYSTICK_DPAD_LEFT 17		

    //       PS                    XBox
    //	Square		|	X
    //	X		|	A
    //	Circle		|	B
    //	Triangle	|	Y
    //	L1		|	LB
    //	R1		|	RB
    //	L2		|	LT
    //	R2		|	RT
    //	Share		|	Address
    //	Options		|	Menu
    //	L3		|	LS
    //	R3		|	RS
    //	Home		|	Home
    //	Touch pad	|	n/a
    //	Dpad up		|	Dpad up
    //	Dpad right	|	Dpad right
    //	Dpad down	|	Dpad down
    //	Dpad left	|	Dpad left

    // Declarations
    int present;
    int id;
    const char * name;
    int axesCount;
    const float * axes;
    int buttonCount;
    const unsigned char * JoystickButtons;

    int GetJoystickID(int i);
    void UpdateJoysticks();
    void InitJoysticks(int i);
    float JoystickAxesState(int axis);
    unsigned char JoystickButtonState(int button);
    int GetJoystickAxesCount();    
    int GetJoystickButtonCount();
    int JoystickIsPresent();
    const char * GetJoystickName();


    // Implementation
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

#endif
