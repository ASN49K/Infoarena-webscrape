#include <fstream>
#include <iostream>
using namespace std;

#define LE 2066

int a[LE],R[LE],b[LE];
int dp[LE][LE];

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int main()
{
    int n,m,i,j;
    f>>n>>m;
    for(i=1; i<=n; ++i) f>>a[i];
    for(i=1; i<=m; ++i) f>>b[i];

    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
            if (a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

    int result=dp[n][m],k=dp[n][m];

 /*   for(i=1;i<=n;++i,cout<<'\n')
       for(j=1;j<=m;++j)
          cout<<dp[i][j]<<" ";
*/
    for(i=n,j=m; i>=0&&j>=0;)
    {
        if (a[i]==b[j])
        {
            R[k]=a[i];
            --k;
            --i;
            --j;
        }
        else
        {
            if (dp[i-1][j]>dp[i][j-1]) --i;
            else --j;
        }
    }

    g<<result<<'\n';
    for(i=1; i<=result; ++i) g<<R[i]<<" ";



    return 0;
}
