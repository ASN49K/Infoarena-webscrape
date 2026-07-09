#include <iostream>
#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int n;
long long a,b;

int cmmdc(long long x,long long y)
{
    long long t;
    t=1;
    while(y!=0)
    {
        t=y;
        y=x%y;
        x=t;
    }
    return t;
}

int main()
{
    f>>n;
    for(int i=1;i<=n;i++)
    {
        f>>a>>b;
        g<<cmmdc(a,b)<<"\n";
    }
        return 0;
}
