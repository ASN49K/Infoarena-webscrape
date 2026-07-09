#include <cstdio>
#include <algorithm>

#define NMAX 1025

using namespace std;

int n;
int m;
int a[NMAX];
int b[NMAX];
int s[NMAX][NMAX];

void read()
{
    freopen("cmlsc.in", "r", stdin);

    scanf("%d %d\n", &n, &m);
    for(int i = 1; i <= n; scanf("%d ", &a[i ++]));
    for(int i = 1; i <= m; scanf("%d ", &b[i ++]));
}

void solve()
{
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j <= m; ++ j)
            if(a[i] == b[j])
                s[i][j] = 1 + s[i - 1][j - 1];
            else
                s[i][j] = max(s[i - 1][j], s[i][j - 1]);
}

void write(int i, int j)
{
    if (i * j == 0)
        return;

    if(a[i] == b[j])
    {
        write(i - 1, j - 1);
        printf("%d ", a[i]);
        return;
    }

    if(s[i - 1][j] > s[i][j - 1])
        write(i - 1, j);
    else
        write(i, j - 1);
}

int main()
{
    read();
    solve();

    freopen("cmlsc.out", "w", stdout);
    printf("%d\n", s[n][m]);
    write(n, m);
    printf("\n");

    return 0;
}
