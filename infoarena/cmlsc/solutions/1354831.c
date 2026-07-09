#include <stdio.h>

#define CAP 1024

inline int max(int a, int b)
{
	return a > b ? a : b;
}

FILE *out;
int n, m;

void backtrack(int (*c)[CAP], int* a, int* b, int i, int j)
{
	if (i == 0 || j == 0) {
		return;
	} else if (a[i - 1] == b[j - 1]) {
		backtrack(c, a, b, i - 1, j - 1);
		fprintf(out, "%d ", a[i - 1]);
	} else if (c[i][j - 1] > c[i - 1][j]) {
		backtrack(c, a, b, i, j - 1);
	} else {
		backtrack(c, a, b, i - 1, j);
	}
}

int main(void)
{
	FILE *in = fopen("cmlsc.in", "r");
	out = fopen("cmlsc.out", "w");

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
	backtrack(c, a, b, n, m);

	fclose(in);
	fclose(out);
	return 0;
}