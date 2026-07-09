#include "stdio.h"
int a[20][20],x[20],y[20],m,n,v[100],k;

int maxim(int x,int y)
{
	if(x>y)
		return x;
	else 
		return y;
}
void dinamica()
{
	int i,j;
	//for(i=0;i<=m;i++)a[i][0]=0; for(j=0;j<=n;j++)a[0][j]=0;
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			if(x[i]==y[j])
				a[i][j]=a[i-1][j-1]+1;
			else 
				a[i][j]=maxim(a[i-1][j],a[i][j-1]);
	printf("%d\n", a[m][n]);
}

void afisare(int i,int j)
{
	k=0;
	while(i>0&&j>0)
	{
		if(x[i]==y[j])
		{
			v[++k]=x[i];
			i--;
			j--;
		}
		else 
			if(a[i][j]==a[i-1][j])
				i--;
		else 
			if(a[i][j]==a[i][j-1])
				j--;
	}
	for(i=k;i>=1;i--)
		printf("%d ",v[i]);
}
int main () 
{
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);
	int i;
	scanf("%d %d", &m, &n);
	for(i=1;i<=m;i++)scanf("%d", &x[i]);
	for(i=1;i<=n;i++)scanf("%d", &y[i]);
	dinamica();
	afisare(m,n);
	return 0;
}
