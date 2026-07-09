#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream f("cmlsc.in"); ofstream g("cmlsc.out");
int n,m,a[1025],b[1025],dp[1025][1025],sol[1025];

int Lmax(int n, int m)
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if (a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][m];
}
int main()
{
    f>>n>>m;
    for(int i=0;i<=n;i++)
    {
        dp[0][i]=0;
        dp[i][0]=0;
    }
    for(int i=1;i<=n;i++) f>>a[i];
    for(int i=1;i<=m;i++) f>>b[i];
    g<<Lmax(n,m)<<'\n';
    int i,j,nr;
    i=n;
    j=m;
    nr=0;
    while(i>=1 || j>=1)
    {
        if (a[i]==b[j])
        {
            nr++;
            sol[nr]=a[i];
            i--;
            j--;
        }
        else
        {
            if (dp[i-1][j]>dp[i][j-1])
            {
                i--;
            }
            else j--;
        }
    }
    for(i=nr;i>=1;i--) g<<sol[i]<<' ';
    return 0;
}
