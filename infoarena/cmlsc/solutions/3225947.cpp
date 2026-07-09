#include <fstream>

using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int n,m,a[1026],b[1026],dp[1026][1026];
void f(int x,int y,int nr)
{
    if(nr==0)
        return ;
    else
        if(a[x]==b[y])
    {
        f(x-1,y-1,nr-1);
        cout<<a[x]<<" ";;
    }
    else
    {
        if(dp[x][y-1]>dp[x-1][y])
            f(x,y-1,nr);
        else
            f(x-1,y,nr);
    }
}
int main()
{
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
    cout<<dp[n][m]<<'\n';
    f(n,m,dp[n][m]);
    return 0;
}
