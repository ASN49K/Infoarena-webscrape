#include <bits/stdc++.h>
#define n_max 100001

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int n, m;

void read()
{
  int t;
  int x, y;
  f>>t;
  for(int i = 1;i <= t;++i)
  {
    f>>x>>y;
    int r;
    while(y)
    {
      r = x % y;
      x = y;
      y = r;
    }
    g<<x<<'\n';
  }
}

int main()
{
  read();
  return 0;
}
