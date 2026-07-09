#include <bits/stdc++.h>
#define link pair<int, int>
#define x first
#define y second

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int n, x, y;

int euclid(int x, int y)
{
  if(!y)
    return x;
  return euclid(y, x % y);   
}

void read()
{
  f>>n;
  for(int i = 1;i <= n;++i)
    f>>x>>y, g<<euclid(x, y)<<'\n';
}
    


int main()
{
  read();
  return 0;
}
