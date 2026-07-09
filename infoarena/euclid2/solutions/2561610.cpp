#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    int q, x, y;
    cin >> q;
    while (q)
    {
        --q;
        cin >> x >> y;
        cout << __gcd(x, y) << '\n';
    }

    return 0;
}
