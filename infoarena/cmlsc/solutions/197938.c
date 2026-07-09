#include <stdio.h>
#define nmax 1024

char c[nmax+1][nmax+1];

char max (char a, char b)
{
	if (a>b)
		return a;
	return b;
}

int main()
{
	int m,n, i, j;
	char a[nmax], b[nmax], sol[nmax];
	freopen ("cmlsc.in", "r", stdin);
	freopen ("cmlsc.out", "w", stdout);
	
	scanf ("%d%d", &m, &n);
	
	for (i=0; i<m; ++i)
		scanf ("%d", &a[i]);
	for (i=0; i<n; ++i)
		scanf ("%d", &b[i]);
	fclose(stdin);
	
	for (i=1; i<=m; ++i)
		for (j=1; j<=n; ++j)
			if (a[i-1]==b[j-1])
				c[i][j]=c[i-1][j-1]+1;
			else
				c[i][j]=max (c[i-1][j], c[i][j-1]);
	
	int max=0;		
	i=m, j=n;
	while (j)
	{
		if (a[i-1]==b[j-1])
		{
			sol[max++]=a[i-1];
			i--; j--;
		}
		else
			if (c[i-1][j]>c[i][j-1]) i--;
			else j--;
	}
	
	printf ("%d\n", max);
	while (max)
		printf ("%d ", sol[--max]) ;
	fclose(stdout);
	return 0;
}
