#include <stdio.h>

void euclid(int a, int b, FILE *fin, FILE *fout);

int main() {
	int n, i, a, b;
	FILE *fin, *fout;

	fin = fopen("euclid2.in", "r");
	fout = fopen("euclid2.out", "w");

	if (fin == NULL && fout == NULL) {
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

	int temp;
	if (a < b) {
		// interschimbare
		a ^= b;
		b ^= a;
		a ^= b;
	}
	if (b == 0) {
		fprintf(fout, "%d\n", a);
		return;
	}
	while (b) {
		temp = a % b;
		a = b;
		b = temp;
	}
	fprintf(fout, "%d\n", a);
}