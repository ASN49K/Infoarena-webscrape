#include <cstdio>

int T, N;

int main () {
    freopen ("nim.in", "r", stdin);
    freopen ("nim.out", "w", stdout);

    scanf ("%d", &T);
    while (T--) {
        int S = 0;
        scanf ("%d", &N);
        while (N--) {
            int X;
            scanf ("%d", &X);
            S ^= X;
        }

        if (S == 0) {
            printf ("NU");
        }
        else {
            printf ("DA");
        }
        printf ("\n");
    }

    return 0;
}
