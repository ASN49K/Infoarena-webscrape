#include <iostream>
#include <fstream>

using namespace std;

ifstream in ("cmlsc.in");
ofstream out ("cmlsc.out");

int a[1026],b[1026],dp[1026][1026],sol[1026];
int main()
{
    int n,m;
    in>>n>>m;
    for (int i=1;i<=n;i++)
        in>>a[i];
    for (int i=1;i<=m;i++)
        in>>b[i];

    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            if (a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    out<<dp[n][m]<<'\n';

    int i=n,j=m,k=0;
    while (i && j)
    {
        if (a[i]==b[j])
        {
            sol[++k]=a[i];
            i--;
            j--;
        }
        else if (dp[i][j-1]>dp[i-1][j])
            j--;
        else
            i--;
    }
    for (int i=k;i>0;i--)
        out<<sol[i]<<' ';
    return 0;
}
