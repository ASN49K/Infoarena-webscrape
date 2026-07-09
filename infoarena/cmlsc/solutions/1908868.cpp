#include <bits/stdc++.h>

using namespace std;

const int nMax = 1026;

int n, m, a[nMax], b[nMax];
int dp[nMax][nMax];
pair<int, int>from[nMax][nMax]; // dp[i][j]=cmlsc dintre prefixul de lg i din a, prefixul de lg j din b

void go(int i, int j) {
	if (i <= 0 || j <= 0)
		return;

	go(from[i][j].first, from[i][j].second);

	if (a[i] == b[j])
		printf("%d ", a[i]);
}
int main() {
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);

	scanf("%d%d", &n, &m);

	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);

	for (int i = 1; i <= m; ++i)
		scanf("%d", &b[i]);

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (a[i] == b[j])
				dp[i][j] = dp[i - 1][j - 1] + 1, from[i][j] = {i - 1, j - 1};
			else {
				if (dp[i - 1][j] > dp[i][j - 1])
					dp[i][j] = dp[i - 1][j], from[i][j] = make_pair(i - 1, j);
				else dp[i][j] = dp[i][j - 1], from[i][j] = make_pair(i, j - 1);
			}
		}
	}

	printf("%d\n", dp[n][m]);
	go(n, m);
	return 0;
}
