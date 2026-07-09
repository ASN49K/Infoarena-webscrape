#include<iostream>
#include<cstdio>
using namespace std;
int maxim(int a,int b)
{
	if(a>b) return a;
		else return b;
}
int M[1025][1025],a[1025],b[1025],sir[1025],i,j,n,m,k;
int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(j=1;j<=m;++j)
		scanf("%d",&b[j]);
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
			if(a[i]==b[j])
				M[i][j]=M[i-1][j-1]+1;
			else
				M[i][j]=maxim(M[i-1][j],M[i][j-1]);
	i=n;j=m;
	while(i)
	{
		if(a[i]==b[j])
			sir[++k]=a[i],i--,j--;
		else
			if(M[i-1][j]<M[i][j-1])
				j--;
		else
			i--;
	}
	printf("%d\n",k);
	for(i=k;i>=1;--i)
		printf("%d ",sir[i]);
	return 0;
}