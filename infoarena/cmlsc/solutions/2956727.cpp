#include <fstream>
#include <vector>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,i,j,a[1030],b[1030],dp[1030][1030],x,y;
vector <int> v;
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>a[i];
    for(i=1;i<=m;i++)
        f>>b[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i]==b[j])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    g<<dp[n][m]<<'\n';
    x=n;
    y=m;
    while(x>=1 && y>=1)
    {
        if(a[x]==b[y])
        {
            v.push_back(a[x]);
            x--;
            y--;
        }
        else
        if(dp[x-1][y]>dp[x][y-1])
            x--;
        else
            y--;
    }
    for(i=v.size()-1;i>=0;i--)
        g<<v[i]<<" ";
    return 0;
}
