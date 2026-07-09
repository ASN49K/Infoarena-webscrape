#include <fstream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int dp[1025][1025];
//dp[i][j] = lungimea celui mai lung subsir crescator pentru prefixele a[1...i] si b[1...j]
int a[1025], b[1025];
int s[1025], lg;

int main()
{
    int n, m, i, j;
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
    lg = 0;
    for (i = m, j = n; i>0 && j>0; )
    {
        if (a[i] == b[j])
        {
            lg++;
            s[lg] = a[i];
            i--;
            j--;
        }
        else if (dp[i-1][j] > dp[i][j-1])
            i--;
        else
            j--;
    }
    fout << lg << '\n';
    for (i = lg; i>=1; i--)
        fout << s[i] << ' ';
    return 0;
}
