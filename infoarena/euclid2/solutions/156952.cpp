#include <fstream.h>
long a,b,i,t, x,y;
ifstream  f("euclid2.in");
ofstream  g("euclid2.out");
long cmmdc(long a,long b)

{ long r;
 r=a%b;
  while (r)
  { a=b;
  b=r;
  r=a%b;
  }
  return b;
}
int main()
{
 f>>t;
 for (i=1; i<=t;i++){
 f>>x>>y;
 g<<cmmdc(x,y)<<'\n';

 }
 f.close();
 g.close();
return 0;
}