#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>

int dp[1050][1050]; // dp[i][j] = cmlsc pana la i si j
int A[1050], B[1050];

int main () {
	std::ifstream in("cmlsc.in");
	in.exceptions(std::fstream::failbit);
	std::ofstream out("cmlsc.out");
	int n, m;

	in >> n >> m;
	for (int i = 1; i <= n; ++ i)
		in >> A[i];
	for (int i = 1; i <= m; ++ i)
		in >> B[i];

	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= m; ++ j) {
			if (A[i] == B[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
		}

	/*
	for (int i = 0; i <= n; ++ i, std::clog << '\n')
		for (int j = 0; j <= m; ++ j)
			std::clog << dp[i][j] << ' ';
	*/

	out << dp[n][m] << '\n';

	int result[1050];
	int k = dp[n][m];

	for (int i = n, j = m; i >= 1 && j >= 1;) {
		if (A[i] == B[j]) {
			result[k --] = A[i];
			-- i, -- j;
		} else if (i > 1 && dp[i - 1][j] > dp[i][j - 1])
			-- i;
		else
			-- j;
	}

	/*
	std::clog << k << '\n';

	for (int i = 1; i <= dp[n][m]; ++ i)
		std::clog << result[i] << ' ';
	*/
	assert(k == 0);

	for (int i = 1; i <= dp[n][m]; ++ i)
		out << result[i] << ' ';
	out << '\n';
}
