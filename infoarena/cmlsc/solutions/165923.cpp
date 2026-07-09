#include<stdio.h>
#define M 10

int n,m,i,j,a[M],b[M],sol[M][M],aux;

int max(int a,int b)
{
	if (a>b) return a;
	else	 return b;
}

int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=m;i++) scanf("%d",&b[i]);
	for (i=1;i<=n/2;i++)
		aux=a[i],a[i]=a[n-i+1],a[n-i+1]=aux;
	for (i=1;i<=m/2;i++)
		aux=b[i],b[i]=b[m-i+1],b[m-i+1]=aux;
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			if (a[i]==b[j])
				sol[i][j]=sol[i-1][j-1]+1;
			else
				sol[i][j]=max(sol[i-1][j],sol[i][j-1]);
	printf("%d\n",sol[n][m]);
	while (sol[n][m])
	{
		if (a[n]==b[m]) printf("%d ",a[n]),n--,m--;
		else
			if (sol[n-1][m]>=sol[n][m-1])
				n--;
			else
				m--;
	}


	return 0;
}