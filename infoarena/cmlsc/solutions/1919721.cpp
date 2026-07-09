#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int dp[1025][1025],v1[1025],v2[1025],n,m,sol[1030],vf;


int main()
{
    f >> n>> m;
    for(int i=1;i<=n;i++)
        f >> v1[i];
    for(int j=1;j<=m;j++)
        f>> v2[j];

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(v1[i]==v2[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

        }

    g << dp[n][m] << "\n";
    int i=n,j=m;
    while(i && j)
    {
        if(v1[i]==v2[j])
        {
            sol[vf++]=v1[i];
            i--;
            j--;
        }
        if(dp[i][j]==dp[i-1][j])
            i--;
        else j--;
    }
    for(int i=vf-1;i>=0;i--)
        g << sol[i] << " ";

    return 0;
}
