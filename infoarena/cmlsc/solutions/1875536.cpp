#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[1025],b[1025],n,m,i,j,dp[1025][1025],sir[1025],pas;
int main()
{
    fin>>n>>m;
    for(i=1;i<=n;i++) fin>>a[i];
    for(i=1;i<=m;i++) fin>>b[i];
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    fout<<dp[n][m]<<"\n";
    for(i=n,j=m;i;)
    {
        if(a[i]==b[j]) sir[++pas]=a[i],i--,j--;
        else if(dp[i-1][j]<dp[i][j-1]) j--;
        else i--;
    }
    for(i=pas;i>=1;i--) fout<<sir[i]<<" ";
}
