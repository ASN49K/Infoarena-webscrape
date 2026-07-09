#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int cmmdc(int a, int b) {

	int r = -1;

	do {

		r = a % b;
		a = b;
		b = r;

	} while (b != 0);

	return a;
}

int main() {
	
	FILE* ip;
	FILE* op;

	ip = fopen("euclid2.in", "r");
	if (ip == NULL) {

		perror("Error opening input file");
		return 1;
	}

	op = fopen("euclid2.out", "w");
	if (op == NULL) {

		perror("Error opening output file!");
		return 1;
	}

	int n = -1;
	int a = 0, b = 0;

	fscanf(ip, "%d", &n);
	
	for (int i = 0; i < n; i++) {

		fscanf(ip, "%d", &a);
		fscanf(ip, "%d", &b);

		fprintf(op, "%d\n", cmmdc(a, b));
	}

	return 0;
}