#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int x,y;
int cmmdc()
{  int r=x%y;
   while(r)
   { x=y;  y=r;  r=x%y;
   }
   return y;
}
int main()
{  f>>x;
   while(f>>x>>y)
      g<<cmmdc()<<'\n';
   f.close();
   g.close();
   return 0;
}
