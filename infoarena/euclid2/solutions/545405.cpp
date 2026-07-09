#include <stdio.h>

int main() {
	long a, b, n, i, c;
	FILE* fin;
	FILE* fout;
	fin = fopen("euclid2.in", "r");
	fout = fopen("euclid2.out", "w");
	fscanf(fin, "%d\n", &n);
	for (i=0; i<n; i++) {
		fscanf(fin, "%d %d\n", &a, &b);
		while (b != 0) {
			c = b;
			b = a % b;
			a = c;
		}
		fprintf(fout, "%d\n", a);
	}
	fclose(fin);
	fclose(fout);
	return 0;	
}
