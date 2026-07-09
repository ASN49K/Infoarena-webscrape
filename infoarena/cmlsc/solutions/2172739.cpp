#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, a[1100], b[1100], dp[1100][1100], rez[1100], k;

void Citire()
{
    fin >> n >> m;

    for(int i = 1; i <= n; i++)
        fin >> a[i];
    for(int j = 1; j <= m; j++)
        fin >> b[j];

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            dp[i][j] = max({dp[i - 1][j], dp[i][j - 1],
                            dp[i - 1][j - 1] + (a[i] == b[j])});

    fout << dp[n][m] << "\n";

    int i = n;
    int j = m;

    while(i >= 1 || j >= 1)
    {
        if(a[i] == b[j])
            rez[++k] = a[i],
            i--, j--;
        else
        {
            if(dp[i - 1][j] < dp[i][j - 1])
                j--;
            else i--;
        }
    }

    for(i = k; i >= 1; i--)
        fout << rez[i] << " ";
}
int main()
{
    Citire();
    return 0;
}
