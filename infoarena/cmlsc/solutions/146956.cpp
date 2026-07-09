#include<stdio.h>

int a[1025], b[1025], v[1025][200], last[1025][2];

int max(int a, int b, int c)
{
	if ((a>=b) && (a>=c)) return a;
	if ((b>=a) && (b>=c)) return b;
	if ((c>=a) && (c>=b)) return c;
	return 0;
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
	
	for (j=1; j<=m; j++)
		for (i=1; i<=n; i++)
		{
			if (a[i]==b[j])
			{
				v[i][j%2]=max(v[i-1][(j+1)%2]+1, v[i][(j+1)%2], v[i-1][j%2]);
				if (max(v[i-1][(j+1)%2]+1, v[i][(j+1)%2], v[i-1][j%2])==v[i-1][(j+1)%2]+1)
					last[i][j%2]=j;
				if (max(v[i-1][(j+1)%2]+1, v[i][(j+1)%2], v[i-1][j%2])==v[i][(j+1)%2])
					last[i][j%2]=last[i][(j+1)%2];
				if (max(v[i-1][(j+1)%2]+1, v[i][(j+1)%2], v[i-1][j%2])==v[i-1][j%2])
					last[i][j%2]=last[i-1][j%2];
				
				
			}
			else
				v[i][j%2]=max(0, v[i][(j+1)%2], v[i-1][j%2]);
				if (max(v[i-1][(j+1)%2]+1, v[i][(j+1)%2], v[i-1][j%2])==v[i][(j+1)%2])
					last[i][j%2]=last[i][(j+1)%2];
				if (max(v[i-1][(j+1)%2]+1, v[i][(j+1)%2], v[i-1][j%2])==v[i-1][j%2])
					last[i][j%2]=last[i-1][j%2];
		}
	printf("%d\n", v[n][m%2]);
	for (i=1, j=1; i<=n; i++)
	{
		if(v[i][m%2]==j)
		{
			printf("%d ", b[last[i][m%2] ]);
			++j;
		}
	}
	fclose(stdout);
	return 0;
}
