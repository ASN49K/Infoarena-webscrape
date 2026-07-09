#include <bits/stdc++.h>

using namespace std;

const int N=1030;

int dp[N][N], a[N], b[N];

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m,n;cin>>m>>n;
    for (int i=1;i<=m;i++){
        cin>>a[i];
    }
    for (int i=1;i<=n;i++){
        cin>>b[i];
    }
    for (int i=1;i<=m;i++){
        for (int j=1;j<=n;j++){
            if (a[i]==b[j]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    int i=m, j=n;
    vector<int> ans;
    while (i>=1 && j>=1){
        if (a[i]==b[j]){
            ans.push_back(a[i]);
            i--;
            j--;
        }
        else{
            if (dp[i-1][j]>dp[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
    }
    cout<<dp[m][n]<<'\n';
    for (int k=ans.size()-1;k>=0;k--){
        cout<<ans[k]<<' ';
    }
    return 0;
}
