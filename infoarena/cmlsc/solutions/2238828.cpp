#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=1024+5;

int n,m;
int a[N],b[N];
int dp[N][N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  //  freopen("euclid2.in","r",stdin);
  //  freopen("euclid2.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int j=1;j<=m;j++)
        cin>>b[j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    vector<int>ans;
    int x=n,y=m;
    int need=dp[n][m];
    while(need)
    {
        if(a[x]==b[y])
        {
            ans.push_back(a[x]);
            need--;
            x--;
            y--;
            continue;
        }
        if(dp[x][y-1]==dp[x][y])
            y--;
        else
            x--;
    }
    cout<<dp[n][m]<<"\n";
    reverse(ans.begin(),ans.end());
    for(auto x:ans)
        cout<<x<<" ";
    cout<<"\n";
    return 0;
}
/**

**/
