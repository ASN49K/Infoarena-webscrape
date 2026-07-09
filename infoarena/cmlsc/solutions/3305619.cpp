#include <bits/stdc++.h>

using namespace std;

#define pb push_back

int n, m;
vector <int> a, b;
vector <vector <int> > dp;

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    cin >> n >> m;

    a.resize(n + 5);
    b.resize(m + 5);
    dp.resize(n + 2, vector <int> (m + 2));

    for (int i = 1; i <= n; i ++)
    {
        cin >> a[i];
    }

    for (int i = 1; i <= m; i ++)
    {
        cin >> b[i];
    }


    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= m; j ++)
        {
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            if(a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
        }
    }

    cout << dp[n][m] << "\n";

    int i, j, pas = dp[n][m];
    i = n, j = m;
    vector <int> sol;
//
//    while(pas  &&  i  &&  j)
//    {
//        if(a[i] == b[j])
//        {
//            assert(i >= 1  &&   i <= n);
//            sol.pb(a[i]);
//            i --;
//            j --;
//            pas --;
//        }
//        else
//        {
//            if(i >= 0  &&  j >= 0 &&  dp[i - 1][j] > dp[j - 1][i])
//                i --;
//            else
//                j --;
//        }
//    }

    for(int i = sol.size() - 1; i >= 0; i --)
    {
        cout << sol[i] << " ";
    }
    return 0;
}
