#include <stdio.h>

void euclid(int a, int b, FILE *fin, FILE *fout);

int main() {
	int n, i, a, b;
	FILE *fin, *fout;

	fin = fopen("euclid.in", "r");
	fout = fopen("euclid.out", "w");

	if (fin == NULL || fout == NULL) {
		printf("eroare la deschidere fisier\n");
		return 1;
	}

	fscanf(fin, "%d", &n);
	
	for (i = 0; i < n; i++) {
		fscanf(fin, "%d%d", &a, &b);
		euclid(a, b, fin, fout);
	}

	fclose(fin);
	fclose(fout);
	
	return 0;
}

void euclid(int a, int b, FILE *fin, FILE *fout) {

	if (a == 0) {
		fprintf(fout, "%d\n", b);
		return;
	}
	while (b) {
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}
	fprintf(fout, "%d\n", a);
}