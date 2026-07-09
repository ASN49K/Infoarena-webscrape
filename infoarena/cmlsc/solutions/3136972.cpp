#include <fstream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

#define NMAX 1050

int a[NMAX], b[NMAX], dp[NMAX][NMAX], sir[NMAX];

int main()
{
    int n, m;
    fin >> n >> m;

    for (int i = 1; i <= n; ++ i)
        fin >> a[i];
    for (int j = 1; j <= m; ++ j)
        fin >> b[j];

    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= m; ++ j)
            if (a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

    int nr = 0;
    for (int i = n, j = m; j; )
        if (a[i] == b[j])
        {
            sir[++ nr] = a[i];
            -- i;
            -- j;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            -- i;
        else
            -- j;

    fout << nr << '\n';
    for (int i = nr; i; -- i)
        fout << sir[i] << ' ';
    return 0;
}
