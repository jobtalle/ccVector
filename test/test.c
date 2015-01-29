#include <stdio.h>

#include <ccVector/ccVector.h>

CCV_DEFINE_VEC(1)

int main(int argc, char **argv) {
	ccvVec1 vec0, vec1, vec2;
	vec0.elements[0] = 0.1f;

	CCV_SET(vec1, 0, 0.5f);
	CCV_SET(vec2, 0, 0.2f);

	ccvVec1Multiply(&vec0, 5);

	printf("%f\n", CCV_GET(vec0, 0));

	getchar();

	return 0;
}