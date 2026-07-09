#include <stdio.h>

int n, m, c[1030][1030], a[1030], b[1030], sol[1000], nr, maxim;

int max(int x, int y) {return x > y ? x : y;}

int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	int i, j;
	scanf("%d %d",&n,&m);
	for (i = 1; i <= n; i++) scanf("%d",a + i);
	for (i = 1; i <= m; i++) scanf("%d",b + i);

	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			if (a[i] == b[j]) c[i][j] = c[i-1][j-1] + 1;
			else c[i][j] = max(c[i-1][j], c[i][j-1]);

	maxim = c[n][m];

	for (i = n; i >= 1; i--)
		for (j = m; j >= 1; j--)
			if (c[i][j] == maxim && (c[i][j-1] != maxim && c[i-1][j] != maxim)) sol[++nr] = a[i], maxim--;

	printf("%d\n",c[n][m]);
	for (i = nr; i >= 1; i--) printf("%d ",sol[i]);
	return 0;
}


		


