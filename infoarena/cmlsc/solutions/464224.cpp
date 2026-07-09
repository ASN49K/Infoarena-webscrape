#include <stdio.h>
#include <algorithm>
using namespace std;

int a[1025], b[1025], c[1025][1025];
int m, n, i, j, k;
int poz;
int Min, Max, lg;
int ok;

int main ()
{
    FILE *f = fopen ("cmlsc.in","r");
    FILE *g = fopen ("cmlsc.out","w");
    fscanf (f,"%d %d", &m, &n);
    for (i=1; i<=m; ++i)
        fscanf (f,"%d", &a[i]);
    for (i=1; i<=n; ++i)
        fscanf (f,"%d", &b[i]);

    for (i=1; i<=m; ++i)
        for (j=1; j<=n; ++j)
        {
            if (a[i] == b[j])
                c[i][j] = c[i-1][j-1] + 1;
            else
                c[i][j] = max (c[i-1][j], c[i][j-1]);
        }
    /*for (i=1; i<=m; ++i)
    {
        for (j=1; j<=n; ++j)
            printf ("%d ", c[i][j]);
        printf ("\n");
    }*/

    fprintf (g,"%d", c[m][n]);

    fclose(g);
    fclose(f);
    return 0;
}

/*
    c[i][j] = lungimea subsirului comun format din primele i elemente ale primului sir
              si subsierul format cu primele j caractere ale celui de-al doilea sir

    relatie de recurenta : cand intalnesc 2 elemente egale c[i]][j] = c[i-1][j-1] + 1
                                    altfel
                                        c[i][j] = max (c[i-1][j], c[i][j-1])
*/
