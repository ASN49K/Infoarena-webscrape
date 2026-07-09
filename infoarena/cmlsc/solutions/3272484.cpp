#include <bits/stdc++.h>

using namespace std;

const int nmax=1026;
int a[nmax], b[nmax], aux[nmax][nmax];
pair <int, int> dp[nmax][nmax];
vector <int> ans;

int main()
{
    ifstream cin("cmlsc.in");
    ofstream cout("cmlsc.out");

    int n, m;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        cin>>a[i];
    for(int i=1; i<=m; i++)
        cin>>b[i];

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(dp[i-1][j].first>dp[i][j-1].first)
            {
                dp[i][j].first=dp[i-1][j].first;
                dp[i][j].second=0;
            }
            if(dp[i][j-1].first>=dp[i-1][j].first)
            {
                dp[i][j].first=dp[i][j-1].first;
                dp[i][j].second=1;
            }

            if(a[i]==b[j])
            {
                if(dp[i-1][j-1].first+1>dp[i][j].first)
                {
                    dp[i][j].first=dp[i-1][j-1].first+1;
                    dp[i][j].second=2;
                }
            }
        }
    }
    cout<<dp[n][m].first<<'\n';
    int i=n, j=m;
    while(i>=1 && j>=1)
    {
        if(dp[i][j].second==2)
        {
            ans.push_back(a[i]);
            i--;
            j--;
        }
        else if(dp[i][j].second==1)
        {
            j--;
        }
        else
        {
            i--;
        }
    }
    reverse(ans.begin(), ans.end());

    for(auto i:ans)
        cout<<i<<' ';

    return 0;
}
