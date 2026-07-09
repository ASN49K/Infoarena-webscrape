#include "fstream.h"
long cmmdc(long a,long b)
{int r=a%b;
 while(r)
 {a=b;
  b=r;
  r=a%b;
 }
 return b;
}
int main()
{long a,b,n,m;
 ifstream f("euclid2.in");
 ofstream g("euclid2.out");
 f>>m;
 while(f>>n)
 {a=n;
  f>>b;
  g<<cmmdc(a,b)<<endl;
 }
 return 0;
}