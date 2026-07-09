#include <stdio.h>

int t, a, b, i;

int euclid(int a, int b) {
    int c;
    while (b) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main() {
    freopen ("euclid2.in", "r", stdin);
    freopen ("euclid2.out", "w", stdout);
    scanf ("%d", &t);
    for (i=1; i<=t; ++i) {
        scanf ("%d %d", &a, &b);
        printf ("%d\n", euclid(a, b));
    }
    return 0;
}
