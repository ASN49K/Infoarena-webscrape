#include <stdio.h>

#define Nmax 1025

int n,m,v[Nmax],t[Nmax],best[Nmax][Nmax],con[Nmax],nr;

int max(int a,int b)
{
	if(a>b)
		return a;
	return b;
}

int main()
{
	int i,j;
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)
		scanf("%d",&v[i]);
	for(i=1;i<=m;++i)
		scanf("%d",&t[i]);
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
			if(v[i]==t[j])
				best[i][j]=1+best[i-1][j-1];
			else
				best[i][j]=max(best[i-1][j],best[i][j-1]);
	printf("%d\n",best[n][m]);
	i=n;j=m;
	nr=best[n][m];
	while(i && j)
		{
			if(v[i]==t[j])
				{
					con[nr--]=v[i];
					--i;
					--j;
				}
			else
				{
					if(best[i-1][j]>best[i][j-1])
						i--;
					else
						j--;
				}
		}
	for(i=1;i<=best[n][m];++i)
		printf("%d ",con[i]);
	return 0;
}