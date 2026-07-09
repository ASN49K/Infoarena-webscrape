#include <cstdio>

int t, x, i, xsum, a;

int main() {

    freopen("nim.in", "r", stdin);
#ifdef INFOARENA
    freopen("nim.out", "w", stdout);
#endif

    scanf("%d", &t);

    while(t--) {
        scanf("%d", &x);
        xsum = 0;

        for (i = 0; i < x; i++) {
            scanf("%d", &a);
            xsum ^= a;
        }

        printf(xsum ? "DA\n" :"NU\n");
    }

    return 0;
}
