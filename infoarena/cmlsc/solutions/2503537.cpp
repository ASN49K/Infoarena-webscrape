#include <iostream>
#include <cstring>

using namespace std;
const int mod=1e9+7;
int k,n,dp[2005][2005];
long long ans;

int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        dp[1][i]=1;
    for(int i=1;i<k;i++){
        for(int j=1;j<=n;j++){
            for(int m=j;m<=n;m+=j){
                dp[i+1][m]%=mod;
                dp[i+1][m]+=dp[i][j]%mod;
                dp[i+1][m]%=mod;
            }
        }
    }
    for(int i=1;i<=n;i++){
        ans+=dp[k][i]%mod;
        ans%=mod;
    }
    cout<<ans;
    return 0;
}
