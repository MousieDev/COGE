#include "Renderer.h"

ProgramProps Gen(float *vertices, unsigned int *indices, unsigned int verticesSize, unsigned int indicesSize, unsigned int vboUsage, unsigned int iboUsage) {
	ProgramProps props;

	GenVAO(&props.vao);
	BindVAO(&props.vao);

	props.vbo.data = vertices;
	props.vbo.size = verticesSize;
	props.vbo.usage = vboUsage;

	GenVBO(&props.vbo);
	BindVBO(&props.vbo);

	props.ibo.data = indices;
	props.ibo.size = indicesSize;
	props.ibo.usage = iboUsage;

	GenIBO(&props.ibo);
	BindIBO(&props.ibo);

	return props;
}

GLFWwindow *WindowInit(int width, int height, const char *name) {

	if (!glfwInit()) {
		LogError("Error Initializing GLFW", NULL);
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

# ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
	glfwWindowHint(GLFW_OPENGL_COMPAT_PROFILE, GL_TRUE);
# endif

	GLFWwindow *window = glfwCreateWindow(width, height, name, NULL, NULL);

	if (!window) {
		LogError("Error Making Window", NULL);
		glfwTerminate();
	}

	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		LogError("Error Initializing GLAD", NULL);
		glfwTerminate();
	}

	LogInfo("OpenGL Version: %s", glGetString(GL_VERSION));

	// Aren't those from fixed pipeline (GL 1.1?)
	//glEnable(GL_BLEND);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	return window;
}

void ClearScreen(float v0, float v1, float v2, float v3) {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(v0, v1, v2, v3);
}

void Draw(unsigned int vertexNum) {
	glDrawElements(GL_TRIANGLES, vertexNum, GL_UNSIGNED_INT, 0);
}