#include <fstream>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int n,m,a[1025],b[1025],dp[1025][1025];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i]==b[j]){
                dp[i][j]=dp[i-1][j-1]+1;
            }else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    int N=1,ans[1025];
    cout<<dp[n][m]<<'\n';
    int i=n,j=m;
    while(i>0){
        if(a[i]==b[j]){
            ans[N++]=a[i],i--,j--;
        }else
            if(dp[i][j-1]>dp[i-1][j])
                j--;
            else
                i--;
    }
    for(int i=N-1;i>=1;i--) cout<<ans[i]<<' ';
    return 0;
}
