#include<stdio.h>
#define N 1025
int n,m,a[N],b[N],c[N][N],sol[N],k;
void read()
{
	int i;
	scanf("%d%d",&m,&n);
	for(i=1;i<=m;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
		scanf("%d",&b[i]);
}
inline int max(int a,int b)
{
	return a>b?a:b;
}
void solve()
{
	int i,j;
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			if(a[i]==b[j])
				c[i][j]=c[i-1][j-1]+1;
			else
				c[i][j]=max(c[i-1][j],c[i][j-1]);
	printf("%d\n",c[m][n]);
	for(i=m,j=n;i;)
		if(a[i]==b[j])
		{
			sol[++k]=a[i];
			i--;
			j--;
		}
		else
			if(c[i-1][j]<c[i][j-1])
				j--;
			else
				i--;
	for(i=k;i>1;i--)
		printf("%d ",sol[i]);
	printf("%d\n",sol[1]);
}
int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	read();
	solve();
	return 0;
}
