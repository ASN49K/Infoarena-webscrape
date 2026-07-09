#include <cstdio>

int cmmdc (int a, int b) {
    int r;
    while (b) {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main () {
    freopen ("euclid2.in", "r", stdin);
    freopen ("euclid2.out", "w", stdout);

    int T, A, B;
    scanf ("%d", &T);
    while (T--) {
        scanf ("%d%d", &A, &B);
        printf ("%d\n", cmmdc (A, B));
    }

    return 0;
}

