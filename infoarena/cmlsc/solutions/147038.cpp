#include<stdio.h>

short int a[1025], b[1025], v[1025][200], sol[1025];

int max(int a, int b)
{
	if (a>=b) return a;
	return b;
}

int main()
{
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);
	
	int i, j, m, n;
	scanf("%d %d", &n, &m);
	for (i=1; i<=n; i++)
		scanf("%d", &a[i]);
	for (i=1; i<=m; i++)
		scanf("%d", &b[i]);
	
	for (i=1; i<=m; i++)
		for (j=1; j<=n; j++)
		{
			if (a[j]==b[i])
			{
				v[i][j]=v[i-1][j-1]+1;
			}
			else
			{
				v[i][j]=max(v[i][j-1], v[i-1][j]);
			}
		}
		
	printf("%d\n", v[m][n]);
	int x=m, y=n;
	for (i=1; i<=v[m][n]; i++)
	{
		while(a[y]!=b[x])
		{
			
			if (v[x][y]==v[x][y-1])
			{
				y--;
				continue;
			}
			if (v[x][y]==v[x-1][y])
			{
				x--;
				continue;
			}
		}
		sol[i]=a[y];
		x--;
		y--;
			
	}
//	for (i=1; i<=m; i++)
//	{
//		for (j=1; j<=n; j++)
//			printf("%d ", v[i][j]);
//		printf("\n");
//	}
	for (i=v[m][n]; i>=1; i--)
	{
		printf("%d ", sol[i]);
	}
	fclose(stdout);
	return 0;
}
