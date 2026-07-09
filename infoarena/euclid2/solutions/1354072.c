#include <stdio.h>

int main(void)
{
	FILE *in = fopen("euclid2.in", "r");
	FILE *out = fopen("euclid2.out", "w");

	int t, i;
	fscanf(in, "%d", &t);
	for (i = 0; i < t; ++i) {
		int a, b;
		fscanf(in, "%d%d", &a, &b);
		while (b != 0) {
			int aux = b;
			b = a % b;
			a = aux;
		}
		fprintf(out, "%d\n", a);
	}

	fclose(in);
	fclose(out);
	return 0;
}