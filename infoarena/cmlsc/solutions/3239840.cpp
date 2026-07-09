#include <bits/stdc++.h>
using namespace std;
// std::string file = "prime";
std::string file = "cmlsc";
std::ifstream fin(file + ".in");
std::ofstream fout(file + ".out");
// #define fin std::cin
// #define fout std::cout
int n, m;
std::vector<int> v1, v2, ans;
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
  for (int i = 0; i <= n; ++i)
    dp[0][i] = 0;
  for (int i = 0; i <= m; ++i)
    dp[1][i] = 0;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
      if (v1[i] == v2[j]) {
        ans.push_back(v1[i]);
        //        dp[i][j]++;
        dp[i][j] = std::max(dp[i][j], dp[i - 1][j - 1] + 1);
      }
    }
  }
  fout << dp[n][m] << "\n";

  //  for (int i = 1; i <= n; ++i) {
  //    for (int j = 1; j <= m; ++j) {
  //      fout << dp[i][j] << " ";
  //    }
  //    fout << "\n";
  //  }
  for (const auto &el : ans) {
    fout << el << " ";
  }
  fout << "\n";
  return 0;
}
