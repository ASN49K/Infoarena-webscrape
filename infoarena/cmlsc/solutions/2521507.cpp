#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
int m, n, a[1024], b[1024], d[1024][1024], sir[1024], bz;
int max(int a,int b)
{
	if (a > b)
		return a;
	else
		return b;
}
int main(void)
{
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);
	int i, j;
	scanf_s("%d %d", &n, &m);
	for ( i = 1; i <= n; ++i)
		scanf_s("%d", &a[i]);
	for ( i = 1; i <= m; i++)
		scanf_s("%d", &b[i]);
	for ( i = 1; i <= n; ++i)
		for ( j = 1; j <= m; ++j)
			if (a[i] == b[j])
				d[i][j] = 1 + d[i - 1][j - 1];
			else
				d[i][j] = max(d[i - 1][j], d[i][j - 1]);
	for ( i = n, j = m; i; )
		if (a[i] == b[j])
			sir[++bz] = a[i], --i, --j;
		else if (d[i - 1][j] < d[i][j - 1])
			--j;
		else
			--i;
	printf("%d\n", bz);
	for (int i = bz; i; --i)
		printf("%d ", sir[i]);
	return 0;
}