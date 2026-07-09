#include <fstream.h>
ifstream f("euclid2.in");
ofstream g("euclid2.out");
long x,y,a,b,t,i,z;
int main ()
{
f>>t;
for (i=1;i<=t;i++)
    {
    f>>a>>b;
    x=a;
    y=b;
   if (y>x)
      {
      z=x;
      x=y;
      y=z;  }
    z=x%y;
    while (z!=0)
   { x=y;
       y=z;
       z=x%y;}
    g<<y<<'\n';
    }

f.close ();
g.close ();
return 0;
}