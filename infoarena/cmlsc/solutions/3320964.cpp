/// patratele
#include <bits/stdc++.h>
using namespace std;

#define MOD 666013

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int i, n, m, v[1040], s[1040], dp[1040][1040], j;
stack<int> q;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  fin >> n >> m;
  for (i = 1; i <= n; i++)
    fin >> v[i];
  for (i = 1; i <= m; i++)
    fin >> s[i];
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++)
      if (v[i] == s[j])
        dp[i][j] = dp[i - 1][j - 1] + 1;
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
  i = n;
  j = m;
  while (i > 0 && j > 0)
  {
    if (dp[i][j] == dp[i - 1][j - 1] + 1 && v[i] == s[j])
    {
      q.push(v[i]);
      i--;
      j--;
    }
    else if (dp[i - 1][j] >= dp[i][j - 1])
      i--;
    else
      j--;
  }
  fout << dp[n][m] << '\n';
  while (q.size())
  {
    fout << q.top() << " ";
    q.pop();
  }
  return 0;
}
