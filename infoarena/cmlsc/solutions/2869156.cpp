#include <bits/stdc++.h>
using namespace std;

ifstream fin("kfib.in");
ofstream fout("kfib.out");

const int MAXN = 1025;

int A[MAXN], B[MAXN];
int dp[MAXN][MAXN];

int main() {
	int n, m;
	fin >> n >> m;
	for(int i = 1; i <= n; i++)
		fin >> A[i];
	for(int i = 1; i <= m; i++)
		fin >> B[i];

	// dp[i][j] = lungimea maxima a unui subsir comun in [1..i] si [1..j]

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(A[i] == B[j])
				dp[i][j] = dp[i-1][j-1] + 1;
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

	vector<int> answer;
	int i = n, j = m;
	while(i > 0 && j > 0) {
		if(A[i] == B[j]) {
			answer.emplace_back(A[i]);
			i--;
			j--;
		}
		else if(dp[i-1][j] > dp[i][j-1])
			i--;
		else
			j--;
	}

	fout << dp[n][m] << '\n';
	reverse(answer.begin(), answer.end());
	for(int num : answer)
		fout << num << ' ';
	fout << '\n';

	return 0;
}
