#include <bits/stdc++.h>

int main() {
    std::ifstream cin("euclid2.in");
    std::ofstream cout("euclid2.out");
    std::ios::sync_with_stdio(false);

    int T, a, b;

    cin >> T;

    for (int i = 0 ; i < T ; ++i) {
        cin >> a >> b;
        cout << std::__gcd(a, b) << '\n';
    }

    return 0;
}
