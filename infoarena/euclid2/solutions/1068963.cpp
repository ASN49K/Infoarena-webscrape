#include <cstdio>

int t, a, b;

int cmmdc(int a, int b) {
    if (b)
        return cmmdc(b, a % b);
    return a;
}

int main() {

    freopen("euclid2.in", "r", stdin);
#ifdef INFOARENA
    freopen("euclid2.out", "w", stdout);
#endif

    scanf("%d", &t);

    while(t--) {
        scanf("%d%d", &a, &b);
        printf("%d\n", cmmdc(a, b));
    }
}
