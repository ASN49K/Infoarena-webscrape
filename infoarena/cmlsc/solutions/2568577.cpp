#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int DIM = 1025;

int v[DIM];
int t[DIM];

int dp[DIM][DIM];

main()
{
	int n, m;
	fin >> n >> m;
	
	for(int i = 1; i <= n; ++i)
		fin >> v[i];
	
	for(int i = 1; i <= m; ++i)
		fin >> t[i];
	
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
		{
			if(v[i] == t[j])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	
	vector <int> ans;
	
	for(int i = n, j = m; i;)
		if(v[i] == t[j])
		{
			ans.emplace_back(v[i]);
			--i;
			--j;
		}
		else
		{
			if(dp[i - 1][j] > dp[i][j - 1])
				--i;
			else
				--j;
		}
	
	reverse(ans.begin(), ans.end());
	
	fout << ans.size() << '\n';
	
	for(auto i : ans)
		fout << i << ' ';
}