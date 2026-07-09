#include <fstream>
#include <vector>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
vector <int> sol;
int n,m,a[1030],b[1030],dp[1030][1030],i,j,ind[1030];
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
    {
        dp[i][j]=dp[i-1][j-1]+1;
        ind[dp[i][j]]=a[i];
    }
           else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    g<<dp[n][m]<<'\n';
    i=n;
    j=m;
    while(i>0 && j>0)
    {
        if(a[i]==b[j])
        {
            sol.push_back(a[i]);
            i--;
            j--;
        }
        else
        if(dp[i-1][j]<dp[i][j-1])
            j--;
        else
            i--;
    }
    for(i=sol.size()-1;i>=0;i--)
        g<<sol[i]<<" ";
    return 0;
}
