#include <stdio.h>

int cmmdc(int n, int m) {
    for(int r; m != 0; n = m, m = r)
        r = n % m;

    return n;
}

int main(void) {
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    
    int n;
    scanf("%d", &n);

    for(int a, b, i = 0; i < n; ++i) {
        scanf("%d%d", &a, &b);
        printf("%d\n", cmmdc(a, b));
    }

    return 0;
}