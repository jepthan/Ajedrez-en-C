#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "Vec.h"
#include "stb_image.h" //non standar library to load images

typedef struct File
{
	const char* filename;
	FILE* Archivo;
}File;
int leerArchivo(File* Archivo);
int HacerArchivo(File* Archivo);
int LoadMovements(File* Archivo, int *Movimientos[64]);
char *LoadShader(File* Archivo);
unsigned int loadImage(File * Archivo);
