#include <bits/stdc++.h>
using namespace std;

int n,a,b;

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;

    for(int i = 0 ; i < n ; i++)
    {
        cin >> a >> b;
        cout << __gcd(a,b) << "\n";
    }
    return 0;
}
