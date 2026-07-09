#include <stdio.h>

#define NMAX 1025
#define max(a, b) a > b ? a : b

int n, m, first[NMAX], second[NMAX], dp[NMAX][NMAX], ans[NMAX], i, j, nans;

int main() {
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	for (int it = 1; it <= n; ++it) scanf("%d", &first[it]);
	for (int it = 1; it <= m; ++it) scanf("%d", &second[it]);
	
	for (int it = 1; it <= n; it++) {
		for (int jt = 1; jt <= m; ++jt) {
			if (first[it] == second[jt]) dp[it][jt] = dp[it - 1][jt - 1] + 1;
			else dp[it][jt] = max(dp[it - 1][jt], dp[it][jt - 1]);
		}
	}
	
	printf("%d\n", dp[n][m]);
	
	i = n;
	j = m;
	
	while(i > 0 & j > 0) {
		if (first[i] == second[j]) {
			ans[nans++] = first[i];
			--i;
			--j;
		} else {
			if (dp[i - 1][j] > dp[i][j - 1]) --i;
			else --j;
		}
	}
	
	for (int it = nans - 1; it >= 0; --it) printf("%d ", ans[it]);
	
	return 0;
}