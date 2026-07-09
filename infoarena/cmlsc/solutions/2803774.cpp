#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

vector <int> comun;

int n,m, v[1050],a[1050],dp[1050][1050],b[1050];

int main()
{
    fin>>m>>n;
    for(int i = 1; i<=m; i++)
    {
        fin>>v[i];
    }
    for(int i = 1; i<=n; i++)
    {
        fin>>a[i];
    }
    for(int i = 1; i<=m; i++)
    {
        for(int j = 1; j<=n; j++)
        {
            if(v[i] == a[j])
            {
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }

        }
    }
    fout<<dp[m][n]<<'\n';
    int elemente = 0,x = m, y = n;
    while(elemente<dp[m][n])
    {
        if(v[x] == a[y])
        {
            b[++elemente] = v[x];
            y--;
            x--;
        }
        else
        {
            if(dp[x-1][y]<dp[x][y-1]) y--;
            else
                x--;
        }
    }
    for(int i = elemente;i>=1;i--)
        fout<<b[i]<<' ';
}
