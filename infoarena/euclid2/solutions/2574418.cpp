#include <bits/stdc++.h>

using namespace std;

int N, a, b;

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    ios_base::sync_with_stdio(false);

    cin >> N;
    while (N--)
    {
        cin >> a >> b;
        cout << __gcd(a, b) << "\n";
    }
    return 0;
}
