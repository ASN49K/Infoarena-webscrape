#include<fstream.h>
long long a,b;

long long cmmdc(long long a,long long b)
{
  if(a>b)
   return cmmdc(a-b,b);
  else
   if(b>a)
    return cmmdc(a,b-a);
   else
    return a;
}


int main()
{
  ifstream f("euclid2.in");
  ofstream g("euclid2.out");
   f>>a>>b;
   g<<cmmdc(a,b);
 return 0;
}