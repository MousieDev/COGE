#ifndef _COGE_KEYBOARD 
    
    #define _COGE_KEYBOARD

    #include "External/GLAD/gl.h"
    #include "External/GLFW/glfw3.h"

    // Declaration
    int keys[GLFW_KEY_LAST + 1];
    int keysChanged[GLFW_KEY_LAST + 1];

    void InitKeyboard();
    void KeyCallback(GLFWwindow * window, int key, int scancode, int action, int mods);
    int Key(int key);
    int KeyChanged(int key);
    int KeyDown(int key);
    int KeyUp(int key);
    int KeyHeldDown(GLFWwindow *window, int key);
    int KeyHeldUp(GLFWwindow *window, int key);

    // Implementation
    void InitKeyboard() {
	int i;
	for (i = 0; i < GLFW_KEY_LAST + 1; i++) {
	    keys[i] = 0;
	    keysChanged[i] = 0;
	}
    }

    void KeyCallback(GLFWwindow * window, int key, int scancode, int action, int mods) {
	if (action != GLFW_RELEASE) {
	    if (!keys[key]) {
		keys[key] = 1;
	    }
	}

	else {
	    keys[key] = 0;
	}

	keysChanged[key] = action != GLFW_REPEAT; 
    }

    int Key(int key) {
	return keys[key];
    }

    int KeyChanged(int key) {
	int ret = keysChanged[key];
	keysChanged[key] = 0;

	return ret;
    }

    int KeyDown(int key) {
	return keys[key] && KeyChanged(key);
    }

    int KeyUp(int key) {
	return !keys[key] && KeyChanged(key);
    }

    int KeyHeldDown(GLFWwindow * window, int key) {
	if (glfwGetKey(window, key)) {
	    return 1;
	}

	return 0;
    }

    int KeyHeldUp(GLFWwindow * window, int key) {
	if (!glfwGetKey(window, key)) {
	    return 1;
	}

	return 0;
    }

#endif   
