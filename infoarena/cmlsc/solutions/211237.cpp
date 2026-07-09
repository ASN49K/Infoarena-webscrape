#include<cstdio>
#define max(a,b) ((a)>(b)?(a):(b))
int n,m,a[1030],b[1030],x[1030][1030],y[1030],k;

void rd()
{
scanf("%d%d",&n,&m);
int i;
for(i=1;i<=n;i++)
	scanf("%d",&a[i]);
for(i=1;i<=m;i++)
	scanf("%d",&b[i]);
}

void pd()
{
for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
		x[i][j]=max(max(x[i][j-1],x[i-1][j]),x[i-1][j-1]+(a[i]==b[j]?1:0));
}

void save(int x)
{
y[++k]=x;
}

void af()
{
printf("%d\n",x[n][m]);
int i=n,j=m;
while(x[i][j]!=0)
	{
	if(x[i-1][j-1]==x[i][j])  i--,j--;
	else if(x[i][j-1]==x[i][j]) j--;
	else if(x[i-1][j]==x[i][j]) i--;
	else save(a[i]),i--,j--;
	}  
for(int l=x[n][m];l;l--)
	printf("%d ",y[l]);
}

int main()
{
freopen("cmlsc.in","r",stdin);
freopen("cmlsc.out","w",stdout);

rd();
pd();
af();

return 0;
}
