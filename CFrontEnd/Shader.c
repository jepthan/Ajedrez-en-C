#include "Shader.h"

void initShader(Shader* oShader) {
	CopileShader(oShader);
	CreateShader(oShader);
}
void CopileShader(Shader* oShader) {
	//sucess se utiliza para verficar si ubo errores
	int success;
	//info log devueve la iformacion de errores
	char infoLog[512];

	// Archivo de texto donde esta el vertex shader
	File VertexF;
	VertexF.filename = oShader->VertexName;
	// Archivo de texto donde esta el vertex shader
	File FragmentF;
	FragmentF.filename = oShader->FragmentName;
	
	//se carga el codigo de los dos shader loadShader lo devuelve como un char * (array of char)
	char* vShaderCode = LoadShader(&VertexF);
	char* fShaderCode = LoadShader(&FragmentF);

	//crea el vertex shader para la grafica
	oShader->Vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(oShader->Vertex, 1, &vShaderCode, NULL);
	//copila el shader
	glCompileShader(oShader->Vertex);
	// imprimir errores de copilacion de los shader
	glGetShaderiv(oShader->Vertex, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(oShader->Vertex, 512, NULL, infoLog);
		printf("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n%s\n", infoLog);
	};

	//Crea el Fragment shader
	oShader->Fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(oShader->Fragment, 1, &fShaderCode, NULL);
	//copila el shader
	glCompileShader(oShader->Fragment);
	// imprime errores si encuentra alguno
	glGetShaderiv(oShader->Fragment, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(oShader->Fragment, 512, NULL, infoLog);
		printf("ERROR::SHADER::FAGMENT::COMPILATION_FAILED\n%s\n", infoLog);
	};

	//Elimina punteros
	free(vShaderCode);
	free(fShaderCode);
}
void CreateShader(Shader* oShader) {

	int success;
	char infoLog[512];
	//Create un programa para que la tarjeta grafica lo corra y alacena el id del objecto del programa creado por  opengl
	oShader->ID = glCreateProgram();

	//agrega vertex shader y fragment shader a el programa
	glAttachShader(oShader->ID, oShader->Vertex);
	glAttachShader(oShader->ID, oShader->Fragment);

	//link program 
	glLinkProgram(oShader->ID);

	// imprimir linking errors
	glGetProgramiv(oShader->ID, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(oShader->ID, 512, NULL, infoLog);
		printf("ERROR::SHADER::PROGRAM::LINKING_FAILED\n%s\n",infoLog);
	}
	// elimina los objetos del vertex y fragment shader pues ya estan en el programa y no se necesitan mas
	glDeleteShader(oShader->Vertex);
	glDeleteShader(oShader->Fragment);

}
void UseShader(Shader oShader) {
	glUseProgram(oShader.ID);
}
void AddMat4PR(Shader oShader, Mat4 Matrix) {

	//agrega matriz de projection
	UseShader(oShader);
	GLuint matrixID = glGetUniformLocation(oShader.ID, "projection");

	glUniformMatrix4fv(matrixID, 1, GL_FALSE, &Matrix.matrix[0][0]);
}
void AddMat4TR(Shader oShader, Mat4 Matrix) {

	//agrea matriz de transformacion
	UseShader(oShader);
	GLuint matrixID = glGetUniformLocation(oShader.ID, "Transform");

	glUniformMatrix4fv(matrixID, 1, GL_FALSE, &Matrix.matrix[0][0]);
}
void AddMat4SC(Shader oShader, Mat4 Matrix) {

	//agrega matriz dé scale
	UseShader(oShader);
	GLuint matrixID = glGetUniformLocation(oShader.ID, "scale");

	glUniformMatrix4fv(matrixID, 1, GL_FALSE, &Matrix.matrix[0][0]);
}