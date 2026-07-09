#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

static inline int gcd(const int &a, const int &b)
{
    if (!a)
        return b;
    if (!b)
        return a;

    if (a > b)
        return gcd(a % b, b);
    return gcd(a, b % a);
}

static inline void test_case()
{
    int a = 0, b = 0;
    f >> a >> b;

    g << gcd(a, b) << '\n';

    return;
}

int main()
{
    f.tie(nullptr);

    int T = 0;

    f >> T;
    for (int t = 1; t <= T; ++t)
        test_case();

    return 0;
}
