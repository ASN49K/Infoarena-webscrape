#include <cstdio>

int main() {
    freopen ("nim.in", "r", stdin);
    freopen ("nim.out", "w", stdout);
    int T, n, v, s;
    scanf ("%d\n", &T);
    while (T--) {
        scanf ("%d\n", &n);
        s = 0;
        for (int i = 0; i < n; ++i) {
            scanf ("%d ", &v);
            s ^= v;
        }
        if (s)
            printf ("DA\n");
        else
            printf ("NU\n");
    }
}
