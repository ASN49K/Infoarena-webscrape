#include <iostream>
#include <fstream>
using namespace std;
ifstream f ("euclid2.in");
ofstream g ("euclid2.out");
long cmmdc (long a, long b)
{
    long c;
    while (b)
    {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}
int main()
{long T, a, b, i;
    f>>T;
    for (i=1; i<=T; i++)
    {
        f>>a>>b;
        g<<cmmdc(a, b)<<endl;
    }
    return 0;
}
