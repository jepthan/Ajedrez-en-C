#ifndef _Ventana_H
#define _Ventana_H
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>

typedef struct Ventana {
	int width;
	int height;
	GLFWwindow* window;
	const char* Titulo;
}Ventana;
void iniciarVentana(Ventana *interfaz);
void GlConfig();
void framebuffer_size_callback(GLFWwindow* window, int _width, int _height);
void error_callback(int error, const char* description);


#endif