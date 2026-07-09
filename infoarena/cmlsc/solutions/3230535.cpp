#include <bits/stdc++.h>

using namespace std;

const int N = 1024 + 7;
int n, m, a[N], b[N], dp[N][N];

void print(int i, int j) {
	if (!i || !j) {
		return;
	}
	if (a[i] == b[j]) {
		print(i - 1, j - 1);
		cout << a[i] << " ";
	} else {
		if (dp[i - 1][j] == dp[i][j]) {
			print(i - 1, j);
		} else {
			print(i, j - 1);
		}
	}
}

int main() {
#ifdef INFOARENA
	freopen ("cmlsc.in", "r", stdin);
	freopen ("cmlsc.out", "w", stdout);
#endif

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= m; i++) {
		cin >> b[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i] == b[j]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
			} else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	cout << dp[n][m] << "\n";
	print(n, m);
	return 0;
}