#include <bits/stdc++.h>
using namespace std;

int main(){

    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);

    int n, m, r, x;
    scanf("%d", &x);

    for(int i = 1; i <= x; ++i) {
        scanf("%d %d", &n, &m);
        while (m) {
            r = n % m;
            n = m;
            m = r; }

        printf("%d\n", n); }

    return 0; }
