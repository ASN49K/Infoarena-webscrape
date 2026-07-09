
#include <fstream.h>
#include<iostream.h>

int main()
{
 ifstream f("euclid2.in");
  ofstream g("euclid2.out");
  int t,r,a,i,b;
  f>>t;
  if(t<=100000 && t>=1)
  for(i=1;i<=t;i++)
  { while(b!=0)
  {r=a%b;
  a=b;
  b=r;
   }
  f>>a>>b;
  g<<a<<"\n"; }
  f.close();
  g.close();
  return 0;
  }
