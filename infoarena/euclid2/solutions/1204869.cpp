#include<iostream>
#include<fstream>
 typedef unsigned long ulong;
using namespace std;

ulong cmmdc( ulong a, ulong b)
{
    if (!b)
        return a;
    else
        return cmmdc(b, a%b);
}

int main()
{
    ulong t,a,b,c,i;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
f>>t;
    for (i=1;i<=t;i++)
    {
        f>>a>>b;
        g<<cmmdc(a,b)<<'/n';
    }

    f.close();
    g.close();
    return 0;
}
