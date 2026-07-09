#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n,m,i,v[1050],g[1050],dp[1050][1050],j;


void reconstituire(int i ,int j)
{
    if (dp[i][j]>0)
    {
        if (v[i]==g[j])
        {
            reconstituire(i-1,j-1);
            fout<<v[i]<<" ";
        }
        else
        {
            if (dp[i-1][j]>dp[i][j-1])
                reconstituire(i-1,j);
            else
                reconstituire(i,j-1);
        }
    }
}

int main()
{
    fin>>n>>m;
    for (i=1; i<=n; i++)
        fin>>v[i];

    for (i=1; i<=m; i++)
        fin>>g[i];

    for (i=1; i<=n; i++)
    {
        for (j=1; j<=m; j++)
        {
            if (v[i]==g[j])
            dp[i][j]=dp[i-1][j-1]+1;
            else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }


    fout<<dp[n][m]<<"\n";

    reconstituire(n,m);


    return 0;
}
