#include<stdio.h>
#include<algorithm>
using namespace std;
long a[1201],v[1201],n,m,nr,i,st,dr,med,poz,x,j;
int caut(long val)
{
	st=1;
	dr=n;
	while (st<=dr)
	{
		med=(st+dr)/2;
		if (a[med]==val)
			return med;
		if (a[med]<val)
			st=med+1;
		else
			dr=med-1;
	}
	return 0;
}
int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%ld %ld",&n,&m);
	for (i=1;i<=n;i++)
		scanf("%ld",&a[i]);
	sort(a+1,a+n+1);
	for (j=1;j<=m;j++)
	{
		scanf("%ld",&x);
		poz=caut(x);
		if (poz>0)
		{
			a[poz]=0;
			sort(a+1,a+n+1);
			v[++nr]=x;
		}
	}
	printf("%ld\n",nr);
	for (i=1;i<=nr;i++)
		printf("%ld ",v[i]);
}