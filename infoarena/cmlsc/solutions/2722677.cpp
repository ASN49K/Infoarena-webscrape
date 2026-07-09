#include <bits/stdc++.h>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int n, m, a[1025], b[1025], dp[1025][1025];

int main()
{
	in >> n >> m;
	
	for(int i = 1; i <= n; i++)
		in >> a[i];
		
	for(int i = 1; i <= m; i++)
		in >> b[i];
		
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			dp[i][j] = max(dp[i-1][j-1] + (a[i] == b[j]), max(dp[i][j-1], dp[i-1][j]));
			
	stack <int> sol;
	int i = n, j = m;
	
	while(i && j)
	{
		if(a[i] == b[j])
		{
			sol.push(a[i]);
			i--;j--;
		}
		else if(i > 1 && dp[i][j] == dp[i-1][j])
			i--;
		else
			j--;
	}
	
	out << dp[n][m] << '\n';
	
	while(!sol.empty())
	{
		out << sol.top() << ' ';
		sol.pop();
	}
	
	return 0;
}