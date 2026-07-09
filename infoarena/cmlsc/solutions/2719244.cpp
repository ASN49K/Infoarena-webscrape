#include <bits/stdc++.h>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n, m, a[1030], b[1030], dp[1030][1030];

void Read()
{
  f>>n>>m;
  for(int i = 1;i <= n;++i)
    f>>a[i];
  for(int j = 1;j <= m;++j)
    f>>b[j];
}

void recon(int i, int j)
{
  if(i > 0 && j > 0)
  {
    if(a[i] == b[j])
      {
        recon(i - 1, j - 1);
        g<<a[i]<<" ";
      }
    else
    {
      if(dp[i - 1][j] > dp[i][j - 1])
        recon(i - 1, j);
      else
        recon(i, j - 1);
    }
  }
}

void Solve()
{
  for(int i = 1;i <= n;++i)
    for(int j = 1;j <= m;++j)
      if(a[i] == b[j])
        dp[i][j] = dp[i - 1][j - 1] + 1;
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
  g<<dp[n][m]<<'\n';
  recon(n, m);
}

int main()
{
  Read();
  Solve();
  return 0;
}
