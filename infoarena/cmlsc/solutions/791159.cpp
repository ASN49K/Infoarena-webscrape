#include<cstdio>
using namespace std;
int nr,i,j,n,m,a[1026],b[1026],c[1026][1026],ras[1026];
int main()
{
freopen("cmlsc.in","r",stdin);
freopen("cmlsc.out","w",stdout);
scanf("%d",&n);
scanf("%d",&m);
for(i=1;i<=n;i++)
	scanf("%d",&a[i]);
for(i=1;i<=m;i++)
	scanf("%d",&b[i]);
if(a[1]==b[1]) c[1][1]=1;
else c[1][1]=0;
for(i=2;i<=n;i++)
{
	if(a[i]==b[1]) c[i][1]=1;
	else c[i][1]=c[i-1][1];
}
for(j=2;j<=m;j++)
{
	if(a[1]==b[j]) c[1][j]=1;
	else c[1][j]=c[1][j-1];
}
for(i=2;i<=n;i++)
	for(j=2;j<=m;j++)
	{
		if(a[i]==b[j]) c[i][j]=c[i-1][j-1]+1;
		else
		{
			if(c[i-1][j]>c[i][j-1]) c[i][j]=c[i-1][j];
			else c[i][j]=c[i][j-1];
		}
	}
i=n;
j=m;
while(i>0&&j>0)
{
	if(a[i]==b[j])
	{
		nr++;
		ras[nr]=a[i];
		i--;
		j--;
	}
	else
	if(c[i][j-1]>c[i-1][j]) j--;
	else i--;
}
printf("%d\n",nr);
for(i=nr;i>=1;i--)
	printf("%d ",ras[i]);
return 0;
}
