#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x << " = " << x << "\n";

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

const int max_n = (int)2e3 + 5;

int n, m;

int a[max_n], b[max_n];

int dp[max_n][max_n];

int main() {
  in >> n >> m;
  for (int i = 1; i <= n; i++) {
    in >> a[i];
  }
  for (int j = 1; j <= m; j++) {
    in >> b[j];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i] == b[j]) {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  out << dp[n][m] << "\n";
  int i = n, j = m;
  vector<int> ans;
  while (i > 0 && j > 0) {
    if (dp[i][j] == dp[i - 1][j]) {
      i--;
    } else if (dp[i][j] == dp[i][j - 1]) {
      j--;
    } else {
      ans.push_back(a[i]);
      i--;
      j--;
    }
  }
  reverse(ans.begin(), ans.end());
  for (int val : ans) {
    out << val << " ";
  }
  return 0;
}
