#include <bits/stdc++.h>
using namespace std;

//int v[500005];

int main() {
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    int n, m, r, q;
    scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        scanf("%d", &n);
        scanf("%d", &m);
        while (m) {
            r = n % m;
            n = m;
            m = r; }
        printf("%d\n", n); }
    return 0; }
