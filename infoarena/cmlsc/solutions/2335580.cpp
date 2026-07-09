#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, a[1030], b[1030], dp[1030][1030], ans[1030];

int main()
{
    int i, k = 0, j;
    fin >> n >> m;
    for(i = 1; i <= n; i++)
        fin >> a[i];
    for(i = 1; i <= m; i++)
        fin >> b[i];
    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
            if(a[i] == b[j])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    for(i = n, j = m; i > 0 && j > 0; )
        if(a[i] == b[j])
        {
            ans[++k] = a[i];
            i--;
            j--;
        }
        else if(dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    fout << k << "\n";
    for(i = k; i >= 1; i--)
        fout << ans[i] << " ";
    fout << "\n";
    fin.close();
    fout.close();
    return 0;
}
