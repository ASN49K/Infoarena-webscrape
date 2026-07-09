#include <stdio.h>

int main(int argc, char **argv) {
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    int n, i;
    int a, b, r;
    scanf("%d", &n);

    for (i = 0 ; i < n ; i++) {
        scanf("%d %d", &a, &b);

        do {
            r = a % b;
            a = b;
            b = r;
        } while (r);

        printf("%d\n", a);
    }

	return 0;
}
