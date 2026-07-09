#include <bits/stdc++.h>
#define link pair<int, int>
#define x first
#define y second

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n, m;
int c[1025][1025];
int a[1025], b[1025];

void read()
{
  f>>n>>m;
  for(int i = 1;i <= n;++i)
    f>>a[i];
  for(int j = 1;j <= m;++j)
    f>>b[j];
}

void recon(int i, int j)
{
  if(i == 0 || j == 0)
    return;

  if(a[i] == b[j])
    {
      recon(i - 1, j - 1);
      g<<a[i]<<" ";
    }
  else
  {
    if(c[i][j - 1] > c[i - 1][j])
      recon(i, j - 1);
    else
      recon(i - 1, j);
  }
}

void solve()
{
  for(int i = 1;i <= n;++i)
    for(int j = 1;j <= m;++j)
      if(a[i] == b[j])
        c[i][j] = c[i - 1][j - 1] + 1;
      else
        c[i][j] = max(c[i][j - 1], c[i - 1][j]);

  g<<c[n][m]<<'\n';
  recon(n, m);
}


int main()
{
  read();
  solve();
  return 0;
}
