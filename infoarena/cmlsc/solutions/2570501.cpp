#include <fstream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

const int MAXN = 1024;
const int MAXM = 1024;

int n, m;
vector<int> v1(MAXN + 2), v2(MAXN + 2);
int dp[MAXN + 2][MAXM + 2];
vector<int> ans;

int main() {
	in >> n >> m;
	for (int i = 1; i <= n; ++ i) in >> v1[i];
	for (int i = 1; i <= m; ++ i) in >> v2[i];

	for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j <= m; ++ j) {
			dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			if (v1[i] == v2[j]) dp[i][j] = max(dp[i - 1][j - 1] + 1, dp[i][j]);
		}
	}

	// for (int i = 1; i <= n; ++ i) {
	// 	for (int j = 1; j <= m; ++ j) {
	// 		out << dp[i][j] << ' ';
	// 	}
	// 	out << '\n';
	// }

	out << dp[n][m] << '\n';

	while (n > 0 && m > 0 && dp[n][m] != 0) {
		if (dp[n][m] == dp[n - 1][m]) -- n;
		else if (dp[n][m] == dp[n][m - 1]) -- m;
		else {
			ans.push_back(v1[n]);
			-- n;
			-- m;
		}
	}

	reverse(ans.begin(), ans.end());
	for (auto x : ans) out << x << ' ';

	return 0;
}
