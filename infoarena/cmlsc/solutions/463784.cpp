#include <stdio.h>
#include <algorithm>
using namespace std;

int a[257], b[257], ca[257], cb[257];
int m, n, i, j, k;
int poz;
int Min, Max, lg;

int main ()
{
    FILE *f = fopen ("cmlsc.in","r");
    FILE *g = fopen ("cmlsc.out","w");
    fscanf (f,"%d %d", &n, &m);
    for (i=1; i<=n; ++i)
        fscanf (f,"%d", &a[i]);
    for (i=1; i<=m; ++i)
        fscanf (f,"%d", &b[i]);

    Min = min (n, m);
    Max = max (n, m);
    for (i=1; i<=n; ++i)
    {
        for (j=1; j<=m; ++j)
        {
            if (a[i] == b[j])
            {
                ca[i] = 1;
                cb[j] = 1;
                if (Min == n)
                    poz = i;
                else
                    poz = j;
            }
        }
    }

    for (i=1; i<=n; ++i)
    {
       // printf ("%d ", ca[i]);
        if (ca[i])
            lg ++;
    }
    /*printf ("\n\n");
    for (i=1; i<=m; ++i)
        printf ("%d ", cb[i]);*/

    fprintf (g,"%d\n", lg);
    for (i=1; i<=n; ++i)
        if (ca[i])
            fprintf (g,"%d ", a[i]);

    fclose(g);
    fclose(f);
    return 0;
}
