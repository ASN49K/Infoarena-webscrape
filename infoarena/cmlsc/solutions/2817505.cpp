#include <bits/stdc++.h>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n, m;
int a[1025], b[1025], c[1025][1025];

void read()
{
  f>>n>>m;
  for(int i = 1;i <= n;++i)
    f>>a[i];
  for(int j = 1;j <= m;++j)
    f>>b[j];
}

void reconstruct(int i, int j)
{
  if(!i || !j)
    return;

  if(a[i] == b[j])
    {
      reconstruct(i - 1, j - 1);
      g<<a[i]<<" ";
    }
  else{
    if(c[i - 1][j] > c[i][j - 1])
      reconstruct(i - 1, j);
    else
      reconstruct(i, j - 1);
  }
}

void solve()
{
  for(int i = 1;i <= n;++i)
    for(int j = 1;j <= m;++j)
      if(a[i] == b[j])
        c[i][j] = c[i - 1][j - 1] + 1;
      else
        c[i][j] = max(c[i - 1][j], c[i][j - 1]);

  g<<c[n][m]<<'\n';
  reconstruct(n, m);
}

int main()
{
  read();
  solve();
  return 0;
}
