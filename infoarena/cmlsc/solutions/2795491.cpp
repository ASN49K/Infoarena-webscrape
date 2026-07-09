#include <iostream>
#include <fstream>
using namespace std;
ifstream f ("cmlsc.in");
ofstream g ("cmlsc.out");
int n,m;
int v1[1030],v2[1030];
int dp[1030][1030];
void afisare(int x,int y)
{
    if(x==0||y==0)
        return;
    if(v1[x] == v2[y])
    {
        afisare(x-1,y-1);
        g << v1[x]<< " ";
    }
    else
    {
        if(dp[x-1][y]>dp[x][y-1])
            afisare(x-1,y);
        else
        {
            afisare(x,y-1);
        }
    }
}
int main()
{
    f >> n >> m;
    for(int i= 1;i<=n;i++)
    {
        f >> v1[i];
    }
    for(int i = 1;i<=m;i++)
    {
        f >> v2[i];
    }
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=m;j++)
        {
            if(v1[i] == v2[j])
                dp[i][j] = dp[i-1][j-1]+1;
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    g << dp[n][m]<< '\n';
    afisare(n,m);
}
