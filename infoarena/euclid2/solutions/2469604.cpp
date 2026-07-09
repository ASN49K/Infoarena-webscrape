#include<bits/stdc++.h>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
long long x, y, n;
long long cmmdc(long long a, long long b)
{
    while(b)
    {
        long long r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    f>>n;
    for(int i=1; i<=n; i++)
    {
        f>>x>>y;
        g<<cmmdc(x, y)<<'\n';
    }
    return 0;
}
