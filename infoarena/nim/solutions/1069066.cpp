#include <cstdio>

int t, x, i, xsum=0, a;

int main() {

    freopen("nim.in", "r", stdin);
#ifdef INFOARENA
    freopen("nim.out", "w", stdout);
#endif

    scanf("%d", &t);

    while(t--) {
        scanf("%d", &x);

        for (i = 0; i < x; i++) {
            scanf("%d", &a);
            xsum ^= a;
        }

        xsum ? printf("DA\n") : printf("NU\n");
    }

    return 0;
}
