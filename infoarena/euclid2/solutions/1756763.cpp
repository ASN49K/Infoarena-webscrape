
#include <stdio.h>

using namespace std;

int gcd(int u, int v)
{
    // simple cases (termination)
    if (u == v)
        return u;

    if (u == 0)
        return v;

    if (v == 0)
        return u;

    // look for factors of 2
    if (~u & 1) // u is even
    {
        if (v & 1) // v is odd
            return gcd(u >> 1, v);
        else // both u and v are even
            return gcd(u >> 1, v >> 1) << 1;
    }

    if (~v & 1) // u is odd, v is even
        return gcd(u, v >> 1);

    // reduce larger argument
    if (u > v)
        return gcd((u - v) >> 1, v);

    return gcd((v - u) >> 1, u);
}

int main() {
    int t, a, b, r;
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &a, &b);
        /*while (b) {
            r = a % b;
            a = b;
            b = r;
        }*/
        printf("%d\n", gcd(a,b));
    }
    return 0;
}
