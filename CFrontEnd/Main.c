
#include <stdio.h>

#include "LoadFile.h"

int main() {

	File Archivo;
	Archivo.filename = "hola.txt";
	//HacerArchivo(&Archivo);
	Vec2 Movimientos[64];
	LoadMovements(&Archivo, Movimientos);
	return 0;
}