#include <stdio.h>

#include <ccVector/ccVector.h>

CCV_DEFINE_VEC(float, 2)
CCV_DEFINE_MAT(float, 2, 2)

int main(int argc, char **argv) {
	ccvVec2 vec0;
	ccvMat2x2 mat0;

	ccvVec2Zero(vec0);

	CCV_VEC_SET(vec0, 0, 0.3f);
	CCV_VEC_SET(vec0, 1, 0.5f);

	printf("%f\t%f\n", CCV_VEC_GET(vec0, 0), CCV_VEC_GET(vec0, 1));
	printf("Length: %f\n", ccvVec2Length(vec0));

	ccvVec2Normalize(vec0);
	
	printf("%f\t%f\n", CCV_VEC_GET(vec0, 0), CCV_VEC_GET(vec0, 1));
	printf("Length: %f\n", ccvVec2Length(vec0));

	ccvMat2x2Identity(mat0);
	ccvMat2x2MultiplyScalar(mat0, 3.f);

	for(int col = 0; col < 2; col++) {
		for(int row = 0; row < 2; row++) {
			printf("%f\t", CCV_MAT_GET(mat0, row, col));
		}
		printf("\n");
	}

	getchar();

	return 0;
}