#include <bits/stdc++.h>

using namespace std;

int main()
{
    fstream f("euclid2.in");
    ofstream g("euclid2.out");
    int n, a, b;
    f>>n;
    for(int i = 0; i < n; i++)
    {
        f>>a>>b;
        g<<__gcd(a, b)<<'\n';
    }
    f.close();
    g.close();
    return 0;
}
