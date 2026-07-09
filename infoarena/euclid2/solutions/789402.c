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
	int max=1024*1024/sizeof(int), n, nt, a, b, i, *vect;

	fin = fopen("euclid2.in", "rt");
	fout = fopen("euclid2.out", "wt");

	fscanf(fin, "%i", &nt);
	n = nt <= max ? nt : max;
	vect = (int*)malloc(n*sizeof(int));

	while(nt > 0)
	{
		for(i = 0; i < n; i++) {
			fscanf(fin, "%i %i", &a, &b);
			vect[i] = cmmdc(a, b);
		}
	
		for(i = 0; i < n; i++) {
			fprintf(fout, "%i\n", vect[i]);
		}
		nt-=n;
		n = nt <= max ? nt : max;
	}

	fclose(fin);
	fclose(fout);
	free(vect);
	return 0;
}
