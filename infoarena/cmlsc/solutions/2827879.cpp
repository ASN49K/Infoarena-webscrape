#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int N = 1025;
int dp[N][N], a[N], b[N];

void sir(int l, int c)
{
    if(l == 0 || c == 0)
        return;
    if(a[l] == b[c])
    {
        sir(l - 1, c - 1);
        fout << a[l] << " ";
    }
    else if(dp[l-1][c] > dp[l][c-1])
        sir(l - 1, c);
    else
        sir(l, c - 1);
}

int main()
{
    int m, n;
    fin >> m >> n;
    for(int i = 1; i <= m; i++)
        fin >> a[i];
    for(int j = 1; j <= n; j++)
        fin >> b[j];
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(a[i] == b[j])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    fout << dp[m][n] << "\n";
    sir(m, n);

    return 0;
}
