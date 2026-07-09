#include <cstring>
#include <cstdio>
#include <cmath>

int n, m;
int a[1025];
int b[1025];
int c[1025][1025];
int s[1025];

int main() {
	FILE * in = fopen("cmlsc.in", "rt");
	FILE * out = fopen("cmlsc.out", "wt");

	fscanf(in, "%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		fscanf(in, "%d", (a + 1) + i);
	}
	for (int i = 0; i < n; ++i) {
		fscanf(in, "%d", (b + 1) + i);
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (a[i] == b[j]) {
				c[i][j] = c[i - 1][j - 1] + 1;
			} else {
				c[i][j] = c[i - 1][j] > c[i][j - 1] ? c[i - 1][j] : c[i][j - 1];
			}
		}
	}

	int i = n;
	int j = m;
	int k = c[n][m];
	while (k) {
		if (c[i - 1][j] < c[i][j - 1]) {
			--j;
		} else if (c[i - 1][j] == k) {
			--i;
		} else {
			s[--k] = a[i];
			--i;
			--j;
		}
	}

	k = c[n][m];
	fprintf(out, "%d\n", k);
	for (int i = 0; i < k; ++i) {
		fprintf(out, "%d ", s[i]);
	}

	fclose(in);
	fclose(out);
}
