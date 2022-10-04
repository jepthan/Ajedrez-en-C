#pragma once
#include <stdio.h>

typedef struct File
{
	const char* filename;
	FILE* Archivo;
};
bool leerArchivo(File* Archivo);
bool HacerArchivo(File* Archivo);