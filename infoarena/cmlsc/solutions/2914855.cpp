#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int a[1025],b[1025],dp[1025][1025];
void afisare(int i, int j)
{
    if(i==0 || j==0)
        return;
    if(a[i]==b[j])
    {
        afisare(i-1,j-1);
        out<<a[i]<<" ";
    }
    else if(dp[i-1][j]>dp[i][j-1])
    {
        afisare(i-1,j);

    }
    else afisare(i,j-1);

}
int main()
{
    int n,m;
    in>>n>>m;
    for(int i=1; i<=n; i++)
        in>>a[i];
    for(int j=1; j<=m; j++)
        in>>b[j];
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
    {
        if(a[i]==b[j])
        {
            dp[i][j]=dp[i-1][j-1]+1;
        }
        else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
    out<<dp[n][m]<<'\n';
    afisare(n,m);

    return 0;
}
