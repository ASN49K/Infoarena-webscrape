#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int nmax=1030;
int a[nmax], b[nmax];
int dp[nmax][nmax];

vector<int> lcs;

void afis(int i, int j)
{
    if (i == 0 || j == 0)
        return;
    if (a[i] == b[j])
    {
        afis(i-1, j-1);
        lcs.push_back(a[i]);
    }
    else if (dp[i-1][j] > dp[i][j-1])
        afis(i-1, j);
    else
        afis(i, j-1);
}

int main()
{
    int n, m;
    fin >> n >> m;

    for (int i = 1; i <= n; i++)
        fin >> a[i];
    for (int i = 1; i <= m; i++)
        fin >> b[i];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i] == b[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

    fout << dp[n][m] << '\n';
    afis(n, m);
    for (int x : lcs)
        fout << x << ' ';

    return 0;
}
