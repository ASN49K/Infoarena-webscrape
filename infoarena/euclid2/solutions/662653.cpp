#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
void euclid (int x, int y)
{
   int z;
    while (y!=0)
    {
        z=x%y;
        x=y;
        y=z;
    }
g<<x;
}
int x,y,n,i;
int main()
{
  f>>n;
  for (i=1;i<=n;i++)
  {
      f>>x>>y;
      euclid(x,y);
      g<<'\n';
  }
return 0;
}
