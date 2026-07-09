#include <stdio.h>

#define nm 1030

int n, m, a[nm], b[nm], c[nm][nm];

int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

int main()
{
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);

	scanf("%d%d", &n, &m);

	for (int i = n; i; --i)
		scanf("%d", &a[i]);

	for (int j = m; j; --j)
		scanf("%d", &b[j]);

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			c[i][j] = max(c[i - 1][j], c[i][j - 1]);

			if (a[i] == b[j])
				c[i][j] = max(c[i][j], c[i - 1][j - 1] + 1);
		}

	printf("%d\n", c[n][m]);

	int crt = c[n][m], x = n, y = m;

	while (crt) {
		if (c[x - 1][y] == crt)
			--x;
		else if (c[x][y - 1] == crt)
			--y;
		else {
			printf("%d ", a[x]);
			--x, --y, --crt;
		}
	}

	printf("\n");

	return 0;
}
