#include <stdio.h>

#define CAP 1024

inline int max(int a, int b)
{
	return a > b ? a : b;
}

int n, m;

void backtrack(int (*c)[CAP], int* a, int* b, int i, int j, FILE* out)
{
	if (i == n + 1 || j == m + 1) {
		fprintf(out, "\n");
	} else if (a[i - 1] == b[j - 1]) {
		fprintf(out, "%d ", a[i - 1]);
		backtrack(c, a, b, i + 1, j + 1, out);
	} else if (c[i][j + 1] > c[i + 1][j]) {
		backtrack(c, a, b, i, j + 1, out);
	} else {
		backtrack(c, a, b, i + 1, j, out);
	}
}

int main(void)
{
	FILE *in = fopen("cmlsc.in", "r");
	FILE *out = fopen("cmlsc.out", "w");

	int i, a[CAP], b[CAP], j;
	static int c[CAP][CAP];
	fscanf(in, "%d%d", &n, &m);

	for (i = 0; i < n; ++i) {
		fscanf(in, "%d", &a[i]);
	}

	for (i = 0; i < m; ++i) {
		fscanf(in, "%d", &b[i]);
	}

	for (i = 1; i < n + 1; ++i) {
		for (j = 1; j < m + 1; ++j) {
			if (a[i - 1] == b[j - 1]) {
				c[i][j] = c[i - 1][j - 1] + 1;
			} else {
				c[i][j] = max(c[i][j - 1], c[i - 1][j]);
			}
		}
	}

	fprintf(out, "%d\n", c[n][m]);
	backtrack(c, a, b, 1, 1, out);

	fclose(in);
	fclose(out);
	return 0;
}