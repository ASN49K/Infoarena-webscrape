#include <bits/stdc++.h>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

const int N = 1026;

int n, m, dp[N][N];
uint16_t v[N];

int main()
{
	f >> n >> m;
	for (int i = 1; i <= n; i++)
		f >> v[i];
	for (int j = 1; j <= m; j++){
		uint16_t x; f >> x;
		for (int i = 1; i <= n; i++){
			if (v[i] == x) dp[i][j] = dp[i-1][j-1]+1;
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	g << dp[n][m] << '\n';

	int i = n, j = m;
	stack<uint16_t> r;
	while (dp[i][j]){
		if (dp[i][j] == dp[i-1][j-1]+1){
			r.push(v[i]);
			i--; j--;
		}
		else if (dp[i][j] == dp[i-1][j]) i--;
		else j--;
	}
	while (!r.empty()){
		g << r.top() << ' ';
		r.pop();
	}

	return 0;
}