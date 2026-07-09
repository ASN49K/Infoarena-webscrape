#include <bits/stdc++.h>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int t,a,b;
int main()
{
    f>>t;
    for(;t;t--)
    {
        f>>a>>b;
        g<<__gcd(a,b)<<'\n';
    }
    return 0;
}

