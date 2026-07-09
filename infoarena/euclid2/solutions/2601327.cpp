#include <bits/stdc++.h>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
long long T,a,b;
int main()
{
    f>>T;
    while(T--)
    {
        f>>a>>b;
        g<<__gcd(a,b)<<'\n';
    }
    f.close();
    g.close();
    return 0;
}
