// Algoritmul lui Euclid
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmmdc(int a, int b) {
	int r;
	while (b != 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

void euclid() {
	FILE *file_in, *file_out;
	int nr, i;
	int x, y;

	file_in = fopen("euclid2.in", "r");
	file_out = fopen("euclid2.out", "w");
	fscanf(file_in, "%d", &nr);
	for (i = 0; i < nr; i++) {
		fscanf(file_in, "%d%d", &x, &y);
		fprintf(file_out, "%d\n", cmmdc(x, y));
	}
	fclose(file_in);
	fclose(file_out);
}

int main(void) {
	euclid ();
	return 0;
}