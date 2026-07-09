#include <bits/stdc++.h>

using namespace std;

int N, a, b;

int gcd(int a, int b)
{
    if (!b) return a;
    return gcd(b, a % b);
}

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    //ios_base::sync_with_stdio(false);

    cin >> N;
    while (N--)
    {
        cin >> a >> b;
        cout << gcd(a, b) << "\n";
    }
    return 0;
}
