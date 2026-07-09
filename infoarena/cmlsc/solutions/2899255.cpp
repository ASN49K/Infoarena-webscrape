#include <iostream>
#include <cmath>
#include <fstream>
#define nmax 1030
using namespace std;
int a[nmax],b[nmax],dp[nmax][nmax],n,m,rsp[nmax],o;
void recur(int i,int j)
{
    if (i<1 || j<1) return;
    if (a[i]==b[j])
    {
        o++;
        rsp[o]=a[i];
        recur(i-1,j-1);
    }
    else
    {
        if (dp[i-1][j]>dp[i][j-1])
            recur(i-1,j);
        else
            recur(i,j-1);
    }
}
int main()
{
    ifstream f ("cmlsc.in");
    ofstream g ("cmlsc.out");
    f>>n>>m;
    for (int i=1; i<=n; i++)
        f>>a[i];
    for (int i=1; i<=m; i++)
        f>>b[i];
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
        {
            if (a[i]==b[j])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    g<<dp[n][m]<<'\n';
    recur(n,m);
    for (int i=o; i>=1; i--)
        g<<rsp[i]<<' ';
}
