#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include "Vec.h"
int main() {

	GLFWwindow* window;
	int width = 480;
	int height = 480;

	if (!glfwInit()) {
		printf("error al iniciar pantalla\n");
	}
	
	window = glfwCreateWindow(width, height, "CFront End", NULL, NULL);
	if (!window)
	{
		printf("Error al iniciar window");
	}
	glfwMakeContextCurrent(window);

	const char* glsl_version = "#version 130";
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	GLenum GlewInitResult = glewInit();
	if (GLEW_OK != GlewInitResult) {
		printf("Error al inicializar glew %s", glewGetErrorString(GlewInitResult));
	}
	
	while (!glfwWindowShouldClose(window)) {

		glClearColor(0, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT);


		glfwPollEvents();
		glfwSwapBuffers(window);
	}
	return 0;
}