#include <bits/stdc++.h>

using namespace std;

ifstream in ("cmlsc.in");
ofstream out ("cmlsc.out");

int dp[1025][1025]; /// dp[n][m] - cmlsc pentru 1..n, 1..m
int a[1025], b[1025];

int main()
{
    int n, m;
    in >> n >> m;

    for (int i=1; i<=n; i++)
        in >> a[i];
    for (int i=1; i<=m; i++)
        in >> b[i];

    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            if (a[i] == b[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
        }
    }

    out << dp[n][m] << '\n';

    vector<int>ans;

    for (int i=n, j=m; i > 0 && j > 0;)
    {
        if (a[i] == b[j])
            ans.push_back(a[i]), i--, j--;
        else if (dp[i-1][j] < dp[i][j-1])
            j--;
        else
            i--;
    }

    reverse(ans.begin(), ans.end());

    for (int x : ans)
        out << x << ' ';
    return 0;
}
