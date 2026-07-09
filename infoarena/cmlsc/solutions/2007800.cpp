#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n,m,dp[1024][1024],a[1024],b[1024],v[1024],k;

int main()
{
    int i,j;

    fin>>n>>m;

    for(i=1;i<=n;i++)
        fin>>a[i];
    for(i=1;i<=m;i++)
        fin>>b[i];

    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

    for(i=n,j=m;i;)
    {
        if(a[i]==b[j])
        {
            v[++k]=a[i];
            i--;
            j--;
        }
        else
            if(dp[i-1][j]<dp[i][j-1])
                j--;
            else
                i--;
    }
    fout<<dp[n][m]<<'\n';
    for(i=k;i>=1;i--)
        fout<<v[i]<<' ';
    return 0;
}
