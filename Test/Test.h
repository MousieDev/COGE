#ifndef _COGE_TEST 
    #define _COGE_TEST

    #include "../Framework/External/GLAD/gl.h"
    #include "../Framework/External/GLFW/glfw3.h"

// Credits: https://github.com/templalizer1284/cshader

    #include "../Framework/IndexBuffer.h"
    #include "../Framework/VertexArray.h"
    #include "../Framework/VertexBuffer.h"
    #include "../Framework/Shader.h"
    #include "../Framework/Texture.h"
    #include "../Framework/Keyboard.h"
    #include "../Framework/Mouse.h"
    #include "../Framework/Joystick.h"
    #include "../Framework/Utils.h"
    #include "../Framework/Log.h"

    GLFWwindow * window;
    unsigned int shaderID;
    int uLocation;
    ProgramProps props;

    void Init();
    void Update();
    void RenderBegin(float r, float g, float b, float a) {
	ClearScreen(r, g, b, a);        
    }

    void Render();

    void RenderEnd() {
	glfwSwapBuffers(window);
	glfwPollEvents();
    }

    void Destroy() {
	glUseProgram(0);
	glfwTerminate();
    }

    void ResetULoc() {
	uLocation = -1;
    }

    void Run() {
	Init();

	while (!glfwWindowShouldClose(window)) {
	    Update();
	    Render();
	}

	Destroy();
    }

#endif
