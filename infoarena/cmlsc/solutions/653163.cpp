# include <stdio.h>
int a[1030],c[1030][1030],i,n,m,j,x,y,b[1030];
void recurs(int x, int y)
{
	if (x!=0 && y!=0)
	{
		if (a[x]!=b[y])
			if (c[x-1][y]>c[x][y-1])
				recurs(x-1,y);
			else
				recurs(x,y-1);
		else
		{
			recurs(x-1,y-1);
			printf("%d ",a[x]);
		}
	}
}
int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d %d\n",&n,&m);
	for (i=1; i<=n; ++i)
		scanf("%d ",&a[i]);
	scanf("\n");
	for (j=1; j<=m; ++j)
		scanf("%d ",&b[j]);
	for (i=1; i<=n; i++)
		for (j=1; j<=m; j++)
		{
			if (a[i]==b[j]) c[i][j]=c[i-1][j-1]+1;
			else
				if (c[i-1][j]>c[i][j-1]) c[i][j]=c[i-1][j];
			else
				c[i][j]=c[i][j-1];
		}
	printf("%d\n",c[n][m]);
	recurs(n,m);
	printf("\n");
	return 0;
}