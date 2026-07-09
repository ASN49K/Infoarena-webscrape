#include <bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
const int N= 1025;
int n, m, i, j, a[N], b[N], dp[N][N], x, y;
vector<int> ans;
pair<int,int> p[N][N];
int main()
{
	fin>>n>>m;
	for(i=1;i<=n;++i)
		fin>>a[i];
	for(i=1;i<=m;++i)
		fin>>b[i];
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
			{
				if(dp[i][j]<dp[i-1][j])
				{
					dp[i][j]=dp[i-1][j];
					p[i][j]=p[i-1][j];
				}
				if(dp[i][j]<dp[i][j-1])
				{
					dp[i][j]=dp[i][j-1];
					p[i][j]=p[i][j-1];
				}
				if(dp[i-1][j-1]+(a[i]==b[j])>dp[i][j])
				{
					dp[i][j]=dp[i-1][j-1]+(a[i]==b[j]);
					if(a[i]==b[j])
					p[i][j]={i,j};
					else p[i][j]=p[i-1][j-1];
				}
			}
	x=p[n][m].st,y=p[n][m].nd;
	while(dp[x][y])
	{
		ans.pb(a[x]);
		--x;
		--y;
		int x2=x, y2=y;
		x=p[x2][y2].st;
		y=p[x2][y2].nd;
	}
	fout<<dp[n][m]<<'\n';
	for(i=dp[n][m]-1;i>=0;--i)
		fout<<ans[i]<<' ';
}