#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "Vec.h"

typedef struct File
{
	const char* filename;
	FILE* Archivo;
}File;
int leerArchivo(File* Archivo);
int HacerArchivo(File* Archivo);
int LoadMovements(File* Archivo, Vec2 Movimientos[64]);
char *LoadShader(File* Archivo);