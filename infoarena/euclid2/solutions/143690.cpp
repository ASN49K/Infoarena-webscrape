#include <fstream.h>

fstream f("euclid2.in");
ofstream g("euclid2.out");


int main()
{
    long a,b,d;
    f>>a>>b;
    while (d!=0)
    {
          d=a%b;
          a=b;
          b=d;
    }
    g<<a;
}
    
