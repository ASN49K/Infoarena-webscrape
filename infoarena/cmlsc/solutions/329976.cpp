#include<stdio.h>
using namespace std;

int n,m,c[1025][1025],a[1025],b[1025];

void tipar(int i,int j)
{
if( i!=0 && j!=0 )
	{
	if(a[i]==b[j])
		{		
		tipar(i-1,j-1);
		printf("%d ",a[i]);
		}
	else 
		{
		if(c[i-1][j]>c[i][j-1])tipar(i-1,j);
		else tipar(i,j-1);
		}
	}
}

int main()
{
freopen("cmlsc.in","r",stdin);
freopen("cmlsc.out","w",stdout);
int i,j;
scanf("%d%d",&n,&m);
for(i=1;i<=n;i++)scanf("%d",&a[i]);
for(i=1;i<=m;i++)scanf("%d",&b[i]);
for(i=1;i<=n;i++)
	{
	for(j=1;j<=m;j++)
		{
		if(a[i]==b[j])
			{
			c[i][j]=1+c[i-1][j-1];
			}
		else
			{
			if(c[i-1][j]<c[i][j-1])
				{
				c[i][j]=c[i][j-1];
				}
			else c[i][j]=c[i-1][j];
			}
		}
	}
int max=c[1][1];
for(i=1;i<=n;i++)
	{
	for(j=1;j<=m;j++)if(c[i][j]>max)max=c[i][j];
	}
printf("%d\n",max);
tipar(n,m);
return 0;
}
