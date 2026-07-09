#include <bits/stdc++.h>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, dp[1026][1026];
int a[1026], b[1026];

void Citire()
{
    int i;
    fin >> n >> m;
    for (i = 1; i <= n; i++)
        fin >> a[i];
    for (i = 1; i <= m; i++)
        fin >> b[i];
}

/*

dp[i][j] = lungimea subsirului comun intre a si b pana la pozitia i si j respectiv

1 7 3 9 8
7 5 8

1 7 
7 7 - dp[2][1] = max( dp[1][0] + 1, dp[1][1], dp[2][0] )

*/

void Dinamica()
{
    int i, j;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
        {
            if (a[i] == b[j]) dp[i][j] = max({ dp[i - 1][j - 1] + 1, dp[i - 1][j], dp[i][j - 1] });
            else              dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    fout << dp[n][m] << '\n';
}

int main()
{
    Citire();
    Dinamica();
    fin.close();
    fout.close();
    return 0;
}