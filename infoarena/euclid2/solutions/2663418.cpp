#include <bits/stdc++.h>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main()
{
    int n;
    f>>n;
    while(n--)
    {
        int x,y;
        f>>x>>y;
        g<<__gcd(x,y)<<'\n';
    }
    return 0;
}
