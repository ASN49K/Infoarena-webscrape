#include <iostream>
#include <fstream>
using namespace std;
#define maxn 1026
int n, m, a[maxn], b[maxn], c[maxn], dp[maxn][maxn];
int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    f>>n>>m;
    for (int i = 1; i <= n; i++)
        f>>a[i];
    for (int i = 1; i <= m; i++)
        f>>b[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
    {
        dp[i][j] = max(max(dp[i][j-1], dp[i-1][j]), (a[i]==b[j]) ? dp[i-1][j-1] + 1 : 0);
    }
    g<<dp[n][m]<<'\n';
    int sol = dp[n][m];
    int i = n, j = m;
    while(sol)
    {
        if (dp[i][j] == dp[i-1][j-1] + 1 && a[i] == b[j]) {
            sol--;
            c[sol] = a[i];
            i--; j--;
            } else if (dp[i][j] == dp[i-1][j]) i--;
        else j--;
    }
    for (i = 0; i < dp[n][m]; i++)
        g<<c[i]<<' ';
}
