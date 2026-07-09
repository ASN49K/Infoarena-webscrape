#include <fstream.h>

fstream f("euclid2.in");
ofstream g("euclid2.out");

long cmmdc(long x, long y)
{
     if (x==0)
       return x;
     cmmdc(x,x%y);
}

int main()
{
    long a,b;
    f>>a>>b;
    g<<cmmdc(a,b);
}
    
