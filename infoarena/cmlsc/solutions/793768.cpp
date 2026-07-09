#include <stdio.h>
#define NMAX 1035
int n,m,A[NMAX],B[NMAX],best[NMAX][NMAX];
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
				best[i][j]=best[i-1][j-1]+1;
			else
				best[i][j]=max(best[i-1][j],best[i][j-1]);
	printf("%d\n",best[n][m]);
}
void recons(int n,int m)
{
	if (n==0 || m==0)
		return ;
	if (A[n]==B[m])
	{
		recons(n-1,m-1);
		printf("%d ",A[n]);
		return ;
	}
	if (best[n-1][m]>best[n][m-1])
		recons(n-1,m);
	else
		recons(n,m-1);
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
