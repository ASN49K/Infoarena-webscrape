#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <bitset>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>

using namespace std;

#ifdef LOCAL
ifstream fin("input.txt");
#define fout cout
#else
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
#endif

const int NMAX = 1050;

int n, m;
int a[NMAX], b[NMAX];
int dp[NMAX][NMAX];
vector<int> ans;

void read() {
	fin >> n >> m;
	for (int i = 1; i <= n; i++)
		fin >> a[i];
	for (int i = 1; i <= m; i++)
		fin >> b[i];
}

void solve() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			if (a[i] == b[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				if (dp[i][j] == (int)ans.size() + 1)
					ans.push_back(a[i]);
			}
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	fout << dp[n][m] << '\n';
	for (auto &it : ans)
		fout << it << ' ';
}

int32_t main() {
	read();
	solve();
	return 0;
}

