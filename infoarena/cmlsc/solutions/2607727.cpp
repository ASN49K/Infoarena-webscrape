#include <fstream>
#include <algorithm>
#define MAXSIZE 1025

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, v[MAXSIZE], w[MAXSIZE], i, j;
int dp[MAXSIZE][MAXSIZE];
int sir[MAXSIZE];
int main()
{
    fin >> m >> n;
    for (i = 1; i <= m; i++)
        fin >> v[i];
    for (i = 1; i <= n; i++)
        fin >> w[i];


    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            dp[i][j] = max(dp[i][j - 1], max(dp[i - 1][j], dp[i - 1][j - 1] + (v[i] == w[j])));
        }
    }
    fout << dp[m][n]<<"\n";
    int i = m, j = n;
    int p = 0;
    while (i > 0 && j > 0)
    {
        if (v[i] == w[j])
        {
            p++;
            sir[p] = v[i];
            i--; j--;
        }
        else if (dp[i - 1][j] < dp[i][j - 1]) j--;
        else i--;
    }

    for (p = dp[m][n]; p >= 1; p--)
        fout << sir[p] << " ";
    return 0;
}