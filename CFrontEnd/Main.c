
#include <stdio.h>

#include "LoadFile.h"

int main() {

	File Archivo;
	Archivo.filename = "hola.txt";
	//HacerArchivo(&Archivo);
	LoadMovements(&Archivo);
	return 0;
}