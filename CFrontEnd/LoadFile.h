#pragma once
#include <stdio.h>
#include "Vec.h"

typedef struct File
{
	const char* filename;
	FILE* Archivo;
}File;
int leerArchivo(File* Archivo);
int HacerArchivo(File* Archivo);
int LoadMovements(File* Archivo);