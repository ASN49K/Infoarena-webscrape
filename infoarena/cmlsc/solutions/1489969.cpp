#include <bits/stdc++.h>
#define MAX 1030
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int dp[MAX][MAX], n, m, s1[MAX], s2[MAX];
int main()
{
    fin>>m>>n;
    for(int i=1; i<=m; ++i)
        fin>>s1[i];
    for(int i=1; i<=n; ++i)
        fin>>s2[i];
    for(int i=1; i<=m; ++i)
        for(int j=1; j<=n; ++j)
            if(s1[i] == s2[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    fout<<dp[m][n]<<'\n';
    int i = m, j = n, nr = 0, rez[MAX];
    while(i > 0 and j > 0)
        if(s1[i] == s2[j])
        {
            nr++;
            rez[nr] = s1[i];
            i--;
            j--;
        }
        else
            if (dp[i-1][j] < dp[i][j-1])
                --j;
            else
                --i;
    for(int i=nr; i>0; --i)
        fout<<rez[i]<<' ';
    return 0;
}
