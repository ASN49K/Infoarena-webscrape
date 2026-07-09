#include <stdio.h>
#include <stdlib.h>

int max(int a, int b, int c)
{
    int max = a;
    if( b > max)
        max = b;
    if( c > max)
        max = c;
    return max;
}

int main()
{
    FILE *f;
    f = fopen("cmlsc.in", "r");

    int i, j, n, m, k;
    fscanf(f,"%d %d", &m, &n);

    int a[m+1],b[n+1], c[m+1][n+1], d[m+1];

    for(i=1; i<=m; i++)
        fscanf(f, "%d", &a[i]);

    for(j=1; j<=n; j++)
        fscanf(f, "%d", &b[j]);

    fclose(f);

    for(i=0; i<=m; i++)
        c[i][0] = 0;

    for(j=0; j<=n; j++)
        c[0][j] = 0;

/*
    for(i=1; i<=m; i++)
        printf("%d ", a[i]);
    printf("\n");
    for(j=1; j<=n; j++)
        printf("%d ", b[j]);
    printf("\n");

*/

    for(i=1; i<=m; i++)
        for(j=1; j<=n; j++)
        {
            c[i][j] = max(c[i-1][j-1], c[i-1][j], c[i][j-1]);
            if(a[i] == b[j])
                c[i][j]++;
        }

/*
    for(i=0; i<=m; i++)
    {
        for(j=0; j<=n; j++)
            printf("%d ", c[i][j]);
        printf("\n");
    }
*/

    i--;
    j--;

    k=0;
    while(c[i][j] !=0 )
    {
        //printf("\n - %d %d %d %d - \n", i, j, a[i], b[j]);
        if(a[i] == b[j])
        {
            d[k] = a[i];
            k++;
            i--;
            j--;
        }
        else if(c[i-1][j] < c[i][j-1])
        {
            j--;
        }
        else
        {
            i--;
        }

    }

    FILE *g;
    g = fopen("cmlsc.out", "w");

    fprintf(g,"%d\n", c[m][n]);
    for(i=k-1; i>=0;i--)
    {
        fprintf(g,"%d ", d[i]);
    }

    fclose(g);

    return 0;
}
