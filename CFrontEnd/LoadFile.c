#include "LoadFile.h"

bool leerArchivo(File* Archivo) {
	Archivo->Archivo = fopen(Archivo->filename, "r");
	if (Archivo->Archivo) {
		return true;
	}
	else {
		return false;
	}
}
bool HacerArchivo(File* Archivo) {
	Archivo->Archivo = fopen(Archivo->filename, "w");
	if (Archivo->Archivo) {
		return true;
	}
	else {
		return false;
	}
}

bool LoadMovements(File *Archivo) {

}