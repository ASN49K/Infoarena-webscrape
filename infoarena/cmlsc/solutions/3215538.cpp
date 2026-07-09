#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
#define MAX 1025
int a[MAX], b[MAX], d[MAX][MAX];

void backtracking(int d[MAX][MAX], int a[MAX], int b[MAX], int i, int j)
{
    if (i == 0 || j == 0)
        return;
    if (a[i] == b[j])
    {
        backtracking(d, a, b, i - 1, j - 1);
        g << a[i] << " ";
    }
    else if (d[i][j - 1] > d[i - 1][j])
        backtracking(d, a, b, i, j - 1);
    else
        backtracking(d, a, b, i - 1, j);

}
int main()
{
    int n, m;
    f >> n >> m;
    for (int i = 1; i <= n; ++i)
        f >> a[i];
    for (int j = 1; j <= m; ++j)
        f >> b[j];
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= m; ++j)
            if (i == 0 || j == 0)
                d[i][j] = 0;
            else if (a[i] == b[j])
                d[i][j] = d[i-1][j-1] + 1;
            else d[i][j] = max(d[i][j - 1], d[i - 1][j]);
    g << d[n][m] << '\n';
    backtracking(d, a, b, n, m);
    f.close();
    g.close();
    return 0;
}
