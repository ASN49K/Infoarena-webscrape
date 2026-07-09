#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

static inline int gcd(int a, int b)
{
    if (!a)
        return b;
    if (!b)
        return a;

    if (a > b)
        return gcd(a % b, b);
    return gcd(a, b % a);
}

int main()
{
    f.tie(nullptr);

    int t = 0;
    f >> t;
    for (int q = 1; q <= t; ++q)
    {
        int a = 0, b = 0;
        f >> a >> b;

        g << gcd(a, b) << '\n';
    }

    return 0;
}
