#include <iostream>
#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

void euclid(int a, int b)
{
  while(a != b)
  {
    if(a < b)
      b -= a;
    else a-=b;
  }
 g<<a<<'\n';
}

int main()
{
  int n, x ,y;
  f>>n;
  for(int i = 1; i <= n ; i++)
    { f>>x>>y;
      euclid(x,y);
    }
    return 0;
}
