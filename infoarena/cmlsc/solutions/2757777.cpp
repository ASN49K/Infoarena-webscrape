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
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                sol[dp[i][j]] = a[i];
            }
            else
                dp[i][j] = max(dp[i - 1][j - 1], max(dp[i - 1][j], dp[i][j - 1]));
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
    Afisare();

    return 0;
}















