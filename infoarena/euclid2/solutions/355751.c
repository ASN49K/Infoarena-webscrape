#include <stdio.h>

int gcd(int a, int b) {
	if (!b) return a;
	return gcd(b, a % b);
}

int main(void) {
	FILE *fin, *fout;
	int n, a, b, c;
	
	fin = fopen("euclid2.in", "r");
	fout = fopen("euclid2.out", "w");
	
	fscanf(fin, "%d", &n);
	for (; n; --n) {
		fscanf(fin, "%d %d", &a, &b);
		c = gcd(a, b);
		fprintf(fout, "%d\n", c);
	}
	fclose(fin);
	fclose(fout);
	return 0;
}
