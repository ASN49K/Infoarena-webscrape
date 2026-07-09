#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b, a % b);
}

int main() {
    int T, a, b;

    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    for (scanf("%d", &T); T; --T) {
        scanf("%d %d", &a, &b);
        printf("%d\n", gcd(a, b));
    }

    return 0;
}