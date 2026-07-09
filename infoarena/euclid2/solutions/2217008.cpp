#include <bits/stdc++.h>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int T;
long long a, b;

long long cmmdc (long long a, long long b)
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
    f>>T;

    for(int i=1; i<=T; i++)
    {
        f>>a>>b;

        g<<cmmdc(a, b)<<'\n';
    }

    return 0;
}
