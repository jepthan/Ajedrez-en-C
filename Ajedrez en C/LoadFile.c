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

int LoadMovements(File *Archivo, int *Movimientos[64]) {
	//carga movimientos de un archivo de texto
	int location = 0;
	if (leerArchivo(Archivo)) {
		int i = 0;
		while (location != EOF && i<64) {
			
			location = fscanf_s(Archivo->Archivo, "%d", &Movimientos[i]);
			i++;
			
		}
		
	}
	return 1;
}
char * LoadShader(File* Archivo) {

	//charga el shader y devuelve un array de char
	
	if (leerArchivo(Archivo)) {
		char* text;
		fseek(Archivo->Archivo, 0, SEEK_END);
		int len = ftell(Archivo->Archivo);
		rewind(Archivo->Archivo);
		
		text = (char*) malloc(sizeof(char) * len + 1);

		if (text) {
			int a = fread(text, sizeof(char), len, Archivo->Archivo);
			text[a] = '\0';
			//printf("%s", text);
			return text;
		}
		
	}

	return NULL;
}
//carga la imagen del archivo y devuelve un unsignet in del id de la textura para usar en el shaders
unsigned int loadImage(File *Archivo) {

	unsigned int textureid;
	int width, height, nrChannels;
	//utiliza libreria stb_image para cargar archivo de imagen devulve la informacion de la imagen en un char y el tamaño de la misma asi commo
	//numero de canales en la imagen ej: RGB, RGBA ...
	unsigned char* data = stbi_load(Archivo->filename, &width, &height, &nrChannels, 0);

	//genera la textura y le da un id
	glGenTextures(1, &textureid);

	//pone la textura como una textura 2D
	glBindTexture(GL_TEXTURE_2D, textureid);

	//configuracion de la textura 
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	//si hay informacion en la  carga esa informacion al objeto de textura creado
	if (data) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA,
			GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

	}
	else {
		printf("Error Texture problem: loading texture");
	}


	return textureid;
}