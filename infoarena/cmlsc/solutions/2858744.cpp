#include <iostream>
#include <fstream>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n,m;
int a[1050],b[1050];
int dp[1050][1050];

void cit()
{
    f>>n>>m;

    for(int i=1;i<=n;i++)
        f>>a[i];

    for(int i=1;i<=m;i++)
        f>>b[i];
}

int vmax(int x, int y, int z)
{
    if(x>=y && x>=z)
        return x;
    else if(y>=x && y>=z)
        return y;
    else
        return z;
}

void constr_dp()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=vmax(dp[i][j-1],dp[i-1][j],dp[i-1][j-1]);
        }
    }

    g<<dp[n][m]<<"\n";
}

void afis(int i, int j)
{
    if(dp[i][j]==0)
        return;

    if(a[i]==b[j])
    {
        afis(i-1,j-1);
        g<<a[i]<<' ';
    }
    else if(vmax(dp[i][j-1],dp[i-1][j],dp[i-1][j-1])==dp[i-1][j])
        afis(i-1,j);
    else if(vmax(dp[i][j-1],dp[i-1][j],dp[i-1][j-1])==dp[i][j-1])
        afis(i,j-1);
    else if(vmax(dp[i][j-1],dp[i-1][j],dp[i-1][j-1])==dp[i-1][j-1])
        afis(i-1,j-1);
}

int main()
{
    cit();

    constr_dp();

    afis(n,m);

    return 0;
}
