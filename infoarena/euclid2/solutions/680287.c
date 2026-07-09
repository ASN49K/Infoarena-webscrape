#include <stdio.h>
#include <stdlib.h>

int euclid2 (int a, int b) {
	int r;
	while (b != 0) {
		r = b;
		b = a % b;
		a = r;
	}
	return a;
}

int main () {
	FILE *f_in = fopen("euclid2.in", "r");
	FILE *f_out = fopen("euclid2.out", "w");

	int T;
	int a, b;
	int i;
	int div;

	fscanf(f_in, "%d", &T);
	for (i = 0; i < T; i++) {
		fscanf(f_in, "%d", &a);
		fscanf(f_in, "%d", &b);
		div = euclid2(a, b);
		fprintf(f_out, "%d\n", div);
	}	
	
	return 0;
}
