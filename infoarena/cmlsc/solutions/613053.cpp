#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1024;
int a[N], b[N], s[N][N], n, m;

void citire()
{
    scanf ("%d %d ", &n, &m);
    for (int i = 1; i <= n; ++ i)
        scanf ("%d ", &a[i]);
    for (int i = 1; i <= m; ++ i)
        scanf ("%d ", &b[i]);
}

void solve()
{
    for (int i = 1; i<= n; ++ i)
        for (int j = 1; j <= m; ++ j)
        {
            if (a[i] == b[j])
                s[i][j] = 1 + s[i-1][j-1];
            else
                s[i][j] = max(s[i][j-1], s[i-1][j]);
        }
    printf ("%d\n", s[n][m]);
}

void afisare(int i,int j)
{
    if (i == 0 || j == 0)
        return;
    if (a[i] == b[j])
    {
        afisare(i-1, j-1);
        printf ("%d ",a[i]);
    }
    else if (s[i][j-1] < s[i-1][j])
        afisare(i-1, j);
    else
        afisare(i, j-1);
}

int main()
{
    freopen ("cmlsc.in", "r", stdin);
    //freopen ("cmlsc.out", "w", stdout);
    citire();
    solve();
    afisare(n,m);
    printf ("\n");
    return 0;
}
