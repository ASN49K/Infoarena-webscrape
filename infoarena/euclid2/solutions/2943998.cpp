#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    int T;
    scanf("%d", &T);
    while(T--) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d %d\n", a, b);
    }

    return 0;
}
