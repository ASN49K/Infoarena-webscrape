#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int dp[1024][1024];
int main() {
	int n, m;
	fin >> n >> m;
	int v[1025], t[1025];
	for (int i = 1; i <= n; i++) fin >> v[i];
	for (int i = 1; i <= m; i++) fin >> t[i];
	for (int i = 1; i <= n; i++) dp[i][0] = 0;
	for (int j = 1; j <= m; j++) dp[0][j] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (v[i] == t[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	fout << dp[n][m];
	int sol[1025], cnt = 0;
	int i = n, j = m;
	while (i && j) {
		if (v[i] == t[j]) {
			sol[++cnt] = v[i];
			i--;
			j--;
		}
		else {
			if (dp[i - 1][j] > dp[i][j - 1]) {
				i--;
			}
			else {
				j--;
			}
		}
	}
	fout << '\n';
	for (int i = cnt; i >= 1; i--) fout << sol[i] << ' ';
}