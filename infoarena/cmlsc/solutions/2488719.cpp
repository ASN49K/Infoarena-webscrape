#include <bits/stdc++.h>

const int MAX_N = 1030;

int n, m;

std::vector<int> a(MAX_N), b(MAX_N);

int dp[MAX_N][MAX_N];

int main() {
  freopen("cmlsc.in", "r", stdin);
  freopen("cmlsc.out", "w", stdout);
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= m; ++i) {
    scanf("%d", &b[i]);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (a[i] == b[j]) {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      } else {
        dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j]);
      }
    }
  }
  std::vector <int> ans;
  int i = n, j = m;
  while (i > 0 && j > 0) {
    if (dp[i][j] == dp[i - 1][j]) {
      --i;
    } else if (dp[i][j] == dp[i][j - 1]) {
      --j;
    } else {
      ans.push_back(a[i]);
      --i;
      --j;
    }
  }
  printf("%d\n", dp[n][m]);
  reverse(ans.begin(), ans.end());
  for (int value : ans) {
    printf("%d ", value);
  }
  return 0;
}
