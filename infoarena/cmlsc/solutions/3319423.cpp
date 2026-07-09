#include <bits/stdc++.h>

using namespace std;
int a[1025], b[1025], dp[1025][1025];
vector<int> rez;
int main()
{
    ifstream cin("ccmlsc.in");
    ofstream cout("cmmlsc.out");
    int n, m;
    cin>>n>>m;

    for(int i=1; i<=n; i++)
        cin>>a[i], dp[i][0] = 0;

    for(int i=1; i<=m; i++)
        cin>>b[i], dp[0][i] = 0;

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(a[i] == b[j]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);

    cout<<dp[n][m]<<'\n';

    int pozi = n, pozj = m;

    while(pozi > 0 && pozj > 0)
    {
        //cout<<pozi<<" "<<pozj<<'\n';
        if(a[pozi] == b[pozj])
        {
            rez.push_back(a[pozi]);
            pozi--;
            pozj--;
        }
        else
        {
            if(dp[pozi][pozj-1] > dp[pozi-1][pozj])
                pozj--;
            else
                pozi--;
        }
    }

    //cout<<'\n';

    reverse(rez.begin(), rez.end());

    for(auto x : rez)
        cout<<x<<" ";

    return 0;
}
