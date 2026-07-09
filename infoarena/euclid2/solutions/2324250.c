#include <stdio.h>

void citire_scriere(FILE *in, FILE *out);
int gcd(int a, int b);

int main() {
	FILE *in = fopen("euclid2.in", "rt");
	if (in == NULL) {
		printf("Couldn`t open input file!\n");
		return -1;
	}
	FILE *out = fopen("euclid2.out", "wt");
	if (out == NULL) {
		printf("Couldn`t open output file!\n");
		return -2;
	}
	citire_scriere(in, out);
	fclose(in);
	fclose(out);
}

void citire_scriere(FILE *in, FILE *out) {
	int n, a, b, div;
	fscanf(in, "%d", &n);
	for (int i = 0 ; i < n ; ++i) {
		fscanf(in, "%d %d", &a, &b);
		div = gcd(a, b);
		fprintf(out, "%d\n", div);
	}
}

int gcd(int a, int b) {
	// Make a bigger
	int tmp;
	if (b > a) {
		tmp = a;
		a = b; 
		b = tmp;
	}
	if (a == 1 || b == 1) {
		return 1;
	}
	if (a == 0) {
		return b;
	}
	if (b == 0) {
		return a;
	}
	int rest = a - (a / b) * b;
	return gcd(b, rest);
}