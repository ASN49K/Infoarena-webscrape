#include <bits/stdc++.h>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int T, A, B;

static inline int gcd (int a, int b)
{
    int r = 0;

    while(b)
    {
        r = a % b;

        a = b;

        b = r;
    }

    return a;
}

static inline void Test_Case ()
{
    f >> A >> B;

    g << gcd(A, B) << '\n';

    return;
}

int main()
{
    f.tie(NULL);

    f >> T;

    while(T--)
        Test_Case();

    return 0;
}
