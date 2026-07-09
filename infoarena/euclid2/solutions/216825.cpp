#include "fstream.h"
long cmm(long a,long b)
{long r=a%b;
 while(r)
 {a=b;
  b=r;
  r=a%b;
 }
 return b;
}
int main()
{unsigned long a,b,n;
 ifstream f("euclid2.in");
 ofstream g("euclid2.out");
 f>>n;
 while(f>>n)
{a=n;
 f>>b;
  g<<cmm(a,b)<<"\n";
 }
 return 0;
}

