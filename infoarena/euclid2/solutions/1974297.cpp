#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    ios::sync_with_stdio(false);
    int N, a,b;
    cin >> N;
    while(N --) {
        cin >> a >> b;
        cout << __gcd(a, b);
    }

    return 0;
}
