#include<stdio.h>
using namespace std;
#define Max 1025
int a[Max],b[Max],i,j,d[Max][Max],n,m;
void rezolva(int x,int y)
{
	if(x>=1&&y>=1)
	{
		if(a[x]==b[y])
		{
			rezolva(x-1,y-1);
			printf("%d ",a[x]);
		}
		else
		{
			if(d[x-1][y]>d[x][y-1])
				rezolva(x-1,y);
			else
				rezolva(x,y-1);
		}
	}
}
int maxim(int x,int y)
{
	if(x>y)
		return x;
	else
		return y;
}
int main()
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
		{
			if(a[i]==b[j])
			d[i][j]=d[i-1][j-1]+1;
			else
			d[i][j]=maxim(d[i-1][j],d[i][j-1]);
		}
		printf("%d\n",d[n][m]);
rezolva(n,m);
	return 0;}