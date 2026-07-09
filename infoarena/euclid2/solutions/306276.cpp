#include <fstream.h>

ifstream f("euclid2.in");
ofstream g("euclid2.out");

long cmmdc (long a, long b)
{ if (b==0) return a;
  return cmmdc(b,a%b);
}

int main ()
{ long t,a,b;
  f>>t;
  for (int i=1; i<=t; i++)
   { f>>a>>b;
     g<<cmmdc(a,b)<<'\n';
   }
  return 0;
}