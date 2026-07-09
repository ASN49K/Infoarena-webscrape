#include <bits/stdc++.h>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
struct solver
{
    int x,y,n;
    solver()
    {
        f>>n;
        for(;n;n--)
        {
            f>>x>>y;
            g<<__gcd(x,y)<<'\n';
        }
    }
}S;

int main()
{
    return 0;
}
