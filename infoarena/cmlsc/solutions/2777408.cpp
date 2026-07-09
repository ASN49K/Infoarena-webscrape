#include <bits/stdc++.h>

using namespace std;

int a[1030], b[1030], d[1030][1030];

void path(int i, int j)
{
    if(!i or !j) return;
    if(a[i] == b[j]) path(i - 1, j - 1), printf("%d ", a[i]);
    else if(d[i - 1][j] > d[i][j - 1]) path(i - 1, j);
    else path(i, j - 1);
}

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int j = 1; j <= m; j++) scanf("%d", &b[j]);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(a[i] == b[j]) d[i][j] = 1 + d[i - 1][j - 1];
            else d[i][j] = max(d[i - 1][j], d[i][j - 1]);
    printf("%d\n", d[n][m]);
    path(n, m);
    return 0;
}
