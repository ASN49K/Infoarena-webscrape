#include <bits/stdc++.h>
#define dbg() cerr <<
#define name(x) (#x) << ": " << (x) << ' ' <<

using namespace std;

const int NMAX = 1024;

int a[NMAX], b[NMAX], ans[NMAX];
int dp[NMAX][NMAX];

int DP(int i, int j) {
  if (i < 0 || j < 0) return 0;
  return dp[i][j];
}

int main() {
  ifstream cin("cmlsc.in");
  ofstream cout("cmlsc.out");

  int n, m; cin >> n >> m;
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  for (int i = 0; i < m; ++i)
    cin >> b[i];

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i] == b[j]) {
        dp[i][j] = DP(i - 1, j - 1) + 1;
      } else {
        dp[i][j] = max(DP(i, j - 1), DP(i - 1, j));
      }
    }
  }

  cout << dp[n - 1][m - 1] << endl;

  int i = n - 1, j = m - 1, len = 0;
  while (i >= 0 && j >= 0) {
    if (a[i] == b[j]) {
      ans[len++] = a[i];
      --i, --j;
    } else {
      if (dp[i][j] == DP(i - 1, j)) --i;
      else --j;
    }
  }

  for (int i = len - 1; i >= 0; --i) {
    cout << ans[i] << ' ';
  }
  cout << endl;
}
