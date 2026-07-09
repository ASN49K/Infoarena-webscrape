#include <bits/stdc++.h>

using namespace std;

int main()
{
        int n,a,b;
        ifstream f("euclid2.in");
        ofstream g("euclid2.out");
        f>>n;
        for(int i=1; i<=n; ++i)
        {
            f>>a>>b;
            g<<__gcd(a,b)<<'\n';
        }
    return 0;
}
