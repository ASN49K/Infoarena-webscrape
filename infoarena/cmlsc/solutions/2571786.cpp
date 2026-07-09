#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int MAX_N = 1e3 + 5;

int n, m, ans_n;

int dp[MAX_N][MAX_N];

int a[MAX_N], b[MAX_N], ans[MAX_N];

int main() {
  int x, y;
  fin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    fin >> a[i];
  }
  for (int i = 1; i <= m; ++i) {
    fin >> b[i];
  }
  dp[0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (a[i] == b[j]) {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  fout << dp[n][m] << "\n";
  x = n;
  y = m;
  while (x > 0 && y > 0) {
    if (dp[x][y] == dp[x - 1][y]) {
      --x;
    } else if (dp[x][y] == dp[x][y - 1]) {
      --y;
    } else if (dp[x][y] == dp[x - 1][y - 1] + 1) {
      ans[++ans_n] = a[x];
      --x;
      --y;
    }
  }
  reverse(ans + 1, ans + ans_n + 1);
  for (int i = 1; i  <= ans_n; ++i) {
    fout << ans[i] << " ";
  }
  return 0;
}
