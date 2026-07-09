#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
const int Nmax=1030;
int dp[Nmax][Nmax],a[Nmax],b[Nmax];
void reconst(int i, int j)
{
    if(a[i]==b[j])
    {
        if(dp[i][j]==1)
        {
            fout<<a[i]<<' ';
            return;
        }
        else reconst(i-1,j-1);
        fout<<a[i]<<' ';
    }
    else
    {
        if(dp[i-1][j]>dp[i][j-1])
        {
            reconst(i-1,j);
        }
        else reconst(i,j-1);
    }
}
int main()
{
    int n,m;
    fin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        fin>>a[i];
    }
    for(int i=1;i<=m;i++)
    {
        fin>>b[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    fout<<dp[n][m]<<'\n';
    reconst(n,m);
    return 0;
}
