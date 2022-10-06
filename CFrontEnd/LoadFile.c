#include "LoadFile.h"

int leerArchivo(File* Archivo) {
	int error_code;
	error_code = fopen_s(&Archivo->Archivo,Archivo->filename, "r");
	if (error_code == 0 ){
		return 1;
	}
	else {
		return 0;
	}
}
int HacerArchivo(File* Archivo) {
	fopen_s(&Archivo->Archivo,Archivo->filename, "w");
	if (Archivo->Archivo) {
		return 1;
	}
	else {
		return 0;
	}
}

int LoadMovements(File *Archivo) {
	
	int location = 0;
	if (leerArchivo(Archivo)) {
		int a;
		while (location != EOF) {
			location = fscanf_s(Archivo->Archivo, "%i", &a, location);
			printf("%i\n", a);
		}
		
	}
	return 1;
}