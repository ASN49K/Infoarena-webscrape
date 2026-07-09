#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef INFOARENA
  freopen ("cmlsc.in", "r", stdin);
  freopen ("cmlsc.out", "w", stdout);
#else
  freopen ("input.txt", "r", stdin);
#endif // INFOARENA

  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  for (auto &x : a) {
    cin >> x;
  }
  for (auto &x : b) {
    cin >> x;
  }
  vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i - 1] == b[j - 1]) {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  vector<int> sol;
  while (n && m) {
    if (a[n - 1] == b[m - 1]) {
      sol.push_back(a[n - 1]);
      n--;
      m--;
    } else {
      if (dp[n - 1][m] > dp[n][m - 1]) {
        n--;
      } else {
        m--;
      }
    }
  }
  reverse(sol.begin(), sol.end());
  cout << (int) sol.size() << "\n";
  for (auto &x : sol) {
    cout << x << " ";
  }
  cout << "\n";
  return 0;
}
