#include "Casilla.h"

void initCasilla(Casilla* oCasilla, Shader oShader) {
	Vertex Vertices[4] = { {{0.5,0.5,0.0},{1.0,1.0}},
						{{0.5,-0.5,0.0},{1.0,0.0}},
						{{-0.5, -0.5, 0.0},{1.0, 0.0}},
						{{-0.5, 0.5, 0.0},{0.0, 1.0}}};

	unsigned int indices[] = {
		0, 1, 3,  
		1, 2, 3   
	};
	unsigned int VAO;//Vertex array object
	unsigned int VBO;//Vertex buffer object
	unsigned int EBO;//Element buffer object
	
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);


	glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(Vertex), &Vertices[0], GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);


	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	
	oCasilla->VAO = VAO;
	oCasilla->Posicion.x = 0;
	oCasilla->Posicion.y = 0;
	oCasilla->oShader = oShader;
}
void pintar(Casilla oCasilla, Ventana app) {

	Mat4 projection = OrthoMatrix(app);
	Mat4 scale = ScaleMat(0.15f);
	Mat4 Transfom = TransformMatrixP2(oCasilla.Posicion);

	AddMat4PR(oCasilla.oShader, projection);
	AddMat4TR(oCasilla.oShader, Transfom);
	AddMat4SC(oCasilla.oShader, scale);


	UseShader(oCasilla.oShader);
	glBindVertexArray(oCasilla.VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

}