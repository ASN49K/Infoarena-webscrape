#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int dp[1030][1030],a[1030],b[1030],sir[1030];
int main()
{
    int n,m,i,j,maxim=0,pozmax,h=0;
    fin>>n>>m;
    for(i=1;i<=n;i++)
    {
        fin>>a[i];
    }
    for(j=1;j<=m;j++)
    {
        fin>>b[j];
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j])
            {
                dp[i][j]=dp[i-1][j-1]+1;
                h++;
                sir[h]=a[i];
            }
            else
            {
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(maxim<dp[i][j])
            {
                maxim=dp[i][j];
                pozmax=i;
            }
        }
    }
    fout<<maxim<<'\n';
    for(i=1;i<=h;i++)
    {
        fout<<sir[i]<<" ";
    }
    return 0;
}
