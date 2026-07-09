#include <stdio.h>

unsigned gcd(unsigned a, unsigned b) {
	unsigned r = a % b;
	while(r) {
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}

int main() {
	FILE *fin = fopen("euclid2.in", "r");
	if(!fin) {
		return 1;
	}

	FILE *fout = fopen("euclid2.out", "w");
	if(!fout) {
		fclose(fin);
		return 2;
	}

	unsigned n, a, b, i;
	fscanf(fin, "%d", &n);
	for(i=0; i<n; i++) {
		fscanf(fin, "%d %d", &a, &b);
		fprintf(fout, "%d\n", gcd(a, b));
	}

	fclose(fin);
	fclose(fout);

	return 0;
}
