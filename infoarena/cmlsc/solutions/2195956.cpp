#include <bits/stdc++.h>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int n, m;
short dp[1050][1050], a[1050], b[1050];
vector <short> sol;

int main(){
	in >> n >> m;
	for(int i = 1; i <= n; i++)
		in >> a[i];
	for(int j = 1; j <= m; j++)
		in >> b[j];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(a[i] == b[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
	out << dp[n][m] << '\n';
	int i = n, j = m;
	while(dp[i][j]){
		while(i && dp[i - 1][j] == dp[i][j])
			i--;
		while(j && dp[i][j - 1] == dp[i][j])
			j--;
		sol.push_back(a[i]);
		i--;
		j--;
	}
	reverse(sol.begin(), sol.end());
	for(auto i : sol)
		out << i << ' ';
	return 0;
}
