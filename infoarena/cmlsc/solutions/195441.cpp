#include <stdio.h>
#include <math.h>

#define MAXN 1030

long n, m, i, a[MAXN], b[MAXN], j, ma[MAXN][MAXN], poz1, poz2, cont, v[MAXN];

long max(long num1, long num2) {
	if (num1 > num2) {
		return num1;
	}
	return num2;
}

int main() {
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);
	scanf("%ld %ld\n", &n, &m);
	for (i = 1; i <= n; ++i) {
		scanf("%ld ", &a[i]);
	}
	for (i = 1; i <= m; ++i) {
		scanf("%ld ", &b[i]);
	}
	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= m; ++j) {
			if (a[i] == b[j]) {
				ma[i][j] = ma[i - 1][j - 1] + 1;
			} else {
				ma[i][j] = max(ma[i - 1][j], ma[i][j - 1]);
			}
		}
	}
	printf("%ld\n", ma[n][m]);
	poz1 = n;
	poz2 = m;
	cont = 0;
	while (cont <= ma[n][m]) {
		if (a[poz1] == b[poz2]) {
			v[ma[n][m] - cont] = a[poz1];
			--poz1;
			--poz2;
			++cont;
		} else {
			if (max(ma[poz1 - 1][poz2], ma[poz1][poz2 - 1]) == ma[poz1 - 1][poz2]) {
				--poz1;
			} else {
				--poz2;
			}
		}
	}
	for (i = 1; i <= ma[n][m]; ++i) {
		printf("%ld ", v[i]);
	}
	printf("\n");
	return 0;
}