#include<stdio.h>
#define N 1026
int a[N][N],v1[N],v2[N],n,m,v[N],nr;
void citire()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1; i<=n; ++i) scanf("%d",&v1[i]);
	for (int i=1; i<=m; ++i) scanf("%d",&v2[i]);
}
void matrice()
{
	for (int i=1; i<=n; ++i)
	{
		for (int j=1; j<=m; ++j)
			if (v1[i]==v2[j])
			{
				a[i][j]=a[i-1][j-1]+1;
				//v[++nr]=v2[j];
			}
			else
				if (a[i-1][j]>a[i][j-1])
					a[i][j]=a[i-1][j];
				else
					a[i][j]=a[i][j-1];
	}
	printf("%d\n",a[n][m]);
	for (int i=1; i<=nr; ++i)
		printf("%d ",v[i]);
}
int main()
{
	citire();
	matrice();
	return 0;
}
