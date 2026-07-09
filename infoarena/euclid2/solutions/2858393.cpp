#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int x, y;
    cin >> x >> y;
    while(x != y) {
        if(x > y) x -= y;
        else y -= x;
    }
    cout << x << '\n';
}

int main() {
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    int t;
    cin >> t;
    while(t--) solve();
}
