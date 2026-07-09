#include<stdio.h>
#define N 1025
int n,m,v1[N],v2[N],c[N][N],sol[N],k;
void read()
{
	int i;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",&v1[i]);
	for(i=1;i<=m;i++)
		scanf("%d",&v2[i]);
}
inline int max(int a,int b)
{
	return a>b?a:b;
}
void solve()
{
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(v1[i]==v2[j])
				c[i][j]=c[i-1][j-1]+1;
			else
				c[i][j]=max(c[i-1][j],c[i][j-1]);
	printf("%d\n",c[n][m]);
	for(i=n,j=m;i;)
		if(v1[i]==v2[j])
		{
			sol[++k]=v1[j];
			i--;
			j--;
		}
		else
			if(c[i-1][j]<c[i][j-1])
				j--;
			else
				i--;
	for(i=k;i>1;i--)
		printf("%d ",sol[i]);
	printf("%d\n",sol[1]);
}
int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	read();
	solve();
	return 0;
}
