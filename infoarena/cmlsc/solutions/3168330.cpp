#include <fstream>

#define NMAX 1050

int vec1[NMAX], vec2[NMAX], dp[NMAX][NMAX], sir[NMAX], nr = 0, n, m;

int main()
{
    std::ifstream fin("cmlsc.in");
    std::ofstream fout("cmlsc.out");

    fin >> n >> m;

    for (int i = 1; i <= n; ++i)
        fin >> vec1[i];
    for (int j = 1; j <= m; ++j)
        fin >> vec2[j];

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (vec1[i] == vec2[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);

    for (int i = n, j = m; j; )
        if (vec1[i] == vec2[j])
        {
            sir[++nr] = vec1[i];
            --i;
            --j;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            --i;
        else
            --j;

    fout << nr << '\n';

    for (int i = nr; i > 0; --i)
        fout << sir[i] << ' ';
    return 0;
}