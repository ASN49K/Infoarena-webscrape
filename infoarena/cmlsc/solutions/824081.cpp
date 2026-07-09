#include<cstdio>
#include<algorithm>
using namespace std;
int a[1025],b[1025],v[1025][1025],rez[1025],n,i,j,k,m,t,p;
int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d %d",&n,&m);
	for (i=1;i<=n;i++) scanf("%d",&a[i]);
	for (i=1;i<=n;i++) scanf("%d",&b[i]);
	for (i=1;i<=n;i++) 
		for (j=1;j<=m;j++) if (a[i]==b[j]) v[i][j]=1+v[i-1][j-1];else v[i][j]=max(v[i-1][j],v[i][j-1]);
	while (n!=0 && n!=0)
	{
		if (a[n]==b[m]) p++,rez[p]=a[n],n--,m--;else
			if (v[n-1][m]<v[n][m-1]) m--;else n--;
	}
	printf("%d\n",p);
	for (i=p;i>=1;i--) printf("%d ",rez[i]);
	return 0;
}