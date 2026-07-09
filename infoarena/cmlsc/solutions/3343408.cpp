#include <fstream>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int n,m,a[1025],b[1025],dp[1025][1025];
void rec(int i,int j){
    if(dp[i][j]==0)
        return ;
    if(a[i]==b[j]){
        rec(i-1,j-1);
        cout<<a[i]<<" ";
    }else{
        if(dp[i-1][j]>dp[i][j-1])
            rec(i-1,j);
        else
            rec(i,j-1);
    }
}
signed main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
        cin>>b[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
        }
    cout<<dp[n][m]<<'\n';
    rec(n,m);
    return 0;
}
