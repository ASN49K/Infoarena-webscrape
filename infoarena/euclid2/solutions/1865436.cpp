#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
unsigned a, b, T;
unsigned cmmdc(unsigned x, unsigned y)
{
    unsigned r=x%y;
    while(r)
    {
        x=y;
        y=r;
        r=x%y;
    }
    return y;
}
int main()
{
    f>>T;
    for(unsigned i=1; i<=T; i++)
    {
        f>>a>>b;
        g<<cmmdc(a,b)<<'\n';
    }
    f.close();
    g.close();
    return 0;
}
