#include <cstdio>
#include <algorithm>
#define Dim 1030

using namespace std;
int n, m, i, j, a[Dim], b[Dim];
int c[Dim][Dim], sol[Dim], k;
void read()
{
    freopen("cmlsc.in", "r", stdin);
    scanf("%d %d", &n, &m);
    for(i = 1; i <= n; ++ i)
        scanf("%d", &a[i]);
    for(i = 1; i <= m; ++ i)
        scanf("%d", &b[i]);
}
void cmlsc()
{
    for(i = 1; i <= n; ++ i)
        for(j = 1; j <= m; ++ j)
            if(a[i] == b[j])
                c[i][j] = c[i - 1][j - 1] + 1;
            else c[i][j] = max(c[i - 1][j], c[i][j - 1]);

}
void write()
{
    freopen("cmlsc.out", "w", stdout);
    printf("%d\n", c[n][m]);
    i = n, j = m;
    while(c[i][j])
    {
        if(a[i] == b[j])
        {
            sol[++ k] = a[i];
            i --;
            j --;
        }
        else
            if(c[i][j] == c[i - 1][j])
                i --;
                    else j --;
    }
    for(i = k; i >= 1; -- i)
        printf("%d ", sol[i]);
}
int main()
{
    read();
    cmlsc();
    write();
    return 0;
}
