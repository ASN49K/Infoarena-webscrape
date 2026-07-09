#include <fstream>
#include <algorithm>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int cpy[1026],n,m,i,v1[1026],v2[1026];
int dp[1026][1026];

int main()
{
    cin>>n>>m;
    for(i=1;i<=n;i++)
        cin>>v1[i];
    for(i=1;i<=m;i++)
        cin>>v2[i];
    for(i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(v1[i]!=v2[j])
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            else
                dp[i][j]=max(dp[i-1][j],max(dp[i][j-1],dp[i-1][j-1]+1));
        }

    }
    cout<<dp[n][m]<<'\n';
    int counter = dp[n][m];

    int x=n,y=m;
    while(x>=1&&y>=1)
    {
        if(v1[x]==v2[y])
            cpy[counter--]=v1[x],x--,y--;
        else
            {
                if(dp[x-1][y]>=dp[x][y-1])
                    x--;
                else
                    y--;
            }
    }
    for(i=1;i<=dp[n][m];i++)
        cout<<cpy[i]<<" ";
    return 0;
}
