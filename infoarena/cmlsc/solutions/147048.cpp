#include<stdio.h>

int a[1025], b[1025], v[1025][1025], sol[1025];

int max(int a, int b)
{
	if (a>=b) return a;
	return b;
}

int main()
{
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);
	
	int i, j, m, n, s;
	scanf("%d %d", &n, &m);
	for (i=1; i<=n; i++)
		scanf("%d", &a[i]);
	for (i=1; i<=m; i++)
		scanf("%d", &b[i]);
	
	for (i=1; i<=m; i++)
		for (j=1; j<=n; j++)
		{
			if (a[j]==b[i])
				v[i][j]=v[i-1][j-1]+1;
			else
				v[i][j]=max(v[i][j-1], v[i-1][j]);
		}
	s=v[m][n];
	printf("%d\n", s);
	int x=m, y=n;
	
	for (i=1; i<=s; i++)
	{
		while(a[y]!=b[x])
		{
			
			if (v[x][y]==v[x][y-1])
				y--;
			if (v[x][y]==v[x-1][y])
				x--;
		}
		sol[i]=a[y];
		x--;
		y--;
	}
	for (i=s; i>=1; i--)
	{
		printf("%d ", sol[i]);
	}
	fclose(stdout);
	return 0;
}
