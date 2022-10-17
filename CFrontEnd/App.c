#include "App.h"


int current = 0;

void StartApp()
{

	

	int movimientos[64];

	// tiempos tiempos para retrazos y delta time
	double Time1 = 0;
	double Time2 = 0;
	double deltaTime = 0;

	


	//Ventana app;
	app.height = 991;
	app.width = 1920;
	app.Titulo = "C FrontEnd";
	iniciarVentana(&app);

	glfwSetKeyCallback(app.window, key_callback);

	//posicion del caballo inicial (11 casilla)
	//int current = 10;


	//Shader oShader;
	oShader.FragmentName = "Fragment.txt";
	oShader.VertexName = "Vertex.txt";
	initShader(&oShader);


	//Shader oShader_Caballo;
	oShader_Caballo.FragmentName = "Fragment_Caballo.txt";
	oShader_Caballo.VertexName = "Vertex.txt";
	initShader(&oShader_Caballo);


	//Caballo oCaballo;
	initCaballo(&oCaballo, oShader_Caballo);

	//Casilla oCasilla[64];

	int conter = 0;
	int colorcont = 0;
	float ypos = 0.85;

	Vec3 blanco = { 0.8,0.8,0.8 };
	Vec3 Negro = { 0.1,0.1,0.1 };
	Vec3 temp = Negro;
	Vec3 temp2 = blanco;

	//inicializar las casillas con su posicion y color
	for (int i = 0; i < 64; i++) {

		initCasilla(&oCasilla[i], oShader);
		oCasilla[i].Posicion.x = (conter * 0.125) - 0.440;
		oCasilla[i].Posicion.y = ypos;
		if (i % 2 == 0) {
			oCasilla[i].Color = temp;

		}
		else {
			oCasilla[i].Color = temp2;
		}
		if (conter == 7) {
			conter = -1;
			ypos += -0.24;
			if (colorcont % 2 == 0) {
				temp = blanco;
				temp2 = Negro;
			}
			else {
				temp = Negro;
				temp2 = blanco;
			}
			colorcont++;
		}

		conter++;
	}



	//Set posicion inicial del caballo
	oCaballo.Posicion = oCasilla[current].Posicion;

	//swap interval 1 cambia el buffer  60 veces por segundo
	glfwSwapInterval(1);
	//el ciclo sige corriendo mientras la ventana este activa
	while (!glfwWindowShouldClose(app.window)) {

		//toma el tiempo inical del frame
		Time1 = glfwGetTime();

		//limpia el frame a un color 
		glClearColor(0.3, 0.3, 0.3, 0.3);
		glClear(GL_COLOR_BUFFER_BIT);

		//pinta las casillas
		for (int i = 0; i < 64; i++) {
			pintar(oCasilla[i], app);

		}
		//pinta el caballo despues para que este sobre las casillas
		pintarCaballo(oCaballo, app);


		glfwPollEvents();
		glfwSwapBuffers(app.window);

		Time2 = glfwGetTime();

		deltaTime = Time2 - Time1;
		system("cls");
		printf("%f", 1/deltaTime);
	}
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_E && action == GLFW_PRESS) {
		oCaballo.Posicion = oCasilla[current].Posicion;
		if (current < 64) {
			current++;
		}
		else {
			current = 0;
		}
	}

}
