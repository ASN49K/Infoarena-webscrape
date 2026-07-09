#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n, m, v[1025], w[1025];
int dp[1025][1025];
int lmax, c[1025];

int main()
{
    int i, j;
    fin >> n >> m;
    for (i = 1; i <= n; i++)
        fin >> v[i];

    for (i = 1; i <= m; i++)
        fin >> w[i];

    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            if (v[i] == w[j]) dp[i][j] = 1 + dp[i - 1][j - 1];
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

    i = n; j = m;
    while (i > 0)
    {
        if (v[i] == w[j])
        {
            lmax++;
            c[lmax] = v[i];
            i--; j--;
        }
        else if (dp[i - 1][j] < dp[i][j - 1]) j--;
        else i--;
    }
    fout << lmax << '\n';
    for (i = lmax; i > 0; i--)
        fout << c[i] << " ";
    return 0;
}