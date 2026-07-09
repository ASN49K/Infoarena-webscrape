#include <bits/stdc++.h>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int n;
long x,y;
int cmmdc(long a, long b)
{
  long c=max(a,b);
  long d=min(a,b);
  long r=c%d;
  while(r!=0)
  {  c=d;
     d=r;
     r=c%d;
  }
 return d;
}
int main()
{ f>>n;
 for(int i=1;i<=n;i++)
 { f>>x>>y;
   g<<cmmdc(x,y)<<'\n';
 }

    return 0;
}
