#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int main() {
  int n, m;
  f >> n >> m;
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
  vector<int> arr1(n), arr2(m);
  vector<int> ans;
  for (int i = 0; i < n; i++)
    f >> arr1[i];
  for (int i = 0; i < m; i++)
    f >> arr2[i];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      if (arr1[i - 1] == arr2[j - 1])
        dp[i][j] = dp[i - 1][j - 1] + 1;
    }
  }
  g << dp[n][m] << "\n";
  int inx = n, iny = m;
  while (inx && iny) {
    if (arr1[inx - 1] == arr2[iny - 1]) {
      ans.push_back(arr1[inx - 1]);
      inx--;
      iny--;
    } else if (dp[inx - 1][iny] < dp[inx][iny - 1])
      iny--;
    else
      inx--;
  }
  for (int i = ans.size() - 1; i >= 0; i--)
    g << ans[i] << " ";
}
