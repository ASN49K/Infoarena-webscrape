#include <stdio.h>
 
#define maxn 1024
 
int n, m, a[maxn], b[maxn], lcs[maxn][maxn];
 
int main()
{
    FILE* f = fopen("cmlsc.in", "r");
    FILE* g = fopen("cmlsc.out", "w");
 
    fscanf(f, "%d%d", &n, &m);
 
    for (int i = 1; i <= n; i++)
        fscanf(f, "%d", &a[i]);
 
    for (int i = 1; i <= m; i++)
        fscanf(f, "%d", &b[i]);
 
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
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

    int bst = 0;
    int i = n;
    int j = m;

    while (i > 0)
    {
        if (a[i] == b[j])
        { 
            lcs[0][bst] = a[i];
            j--;
            i--;
            bst++;
        }
        else
        {
            if (lcs[i-1][j] < lcs[i][j])
                j--;
            else
                i--;
        }
    }

    fprintf(g, "%d\n", bst);
    for (i = bst-1; i >=0; i--)
        fprintf(g, "%d ", lcs[0][i]);

    return 0;
}
