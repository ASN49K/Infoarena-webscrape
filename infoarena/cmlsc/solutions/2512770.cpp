#include <fstream>
using namespace std;
 
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int dp[1025][1025];

int main()
{
    int n, m, i, j, a[1025], b[1025], sir[1025];
    fin >> m >> n;
    for (i = 1; i<=m; i++)
        fin >> a[i];
    for (i = 1; i<=n; i++)
        fin >> b[i];
    for (i = 1; i<=m; i++)
        for (j = 1; j<=n; j++)
        {
            if (a[i] == b[j])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    sir[0] = 0;
    for (i = m, j = n; i>0 && j>0; )
    {
        if (a[i] == b[j])
        {
            sir[0]++;
            sir[sir[0]] = a[i];
            i--;
            j--;
        }
        else if (dp[i-1][j] > dp[i][j-1])
            i--;
        else
            j--;
    }
    fout << sir[0] << '\n';
    for (i = sir[0]; i>=1; i--)
        fout << sir[i] << ' ';
    return 0;
}
