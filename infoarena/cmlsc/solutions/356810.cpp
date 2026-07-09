#include<stdio.h>
int N,M,a[1025],b[1025],d[1025][1025],i,j,k,c[1025];
void read(), solve();
int main()
{
	read();
	solve();
	return 0;
}
void read()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d%d",&M,&N);
	for(i=1;i<=M;i++)
		scanf("%d",&a[i]);
	for(j=1;j<=N;j++)
		scanf("%d",&b[j]);
}
void solve()
{
	for(i=1;i<=M;i++)
	for(j=1;j<=N;j++)
	{
		if(a[i]==b[j])
		{
			d[i][j]=d[i-1][j-1]+1; continue;
		}
		d[i][j]=d[i][j-1]>d[i-1][j]?d[i][j-1]:d[i-1][j];
	}
	printf("%d\n",d[M][N]);
	for(;;)
	{
		if(!d[M][N]) break;
		if(a[M]==b[N])
		{
			c[++k]=a[M];
			M--; N--; continue;
		}
		if(d[M][N]==d[M-1][N])
			{M--; continue;}
		N--;
		continue;
	}
	for(;k;k--)
		printf("%d ",c[k]);
}

