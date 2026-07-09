#include <bits/stdc++.h>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
    int n, x, y;
    f>>n;
    for(int i=0;i<n;i++)
    {
        f>>x>>y;
        g<<__gcd(x, y)<<'\n';
    }
    f.close();
    g.close();
    return 0;
}
