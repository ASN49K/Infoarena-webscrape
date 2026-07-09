#include <bits/stdc++.h>

using namespace std;

inline void Open(const string Name) {
    #ifndef ONLINE_JUDGE
        (void)!freopen((Name + ".in").c_str(), "r", stdin);
        (void)!freopen((Name + ".out").c_str(), "w", stdout);
    #endif
}

int T;

void solve() {
    int N, x, sumxor = 0;

    cin >> N;
    for(int i = 1;i <= N;i++)
        cin >> x, sumxor ^= x;

    if(sumxor) {
        cout << "DA\n";
        return;
    }

    cout << "NU\n"
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //Open("");

    cin >> T;
    while(T--) {
        solve();
    }

    return 0;
}