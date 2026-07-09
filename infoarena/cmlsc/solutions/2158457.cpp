#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
const int MAX=1030;
int a[MAX],b[MAX],na,nb,dp[MAX][MAX];

int main()
{
    f>>na>>nb;
    for(int i=1;i<=na;i++)
        f>>a[i];
    for(int i=1;i<=nb;i++)
        f>>b[i];
    for(int i=1;i<=na;i++)
        for(int j=1;j<=nb;j++)
            {if(a[i]==b[j])
            dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);}
    int x=na,y=nb;
int sol[dp[na][nb]];
    while(dp[x][y]>0)
    {
        if(a[x]==b[y])
            {sol[dp[x][y]]=a[x];
        --x;
        --y;}
        else if(dp[x][y]==dp[x-1][y]) --x;
        else --y;
    }
    g<<dp[na][nb]<<'\n';
    for(int i=1;i<=dp[na][nb];i++)
        g<<sol[i]<<' ';
    return 0;
}
