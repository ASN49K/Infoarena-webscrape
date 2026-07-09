#include <stdio.h>

const char* INPUT_FILE_NAME  = "euclid2.in";
const char* OUTPUT_FILE_NAME = "euclid2.out";

int cmmdc(int a, int b) {
	while (a != b) {
		if (a > b) {
			a -= b;
		}
		else {
			b -= a;
		}
	}

	return a;
}

int main()
{
	FILE *input = fopen(INPUT_FILE_NAME, "r");
	FILE *output = fopen(OUTPUT_FILE_NAME, "w");

	int T;
	fscanf(input, "%d", &T);

	for (int i = 0; i < T; i++) {
		int a, b;
		fscanf(input, "%d", &a);
		fscanf(input, "%d", &b);

		fprintf(output, "%d\n", cmmdc(a, b));
	}

	return 0;
}