#include <cstdio>
#include <iostream>
using namespace std;

const int nmx = 1030;

int n,m;
int a[nmx],b[nmx],mat[nmx][nmx];

void rec(int i, int j)
{
    if(mat[i][j] == mat[i-1][j-1] + 1)
    {
        if(i > 1 && j > 1)
            rec(i-1,j-1);
        printf("%d ", a[i]);
        return;
    }
    if(mat[i-1][j] > mat[i][j-1] && i - 1 > 0)
        rec(i-1,j);
    else if(j - 1 > 0)
        rec(i-1,j);
}

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for(int j = 1; j <= m; ++j)
        scanf("%d", &b[j]);

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(a[i] == b[j])
                mat[i][j] = mat[i-1][j-1] + 1;
            else
                mat[i][j] = max(mat[i-1][j],mat[i][j-1]);

    printf("%d\n", mat[n][m]);

    rec(n,m);

    return 0;
}
