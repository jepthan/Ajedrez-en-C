#ifndef _Vec_H
#define _Vec_H
typedef struct Vec2 {
	float x;
	float y;
	
}Vec2;

typedef struct Vec3 {
	float x;
	float y;
	float z;
}Vec3;


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