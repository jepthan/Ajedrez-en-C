#ifndef _Vec_H
#define _Vec_H
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Ventana.h"
//Vector de 2 domensiones para posiciones en 2d y texture cordinates
typedef struct Vec2 {
	float x;
	float y;
	
}Vec2;
//Vector de 3 dimensiones para posiciones en 3d  y colores
typedef struct Vec3 {
	float x;
	float y;
	float z;
}Vec3;
// matrices de 4 *4 para matris de transformacion scale y projecton
typedef struct Mat4 {
	float matrix[4][4];
}Mat4;

Mat4 TransformMatrixP3(Vec3 positon);
Mat4 TransformMatrixP2(Vec2 positon);
Mat4 OrthoMatrix(Ventana oVentana);
Mat4 ScaleMat(float uniform);
/* dreams
Vec2() {}
Vec2(float _x, float _y) {
	x = _x;
	y = _y;
}

/*Dreams
Vec3(){}
	Vec3(float _x, float _y, float _z){
		x = _x;
		y = _y;
		z = _z;
	}
	Vec3(Vec2 pos, float _z){
		x = pos.x;
		y = pos.y;
		z = _z;
	}
*/
/*Sad dreams
typedef struct Position{
	Vec3 pos;
}
Position(){}
	Position(float x, float y, float z) {

}
*/
#endif