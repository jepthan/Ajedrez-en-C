#ifndef CABALLO_H
#define CABALLO_H
#include "Shader.h"
#include "Vertex.h"
typedef struct Caballo {
	unsigned int VAO;
	unsigned int Texture;
	Vec2 Posicion;
	Shader oShader;
}Caballo;
void initCaballo(Caballo* oCaballo, Shader oShader);
void pintarCaballo(Caballo oCaballo, Ventana app);

#endif // !CABALLO_H