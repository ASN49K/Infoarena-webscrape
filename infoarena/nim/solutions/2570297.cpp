#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    freopen("nim.in", "r", stdin);
    freopen("nim.out", "w", stdout);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int sxor;
        cin >> sxor;
        for(int i = 1; i < n; ++i){
            int x;
            cin >> x;
            sxor ^= x;
        }
        (sxor) ? cout << "DA\n" : cout << "NU\n";
    }

    return 0;
}
