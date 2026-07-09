#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int a, b, r;
	int T;
	FILE *file_in;
	FILE *file_out;

	file_in = fopen("euclid2.in", "r");
	file_out = fopen("euclid2.out", "w");

	fscanf(file_in, "%d", &T);

	for (int i = 0; i < T; i++) {
		fscanf(file_in, "%d%d", &a, &b);

		while (b != 0) {
			r = a % b;
			a = b;
			b = r;
		}
		fprintf(file_out, "%d\n", a);
	}

	fclose(file_in);
	fclose(file_out);
	return 0;
}