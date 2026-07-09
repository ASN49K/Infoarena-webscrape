#include <fstream>
#include <algorithm>
using namespace std;
ifstream f("cmlsc.in"); ofstream g("cmlsc.out");
int n, m, a[1050], b[1050], dp[1050][1050], sir[1050];
int main()
{
    f>>n>>m;
    for(int i=1; i<=n; i++) f>>a[i]; for(int i=1; i<=m; i++) f>>b[i];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1;
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    g<<dp[n][m]<<'\n';
    int nrmax=0, i=n,j=m;
    while(i && j)
    {
        if(a[i]==b[j]) sir[++nrmax]=a[i],i--,j--;
        else if(dp[i-1][j]==dp[i][j]) i--;
            else j--;
    }
    for(int i=nrmax; i; i--) g<<sir[i]<<" ";
    g.close(); return 0;
}
