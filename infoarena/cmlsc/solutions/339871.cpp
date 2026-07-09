#include <stdio.h>
#define MAXN 1025

short best[MAXN][MAXN],pred[MAXN][MAXN],s1[MAXN],s2[MAXN];
int max(int v1,int v2,int v3,int v4)
{
	if (v1>v2)
	{
		pred[v3][v4] = 2;
		return v1; 
	}
	pred[v3][v4] = 1;
	return v2;
}

void tipar(int i,int j)
{
	switch (pred[i][j])
	{
	case 1:
		tipar(i,j-1);break;
	case 2:
		tipar(i-1,j);break;
	case 3:
		tipar(i-1,j-1);printf("%d ",s1[i]);break;
	}
}

int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);

	int i,j,n,m;

	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++)
	{
		scanf("%d",&s1[i]);
	}
	for (i=1;i<=m;i++)
	{
		scanf("%d",&s2[i]);
	}

	for (i=1;i<=n;i++)
	{
		for (j=1;j<=m;j++)
		{
			if (s1[i] == s2[j])
			{
				best[i][j] = best[i-1][j-1] + 1;
				pred[i][j] = 3;
			}
			else
			{
				best[i][j] = max(best[i-1][j],best[i][j-1],i,j);
			}
		}
	}
	printf("%d\n",best[n][m]);
	tipar(n,m);
	return 0;
}