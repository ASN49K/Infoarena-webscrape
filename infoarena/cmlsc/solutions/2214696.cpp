#include <cstdio>
#include <algorithm>

using namespace std;

#define NMAX 1025

int main () {
	int x[NMAX], y[NMAX], lcs[NMAX][NMAX], res[NMAX];
	int n, m;

	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);

	scanf("%d", &n);
	scanf("%d", &m);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &x[i]);
	}

	for (int i = 1; i <= m; i++) {
		scanf("%d", &y[i]);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (x[i] == y[j]) {
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			} else {
				lcs[i][j] = max(lcs[i][j - 1], lcs[i - 1][j]);
			}
		}
	}
	
	printf("%d\n", lcs[n][m]);

	int i = n, j = m;
	int size = NMAX - 1;

	while (i > 0 && j > 0) {
		if (lcs[i][j - 1] == lcs[i][j]) {
			j--;
		} else if (lcs[i - 1][j] == lcs[i][j]) {
			i--;
		} else {
			res[size] = x[i];
			i--;
			j--;
			size--;
		}
	}

	for (i = size + 1; i < NMAX; i++) {
		printf("%d ", res[i]);
	}

	printf("\n");

	return 0;
}