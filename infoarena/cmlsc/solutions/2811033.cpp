#include <bits/stdc++.h>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n, m;
int a[1025], b[1025], dp[1025][1025];

void read()
{
  f>>n>>m;
  for(int i = 1;i <= n;++i)
    f>>a[i];
  for(int i = 1;i <= m;++i)
    f>>b[i];
}

void reconstruct(int i, int j)
{
  if(i == 0 || j == 0)
    return;
  if(a[i] == b[j])
    {
      reconstruct(i - 1, j - 1);
      g<<a[i]<<" ";
    }
  else
  {
    if(dp[i][j - 1] > dp[i - 1][j])
      reconstruct(i, j - 1);
    else
      reconstruct(i - 1, j);
  }
}

void solve()
{
  for(int i = 1;i <= n;++i)
    for(int j = 1;j <= m;++j)
      if(a[i] == b[j])
        dp[i][j] = dp[i - 1][j - 1] + 1;
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

  g<<dp[n][m]<<'\n';
  reconstruct(n, m);
}

int main()
{
  read();
  solve();
  return 0;
}
