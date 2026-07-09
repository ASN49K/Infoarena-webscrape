#include <bits/stdc++.h>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

long long cmmdc(long long a, long long b)
{
    long long c;
    while(b)
    {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}

long long n,x,y,i;

int main()
{
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>x>>y;
        g<<cmmdc(x,y)<<'\n';
    }
    return 0;
}
