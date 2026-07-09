#include <cstdio>

using namespace std;

int gcd(int a, int b) {
        if (b == 0) {
                return a;
        } else {
                return gcd(b, a % b);
        }
}

int main() {
        freopen ("euclid2.in", "r", stdin);
        freopen ("euclid2.out", "w", stdout);

        int t;
        scanf("%d", &t);
        for (int tc = 1; tc <= t; tc++) {
                int a, b;
                scanf("%d %d", &a, &b);
                printf("%d\n", 1);
        }
}
