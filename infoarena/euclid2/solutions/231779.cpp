#include <stdio.h>

FILE *fi = fopen("euclid2.in", "r");
FILE *fo = fopen("euclid2.out", "w");

unsigned long A, B, T;

unsigned long cmmdc(unsigned long A, unsigned long B) {
	unsigned long C;

	while (B) {
		C = A%B;
		A = B;
		B = C;		
	}

	return A;
}

int main() {
	fscanf(fi, "%lu", &T);

	for (int i=0; i<T; i++) {
		fscanf(fi, "%lu %lu", &A, &B);
		fprintf(fo, "%lu\n", cmmdc(A, B));
	}

	fclose(fi);
	fclose(fo);

	return 0;
}