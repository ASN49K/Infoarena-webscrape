#include <bits/stdc++.h>

using namespace std;

int a[1030], b[1030], sol[1030];
int dp[1030][1030];
int n, m;

void Citire()
{
    int i;
    ifstream fin("cmlsc.in");
    fin >> n >> m;
    for(i = 1; i <= n; i++)
        fin >> a[i];
    for(i = 1; i <= m; i++)
        fin >> b[i];
    fin.close();
}

void LCS()
{
    int i, j;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
            if(a[i] == b[j])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
}

void Afisare()
{
    ofstream fout("cmlsc.out");
    int k, i, j;
    fout << dp[n][m] << "\n";
    i = n;
    j = m;
    k = 0;
    while(i > 0 && j > 0)
        if(a[i] == b[j])
        {
            sol[++k] = a[i];
            i--;
            j--;
        }
        else if(dp[i - 1][j] > dp[i][j - 1]) i--;
        else j--;
    for(i = k; i >= 1; i--)
        fout << sol[i] << " ";
    fout.close();
}

int main()
{
    Citire();
    LCS();
    Afisare();
    return 0;
}
