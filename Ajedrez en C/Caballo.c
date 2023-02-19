#include "Caballo.h"
void initCaballo(Caballo* oCaballo, Shader oShader)
{
	Vertex Vertices[4] = { {{0.5,0.5,0.0},{0.0,0.0}},
						{{0.5,-0.5,0.0},{0.0,1.0}},
						{{-0.5, -0.5, 0.0},{1.0, 1.0}},
						{{-0.5, 0.5, 0.0},{1.0, 0.0}} };

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

	oCaballo->VAO = VAO;
	oCaballo->Posicion.x = 0;
	oCaballo->Posicion.y = 0;
	oCaballo->oShader = oShader;
	File imagen;
	imagen.filename = "Caballo.png";
	oCaballo->Texture = loadImage(&imagen);

}

void pintarCaballo(Caballo oCaballo, Ventana app)
{
	Mat4 projection = OrthoMatrix(app);
	Mat4 scale = ScaleMat(0.17f);
	Mat4 Transfom = TransformMatrixP2(oCaballo.Posicion);

	UseShader(oCaballo.oShader);

	AddMat4PR(oCaballo.oShader, projection);
	AddMat4TR(oCaballo.oShader, Transfom);
	AddMat4SC(oCaballo.oShader, scale);


	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, oCaballo.Texture);

	glUniform1i(glGetUniformLocation(oCaballo.oShader.ID, "Texture0"), 0);

	glBindVertexArray(oCaballo.VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}