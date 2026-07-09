#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
    if (!a || !b)
        return a + b;

    if (a == b)
        return a;

    if (~a & 1)
    {
        if (~b & 1)
            return 2 * gcd(a >> 1, b >> 1);
        else
            return gcd(a >> 1, b);
    }
    else
    {
        if (~b & 1)
            return gcd(a, b >> 1);
    }

    if (a > b)
        return gcd((a - b) >> 1, b);
    else
        return gcd((b - a) >> 1, a);
}

int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");

    int T, a, b;

    in >> T;

    while (T--)
    {
        in >> a >> b;
        out << gcd(a, b) << "\n";
    }

    return 0;
}
