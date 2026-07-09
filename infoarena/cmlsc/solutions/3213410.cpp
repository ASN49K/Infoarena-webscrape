#include <bits/stdc++.h>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m;
int a[1030], b[1030];
int dp[1030][1030];
int sol[1030], top;

int main()
{
    int i, j;
    fin >> n >> m;
    for (i = 1; i <= n; i++)
        fin >> a[i];
    for (i = 1; i <= m; i++)
        fin >> b[i];
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            if (a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    fout << dp[n][m] << "\n";
    i = n; j = m;
    while (i >= 1 && j >= 1)
    {
        if (a[i] == b[j])
        {
            top++;
            sol[top] = a[i];
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else j--;
    }
    while (top)
    {
        fout << sol[top] << " ";
        top--;
    }
    fout << "\n";
    return 0;
}
