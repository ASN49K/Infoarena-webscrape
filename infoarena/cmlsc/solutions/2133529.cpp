#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int maximum(int a, int b)
{
    return a > b ? a : b;
}

int A[1025], B[1025], dp[1025][1025];

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        cin >> A[i];
    for(int i = 1; i <= m; ++i)
        cin >> B[i];

    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            if(A[i] == B[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = maximum(dp[i][j - 1], dp[i - 1][j]);
        }
    }

    cout << dp[n][m] << '\n';
    vector<int> sol;

    while(n > 0 && m > 0)
    {
        if(dp[n][m] > dp[n][m - 1] && dp[n][m] > dp[n - 1][m])
        {
            sol.push_back(A[n]);
            --n;
            --m;
        }
        else
        {
            if(dp[n][m] == dp[n - 1][m])
                --n;
            else
                --m;
        }
    }
    for(int i = sol.size() - 1; i >= 0; --i)
        cout << sol[i] << ' ';
    return 0;
}
