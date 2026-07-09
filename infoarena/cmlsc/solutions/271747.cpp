#include <stdio.h>
int t[1030],m,n,a[1030],b[1030],x[1030][1030],i,j,k=0;
int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d%d",&m,&n);
	for (i=1;i<=m;i++)
		scanf("%d",&a[i]);
	for (i=1;i<=n;i++)
		scanf("%d",&b[i]);
	
	x[0][0]=0;
	for (i=1;i<=m;i++)
	{
		for (j=1;j<=n;j++)
			if (a[i]==b[j]) {
				x[i][j]=1+x[i-1][j-1];
				t[++k]=j;
			}
			else
			{
				if (x[i-1][j]>x[i][j-1]) x[i][j]=x[i-1][j];
				else x[i][j]=x[i][j-1];
			}
	}
	printf("%d\n",x[m][n]);
	for (i=1;i<=k;i++)
		printf("%d ",b[t[i]]);
	printf("\n");
	return 0;
}