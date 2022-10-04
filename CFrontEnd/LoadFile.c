#include "LoadFile.h"

int leerArchivo(File* Archivo) {
	Archivo->Archivo = fopen(Archivo->filename, "r");
	if (Archivo->Archivo) {
		return 1;
	}
	else {
		return 0;
	}
}
int HacerArchivo(File* Archivo) {
	Archivo->Archivo = fopen(Archivo->filename, "w");
	if (Archivo->Archivo) {
		return 1;
	}
	else {
		return 0;
	}
}

int LoadMovements(File *Archivo) {

}