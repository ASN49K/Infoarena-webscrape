#include <fstream>
#define nmax 1024
int n, m, sol[nmax];
int A[nmax], B[nmax], dp[nmax][nmax];
std::ifstream fin("cmlsc.in");
std::ofstream fout("cmlsc.out");
inline void createDp()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (A[i] == B[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    fout << dp[n][m] << '\n';
}
inline void showSequence()
{
    int i = n, j = m;
    int k = 0;
    while (i >= 1 && j >= 1)
    {
        if (A[i] == B[j])
        {
            sol[++k] = A[i];
            i--;
            j--;
        }
        else
        {
            if (dp[i - 1][j] > dp[i][j - 1])
                i--;
            else
                j--;
        }
    }
    for (i = k; i >= 1; i--)
    {
        fout << sol[i] << " ";
    }
}
int main()
{
    fin >> n >> m;
    for (int i = 1; i <= n; i++)
        fin >> A[i];
    for (int i = 1; i <= m; i++)
        fin >> B[i];
    createDp();
    showSequence();
    return 0;
}