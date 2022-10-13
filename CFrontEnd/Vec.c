#include "Vec.h"
Mat4 TransformMatrixP3(Vec3 positon) {

	Mat4 Tranformation;

	Tranformation.matrix[0][0] = 1.0;
	Tranformation.matrix[1][0] = 0.0;
	Tranformation.matrix[2][0] = 0.0;
	Tranformation.matrix[3][0] = 0.0;

	Tranformation.matrix[0][1] = 0.0;
	Tranformation.matrix[1][1] = 1.0;
	Tranformation.matrix[2][1] = 0.0;
	Tranformation.matrix[3][1] = 0.0;

	Tranformation.matrix[0][2] = 0.0;
	Tranformation.matrix[1][2] = 0.0;
	Tranformation.matrix[2][2] = 1.0;
	Tranformation.matrix[3][2] = 0.0;

	Tranformation.matrix[0][3] = positon.x;
	Tranformation.matrix[1][3] = positon.y;
	Tranformation.matrix[2][3] = positon.z;
	Tranformation.matrix[3][3] = 1.0;

	return Tranformation;
}

Mat4 TransformMatrixP2(Vec2 positon) {

	Mat4 Tranformation;

	Tranformation.matrix[0][0] = 1.0;
	Tranformation.matrix[1][0] = 0.0;
	Tranformation.matrix[2][0] = 0.0;
	Tranformation.matrix[3][0] = 0.0;

	Tranformation.matrix[0][1] = 0.0;
	Tranformation.matrix[1][1] = 1.0;
	Tranformation.matrix[2][1] = 0.0;
	Tranformation.matrix[3][1] = 0.0;

	Tranformation.matrix[0][2] = 0.0;
	Tranformation.matrix[1][2] = 0.0;
	Tranformation.matrix[2][2] = 1.0;
	Tranformation.matrix[3][2] = 0.0;

	Tranformation.matrix[0][3] = positon.x;
	Tranformation.matrix[1][3] = positon.y;
	Tranformation.matrix[2][3] = 0.0;
	Tranformation.matrix[3][3] = 1.0;

	return Tranformation;
}
Mat4 OrthoMatrix() {

}