#include "bits/stdc++.h"
using namespace std;

unsigned long long a, b;

int main() {
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;              cin >>n;

    for (int i = 0; i < n; ++i)
        cin >> a, cin >> b, cout << __gcd(a,b) << '\n';

    return 0;
}
