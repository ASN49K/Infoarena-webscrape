#include <iostream>
#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int cmmdc(int a, int b)
{
      int r;
      while(b)
      {
          r=a%b;
          a=b;
          b=r;
      }
      return a;
}
int a,b,nr;
int main()
{

f>>nr;
for(int i=0;i<nr;i++)
{
    f>>a>>b;
    g<<cmmdc(a,b)<<'\n';
}

    return 0;
}
