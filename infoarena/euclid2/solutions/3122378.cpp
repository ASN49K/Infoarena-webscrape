#include <bits/stdc++.h>
using namespace std;
int t, a, b;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
    f >> t;
    for(int i = 1; i <= t; ++i)
    {
        f >> a >> b;
        g << __gcd(a, b) << '\n';
    }
    return 0;
}
