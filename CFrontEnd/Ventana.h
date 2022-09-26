#ifndef _Ventana_H
#define _Ventana_H
#include <GL/glew.h>
#include <GLFW/glfw3.h>

typedef struct Ventana {
	int width;
	int height;
	GLFWwindow* window;
	const char* Titulo;
};

#endif