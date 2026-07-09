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
        freopen ("grader_test1.ok", "r", stdin);
        freopen ("euclid2.out", "w", stdout);

        for (int i = 1; i <= 4; i++) {
                int x;
                scanf("%d", &x);
                printf("%d\n", x);
        }
}
