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
		while (a != b) {
			if (a > b) {
				a = a - b;
			} else {
				b = b - a;
			}
		}
		fprintf(out, "%d\n", a);
	}

	fclose(in);
	fclose(out);
	return 0;
}