#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[1026], b[1026];
int n, m;
int dp[1026][1026];

void Citire()
{
    int i;
    fin >> n >> m;
    for (i = 1; i <= n; i++)
        fin >> a[i];
    for (i = 1; i <= m; i++)
        fin >> b[i];
}

void Cmlsc()
{
    int i, j;
    for (i = n; i >= 1; i--)
        for (j = m; j >= 1; j--)
            if (a[i] == b[j]) dp[i][j] = 1 + dp[i + 1][j + 1];
            else dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
}

void Afisare()
{
    int i, j;
    fout << dp[1][1] << "\n";
    i = j = 1;
    while (i <= n && j <= m)
    {
        if (a[i] == b[j])
        {
            fout << a[i] << " ";
            i++; j++;
        }
        else if (dp[i + 1][j] > dp[i][j + 1]) i++;
        else j++;
    }
}

int main()
{
    Citire();
    Cmlsc();
    Afisare();
}