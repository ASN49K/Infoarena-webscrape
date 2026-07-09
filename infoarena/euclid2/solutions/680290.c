#include <stdio.h>

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

	int T, a, b, i;

	fscanf(f_in, "%d", &T);
	for (i = 0; i < T; i++) {
		fscanf(f_in, "%d %d", &a, &b);
		fprintf(f_out, "%d\n", euclid2(a, b));
	}
	
	fclose(f_in);
	fclose(f_out);
	return 0;
}
