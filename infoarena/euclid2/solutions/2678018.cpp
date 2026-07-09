#include <bits/stdc++.h>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
long long x,y,i,n;
int main()
{
    f>>n;
    for (i=1;i<=n;i++)
    {
        f>>x>>y;
        g<<__gcd(x,y)<<'\n';
    }
    return 0;
}
