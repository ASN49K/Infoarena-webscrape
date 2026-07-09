#include <bits/stdc++.h>

using namespace std;

int t, a, b;

int gcd(int a, int b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &a, &b);
        printf("%d\n", gcd(a, b));
    }

    return 0;
}
