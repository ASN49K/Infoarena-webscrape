#include <bits/stdc++.h>

using namespace std;

int n, t;

int main() {
    freopen("nim.in", "r", stdin);
    freopen("nim.out", "w", stdout);
    scanf("%d", &t);
    while (t --) {
        scanf("%d", &n);
        int xorSum = 0;
        for (int i = 1; i <= n; ++i) {
            int value;
            scanf("%d", &value);
            xorSum ^= value;
        }
        if (xorSum > 0) {
            printf("DA\n");
        } else {
            printf("NU\n");
        }
    }
    return 0;
}
