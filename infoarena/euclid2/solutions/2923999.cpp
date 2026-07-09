#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt = 1;
    cin >> tt;

    while(tt--) {
        int a, b;
        cin >> a >> b;
        cout << gcd(a, b) << '\n';
    }

    return 0;
}
