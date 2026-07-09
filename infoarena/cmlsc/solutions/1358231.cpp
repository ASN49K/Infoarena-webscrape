#include <stdio.h>

#define maxn 1024

int n, m, a[maxn], b[maxn], lcs[maxn][maxn];

int main()
{
    // FILE INITIALIZATION
    FILE* f = fopen("cmlsc.in", "r");
    FILE* g = fopen("cmlsc.out", "w");

    // READING
    fscanf(f, "%d%d", &n, &m);

    for (int i = 0; i < n; i++)
    {
        fscanf(f, "%d", &a[i]);
    }

    for (int i = 0; i < m; i++)
    {
        fscanf(f, "%d", &b[i]);
    }

    // ALGORITHM
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i] == b[j])
            {
                lcs[i][j] = lcs[i-1][j-1] + 1;
            }
            else
            {
                lcs[i][j] = lcs[i-1][j] > lcs[i][j-1] ? lcs[i-1][j] : lcs[i][j-1];
            }
        }
    }

    int bst = 0;

    int j = 0;

    for (int i = m, j = n; i; )
        if (a[i] == b[j])
            bst++, --i, --j;

    printf("%d", bst);

    return 0;
}
