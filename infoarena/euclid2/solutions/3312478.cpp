#include <bits/stdc++.h>

int gcd(int a, int b) {
    if (!b) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    #ifndef LOCAL
        freopen("euclid2.in", "r", stdin);
        freopen("euclid2.out", "w", stdout);
    #endif
    int T;
    std::cin >> T;
    for (
        ;
        T--
        ;
    ) {
        int A;
        int B;
        std::cin >> A >> B;
        std::cout << gcd(A, B) << "\n";
    }
    return 0;
}