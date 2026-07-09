#include <fstream>
#define N_max 1025
using namespace std;
ifstream cin ("cmlsc.in");
ofstream cout ("cmlsc.out");
int dp[N_max][N_max],a[N_max],b[N_max],n,m;
void read(){

    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<=m;++i) cin>>b[i];
}
void CMLSC(int is,int js){

    if(is && js){

        if(a[is]==b[js]){
            CMLSC(is-1,js-1);
            cout<<a[is]<<" ";
        }
        else if(dp[is-1][js]>dp[is][js-1])
            CMLSC(is-1,js);
        else CMLSC(is,js-1);
    }
}
void solve(){

    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
    cout<<dp[n][m]<<'\n';
    CMLSC(n,m);
}
int main()
{
    read();
    solve();
}
