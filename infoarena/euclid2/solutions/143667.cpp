#include <fstream.h>

fstream f("euclid2.in");
fstream g("euclid2.out");

int main()
{
    int a,b;
    f>>a>>b;
    while (a!=b)
       if (a>b)
          a=a-b;
       else
          b=b-1;
   g<<a;
}
    
