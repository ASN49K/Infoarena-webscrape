#include <stdlib.h>
#include <stdio.h>

int cmmdc(int a, int b) {
	int aux;
	while(b != 0) {
		aux = b;
		b = a % b;
		a = aux;
	}

	return a;
}

int main() {
	FILE *fin;
	FILE *fout;
	int n, a, b;

	fin = fopen("euclid2.in", "rt");
	fout = fopen("euclid2.out", "wt");
	fscanf(fin, "%i", &n);
	while(n--) {
		fscanf(fin, "%i %i", &a, &b);
		fprintf(fout, "%i\n", cmmdc(a, b));
	}
	fclose(fin);
	fclose(fout);
}
