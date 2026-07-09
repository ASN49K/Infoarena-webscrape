#include <stdio.h>

#define max(a, b) (a>b?a:b)
#define dim 1030

long a[dim], b[dim], c[dim][dim], k, sir[dim];
long n, m , i, j;

int main()
{
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);

	scanf("%ld %ld", &n, &m);

	for(i=1; i<=n; i++)
		scanf("%ld", a+i);

	for(i=1; i<=m; i++)
		scanf("%ld", b+i);

	for(i=1; i<=n; i++)
	{
		for(j=1; j<=m; j++)
		{
			if(a[i]==b[j])
				c[i][j]=c[i-1][j-1]+1;
			else
				c[i][j]=max(c[i-1][j], c[i][j-1]);
		}
	}
	printf("%ld\n", c[n][m]);/*
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=m; j++)
		{
			printf("%ld ", c[i][j]);
		}
		printf("\n");
	}                          */
	for(i=n, j=m; i ; )
	{
		if(a[i]==b[j]) sir[++k]=a[i], i--, j--;
		else if(c[i-1][j]<c[i][j-1]) j--;
		else i--;
	}

	for(j=k; j; j--)
		{
			printf("%ld ", sir[j]);
		}

	return 0;
}