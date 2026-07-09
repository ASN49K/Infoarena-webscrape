#include <fstream>
#include <vector>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int nmax = 1024;
int a[nmax + 5], b[nmax + 5], dp[nmax + 5][nmax + 5];

int main()
{
    int n, m;
    fin >> n >> m;
    for (int i = 1; i <= n; ++i)
        fin >> a[i];
    for (int j = 1; j <= m; ++j)
        fin >> b[j];

    // Calculăm LCS
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            if (a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }

    fout << dp[n][m] << "\n"; // Newline după LCS

    // Reconstruim secvența LCS
    vector<int> sol;
    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (a[i] == b[j])
        {
            sol.push_back(a[i]);
            --i, --j;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            --i;
        else
            --j;
    }

    // Afișăm rezultatul corect
    for (int k = sol.size() - 1; k >= 0; --k)
        fout << sol[k] << " ";

    fout << "\n"; // Newline la final pentru siguranță
    return 0;
}
