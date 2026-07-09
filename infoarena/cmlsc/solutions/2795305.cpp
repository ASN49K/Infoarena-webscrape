#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
#define NMAX 1025
int n, m, a[NMAX], b[NMAX], dp[NMAX][NMAX];
void citire()
{
    f >> n >> m;
    for (int i = 1; i <= n; ++i)
        f >> a[i];
    for (int i = 1; i <= m; ++i)
        f >> b[i];
}
void dinamica()
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            if (a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
}
void afisare()
{
    int afis[NMAX], i = n, j = m, lg = dp[i][j];
    g << lg << '\n';
    while (dp[i][j])
    {
        if (a[i] == b[j])
        {
            afis[dp[i][j]] = a[i];
            i--;
            j--;
        }
        else if (dp[i - 1][j] >= dp[i][j - 1])
            i--;
        else
            j--;
    }
    for (int k = 1; k <= lg; ++k)
        g << afis[k] << ' ';
}
int main()
{
    citire();
    dinamica();
    afisare();
    return 0;
}
