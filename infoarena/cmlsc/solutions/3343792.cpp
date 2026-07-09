#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n, m, i, j, a[1025], b[1025], dp[1025][1025], v[1025], k;
int main()
{
    fin>>n>>m;
    for(i=1; i<=n; i++)
        fin>>a[i];
    for(i=1; i<=m; i++)
        fin>>b[i];
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if(a[i]!=b[j])
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            else
                dp[i][j]=dp[i-1][j-1]+1;
    fout<<dp[n][m]<<'\n';
    int i=n, j=m;
    while(dp[i][j])
    {
        if(a[i]!=b[j])
        {
            if(dp[i-1][j]>dp[i][j-1])
                i--;
            else
                j--;
        }
        else
        {
            v[++k]=a[i];
            i--;
            j--;
        }
    }
    for(i=k; i>=1; i--)
        fout<<v[i]<<" ";
    return 0;
}
