#include<cstdio>
int max(int a,int b)
{
	if(a<=b)
		return b;
	return a;
}
int num,n,m,i,j,sol[1030],a[1030],b[1030],d[1030][1030];
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
		{
			if(a[i]==b[j])
				d[i][j]=d[i-1][j-1]+1;
			else
				d[i][j]=max(d[i][j-1],d[i-1][j]);
		}
	printf("%d\n",d[m][n]);
	num=d[m][n];
	i=m; j=n;
	while(num!=0&&i>0&&j>0)
	{
		if(a[i]==b[j])
		{ sol[num--]=a[i]; i--;j--;}
		else
			if(d[i][j-1]>d[i-1][j])
				j--;
			else
				i--;
	}
	for(i=1;i<=d[m][n];i++)
		printf("%d ",sol[i]);
	return 0;
}
