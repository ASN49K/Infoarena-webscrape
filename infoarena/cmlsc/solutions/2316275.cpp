#include <iostream>
#include <fstream>
using namespace std;

int dp[100][100];
ofstream g("cmlsc.out");
void citire(int a[100], int b[100], int &n, int &m)
{
    ifstream f("cmlsc.in");
    f>>n>>m;
    for(int i = 1; i <= n; i++)
        f>>a[i];
    for(int i = 1; i <= m; i++)
        f>>b[i];
}

void printare(int a[100], int x, int i, int j)
{
    if (x <= 0)
        return;
    while (dp[i - 1][j] == x)
        i--;
    while (dp[i][j - 1] == x)
        j--;
    printare(a, x - 1, i - 1, j - 1);
    g<<a[i]<<" ";
}

void cmlsc(int a[100], int b[100], int n, int m)
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (a[i] == b[j])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
        }
    }
    g<<dp[n][m]<<endl;
    printare(a, dp[n][m], n, m);
}

int main()
{
    int a[100], b[100], n, m;
    citire(a, b, n, m);
    cmlsc(a, b, n, m);
    return 0;
}
