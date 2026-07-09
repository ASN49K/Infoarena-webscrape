
#include <bits/stdc++.h>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int dp[1050][1050];
int n, m;
int v[1050], a[1050], sir[1050];
int main()
{
    fin >> n >> m;
    for (int i = 1; i <= n; i++)
        fin >> a[i];
    for (int i = 1; i <= m; i++)
        fin >> v[i];
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            if (v[i] == a[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    fout << dp[m][n]<<'\n';
    int mk = 0;
    for (int i = m, j = n; i;)
    {
        if (v[i] == a[j])
            sir[++mk] = v[i], i--, j--;
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }
    for (; mk; mk--)
        fout << sir[mk] << " ";
}