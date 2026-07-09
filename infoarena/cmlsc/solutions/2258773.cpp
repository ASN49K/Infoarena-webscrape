#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int>a(n),b(m);
    vector<vector<int>>dp(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<m;i++)
        cin>>b[i];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i]==b[j])
            {
                if(i==0 || j==0)
                    dp[i].push_back(1);
                else
                    dp[i].push_back(1+dp[i-1][j-1]);
            }
            else
            {
                if(i==0 || j==0)
                    dp[i].push_back(0);
                else
                    dp[i].push_back(max(dp[i-1][j],dp[i][j-1]));
            }
        }
    }
    vector<int>sl;
    int i=n-1;
    int j=m-1;

    while(i>=0 && j>=0 && dp[i][j])
    {
        if(a[i]==b[j])
        {
            sl.push_back(a[i]);
            i--;
            j--;
        }
        else
        {
            if(dp[i-1][j]>dp[i][j-1])
                i--;
            else
                j--;
        }
    }

    cout<<dp[n-1][m-1]<<"\n";
    reverse(sl.begin(),sl.end());
    for(auto &it:sl)
        cout<<it<<" ";
    cout<<"\n";
    return 0;
}
/**

**/
