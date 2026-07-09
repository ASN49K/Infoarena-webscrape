#include <stdio.h>

int c[1024][1024], a[1024], b[1024], n, m;


int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    int i, j;

    scanf("%d %d", &n, &m);

    for(i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
    }
    for(i = 1; i <= m; ++i)
    {
        scanf("%d", &b[i]);
    }

    for(i = n; i > 0; --i)
    {
        for(j = m; j > 0; --j)
        {
            if(a[i] == b[j])
            {
                c[i][j] = c[i + 1][j + 1] + 1;
                continue;
            }
            c[i][j] = c[i + 1][j];
            if(c[i][j + 1] > c[i][j])
            {
                c[i][j] = c[i][j + 1];
            }
        }
    }

    printf("%d\n", c[1][1]);
    i = j = 1;
    while(i <= n && j <= m)
    {
        if(a[i] == b[j])
        {
            printf("%d ", a[i], b[j]);
            ++i;
            ++j;
        }
        else
        {
            if(c[i][j + 1] > c[i + 1][j])
            {
                ++j;
            }
            else
            {
                ++i;
            }
        }
    }
    printf("\n");

    return 0;
}

