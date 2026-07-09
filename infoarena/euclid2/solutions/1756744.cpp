
#include <stdio.h>

int main() {
    int t, a, b, r;
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &a, &b);
        while (b) {
            r = a % b;
            a = b;
            b = r;
        }
        printf("%d\n", a);
    }
    return 0;
}
