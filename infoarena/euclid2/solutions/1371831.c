#include <stdio.h>

inline int gcd (int firstNo, int secondNo) {
	if (!secondNo) return firstNo;
	return gcd (secondNo, firstNo % secondNo);
}

int main () {

	int noOfTests, firstNo, secondNo, test, greatestCommonDivisor;

	FILE* fdin = fopen("euclid2.in", "r");
	FILE* fdout = fopen("euclid2.out", "w");

	fscanf(fdin, "%d", &noOfTests);

	for (test = 1; test <= noOfTests; test++) {
		fscanf(fdin, "%d%d", &firstNo, &secondNo);
		greatestCommonDivisor = gcd (firstNo, secondNo);
		fprintf(fdout, "%d\n", greatestCommonDivisor);
	}

	return 0;
}