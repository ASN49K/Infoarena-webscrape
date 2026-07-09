#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int DIM = 1024;

int n, m;
int a[DIM + 1], b[DIM + 1];
int dp[DIM + 1][DIM + 1];
vector<int> ans;

void path(int i, int j) {
	if(i != 0 && j != 0) {
		if(a[i] == b[j]) {
			path(i - 1, j - 1);

			ans.push_back(a[i]);
		} else {
			if(dp[i - 1][j] > dp[i][j - 1]) {
				path(i - 1, j);
			} else {
				path(i, j - 1);
			}
		}
	}
}

int main() {
	fin >> n >> m;

	for(int i = 1; i <= n; i++) {
		fin >> a[i];
	}

	for(int i = 1; i <= m; i++) {
		fin >> b[i];
	}

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(a[i] == b[j]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
			} else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	// for(int i = 1; i <= n; i++) {
	// 	for(int j = 1; j <= m; j++) {
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << '\n';
	// }

	path(n, m);

	fout << ans.size() << '\n';
	for(int x: ans) {
		fout << x << " ";
	}
	fout << '\n';
	return 0;
}