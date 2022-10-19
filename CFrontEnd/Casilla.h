#ifndef CASILLA_H
#define CASILLA_H
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Vec.h"
#include "Vertex.h"
#include "Shader.h"

typedef struct Casilla {
	unsigned int VAO;
	Vec2 Posicion;
	Vec3 Color;
	Shader oShader;

}Casilla;
void initCasilla(Casilla* oCasilla, Shader oShader);
void pintar(Casilla oCasilla, Ventana app);

#endif // !CASILLAS_H
