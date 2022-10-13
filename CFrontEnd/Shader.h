#ifndef SHADER_H
#define SHADER_H
#include "LoadFile.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
typedef struct Shader {
	unsigned int Vertex;
	unsigned int Fragment;
	unsigned int ID;
	char* VertexName;
	char* FragmentName;
}Shader;

void initShader(Shader *oShader);
void CopileShader(Shader* oShader);
void CreateShader(Shader* oShader);
void UseShader(Shader oShader);
void AddMat4PR(Shader oShader, Mat4 Matrix);
void AddMat4TR(Shader oShader, Mat4 Matrix);
void AddMat4SC(Shader oShader, Mat4 Matrix);
#endif // !SHADER_H
