#include <fstream>
#include <algorithm>
#define NMAX 1030
using namespace std;
short a[NMAX], b[NMAX], dp[NMAX][NMAX], lcs[NMAX];
int main()
{
    short n, m, i, j;
    ifstream in("cmlsc.in");
    ofstream out("cmlsc.out");
    in>>n>>m;
    for(i=1; i<=n; ++i) in>>a[i];
    for(i=1; i<=m; ++i) in>>b[i];
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
            if(a[i]==b[j])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
    i=n; j=m;
    while(i&&j)
    {
        if(a[i]==b[j])
        {
            lcs[dp[i][j]]=a[i];
            --i; --j;
        }
        else
            if(dp[i][j-1]>dp[i-1][j]) --j;
            else --i;
    }
    out<<dp[n][m]<<'\n';
    for(i=1; i<=dp[n][m]; ++i) out<<lcs[i]<<' ';
    return 0;
}
