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
	int n, a, b, i, *vect;

	fin = fopen("euclid2.in", "rt");
	fscanf(fin, "%i", &n);
	vect = (int*)malloc(n*sizeof(int));
	for(i = 0; i < n; i++) {
		fscanf(fin, "%i %i", &a, &b);
		vect[i++] = cmmdc(a, b);
	}
	fclose(fin);
	
	fout = fopen("euclid2.out", "wt");
	for(i = 0; i < n; i++) {
		fprintf(fout, "%i\n", vect[i]);
	}
	fclose(fout);
	free(vect);
	return 0;
}
