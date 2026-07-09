#include <cstdio>

int n;

int main() {
    int a, b, r;
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    scanf("%d\n", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d\n", &a, &b);
        while (b) {
            r = a % b;
            a = b;
            b = r;
        }
        printf("%d\n", a);
    }

    fclose(stdout);
    return 0;
}
