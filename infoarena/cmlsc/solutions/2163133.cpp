#include <fstream>
#define nmax 1030

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n,m,a[nmax],b[nmax],dp[nmax][nmax],i,j,ans[nmax],nr;

int main()
{
    fin >> n >> m;
    for (i=1; i<=n; i++)
        fin >> a[i];
    for (i=1; i<=m; i++)
        fin >> b[i];
    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++)
            if (a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    fout << dp[n][m] << '\n';
    for (i=n,j=m; i>0&&j>0;)
        if (a[i]==b[j])
            ans[++nr]=a[i],i--,j--;
        else
            if (dp[i-1][j]>dp[i][j-1])
                i--;
            else
                j--;
    for (i=nr; i; i--)
        fout << ans[i] << ' ';
    fout << '\n';
}
