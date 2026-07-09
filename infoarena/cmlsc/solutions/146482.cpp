#include<stdio.h>
int n,m,i,j;
int a[1025],b[1025],c[1025][1025];
void ruxii(int i,int j)
{
if(i>0&&j>0)
	{
	if(a[i]==b[j])
		{
		ruxii(i-1,j-1);
		printf("%d ",a[i]);
		}
	else
	if (c[i][j]==c[i][j-1])
	ruxii(i,j-1);
	else
	ruxii(i-1,j);
	}
}
int main(void)
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(j=1;j<=m;j++)
		scanf("%d",&b[j]);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(a[i]==b[j])
				c[i][j]=c[i-1][j-1]+1;
			else
			{
			c[i][j]=c[i-1][j];
			if(c[i][j-1]>c[i][j])
			c[i][j]=c[i][j-1];
}
printf("%d\n",c[n][m]);
ruxii(n,m);
printf("\n");
return 0;
}

