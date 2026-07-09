#include <bits/stdc++.h>
#define N 1030

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int A[N], B[N], dp[N][N], n, m, v[N], k;
void read() {
	fin >> m >> n;
	for (int i = 1; i <= m; ++i)
		fin >> A[i];
	for (int i = 1; i <= n; ++i)
		fin >> B[i];
}
void dinamica() {
	for(int i=1;i<=m;++i)
		for (int j = 1; j <= n; ++j) {
			if (A[i] == B[j])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	for (int i = m, j = n; i;) {
		if (A[i] == B[j])
			v[++k] = A[i], --i, --j;
		else if (dp[i - 1][j] < dp[i][j - 1])
			--j;
		else
			--i;
	}
	fout << k << "\n";
	for (int i = k; i >= 1; --i)
		fout << v[i] << " ";
}
int main() {
	read();
	dinamica();
	return 0;
}