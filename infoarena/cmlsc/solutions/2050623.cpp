#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
int dp[1030][1030], m, n, s1[1030], s2[1030], rez[1030], cont=1;
int main()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>s1[i];
    for(int i=1;i<=m;i++)
        fin>>s2[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s1[i]==s2[j])
            {
                dp[i-1][j-1]++;
                rez[cont]=s1[i];
                cont++;
            }
            dp[i][j]=max(dp[i-1][j-1],max(dp[i-1][j],dp[i][j-1]));
        }
    }
    fout<<dp[n][m]<<'\n';
    for(int i=1;i<cont;i++)
        fout<<rez[i]<<" ";
    return 0;
}
