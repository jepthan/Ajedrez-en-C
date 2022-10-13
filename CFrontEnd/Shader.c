#include "Shader.h"

void initShader(Shader* oShader) {
	CopileShader(oShader);
	CreateShader(oShader);
}
void CopileShader(Shader* oShader) {
	int success;
	char infoLog[512];
	// vertex Shader
	File VertexF;
	VertexF.filename = oShader->VertexName;
	File FragmentF;
	FragmentF.filename = oShader->FragmentName;
	char* vShaderCode = LoadShader(&VertexF);
	char* fShaderCode = LoadShader(&FragmentF);
	oShader->Vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(oShader->Vertex, 1, &vShaderCode, NULL);
	glCompileShader(oShader->Vertex);
	// print compile errors if any
	glGetShaderiv(oShader->Vertex, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(oShader->Vertex, 512, NULL, infoLog);
		printf("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n%s\n", infoLog);
			;
	};

	//Fragment Shader
	oShader->Fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(oShader->Fragment, 1, &fShaderCode, NULL);
	glCompileShader(oShader->Fragment);
	// print compile errors if any
	glGetShaderiv(oShader->Fragment, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(oShader->Fragment, 512, NULL, infoLog);
		printf("ERROR::SHADER::FAGMENT::COMPILATION_FAILED\n%s\n", infoLog);
	};
}
void CreateShader(Shader* oShader) {
	int success;
	char infoLog[512];
	//Create Shader program and link to ID
	oShader->ID = glCreateProgram();
	//attach vertex and fragment shader to shader program
	glAttachShader(oShader->ID, oShader->Vertex);
	glAttachShader(oShader->ID, oShader->Fragment);
	//link program 
	glLinkProgram(oShader->ID);
	// print linking errors
	glGetProgramiv(oShader->ID, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(oShader->ID, 512, NULL, infoLog);
		printf("ERROR::SHADER::PROGRAM::LINKING_FAILED\n%s\n",infoLog);
	}
	// delete shaders; they’re linked into our program and no longer necessary
	glDeleteShader(oShader->Vertex);
	glDeleteShader(oShader->Fragment);
	//delete pointers
}
void UseShader(Shader oShader) {
	glUseProgram(oShader.ID);
}
void AddMat4(Shader oShader, Mat4 Matrix) {

	UseShader(oShader);
	GLuint matrixID = glGetUniformLocation(oShader.ID, "Transform");

	glUniformMatrix4fv(matrixID, 1, GL_FALSE, &Matrix.matrix[0][0]);
}