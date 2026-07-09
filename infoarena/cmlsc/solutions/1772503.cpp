#include <cstdio>
#include <algorithm>
#define N 1300

using namespace std;
int a[N], b[N], best[N][N], sol[N];
int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    int n, m, i, j;
    scanf("%d %d", &m, &n);
    for(i = 1; i <= m; i++)
        scanf("%d", &a[i]);
    for(i = 1; i <= n; i++)
        scanf("%d", &b[i]);
    for(i = 1; i <= m; i++)
        for(j = 1; j <= n; j++)
        {
            if(a[i]==b[j])
                best[i][j] = best[i-1][j-1] + 1;
            else
                best[i][j] = max(best[i-1][j], best[i][j-1]);
        }
    printf("%d\n", best[m][n]);
    int maxim = best[m][n];
    for(i = m; i >= 1; i--)
        for(j = n; j >= 1; j--)
            if(best[i][j]==maxim && a[i] == b[j])
            {
                sol[maxim]= a[i];
                maxim--;
            }

    for(i = 1; i <= best[m][n]; i++)
        printf("%d ", sol[i]);

    return 0;
}
