#include <fstream>
#include <stack>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

const int MAXN = 1024;
const int MAXM = 1024;

int a[MAXN + 1], b[MAXM + 1], dp[MAXN + 2][MAXM + 2];
int n, m;

int main() {
	in >> n >> m;

	for (int i = 1; i <= n; ++ i) in >> a[i];
	for (int i = 1; i <= m; ++ i) in >> b[i];

	for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j <= m; ++ j) {
			dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			if (a[i] == b[j])
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
		}
	}

	// for (int i = 1; i <= n; ++ i) {
	// 	for (int j = 1; j <= m; ++ j) {
	// 		out << dp[i][j] << ' ';
	// 	}
	// 	out << '\n';
	// }

	out << dp[n][m] << '\n';

	stack<int> ans;
	int i = n, j = m;
	while (dp[i][j] != 0) {
		while (dp[i - 1][j] == dp[i][j]) -- i;
		while (dp[i][j - 1] == dp[i][j]) -- j;
		ans.push(a[i]);
		-- i;
		-- j;
	}

	while (ans.size()) {
		out << ans.top() << ' ';
		ans.pop();
	}



	return 0;
}
