
#include "fstream.h"
int a,b,r,t;
int main()
{ifstream f("euclid2.in");
 ofstream g("euclid2.out");
f>>t;
for(;t>0;t--)
  {f>>a;f>>b;
  while(b!=0)
    {r=a%b;a=b;b=r;}
  g<<a<<endl;}

return 0;}