/// Craciun Catalin
///  Euclid2
///   www.infoarena.ro/problema/euclid2
#include <fstream>
#include <iostream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

long t;

long euclid(long a, long b)
{
    while (b!=0)
    {
        long r=a%b;
        a=b;
        b=r;
    }

    return a;
}

int main()
{
    f>>t;
    for (long i=1;i<=t;i++)
    {
        long a,b;
        f>>a>>b;
        g<<euclid(a,b)<<'\n';
    }

    f.close();
    g.close();

    return 0;
}
