// https://infoarena.ro/problema/cmlsc - Szücs Patrik - Kevin
#include <fstream>
#include <vector>

int main()
{
    short m, n;

    std::ifstream in("cmlsc.in");
    in >> m >> n;

    std::vector<short> a(m), b(n);
    for (short &elem : a)
    {
        in >> elem;
    }

    for (short &elem : b)
    {
        in >> elem;
    }

    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    std::ofstream out("cmlsc.out");
    out << dp[m][n] << '\n';
    int i = m, j = n;
    std::vector<short> reverse;

    while (i > 0 && j > 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            reverse.push_back(a[i - 1]);
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    for (int i = dp[m][n] - 1; i >= 0; i--)
    {
        out << reverse[i] << " ";
    }

    return 0;
}