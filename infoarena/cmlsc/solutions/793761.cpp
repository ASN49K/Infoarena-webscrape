#include <stdio.h>
#define NMAX 1035
int n,m,A[NMAX],B[NMAX],best[NMAX][NMAX];
int dx[]={-1,0,-1},dy[]={-1,-1,0};
char ant[NMAX][NMAX];
void read()
{
	scanf("%d%d",&n,&m);
	int i;
	for (i=1; i<=n; i++)
		scanf("%d",&A[i]);
	for (i=1; i<=m; i++)
		scanf("%d",&B[i]);
}
inline int max(int x,int y)
{
	return x>y ? x : y;
}
void solve()
{
	int i,j;
	for (i=1; i<=n; i++)
		for (j=1; j<=m; j++)
			if (A[i]==B[j])
			{
				best[i][j]=best[i-1][j-1]+1;
				ant[i][j]=0;
			}
			else
			{
				if (best[i][j-1]>best[i-1][j])
				{
					best[i][j]=best[i][j-1];
					ant[i][j]=1;
				}
				else
				{
					best[i][j]=best[i-1][j];
					ant[i][j]=2;
				}
			}
	printf("%d\n",best[n][m]);
}
void recons(int n,int m)
{
	if (n==0 || m==0)
		return ;
	int tip=ant[n][m];
	recons(n+dx[tip],m+dy[tip]);
	if (tip==0)
		printf("%d ",A[n]);
}
int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	read();
	solve();
	recons(n,m);
	printf("\n");
	return 0;
}
