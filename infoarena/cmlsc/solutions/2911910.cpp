#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
int d1[5] = { 0, -1, 0, 1, 0 };
int d2[5] = { 0, 0, 1, 0, -1 };

int d11[9] = { 0 , -1, -1, 0, 1, 1, 1, 0, -1 };
int d22[9] = { 0, 0, 1, 1, 1, 0, -1, -1, -1 };
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");


//----------------------------------

int n, m;
int a[1025], b[1025], dp[1025][1025];

int main() {

	fin >> n >> m;
	for (int i = 1; i <= n; i++) {
		fin >> a[i];
	}
	for (int j = 1; j <= m; j++) {
		fin >> b[j];
	}


	for (int j = 1; j <= m; j++) {
		for (int i = 1; i <= n; i++) {
			if (a[i] == b[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	int ia = n, ja = m;
	vector<int> ans;

	while (1) {
		if (ans.size() == dp[n][m]) {
			break;
		}
		else {
			if (a[ia] == b[ja]) {
				ans.push_back(a[ia]);
				ia--, ja--;
			}
			else {
				if (dp[ia - 1][ja] == dp[ia][ja]) {
					ia--;
				}
				else {
					ja--;
				}
			}
		}
	}

	fout << dp[n][m] << '\n';
	reverse(ans.begin(), ans.end());

	for (auto i : ans) {
		fout << i << " ";
	}
}