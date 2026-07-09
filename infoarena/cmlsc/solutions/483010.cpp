#include <stdio.h>
#include <algorithm>
using namespace std;

int a[1025], b[1025], c[1025][1025], sol[1025];
int n, m, i, j, k;

int main ()
{
    FILE *f = fopen ("cmlsc.in","r");
    FILE *g = fopen ("cmlsc.out","w");

    fscanf (f,"%d %d", &n, &m);
    for (i=1; i<=n; ++i)
        fscanf (f,"%d", &a[i]);
    for (i=1; i<=m; ++i)
        fscanf (f,"%d", &b[i]);

    for (i=1; i<=n; ++i)
        for (j=1; j<=m; ++j)
            if (a[i] == b[j])
                c[i][j] = c[i-1][j-1] + 1;
            else
                c[i][j] = max (c[i-1][j], c[i][j-1]);


    fprintf (g,"%d\n", c[n][m]);
    i = n;
    j = m;
    while (i >= 1 && j >= 1)
    {
        if (a[i] == b[j])
        {
            k ++;
            sol[k] = a[i];
        }

        if (c[i][j] == c[i-1][j])
            i --;
        else if (c[i][j] == c[i][j-1])
            j --;
        else if (c[i][j] == c[i-1][j-1] + 1)
        {
            i --;
            j --;
        }
    }

    for (i=k; i>=1; --i)
        fprintf (g,"%d ", sol[i]);

    fclose (g);
    fclose (f);
    return 0;
}
