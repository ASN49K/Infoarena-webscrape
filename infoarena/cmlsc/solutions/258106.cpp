#include<stdio.h>
int v[1024][1024],n,m,i,j,a[1024],b[1024],r[1024],k;
int max(int a,int b)
{
	if(a>b)
		return a;
	return b;
}
int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=m;i++)
		scanf("%d",&b[i]);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			if(a[i]==b[j])
				v[i][j]=v[i-1][j-1]+1;
			else
				v[i][j]=max(v[i][j-1],v[i-1][j]);
		}
	printf("%d\n",v[n][m]);
	k=v[n][m];
	for(i=n,j=m;i>0,j>0;)
		if(a[i]==b[j])
		{
			r[k]=a[i];
			k--;
			j--;
			i--;
		}
		else
			if(v[i][j]==v[i][j-1])
				j--;
			else
				i--;
	for(i=1;i<=v[n][m];i++)
		printf("%d ",r[i]);
	return 0;
}
