#include <fstream>
#include <cmath>
#include <vector>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int dp[1030][1030], n, m, v1[1030], v2[1030];
int main(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> v1[i];
	}
	for (int i = 1; i <= m; i++) {
		cin >> v2[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (v1[i] == v2[j]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	int ans = dp[n][m], x = n, y = m;
	vector<int> rez;
	cout << ans << '\n';
	while (ans != 0) {
		if (v1[x] == v2[y]) {
			ans--;
			rez.emplace_back(v1[x]);
			x--;
			y--;
		}
		else {
			if (dp[x - 1][y] == dp[x][y]) {
				x--;
			}
			else {
				y--;
			}
		}
	}
	for (int i = rez.size() - 1; i >= 0; i--) {
		cout << rez[i] << ' ';
	}
}