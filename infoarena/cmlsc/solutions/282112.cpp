#include <stdio.h>
#define dim 1200
#define max(a,b) ((a)>(b))?(a):(b)

int m, n, a[dim], b[dim], mat[dim][dim], sir[dim], k;

int main()
{
	int i, j;
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);
	scanf("%d %d\n", &m, &n);
	for (i=1; i<=m; i++) scanf("%d ", &a[i]);
	for (i=1; i<=n; i++) scanf("%d ", &b[i]);
	for (i=1; i<=m; i++)
		for (j=1; j<=n; j++)
			if (a[i]==b[j]) mat[i][j]=1+mat[i-1][j-1];
			else mat[i][j]=max(mat[i-1][j], mat[i][j-1]);
	for (i=m, j=n; i; )
		if (a[i]==b[j])
		{
			sir[++k]=a[i];
			i--;
			j--;
		}
		else if (mat[i-1][j]<mat[i][j-1]) j--;
		else i--;
	printf("%d\n", k);
	for (i=k; i; i--) printf("%d ", sir[i]);
	return 0;
}
