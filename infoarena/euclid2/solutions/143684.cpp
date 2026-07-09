#include <fstream.h>

fstream f("euclid2.in");
ofstream g("euclid2.out");

long cmmdc(long x, long y)
{
     if (!y)
       return x;
     return cmmdc(y,x%y);
}

int main()
{
    long a,b;
    f>>a>>b;
    g<<cmmdc(a,b);
}
    
