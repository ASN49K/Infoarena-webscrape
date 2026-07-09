#include<cstdio>
#include<algorithm>
#define nmax 1025
using namespace std;
int m,n,i,j,k,aux[nmax],v[nmax][nmax],a[nmax],b[nmax];
int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d %d",&n,&m);
	for (i=1;i<=n;i++) scanf("%d",&a[i]);
	for (i=1;i<=m;i++) scanf("%d",&b[i]);
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++) if (a[i]==b[j]) v[i][j]=1+v[i-1][j-1];else v[i][j]=max(v[i-1][j],v[i][j-1]);
	printf("%d\n",v[n][m]);
	k=v[n][m];
	while (n>0 & m>0)
	{
		while (v[n-1][m]==k) n--;
		while (v[n][m-1]==k) m--;
		aux[k]=a[n];
		n--;m--;k--;
	}
	i=1;
	while (aux[i]) printf("%d ",aux[i]),i++;
}