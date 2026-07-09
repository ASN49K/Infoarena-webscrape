#include<cstdio>
#include<algorithm>
using namespace std;
int a[1026],b[1026],v[1026][1026],rez[1026],n,i,j,k,m,t,p;
int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d %d",&n,&m);
	for (i=1;i<=n;i++) scanf("%d",&a[i]);
	for (i=1;i<=n;i++) scanf("%d",&b[i]);
	for (i=1;i<=n;i++) 
		for (j=1;j<=m;j++) if (a[i]==b[j]) v[i][j]=1+v[i-1][j-1];else v[i][j]=max(v[i-1][j],v[i][j-1]);
	printf("%d\n",v[n][m]);
	p=v[n][m];i=n,j=m;
	while (v[i][j]!=0)
	{
		if (a[i]==b[j]) rez[v[i][j]]=a[i],--i,--j;else
			if (v[i-1][j]>v[i][j-1]) i--;else j--;
	}
	for (i=1;i<=p;i++) printf("%d ",rez[i]);
	return 0;
}