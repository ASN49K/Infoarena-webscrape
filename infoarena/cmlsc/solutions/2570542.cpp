#include <bits/stdc++.h>

using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

const int N = 1030;
int n, m, i, j, a[N], b[N], dp[N][N];
vector<int>ans;

int main()
{
    in >> n >> m;

    for(i = 1; i <= n; i++)
        in >> a[i];

    for(i = 1; i <= m; i++)
        in >> b[i];

    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
            if(a[i] == b[j])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

    out << dp[n][m] << '\n';

    i = n, j = m;

    while(i && j)
    {
        if(a[i] == b[j])
        {
            ans.push_back(a[i]);
            i--, j--;
        }
        else if(dp[i-1][j] > dp[i][j-1])
            i--;
        else
            j--;
    }

    for(i = ans.size() - 1; i >= 0; i--)
        out << ans[i] << ' ';
}
