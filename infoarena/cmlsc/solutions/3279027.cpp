#include <bits/stdc++.h>

std::ifstream fin("cmlsc.in");
std::ofstream fout("cmlsc.out");

int main() {
    int n, k;
	fin >> n >> k;

	std::vector<int> a(n + 1), b(k + 1);

	for (int i = 1; i <= n; i++) {
		fin >> a[i];
	}

	for (int i = 1; i <= k; i++) {
		fin >> b[i];
	}

	std::vector<std::vector<int>> dp(n + 1, std::vector<int>(k + 1, 0));

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= k; ++j) {
			if (a[i] == b[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	}

	std::vector<int> result;

	for (int i = n, j = k; i >= 1 && j >= 1; --i, --j) {
		if (a[i] == b[j]) {
			result.push_back(a[i]);
		} // Continuam unde lungimea sirului este mai mare
		else if (dp[i - 1][j] < dp[i][j - 1]) {
			--j;
		}
		else {
			--i;
		}
	}

	fout << result.size() << '\n';
	for (int i = result.size() - 1; i >= 0; --i)
		fout << result[i] << ' ';
    return 0;
}
