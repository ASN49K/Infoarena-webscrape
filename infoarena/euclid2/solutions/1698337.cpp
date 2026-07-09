#include <iostream>
#include <fstream>
using namespace std;
long long a,b,n;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
long long euclid(long long a, long long b)
{
    long long r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    f>>n;
    for(int i=1;i<=n;i++)
    {
        f>>a>>b;
        g<<euclid(a,b)<<'\n';
    }
    return 0;
}
