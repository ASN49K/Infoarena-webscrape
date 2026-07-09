#include <bits/stdc++.h>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
#define cin f
#define cout g
const int MAX = 1025;
int n, m, a[MAX], b[MAX];
int dp[MAX][MAX], ans[MAX];
int main()
{
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	for(int i=1;i<=m;i++)
		cin >> b[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[i] == b[j])
				dp[i][j] = dp[i-1][j-1] + 1;
			else
				dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
	cout<<dp[n][m]<<'\n';
	int i = n, j = m;
	while(dp[i][j] != 0)
	{
		if(dp[i-1][j-1] + 1 == dp[i][j])
		{
			ans[dp[i][j]] = a[i];
			j --;
		}
		i --;
	}
	for(int i=1;i<=dp[n][m];i++)
		cout<<ans[i]<<" ";
	return 0;
}