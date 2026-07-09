#include <fstream>
#include <vector>

using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");
int nr,i,j,n,m,v1[1026],v2[1026], dp[1026][1026];
int ans[1026];

int main()
{
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>v1[i];
    for(i=1;i<=m;i++)
        fin>>v2[i];
    for(i=0;i<=n;i++)
        dp[i][0]=0;
    for(i=1;i<=m;i++)
        dp[0][i]=0;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            if(v1[i]==v2[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i][j-1], dp[i-1][j]);
        }
    fout<<dp[n][m]<<'\n';
    i=n;
    j=m;
    while(i)
    {
        if(v1[i]==v2[j])
        {
            nr++;
            ans[nr]=v1[i];
            i--;
            j--;
        }
        else
        {
            if(dp[i-1][j] < dp[i][j-1])
                j--;
            else
                i--;
        }
    }
    for(i=nr;i>=1;i--)
        fout<<ans[i]<<' ';
    return 0;
}
