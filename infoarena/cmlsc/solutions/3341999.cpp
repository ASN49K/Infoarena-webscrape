#include <bits/stdc++.h>

using namespace std;
int n,m,i,j,a[1030],b[1030],dp[1030][1030];
int main()
{
    set<int>s;
    cin >> n >> m;
    for(i = 1;i<=n;i++){
        cin >> a[i];
    }
    for(i = 1;i<=m;i++){
        cin >> b[i];
    }
    for(i = 1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(a[i] != b[j]){
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
            else
                dp[i][j] = dp[i-1][j-1]+1;
        }
    }
    i = n;
    j = m;
    cout << dp[i][j] << endl;;
    while(i!=0&&j!=0){
            if(a[i] == b[j]){
                s.insert(a[i]);
                i = i-1;
                j = j-1;
            }
            else{
                if(dp[i-1][j]<dp[i][j-1]){
                    j = j-1;
                }
                else{
                    i = i-1;
                }
            }
    }
    for(auto x:s){
        cout << x << ' ';
    }
    return 0;
}
