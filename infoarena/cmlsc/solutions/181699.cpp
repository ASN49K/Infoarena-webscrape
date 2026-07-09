#ifdef WIN32
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

int a[1025], b[1025], d[1025][1025];


int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}


void solutie(int x, int y)
{
	if (x == 0 || y == 0)
		return;

	if (a[x] == b[y])
	{
		solutie(x - 1, y - 1);
		printf("%d ", a[x]);
	}
	else
		if (d[x][y - 1] > d[x - 1][y])
			solutie(x, y - 1);
		else
			solutie(x - 1, y);
}


int main()
{
	freopen("cmlsc.in", "rt", stdin);
	freopen("cmlsc.out", "wt", stdout);

	int m, n, i, j;
	scanf("%d%d", &m, &n);
	for (i = 1; i <= m; i++) scanf("%d", &a[i]);
	for (i = 1; i <= n; i++) scanf("%d", &b[i]);

	for (i = 1; i <= m; i++)
		for (j = 1; j <= n; j++)
			if (a[i] == b[j])
				d[i][j] = d[i - 1][j - 1] + 1;
			else
				d[i][j] = max(d[i - 1][j], d[i][j - 1]);

	printf("%d\n", d[m][n]);
	solutie(m, n);
	printf("\n");

	return 0;
}
