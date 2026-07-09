#include <cstdio>
#include <algorithm>

#define NMAX 1025

using namespace std;

int n;
int m;
int a[NMAX];
int b[NMAX];
int sol[NMAX][NMAX];

void readArray(int *s, int l)
{
    for(int i = 1; i <= l; ++ i)
        scanf("%d ", &s[i]);
}

void read()
{
    freopen("cmlsc.in", "r", stdin);

    scanf("%d %d\n", &n, &m);
    readArray(a, n);
    readArray(b, m);
}

void solve()
{
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j <= m; ++ j)
            if(a[i] == b[j])
                sol[i][j] = 1 + sol[i - 1][j - 1];
            else
                sol[i][j] = max(sol[i][j - 1], sol[i - 1][j]);
}

void write(int i, int j)
{
    if(i * j == 0)
        return;

    if(a[i] == b[j])
    {
        write(i - 1, j - 1);
        printf("%d ", a[i]);
        return;
    }

    if(sol[i][j - 1] > sol[i - 1][j])
        write(i, j - 1);
    else
        write(i - 1, j);
}

int main()
{
    read();
    solve();

    freopen("cmlsc.out", "w", stdout);
    printf("%d\n", sol[n][m]);
    write(n, m);

    return 0;
}
