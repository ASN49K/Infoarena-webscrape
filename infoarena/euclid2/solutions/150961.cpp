#include<fstream.h>
long long a,b;

long long cmmdc(long long a,long long b)
{
  if(!b)
    return a;
  return cmmdc(b,a%b);
}


int main()
{
  ifstream f("euclid2.in");
  ofstream g("euclid2.out");
   f>>a>>b;
   g<<cmmdc(a,b);
 return 0;
}