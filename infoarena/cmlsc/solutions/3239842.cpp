#include <bits/stdc++.h>
using namespace std;

// std::string file = "prime";
std::string file = "cmlsc";
std::ifstream fin(file + ".in");
std::ofstream fout(file + ".out");
// #define fin std::cin
// #define fout std::cout
int n, m;
std::vector<int> v1, v2;
std::vector<std::vector<int>> dp;

int32_t main(int32_t argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  fin.tie(0);
  fout.tie(0);
  fin >> n >> m;
  dp.resize(n + 1, std::vector<int>(m + 1, 0));
  v1.resize(n + 1);
  v2.resize(m + 1);

  for (int i = 1; i <= n; ++i)
    fin >> v1[i];
  for (int i = 1; i <= m; ++i)
    fin >> v2[i];

  // Fill the DP table
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (v1[i] == v2[j]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  fout << dp[n][m] << "\n";

  // Reconstruct the LCS from the DP table
  int i = n, j = m;
  std::vector<int> lcs;
  while (i > 0 && j > 0) {
    if (v1[i] == v2[j]) {
      lcs.push_back(v1[i]);
      i--;
      j--;
    } else if (dp[i - 1][j] >= dp[i][j - 1]) {
      i--;
    } else {
      j--;
    }
  }

  // The LCS was constructed backwards, so reverse it
  reverse(lcs.begin(), lcs.end());

  // Print the LCS
  for (const auto &el : lcs) {
    fout << el << " ";
  }
  fout << "\n";

  return 0;
}
