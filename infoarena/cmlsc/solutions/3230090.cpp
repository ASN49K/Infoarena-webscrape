#include <fstream>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int t[1025][1025],dp[1025][1025],a[1025],b[1025],n,m;
void rec(int i,int j){
    if(dp[i][j]>0){
        if(a[i]==b[j]){
            rec(i-1,j-1);
            cout<<a[i]<<" ";
        }else{
            if(t[i][j]==1)
                rec(i,j-1);
            else
                rec(i-1,j);
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
        cin>>b[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else{
                if(dp[i][j-1]>dp[i-1][j]){
                    dp[i][j]=dp[i][j-1];
                    t[i][j]=1;
                }else{
                    dp[i][j]=dp[i-1][j];
                    t[i][j]=-1;
                }
            }
    cout<<dp[n][m]<<'\n';
    rec(n,m);
    return 0;
}
