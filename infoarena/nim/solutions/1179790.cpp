#include <cstdio>
using namespace std;

int main () {

    freopen ("nim.in", "r", stdin);
    freopen ("nim.out", "w", stdout);
    int N, M, i, j, x;
    scanf ("%d", &N);
    while (N--) {
        scanf ("%d", &M);
        x = 0;
        for (i = 1; i <= M; ++i) {
            scanf ("%d", &j);
            x ^= j;
        }
        if (x)
            printf ("DA\n");
        else
            printf ("NU\n");
    }

}
