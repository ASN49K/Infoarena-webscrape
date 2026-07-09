#include <bits/stdc++.h>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
const int NMAX = 2e3;
int n,m;
int dp[NMAX][NMAX];
int v1[NMAX],v2[NMAX];
int best[NMAX];

int32_t main()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>v1[i];
    for(int i=1;i<=m;i++)
        fin>>v2[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(v1[i] == v2[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    int i = n, j = m;
    int k = 0;
    while(i>=1 && j>=1){
        if(v1[i] == v2[j])
        {
            k++;
            best[k] = v1[i];
            i--; j--;
        }
        else if(dp[i-1][j] > dp[i][j-1])
            i--;
        else
            j--;
    
    }
    fout<<dp[n][m]<<'\n';
    for(int h=k;h>=1;h--)
        fout<<best[h]<<' ';
}