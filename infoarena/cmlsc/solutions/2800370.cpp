#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

vector <int> comun;

int n,m, v[1050],a[1050],dp[1050][1050];

int main()
{
    fin>>m>>n;
    for(int i = 1;i<=m;i++)
    {
        fin>>v[i];
    }
    for(int i = 1;i<=n;i++)
    {
        fin>>a[i];
    }
    for(int i = 1;i<=m;i++)
    {
        for(int j = 1;j<=n;j++)
        {
            if(v[i] == a[j])
                {
                    dp[i][j] = dp[i-1][j-1]+1;
                    comun.push_back(a[j]);
                }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }

        }
    }
    fout<<dp[m][n]<<'\n';
    for(int i = 0;i<comun.size();i++)
    {
        fout<<comun[i]<<' ';
    }
}
