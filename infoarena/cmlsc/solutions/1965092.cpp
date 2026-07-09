#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX=1<<10;
int dp[MAX+1][MAX+1],a[MAX+1],b[MAX+1];
void rec(int i,int j)
{
	if(dp[i][j]==0)
		return ;
	if(dp[i-1][j-1]+1==dp[i][j] && a[i]==b[j])
	{
		rec(i-1,j-1);
		printf("%d ",a[i]);
	}
	else
	{
		if(dp[i-1][j]>dp[i][j-1])
			rec(i-1,j);
		else
			rec(i,j-1);
	}
}
int main(int argc, char const *argv[])
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i)
		scanf("%d",&a[i]);
	for(int i=1; i<=m; ++i)
		scanf("%d",&b[i]);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
		{
			if(a[i]==b[j])
				dp[i][j]=dp[i-1][j-1]+1;
			else
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	printf("%d\n",dp[n][m]);
	rec(n,m);
	return 0;
}