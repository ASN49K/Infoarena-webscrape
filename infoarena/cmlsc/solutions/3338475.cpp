#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int m, n, i, j, dp[1025][1025], a[1025], b[1025], v[1025], k;
int main()
{
    fin>>m>>n;
    for(i=1; i<=m; i++)
        fin>>a[i];
    for(i=1; i<=n; i++)
        fin>>b[i];
    for(i=1; i<=m; i++)
        for(j=1; j<=n; j++)
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
    fout<<dp[m][n]<<'\n';
    int i=m, j=n;
    int nr=dp[m][n];
    while(nr)
    {
        if(a[i]==b[j])
        {
            v[++k]=a[i];
            i--;
            j--;
            nr--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
            i--;
        else
            j--;
    }
    for(int i=k; i>=1; i--)
        fout<<v[i]<<" ";
    return 0;
}
