#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);

	int M, N;
	cin >> M >> N;
	
	vector<int> A(M + 1);
	for (int i = 1; i <= M; i++)
		cin >> A[i];
		
	vector<int> B(N + 1);
	for (int i = 1; i <= N; i++)
		cin >> B[i];
		
	vector<vector<int>> dp(M + 1, vector<int>(N + 1, 0));
	for (int i = 1; i <= M; i++)
		for (int j = 1; j <= N; j++) {
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			if (A[i] == B[j])
				dp[i][j] = max(dp[i][j], 1 + dp[i - 1][j  - 1]);
		}

	cout << dp[M][N] << "\n";

	vector<int> solution;
	int i = M, j = N;
	while (i >= 1 && j >= 1) {
		if (A[i] == B[j]) {
			solution.push_back(A[i]);
			i--, j--;
		} else if (dp[i - 1][j] >= dp[i][j - 1]) {
			i--;
		} else {
			j--;
		}
	}

	reverse(solution.begin(), solution.end());
	for (auto element : solution)
		cout << element << " ";

	return 0;
}