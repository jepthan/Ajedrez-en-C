#include "Vec.h"
#include <math.h>
#define ToRadian(x) (float)(x*(1.14f/180))
#define ToDegrees(x) (float)(x*(180/1.14))

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
Mat4 ScaleMat(float uniform) {

	Mat4 Tranformation;

	Tranformation.matrix[0][0] = uniform;
	Tranformation.matrix[1][0] = 0.0;
	Tranformation.matrix[2][0] = 0.0;
	Tranformation.matrix[3][0] = 0.0;

	Tranformation.matrix[0][1] = 0.0;
	Tranformation.matrix[1][1] = uniform;
	Tranformation.matrix[2][1] = 0.0;
	Tranformation.matrix[3][1] = 0.0;

	Tranformation.matrix[0][2] = 0.0;
	Tranformation.matrix[1][2] = 0.0;
	Tranformation.matrix[2][2] = 1.0;
	Tranformation.matrix[3][2] = 0.0;

	Tranformation.matrix[0][3] = 0.0;
	Tranformation.matrix[1][3] = 0.0;
	Tranformation.matrix[2][3] = 0.0;
	Tranformation.matrix[3][3] = 1.0;

	return Tranformation;

}
Mat4 OrthoMatrix(Ventana oVentana) {

	int width;
	int height;

	glfwGetWindowSize(oVentana.window, &width, &height);

	float FOV = 90.0f;
	float tanHalfFOV = tanf(ToRadian(FOV));
	float d = 1 / tanHalfFOV;
	float aspectRatio = (float)width / (float)height;//so it works when you resize window
	float NearZ = 0.1f;
	float FarZ = 10.0f;
	float ZRange = NearZ - FarZ;
	float A = (-FarZ - NearZ) / ZRange;
	float B = 2.0f * FarZ * NearZ / ZRange;

	Mat4 Tranformation;

	Tranformation.matrix[0][0] = d / aspectRatio;
	Tranformation.matrix[1][0] = 0.0;
	Tranformation.matrix[2][0] = 0.0;
	Tranformation.matrix[3][0] = 0.0;

	Tranformation.matrix[0][1] = 0.0;
	Tranformation.matrix[1][1] = d;
	Tranformation.matrix[2][1] = 0.0;
	Tranformation.matrix[3][1] = 0.0;

	Tranformation.matrix[0][2] = 0.0;
	Tranformation.matrix[1][2] = 0.0;
	Tranformation.matrix[2][2] = A;
	Tranformation.matrix[3][2] = B;

	Tranformation.matrix[0][3] = 0.0;
	Tranformation.matrix[1][3] = 0.0;
	Tranformation.matrix[2][3] = 0.0;
	Tranformation.matrix[3][3] = 1.0;

	return Tranformation;
}