#include <iostream>
#include <fstream>
#include <vector>
#define nl '\n'

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int NMAX = 2*1e3;

int a[NMAX], b[NMAX], n, m, dp[NMAX][NMAX];
vector<int> sol;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    fin >> n >> m;
    for (int i = 1; i <= n; i++)
        fin >> a[i];
    for (int i = 1; i <= m; i++)
        fin >> b[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i] == b[j])
                dp[i][j] = dp[i-1][j-1]+1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    int x = dp[n][m], i = n, j = m;
    while (x)
    {
        if (a[i] == b[j])
        {
            sol.push_back(a[i]);
            i--;
            j--;
            x--;
        }
        else if (dp[i][j-1] < dp[i-1][j])
            i--;
        else
            j--;
    }
    fout << dp[n][m] << nl;
    for (int i = dp[n][m]-1; i >= 0; i--)
        fout << sol[i] << ' ';
    return 0;
}

