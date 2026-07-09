#include <iostream>
#include <cstdio>

using namespace std;

int n, m, a[1050], b[1050], best[1050][1050];

void afisare(int i, int j)
{
    if (i <= 0 || j <= 0 || best[i][j] == 0)
        return;
    if (a[i] == b[j])
    {
        afisare(i-1, j-1);
        printf("%d ", a[i]);
    }
    else if (best[i][j-1] > best[i-1][j])
        afisare(i, j-1);
    else
        afisare(i-1, j);

}

void solve()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i] == b[j])
                best[i][j] = best[i-1][j-1] + 1;
            else
                best[i][j] = (best[i][j-1] > best[i-1][j] ? best[i][j-1] : best[i-1][j]);
    printf("%d\n", best[n][m]);
    afisare(n, m);
}

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d ", &a[i]);
    for (int i = 1; i <= m; i++)
        scanf("%d ", &b[i]);
    solve();

    return 0;
}
