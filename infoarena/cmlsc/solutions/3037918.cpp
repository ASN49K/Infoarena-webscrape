#include <bits/stdc++.h>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main()
{
  int n, m;
  fin >> n >> m;

  vector<int> vec1(n + 1), vec2(m + 1);

  for (int i = 1; i <= n; i++)
    fin >> vec1[i];
  for (int i = 1; i <= m; i++)
    fin >> vec2[i];

  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
    {
      int maxx = max(dp[i - 1][j], dp[i][j - 1]);
      if (vec1[i] == vec2[j])
        maxx = max(maxx, dp[i - 1][j - 1] + 1);

      dp[i][j] = maxx;
    }

  int i = n, j = m;
  vector<int> res;
  while (i > 0 && j > 0)
  {
    if (vec1[i] == vec2[j])
      res.push_back(vec1[i]), i--, j--;
    else if (dp[i][j - 1] > dp[i - 1][j])
      j--;
    else
      i--;
  }

  fout << dp[n][m] << "\n";
  for (int i = res.size() - 1; i >= 0; i--)
    fout << res[i] << " ";

  return 0;
}