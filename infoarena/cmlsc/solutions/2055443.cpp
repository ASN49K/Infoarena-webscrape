#include <iostream>
#include <fstream>
#include <stack>
#define NMAX 1030

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

stack <int> path;

int m, n;
int a[NMAX], b[NMAX];
int dp[NMAX][NMAX];

void Input()
{
    f>>m>>n;
    for (int i = 1; i <= m; ++i)
        f>>a[i];
    for (int i = 1; i <= n; ++i)
        f>>b[i];
}

void d()
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (a[j] == b[i])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
}

void getPath()
{
    int i = n;
    int j = m;
    while (i > 0 && j > 0)
    {
        if (dp[i][j - 1] == dp[i][j] - 1 && a[j] == b[i])
        {
            path.push(a[j]);
            j--;
        }
        else if (dp[i - 1][j] == dp[i][j] - 1 && a[j] == b[i])
        {
            path.push(a[j]);
            i--;
        }
        else if (dp[i][j - 1] == dp[i][j])
            j--;
        else if (dp[i - 1][j] == dp[i][j])
            i--;
    }

}

int main()
{
    Input();
    d();
    g << dp[n][m] << "\n";
    getPath();
    while (!path.empty())
    {
        g << path.top() << " ";
        path.pop();
    }
    return 0;
}
