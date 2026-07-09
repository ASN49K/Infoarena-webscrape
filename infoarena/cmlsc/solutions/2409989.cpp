#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1025;

int dp[MAXN][MAXN];

int main() {
	#ifdef BLAT
		freopen("input", "r", stdin);
	#else
		freopen("cmlsc.in", "r", stdin);
		freopen("cmlsc.out", "w", stdout);
	#endif

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector < int > a(n + 1), b(m + 1);

	for(int i = 1; i <= n; ++i) cin >> a[i];
	for(int j = 1; j <= m; ++j) cin >> b[j];

	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			if(a[i] == b[j]) {
				dp[i][j] = dp[i-1][j-1] + 1;
			}

			dp[i][j] = max(dp[i][j], max(dp[i-1][j], dp[i][j-1]));
		}
	} 

	cout << dp[n][m] << '\n';
	vector< int > ans;
	int i = n, j = m;
	while(i && j) {
		if(dp[i][j] == dp[i-1][j-1] + 1 && a[i] == b[j]) {
			ans.emplace_back(a[i]);
			--i, --j;
			continue;
		}
		if(dp[i][j] == dp[i-1][j]) --i;
		else --j;
	}

	reverse(ans.begin(), ans.end());
	for(auto &x : ans) cout << x << ' ';
	return 0;
}
