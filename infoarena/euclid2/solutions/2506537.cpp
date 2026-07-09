#include <bits/stdc++.h>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int x,y,t;
int main()
{
    f>>t;
    for(int i=1;i<=t;i++)
    {
        f>>x>>y;
        g<<__gcd(x,y)<<'\n';
    }
    return 0;
}
