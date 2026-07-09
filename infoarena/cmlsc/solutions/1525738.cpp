#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = (1 << 10) + 5;

int n, m;
int a[MAX], b[MAX], dp[MAX][MAX];
vector<int> v;

int main() {
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= m; i++)	
		scanf("%d", &b[i]);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (a[i] == b[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

	printf("%d\n", dp[n][m]);
	
	int i = n, j = m, sol = dp[n][m];
	while (i >= 1 && j >= 1 && sol) 
		if (a[i] == b[j]) {
			v.push_back(a[i]);
			i--, j--, sol--;
		} else {
			if (dp[i][j] == dp[i - 1][j])
				i--;
			else j--;
		}
	
	while (!v.empty()) {
		printf("%d ", v.back());
		v.pop_back();
	}
	

	return 0;	
}