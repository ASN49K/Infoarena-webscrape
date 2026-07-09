#include<cstdio>
const int N=1100;
int maxi,n,m,sol[N],a[N],b[N],M[N][N];
int max(int x,int y)
{
	if(x>y) return x;
	return y;
}
int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;++i)
		scanf("%d",&b[i]);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;j++)
			if(a[i]==b[j])
				M[i][j]=M[i-1][j]+1;
			else
				M[i][j]=max(M[i][j-1],M[i-1][j]);
	printf("%d\n",M[n][m]);
	maxi=M[n][m];
	if(maxi==0)
		return 0;
	int i=n;
	int j=m;
	while(maxi)
	{
		if(M[i-1][j]==maxi)
		{
			i--;
			continue;
		}
		if(M[i][j-1]==maxi)
		{
			j--;
			continue;
		}
		sol[maxi]=a[i];
		i--;
		j--;
		maxi--;
	}
	for(int i=1;i<=M[n][m];i++)
		printf("%d ",sol[i]);
	return 0;
}