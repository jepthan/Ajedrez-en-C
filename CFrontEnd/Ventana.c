#include "Ventana.h"

void iniciarVentana(Ventana *interfaz) {
	if (!glfwInit()) {
		printf("error al iniciar pantalla\n");
	}
	interfaz->window = glfwCreateWindow(interfaz->width, interfaz->height, interfaz->Titulo, NULL, NULL);
	if (interfaz->window)
	{
		printf("Error al iniciar window");
	}
	glfwMakeContextCurrent(interfaz->window);
	GlConfig();
	GLenum GlewInitResult = glewInit();
	if (GLEW_OK != GlewInitResult) {
		printf("Error al inicializar glew %s", glewGetErrorString(GlewInitResult));
	}
}

void GlConfig() {

	const char* glsl_version = "#version 130";
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

}
