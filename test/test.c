#include <stdio.h>

#include <ccVector/ccVector.h>

#define PI 3.141592f

CCV_DEFINE_VEC(2)
CCV_DEFINE_MAT(2)

int main(int argc, char **argv) {
	ccvVec2 vec0, vec1;
	ccvMat2 mat0, mat1, mat2;

	float r = PI/4;

	ccvVec2Zero(vec0);

	CCV_VEC_SET(vec0, 0, 1);
	CCV_VEC_SET(vec0, 1, 0);

	printf("%f\t%f\n", CCV_VEC_GET(vec0, 0), CCV_VEC_GET(vec0, 1));
	printf("Length: %f\n", ccvVec2Length(vec0));

	ccvVec2Normalize(vec0);
	
	printf("%f\t%f\n", CCV_VEC_GET(vec0, 0), CCV_VEC_GET(vec0, 1));
	printf("Length: %f\n", ccvVec2Length(vec0));

	CCV_MAT_SET(mat1, 0, 0, cosf(r));
	CCV_MAT_SET(mat1, 1, 0, -sinf(r));
	CCV_MAT_SET(mat1, 0, 1, sinf(r));
	CCV_MAT_SET(mat1, 1, 1, cosf(r));

	ccvMat2Identity(mat2);
	ccvMat2MultiplyScalar(mat2, 3.f);
	ccvMat2MultiplyMatrix(mat0, mat1, mat2);

	printf("\n");
	for(int col = 0; col < 2; col++) {
		for(int row = 0; row < 2; row++) {
			printf("%f\t", CCV_MAT_GET(mat0, row, col));
		}
		printf("\n");
	}
	printf("\n");

	ccvMat2MultiplyVector(vec1, mat0, vec0);

	printf("%f\t%f\n", CCV_VEC_GET(vec1, 0), CCV_VEC_GET(vec1, 1));
	printf("Length: %f\n", ccvVec2Length(vec1));

	getchar();

	return 0;
}