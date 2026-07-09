#include <iostream>
#include <fstream>
using namespace std;

long long euclid(long long a,long long b)
{
    long long t;
    while(a)
    {
        t=a;
        a=b%a;
        b=t;
    }
    return b;
}

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    long T,i;
    long long a,b;
    f>>T;
    for (i=0;i<T;i++)
    {
        f>>a>>b;
        g<<euclid(a,b)<<'\n';
    }
    f.close();
    g.close();
    return 0;
}
