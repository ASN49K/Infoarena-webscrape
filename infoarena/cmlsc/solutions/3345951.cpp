#include <iostream>
using namespace std;

int a[1025], n;
int b[1025], m;

int dp[1025][1025];

int main()
{
    cin>>n>>m;
    for (int i = 1; i<=n; ++i)
        cin>>a[i];
    for (int i = 1; i<=m; ++i)
        cin>>b[i];

    for (int i = n; i>=1; --i)
        for (int j = m; j>=1; --j)
    {
        if (a[i] == b[j])
            dp[i][j] = dp[i+1][j+1] + 1;
        else
            dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
    }

    int maxim = dp[1][1];
    int pi = 1, pj = 1;
    cout<<maxim<<'\n';

    while (maxim)
    {
        if (a[pi] == b[pj])
        {
            cout<<a[pi]<<' ';
            ++pi, ++pj;
            --maxim;
        }
        else if (dp[pi][pj] == dp[pi + 1][pj])
            ++pi;
        else
            ++pj;
    }

}
