#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int cmmdc(int x,int y)
{ long r,a,b;
  a=x; b=y; r=a%b;
  while(r!=0)
  {  a=b;
     b=r;
     r=a%b;
  }
  g<<b<<endl;
}
int main()
{
   long x,y;
   f>>x;
   while(f>>x>>y)
     cmmdc(x,y);
   f.close();
   g.close();
   return 0;
}
