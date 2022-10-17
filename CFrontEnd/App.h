#ifndef APP_H
#define APP_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include "Ventana.h"
#include "Casilla.h"
#include "Caballo.h"
//variables globales
Ventana app;

Shader oShader;

Shader oShader_Caballo;

Caballo oCaballo;

Casilla oCasilla[64];

int movimientos[64];

// tiempos tiempos para retrazos y delta time
double Time1 = 0;
double Time2 = 0;
double deltaTime = 0;

int current = 0;

void StartApp();

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

#endif // !APP_H
