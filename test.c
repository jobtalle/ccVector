#include <stdio.h>

#include "ccVector.h"

CCV_DEFINE_VEC(6);

#define PI 3.141592f

static void printVec3(vec3 v) {
	unsigned int i;

	for(i = 0; i < 3; i++) {
		printf("%.2f\n", v.v[i]);
	}
	printf("\n");
}

static void printMat3x3(mat3x3 m) {
	unsigned int c, r;

	for(c = 0; c < 3; c++) {
		for(r = 0; r < 3; r++) {
			printf("%.2f\t", m[r][c]);
		}
		printf("\n");
	}
	printf("\n");
}

int main(int argc, char **argv) {
	vec3 vector, vectorMultiplied;
	vec2 add;
	mat3x3 transform;

	vector.x = 3;
	vector.y = 0;
	vector.z = 1;

	add.x = 1000;
	add.y = 1000;

	printVec3(vector);

	vectorMultiplied = vector;
	mat3x3Identity(transform);
	mat3x3Rotate2D(transform, PI / 4);
	mat3x3Scale2D(transform, 2);
	mat3x3Translate(transform, add);

	printMat3x3(transform);

	printVec3(mat3x3GetCol(transform, 1));

	printf("Applying transformation matrix...\n\n");

	vectorMultiplied = mat3x3MultiplyVector(transform, vector);

	printVec3(vectorMultiplied);

	printf("Length: %.2f\n", vec2Length(vector.vec2));

	return 0;
}