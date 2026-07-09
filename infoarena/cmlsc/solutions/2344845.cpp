#include <iostream>
#include <fstream>
#define X 1039
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, a[X], b[X], dp[X][X], nr[X];

int main()
{
    fin >> n >> m;
    int i, j;

    for(i=1; i<=n; i++)
        fin >> a[i];
    for(i=1; i<=m; i++)
        fin >> b[i];


    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
        if(a[i] == b[j]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

    fout << dp[n][m] << "\n";

    int k = 0;
    for(i = n, j = m; i > 0;)
    {
        if (a[i] == b[j])
        {
            nr[++k] = a[i];
            i--;
            j--;
        }
        else if (dp[i - 1][j] < dp[i][j - 1])
            j--;
        else i--;
    }
    for (i = k; i >= 1; i--)
        fout << nr[i] << " ";
        fout << "\n";
    return 0;
}
