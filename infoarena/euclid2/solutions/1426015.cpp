#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int Cmmdc(int x,int y)
{
  int r;
  r=1;
  while(r>0)
   {
     r=x%y;
     x=y;
     y=r;
   }
   return x;
}

int main()
{
    int t,i,x,y;
    f>>t;
    for(i=1; i<=t; i++)
      {
        f>>x>>y;
        g<<Cmmdc(x,y)<<'\n';
      }

f.close();
g.close();

    return 0;
}
