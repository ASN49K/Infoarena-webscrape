#include <iostream>
#include <fstream>
using namespace std;
ifstream InF ("euclid.in");
ofstream OutF ("euclid.out");
unsigned T,a,b;
unsigned i;
unsigned GCD (unsigned a,unsigned b);
int main()
{   InF>>T;
    for (i=1;i<=T;i++)
    {
        InF>>a>>b;
        OutF<<GCD (a,b)<<"/n";
    }

    return 0;
}
unsigned GCD(unsigned x,unsigned y)
{
    unsigned r;
    r=0;
    while (y!=0)
        {r=x%y;
        x=y;
        y=r;
        }
    return x;
}
