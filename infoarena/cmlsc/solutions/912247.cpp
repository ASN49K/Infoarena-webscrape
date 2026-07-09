#include<cstdio>
#include<cstring>
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
	printf("%d\n",a[n][m]);
	
	memset(v,0,sizeof(v));
	k=a[n][m];j=k;
	while(k!=0){
		while(a[n][m-1]==k)m--;
		while(a[n-1][m]==k)n--;
		v[k]=w[m];
		n--;m--;k--;
	}
	for(i=1;i<=j;i++)printf("%d ",v[i]);
	return 0;
}