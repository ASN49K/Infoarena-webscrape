#include <bits/stdc++.h>

using namespace std;
int a[1030], b[1030], dp[1030][1030];
int main()
{
    ifstream cin("cmlsc.in");
    ofstream cout("cmlsc.out");
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        cin>>a[i];
    for(int i=1; i<=m; i++)
        cin>>b[i];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout<<dp[n][m]<<'\n';
    int poz1=n, poz2=m;
    vector<int>sir;
    while(poz1>0 && poz2>0)
    {
        if(a[poz1]==b[poz2])
            sir.push_back(a[poz1]), poz1--, poz2--;
        else
        {
            if(dp[poz1][poz2-1]>dp[poz1-1][poz2])
                poz2--;
            else
                poz1--;
        }
    }
    reverse(sir.begin(), sir.end());
    for(auto x: sir)
        cout<<x<<" ";
    return 0;
}
