#include <stdio.h>
#include <stdlib.h>

int l[1025][1025];

void tracebackONCE(int l[1025][1025], int i, int j)
{
    if (l[i][j] == 0) return;
    else if (l[0][j] == l[i][0])
    {
        tracebackONCE(l, i-1, j-1);
        printf("%d ", l[0][j]);
    }
    else
    {
        if (l[i][j-1] > l[i-1][j]) tracebackONCE(l, i, j-1);
        else tracebackONCE(l, i-1, j);
    }
}

int main()
{
    int i, j, m, n;

    // open files
    freopen("cmlsc.in", "r", stdin);
    // freopen("cmlsc.out", "w", stdout);

    // read input
    scanf("%d", &m);
    scanf("%d", &n);
    for (i = 2; i <= m+1; i++) scanf("%d", &l[0][i]);
    for (i = 2; i <= n+1; i++) scanf("%d", &l[i][0]);

    // generate the LCS table
    for (i = 2; i <= n+1; i++)
    {
        for (j = 2; j <= m+1; j++)
        {
            if (l[0][j] == l[i][0])
            {
                l[i][j] = l[i-1][j-1] + 1;
            }
            else
            {
                l[i][j] = l[i-1][j] < l[i][j-1] ? l[i][j-1] : l[i-1][j];
            }
        }
    }

    // read out a LCS
    tracebackONCE(l, n+1, m+1);

    return 0;
}
