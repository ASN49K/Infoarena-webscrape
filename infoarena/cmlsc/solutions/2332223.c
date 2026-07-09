#include <stdio.h>
#include <stdlib.h>

int max_of(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

int lcs(int *a, int *b, int m, int n, int *v) {
	if (m < 0 || n < 0) {
		return 0;
	}
	if (a[m] == b[n]) {
		int ct = 1 + lcs(a, b, m - 1, n - 1, v);
		v = realloc(v, ct * sizeof(int));
		if (v == NULL) {
			printf("Eroare realocare\n");
			return -3;
		}
		v[ct] = a[m];
		return ct;
	} else {
		return max_of(lcs(a, b, m - 1, n, v), lcs(a, b, m, n - 1, v));
	}
	return 0;
}

int main() {
	FILE *in, *out;
	if (((in = fopen("cmlsc.in", "rt")) == NULL)) {
		printf("Nu am putut deschide fisierul de input!");
		return -1;
	}
	if (((out = fopen("cmlsc.out", "wt")) == NULL)) {
		printf("Nu am putut deschide fisierul de output!");
		return -2;
	}
	int m, n, *a, *b, *v;
	fscanf(in, "%d %d", &m, &n);
	a = malloc(m * sizeof(int));
	if (a == NULL) {
		printf("Nu am putut adresa memorie\n");
		return -1;
	}
	b = malloc(n * sizeof(int));
	if (b == NULL) {
		printf("Nu am putut adresa memorie\n");
		return -2;
	}
	// Citire
	for (int i = 0 ; i < m ; ++i) {
		fscanf(in, "%d", &a[i]);
	}
	for (int i = 0 ; i < n ; ++i) {
		fscanf(in, "%d", &b[i]);
	}
	v = malloc(sizeof(int));
	int total = lcs(a, b, m - 1, n - 1, v);
	fprintf(out, "%d\n", total);
	for (int i = 1 ; i <= total ; ++i) {
		fprintf(out, "%d ", v[i]);
	}
	// Freeing the memory
	free(a);
	free(b);
	free(v);
	fclose(in);
	fclose(out);
	return 0;
}
