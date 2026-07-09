#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

int n, m, a[1025], b[1025];
int dp[1025][1025], traseu[1025][1025];

void find_sir (int i, int j)
{
    if(i==0 || j==0)
        return;
    if(traseu[i][j]==0)
    {
        find_sir(i-1, j-1);
        fout<<a[i]<<" ";
    }
    else
        if(traseu[i][j]==1)
            find_sir(i, j-1);
        else
            find_sir(i-1, j);
}

int main()
{
    fin>>n>>m;
    for(int i=1; i<=n; i++)
        fin>>a[i];
    for(int j=1; j<=m; j++)
        fin>>b[j];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else{
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                if(dp[i-1][j]<=dp[i][j-1])
                    traseu[i][j]=1;
                else
                    traseu[i][j]=2;
            }
    }
    fout<<dp[n][m]<<"\n";
    find_sir(n, m);
    return 0;
}
