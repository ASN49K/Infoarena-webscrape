#include <fstream>

using namespace std;

static const int MAXN = 1024;

int a[MAXN + 1], b[MAXN + 1];
int dp[MAXN + 1][MAXN + 1];
int ans[MAXN + 1];

int main() {
  ifstream fin("cmlsc.in");
  ofstream fout("cmlsc.out");

  int n, m;
  fin >> n >> m;
  for (int i = 1; i <= n; ++i)
    fin >> a[i];
  for (int j = 1; j <= m; ++j)
    fin >> b[j];

  // DP table: dp[i][j] = LCS length for a[1..i], b[1..j]
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (a[i] == b[j])
        dp[i][j] = dp[i - 1][j - 1] + 1;
      else
        dp[i][j] = (dp[i - 1][j] >= dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
    }
  }

  // Reconstruct one LCS
  int i = n, j = m, k = 0;
  while (i > 0 && j > 0) {
    if (a[i] == b[j]) {
      ans[++k] = a[i];
      --i;
      --j;
    } else if (dp[i - 1][j] >= dp[i][j - 1]) {
      --i;
    } else {
      --j;
    }
  }

  // Output
  fout << dp[n][m] << '\n';
  for (int t = k; t >= 1; --t) {
    if (t != k)
      fout << ' ';
    fout << ans[t];
  }
  fout << '\n';

  return 0;
}
