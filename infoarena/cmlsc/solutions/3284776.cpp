#include <fstream>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int dp[1025][1025],a[1025],b[1025],n,m;
void rec(int l,int c){
    if(l==0||c==0)
        return ;
    if(a[l]==b[c]){
        rec(l-1,c-1);
        cout<<a[l]<<" ";
    }else if(dp[l-1][c]>dp[l][c-1])
        rec(l-1,c);
    else
        rec(l,c-1);
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
            else
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
    cout<<dp[n][m]<<'\n';
    rec(n,m);
    return 0;
}
