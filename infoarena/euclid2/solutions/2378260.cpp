#include <bits/stdc++.h>
using namespace std;
unsigned int gcd(unsigned int u, unsigned int v)
{
    unsigned t;
    int shift;
    if (u == 0) return v;
    if (v == 0) return u;
    shift = __builtin_ctz(u | v);
    u >>= __builtin_ctz(u);
    do {
        v >>= __builtin_ctz(v);
        if (u > v) {
            t = v;
            v = u;
            u = t;
        }
        v = v - u;
    } while (v != 0);
    return u << shift;
}
int main(void)
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    unsigned T, A, B;
    scanf("%d", &T);
    while(T)
    {
        scanf("%d%d", &A, &B);
        printf("%d\n",gcd(A,B));
        --T;
    }
    return 0;
}
