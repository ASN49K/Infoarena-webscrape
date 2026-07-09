#include <fstream>

using namespace std;

int i, j, n, m, nr, a[1024], b[1024], c[1024][1024], d[1024];

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d %d", &m, &n);

    for(i = 1; i<=m; i++)
        scanf("%d", a + i);

    for(i = 1; i<=n; i++)
        scanf("%d", b + i);

    for(i = 1; i<=m; i++)
        for(j = 1; j<=n; j++)
            if(a[i] == b[j])
                c[i][j] = 1 + c[i - 1][j - 1];
            else
                c[i][j] = max(c[i][j - 1], c[i - 1][j]);

    for(i = m, j = n; i;)
        if(a[i] == b[j])
        {
            nr++;
            d[nr] = a[i];
            i--;
            j--;
        }
        else if(c[i - 1][j] < c[i][j - 1])
            j--;
        else
            i--;

    printf("%d\n", nr);

    for(i = nr; i>0; i--)
        printf("%d ", d[i]);
}
