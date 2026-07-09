#include <cstdio>
#include <fstream>
#include <algorithm>

using namespace std;
int v[1025][2];
int dp[1025][1025];
int main() {
	ifstream fin("cmlsc.in");
	ofstream fout("cmlsc.out");	
	int n, m;
	fin >> n >> m;
	int i, j, k;
	for (i = 1; i <= n; ++i) fin >> v[i][0];
	for (i = 1; i <= m; ++i) fin >> v[i][1];
	for (i = 1; i <= n; ++i) 
	for (j = 1; j <= m; ++j) {
		dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		if (v[i][0] == v[j][1]) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
	}	
	fout << dp[n][m] << '\n';
	k = 0;
	int aux[1025];
	while (n != 0 && m != 0) {
		if (v[n][0] == v[m][1]) {n--; m--; aux[++k]=v[n+1][0];continue;}
		if (dp[n-1][m] > dp[n][m-1]) {n--; continue;}
		m--;
	}
	while (k--) {fout << aux[k+1] << ' ';}
	fout << '\n';
	return 0;
}
