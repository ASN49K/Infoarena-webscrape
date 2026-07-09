#include<stdio.h>

#define N 1025

int n,m,a[N],b[N],sol[N][N],solfin[N];

int max(int a, int b)
{
	if(a>b) return a;
	return b;
}

int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	
	int i,j,val;
	
	scanf("%d %d",&n,&m);
	for(i=1; i<=n; i++) scanf("%d",&a[i]);
	for(i=1; i<=m; i++) scanf("%d",&b[i]);
	
	for(i=1; i<=n; i++)
	for(j=1; j<=m; j++)
		if(a[i]==b[j]) sol[i][j]=sol[i-1][j-1]+1;
				  else sol[i][j]=max(sol[i-1][j],sol[i][j-1]);
	
	for(i=n,j=m,val=0; i>0 && j>0;)
		if(a[i]==b[j]) solfin[++val]=a[i], --i, --j;
		else 
			if(sol[i-1][j]>sol[i][j-1]) i--;
								   else j--;
	
	printf("%d\n",sol[n][m]);
	for(i=val; i>=1; i--) printf("%d ",solfin[i]);

	return 0;
}