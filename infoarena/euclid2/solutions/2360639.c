#include <stdio.h>

int gcb(int a, int b) {
	int t;
	
	while (b != 0) {
		t = b;
		b = a % b;
		a = t;
	}
	
	return a;
}

int main() {
	int i, n, a, b, d;
	
	FILE* fin = fopen("euclid2.in", "r");
	FILE* fout = fopen("euclid2.out", "w");
	
	fscanf(fin, "%d", &n);
	for (i = 0; i < n; i++) {
		fscanf(fin, "%d %d", &a, &b);
		d = gcb(a, b);
		fprintf(fout, "%d\n", d);
	}
	
	fclose(fin);
	fclose(fout);
	
	return 0;
}
