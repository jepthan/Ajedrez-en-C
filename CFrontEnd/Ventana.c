#include "Ventana.h"

void iniciarVentana(Ventana *interfaz) {

	if (!glfwInit()) {
		printf("error al iniciar pantalla\n");
	}
	interfaz->window = glfwCreateWindow(interfaz->width, interfaz->height, interfaz->Titulo, NULL, NULL);
	if (interfaz->window == NULL)
	{
		printf("Error al iniciar window");
	}
	glfwMakeContextCurrent(interfaz->window);
	GlConfig();
	GLenum GlewInitResult = glewInit();
	if (GLEW_OK != GlewInitResult) {
		printf("Error al inicializar glew %s", glewGetErrorString(GlewInitResult));
	}
	//error callback declaration
	glfwSetErrorCallback(error_callback);
	//frame buffer size callback
	glfwSetFramebufferSizeCallback(interfaz->window, framebuffer_size_callback);

}
void framebuffer_size_callback(GLFWwindow* window, int _width, int _height) {

	glViewport(0, 0, _width, _height);
	glfwGetFramebufferSize(window, &_width, &_height);
}
void error_callback(int error, const char* description) {
	fprintf(stderr, "Error: %s\n", description);

}
void GlConfig() {

	const char* glsl_version = "#version 130";
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	

}
