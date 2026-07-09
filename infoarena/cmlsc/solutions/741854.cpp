#include<stdio.h>
int n,m,s,i,j,min,o,k,sir[100],d[101][101],b[101],a[101];
int main ()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=m;i++)
		scanf("%d",&b[i]);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(a[i]==b[j])d[i][j]=1+d[i-1][j-1];
			else 
			{
				if(d[i-1][j]>d[i][j-1])d[i][j]=d[i-1][j];
				else d[i][j]=d[i][j-1]; 
			}
	i=n;
	j=m;
	while(i>0&&j>0)
		if(a[i]==b[j])
		{
			sir[++k]=a[i];
			i--;
			j--;
		}
		else if(d[i-j][j]<d[i][j-1])
			j--;
		else i--;
	printf("%d\n",k);
	for(i=k;i>=1;i--)
		printf("%d ",sir[i]);
	return 0;
}
