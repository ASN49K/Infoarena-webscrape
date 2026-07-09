#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, a[1028], b[1028], dp[1028][1028], rasp[1028], len;

int main()
{
    int i, j;
    fin >> n >> m;
    for (i = 1; i <= n; i++)
        fin >> a[i];
    for (j = 1; j <= m; j++)
        fin >> b[j];
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            if (a[i] == b[j]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    i = n; j = m;
    while (i)
    {
        if (a[i] == b[j])
        {
            rasp[++len] = a[i];
            i--; j--;
        }
        else if (dp[i-1][j] < dp[i][j-1]) j--;
        else i--;
    }
    fout << len << "\n";
    for (i = len; i >= 1; i--)
        fout << rasp[i] << " ";
    return 0;
}
