#include <stdio.h>

#include <ccVector/ccVector.h>

CCV_DEFINE_VEC(2)
CCV_DEFINE_MAT(3, 2)

int main(int argc, char **argv) {
	ccvVec2 vec0;
	ccvMat3x2 mat0;

	ccvVec2Zero(vec0);

	CCV_SET(vec0, 0, 0.5f);
	CCV_SET(vec0, 1, 0.5f);

	printf("%f\t%f\n", CCV_GET(vec0, 0), CCV_GET(vec0, 1));
	printf("Length: %f\n", ccvVec2Length(vec0));

	ccvVec2Normalize(vec0);
	
	printf("%f\t%f\n", CCV_GET(vec0, 0), CCV_GET(vec0, 1));
	printf("Length: %f\n", ccvVec2Length(vec0));

	getchar();

	return 0;
}