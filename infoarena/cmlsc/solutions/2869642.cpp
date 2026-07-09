#include <bits/stdc++.h>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, a[1026], b[1026], dp[1026][1026];
int sol[1026];

void Citire()
{
    int i, j;
    fin >> n >> m;
    for (i = 1; i <= n; i++)
        fin >> a[i];
    for (j = 1; j <= m; j++)
        fin >> b[j];
}

void Dinamica()
{
    int i, j, top;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
        {
            if (a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else              dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    i = n; j = m;
    top = 0;
    while (i > 0 && j > 0)
    {
        if (a[i] == b[j])
        {
            sol[++top] = a[i];
            i--; j--;
        }
        else if (dp[i - 1][j] < dp[i][j - 1]) j--;
        else i--;
    }
    fout << dp[n][m] << "\n";
    for (i = top; i > 0; i--)
        fout << sol[i] << " ";
}

int main()
{
    Citire();
    Dinamica();
    
    fin.close();
    fout.close();
    return 0;
}