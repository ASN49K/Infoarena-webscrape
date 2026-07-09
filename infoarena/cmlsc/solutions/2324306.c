#include <stdio.h>
#include <stdlib.h>

void cautare_subsir(int n, int *a, int m, int *b, FILE* out) {
	int *v = malloc (sizeof(int));
	int i, j, ct = 0;
	for (i = n - 1 ; i >= 0; --i) {
		for (j = m - 1 ; j >= 0 ; --j) {
			if (a[i] == b[j]) {
				v[ct] = a[i];
				ct++;
				v = realloc(v, (ct + 1) * sizeof(int));
			}
		}
	}
	// Afisare
	fprintf(out, "%d\n", ct);
	for (i = ct - 1 ; i >= 0 ; --i) {
		fprintf(out, "%d ", v[i]);
	}
	fprintf(out, "\n");
	free(v);
}

int main() {
	int n, m, *a, *b;
	FILE *in = fopen("cmlsc.in", "rt");
	if (in == NULL) {
		printf("Couldn`t open the input file.\n");
		return -1;
	}
	FILE *out = fopen("cmlsc.out", "wt");
	if (out == NULL) {
		printf("Couldn`t open the output file.\n");
		return -2;
	}

	// Citire
	(void)fscanf(in, "%d %d", &n, &m);
	a = malloc(n * sizeof(int));
	for (int i = 0 ; i < n ; i++) {
		(void)fscanf(in , "%d", &a[i]);
	}
	b = malloc(m * sizeof(int));
	for (int i = 0 ; i < m ; i++) {
		(void)fscanf(in , "%d", &b[i]);
	}
	cautare_subsir(n, a, m, b, out);
	// Elibieram memoria
	free(a);
	free(b);
	return 0;
}