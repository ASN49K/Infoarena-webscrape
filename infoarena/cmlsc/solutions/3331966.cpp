#include <bits/stdc++.h>
#include <fstream>
#include <vector>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int main() {
  int n, m;
  fin >> n >> m;
  vector<int> v1(n + 1, 0), v2(m + 1, 0);
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
  for (int i = 1; i <= n; i++)
    fin >> v1[i];
  for (int j = 1; j <= m; j++)
    fin >> v2[j];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      if (v1[i] == v2[j])
        dp[i][j] = dp[i - 1][j - 1] + 1;
    }
  }
  fout << dp[n][m] << "\n";
  vector<int> ans;
  int maxx = dp[n][m], x = n, y = m;
  while (x > 0 && y > 0) {
    if (dp[x][y] == maxx && v1[x] == v2[y]) {
      ans.push_back(v1[x]);
      x--;
      y--;
      maxx--;
    } else if (dp[x - 1][y] == maxx)
      x--;
    else if (dp[x][y - 1] == maxx)
      y--;
  }
  for (int i = ans.size() - 1; i >= 0; i--)
    fout << ans[i] << " ";
  return 0;
}
