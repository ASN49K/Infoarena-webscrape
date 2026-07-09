#include <stdio.h>

#define nmax 1025

int i, j, n, m, p;
int sir[nmax];
int a[nmax], b[nmax];
int c[nmax][nmax];

int max(int a, int b) { if(a > b) return a; else return b; }

int main()
{
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);

	scanf("%d%d", &n, &m);
	for(i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(i = 1; i <= m; i++) scanf("%d", &b[i]);

	for(i = 1; i <= n; i++)
		for(j = 1; j <= m; j++)
			if(a[i] == b[j]) c[i][j] = 1 + c[i - 1][j - 1];
			else c[i][j] = max(c[i - 1][j], c[i][j - 1]);

	i = n, j = m;
	while(i > 0 && j > 0)
		if(a[i] == b[j]) sir[++p] = a[i], i--, j--;
		else if(c[i - 1][j] > c[i][j - 1]) i--;
		else j--;

	printf("%d\n", c[n][m]);
	for(i = p; i >= 1; i--) printf("%d ", sir[i]); printf("\n");

	return 0;
}