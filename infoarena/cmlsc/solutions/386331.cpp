#include<cstdio>
#define N 1026
#define maxx(a,b) ((a<b)? (b):(a))
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
				a[i][j]=a[i-1][j-1]+1;
			else
				a[i][j]=maxx(a[i-1][j],a[j][i-1]);
	}
	printf("%d\n",a[n][m]);
}
int c=0;
void subsir()
{
	int x=n,y=m,nr=a[n][m];
	while (nr)
	{
		if (v1[x]==v2[y])
		{
			v[nr--]=v1[x];
			--x;
			--y;
		}
		else
			if (a[x-1][y]>a[x][y-1])
				--x;
			else 
				--y;
	}
	for (int i=1;i<=a[n][m];++i)
		printf("%d ",v[i]);
}
int main()
{
	citire();
	matrice();
	subsir();
	return 0;
}