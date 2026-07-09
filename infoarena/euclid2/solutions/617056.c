#include <stdio.h>

int cmmdc(int a, int b) {
	int c = a % b;

	while (c) {
		a = b;
		b = c;
		c = a % b;
	}

	return b;
}

int main() {

	FILE *in = fopen("euclid2.in", "r");
	FILE *out = fopen("euclid.out", "w");
	int n, a, b, i;

	fscanf(in, "%d", &n);

	for (i = 0; i < n; i++) {
		fscanf(in, "%d %d", &a, &b);
		fprintf(out, "%d\n", cmmdc(a, b));
	}
	
	fclose(in);
	fclose(out);

	return 0;
}
	
