#ifndef SHADER_H
#define SHADER_H
#include "LoadFile.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

typedef struct Shader {
	unsigned int Vertex;
	unsigned int Fragment;
	unsigned int ID;
	//path del vertex shader y fragment shader
	char* VertexName;
	char* FragmentName;
}Shader;
//inicializar el shader
void initShader(Shader *oShader);
//copilar vertex y fragment shader
void CopileShader(Shader* oShader);
//link shader program con vertex y fragment 
void CreateShader(Shader* oShader);
//usar el shader para dibujar lo siguiente
void UseShader(Shader oShader);
//agregar matrices como unform para el shader
void AddMat4PR(Shader oShader, Mat4 Matrix);
void AddMat4TR(Shader oShader, Mat4 Matrix);
void AddMat4SC(Shader oShader, Mat4 Matrix);
#endif // !SHADER_H
