#include <fstream>
#include <algorithm>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int y,x,i,n,r;
int main()
{

    f>>n;
    for (i=1;i<=n;i++)
     {
         f>>x>>y;
          if (y<x)swap(y,x);
         while (x)
         {
             r=y%x;
             y=x;
             x=r;

         }
         g<<y<<'\n';
     }
     f.close();
     g.close();
}
