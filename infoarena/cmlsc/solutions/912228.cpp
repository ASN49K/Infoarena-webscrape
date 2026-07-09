#include<cstdio>
#include<algorithm>
using namespace std;
int a[1025][1025],v[1025],w[1025],n,m,i,j,k;
int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)scanf("%d",&v[i]);
	for(i=1;i<=m;i++)scanf("%d",&w[i]);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		if(v[i]==w[j])a[i][j]=1+a[i-1][j-1];
		else a[i][j]=max(a[i-1][j],a[i][j-1]);
	printf("%d",a[n][m]);
	return 0;
}