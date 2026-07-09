#include <iostream>
#include <fstream>
#define DM 1026
using namespace std;

int n, m, a[DM], b[DM], i, j, dp[DM][DM], v[DM], k, mx, ii ,jj;
int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    fin >> n >> m;
    for(i = 1; i <= n; i++)
        fin >> a[i];
    for(i = 1; i <= m; i++)
        fin >> b[i];
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
        {
            if(a[i] == b[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            dp[i][j] = max(dp[i][j], max(dp[i][j - 1], dp[i - 1][j]));
        }
    }
    k = dp[n][m];
    fout << k << "\n";
    for(i = n, j = m; k;)
    {
        mx = 0;
        if(a[i] == b[j])
        {
            v[k] = a[i];
            mx = dp[i - 1][j - 1] + 1;
            ii = i - 1;
            jj = j - 1;
            k--;
        }
        if(dp[i][j - 1] > mx)
        {
            mx = dp[i][j - 1];
            ii = i;
            jj = j - 1;
        }
        if(dp[i - 1][j] > mx)
        {
            mx = dp[i - 1][j];
            ii = i - 1;
            jj = j;
        }
        i = ii;
        j = jj;
    }
    for(i = 1; i <= dp[n][m]; i++)
        fout << v[i] << " ";
    return 0;
}
