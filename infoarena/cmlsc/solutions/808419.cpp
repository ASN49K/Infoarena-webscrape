#include <cstdio>
#include <algorithm>
using namespace std;

inline int next_int() {
	int d;
	scanf("%d", &d);
	return d;
}

int n, m, size;
int A[1024], B[1024], ans[1024];
int dp[1024 + 2][1024 + 2];
int main() {
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);
	n = next_int();
	m = next_int();
	for (int i = 0; i < n; i++) {
		A[i] = next_int();
	}
	for (int j = 0; j < m; j++) {
		B[j] = next_int();
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (A[i - 1] == B[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			} else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	printf("%d\n", dp[n][m]);
	while (n > 0 && m> 0) {
		if (A[n - 1] == B[m - 1]) {
			ans[size++] = A[n - 1];
			n--;
			m--;
		} else if (dp[n - 1][m] < dp[n][m - 1]) {
			m--;
		} else {
			n--;
		}
	}
	while (size--) {
		printf("%d ", ans[size]);
	}
	return 0;
}
