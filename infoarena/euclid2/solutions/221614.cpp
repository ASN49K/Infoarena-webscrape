#include <fstream.h>
ifstream f("euclid2.in");
ofstream g("euclid2.out");
long x,y,a,b,t,i;
int main ()
{
f>>t;
for (i=1;i<=t;i++)
    {
    f>>a>>b;
    x=a;
    y=b;
    while (x!=y)
    if (x>y)
       x=x-y;
       else
       y=y-x;
    g<<x<<'\n';
    }
f.close ();
g.close ();
return 0;
}