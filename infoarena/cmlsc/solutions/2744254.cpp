#include <fstream>

using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
#define NMAX 1025
int v[NMAX],v2[NMAX],dp[NMAX][NMAX],vrez[NMAX];
int main()
{
    /// cel mai lung subsir komunist
    int n,m,i,j,x,y;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        cin>>v[i];
    }
    for(i=1;i<=m;i++)
        cin>>v2[i];
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    {
        if(v[i]==v2[j])
            dp[i][j]=dp[i-1][j-1]+1;
        else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
    cout<<dp[n][m]<<'\n';
    x=n;
    y=m;
    while(dp[x][y]!=0)
    {
        if(x>1 && y>1)
        {
            if(dp[x-1][y]<dp[x][y] && dp[x][y-1]<dp[x][y])
            {
                vrez[dp[x][y]]=v[x];
                x--;
                y--;
            }
            else
            if(dp[x-1][y]>=dp[x][y-1])
            {
                x--;
            }
            else
                y--;
        }
        else
        if(x>1)
        {
            if(dp[x-1][y]!=dp[x][y])
            {
                vrez[dp[x][y]]=v[x];
                x--;
                y--;
            }
            else
                x--;
        }
        else
        if(y>1)
        {
            if(dp[x][y-1]!=dp[x][y]){
                vrez[dp[x][y]]=v[x];
                x--;
                y--;
            }
            else
                y--;
        }
        else
        {
            vrez[dp[x][y]]=v[x];
            x--;
            y--;
        }
    }
    for(i=1;i<=dp[n][m];i++)
    {
        cout<<vrez[i]<<" ";
    }
    return 0;
}
