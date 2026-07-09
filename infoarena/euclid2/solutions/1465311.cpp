#include <fstream.h>
using namespace std;
unsigned long div(unsigned long x, unsigned long y)
{
    unsigned int r;
    while (y!=0)
    {
        r=x%y;
        x=y;
        y=r;
    }
    return x;
}
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    unsigned long t, a, b, i;
    f>>t;
    for(i=1; i<=t; i++)
    {   f>>a>>b;
        g<<div(a, b)<<'/n';
    }
    f.close();
    g.close();
    return 0;
}
