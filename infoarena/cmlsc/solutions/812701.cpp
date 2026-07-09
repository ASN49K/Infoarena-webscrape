#include<cstdio>
int max(int q1,int q2)
{
	if(q1>q2)return q1;
	return q2;
}	
int m,n,a[1100],b[1100],v[1100][1100],sir[1100],rez,i,j;
int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d%d",&m,&n);
	for(i=1;i<=m;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			if(a[i]==b[j])
				v[i][j]=v[i-1][j-1]+1;
			else
				v[i][j]=max(v[i-1][j],v[i][j-1]);
	for (i = m, j = n; i; )
		if(a[i]==b[j])
			sir[++rez]=a[i],--i,--j;
		else if(v[i-1][j]<v[i][j-1])
				--j;
		else	--i;
	printf("%d\n",rez);
	for(i=rez;i>=1;--i)
		printf("%d ",sir[i]);
}