#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

using ll = long long;

const string myf = "cmlsc";
ifstream fin(myf + ".in");
ofstream fout(myf + ".out");


int n, m;
int a[1025];
int b[1025];
int dp[1025][1025];

int main() {

	fin >> n >> m;
	for (int i = 1; i <= n; ++i)
		fin >> a[i];
	for (int j = 1; j <= m; ++j)
		fin >> b[j];
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			dp[i][j] = max({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] + (a[i] == b[j])});
	fout << dp[n][m] << '\n';
	int i, j;
	i = n, j = m;
	vector<int> fn;
	while (i && j) {
		if (a[i] == b[j]) {
			fn.pb(a[i]);
			--i;
			--j;
		}
		else if (dp[i - 1][j] < dp[i][j - 1])
			--j;
		else --i;
	}
	reverse(fn.begin(), fn.end());
	for (auto i : fn)
		fout << i << " ";
	fin.close();
	fout.close();
	return 0;
}