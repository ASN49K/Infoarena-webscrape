#include <bits/stdc++.h>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
// #define f cin
// #define g cout
int gcd(int a, int b)
{
    if (!a || !b)
        return a | b;
    unsigned shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    do
    {
        b >>= __builtin_ctz(b);
        if (a > b)
            swap(a, b);
        b -= a;
    } while (b);
    return a << shift;
}
int main()
{
    ios_base::sync_with_stdio(false);
    f.tie(nullptr);
    g.tie(nullptr);
    int q;
    f >> q;
    for (int x, y; q; q--)
    {
        f >> x >> y;
        g << gcd(x, y) << '\n';
    }
    return 0;
}
