#include <iostream>
#include <fstream>

using namespace std;

int n, m, a[1025], b[1025], dp[1025][1025], sol[1025];

void Citire()
{
    ifstream f("cmlsc.in");

    f >> n >> m;

    for(int i = 1; i <= n; i++)
        f >> a[i];

    for(int j = 1; j <= m; j++)
        f >> b[j];
}

void DeterminareCMLS()
{
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
}

void DeterminareSir()
{
    int i = n, j = m;

    while(i && j)
    {
        if(a[i] == b[j])
        {
            sol[dp[i][j]] = a[i];
            i--, j--;
        }
        else
        {
            if(dp[i - 1][j] > dp[i][j - 1])
                i--;
            else
                j--;
        }
    }
}

void Afisare()
{
    ofstream g("cmlsc.out");
    g << dp[n][m] << '\n';
    for(int i = 1; i <= dp[n][m]; i++)
        g << sol[i] << ' ';
}

int main()
{
    Citire();
    DeterminareCMLS();
    DeterminareSir();
    Afisare();

    return 0;
}















