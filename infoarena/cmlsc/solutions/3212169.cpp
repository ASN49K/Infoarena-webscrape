#include <iostream>
#include <algorithm>
#include <queue>
#define ll long long


using namespace std;

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>>d(n+1,vector<ll>(m+1,0));
    vector<ll>a(n + 1), b(m + 1);
    for (ll i = 1; i <= n; ++i)
        cin >> a[i];
    for (ll j = 1; j <= m; ++j)
        cin >> b[j];

    for(ll i=1; i<=n; ++i)
        for (ll j = 1; j <= m; ++j)
        {
            if (a[i] == b[j])
                d[i][j] = 1 + d[i - 1][j - 1];
            else
                d[i][j] = max(d[i - 1][j], d[i][j - 1]);
        }

    ll p = 0, i = n, j = m;
    vector<ll> sor(n+1);
    while (i != 1 && j != 1)
    {
        if (a[i] == b[j])
        {
            ++p;
            sor[p] = a[i];
            --i;
            --j;
        }
        else
        {
            if (d[i - 1][j] < d[i][j - 1])
                --j;
            else
                --i;
        }
    }
    if (a[i] == b[j])
    {
        ++p;
        sor[p] = a[i];
    }
    cout << p << "\n";
    for (i = p; i >= 1; --i)
        cout << sor[i]<<' ';

    return 0;
}
