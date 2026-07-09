#include <bits/stdc++.h>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");
int t,x,y;
int main()
{
    f>>t;
    for(;t;t--)
    {
        f>>x>>y;
        g<<__gcd(x,y)<<'\n';
    }
    return 0;
}
