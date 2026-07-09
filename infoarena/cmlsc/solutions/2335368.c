#include <stdio.h>
#include <stdlib.h>

int max_of(int a, int b) {
	if (a > b)
		return a;
	return b;
}

int lcs(int *A, int m, int *B, int n, FILE* out) {
	int i, j, **L;
	L = malloc((m + 1) * sizeof(int *));
	if (L == NULL) {
		printf("Nu am putut aloca memorie");
		return -3;
	}
	for (i = 0 ; i < m + 1 ; ++i) {
		L[i] = malloc((n + 1) * sizeof(int));
		if (L[i] == NULL) {
			printf("Nu am putut aloca memorie");
			return -3;
		}
	}
	for (i = 0 ; i < m + 1 ; ++i) {
		for (j = 0 ; j < n + 1 ; ++j) {
			if (i == 0 || j == 0) {
				L[i][j] = 0;
			} else if (A[i - 1] == B[j - 1]) {
				L[i][j] = L[i - 1][j - 1] + 1;
			} else {
				L[i][j] = max_of(L[i][j - 1], L[i - 1][j]);
			}
		}
	}
	fprintf(out, "%d\n", L[m][n]);
	i = m;
	j = n;
	int ct = 0;
	int *result = malloc(L[m][n] * sizeof(int));
	if (result == NULL) {
		printf("Nu am putut aloca memorie\n");
		return -3;
	}
	// For reading the sequence
	while (L[i][j] != 0) {
		if (L[i][j] > max_of(L[i - 1][j], L[i][j - 1])) {
			result[ct] = A[i - 1];
			i--;
			j--;
			ct++;
		} else if (L[i - 1][j] > L[i][j - 1]) {
			i--;
		} else {
			j--;
		}
	}
	for (i = ct - 1 ; i >= 0 ; --i) {
		fprintf(out, "%d ", result[i]);
	}
	// Freeing memory
	for (i = 0 ; i < m + 1 ; ++i) {
		free(L[i]);
	}
	free(L);
	free(result);
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
	int *A, *B, m, n;
	// Citire
	fscanf(in, "%d %d", &m, &n);
	A = malloc(m * sizeof(int));
	if (A == NULL) {
		printf("Nu am putut aloca memorie");
		return -3;
	}
	for (int i = 0 ; i < m ; ++i) {
		fscanf(in, "%d", &A[i]);
	}
	B = malloc(n * sizeof(int));
	if (B == NULL) {
		printf("Nu am putut aloca memorie");
		return -3;
	}
	for (int i = 0 ; i < n ; ++i) {
		fscanf(in, "%d", &B[i]);
	}
	lcs(A, m, B, n, out);
	// Freeing the memory
	free(A);
	free(B);
	fclose(in);
	fclose(out);
	return 0;
}
