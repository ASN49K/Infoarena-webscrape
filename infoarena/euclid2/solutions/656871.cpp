#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int x,y,n,i;
int euclid(int a,int b)
{
  int r;
  while (b!=0)
    {
      r=a%b;
      a=b;
      b=r;
    }
  return a;
}
int main()
{
  f>> n;
  for(i=1; i<=n; i++)
    {
      f>>x>>y;
      g<<euclid(x,y)<<'\n';
    }



  f.close();
  g.close();
  return 0;
}
