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
	app.height = 720;
	app.width = 720;
	app.Titulo = "C FrontEnd";
	iniciarVentana(&app);

	

	Shader oShader;
	oShader.FragmentName = "Fragment.txt";
	oShader.VertexName = "Vertex.txt";
	initShader(&oShader);
	Vec2 pos = {0,0.0};
	Mat4 Transform = TransformMatrixP2(pos);
	AddMat4(oShader, Transform);
	Casilla oCasilla;
	initCasilla(&oCasilla, oShader);

	while (!glfwWindowShouldClose(app.window)) {

		glClearColor(0.5, 0, 0.7, 1);
		glClear(GL_COLOR_BUFFER_BIT);

		
		
		pintar(oCasilla);
		glfwPollEvents();
		glfwSwapBuffers(app.window);
	}
	return 0;
}