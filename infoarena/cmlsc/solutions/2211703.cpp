#include <bits/stdc++.h>

using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

int n, m, sol[1025], nr;
int a[1025], b[1025];
int dp[1025][1025];

int main()
{
  fin >> n >> m;
  for (int i = 1; i <= n; i++)
    fin >> a[i];
  for (int j = 1; j <= m; j++)
    fin >> b[j];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (a[i] == b[j])
        dp[i][j] = dp[i - 1][j - 1] + 1;
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
  int i = n, j = m;
  while (i && j) {
    if (a[i] == b[j]) {sol[++nr] = a[i]; i--; j--;}
    if (dp[i - 1][j] < dp[i][j - 1])
      j--;
    else
      i--;
  }
  fout << dp[n][m] << "\n";
  for (int i = nr; i >= 1; i--)
    fout << sol[i] << " ";
  return 0;
}
