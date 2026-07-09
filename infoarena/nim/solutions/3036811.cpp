#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, xr = 0;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i], xr ^= a[i];
    cout << (!xr ? "NU" : "DA") << '\n';
    return;
}

int main()
{
    freopen("nim.in", "r", stdin);
    freopen("nim.out", "w", stdout);

    ios :: sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; cin >> tt; while(tt--)
        solve();

    return 0;
}
