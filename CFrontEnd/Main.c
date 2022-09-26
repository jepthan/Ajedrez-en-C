#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include "Vec.h"
#include "Ventana.h"
int main() {

	Ventana app;
	app.height = 480;
	app.width = 480;
	app.Titulo = "C FrontEnd";
	iniciarVentana(&app);

	while (!glfwWindowShouldClose(app.window)) {

		glClearColor(0, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT);


		glfwPollEvents();
		glfwSwapBuffers(app.window);
	}
	return 0;
}