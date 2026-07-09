#include <fstream>
#include <algorithm>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int n,a,b,i;
int euclid(int a,int b)
{
  int r;
  r=1;
  while (r!=0)
  {
    r=a%b;
    a=b;
    b=r;
  }
  return a;
}
int main()
{
  f>>n;
  for (i=1;i<=n;i++)
  {
    f>>a>>b;
    g<<euclid(a,b)<<'\n';

  }
  return 0;
}
