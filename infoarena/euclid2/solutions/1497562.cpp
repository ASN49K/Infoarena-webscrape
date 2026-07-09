#include <iostream>

using namespace std;

int tests, t, A, B;

int gcd(int a, int b) {
    int t = 0;
    while (b) {
        t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {

    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    t = 0;
    scanf("%d", &tests);

    while (t++ < tests) {
        scanf("%d %d", &A, &B);
        printf("%d\n", gcd(A, B));
    }
    return 0;
}


