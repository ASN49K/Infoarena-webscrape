#include <bits/stdc++.h>

#define NMax 1030

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int dp[NMax][NMax], n, m, a[NMax], b[NMax], sol[NMax], k;

int main()
{
    int i, j;
    fin >> n >> m;
    for(i = 1; i <= n; i++)
        fin >> a[i];
    for(i = 1; i <= m; i++)
        fin >> b[i];
    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
            if(a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j]= max(dp[i - 1][j], dp[i][j-1]);
    fout << dp[n][m] << "\n";
    for(i = n, j = m; i;)
        if(a[i] == b[j])
        {
            sol[++k] = a[i];
            i--;
            j--;
        }
        else
            if(dp[i - 1][j] < dp[i][j - 1])j--;
        else i--;
    for(i = k; i >= 1; i--)
        fout << sol[i] << ' ';
    fin.close();
    fout.close();
    return 0;
}
