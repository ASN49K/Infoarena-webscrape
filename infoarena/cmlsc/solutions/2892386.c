#include <stdio.h>
#define NMAX (1 << 10)

int dp[1 + NMAX][1 + NMAX];
int a[NMAX + 1], b[NMAX + 1];

int maximum(int x, int y, int z)
{
	if (x >= y && x >= z)
		return x;

	if (y >= x && y >= z)
		return y;

	return z;
}

int reconstruct(int i, int j)
{
	if (i == 0 || j == 0 || dp[i][j] == 0)
		return -1;

	if (i >= 1 && dp[i][j] == dp[i - 1][j])
		return reconstruct(i - 1, j);

	if (j >= 1 && dp[i][j] == dp[i][j - 1])
		return reconstruct(i, j - 1);

	reconstruct(i - 1, j - 1);
	printf("%d ", a[i]);
	return -1;
}

int main()
{
	FILE *in, *out;
	in = fopen("cmlsc.in", "rt");
	out = fopen("cmlsc.out", "wt");

	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; ++i)
		scanf("%d", a + i);

	for (int j = 1; j <= m; ++j)
		scanf("%d", b + j);

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			dp[i][j] = maximum(dp[i][j - 1], dp[i - 1][j], (a[i] == b[j]) + dp[i - 1][j - 1]);

	printf("%d\n", dp[n][m]);
	reconstruct(n, m);

	fclose(in);
	fclose(out);
	return 0;
}