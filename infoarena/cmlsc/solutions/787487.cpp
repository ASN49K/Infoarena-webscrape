#include<stdio.h>



int max(int i, int j, int k)
{
	if(i<j)
		i=j;
	if(i<k)
		i=k;
	return i;
}



int a[1030][1030];
char x[1030],y[1030];



int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	int n,m,i,j,k;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)
		scanf("%d",&x[i]);
	for(i=1;i<=m;++i)
		scanf("%d",&y[i]);
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
			if(x[i]==y[j])
				a[i][j]=a[i-1][j-1]+1;
			else
				a[i][j]=max(a[i-1][j-1],a[i][j-1],a[i-1][j]);
	printf("%d\n",a[n][m]);
	i=n;
	j=m;
	k=0;
	while(i&&j&&k<=a[n][m])
	{
		if(x[i]==y[j])
		{
			a[0][++k]=x[i];
			--i;
			--j;
		}
		else
			if(a[i][j]==a[i-1][j-1])
			{
				--i;
				--j;
			}
			else
				if(a[i][j]==a[i-1][j])
					--i;
				else
					--j;
	}
	for(;k>0;--k)
		printf("%d ",a[0][k]);
	return 0;
}
