#include <iostream>
#include <fstream>

using namespace std;

int n, m, a[1025], b[1025], dp[1025][1025];

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
                dp[i][j] = max(dp[i - 1][j - 1], max(dp[i - 1][j], dp[i][j - 1]));
}

ofstream g("cmlsc.out");

void AfisareREC(int lungime, int ii, int jj)
{
    if(lungime)
    {
        for(int i = ii; i >= 1; i--)
            for(int j = jj; j >= 1; j--)
                if(a[i] == b[j])
                {
                    AfisareREC(lungime - 1, i - 1, j - 1);
                    g << a[i] << ' ';
                    return;
                }
    }
}

void Afisare()
{
    g << dp[n][m] << '\n';
    AfisareREC(dp[n][m], n, m);
}

int main()
{
    Citire();
    DeterminareCMLS();
    Afisare();

    return 0;
}















