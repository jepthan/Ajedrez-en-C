#pragma once
#include <stdio.h>

typedef struct File
{
	const char* filename;
	FILE* Archivo;
}File;
int leerArchivo(File* Archivo);
int HacerArchivo(File* Archivo);