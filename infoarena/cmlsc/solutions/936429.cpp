#include <fstream>
using namespace std;

int main() {
	ifstream fin("cmlsc.in");
	ofstream fout("cmlsc.out");
	int m, n;
	fin >> m >> n;
	int a[m+1], b[n+1];
	for (int i = 1; i <= m; ++i)
		fin >> a[i];
	for (int i = 1; i <= n; ++i)
		fin >> b[i];

	int dp[m+1][n+1];
	for (int i = 0; i <= m; ++i)
		dp[i][0] = 0;
	for (int i = 1; i <= n; ++i)
		dp[0][i] = 0;
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (a[i] == b[j]) dp[i][j] = dp[i-1][j-1]+1;
			else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		}
	}
	int ans = dp[m][n];
	int sub[ans];
	for (int i = m, j = n, k = ans; k >= 0;) {
		if (a[i] == b[j]) {
			sub[--k] = a[i];
			--i;
			--j;
		}
		else {
			if (dp[i-1][j] >= dp[i][j-1]) --i;
			else --j;
		}
	}
	fout << ans << '\n';
	for (int i = 0; i < ans; ++i)
		fout << sub[i] << ' ';
	return 0;
}
