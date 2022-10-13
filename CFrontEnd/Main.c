#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include "Vec.h"
#include "Ventana.h"
#include "Casilla.h"
#include "LoadFile.h"
#include "Shader.h"
int main() {

	Ventana app;
	app.height = 991;
	app.width = 1920;
	app.Titulo = "C FrontEnd";
	iniciarVentana(&app);

	

	Shader oShader;
	oShader.FragmentName = "Fragment.txt";
	oShader.VertexName = "Vertex.txt";
	initShader(&oShader);
	Vec2 pos = {0.0,0.3};
	
	Casilla oCasilla[64];
	int conter = 0;
	float ypos = 0.85;
	for (int i = 0; i < 64; i++) {

		initCasilla(&oCasilla[i], oShader);
		oCasilla[i].Posicion.x = (conter * 0.125) - 0.440;
		oCasilla[i].Posicion.y = ypos;

		if (conter == 7) {
			conter = -1;
			ypos += -0.24;
		}
		conter++;
	}
	

	while (!glfwWindowShouldClose(app.window)) {

		glClearColor(0.5, 0, 0.7, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		for (int i = 0; i < 64; i++) {
			pintar(oCasilla[i], app);

		}
		
		glfwPollEvents();
		glfwSwapBuffers(app.window);
	}
	return 0;
}