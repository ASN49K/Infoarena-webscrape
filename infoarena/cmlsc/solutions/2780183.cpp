#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int N=1e3+2;

int n,m,lg,i,j;
int a[N],b[N],r[N];
int dp[N][N];

int main()
{
    fin>>n>>m;
    for(i=1; i<=n; i++)
        fin>>a[i];
    for(j=1; j<=m; j++)
        fin>>b[j];

    dp[0][0]=dp[0][1]=dp[1][0]=0;
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
        {
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            if(a[i]==b[j] && dp[i-1][j-1]+1>=dp[i][j])
                dp[i][j]=dp[i-1][j-1]+1, r[dp[i][j]]=a[i];
        }

    fout<<dp[n][m]<<'\n';
    for(i=n,j=m; i && j;)
        if(a[i]==b[j])
            r[++r[0]]=a[i], i--, j--;
        else if(dp[i-1][j]>dp[i][j-1])
            i--;
        else
            j--;

    for(i=r[0]; i>0; i--)
        fout<<r[i] << ' ';
    fout<<'\n';
    return 0;
}
