#include <iostream>
#include <cstdio>

using namespace std;

int dp[1028][1028],a[1028],b[1028],sols[1028];

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    int i,j,n,m,num;
    cin>>n>>m;
    for(i=1;i<=n;i++)
        cin>>a[i];
    for(j=1;j<=m;j++)
        cin>>b[j];
    ///DETERMINARE LUNGIME
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++){
        if(a[i] == b[j]){
            dp[i][j] = dp[i-1][j-1] + 1;
        }else{
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout<<dp[n][m]<<'\n';
    num = dp[n][m];

    ///ACUM BACKTRACKING
    for(i=n;i>=1;i--)
    for(j=m;j>=1;j--){
        if(dp[i][j] == num && a[i] == b[j]){
            sols[num] = b[j];
            num--;
        }
    }
    for(i=1;i<=dp[n][m];i++)
        cout<<sols[i]<<' ';
    return 0;
}
