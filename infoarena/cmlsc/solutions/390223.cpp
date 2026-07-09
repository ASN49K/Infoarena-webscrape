#include<stdio.h>
int n,m;
int mat[1100][1100];
int c[1100],d[1100],st[1100];
int max(int a, int b)
{
	if(a>b) return a;
	return b;
}
void read()
{
	int i;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i) scanf("%d",&c[i]);
	for(i=1;i<=m;++i) scanf("%d",&d[i]);
}
void rez()
{
	int i,j;
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=m;++j)
		{
			if(c[i]==d[j])
			{
				mat[i][j]=mat[i-1][j-1]+1;
			}
			else
			{
				mat[i][j]=max(mat[i][j-1],mat[i-1][j]);
			}
		}
	}
	printf("%d\n",mat[n][m]);
	st[0]=-1;
}
void print()
{
	int i;
	for(i=st[0];i>=1;--i) printf("%d ",st[i]);
}
void reconst(int n, int m, int l)
{
	int i,j;
	st[++st[0]]=c[n+1];
	if(l==0) print();
	else
	{
		for(i=n;i>=1;--i)
			for(j=m;j>=1;--j)
				if(mat[i][j]==l && c[i]==d[j])
					reconst(i-1,j-1,l-1);
	}
}
int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	read();
	rez();
	reconst(n,m,mat[n][m]);
	return 0;
}