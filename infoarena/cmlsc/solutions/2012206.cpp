#include <bits/stdc++.h>
using namespace std;

const int N = 1026;
int n, m, a[N], b[N];
int dp[2][N], from[2][N];
vector <int> cmlsc;

void init(int l, int y1, int y2) {
	for(int i = max(0, y1 - 1); i <= y2; ++i) {
		from[l][i] = 0;
		dp[l][i] = 0;
	}
}
void rec(int x1, int y1, int x2, int y2) {
	if(y1 > y2)return;
	if(x1 == x2) {
		for(int j = y1; j <= y2; ++j)
			if(b[j] == a[x1]) {
				cmlsc.push_back(a[x1]);
				return;
			}
		return;
	}
	int mid = (x1 + x2) / 2;
	bool l = 0;
	init(0, y1, y2), init(1, y1, y2);
	for(int k = x1; k <= mid; ++k) {
		l ^= 1;
		init(l, y1, y2);
		for(int j = y1; j <= y2; ++j) {
			if(a[k] == b[j]) {
				dp[l][j] = dp[l ^ 1][j - 1] + 1;
			} else {
				if(dp[l ^ 1][j] > dp[l][j - 1] || (j == y1))
					dp[l][j] = dp[l ^ 1][j];
				else dp[l][j] = dp[l][j - 1];
			}
		}
	}
	for(int j = y1; j <= y2; ++j) from[l][j] = j;
	for(int k = mid + 1; k <= x2; ++k) {
		l ^= 1;
		init(l, y1, y2);
		for(int j = y1; j <= y2; ++j) {
			if(a[k] == b[j]) {
				dp[l][j] = dp[l ^ 1][j - 1] + 1, from[l][j] = from[l ^ 1][j - 1];
			} else {
				if(dp[l ^ 1][j] > dp[l][j - 1] || (j == y1))
					dp[l][j] = dp[l ^ 1][j], from[l][j] = from[l ^ 1][j];
				else dp[l][j] = dp[l][j - 1], from[l][j] = from[l][j - 1];
			}
		}
	}
	int val = from[l][y2];
	rec(x1, y1, mid, val);
	rec(mid + 1, val + 1, x2, y2);

}
int main() {
	ifstream cin("cmlsc.in");
	ofstream cout("cmlsc.out");
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)cin >> a[i];
	for(int i = 1; i <= m; ++i)cin >> b[i];
	rec(1, 1, n, m);
	cout << cmlsc.size() << '\n';
	for(auto it : cmlsc)cout << it << ' ';
}
