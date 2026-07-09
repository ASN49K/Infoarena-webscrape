#include <stdio.h>
int x[1030][1030],sol[1030];
int main()
{
int s=0,a[1030],b[1030],m,n,i,j;
freopen("cmlsc.in","r",stdin);
freopen("cmlsc.out","w",stdout);
scanf("%d%d",&m,&n);
for (i=1;i<=m;++i)
	scanf("%d",&a[i]);
for (i=1;i<=n;++i)
	scanf("%d",&b[i]);
for (i=1;i<=m;++i)
	for (j=1;j<=n;++j)
		if (a[i]==b[j])
			x[i][j]=1+x[i-1][j-1];
		else
			if (x[i-1][j]>x[i][j-1]) x[i][j]=x[i-1][j];
				else x[i][j]=x[i][j-1];
printf("%d\n",x[m][n]);
i=m;
j=n;
while (i&&j)
	{
	if (a[i]==b[j])
		{
		sol[++s]=a[i];
		i--;
		j--;
		}
	else
	if (x[i-1][j]>x[i][j-1])
		i--;
	else
		j--;
	}
for (i=s;i>=1;i--)
	printf("%d ",sol[i]);
printf("\n");

return 0;
}