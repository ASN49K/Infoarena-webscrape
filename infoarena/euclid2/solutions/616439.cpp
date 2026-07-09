
#include <fstream.h>
#include<iostream.h>

int cmmdc (int a, int b)
{ if (!b)  return b;
       return cmmdc (b, a%b);
}

int main()
{
 ifstream f("euclid2.in");
  ofstream g("euclid2.out");
  int t,a,b;
  f>>t;
  for(t;t;--t)
  { f>>a>>b;
  g<<cmmdc(a,b)<<"\n"; }
  f.close();
  g.close();
  return 0;
  }
