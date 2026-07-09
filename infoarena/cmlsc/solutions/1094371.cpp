#include <stdio.h>

#define Nmax 1030

int n, m;
int a[Nmax], b[Nmax];
int best[Nmax][Nmax];

void read()
{
    freopen("cmlsc.in", "r", stdin);

    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= m; ++i)
        scanf("%d", &b[i]);
    fclose(stdin);
}

inline int maximum(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

void solve()
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j){
            if (a[i] == b[j])
                best[i][j] = best[i-1][j-1] + 1;
            else
                best[i][j] = maximum(best[i-1][j], best[i][j-1]);
        }
}

void writeSequence(int i, int j)
{
    if (i == 0 || j == 0)
        return;

    if (best[i][j] > best[i-1][j] && best[i][j] > best[i][j-1]){
        writeSequence(i-1, j-1);
        printf("%d ", a[i]);
    } else if (best[i-1][j] > best[i][j-1])
        writeSequence(i-1, j);
    else
        writeSequence(i, j-1);
}

int main()
{
    read();
    solve();
    freopen("cmlsc.out", "w", stdout);
    printf("%d\n", best[n][m]);
    writeSequence(n, m);
}
