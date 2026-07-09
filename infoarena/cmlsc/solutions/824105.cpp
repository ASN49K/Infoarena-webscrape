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
	p=v[n][m];
	while (v[n][m]!=0)
	{
		if (a[n]==b[m]) rez[v[n][m]]=a[n],--n,--m;else
			if (v[n-1][m]>v[n][m-1]) n--;else m--;
	}
	for (i=1;i<=p;i++) printf("%d ",rez[i]);
	return 0;
}