#include<stdio.h>
inline int max(int x,int y)
{
	if(x>y) return x;
	return y;
}
int m,n,i,j,v[1030][1030],a[1030],b[1030],k,l,p=0;
int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d%d",&m,&n);
	for(i=1;i<=m;++i)
		scanf("%d",&a[i]);
	for(i=1;i<=n;++i)
		scanf("%d",&b[i]);
	for(i=1;i<=m;++i)
	{
		for(j=1;j<=n;++j)
			if(a[i]==b[j])
					v[i][j]=v[i-1][j-1]+1;
			else v[i][j]=max(v[i-1][j],v[i][j-1]);
	}
	printf("%d\n1",v[m][n]);
	return 0;
}
