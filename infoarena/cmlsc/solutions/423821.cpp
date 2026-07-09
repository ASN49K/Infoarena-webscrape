#include<cstdio>
#include<algorithm>
using namespace std;

int a[2000],b[2000],x[1050][1050],R[1050],k,n,m;

void rd()
{
scanf("%d%d",&n,&m);

int i;
for(i=1;i<=n;i++)
	scanf("%d",&a[i]);
for(i=1;i<=m;i++)
	scanf("%d",&b[i]);
}

void go()
{
for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
		{
		x[i][j]=max(x[i-1][j],x[i][j-1]);
		if(a[i]==b[j])
			x[i][j]=x[i-1][j-1]+1;
		}
}

void af()
{
int i=n,j=m;
while(i&&j)
	if(a[i]==b[j])
		R[++k]=a[i],i--,j--;
	else if(x[i-1][j]>x[i][j-1])
		i--;
	else
		j--;

		
printf("%d\n",k);
for(;k;k--)
	printf("%d ",R[k]);
}

int main()
{
freopen("cmlsc.in","r",stdin);
freopen("cmlsc.out","w",stdout);

rd();
go();
af();

return 0;
}
