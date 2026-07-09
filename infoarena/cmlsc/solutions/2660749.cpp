#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

const int NMAX = 1024;

int n, m;
int a[1 + NMAX], b[1 + NMAX];
int dp[1 + NMAX][1 + NMAX];
std::vector<int> sol;

void read() {
  std::ifstream in("cmlsc.in");

  in >> n >> m;
  for (int i = 1; i <= n; ++i)
    in >> a[i];

  for (int i = 1; i <= m; ++i)
    in >> b[i];
}

int main() {
  read();

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (a[i] == b[j])
        dp[i][j] = dp[i - 1][j - 1] + 1;
      else
        dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
    }
  }

  int i = n, j = m;
  while (i > 0 && j > 0) {
    if (a[i] == b[j]) {
      sol.emplace_back(a[i]);
      --i;
      --j;
    } else if (dp[i - 1][j] > dp[i][j - 1])
      --i;
    else
      --j;
  }

  std::ofstream out("cmlsc.out");

  std::reverse(sol.begin(), sol.end());
  out << dp[n][m] << '\n';
  for (int el : sol)
    out << el << ' ';

  return 0;
}
