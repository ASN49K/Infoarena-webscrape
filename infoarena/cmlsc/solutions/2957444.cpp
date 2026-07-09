#include <fstream>
#include <iostream>

const size_t NMAX = 1024;

std::ifstream fin("cmlsc.in");
std::ofstream fout("cmlsc.out");

int dp[NMAX + 1][NMAX + 1];

int n, m, N[NMAX + 1], M[NMAX + 1];
void back_afisare(int i, int j)
{
    if (i == 0 || j == 0)
        return;
    if (N[i] == M[j])
    {
        back_afisare(i - 1, j - 1);
        fout << N[i] << ' ';
    }
    else
    {
        if (dp[i - 1][j] > dp[i][j - 1])
            back_afisare(i - 1, j);
        else
            back_afisare(i, j - 1);
    }
}

int main()
{
    fin >> n >> m;
    for (int i = 1; i <= n; i++)
        fin >> N[i];
    for (int i = 1; i <= m; i++)
        fin >> M[i];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (N[i] == M[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    fout << dp[n][m] << '\n';
    back_afisare(n, m);
    fout << '\n';
    return 0;
}