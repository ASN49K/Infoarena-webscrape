#include <bits/stdc++.h>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int n,x,y;

int main()
{
    f>>n;
    for(int i=1;i<=n;i++)
    {
        f>>x>>y;
        g<<__gcd(x,y)<<'\n';
    }
    return 0;
}
