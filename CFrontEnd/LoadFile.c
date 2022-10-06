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

int LoadMovements(File *Archivo, Vec2 Movimientos[64]) {
	
	int location = 0;
	if (leerArchivo(Archivo)) {
		int i = 0;
		int j = 0;
		while (location != EOF && i<64) {
			if (j % 2 == 0) {
				location = fscanf_s(Archivo->Archivo, "%f", &Movimientos[i].x);
			}
			else {
				location = fscanf_s(Archivo->Archivo, "%f", &Movimientos[i].y);
				printf("%f , %f\n", Movimientos[i].x, Movimientos[i].y);
				i++;
			}
			j++;
		}
		
	}
	return 1;
}